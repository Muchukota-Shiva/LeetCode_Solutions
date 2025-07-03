/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lower=1;
        int higher=n;

        while(lower<higher)
        {
            int mid = lower + ((higher - lower) >> 1);

            if (guess(mid)<=0)
            {
                higher = mid;
            }
            else
            {
                lower = mid+1;
            }
        }

        return lower;
    }
};