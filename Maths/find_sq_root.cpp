//Given a perfect square. Find the square root

#include <iostream>
#include <vector>
#include <algorithm>

int linear_search_mtd(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (i*i == n)
			return i;
	}
}

int binary_search_mtd(int n)
{
	int l = 1, r = n;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (mid*mid == n)
			return mid;
		else if (mid*mid < n)
			l = mid+1;
		else 
			r = mid-1;
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

    std::cout << linear_search_mtd(n) << "\n";
    std::cout << binary_search_mtd(n) << "\n";

    return 0;

}
