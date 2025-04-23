class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int count = 0;
            int siz = flowerbed.size();
            int i =0;
    
            while(i<siz)
            {
                if(flowerbed[i]==0)
                {
                    if(i==siz-1 || flowerbed[i+1]==0)
                    {
                        count++;
                    }
                    else
                    {
                        i++; // next plot has been plotted so cant check next even will try next odd
                    }
                }
                i+=2;
            }
    
            if(count>=n)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };