#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool palindrome(std::string& str, int s, int e)
{
    if (s >= e) return true;

    if (str[s] == str[e])
        return palindrome(str, s+1, e-1);

    return false;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string s;
    std::cin >> s;

    std::cout << palindrome(s, 0, s.size()-1) << "\n";

    return 0;

}
