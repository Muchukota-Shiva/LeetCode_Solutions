#include <vector>
#include <climits> // Include for INT_MAX

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int firstMin = INT_MAX; 
        int secondMin = INT_MAX; 

        for (int num : nums) {
            if (num > secondMin) {
                return true; 
            }
            if (num <= firstMin) {
                firstMin = num; 
            } else {
                secondMin = num; 
            }
        }
        return false;
    }
};
