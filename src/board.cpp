/**
 *  Implementation of the Board
 */

#include <iostream>
#include <board.hpp>
#include <piece.hpp>
#include <pieces/bishop.hpp>
#include <pieces/king.hpp>
#include <pieces/knight.hpp>
#include <pieces/pawn.hpp>
#include <pieces/queen.hpp>
#include <pieces/rook.hpp>

Board::Board( ){

    // let the world know the board has been constructed
    std::cout << "Board constructed\n";

    // set the textures
    this->boardSprite.setScale(0.8f, 0.8f);
    for (int i=0; i<32; i++) {
        this->f[i].setTexture(this->figures);
        this->f[i].setScale(1.8f, 1.65f);
    }

    // build the pieces on initialization
    buildPieces();
}

/**
 *  Method that constructs the board pieces
 */
void Board::buildPieces( ){

    // loop over entire board
    int k=0;
    for (int i=0;i<8;i++)
      for (int j=0;j<8;j++)
        {
            // get piece code from board engine
            int n = this->board[i][j];
            if (!n) continue; // if 0 there is no piece

            // determine which color piece should be used
            int pieceId = abs(n) - 1;
            int player = n > 0 ? 1 : 0;
            
            // initialize the piece
            Piece* piece;

            switch(pieceId) {
                case 0:
                    {
                        piece = new Rook(player);
                        break;
                    }
                case 1: 
                    {
                        piece = new Knight(player);
                        break;
                    }
                case 2:
                    { 
                        piece = new Bishop(player);
                        break;
                    }
                case 3: 
                    {
                        piece = new Queen(player);
                        break;
                    }
                case 4: 
                    {   
                        piece = new King(player);
                        break;
                    }
                case 5: 
                    {
                        piece = new Pawn(player);
                        break;
                    }
            }

            // place piece correctly
            piece->setSpritePosition(this->piece_size*j, this->piece_size*i);
            piece->setPosition(i, j);

            // add to vector
            this->pieces.push_back(piece);
        }
}

/**
 *  Method to process the user input to the board
 *  param square: the clicked square
 *  param selectedPiece: the code of the selected piece 
 *  param y: the clicked rank
 *  param x: the clicked file
 */
void Board::process(int square, int selectedPiece, int y, int x) {

    // update the board
    this->board[y][x] = square;

    // todo, maybe check legal moves here already?

    // move the piece to the center of the square
    this->pieces[selectedPiece]->move(y, x);

    // check gamestate here
    // checks
    // checkmate
    // etc etc
}