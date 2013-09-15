// TLE
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

        //
        // be careful about duplicates in the dictionary
        //
        vector<int> *match = new vector<int>[slen];
        for (int i = 0; i < slen; ++i)
            match[i].clear();
        bool *found = new bool[size];
        int wlen = (int)L[0].length();

        for (int i = 0; i < slen; ++i) {
            for (int j = 0; j < size; ++j) {
                if (S.substr(i, wlen) == L[j]) {
                    match[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < slen; ++i) {
            memset(found, false, sizeof(bool) * size);
            for (int j = 0; j < size && i + j * wlen < slen; ++j) {
                for (int k = 0; k < (int)match[i + j * wlen].size(); ++k) {
                    if (!found[match[i + j * wlen][k]]) {
                        found[match[i + j * wlen][k]] = true;
                        break;
                    }
                }
            }
            int k;
            for (k = 0; k < size; ++k) {
                if (!found[k])
                    break;
            }
            if (k == size)
                ans.push_back(i);
        }


        delete []found;
        delete []match;
        return ans;
    }
};
