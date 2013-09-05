class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        int tmp = x;
        if (x < 0)
            return false;
        long long mod[] = {1, 10};
        while (tmp) {
            ++len;
            tmp /= 10;
            mod[0] *= 10;
        }
        long long div[] = {mod[0] / 10, 1};
        int i;
        for (i = 0; i < len / 2; ++i) {
            int high = (x % mod[0]) / div[0];
            int low = (x % mod[1]) / div[1];
            if (low != high) break;
            mod[0] /= 10;
            div[0] /= 10;
            mod[1] *= 10;
            div[1] *= 10;
        }
        return i == len / 2;
    }
};
