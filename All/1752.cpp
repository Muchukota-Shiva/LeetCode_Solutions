class Solution {
public:
    bool check(vector<int>& nums) {
        int rotates = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>nums[(i+1)%nums.size()])
                rotates++;
        }

        if(rotates>1) return false;
        return true;
    }
};