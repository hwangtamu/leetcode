#include <vector>
#include <string>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        ans.clear();
        if (L.size() == 0)
            return ans;

        int slen = (int)S.length();
        int size = (int)L.size();
        int wlen = (int)L[0].length();

        //
        // be careful about duplicates in the dictionary
        //
        int *found = new int[size];
        int *match = new int[slen];

        map<string, pair<int, int> > mp;
        mp.clear();
        for (int i = 0; i < size; ++i) {
            if (!mp.count(L[i]))
                mp[L[i]] = make_pair(i, 1);
            else
                ++mp[L[i]].second;
        }

        for (int i = 0; i < wlen; ++i) {

            memset(found, 0, sizeof(int) * size);

            int j, left;
            int cnt = 0;

            for (j = i, left = i; j + wlen <= slen; j += wlen) {
                string str = S.substr(j, wlen);

                if (mp.count(str)) {
                    left = j + wlen;
                    cnt = 0;
                    memset(found, 0, sizeof(int) * size);
                    continue;
                }

                int index = mp[str].first;
                int sum = mp[str].second;
                if (found[index] < sum) {
                    ++found[index];
                    ++cnt;
                }
                else {
                    while (match[left] != index) {
                        --cnt;
                        --found[match[left]];
                        left += wlen;
                    }
                }
                match[j] = index;

                if (cnt == size) {
                    ans.push_back(left);
                    --found[match[left]];
                    left += wlen;
                    --cnt;
                }
            }
        }

        delete []found;
        delete []match;
        return ans;
    }
};

int main()
{
    Solution s;
    string S("abaaabbb");
    vector<string> L;
    L.clear();
    L.push_back("ab");
    L.push_back("bb");
    s.findSubstring(S, L);
    return 0;
}
