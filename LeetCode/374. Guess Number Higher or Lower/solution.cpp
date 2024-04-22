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
        long long l = 1,  r = n;
        while(l <= r)
        {
            long long m = (l+r)/2;
            int x = guess(m);

            if(x == -1)
            {
                r = m - 1;
            }
            else if (x == 1)
            {
                l = m+1;
            }
            else
            {
                return m;
            }
        }
            return -1;
    }

};