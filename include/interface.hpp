/**
 *  Header file of the board
 */

#ifndef INTERFACE
#define INTERFACE

#include <board.hpp>


class Interface 
  {
    public:

    // variables required to run the interface
    bool moving; 
    int square; // the square which is clicked
    int selectedPiece; // the code of the piece that is selected

    /**
     *  Constructor
     */    
    Interface();

    /**
     *  Method to process the input
     *  param x: integer depicting which file is clicked
     *  param y: integer depicting which rank is clicked
     */
    void processInput(Board &board, int x, int y);
};

#endif