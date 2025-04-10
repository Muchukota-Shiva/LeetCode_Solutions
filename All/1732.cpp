class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt(n+1); alt[0]=0;
        int ans = 0;
        int cur = 0;

        for(auto i:gain)
        {
            cur = alt.back();
            cur += i;
            alt.push_back(cur);
            //cout << cur;
            if(cur>ans)
            {
                ans = cur;
            }
        }
        return ans;
    }
};