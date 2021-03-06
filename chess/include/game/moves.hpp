/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <vector>
#include <array>
#include <piece.hpp>

/**
 *  Struct depicting a single move of a single piece
 */
struct Move
  {
    Piece* piece; // the piece that wants to make the move
    std::array<int,2> start;  // the start square from which the piece wants to move
    std::array<int,2> square; // the square to which the piece wants to go
    Piece* capturedPiece = NULL; // a potentially captured piece on the goal square
  };

/** 
 *  Class depicting the full set of moves for a given piece
 */
class Moves 
  {
    public:

    // inner variables
    int pieceId;
    std::string piece;
    std::vector<Move> moves;
    std::vector<std::string> notations; // human readable chess move notations
    bool castling = false; // boolean denoting whether this moveset is a castling move

    /**
     *  Constructor
     */    
    Moves(std::string piece, int pieceId, std::vector<Move> moves);
    
    /**
     *  Method to convert the moves into human readable notations
     */
    void generateNotations();
};

#endif