/**
 *  Implementation of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#include <board.hpp>
#include <game/legal_move_generator.hpp>
#include <game/moves.hpp>
#include <piece.hpp>
#include <vector>
#include <iostream>

/**
 *  Constructor
 */
LegalMoveGenerator::LegalMoveGenerator(Board &board) {

    // we need to store the board here
    this->board = &board;
}

/**
 *  Method to generate all possible moves given a board configuration
 *  for the white or black player
 *  @param turn (int) 0 for black's turn and 1 for white's turn
 */
std::vector<Moves> LegalMoveGenerator::generate(int turn){

    // initialize a valid move vector
    std::vector<Moves> validMoves;

    // start by generating all the piece moves for this player's turn
    std::vector<Moves> allPieceMoves = LegalMoveGenerator::generateAllPieceMoves(turn);

    // loop over all of the moves
    for (int i=0; i<allPieceMoves.size(); i++) {

        // extract moves for a single piece
        Moves pieceMoves = allPieceMoves[i];

        // copy the Moves vector but clear the valid moves
        Moves validPieceMoves = pieceMoves;
        validPieceMoves.moves = {};

        // loop over the moves from this piece
        for (int j=0; j<pieceMoves.moves.size(); j++) {
            
            // extract a single move
            Move move = pieceMoves.moves[j];

            // make the pseudo move (boolean denotes this is pseudo)
            this->board->move(move, true);

            // here we need to check all the moves again and see if the king is in check
            // FOR THIS WE NEED TO GENERATE ALL THE MOVES OF THE !!OTHER!! PLAYER
            bool check = this->lookForChecks(turn);

            if (!check) {
                validPieceMoves.moves.push_back(move);
            }

            // undo the move
            this->board->undo(move);
        }

        // add the valid moves object if it has any moves
        validPieceMoves.generateNotations();
        if (validPieceMoves.moves.size() > 0) validMoves.push_back(validPieceMoves);
        
    }

    // check for castling
    std::vector<Moves> castleMoves = this->checkCastling(turn);

    // add all individual castling moves
    for (int i=0; i<castleMoves.size(); i++) validMoves.push_back(castleMoves[i]);

    return validMoves;
}

/**
 *  Method that generates the moves of all pieces considering a board configuration
 *  The moves yielded by this function ignore checks and castling
 *  @param turn (int) 0 for black's turn and 1 for white's turn
 */
std::vector<Moves> LegalMoveGenerator::generateAllPieceMoves(int turn){

    // initialize moves
    std::vector<Moves> allMoves;

    // loop over all the pieces on the board
    for (int i=0; i<this->board->pieces.size(); i++) {
        
        // only generate moves for pieces that belong to the side who's turn it is
        if (this->board->pieces[i]->player != turn) {
            continue;
        }
        
        // extract the piece name
        Piece* piece = this->board->pieces[i];

        // convert these pieces into Move structs, which hold both
        // the square to which the move wants to go as well as a potential piece to be captured
        std::vector<Move> pieceMoves = this->generateSinglePieceMoves(piece); 

        // create a moves class for the piece holding all legal moves in there
        Moves moves = Moves(piece->notation, piece->id, pieceMoves);     

        // add this move to all the moves
        allMoves.push_back(moves);
    } 

    return allMoves;
}

/**
 *  Method that generate all the moves of a single piece of the board
 *  @param piece (Piece) the piece for which the moves should be generated
 */
std::vector<Move> LegalMoveGenerator::generateSinglePieceMoves(Piece* piece) {

    // generate the move coordinates that the piece can go to
    std::vector<std::array<int, 2>>pieceMoveSuggestions = piece->getMoves(this->board->board);

    // initialize a move vector
    std::vector<Move> pieceMoves;

    // loop over the move suggestions
    for (int i=0; i<pieceMoveSuggestions.size(); i++) {
        
        // extract coordinates
        int y = pieceMoveSuggestions[i][0];
        int x = pieceMoveSuggestions[i][1];

        // get the square on the board
        int square = this->board->board[y][x];

        // initialize a move struct here
        Move move = { 
            .piece = piece,
            .start = {piece->y, piece->x},
            .square = pieceMoveSuggestions[i],
        };

        // check if this will capture a piece
        if (square != 0) {

            // if so, we need to find out which piece this is and add it to the move struct
            for (int j=0; j<this->board->pieces.size(); j++) {
                
                // extract piece
                Piece* p = this->board->pieces[j];

                // check if piece is on square location
                if (p->y == y && p->x == x) {

                    // if so we need to add it to the move struct
                    move.capturedPiece = p;
                }
            }         
        }

        // add the move to the struct
        pieceMoves.push_back(move);
    }

    // return the suggested piece moves
    return pieceMoves;
};

/**
 *  Method to look for checks given a certain board configuration
 *  !! IMPORTANT !! This function will only be called on pseudoboards
 *  @param turn (int) the player's turn
 */
