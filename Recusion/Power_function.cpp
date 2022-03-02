#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int pow_fun(int b, int p, int m)
{
    if (b == 1 || p == 0) return 1;

    int half_pow = pow_fun(b, p/2, m);
    int half_ans = ((half_pow % m) * (half_pow % m)) % m;

    if (p % 2 == 0)
        return (half_ans % m);
    else  
        return ((half_ans % m) * (b % m)) % m;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int base, pow, mod;
    std::cin >> base >> pow >> mod;

    std::cout << pow_fun(base, pow, mod) << "\n";

    return 0;

}
