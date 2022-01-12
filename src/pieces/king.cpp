/**
 *  Implementation of the King
 */

#include <iostream>
#include <pieces/king.hpp>


/**
 *  Constructor
 */
King::King(int player) {

    // let the world know we're creating a king
    std::cout << "Creating King\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    this->sprite.setTextureRect( sf::IntRect(this->size*4, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);
}

bool King::isValidMove(int y, int x){

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // only a single step
    if ((dy == 1 || dx == 1) && (dy < 2 && dx < 2)) {
        return true;
    } else {
        return false;
    }
}

void King::setSpritePosition(int x, int y) { 
    
    // change position of sprite
    this->sprite.setPosition(x, y); 
}
