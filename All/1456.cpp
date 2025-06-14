#include <unordered_set>
#include <string>

class Solution {
public:
    int maxVowels(string s, int k) {
    int total = s.size(); 
    int maxSum = 0; 
    int currentSum = 0;

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for(int i=0; i<k; i++)
    {
        if(vowels.count(s[i]))
        {
            currentSum++;
        }
    }
    maxSum = currentSum;

    for(int i=k; i<total; i++)
    {
        if(vowels.count(s[i]))
        {
            currentSum++;
        }
        if(vowels.count(s[i-k]))
        {
            currentSum--; // remove extra number if its out of the window
        }
        maxSum=max(maxSum,currentSum);
    }

    return maxSum;
    }
};