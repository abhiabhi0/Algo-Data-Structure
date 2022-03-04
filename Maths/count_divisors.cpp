#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// N = p1^a1 * p2^a2 * p3^a3..
// divisors = (a1+1)(a2+1)(a3+1)

int count_divisors(int n)
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
				{
					factors[j] = i;
				}
			}
		}
	}

	int ans = 1;

	while (n > 1)
	{
		int x = factors[n];
		int count = 0;

		while (n % x == 0)
		{
			count++;
			n = n/x;
		}

		ans = ans * (count+1);
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

    std::cout << count_divisors(n) << "\n";

    return 0;
}
