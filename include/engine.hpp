/**
 *  Header file of the game engine
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <board.hpp>
#include <piece.hpp>
#include <legal_move_generator.hpp>


class Engine 
  {
    public:
    Board* board;
    LegalMoveGenerator* lgm;
    int turn = 1; // 1 for white and 0 for black


    /**
     *  Constructor
     */    
    Engine(Board &board);

    /**
     *  Function to process clicked squares on the board
     *  @param selectedPiece (piece) the piece that has been selected to move
     *  @param y the clicked rank of the board
     *  @param x the clicked file of the board
     */
    void process(Piece* selectedPiece, int y, int x);
};

#endif