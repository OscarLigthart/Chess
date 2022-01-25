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
     *  @param turn (string) white | black player's turn
     */
    std::vector<Moves> generate(std::string turn);

    /** 
     *  Method to pretty print all available move notations given a board configurations
     */
    void printMoves();    
};

#endif