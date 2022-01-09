/**
 *  Implementation of the Rook
 */

#include <pieces/rook.hpp>

Rook::Rook(int player) {

    // let the world know that a rook has been created
    std::cout << "Creating Rook\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");

    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*0, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);  
}

bool Rook::isValidMove(int y, int x) {
    // to go straight, one coordinate needs to stay equal  
    if (this->x == x || this->y == y) {
        return true;
    } else {
        return false;
    }
}

void Rook::setSpritePosition(int x, int y) { 

    // set the sprite position
    this->sprite.setPosition(x, y); 
}
