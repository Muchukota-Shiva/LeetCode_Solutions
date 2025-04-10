class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
           int siz = nums.size();
    
           sort(nums.begin(), nums.end());
    
           int st=0; int ls=siz-1; int ans=0;
    
            while(st<ls)
            {
                int sum=nums[st]+nums[ls];
                if(sum==k)
                {
                    ans++;
                    st++;
                    ls--;
                    // basically remove these elements, its sorted so wont miss stuff
                }
                else if(sum<k)
                {
                    st++;
                    // increase number to reach the sum
                }
                else
                {
                    ls--;
                    // reduce number we crossed sum
                }
            }
    
            return ans;
        }
    };