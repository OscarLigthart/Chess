/**
 *  Class that holds the base logic of a piece
 */

#ifndef PIECE
#define PIECE

#include <SFML/Graphics.hpp>
#include <string>

class Piece {               // The class
  public:                   // Access specifier
    int y;                  // position in y coordinates
    int x;                  // position in x coordinates
    int piece_size = 100;   // 800/8
    int player;
    int id;          // the ID of the piece
    bool has_moved = false; // boolean whether the piece has moved
    std::string castle;     // we need to keep track of whether a rook is the one for long or short castling
    std::string notation;   // variable denoting the chess notation of the piece
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
    void move(int y, int x);

    /**
     *  Method to check if move is valid
     *  We just return true here because this function will be overwritten by the children
     */ 
    virtual bool isValidMove(int y, int x) { return true; }

    /**
     *  Method that retrieves all moves for a piece
     */ 
    virtual std::vector<std::array<int, 2>> getMoves(int board[8][8]);

    /**
     *  Method to check for collisions
     */
    std::array<bool, 2> checkCollision(std::array<int, 2> new_move, int square);

    /**
     *  Method to check if desired location is out of bounds
     */
    bool checkOutOfBounds(int y, int x);

    /**
     *  Method to change the position on the board
     */
    virtual void setPosition(int y, int x);

    /**
     *  Method to retrieve the position
     */
    std::array<int,2> getPosition() { return std::array<int,2> {this->y, this->x}; }

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
