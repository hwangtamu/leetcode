class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dir = 0;
        int downStep = (nRows - 1) * 2;
        int upStep = 0;
        string ans;

        if (nRows == 1)
            return s;

        for (int i = 0; i < nRows && i < (int)s.length(); ++i) {
            int cur = i;
            int next;
            ans += s[cur];
            while(1) {
                if (dir == 0) {  // going down
                    if (downStep == 0) {
                        dir = 1;
                        continue;
                    }
                    next = cur + downStep;
                }
                else { // going up
                    if (upStep == 0) {
                        dir = 0;
                        continue;
                    }
                    next = cur + upStep;
                }
                if (next >= (int)s.length()) {
                   dir = 0;
                   downStep -= 2;
                   upStep += 2;
                   break;
                }
                else {
                    ans += s[next];
                    cur = next;
                    dir ^= 1;
                }
            };
        }

        return ans;
    }
};
