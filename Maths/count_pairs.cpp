//Find number of pairs in an integer array A whose sum is divisible by M

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

int count_pairs(std::vector<int>& vec, int m)
{
	std::unordered_map<int, int> um;
	int ans = 0;

	for (int x : vec)
	{
		int val = x % m;

		if (um.find(val) != um.end())
			um[val]++;
		else  
			um.insert({val, 1});
	}

	for (auto u : um)
	{
		if (u.first == 0)
			ans += (u.second * (u.second -1));
		else  
			ans += (u.second * um[m - u.first]);
	}

	return ans/2;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << count_pairs(vec, m) << "\n";

    return 0;
}
