class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (int x : nums) {
            if (cnt == 0 || x != nums[cnt - 1]) // skip first element no need
            {
                nums[cnt++] = x;
            }
        }
        for (auto i : nums)
            cout << i << " ";
        return cnt;
    }
};