/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>

class Rook: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    Rook (int player)
    {
        std::cout << "Creating Bishop\n";

        // set the texture here
        this->figures.loadFromFile("../img/pieces.png");
        // set the texture here
        this->sprite.setTexture(this->figures);

        // std::cout << this->size;
        this->sprite.setTextureRect( sf::IntRect(this->size*0, this->size*player, this->size, this->size)); 
        this->sprite.setScale(1.8f, 1.65f);   
    }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x){

        // to go straight, one coordinate needs to stay equal  
        if (this->x == x || this->y == y) {
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