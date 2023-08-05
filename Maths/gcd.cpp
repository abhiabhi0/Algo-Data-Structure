#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int gcd(int a, int b)
{
	if (a == 0) return b;

	return gcd(b, a % b);
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int a, b;
    std::cin >> a >> b;

    std::cout << gcd(a, b) << "\n";

    return 0;
}
