class Solution {
public:
    int* convert(string a){
        int* arr = new int[a.size()];
	    for(int i = 0;i < a.size(); i++){
		    arr[i] = (int)(a[a.size()-i-1]-'0');
	    }
	    return arr;
    }

    int* product(int* a1,int* a2, int m,int n){
	    int* ans = new int[m+n];
	    for(int i = 0;i < m+n; i++)
		    ans[i] = 0;
	    for(int j = 0;j < m; j++){
		    for(int k = 0;k < n; k++)
			    ans[j+k] += a1[j]*a2[k];
	    }
	    for(int i = 0;i < m+n-1;i++){
		    ans[i+1] += ans[i]/10;
		    ans[i] = ans[i]%10;
	    }
	    return ans;
    }
    string multiply(string num1, string num2){
        if(num1=="0"||num2=="0")
    	    return "0";
	    int* val1 = convert(num1);
	    int* val2 = convert(num2);
	    int* arr = product(val1,val2,num1.size(),num2.size());
	    string ans;
	    for(int i = num1.size()+num2.size();i>0;i--)
		    ans.push_back((char)(arr[i-1]+'0'));
	    if(ans == "0")
		    return ans;
	    while(ans.front() == '0')
		    ans.erase(ans.begin());
	    return ans;
    }
};
