/** 
 * Given an array. Return an array containg the max value of 
 * every windows of size k 
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

std::vector<int> max_val_window(std::vector<int>& arr, int k)
{
	std::deque<int> dq;
	std::vector<int> res;
	int n = arr.size();

	for (int i = 0; i < k; ++i)
	{
		if (dq.empty() || dq.back() >= arr[i])
		{
			dq.push_back(arr[i]);
		}
		else if (dq.back() < arr[i])
		{
			while (!dq.empty() && dq.back() < arr[i])
			{
				dq.pop_back();
			}
			dq.push_back(arr[i]);
		}
	}
	
	res.push_back(dq.front());

	for (int i = 1; i <= n-k; ++i)
	{
		if (arr[i-1] == dq.front())
		{
			dq.pop_front();
		}

		if (dq.empty() || dq.back() >= arr[i+k-1])
		{
			dq.push_back(arr[i+k-1]);
		}
		else if (dq.back() < arr[i+k-1])
		{
			while (!dq.empty() && dq.back() < arr[i+k-1])
			{
				dq.pop_back();
			}
			dq.push_back(arr[i+k-1]);
		}
		res.push_back(dq.front());
	}
	return res;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    auto res = max_val_window(arr, 3);

    for (int x : res)
    {
    	std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
