class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        if (strs.size() == 0)
            return ans;

        ans = strs[0];

        for (int i = 1; i < (int)strs.size(); ++i) {
            int p, q;
            for (p = 0, q = 0; p < (int)ans.length() &&
                q < (int)strs[i].length() && ans[p] == strs[i][q]; ++p, ++q);
            ans = ans.substr(0, p);
        }

        return ans;
    }
};
