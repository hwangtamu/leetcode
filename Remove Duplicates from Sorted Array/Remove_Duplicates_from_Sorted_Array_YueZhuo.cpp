class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return n;
        int len = 1;
        int prev = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] != prev) {
                prev = A[i];
                if (i != len)
                    A[len] = A[i];
                ++len;
            }
        }
        return len;
    }
};
