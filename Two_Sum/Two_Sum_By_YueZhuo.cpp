class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        map<int, int> numSet;
        numSet.clear();
        vector<int> ans;
        ans.clear();

        for (int i = 0; i < (int)numbers.size(); ++i) {
            if (numSet.count(target - numbers[i])) {
                ans.push_back(numSet[target - numbers[i]] + 1);
                ans.push_back(i + 1);
            }

            numSet[numbers[i]] = i;
        }
        return ans;
    }
};
