/**
 *  Implementation of the Board
 */

#include <iostream>
#include <board.hpp>
#include <game/moves.hpp>
#include <piece.hpp>
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
    int idCounter=0; // id tracker
    for (int rank=0;rank<8;rank++)
      for (int file=0;file<8;file++)
        {
            // get piece code from board engine
            int n = this->board[rank][file];
            if (!n) continue; // if 0 there is no piece

            // determine which color piece should be used
            int pieceId = abs(n) - 1;
            int player = n > 0 ? 1 : 0;
            
            // initialize the piece
            Piece* piece;

            switch(pieceId) {
                case 0:
                    {
                        piece = new Rook(player, idCounter, file);
                        break;
                    }
                case 1: 
                    {
                        piece = new Knight(player, idCounter);
                        break;
                    }
                case 2:
                    { 
                        piece = new Bishop(player, idCounter);
                        break;
                    }
                case 3: 
                    {
                        piece = new Queen(player, idCounter);
                        break;
                    }
                case 4: 
                    {   
                        piece = new King(player, idCounter);
                        break;
                    }
                case 5: 
                    {
                        piece = new Pawn(player, idCounter);
                        break;
                    }
            }

            // place piece correctly
            piece->setSpritePosition(this->piece_size*file, this->piece_size*rank);
            piece->setPosition(rank, file);

            // add to vector
            this->pieces.push_back(piece);

            // add to k
            idCounter++;
        }
}

/**
 *  Method to remove a captured piece from the board
 */
void Board::removePiece(Piece* p){
    
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
 *  Method to perform a single move on the board
 *  @param move (Move) the move struct object holding all info to make the move
 */
void Board::move(Move move) {

    // get the square on the board the piece was originally at
    int square = this->board[move.start[0]][move.start[1]];

    // save the old board
    for (int i=0; i<8;i++)
      for (int j=0; j<8; j++) {
          this->oldBoard[i][j] = this->board[i][j];
      }

    if (move.capturedPiece != NULL) {
        std::cout << this->pieces.size() << "\n";
    }
    
    // update the board with the piece position
    this->board[move.square[0]][move.square[1]] = square;

    // old square should be zero, as there will no longer be a piece
    this->board[move.start[0]][move.start[1]] = 0;

    // make the move for the piece
    move.piece->move(move.square[0], move.square[1]);

    // check for capture here
    // if we capture, remove the piece from the pieces list
    if (move.capturedPiece != NULL) {
        this->removePiece(move.capturedPiece);
    }

    return;
}

/**
 *  Method to undo a given move on the board
 *  @param move (Move) the move struct object holding all info to make the move
 */
void Board::undo(Move move) {

    // go back to old board
    for (int i=0; i<8;i++)
      for (int j=0; j<8; j++) {
          this->board[i][j] = this->oldBoard[i][j];
      }

    // put captured piece back
    if (move.capturedPiece != NULL) {
        this->pieces.push_back(move.capturedPiece);
    }

    // make the move for the piece to the old
    move.piece->move(move.start[0], move.start[1]);

    return;
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
