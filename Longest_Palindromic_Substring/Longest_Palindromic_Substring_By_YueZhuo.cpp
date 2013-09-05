class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int pos;
        for (int i = 0; i < (int)s.length(); ++i) {

            // for even length
            int p = i, q = i + 1;
            int len = 0;
            while (p >= 0 && q < (int)s.length()) {
                if (s[p] != s[q])
                    break;
                --p;
                ++q;
                len += 2;
            }
            if (len > ans) {
                ans = len;
                pos = p + 1;
            }
            // for odd length
            p = i - 1;
            q = i + 1;
            len = 1;
            while (p >= 0 && q < (int)s.length()) {
                if (s[p] != s[q])
                    break;
                --p;
                ++q;
                len += 2;
            }
            if (len > ans) {
                ans = len;
                pos = p + 1;
            }
        }

        return s.substr(pos, ans);
    }
};
