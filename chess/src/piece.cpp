/**
 *  Class that holds the base logic of a piece
 */

#include <iostream>
#include <piece.hpp>

#include <vector>
#include <array>

/**
 *  Constructor
 */
Piece::Piece() {}

void Piece::move(int y, int x) {

    // change the position of the piece
    this->setSpritePosition(this->piece_size * x, this->piece_size * y);
    this->setPosition(y, x);
}

std::vector<std::array<int, 2>> Piece::getMoves(int board[8][8]) {

    // mock getting moves (will be overwritten anyway)
    std::vector<std::array<int, 2>> weights;
    std::array<int, 2> weight = {1, 2};
    weights.push_back(weight);

    return weights;
}

/**
 *  Method that checks if a suggested move yields a collision
 *  and whether that collision is with your own or an opponents piece
 *
 *  @return boolean array holding 2 booleans: 
 *             {
 *                  collision (true|false),
 *                  opponent's piece (true|false)
 *             }
 */ 
std::array<bool, 2> Piece::checkCollision(std::array<int, 2> new_move, int square) {

    // we need two booleans to denote a collision and whether that is with an
    // opponent's piece
    std::array<bool, 2> b = {false, false};

    // only check if we find a piece on the square
    if (square != 0){
        
        // black player
        if (this->player == 0){
            
            // opponent's piece
            if (square > 0) {
                b[1] = true;
            }

            // we should stop here
            b[0] = true;
        }

        // white player
        else {
            
            // opponent's piece
            if (square < 0) {
                b[1] = true;
            }

            // we should stop here 
            b[0] = true;
        }
    }

    return b;
}

/**
 *  Method checks if the desired coordinates are out of bounds
 */ 
bool Piece::checkOutOfBounds(int y, int x) {

    // check for out of bounds y
    if (y < 0 || y > 7) {
        return true;
    }

    // check for out of bounds x
    else if (x < 0 || x > 7){
        return true;
    }

    // if we reach this we are in bounds
    else {
        return false;
    }
}

/**
 *  Method to set the piece to a new position
 */
void Piece::setPosition(int y, int x) {

    // denote that this piece has moved
    this->has_moved = true;

    // move the piece
    this->y = y;
    this->x = x;
}

void Piece::setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

void Piece::remove(void) {
    // todo implement
}
