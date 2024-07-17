#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize pointers:
        // 'left' is the position where the next 0 should go,
        // 'right' is the position one more than where the next 2 should go,
        // 'current' is the current index being considered.
        int left = -1, right = nums.size(), current = 0;
      
        while (current < right) { // go till end
            if (nums[current] == 0) {
                swap(nums[++left], nums[current++]); // swap left+1 and current, then increment current
            } else if (nums[current] == 2) {

                swap(nums[--right], nums[current]);
            } else {
                ++current;
            }
        }
    }
};