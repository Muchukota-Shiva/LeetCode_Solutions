class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // initialize array and get dimensions mXn
        int m=grid.size();
        int n=grid[0].size();
        const int mn=m*n;
        int remainder = grid[0][0]%x; // from hint 1
        vector<int> num(mn); // utility

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]%x!=remainder)
                {
                    return -1; // not possilbe remove
                }
                 num[i*n+j]=grid[i][j]; // i*n+j is to find exact element in row
            }
           
        }
        sort(num.begin(), num.end());
        int n2= num.size();
        int median = n2/2;

        int ans=0;
        for(int i=0; i<n2; ++i)
        {
            ans+=abs(num[i]-num[median])/x; // gap divided by integer x
        }
        return ans;
    }
};