class Solution {
public:

    int find_partition(int A[], int l, int r)
    {
        if (l == r)
            return -1;
        if (l + 1 == r) {
            if (A[l] > A[r])
                return r;
            return -1;
        }
        int p1 = (2 * l + r) / 3;
        int p2 = (l + 2 * r) / 3;

        if (A[p1] > A[p2])
            return find_partition(A, p1, p2);
        int res = find_partition(A, l, p1);
        if (res != -1)
            return res;
        return find_partition(A, p2, r);
    }

    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return -1;
        int res = find_partition(A, 0, n - 1);
        int l, r, mid;
        if (res == -1) {
            l = 0;
            r = n;
        }
        else {
            if (A[0] <= target) {
                l = 0;
                r = res;
            }
            else {
                l = res;
                r = n;
            }
        }

        while (l + 1 < r) {
            mid  = (l + r) >> 1;
            if (A[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (A[l] == target)
            return l;
        return -1;
    }
};
