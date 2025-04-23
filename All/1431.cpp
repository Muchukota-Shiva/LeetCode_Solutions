class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int siz = candies.size();
        vector<bool> ans(siz);

        int highest = *max_element(candies.begin(), candies.end());

        for(int i=0; i<siz; i++)
        {
            int cur = candies[i];

            if(cur+extraCandies >= highest)
            {
                ans[i]=true;
            }
            else
            {
                ans[i]=false;
            }
        }

        return ans;
    }
};