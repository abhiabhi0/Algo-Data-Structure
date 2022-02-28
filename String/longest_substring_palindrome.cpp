#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int expand(std::string& s, int l, int r)
{
	int n = s.size();
	int i = l, j = r;

	while (i >= 0 && j < n && s[i] == s[j])
	{
		i--;
		j++;
	}

	return j-i-1;
}

int largest_palin(std::string& s)
{
	int ans = 1;

	for (int i = 0; i < s.size(); ++i)
	{
		//Odd length palindrome
		ans = std::max(ans, expand(s, i, i));

		//Even length palindrome
		ans = std::max(ans, expand(s, i, i+1));
	}

	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string s;
    std::cin >> s;

    std::cout << largest_palin(s) << "\n";

    return 0;

}
