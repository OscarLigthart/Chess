/**
 *  Implementation of the Bishop piece
 */

#include <iostream>
#include <pieces/bishop.hpp>
#include <board.hpp>


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
int Bishop::getMoves(Board &board, int y, int x) {

    // generate the directions to move in
    int directions[4][2] = {{-1,1},{1,1},{-1,-1}, {1, -1}}

    // initialize valid move list
    int moves[][];

    // loop over diagonals
    for (int i=0; i<4; i++) {

        // keep going down thi sdiagonal as long as we're not out of bounds
        bool invalid = false;
        while (!invalid){
            
            // take current position and add the direction
            int new_move[] = {y + directions[i][0], x + directions[i][1]}

            // now test if we hit a piece or are out of bounds


        }

    }

}



void Bishop::setSpritePosition(int x, int y) { this->sprite.setPosition(x, y); }
