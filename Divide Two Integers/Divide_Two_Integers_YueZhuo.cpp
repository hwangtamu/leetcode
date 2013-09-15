class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 1;
        long long ldividend = dividend;
        if (ldividend < 0) ldividend = -ldividend;
        long long ldivisor = divisor;
        if (ldivisor < 0) ldivisor = -ldivisor;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            sign = -1;

        long long ans = 0;
        int shift = 0;

        while (ldividend > ldivisor) {
            ++shift;
            ldivisor <<= 1;
        }

        do {

            ans <<= 1;
            if (ldividend >= ldivisor) {
                ans |= 1;
                ldividend -= ldivisor;
            }
            ldivisor >>= 1;

        } while (shift--);

        return sign == -1 ? -ans : ans;
    }
};
