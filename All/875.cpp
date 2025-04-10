class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) { // seems like a binary search thingy
            int x=1; 
            int r=*max_element(piles.begin(), piles.end());
    
            while(x<r)
            {
                int mid = (x+r)/2;
                int cur = 0;
                for(int i : piles)
                {
                    cur += (i+mid-1)/mid; // time taken to eat a pile
                }
                if(cur<=h) // time taken to eat is less than total time
                {
                    r=mid; // reduce upper limit we are getting closer, try smaller mid
                }
                else
                {
                    x = mid +1; // increase lower limit, eating too slow
                }
            }
            return x;
        }
    };