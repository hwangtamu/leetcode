class Solution {
public:
    vector<string> ans;

    void dfs(string digits, int index, string &str, int len, string mp[])
    {
        if (index == (int)digits.length()) {
            str[len] = 0;
            ans.push_back(str);
            return;
        }
        if (digits[index] <= '1')
            dfs(digits, index + 1, str, len, mp);
        else {
            int j = digits[index] - '0';
            for (int i = 0; i < (int)mp[j].length(); ++i) {
                str[len] = mp[j][i];
                dfs(digits, index + 1, str, len + 1, mp);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string mp[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.clear();
        string str(digits);

        dfs(digits, 0, str, 0, mp);
        return ans;
    }
};
