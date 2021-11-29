/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>

class Piece {               // The class
  public:                   // Access specifier
    int y;                  // position in y coordinates
    int x;                  // position in x coordinates
    int position[2];
    int size = 56;          // required for cutting out the pieces 
    int piece_size = 100;   // 800/8
    sf::Texture figures;    // the texture for all the pieces
    sf::Sprite sprite;      // the sprite for the piece

    Piece ()
    {
        std::cout << "Creating Piece\n";

        // set the texture here
        figures.loadFromFile("../img/pieces.png");
    }

    /**
     *  Method to move the piece from one place to the other
     *  Inherently changes the position of the piece and returns a boolean
     *  denoting whether the move is valid
     */
    bool move(int y, int x) {
        
        if (!this->isValidMove(y, x)) { 

            // move to old position
            this->setSpritePosition(this->piece_size * this->x, this->piece_size * this->y);
            this->setPosition(this->y, this->x);

            // stop here
            return false; 
        }

        // change the position of the piece
        this->setSpritePosition(this->piece_size * x, this->piece_size * y);
        this->setPosition(y, x);
    }

    /**
     *  Method to check if move is valid
     */ 
    virtual bool isValidMove(int y, int x){

        return true;
    }

    /**
     *  Method to change the position on the board
     */
    void setPosition(int y, int x) {
        this->y = y;
        this->x = x;

        this->position[0] = y;
        this->position[1] = x;
    }

    int* getPosition() {
        return this->position;
    }

    /** 
     *  Method to retrieve the sprite
     */ 
    virtual sf::Sprite getSprite() { return this->sprite; } 
    virtual void setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }

    /**
     *  Method to remove the piece from play
     */
    void remove(void) {
        // todo implement
    }
};