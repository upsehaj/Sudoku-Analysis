#include <bits/stdc++.h>
using namespace std;

bool Check_unassigned(int arr[9][9], int &row, int &col)
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


bool usedinrow(int arr[9][9], int row, int num)
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

bool usedincol(int arr[9][9], int col, int num)
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

bool usedinblock(int arr[9][9], int blockrow , int blockcol , int num)
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(arr[row + blockrow][col + blockcol] == num)
				return true;
		}
	}
	return false;
}

bool isSafe(int arr[9][9], int row , int col, int num)
{
	return (!usedinrow(arr, row, num) && !usedincol(arr, col, num) && !usedinblock(arr, row - row%3, col-col%3, num));
}

void printgrid(int arr[9][9])
{
	for(int row = 0; row < 9; row++)
	{
		for(int col = 0; col < 9; col++)
		{
			cout << arr[row][col] << " ";
		}
        cout << endl;
	}
}

bool SolveSudoku(int arr[9][9])
{
	int row , col;
	if(!Check_unassigned(arr, row, col))
		return true;
	for(int num = 1; num <= 9; num++)
	{
		if(isSafe(arr, row, col, num))
		{
			arr[row][col] = num;
			if(SolveSudoku(arr))
				return true;
			arr[row][col] = 0; //UNASSIGN
		}
	}
	return false;
}

int main()
{
	int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	if(SolveSudoku(grid) == true)
		printgrid(grid);
	else
		cout << "No Solution Exists" << endl;

	return 0;

}