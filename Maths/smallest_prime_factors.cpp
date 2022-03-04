#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> smallest_prime_factors(int n)
{
	std::vector<int> factors(n+1);
	
	for (int i = 0; i <= n; ++i)
		factors[i] = i;

	for (int i = 2; i*i <= n; ++i)
	{
		if (factors[i] == i)
		{
			for (int j = i*i; j <= n; j += i)
			{
				if (factors[j] == j)
					factors[j] = i;
			}
		}
	}

	return factors;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<int> factors = smallest_prime_factors(n);

    for (int i = 2; i < factors.size(); ++i)
    {
    	std::cout << i << ":" << factors[i] << " ";
    }

    return 0;
}
