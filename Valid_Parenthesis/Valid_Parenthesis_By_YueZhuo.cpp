class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stk;
        while (!stk.empty()) stk.pop();
        map<char, char>mp;
        mp.clear();
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';

        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stk.empty() || stk.top() != mp[s[i]])
                    return false;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.empty();
    }
};
