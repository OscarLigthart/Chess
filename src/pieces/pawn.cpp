/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>

class Pawn: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    int player;
    bool has_moved = false;
    Pawn (int player)
    {
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

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x){

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

    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }
    void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

};