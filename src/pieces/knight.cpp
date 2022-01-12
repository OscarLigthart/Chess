/**
 *  Implementation of the knight piece
 */

#include <iostream>
#include <pieces/knight.hpp>


/**
 *  Constructor
 */
Knight::Knight(int player) {
    
    // let the world know we're creating a knight
    std::cout << "Creating Knight\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*1, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);   
}

bool Knight::isValidMove(int y, int x) {

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // difference should be one and both should be lower than 3
    if ((dx == 2 || dx == 1) && (dy == dx % 2 + 1)) {
        return true;
    } else {
        return false;
    }   
}

void Knight::setSpritePosition(int x, int y) { 

    // change sprite position
    this->sprite.setPosition(x, y); 
}
