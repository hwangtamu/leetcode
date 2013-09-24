class Solution {
public:

    void find_path(int cur, int last, vector<int> &num, vector<int> &path, vector<vector<int> > &ans, int target)
    {
        if (cur == target) {
            ans.push_back(path);
            return;
        }

        for (int i = last + 1; i < (int)num.size() && cur + num[i] <= target; ++i) {
            if (i && num[i] == num[i - 1] && i - 1 != last) continue;
            int val = num[i];
            path.push_back(val);
            find_path(cur + val, i, num, path, ans, target);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > ans;
        vector<int> path;
        ans.clear();
        path.clear();

        sort(num.begin(), num.end());

        find_path(0, -1, num, path, ans, target);

        return ans;
    }
};
