class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map <char,int> valid;
        int cursor = 0;
	    int ans = 0;
	    for(int i =0;i<s.size();++i){
		    if(valid.count(s[i])==0){
			    valid[s[i]] = i;
			}
		    else{
			    ans<i-cursor?ans = i-cursor:ans=ans;
                            cursor = cursor>valid[s[i]]?cursor:valid[s[i]]+1;
			    valid[s[i]] = i;
		    }
	    }
        return ans<s.size()-cursor?s.size()-cursor:ans;
    }
};
