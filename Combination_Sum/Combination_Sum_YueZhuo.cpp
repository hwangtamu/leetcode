class Solution {
public:

    void find_path(int cur, int last, vector<int> &candidates, vector<int> &path, vector<vector<int> > &ans, int target)
    {
        if (cur == target) {
            ans.push_back(path);
            return;
        }

        for (int i = last; i < (int)candidates.size() && cur + candidates[i] <= target; ++i) {
            int val = candidates[i];
            path.push_back(val);
            find_path(cur + val, i, candidates, path, ans, target);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        vector<vector<int> > ans;
        ans.clear();

        if (candidates.size() == 0)
            return ans;

        // remove duplicates
        sort(candidates.begin(), candidates.end());
        int cnt = 1;
        for (int i = 1; i < (int)candidates.size(); ++i) {
            if (candidates[i] != candidates[i - 1])
                candidates[cnt++] = candidates[i];
        }
        candidates.erase(candidates.begin() + cnt, candidates.end());

        vector<int> path;
        path.clear();

        find_path(0, 0, candidates, path, ans, target);

        return ans;
    }
};
