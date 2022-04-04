/**
 * Given n elements, where A[i] = height of ith wall.
 * Pick any two walls such that the water collected between them 
 * is maximum
**/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int container_with_most_water(std::vector<int>& vec, int n)
{
	int ans = 0, i = 0, j = n-1;

	while (i < j)
	{
		int x = (j - i) * std::min(vec[i], vec[j]);
		ans = std::max(ans, x);

		if (vec[i] < vec[j])
		{
			i++;
		}
		else  
		{
			j--;
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

    int n;
    std::cin >> n;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << container_with_most_water(vec, n) << "\n";

    return 0;
}
