class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        sort(num.begin(), num.end());
        int mindif = INT_MAX;
        int ans;

        for (int i = 0; i < (int)num.size() - 2; ++i) {

            int j = i + 1;
            int k = (int)num.size() - 1;
            int sum = target - num[i];

            while (j < k) {
                int dif = abs(num[j] + num[k] - sum);
                if (dif < mindif) {
                    mindif = dif;
                    ans = num[i] + num[j] + num[k];
                }
                if (num[j] + num[k] < sum)
                    ++j;
                else
                    --k;
            }
        }
        return ans;
    }
};
