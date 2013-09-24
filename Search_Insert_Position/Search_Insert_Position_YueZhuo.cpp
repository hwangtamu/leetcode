class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return 0;
        int l, r, mid;
        l = 0, r = n;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (A[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (A[l] >= target)
            return l;
        return l + 1;
    }
};
