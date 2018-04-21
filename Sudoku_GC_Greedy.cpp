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
                {
                    if(i == k && j != l)
                    {
                        adj[i][j][k][l] = true;
                        adj[k][l][i][j] = true;
                    }
                    else 
                    {
                        adj[i][j][k][l] = false;
                        adj[k][l][i][j] = false;
                    }
                    if(i != k && j == l)
                    {
                        adj[i][j][k][l] = true;
                        adj[k][l][i][j] = true;
                    }
                    else 
                    {
                        adj[i][j][k][l] = false;
                        adj[k][l][i][j] = false;
                    }                    
                } 
    
    return 0;
}
