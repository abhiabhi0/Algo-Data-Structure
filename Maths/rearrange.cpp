//Given an array of size N of all distinct integers from 0 to N-1. Rearrange
// the array such that A[i] = A[A[i]]

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void rearrange(std::vector<int>& vec, int n)
{
	for (int i = 0; i < n; ++i)
		vec[i] = vec[i]*n;

	for (int i = 0; i < n; ++i)
	{
		int idx = vec[i]/n;
		
		int val = vec[idx]/n;
		vec[i] = vec[i] + val;
	}

	for (int i = 0; i < n; ++i)
	{
		vec[i] = vec[i] % n;
	}
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

    rearrange(vec, n);

    for (int x : vec)
    	std::cout << x << " ";

    return 0;
}
