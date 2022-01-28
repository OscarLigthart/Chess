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

    // initialize moves
    std::vector<Moves> moves;

    // loop over all the pieces on the board
    for (int i=0; i<this->board->pieces.size(); i++) {
        
        // only generate moves for pieces that belong to the side who's turn it is
        if (this->board->pieces[i]->player != turn) {
            continue;
        }
        
        // extract the piece name
        Piece* piece = this->board->pieces[i];

        // generate the moves
        std::vector<std::array<int, 2>> piece_moves;
        piece_moves = piece->getMoves(this->board->board);

        // check for capture
        // need to see where the moves end up
        // then find which piece is on that square, if any
        // then add that piece as object to this move

        // convert to move class
        Moves move = Moves(piece->notation, piece->id, piece_moves);

        // add this move to all the moves
        moves.push_back(move);
    } 

    return moves;
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
