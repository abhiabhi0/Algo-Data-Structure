//Given an array of size N. Return the minimum distance b/w any
//two duplicate elements

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

int min_dist(std::vector<int>& vec, int n)
{
	std::unordered_map<int, int> um;
	int dist = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (um.find(vec[i]) != um.end())
		{
			dist = std::min(dist, i-um[vec[i]]);
			um[vec[i]] = i;
		}
		else 
		{
			um.insert({vec[i], i});
		}
	}
	return dist;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << min_dist(vec, n) << "\n";

    return 0;

}
