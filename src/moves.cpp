/**
 *  Implementation of the Moves
 *  This class takes a pieces moves and encapsulates them
 */

#include <moves.hpp>
#include <string>
#include <vector>
#include <array>
#include <iostream>

/**
 *  Constructor
 */
Moves::Moves(std::string piece, int pieceId, std::vector<std::array<int, 2>> moves) {

    // save the incoming variables
    this->piece = piece;
    this->pieceId = pieceId;
    this->moves = moves;

    // generate the human readable moves
    this->generateNotations();
}

/**
 *  Method to convert the moves into human readable notations
 */
void Moves::generateNotations(){
    
    // loop over the amount of moves
    for (int i; i<this->moves.size(); i++) {

        // initialize a move string
        std::string notation;

        // start string with the piece name
        notation += this->piece;

        // convert the file first
        notation += static_cast<char>('a' + this->moves[i][1]);

        // convert the first (y) into the rank
        notation += std::to_string(8 - this->moves[i][0]);

        // add this to the notations
        this->notations.push_back(notation);
    }
}