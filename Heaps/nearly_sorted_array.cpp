/**
 * Given a nearly sorted array. Sort the array.
 * k-sorted : every element is atmost k positions away from
 * its sorted position
**/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> sort_array(std::vector<int>& vec, int k)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	std::vector<int> res;

	for (int i = 0; i <= k; ++i)
	{
		min_heap.push(vec[i]);
	}
	res.push_back(min_heap.top());
	min_heap.pop();

	for (int i = k+1; i < vec.size(); ++i)
	{
		min_heap.push(vec[i]);
		res.push_back(min_heap.top());
		min_heap.pop();
	}
	

	while (!min_heap.empty())
	{
		res.push_back(min_heap.top());
		min_heap.pop();
	}
	return res;
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

    std::vector<int> res = sort_array(vec, k);

    for (int x : res)
    {
    	std::cout << x << " ";
    }

    return 0;
}
