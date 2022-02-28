#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void toggle_case(std::string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] = (s[i] ^ 32);
	}
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string s;
    std::cin >> s;

    toggle_case(s);

    std::cout << s << "\n";

    return 0;
}
