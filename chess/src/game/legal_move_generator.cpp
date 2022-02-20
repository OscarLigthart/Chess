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

            // make the move
            this->board->move(move);

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
    // std::vector<Moves> castleMoves = this->checkCastling(turn);

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

    // initialize Moves object 
    std::vector<Moves> moves;

    // extract the pieces?
    Piece* king;
    Piece* r1;
    Piece* r2;

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
            
            // extract the rooks one by one
            if (r1->id == NULL) r1 = this->board->pieces[i];
            else r2 = this->board->pieces[i];
        }
    }
        
    // create a moves class with empty moves for the king holding the castling moves there
    Moves kingMoves = Moves(king->notation, king->id, std::vector<Move> {});     

    // if the king has moved we return an empty move list
    if (king->has_moved) return moves;

    /**
     *  Check short castling
     */
    
    // short rook should not have moved

    // no pieces in between

    // none of the position where the king is should lead to a check

    /**
     *  Check long castling
     */

    // long rook should not have moved

    // no pieces in between

    // none of the position where the king is going to be should lead to a check

    /**
     *  Create the move
     */
    // we should create two moves, and label them as castling moves, so they can both be performed
    // by the engine


}

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
