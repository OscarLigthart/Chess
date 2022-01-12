/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE_QUEEN
#define PIECE_QUEEN

#include <SFML/Graphics.hpp>
#include <piece.hpp>

class Queen: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    Queen (int player);

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x);

    /** 
     *  Method to retrieve the sprite
     */ 
    sf::Sprite getSprite() { return this->sprite; }

    /**
     *  Method to update sprite position
     */ 
    void setSpritePosition(int x, int y);
};

#endif