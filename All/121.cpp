class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_ = 0;
        int min_ = prices[0];

        for(int price : prices)
        {
            max_ = max(max_, price - min_);

            min_ = min(min_, price);
        }
        return max_;
    }
};