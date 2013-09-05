class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        int sign = 1;
        int len = (int)strlen(str);
        // discard whitespace
        for (i = 0; i < len && str[i] == ' '; ++i);
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        else if (str[i] == '+') {
            ++i;
        }
        long long res = 0;
        for (; i < len; ++i) {
            if (str[i] < '0' || str[i] > '9')
                break;
            int num = str[i] - '0';
            res = res * 10 + num;
        }
        res = res * sign;
        if (res > INT_MAX)
            return INT_MAX;
        else if (res < INT_MIN)
            return INT_MIN;
        return res;
    }
};
