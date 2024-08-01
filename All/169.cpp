#include <unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
	unordered_map<int, int> count;
	int n = ceil(nums.size() / 2.0);

	for(int i = 0; i < nums.size(); ++i) {
		++count[nums[i]];
		if(count[nums[i]] >= n) return nums[i];
	}

	return -1;
}
};