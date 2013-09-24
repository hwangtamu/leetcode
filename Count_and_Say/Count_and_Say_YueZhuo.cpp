class Solution {
public:
    string num_to_string(int cnt)
    {
        string ans = "";
        while (cnt) {
            ans += '0' + cnt % 10;
            cnt /= 10;
        }
        int len =(int)ans.length();
        for (int i = 0; i < len / 2; ++i)
            swap(ans[i], ans[len - 1 - i]);
        return ans;
    }

    string countAndSay(int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans = "";
        if (n == 0)
            return ans;
        ans += '1';
        for (int i = 1; i < n; ++i) {
            string tmp = "";
            int cnt = 1;
            char cur = ans[0];
            for (int j = 1; j < (int)ans.length(); ++j) {
                if (ans[j] == ans[j - 1])
                    ++cnt;
                else {
                    tmp += num_to_string(cnt);
                    tmp += cur;
                    cnt = 1;
                    cur = ans[j];
                }
            }
            tmp += num_to_string(cnt);
            ans = tmp;
        }
        return ans;
    }
};
