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
     *  for the white or black player
     *  @param turn (int) 0 for black's turn and 1 for white's turn
     */
    std::vector<Moves> generate(int turn);

    /**
     *  Method to print all the available moves of the current board configurations
     *  Mainly used for debugging
     *  @param turn (int) 0 for black's turn and 1 for white's turn
     */
    void printMoves(int turn);    
};

#endif