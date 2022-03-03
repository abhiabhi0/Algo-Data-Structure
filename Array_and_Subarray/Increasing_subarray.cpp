//Return true if subarray from L to R is increasing
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool increasing_subarray(std::vector<int>& binary_vec, int s, int e)
{
	for (int i = s+1; i <= e; ++i)
	{
		if (binary_vec[i])
			return false;
	}
	return true;
}

std::vector<bool> check(std::vector<int>& vec)
{
	std::vector<int> binary_vec(vec.size());
	binary_vec[0] = 0;

	std::vector<bool> res;

	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i-1] > vec[i])
		{
			binary_vec[i] = 1;
		}
		else  
		{
			binary_vec[i] = 0;
		}
	}

	// for (int x : binary_vec)
	// {
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n";

	int q;
	std::cin >> q;

	while (q--)
	{
		int l, r;
		std::cin >> l >> r;

		res.push_back(increasing_subarray(binary_vec, l, r));
	}

	return res;
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

    auto res = check(vec);

    for (auto r : res)
    {
    	std::cout << r << "\n";
    }

    return 0;
}
