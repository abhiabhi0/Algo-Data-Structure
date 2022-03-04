//Check if there exists any subsequence in the array such that 
// gcd(subsequence) == 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int gcd(int a, int b)
{
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

bool gcd_seq(std::vector<int>& vec, int n)
{
	int curr = vec[0];

	for (int i = 1; i < n; ++i)
	{
		curr = gcd(curr, vec[i]);

		if (curr == 1)
			return true;
	}	
	return false;
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
    	std::cin >> vec[i];

    std::cout << gcd_seq(vec, n) << "\n";

    return 0;
}
