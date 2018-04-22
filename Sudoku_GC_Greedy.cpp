#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int x;
    int y;
    bool done;
};

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

int main(int argc, char const *argv[])
{
    // sudoku elements
    int s[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                   {5, 2, 0, 0, 0, 0, 0, 0, 0},
                   {0, 8, 7, 0, 0, 0, 0, 3, 1},
                   {0, 0, 3, 0, 1, 0, 0, 8, 0},
                   {9, 0, 0, 8, 6, 3, 0, 0, 5},
                   {0, 5, 0, 0, 9, 0, 6, 0, 0},
                   {1, 3, 0, 0, 0, 0, 2, 5, 0},
                   {0, 0, 0, 0, 0, 0, 0, 7, 4},
                   {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    cout << "Unsolved Sudoku::" << endl;
    display(s);
    cout << endl;

    // adjacency matrix
    bool adj[9][9][9][9];

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                for(int l = 0; l < 9; l++)
                    adj[i][j][k][l] = false;

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                for(int l = 0; l < 9; l++)
                {
                    if(i == k && j != l)
                    {
                        adj[i][j][k][l] = true;
                        adj[k][l][i][j] = true;
                    }
                    
                    if(i != k && j == l)
                    {
                        adj[i][j][k][l] = true;
                        adj[k][l][i][j] = true;
                    }
                    
                    for(int row = 0; row < 3; row++)
                    {
                        for(int col = 0; col < 3; col++)
                        {
                            if(i != row + i - i%3 && j != col + j - j%3)
                            {
                                adj[i][j][row + i - i%3][col + j - j%3] = true;
                                adj[row + i - i%3][col + j - j%3][i][j] = true;
                            }
                        }
                    }                  
                }

    // list of sudoku boxes
    struct vertex v[81];
    int index = 0;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            v[index].x = i;
            v[index].y = j;
            v[index].done = false;
            index++;
        }
    
    for(int color = 1; color <= 9; color++)
    {
        for(int i = 0; i < 81; i++)
        {
            int x = v[i].x;
            int y = v[i].y;
            if(s[x][y] == 0)
            {
                int flag = false;
                for(int j = 0; j < 81; j++)
                {
                    int p = v[j].x;
                    int q = v[j].y;
                    if(adj[x][y][p][q] && !v[j].done && s[p][q] != 0)
                    {
                        flag = true;
                        break;
                    }
                }  
                if(!flag)
                    s[x][y] = color;
            }
        }

        for(int i = 0; i < 81; i++)
        {
            if(s[v[i].x][v[i].y] != 0)
                v[i].done = true;
        }
    }
	
	cout << "Solved Sudoku::" << endl;		
    display(s);
	    
    return 0;
}