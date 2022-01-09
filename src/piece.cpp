/**
 *  Class that holds the base logic of a piece
 */

// #include <SFML/Graphics.hpp>
#include <iostream>
#include <piece.hpp>

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
