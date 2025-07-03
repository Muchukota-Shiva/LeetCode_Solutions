class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }

        vector<int> counts(26,0);

        for(int i=0; i<s.size(); i++)
        {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }

        for(auto& a:counts)
        {
            if(a!=0)
            {
                return false;
            }
        }
        return true;
    }
};