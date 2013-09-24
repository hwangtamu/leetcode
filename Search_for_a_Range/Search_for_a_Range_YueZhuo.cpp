class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(2, -1);

        if (n == 0)
            return ans;

        int l, r, mid;
        l = 0, r = n;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (A[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (A[l] != target)
            return ans;
        ans[1] = l;

        l = -1, r = n - 1;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (A[mid] < target)
                l = mid;
            else
                r = mid;
        }
        ans[0] = r;

        return ans;
    }
};
