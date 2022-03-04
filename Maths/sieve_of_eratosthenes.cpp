#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<bool> sieve(int n)
{
	std::vector<bool> primes(n+1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i <= n; ++i)
	{
		if (primes[i])
		{
			for (int j = i*2; j <= n; j += i)
			{
				primes[j] = false;
			}
		}
	}

	return primes;
}

std::vector<bool> optimised_sieve(int n)
{
	std::vector<bool> primes(n+1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i*i <= n; ++i)
	{
		if (primes[i])
		{
			for (int j = i*i; j <= n; j += i)
			{
				primes[j] = false;
			}
		}
	}

	return primes;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<bool> primes = optimised_sieve(n);

    for (int i = 2; i < primes.size(); ++i)
    {
    	std::cout << i << ":" << primes[i] << " ";
    }

    return 0;
}
