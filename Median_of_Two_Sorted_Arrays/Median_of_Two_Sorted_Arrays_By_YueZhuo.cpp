class Solution {
public:

    int median(int A[], int m, int B[], int n, int med)
    {
        int l = 0, r = m;
        int mid, pos;

        while (l + 1 < r) {
            mid = (l + r) >> 1;
            pos = med - mid - 2;

            if (pos >= n || (pos >= 0 && A[mid] < B[pos]))
                l = mid;
            else if (pos + 1 < 0 || (pos + 1 < n && A[mid] > B[pos + 1]))
                r = mid;
            else
                return mid;
        }
        pos = med - l - 2;
        if (l >= m || pos >= n || (pos >= 0 && A[l] < B[pos]))
            return -1;
        else if (pos + 1 < 0 || (pos + 1 < n && A[l] > B[pos + 1]))
            return -1;
        else
            return l;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = m + n;
        double ans;
        int ret;

        if (len & 1) {
            int med = (len + 1) / 2;
            if ((ret = median(A, m, B, n, med)) != -1)
                 ans = A[ret];
            else {
                ret = median(B, n, A, m, med);
                ans = B[ret];
            }
        }
        else {
            int med = (len + 1) / 2;
            if ((ret = median(A, m, B, n, med)) != -1)
                 ans = A[ret];
            else {
                ret = median(B, n, A, m, med);
                ans = B[ret];
            }

            med += 1;
            if ((ret = median(A, m, B, n, med)) != -1)
                 ans += A[ret];
            else {
                ret = median(B, n, A, m, med);
                ans += B[ret];
            }
            ans /= 2;
        }
        return ans;
    }
};