bool LegalMoveGenerator::lookForChecks(int turn) {

    // we have to generate all possible piece moves of the other player!
    // we do it of the other player by flipping the integer from 1 to 0 and vice versa
    std::vector<Moves> allPieceMoves = this->generateAllPieceMoves(!turn);

    // loop over them
    for (int i=0; i<allPieceMoves.size(); i++) {

        // extract moves for a single piece
        Moves pieceMoves = allPieceMoves[i];

        // loop over the moves from this piece
        for (int j=0; j<pieceMoves.moves.size(); j++) {

            // extract a single move
            Move move = pieceMoves.moves[j];

            // check if this move potentially captures a king
            if (move.capturedPiece != NULL) {
                if (move.capturedPiece->notation == "K") return true;
            }
        }
    }

    // if we reach this we found no checks
    return false;
}

/**
 *  Method that checks if the player has castling rights given a certain
 *  board configuration
 *  @param turn (int) the player's turn
 */
std::vector<Moves> LegalMoveGenerator::checkCastling(int turn) {

    // initialize moves vector
    std::vector<Moves> moves;

    // extract the pieces
    Piece* king;
    Piece* rookQueenSide;
    Piece* rookKingSide;

    // get the king of the player who's turn it is
    for (int i=0; i<this->board->pieces.size(); i++) {
        
        // only generate moves for pieces that belong to the side who's turn it is
        if (this->board->pieces[i]->player != turn) {
            continue;
        }

        // extract king
        if (this->board->pieces[i]->notation != "K") {
            king = this->board->pieces[i];

        // we need both rooks
        } else if (this->board->pieces[i]->notation != "R") {
            
            // save the rook according to the information stored in the class 
            // about whether it's the short or long castle
            if (this->board->pieces[i]->side == "queen") rookQueenSide = this->board->pieces[i];
            else rookKingSide = this->board->pieces[i];
        }
    }

    std::cout << "ACTION 1, TURN " << turn << "\n";

    // if the king has moved we return an empty move list
    if (king->has_moved) return moves;

    // initialize boolean
    bool valid;

    // create vector of rooks to check for both castling sides
    std::vector<Piece*> rooks = {rookKingSide, rookQueenSide};

    // loop for both rooks
    for (int i=0; i<2; i++) {

        // get the right rook
        Piece* rook = rooks[i];

        std::cout << "ACTION " << i+2 << ", TURN " << turn << "\n";
        
        // determine if it's valid to castle
        valid = this->validateCastlingMove(king, rookKingSide, turn, "king");
        
        // If valid, we should add the king moves for short castling here
        if (valid) {

            // create moves here
            std::vector<Move> castleMoves;

            // get the direction for the king move
            int direction = rook->side == "king" ? 1 : -1;

            // decide amount of rooksteps, 2 on king side, 3 on queen side
            int rookSteps = rook->side == "king" ? 2: 3;
            
            // create the moves
            Move kingMove = { 
                .piece = king,
                .start = {king->y, king->x},
                .square = {king->y, king->x + (2*direction)},
            };
            Move rookMove = {
                .piece = rook,
                .start = {rook->y, rook->x},
                .square = {rook->y, rook->x - (rookSteps*direction)}
            };

            // add them
            castleMoves.push_back(kingMove);
            castleMoves.push_back(rookMove);
            
            // create a moves class with empty moves for the king holding the castling moves there
            Moves castling = Moves(king->notation, king->id, castleMoves);     
            castling.castling = true; // denote this is a castling move

            // add to moves
            moves.push_back(castling);
        }
    }

    // return the moves vector
    return moves;
}

/**
 *  Method that checks whether the short castling move is available
 *  Takes as input the king and the king side rook of a particular player
 *  @param king (Piece) the king that will move
 *  @param rook (Piece) the rook on the king side
 */
bool LegalMoveGenerator::validateCastlingMove(Piece* king, Piece* rook, int turn, std::string side){

    // first, check if rook has moved
    if (rook->has_moved) return false;

    // get the current rank position of the king
    int rank = king->y;

    /**
     *  Check for checks
     */
    bool check; // boolean denoting whether the king is in check

    // current position
    check = this->lookForChecks(turn);
    if (check) return false;

    // loop for two moves
    for (int i=1;i<3;i++) {

        // goal square
        std::array<int,2> goal;
        if (side == "king") goal = {king->y, king->x + i};
        else goal = {king->y, king->x - i};

        if (this->board->board[goal[0]][goal[1]] != 0) return false;

        // initialize a move struct here
        Move move = { 
            .piece = king,
            .start = {king->y, king->x},
            .square = {king->y, king->x + i},
        };  

        // make the move (boolean denotes this is pseudo)
        this->board->move(move, true);

        // look for checks
        check = this->lookForChecks(turn);
        if (check) return false;

        // undo move
        this->board->undo(move);
    }

    // if we make it here, it's valid!
    return true;
};

/**
 *  Method to print all the available moves of the current board configurations
 *  Mainly used for debugging
 *  @param turn (int) 0 for black's turn and 1 for white's turn
 */
void LegalMoveGenerator::printMoves(int turn) {

    // generate the moves
    std::vector<Moves> moves;
    moves = this->generate(turn);

    // print the available moves
    for (int i=0; i<moves.size(); i++) {
        
        // extract the move notations
        for (int j=0; j<moves[i].notations.size(); j++) {

            // print the notation
            std::cout << moves[i].notations[j] << " ";
        }
        
        // start newline?
        std::cout << '\n';
    }

}
