/**
 *  Implementation of the King
 */

#include <iostream>
#include <pieces/king.hpp>


/**
 *  Constructor
 */
King::King(int player, int id) {

    // let the world know we're creating a king
    std::cout << "Creating King\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    this->sprite.setTextureRect( sf::IntRect(this->size*4, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);

    this->player = player;
    this->id = id;
    this->notation = "K";
}

bool King::isValidMove(int y, int x){

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // only a single step
    if ((dy == 1 || dx == 1) && (dy < 2 && dx < 2)) {
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
std::vector<std::array<int, 2>> King::getMoves(int board[8][8]) {

    // generate the directions to move in
    int directions[8][2] = {{-1,0},{1,0},{0,-1}, {0,1},{-1,1},{1,1},{-1,-1},{1, -1}};

    // initialize valid move list
    std::vector<std::array<int,2>> moves;

    // set the current position to the actual position
    std::array<int,2> start = {this->y, this->x};

    // loop over diagonals
    for (int i=0; i<8; i++) {
        
        // take current position and add the direction
        std::array<int,2> new_move = {start[0] + directions[i][0], start[1] + directions[i][1]};

        // start by checking for out of bounds
        bool outOfBounds = this->checkOutOfBounds(new_move[0], new_move[1]);

        // stop if we are out of bounds
        if (outOfBounds) { continue; }
        
        // retrieve the piece that is placed on the square of the new move
        int square = board[new_move[0]][new_move[1]];

        // check for collisions, and whether they arrise with an opponent's piece or not
        std::array<bool, 2> collision = this->checkCollision(new_move, square);

        // if we collided we should stop
        if (collision[0]) { 
            
            // if it was with another piece, we need to add the move as a possibility 
            if (collision[1]) { moves.push_back(new_move); }
            
            // stop the loop
            continue;
        }


        // if we reach this we can add the move to the total moves
        moves.push_back(new_move);
    }
    
    // the total set of valid moves
    return moves;
}

void King::setSpritePosition(int x, int y) { 
    
    // change position of sprite
    this->sprite.setPosition(x, y); 
}
