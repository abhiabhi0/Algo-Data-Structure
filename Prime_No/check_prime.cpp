//Check if a number is a prime number 

#include <iostream>
#include <vector>
#include <algorithm>

bool is_prime(int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    bool res = is_prime(n);

    std::cout << res << "\n";

    return 0;
}
