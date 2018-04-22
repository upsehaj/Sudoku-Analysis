#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int x;
    int y;
    int deg;
};

bool comp_degree(struct vertex a, struct vertex b) { return a.deg > b.deg; }

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

    int deg[9][9];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            deg[i][j] = 0;

    struct vertex v[81];
    int index = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                for(int l = 0; l < 9; l++)
                {
                    if(adj[i][j][k][l])
                        deg[i][j]++;
                }
            }
            v[index].x = i;
            v[index].y = j;
            v[index].deg = deg[i][j];
            index++;
        }
    }   

    sort(v, v+81, comp_degree);
    for(int i = 0; i < 81; i++)
    {
        cout << v[i].deg << " ";
    }
    
    return 0;
}