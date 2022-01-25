/**
 *  Implementation of the Interface to control the game
 */

#include <iostream>
#include <interface.hpp>
#include <board.hpp>
#include <vector>

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

    // do something if there is a piece there
    // find out which piece it is as well
    this->square = board.board[y][x];

    for (int i=0; i<32; i++) std::cout << board.pieces[i]->notation << ' ';

    // check which piece is placed there
    for (int i=0; i<32; i++) {
        if (board.pieces[i]->getPosition()[0] == y && board.pieces[i]->getPosition()[1] == x) {
            this->selectedPiece = board.pieces[i];

            // insert this piece at the start and remove it from the list
            board.pieces.push_back(board.pieces[i]);
            board.pieces.erase(board.pieces.begin() + i);
            
            break;
        }
    };

    for (int i=0; i<32; i++) std::cout << board.pieces[i]->notation << ' ';

    // indicate we start moving, if we have a piece on the square
    if (this->square) 
    {
        this->moving = !this->moving;    
    }
}

void Interface::reset(){
    
    // reset variables
    this->moving = !this->moving;
}
