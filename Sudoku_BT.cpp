#include <bits/stdc++.h>
using namespace std;
//**0 in the sud matrix represents the entries that have not been alloted**
//finds the position in sud matrix which has not been assigned
bool position_not_assigned(int arr[9][9], int &row, int &col)
{
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(arr[row][col] == 0)
				return true;
		}
	}
}

//checks for match in the row
bool checkrow(int arr[9][9], int row, int num)
{
	for(int col = 0; col < 9; col++)
	{
		if(arr[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

//checks for match in the column
bool checkcol(int arr[9][9], int col, int num)
{
	for(int row = 0; row < 9; row++)
	{
		if(arr[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

//checks for match in 3X3 block
bool checkblock(int matrix[9][9], int blockrow , int blockcol , int num)
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(matrix[row + blockrow][col + blockcol] == num)
				return true;
		}
	}
	return false;
}

//checks for match for the element to be input in row, column and block by calling checkrow(),checkcol() and checkblock() resp.
bool check_row_col_block(int matrix[9][9], int row , int col, int num)
{
	return (!checkrow(matrix, row, num) && !checkcol(matrix, col, num) && !checkblock(matrix, row - row%3, col-col%3, num));
}

//display the input matrix
void display(int matrix[9][9])
{
	for(int row = 0; row < 9; row++)
	{
		for(int col = 0; col < 9; col++)
		{
			cout << matrix[row][col] << " ";
		}
        cout << endl;
	}
}

//Assigns the number (from 0 to 9) to an element of matrix if that is not present in that row, column and 3X3 block
bool solve(int matrix[9][9])
{
	int row , col;
	if(!position_not_assigned(matrix, row, col))
		return true;
	for(int num = 1; num <= 9; num++)
	{
		if(check_row_col_block(matrix, row, col, num))
		{
			matrix[row][col] = num;
			if(solve(matrix))
				return true;
			matrix[row][col] = 0; 
		}
	}
	return false;
}

int main()
{
	int sud[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	cout << "Unsolved Sudoku::"<<endl;
	display(sud);
	cout<< endl;
	if(solve(sud) == true){
		cout << "Solved Sudoku::" <<endl;
		display(sud);
	}
	else
		cout << "No Solution" << endl;

	return 0;

}
