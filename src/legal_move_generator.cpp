/**
 *  Implementation of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#include <legal_move_generator.hpp>
#include <board.hpp>
#include <moves.hpp>
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

    // start by generating all the piece moves for this player's turn
    std::vector<Moves> allMoves = LegalMoveGenerator::generateAllPieceMoves(turn);

    // next we need to run the moves in a pseudo configuration

    // copy the board

    // loop over moves

    // make move

    // generate all moves for pieces (own player only)

    // loop over all of these moves and check if the king is among the capturedPieces

    // if not the move is valid, if yes the move is invalid



    return allMoves;
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
