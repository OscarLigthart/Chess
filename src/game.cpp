/**
 *  Implementation of the game class
 * 
 *  The game class is the place where everything comes together
 *  end-to-end, it will process the clicked file all the way up
 *  to checking the validity of the move and making it happen
 */


#include <game.hpp>
#include <game/legal_move_generator.hpp>
#include <game/moves.hpp>
#include <interface.hpp>
#include <board.hpp>
#include <iostream>

Game::Game(Board &board) {
    
    // inherit the board
    this->board = &board;

    // initialize the legal move generator
    this->lgm = new LegalMoveGenerator(board);

    // generate all the moves for the player who's turn it is
    this->moves = this->lgm->generate(this->turn);

    this->lgm->printMoves(this->turn);

}

/**
 *  Function to process clicked squares on the board
 *  @param y the clicked rank of the board
 *  @param x the clicked file of the board
 */
void Game::process(Piece* selectedPiece, int y, int x) {
    
    // the requested move should be in the valid moves
    for (int i=0; i<this->moves.size(); i++) {
        
        // print the moves
        // todo need to have a better ID for every piece
        if (this->moves[i].pieceId == selectedPiece->id) {
            
            // check if any of the moves is valid
            for (int j=0; j<this->moves[i].moves.size(); j++) {

                // extract the move
                Move move = this->moves[i].moves[j];

                // for the move to be valid the clicked square should be the goal of the move
                if (move.square[0] == y && move.square[1] == x){
                    
                    // perform the move
                    this->board->move(move);

                    // set the other turn
                    this->turn = !this->turn;

                    // generate the newly valid moves
                    this->moves = this->lgm->generate(this->turn);

                    // check if the game might be over
                    this->checkGameOver();

                    // stop here
                    return;
                }

                // here we should check for castling
                // king should have a move labelled castling

                // generate a new moves object under the king, this one should have the move of the rook as well

            }
        }
    }

    // if we made it this far we have to move the piece back, as it was no legal move
    selectedPiece->move(selectedPiece->y, selectedPiece->x);
}

/**
 *  Method that checks whether the game is over
 */
void Game::checkGameOver() {

    // check for checkmate
    if (this->moves.size() == 0) std::cout << "Checkmate!" << "\n";


    // check for stalemate

}