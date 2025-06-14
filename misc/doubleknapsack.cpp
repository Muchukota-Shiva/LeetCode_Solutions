// C++ program to find the largest subset of
// the array that can fit into two knapsack
// using memoization

#include <iostream>
#include <vector>
using namespace std;
int findMaxWeight(int curr, int n, vector<int> &arr, int capacity1, 
                  int capacity2, vector<vector<vector<int>>> &memo) {

    // Base case: If all items have been considered,
    // return 0 as no more items can be added
    if (curr >= n)
        return 0;

    // If the result for this subproblem is already
    // computed, return the memoized value
    if (memo[curr][capacity1][capacity2] != -1)
        return memo[curr][capacity1][capacity2];

    // Option 1: Don't take the current item, and
    // proceed to the next item
    int res = findMaxWeight(curr + 1, n, arr, 
                            capacity1, capacity2, memo);

    // Option 2: If the current item can be added
    // to the first knapsack, include it
    if (capacity1 >= arr[curr]) {
        int takeInFirst = arr[curr] + 
       findMaxWeight(curr + 1, n, arr, capacity1 - arr[curr], 
                     capacity2, memo);
        res = max(res, takeInFirst);
    }

    // Option 3: If the current item can be added
    // to the second knapsack, include it
    if (capacity2 >= arr[curr]) {
        int takeInSecond = arr[curr] + 
        findMaxWeight(curr + 1, n, arr, capacity1, 
                      capacity2 - arr[curr], memo);
        res = max(res, takeInSecond);
    }
    return memo[curr][capacity1][capacity2] = res;
}
int maxWeight(vector<int> &arr, int capacity1, int capacity2) {
    int n = arr.size();
    vector<vector<vector<int>>> memo =
        vector<vector<vector<int>>>(n, vector<vector<int>>
		(capacity1 + 1, vector<int>(capacity2 + 1, -1)));
    int res = findMaxWeight(0, n, arr, capacity1, capacity2, memo);
    return res;
}

int main() {
    vector<int> arr = {8, 2, 3};
    int capacity1 = 10, capacity2 = 3;
     int res=maxWeight(arr, capacity1, capacity2);
    cout << res;
    return 0;
}