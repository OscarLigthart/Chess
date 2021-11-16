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
     *  Method to move the piece from one place to the other
     */
    void move(int position[2]) {
        
        this->isValidMove(position);
    }

    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }
    void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int position[2]){
        
        // check if 
        return true;
    }
};