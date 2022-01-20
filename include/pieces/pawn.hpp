/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE_PAWN
#define PIECE_PAWN

#include <SFML/Graphics.hpp>
#include <piece.hpp>

class Pawn: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    int player;
    bool has_moved = false;
    Pawn (int player);

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x);

    /**
     *  Method that retrieves all moves for this piece
     */ 
    int getMoves(int y, int x);

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