/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>


class King: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    King (int player)
    {
        std::cout << "Creating King\n";

        // set the texture here
        this->figures.loadFromFile("../img/pieces.png");
        // set the texture here
        this->sprite.setTexture(this->figures);

        // std::cout << this->size;
        this->sprite.setTextureRect( sf::IntRect(this->size*4, this->size*player, this->size, this->size)); 
        this->sprite.setScale(1.8f, 1.65f);   
    }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x){
        
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


    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }
    void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

};