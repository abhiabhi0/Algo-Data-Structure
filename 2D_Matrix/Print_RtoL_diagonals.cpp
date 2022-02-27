//Print all diagonals from Right to Left
//Total diagonals = m + n - 1

#include <iostream>
#include <vector>

void print_diag(std::vector< std::vector<int> >& vec, int s_row, int s_col, int rows, int cols)
{
	int i = s_row, j = s_col;

	while (i < rows && j >= 0)
	{
		std::cout << vec[i][j] << " ";
		i++;
		j--;
	}
}

void diagonals(std::vector< std::vector<int> >& vec, int n, int m)
{
	for (int j = 0; j < m; ++j)
	{
		print_diag(vec, 0, j, n, m);
		std::cout << "\n";
	}

	for (int i = 0; i < n; ++i)
	{
		print_diag(vec, i, m-1, n, m);
		std::cout << "\n";
	}
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int rows, cols;
    std::cin >> rows >> cols;

    std::vector< std::vector<int> > vec(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
    	for (int j = 0; j < cols; ++j)
    	{
    		std::cin >> vec[i][j];
    	}
    }

    diagonals(vec, rows, cols);

    return 0;
}
