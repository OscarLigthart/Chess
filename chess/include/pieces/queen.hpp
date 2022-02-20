/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE_QUEEN_H
#define PIECE_QUEEN_H

#include <SFML/Graphics.hpp>
#include <piece.hpp>

class Queen: public Piece 
{           // The class
  public:               // Access specifier
    sf::Sprite sprite;  // the sprite for the piece
    using Piece::id;
    using Piece::player;
    using Piece::notation;
    // using Piece::figures;

    /**
     *  Constructor
     */
    Queen (int player, int id, int rank, int file);

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
