/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE
#define PIECE

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

    /**
     *  Constructor
     */
    Piece ();

    /**
     *  Method to move the piece from one place to the other
     *  Inherently changes the position of the piece and returns a boolean
     *  denoting whether the move is valid
     */
    bool move(int y, int x);

    /**
     *  Method to check if move is valid
     *  We just return true here because this function will be overwritten by the children
     */ 
    virtual bool isValidMove(int y, int x) { return true; }

    /**
     *  Method to change the position on the board
     */
    void setPosition(int y, int x);

    /**
     *  Method to retrieve the position
     */
    int* getPosition() { return this->position; }

    /** 
     *  Method to retrieve the sprite
     */ 
    virtual sf::Sprite getSprite() { return this->sprite; } 
    virtual void setSpritePosition(int x, int y);

    /**
     *  Method to remove the piece from play
     */
    void remove(void);
};

#endif
