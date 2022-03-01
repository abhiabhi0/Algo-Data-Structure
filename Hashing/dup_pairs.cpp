//Given an array of N elements. Count the number of duplicate
// pairs i. e. A[i] == A[j], i != j

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


int dup_pairs_mtd1(std::vector<int>& vec)
{
	std::unordered_map<int, int> um;

	for (int x : vec)
	{
		if (um.find(x) != um.end())
			um[x]++;
		else
			um.insert({x, 1});
	}

	// for (auto it : um)
	// {
	// 	std::cout << it.first << " " << it.second << "\n";
	// }

	int sum = 0;

	for (auto it : um)
	{
		if (it.second > 1)
		{
			sum += (((it.second) * (it.second - 1))/2);
		}
	}
	return sum;
}

int dup_pairs_mtd2(std::vector<int>& vec)
{
	std::unordered_map<int, int> um;
	int sum = 0;

	for (int x : vec)
	{
		if (um.find(x) != um.end())
		{
			sum += um[x];
			um[x]++;
		}
		else
			um.insert({x, 1});
	}

	return sum;
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

    std::cout << dup_pairs_mtd1(vec) << "\n";
    std::cout << dup_pairs_mtd2(vec) << "\n";

    return 0;

}
