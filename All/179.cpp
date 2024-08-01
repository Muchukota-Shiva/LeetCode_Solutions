using namespace std;
class Solution {
public:
    static bool compare(const string& X, const string& Y)
    {
        return (X+Y)>(Y+X);
    }
    string largestNumber(vector<int>& nums) {
        //vector<string> sortedArr = nums;
        vector<string> stringNums;
        for(int num:nums)
        {
            stringNums.push_back(to_string(num));
        }
        sort(stringNums.begin(), stringNums.end(), compare);
        if(stringNums[0]=="0")
        {
            return "0";
        }

        string result;
        for(const string& num : stringNums)
        {
            result+=num;
        }
        return result;
    }
};