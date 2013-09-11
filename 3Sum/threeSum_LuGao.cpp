class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> triple(3);
        set<vector<int>> triples;
        vector<vector<int>> empty;
        if(num.size() < 3)
            return empty;
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(num[i] + num[j] + num[k] < 0)
                    j++;
                else if(num[i] + num[j] + num[k] > 0)
                    k--;
                else{
                    triple[0] = num[i];
                    triple[1] = num[j];
                    triple[2] = num[k];
                    triples.insert(triple);
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> triplets (triples.begin(), triples.end());
        return triplets;
    }
};