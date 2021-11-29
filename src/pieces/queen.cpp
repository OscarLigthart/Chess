/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>

class Queen: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    Queen (int player)
    {
        std::cout << "Creating Queen\n";

        // set the texture here
        this->figures.loadFromFile("../img/pieces.png");
        // set the texture here
        this->sprite.setTexture(this->figures);

        // std::cout << this->size;
        this->sprite.setTextureRect( sf::IntRect(this->size*3, this->size*player, this->size, this->size)); 
        this->sprite.setScale(1.8f, 1.65f);   
    }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x){

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

    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }
    void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }
};