class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = (int)height.size() - 1;
        int ans = 0;
        
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
                ++l;
            else 
                --r;
        }
        return ans;
    }
};