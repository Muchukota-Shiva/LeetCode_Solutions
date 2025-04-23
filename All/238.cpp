class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(); 
        vector<int> output(size); 
        int leftProduct = 1;

        for (int index = 0; index < size; ++index) {
            output[index] = leftProduct;
            leftProduct *= nums[index];   
        }

        int rightProduct = 1;

        for (int index = size - 1; index >= 0; --index) {
            output[index] *= rightProduct;
            rightProduct *= nums[index];
        }
      
        return output;
    }
};