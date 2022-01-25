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
 *  Generate function
 */
std::vector<Moves> LegalMoveGenerator::generate(std::string turn){

    // initialize moves
    std::vector<Moves> moves;

    // convert the string of the turn into the right playervalue
    int playerTurn = turn == "white" ? -1 : 1;

    // loop over all the pieces on the board
    for (int i=0; i<this->board->pieces.size(); i++) {

        if (this->board->pieces[i]->playerValue != playerTurn) {
            continue;
        }
        
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

    return moves;
}

/**
 *  Method to print all the available moves of the current board configurations
 *  Mainly used for debugging
 */
void LegalMoveGenerator::printMoves() {

    // generate the moves
    std::vector<Moves> moves;
    moves = this->generate();

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
