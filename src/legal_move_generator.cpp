/**
 *  Implementation of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#include <legal_move_generator.hpp>
#include <board.hpp>
#include <moves.hpp>
#include <piece.hpp>

/**
 *  Constructor
 */
LegalMoveGenerator::LegalMoveGenerator(Board &board) {

    // we need to store the board here
    this->board = &board;
}

/**
 *  Generate function
 */
std::vector<Moves> LegalMoveGenerator::generate(){

    // initialize moves
    std::vector<Moves> moves;

    // loop over all the pieces on the board
    for (int i=0; i<this->board->pieces.size(); i++) {
        
        // extract the piece name
        Piece* piece = this->board->pieces[i];

        // generate the moves
        std::vector<std::array<int, 2>> piece_moves;
        piece_moves = piece->getMoves(this->board->board);

        // convert to move class
        Moves move = Moves(piece->notation, piece_moves);

        // add this move to all the moves
        moves.push_back(move);
    } 
}
