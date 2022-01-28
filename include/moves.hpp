/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <vector>
#include <array>


/** 
 *  Class depicting the full set of moves for a given piece
 */
class Moves 
  {
    public:

    // inner variables
    int pieceId;
    std::string piece;
    std::vector<std::array<int, 2>> moves;
    std::vector<std::string> notations; // human readable chess move notations
    

    /**
     *  Constructor
     */    
    Moves(std::string piece, int pieceId, std::vector<std::array<int, 2>> moves);
    
    /**
     *  Method to convert the moves into human readable notations
     */
    void generateNotations();
};

/**
 *  Struct depicting a single move of a single piece
 */
struct Move
  {
    public:

    std::array<int,2> square; // the square to which the piece wants to go
    Piece* capturedPiece; // a potentially captured piece on the goal square
  }

#endif