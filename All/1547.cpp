#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(int totalLength, vector<int>& cuts) {
        // Include the edges as cuts (start and end of the rod)
        cuts.push_back(0);
        cuts.push_back(totalLength);
        // Sort the cuts for dynamic programming approach
        sort(cuts.begin(), cuts.end());

        int numOfCuts = cuts.size();
        int costMatrix[110][110] = {0}; // Assuming we will not have more than 100 cuts

        // Filling cost matrix diagonally, starting from the smallest subproblems
        for (int len = 2; len < numOfCuts; ++len) {
            for (int i = 0; i + len < numOfCuts; ++i) {
                int j = i + len;
                costMatrix[i][j] = 1 << 30; // Initialize with a large number (infinity)
              
                // Find the minimum cost to cut this piece further
                for (int k = i + 1; k < j; ++k) {
                    int cost = costMatrix[i][k] + costMatrix[k][j] + cuts[j] - cuts[i];
                    costMatrix[i][j] = min(costMatrix[i][j], cost);
                }
            }
        }

        // Return the minimum cost to cut the whole rod
        return costMatrix[0][numOfCuts - 1];
    }
};