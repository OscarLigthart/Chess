/**
 *  Implementation of the Bishop piece
 */

#include <iostream>
#include <pieces/bishop.hpp>


Bishop::Bishop(int player) {

    // let the world know we're creating a bishop
    std::cout << "Creating Bishop\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*2, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f); 
}

bool Bishop::isValidMove(int y, int x) {

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // difference needs to be equal to go diagonal
    if (dy == dx) {
        return true;
    } else {
        return false;
    }
}

void Bishop::setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }
