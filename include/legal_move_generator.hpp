/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef LEGAL_MOVE_GENERATOR
#define LEGAL_MOVE_GENERATOR

#include <board.hpp>


class LegalMoveGenerator 
  {
    public:

    /**
     *  Constructor
     */    
    LegalMoveGenerator();

    void generate(Board &board);

};

#endif