class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.empty())
      return true; // edge case

    int i = 0; // ulta approach to what I did initially
    for (const char c : t)
      if (s[i] == c && ++i == s.length())
        return true;

    return false;
  }
};