#include <bits/stdc++.h>
using namespace std;

// struct vertex
// {
//     int x;
//     int y;

//     vertex(int x, int y)
//     {
//         this->x = x;
//         this->y = y;
//     }
// };

// int vertex_index(int x, int y)
// {
//     return 9*x + 9*y
// }

int main(int argc, char const *argv[])
{
    // sudoku elements
    int s[9][9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> s[i][j];
        }
        
    }

    // adjacency matrix
    bool adj[9][9][9][9];
    int index = 0;

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
                
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                for(int l = 0; l < 9; l++)
                    if(adj[i][j][k][l])
                        deg[i][j]++;

    return 0;
}
