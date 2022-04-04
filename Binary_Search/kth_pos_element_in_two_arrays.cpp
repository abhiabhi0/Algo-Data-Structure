/**
 * Given two sorted arrays. Find kth position element if it was 
 * sorted. 
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

int k_pos_element(std::vector<int>&vec1, int n, std::vector<int>&vec2, int m, int k)
{
	int low = std::min(vec1[0], vec2[0]);
	int high = std::max(vec1[n-1], vec2[m-1]);
	int ans = -1;

	while (low <= high)
	{
		int mid = (low + high)/2;

		int count = count_smaller(vec1, n, mid);
		count += count_smaller(vec2, m, mid);

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

    std::vector<int> vec1(n);

    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec1[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> vec2(m);

    for (int i = 0; i < m; ++i)
    {
    	std::cin >> vec2[i];
    }

    std::cout << k_pos_element(vec1, n, vec2, m, k) << "\n";

    return 0;
}
