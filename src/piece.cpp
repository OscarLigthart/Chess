/**
 *  Class that holds the base logic of a piece
 */

#include <iostream>
#include <piece.hpp>

#include <vector>
#include <array>

Piece::Piece() {

    // let the world know we're creating the pieces
    std::cout << "Creating Piece\n";

    // set the texture here
    figures.loadFromFile("../img/pieces.png");
}

bool Piece::move(int y, int x) {

    if (!this->isValidMove(y, x)) { 

        // move to old position
        this->setSpritePosition(this->piece_size * this->x, this->piece_size * this->y);
        this->setPosition(this->y, this->x);

        // stop here
        return false; 
    }

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
bool * Piece::checkCollision(std::array<int, 2> new_move, int square) {

    // we need two booleans to denote a collision and whether that is with an
    // opponent's piece
    static bool b[2] = {false, false};

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

void Piece::setPosition(int y, int x) {
    this->y = y;
    this->x = x;

    this->position[0] = y;
    this->position[1] = x;
}

void Piece::setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

void Piece::remove(void) {
    // todo implement
}
