class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0;
        int ans=0;

        for(int i:nums)
        {
            if(i==1)
            {
                sum++;
            }
            else
            {
                sum=0;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};