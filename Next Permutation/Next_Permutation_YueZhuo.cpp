class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = (int)num.size();
        if (len == 0)
            return;
        bool flag = false;
        for (int i = len - 2; i >= 0; --i) {
            if (num[i] >= num[i + 1]) continue;

            int j;
            for (j = i + 1; j < len && num[j] > num[i]; ++j);

            swap(num[j - 1], num[i]);
            sort(num.begin() + i + 1, num.end());
            flag = true;
            break;
        }

        if (!flag) {
            for (int i = 0; i < len / 2; ++i)
                swap(num[i], num[len - 1- i]);
        }

    }
};
