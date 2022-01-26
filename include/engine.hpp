/**
 *  Header file of the game engine
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <board.hpp>
#include <legal_move_generator.hpp>



class Engine 
  {
    public:
    Board* board;
    LegalMoveGenerator* lgm;
    int turn = 1; // 1 for white and 0 for black

    Piece* selectedPiece; // the code of the piece that is selected and therefore needs to be moved
    bool moving; // determine whether we are currently moving a piece


    /**
     *  Constructor
     */    
    Engine(Board &board);

    /**
     *  Function to process clicked squares on the board
     *  @param y the clicked rank of the board
     *  @param x the clicked file of the board
     */
    void process(int y, int x);

};

#endif