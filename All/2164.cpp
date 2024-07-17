class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // work for even indices
        for (int i = 0; i < nums.size(); i += 2){
            for (int j = i + 2; j < nums.size(); j += 2){
                // sort in non-decreasing order
                if (nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        // work for odd indicies
        for (int i = 1; i < nums.size(); i += 2){
           for (int j = i + 2; j < nums.size(); j += 2){
               // sort in non-increasing order
                if (nums[i] < nums[j]){
                    swap(nums[i], nums[j]);
                }
           }
        }
        return nums;
    }
};