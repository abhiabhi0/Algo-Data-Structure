/**
 * Given an unsorted array. Find kth position element if it was 
 * sorted. 
 * No modification of array and no extra space.
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int count_smaller(std::vector<int>&vec, int n, int mid)
{
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (vec[i] < mid)
		{
			count++;
		}
	}
	return count;
}

int k_pos_element(std::vector<int>&vec, int n, int k)
{
	int low = *std::min_element(vec.begin(), vec.end());
	int high = *std::max_element(vec.begin(), vec.end());
	int ans = -1;

	while (low <= high)
	{
		int mid = (low + high)/2;

		int count = count_smaller(vec, n, mid);

		if (count <= k)
		{
			ans = mid;
			low = mid + 1;
		}
		else  
		{
			high = mid - 1;
		}
	}
	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << k_pos_element(vec, n, k) << "\n";

    return 0;
}
