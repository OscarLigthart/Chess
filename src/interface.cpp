/**
 *  Implementation of the Interface to control the game
 */

#include <iostream>
#include <interface.hpp>
#include <board.hpp>

/**
 *  Constructor
 */
Interface::Interface() {

    // start with moving is false
    this->moving = false;
}

/**
 *  Method to process the mouse input
 *  param x: integer depicting which file is clicked
 *  param y: integer depicting which rank is clicked
 */
void Interface::processInput(Board &board, int x, int y) {

    // pick up the piece
    if (!this->moving){

        // do something if there is a piece there
        // find out which piece it is as well
        this->square = board.board[y][x];

        // check which piece is placed there
        for (int i=0; i<32; i++) {
            if (board.pieces[i]->getPosition()[0] == y && board.pieces[i]->getPosition()[1] == x) {
                this->selectedPiece = i;

                std::cout << "Clicked\n";
                break;
            }
        };

        // indicate we start moving, if we have a piece on the square
        if (this->square) 
        {
            this->moving = !this->moving;    
        }

    // put down the piece
    }
    else {
        // update the board
        board.board[y][x] = this->square;

        std::cout << "Clicked\n";

        // move the piece to the center of the square
        board.pieces[this->selectedPiece]->move(y, x);
        
        // reset
        this->selectedPiece = -1;
        this->moving = !this->moving;
    }
}
