class Solution {
public:
    void generator (vector<string> &ans, string str, int len, int cur, int left, int right)
    {
        if (cur == len) {
            ans.push_back(str);
            return;
        }
        if (left == right) {
            generator(ans, str + '(', len, cur + 1, left + 1, right);
        }
        else {
            if (left < len / 2)
                generator(ans, str + '(', len, cur + 1, left + 1, right);
            generator(ans, str + ')', len, cur + 1, left, right + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        ans.clear();
        generator(ans, "", n * 2, 0, 0, 0);
        return ans;
    }
};
