#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void tower_of_hanoi(int n, std::string& src, std::string& dest, std::string& temp)
{
	if (n == 0)
		{return;}

	tower_of_hanoi(n-1, src, temp, dest);
	std::cout << "from " << src << " to " << dest << "\n";
	tower_of_hanoi(n-1, temp, dest, src);
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::string src, temp, dest;
    std::cin >> src >> temp >> dest;

    tower_of_hanoi(n, src, dest, temp);

    return 0;
}
