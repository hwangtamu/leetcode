#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char s, char p)
    {
        if (s == '.' || p == '.' || s == p)
            return true;
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = strlen(s) + 1;
        int plen = strlen(p) + 1;

        char *ts = new char[slen + 1];
        char *tp = new char[plen + 1];
        strcpy(ts + 1, s);
        strcpy(tp + 1, p);
        ts[0] = tp[0] = 'a';

        bool **f = new bool *[slen + 1];
        for (int i = 0; i <= slen; ++i) {
            f[i] = new bool[plen + 1];
            memset(f[i], false, sizeof(bool) * (plen + 1));
        }

        f[0][0] = true;

        for (int i = 1; i <= slen; ++i) {
            for (int j = 1; j <= plen; ++j) {

                if (ts[i - 1] == '.') {
                    if (tp[j - 1] == '.')
                        f[i][j] = f[i - 1][j - 1];
                    else if (tp[j - 1] == '*')
                        f[i][j] = f[i - 1][j - 1] | f[i][j - 1] | f[i][j - 2];
                    else
                        f[i][j] = f[i - 1][j - 1];
                }
                else if (ts[i - 1] == '*') {
                    if (tp[j - 1] == '.')
                        f[i][j] = f[i - 1][j - 1] | f[i - 1][j] | f[i - 2][j];
                    else if (tp[j - 1] == '*') {
                        f[i][j] = f[i - 1][j - 1] & match(ts[i - 2], tp[j - 2]);
                        for (int m = i - 2; m <= i; ++i) {
                            for (int n = j - 2; n <= j; ++j) {
                                if (m == i && n == j) continue;
                                f[i][j] |= f[m][n];
                            }
                        }
                    }
                    else
                        //f[i][j] = f[i - 2][j] | f[i - 1][j] | (f[i - 1][j - 1] & match(ts[i - 2], tp[j - 1]));
                        f[i][j] = f[i - 2][j] | f[i - 1][j] | (f[i][j - 1] & match(ts[i - 2], tp[j - 1]));
                }
                else {
                    if (tp[j - 1] == '.')
                        f[i][j] = f[i - 1][j - 1];
                    else if (tp[j - 1] == '*')
                        //f[i][j] = (f[i - 1][j - 1] & match(ts[i - 1], tp[j - 2])) | f[i][j - 1] | f[i][j - 2]
                        //            | (f[i - 1][j] & match(ts[i - 1], tp[j - 2]));
                        f[i][j] = (f[i - 1][j] & match(ts[i - 1], tp[j - 2])) | f[i][j - 1] | f[i][j - 2];
                    else
                        f[i][j] = f[i - 1][j - 1] & match(ts[i - 1], tp[j - 1]);
                }

                //printf("%d, %d: %d\n", i, j, f[i][j]);
            }
        }

        bool res = f[slen][plen];

        for (int i = 0; i <= slen; ++i)
            delete []f[i];
        delete []f;
        delete []ts;
        delete []tp;

        //printf("%d\n", res);
        return res;
    }
};

int main()
{
    Solution s;
    s.isMatch("aaa", "a*");
    return 0;
}
