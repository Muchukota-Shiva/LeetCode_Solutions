class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int totalNumbers = nums.size(); 
    int maxSum = 0; 
    int currentSum = 0;

    for (int index = 0; index < k; ++index) {
        currentSum += nums[index];
    }
    maxSum = currentSum;
    for (int index = k; index < totalNumbers; ++index) {
        currentSum += nums[index] - nums[index - k];
        maxSum = std::max(maxSum, currentSum);
    }

    return static_cast<double>(maxSum) / k;
    }
};