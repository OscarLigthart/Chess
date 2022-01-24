/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <vector>
#include <array>


class Moves 
  {
    public:

    // inner variables
    std::string piece;
    std::vector<std::array<int, 2>> moves;
    std::vector<std::string> notations; // human readable chess move notations

    /**
     *  Constructor
     */    
    Moves(std::string piece, std::vector<std::array<int, 2>> moves);
    
    /**
     *  Method to convert the moves into human readable notations
     */
    void generateNotations();
};

#endif