// twoSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector <int> twoSum(vector <int> &numbers, int target){
		vector <int> ans (2, 0);
		for (int i = 0; i < numbers.size(); ++i)
		{
			ans[0] = i + 1;
			ans[1] = i + 2;
			while (ans[1]<numbers.size())
			{
				if (numbers[ans[0] - 1] + numbers[ans[1] - 1] == target)
					return ans;
				++ans[1];
			}
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv [])
{
	int a[] = {2, 7, 11, 5};
	vector <int> b(a, a + sizeof(a) / sizeof(int) );
	Solution s;
	cout << s.twoSum(b, 9)[0] << "," << s.twoSum(b, 9)[1] << '\n';
	return 0;
}

