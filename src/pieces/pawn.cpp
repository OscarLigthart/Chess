/**
 *  Implementation of the Pawn
 */

#include <iostream>
#include <pieces/pawn.hpp>


/**
 *  Constructor
 */ 
Pawn::Pawn(int player) {

    // let the world know we're creating a pawn
    std::cout << "Creating Pawn\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*5, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f); 

    // set player
    this->player = player == 1 ? 1 : -1;  
}

bool Pawn::isValidMove(int y, int x) {

    // get difference in movement
    int dy = this->y - y;
    int dx = std::abs(this->x - x);

    if (dy == player && dx == 0) {
        return true;
    } else if (dy == player * 2 && dx == 0 && !this->has_moved){
        this->has_moved = true;
        return true;
    } else {
        return false;
    }
}

void Pawn::setSpritePosition(int x, int y) { 

    // set the sprite position
    this->sprite.setPosition(x, y); 
}
