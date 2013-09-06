class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        ans.clear();

        if (num.size() == 0)
            return ans;

        int prei = num[0] - 1;

        for (int i = 0; i < (int)num.size() - 2; ++i) {

            if (num[i] == prei)
                continue;
            prei = num[i];

            int j = i + 1;
            int k = (int)num.size() - 1;
            int pre = num[j];
            int target = -num[i];

            while (j < k) {
                if (num[j] + num[k] < target) {
                    ++j;
                    while (j < k && num[j] == pre)
                        ++j;
                    if (j < k)
                        pre = num[j];
                }
                else if (num[j] + num[k] > target)
                    --k;
                else {
                    vector<int> triplet;
                    triplet.clear();
                    triplet.push_back(num[i]);
                    triplet.push_back(num[j]);
                    triplet.push_back(num[k]);
                    ans.push_back(triplet);
                    ++j;
                    --k;
                    while (j < k && num[j] == pre)
                        ++j;
                    if (j < k)
                        pre = num[j];
                }
            }
        }
        return ans;
    }
};
