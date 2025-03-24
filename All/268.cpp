class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tot = nums.size();
        int sum = (tot*(tot+1))/2; // n*(n+1)/2

        for(int i:nums)
        {
            sum-=i;
        }
        return sum;
    }
};