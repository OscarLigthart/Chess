/**
 *  Implementation of the Bishop piece
 */

#include <iostream>
#include <pieces/bishop.hpp>
#include <board.hpp>
#include <vector>
#include <array>


Bishop::Bishop(int player) {

    // let the world know we're creating a bishop
    std::cout << "Creating Bishop\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*2, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f); 

    // set the player var
    this->player = player;
}

bool Bishop::isValidMove(int y, int x) {

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // difference needs to be equal to go diagonal
    if (dy == dx) {
        return true;
    } else {
        return false;
    }
}

/**
 *  Method that retrieves all moves for this piece
 *
 *  @return list of arrays depicting a diagonal in coordinates
 */ 
std::vector<std::array<int, 2>> Bishop::getMoves(int board[8][8]) {

    // generate the directions to move in
    int directions[4][2] = {{-1,1},{1,1},{-1,-1}, {1, -1}};

    // initialize valid move list
    std::vector<std::array<int,2>> moves;

    // loop over diagonals
    for (int i=0; i<4; i++) {
        
        // set the current position to the actual position
        std::array<int,2> start = {this->y, this->x};

        // keep going down this diagonal as long as we're not out of bounds
        bool invalid = false;

        while (!invalid){

            // take current position and add the direction
            std::array<int,2> new_move = {start[0] + directions[i][0], start[1] + directions[i][1]};

            // start by checking for out of bounds
            bool outOfBounds = this->checkOutOfBounds(new_move[1], new_move[0]);

            // stop if we are out of bounds
            if (outOfBounds) { break; }
            
            // retrieve the piece that is placed on the square of the new move
            int square = board[new_move[0]][new_move[1]];

            // check for collisions
            bool collision = this->checkCollision(moves, new_move, square);

            // if we collided we should stop
            if (collision) { break; }

            // if we reach this we can add the move to the total moves
            moves.push_back(new_move);

            // overwrite the start with the newly generated move to continue following the path
            start = new_move;
        }
    }

    // the total set of valid moves
    return moves;
}

void Bishop::setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }
