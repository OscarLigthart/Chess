/**
 *  Implementation of the Rook
 */

#include <iostream>
#include <pieces/rook.hpp>

Queen::Queen(int player) {

    // let the world know we're creating a queen
    std::cout << "Creating Queen\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*3, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);  
}

bool Queen::isValidMove(int y, int x) {

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // rook and bishop combined
    if (dy == dx) {
        return true;
    } else if (this->x == x || this->y == y){
        return true;
    } else {
        return false;
    }
}

void Queen::setSpritePosition(int x, int y) { 

    // set the sprite position
    this->sprite.setPosition(x, y); 
}
