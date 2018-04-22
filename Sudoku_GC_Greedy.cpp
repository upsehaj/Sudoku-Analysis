#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int x;
    int y;
    int sat_deg;

    vertex()
    {
        this->x = -1;
        this->y = -1;
        this->sat_deg = -1;
    }

    vertex(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->sat_deg = -1;
    }
};

bool comp_degree(struct vertex a, struct vertex b) { return a.sat_deg > b.sat_deg; }

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

    cout << "Unsolved Sudoku:" << endl;
    display(s);
    cout << endl;

    vector<vertex> adj[9][9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                for(int l = 0; l < 9; l++)
                {
                    if(i == k && j != l)
                    {
                        vertex temp1(k, l);
                        adj[i][j].push_back(temp1);
                    }
                    
                    if(j == l && i != k)
                    {
                        vertex temp1(k, l);
                        adj[i][j].push_back(temp1);
                    }                
                }
            }
            for(int row = 0; row < 3; row++)
            {
                for(int col = 0; col < 3; col++)
                {
                    int p = row + i - i%3;
                    int q = col + j - j%3;
                    if(i != p && j != q)
                    {
                        vertex temp1(p, q);
                        adj[i][j].push_back(temp1);
                    }
                }
            } 
        }
    }

    // list of sudoku boxes
    struct vertex v[81];
    int index = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int count = 0;
            for(int k = 0; k < 20; k++)
            {
                if(s[adj[i][j][k].x][adj[i][j][k].y] != 0)
                    count++;
            }
            v[index].x = i;
            v[index].y = j;
            v[index].sat_deg = count;
            index++;
        }
    }
    
    sort(v, v+81, comp_degree);

    for(int color = 1; color <= 9; color++)
    {
        for(int i = 0; i < 81; i++)
        {
            int x = v[i].x;
            int y = v[i].y;
            int flag = false;
            if(s[x][y] == 0)
            {
                for(int j = 0; j < 20; j++)
                {
                    int p = adj[x][y][j].x;
                    int q = adj[x][y][j].y;
                    if(s[p][q] == color)
                    {
                        flag = true;
                        break;
                    }
                }  
                if(!flag)
                    s[x][y] = color;
            }
        }
    }
	
	cout << "Solved Sudoku:" << endl;		
    display(s);  

    return 0;
}