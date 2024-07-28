class Solution {
public:
    int countGoodSubstrings(const std::string& s) {
    int length = s.length();
    int goodSubstringCount = 0;
    for (int i = 0; i < length - 2; ++i) {
        char char1 = s[i],
             char2 = s[i + 1],
             char3 = s[i + 2];
        if (char1 != char2 && char1 != char3 && char2 != char3) {
            ++goodSubstringCount;
        }
    }
    return goodSubstringCount;
}
};