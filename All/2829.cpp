class Solution {
public:
  int minimumSum(int n, int k) {    
    int sum = 0;
    unordered_set<int> s;
    for (int i = 1; s.size() != n; ++i) {
      if (s.count(k - i)) continue;
      sum += i;
      s.insert(i);
    }
    return sum;
  }
};