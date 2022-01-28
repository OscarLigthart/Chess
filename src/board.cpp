/**
 *  Implementation of the Board
 */

#include <iostream>
#include <board.hpp>
#include <piece.hpp>
#include <moves.hpp>
#include <pieces/bishop.hpp>
#include <pieces/king.hpp>
#include <pieces/knight.hpp>
#include <pieces/pawn.hpp>
#include <pieces/queen.hpp>
#include <pieces/rook.hpp>

#include <vector>
#include <array>

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
    this->buildPieces();
}

/**
 *  Method that constructs the board pieces
 */
void Board::buildPieces( ){

    // loop over entire board
    int k=0; // id tracker
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
                        piece = new Rook(player, k);
                        break;
                    }
                case 1: 
                    {
                        piece = new Knight(player, k);
                        break;
                    }
                case 2:
                    { 
                        piece = new Bishop(player, k);
                        break;
                    }
                case 3: 
                    {
                        piece = new Queen(player, k);
                        break;
                    }
                case 4: 
                    {   
                        piece = new King(player, k);
                        break;
                    }
                case 5: 
                    {
                        piece = new Pawn(player, k);
                        break;
                    }
            }

            // place piece correctly
            piece->setSpritePosition(this->piece_size*j, this->piece_size*i);
            piece->setPosition(i, j);

            // add to vector
            this->pieces.push_back(piece);

            // add to k
            k++;
        }
}

/**
 *  Method to remove a captured piece from the board
 */
void Board::removePiece(Piece* p){
    
    // delete the piece object
    delete p;

    // index of piece to be removed
    int index;

    // find index of piece in list
    for (int i=0; i<this->pieces.size(); i++) {
        if (p->id == this->pieces[i]->id) index = i;
    }

    // remove it from the list
    this->pieces.erase(this->pieces.begin() + index);
}

/**
 *  Method to print the board
 */
void Board::print() {

    std::cout << "PRINTING BOARD" << "\n";
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            std::cout << this->board[i][j] << " ";
        }
        std::cout << "\n";
    }        
}
