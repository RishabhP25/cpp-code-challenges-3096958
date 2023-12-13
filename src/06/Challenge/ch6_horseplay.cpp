// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.

// std::vector<std::string> knight_moves(std::string knight){
//     std::vector<std::string> moves;
//     std::vector<std::string> alpha = {"a","b","c","d","e","f","g","h"};
//     std::vector<std::string> num = {"1","2","3","4","5","6","7","8"};
//     std::vector<std::string> allMoves;
//     int count = 0;
//     bool legalMove;

//     // Write your code here 
//     // storing all possible squares in the chess board to vector allMoves
//     for(int i = 0; i < alpha.size(); i++) {
//         for (int j = 0; j < num.size(); j++) {
//             allMoves.push_back(alpha[i] + num[j]);
//             count += 1;
//         }
//     }

//     auto it = std::find(allMoves.begin(), allMoves.end(), knight);

//     size_t index = std::distance(allMoves.begin(), it);

//     if (it != allMoves.end()) {
//         legalMove = true;
//     } else {
//         legalMove = false;
//     }
//     std::string move;
    

//     int indexMove1;
//     int indexMove2;

//     if (!legalMove) {
//         std::cout << "This move is illegal according to the chess board" << std::endl << std::endl << std::flush;
//     }

//     // forward  positions
//     if (legalMove) {
//         indexMove1 = index + 10;
//         indexMove2 = index - 6;
//         if (indexMove1 < allMoves.size()) {
//             move = allMoves[indexMove1];
//             moves.push_back(move);
//         }

//         if (indexMove2 < allMoves.size()) {
//             move = allMoves[indexMove2];
//             moves.push_back(move);
//         }

            
//     }

//     // down positions
//     if (legalMove) {
//         indexMove1 = index - 10;
//         indexMove2 = index + 6;
//         if (indexMove1 < allMoves.size()) {
//             move = allMoves[indexMove1];
//             moves.push_back(move);
//         }

//         if (indexMove2 < allMoves.size()) {
//             move = allMoves[indexMove2];
//             moves.push_back(move);
//         }

            
//     }

//     // right positions
//     if (legalMove) {
//         indexMove1 = index + 17;
//         indexMove2 = index + 15;
//         if (indexMove1 < allMoves.size()) {
//             move = allMoves[indexMove1];
//             moves.push_back(move);
//         }

//         if (indexMove2 < allMoves.size()) {
//             move = allMoves[indexMove2];
//             moves.push_back(move);
//         }

            
//     }

//     // left positions
//     if (legalMove) {
//         indexMove1 = index - 17;
//         indexMove2 = index - 15;
//         if (indexMove1 < allMoves.size()) {
//             move = allMoves[indexMove1];
//             moves.push_back(move);
//         }

//         if (indexMove2 < allMoves.size()) {
//             move = allMoves[indexMove2];
//             moves.push_back(move);
//         }

            
//     }
    

    
    
    


    
//     return moves;
// }

std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    int x, y;
    x = knight[0] - 'a' + 1;
    y = knight[1] - '0';
    const int delta1[2] = {-1, 1};
    const int delta2[2] = {-2, 2};
    
    int new_x;
    int new_y;
    std::string new_loc = "  ";

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            new_x = x + delta1[i];
            new_y = y + delta2[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }

            new_x = x + delta2[i];
            new_y = y + delta1[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }
        }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}