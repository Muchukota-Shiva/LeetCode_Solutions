#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        for(int i=0; i<nums.size(); i++)
        {
            int cur=nums[i];
            int comp=target-cur;

            if(num_index.count(comp))
            {
                return {num_index[comp],i};
            }
            num_index[cur]=i;
        }

        return {};
    }
};