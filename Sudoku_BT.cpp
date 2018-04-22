#include<iostream>
using namespace std;

// 0 in the sud matrix represents the entries that have not been alloted
// finds the position in sud matrix which has not been assigned
bool unassigned(int arr[9][9])
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9; j++)
		{
			if( arr[i][j] == 0 )
				return true;
		}
	}
	return false;
}

//checks for match in the row
bool findrow(int arr[9][9], int x, int num)
{
	for(int i = 0; i < 9; i++)
	{
		if (arr[x][i] == num)
			return true;

	}
	return false;
}

//checks for match in the column
bool findcol(int arr[9][9], int y, int num)
{
	for (int i = 0 ; i < 9 ; i++)
	{
		if (arr[i][y] == num)
			return true;

	}
	return false;
}

//checks for match in 3X3 block
bool findblock(int arr[9][9], int x, int y,int num)
{
	int a = x - x % 3;
	int b = y - y % 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i + a][j + b] == num)
				return true;
		}

	}
	return false;
}

bool solve(int arr[9][9]);

//checks each possibility by inserting the number from 1 to 9 and if problem then backtracks
bool compare(int arr[9][9])
{
	int x , y;
	for(int i = 0 ; i < 9; i++)
	{
		for(int j = 0 ; j < 9; j++)
		{
			if(arr[i][j] == 0)
			{
				x = i;
				y = j;
			}
					
		}
	}

	for (int num = 1; num < 10; num++)
	{
					
		if ((!findrow(arr, x, num)) && (!findcol(arr, y,num)) && (!findblock(arr, x, y,num)))
		{
			arr[x][y] = num;
			if(solve(arr))
			{
				return true;	
			}
			arr[x][y] = 0;
			
		}
	}
	return false;
}

//checks for unassigned element in the input matrix, if found then calls compare() else returns true
bool solve(int arr[9][9])
{
	if(!unassigned(arr))
		return true;
	
	compare(arr);
		
}

//display the input matrix
void display(int arr[9][9])
{
	for (int i = 0 ; i < 9 ; i++)
	{
		for (int j = 0 ; j < 9 ; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int arr[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					  { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					  { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					  { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					  { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					  { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					  { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					  { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					  { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	
	cout << "SUDOKU Unsolved:" << endl;
	display(arr);
	cout << endl;

	cout << "SUDOKU Solved:";
	if(solve(arr))
		display(arr);

	return 0;

}



