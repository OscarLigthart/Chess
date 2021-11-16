/**
 *  Class that holds the base logic of a piece
 */

#include <SFML/Graphics.hpp>

class Piece {               // The class
  public:                   // Access specifier
    int position[2];        // position in x and y coordinates
    int size = 56;          // required for cutting out the pieces 
    int myInt = 0;
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
     */
    void move(int position[2]) {
        
        this->isValidMove(position);
    }

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int position[2]){

        return true;
    }

    /**
     *  Method to change the position on the board
     */
    void setPosition(int y, int x) {
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