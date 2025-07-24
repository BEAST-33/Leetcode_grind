#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/**
 * @brief Determines the indices of ants remaining on a 1D rod after collisions.
 * * @param strength A vector of integers representing the strength of each ant.
 * @param directions A vector of integers (+1 for right, -1 for left) for each ant's direction.
 * @return A vector of indices of the surviving ants, sorted in increasing order.
 */
std::vector<int> getRemainingAnts(const std::vector<int>& strength, const std::vector<int>& directions) {
    int n = strength.size();
    // We use a vector as a stack to store the indices of ants that are potential survivors.
    std::vector<int> survivors; 

    for (int i = 0; i < n; ++i) {
        if (directions[i] == 1) {
            // An ant moving right is pushed onto the stack.
            survivors.push_back(i);
        } else { // An ant is moving left (direction == -1).
            bool currentAntEliminated = false;
            // This left-moving ant will collide with any right-moving ants on the stack.
            while (!survivors.empty() && directions[survivors.back()] == 1) {
                int rightAntIndex = survivors.back();

                if (strength[rightAntIndex] < strength[i]) {
                    // The right-moving ant is weaker and gets eliminated.
                    survivors.pop_back(); 
                } else if (strength[rightAntIndex] > strength[i]) {
                    // The current left-moving ant is weaker and gets eliminated.
                    currentAntEliminated = true;
                    break;
                } else { // Strengths are equal.
                    // Both ants get eliminated.
                    survivors.pop_back();
                    currentAntEliminated = true;
                    break;
                }
            }
            
            // If the left-moving ant was not eliminated, it's a survivor.
            if (!currentAntEliminated) {
                survivors.push_back(i);
            }
        }
    }

    return survivors;
}

// Example Usage
int main() {
    std::vector<int> strength = {6, 1, 4, 8, 3};
    std::vector<int> directions = {1, 1, -1, 1, -1};

    std::vector<int> result = getRemainingAnts(strength, directions);

    std::cout << "Indices of surviving ants: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Expected output: 0 3

    return 0;
}