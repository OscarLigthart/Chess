/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE_PAWN_H
#define PIECE_PAWN_H

#include <SFML/Graphics.hpp>
#include <piece.hpp>

class Pawn: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    using Piece::id;
    using Piece::player;
    using Piece::notation;
    int playerValue; // the player value translated to -1 and 1
    using Piece::has_moved;

    /**
     *  Constructor
     */
    Pawn (int player, int id);

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

    /**
     *  Method to update the piece position
     */
    void setPosition(int y, int x);
};

#endif