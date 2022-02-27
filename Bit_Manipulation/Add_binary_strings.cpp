#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string add_binary(std::string& a, std::string& b)
{
	std::string res = "";

	int carry = 0, sum;
	int i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
		{
			sum += (a[i] - '0');
		}

		if (j >= 0)
		{
			sum += (b[j] - '0');
		}

		int rem = sum % 2;
		carry = sum / 2;

		res.push_back((char)('0' + rem));

		i--;
		j--;
	}

	std::reverse(res.begin(), res.end());
	return res;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string a, b;
    std::cin >> a >> b;

    std::string r = add_binary(a, b);

    std::cout << r << "\n";

    return 0;

}
