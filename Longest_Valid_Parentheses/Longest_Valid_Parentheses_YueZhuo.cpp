class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> num;
        stack<char> stk;
        while (!num.empty()) num.pop();
        while (!stk.empty()) stk.pop();
        int ans = 0;

        for (int i = 0; i < (int)s.length(); ++i) {
            if (stk.size() == 0 || s[i] == '(')
                stk.push(s[i]);
            else {
                char top = stk.top();
                if (top == 'Z') {
                    stk.pop();
                    if (stk.size() && stk.top() == '(') {
                        stk.pop();
                        int val = num.top() + 1;
                        num.pop();
                        if (stk.size() && stk.top() == 'Z') {
                            val += num.top();
                            num.pop();
                            stk.pop();
                        }
                        stk.push('Z');
                        num.push(val);
                        ans = max(ans, val);
                    }
                    else {
                        stk.push(top); // push back 'Z'
                        stk.push(s[i]);
                    }
                }
                else if (top == '(') {
                    int val = 1;
                    stk.pop();
                    if (stk.size() && stk.top() == 'Z') {
                        val += num.top();
                        num.pop();
                        stk.pop();
                    }
                    stk.push('Z');
                    num.push(val);
                    ans = max(ans, val);
                }
                else
                    stk.push(s[i]);
            }
        }
        return ans * 2;
    }
};
