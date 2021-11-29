/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>


class Knight: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    Knight (int player)
    {
        std::cout << "Creating Knight\n";

        // set the texture here
        this->figures.loadFromFile("../img/pieces.png");
        // set the texture here
        this->sprite.setTexture(this->figures);

        // std::cout << this->size;
        this->sprite.setTextureRect( sf::IntRect(this->size*1, this->size*player, this->size, this->size)); 
        this->sprite.setScale(1.8f, 1.65f);   
    }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x){

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

    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }
    void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

};