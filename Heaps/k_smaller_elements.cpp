#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> k_smaller_ele(std::vector<int>& vec, int k)
{
	std::priority_queue<int> max_heap;

	for (int i = 0; i < k; ++i)
	{
		max_heap.push(vec[i]);
	}

	for (int i = k; i < vec.size(); ++i)
	{
		if (vec[i] < max_heap.top())
		{
			max_heap.pop();
			max_heap.push(vec[i]);
		}
	}
	std::vector<int> res;

	while (!max_heap.empty())
	{
		res.push_back(max_heap.top());
		max_heap.pop();
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

    std::vector<int> res = k_smaller_ele(vec, k);

    for (int x : res)
    {
    	std::cout << x << " ";
    }

    return 0;
}
