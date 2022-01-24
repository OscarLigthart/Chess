/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef LEGAL_MOVE_GENERATOR
#define LEGAL_MOVE_GENERATOR

#include <board.hpp>
#include <moves.hpp>


class LegalMoveGenerator 
  {
    public:
    Board* board;

    /**
     *  Constructor
     */    
    LegalMoveGenerator(Board &board);

    /**
     *  Method to generate all possible moves given a board configuration
     */
    std::vector<Moves> generate();
};

#endif