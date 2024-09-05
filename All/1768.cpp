class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.size(); 
        int length2 = word2.size(); 
        string result;
        for (int i = 0; i < max(length1, length2); ++i) {
            if (i < length1) result += word1[i];
            if (i < length2) result += word2[i];
        }

        return result; // Return the merged string
    }
};