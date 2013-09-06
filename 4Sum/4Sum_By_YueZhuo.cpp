class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        ans.clear();

        for (int i = 0; i < (int)num.size() - 3; ++i) {
            if (i != 0 && num[i] == num[i - 1]) continue;

            for (int j = i + 1; j < (int)num.size() - 2; ++ j) {
                if (j != i + 1 && num[j] == num[j - 1]) continue;

                int sum = target - num[i] - num[j];
                int p = j + 1;
                int q = (int)num.size() - 1;

                while (p < q) {
                    if (p != j + 1 && num[p] == num[p - 1]) {
                        ++p;
                        continue;
                    }
                    if (num[p] + num[q] < sum)
                        ++p;
                    else if (num[p] + num[q] > sum)
                        --q;
                    else {
                        vector<int> quadruplet;
                        quadruplet.clear();
                        quadruplet.push_back(num[i]);
                        quadruplet.push_back(num[j]);
                        quadruplet.push_back(num[p]);
                        quadruplet.push_back(num[q]);
                        ans.push_back(quadruplet);
                        ++p;
                        --q;
                    }
                }
            }
        }

        return ans;
    }
};
