// twosum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> ans(2,0);
		for(int i=0;i<numbers.size();++i)
		{
			ans[0] = i+1;
			ans[1] = ans[0]+1;
			while(ans[1]<=numbers.size())
			{
				if(numbers[ans[0]-1]+numbers[ans[1]-1]==target)
					return ans;
				++ans[1];
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

