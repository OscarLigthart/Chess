/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE_KNIGHT_H
#define PIECE_KNIGHT_H

#include <SFML/Graphics.hpp>
#include <piece.hpp>

class Knight: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    using Piece::id;
    using Piece::player;
    using Piece::notation;

    /**
     *  Constructor
     */
    Knight (int player, int id);

    /**
     *  Method to check if move is valid
     */ 
    bool isValidMove(int y, int x);

    /**
     *  Method that retrieves all moves for this piece
     */ 
    std::vector<std::array<int, 2>> getMoves(int board[8][8]);

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