class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> mp;
        mp.clear();
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (i + 1 < (int)s.length() && mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }

        return ans;
    }
};
