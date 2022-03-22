/**
 * Given an array of positive integers. For every index i, 
 * find the nearest element on left side of i which is
 * smaller than A[i]
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

std::vector<int> nearest_smallest_element(std::vector<int>& vec)
{
	std::vector<int> ans;
	std::stack<int> st;

	for (int x : vec)
	{
		while (!st.empty() && st.top() >= x)
		{
			st.pop();
		}

		if (st.empty())
		{
			ans.push_back(-1);
		}
		else if (st.top() < x)
		{
			ans.push_back(st.top());
		}
		st.push(x);
	}
	return ans; 
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {4, 5, 2, 10, 18, 2};
    std::vector<int> res = nearest_smallest_element(arr);

    for (int x : res)
    {
    	std::cout << x << " ";
    }

    return 0;
}
