class Solution {
public:
    vector<vector<int>> ans;

    void help(int i, vector<int>& C, int t, vector<int>& sol) {
        // If target is met, store the valid combination
        if (t == 0) {
            ans.push_back(sol);
            return;
        }
        
        // If target goes negative, stop further recursion
        if (t < 0 || i == C.size()) { 
            return;
        }
        
        // Skip ith element
        help(i + 1, C, t, sol);

        // Pick the ith element (we can reuse the same element)
        sol.push_back(C[i]);
        help(i, C, t - C[i], sol);
        sol.pop_back();  // Backtrack
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        help(0, candidates, target, sol);
        return ans;
    }
};
