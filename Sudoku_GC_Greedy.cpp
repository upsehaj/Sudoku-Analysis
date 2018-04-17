#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int x;
    int y;

    vertex(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};


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

    // adjacency list
    vector<vertex> adj[81];
    int index = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            adj[index++].push_back(vertex(i, j));
        }
        
    }
    
    
    return 0;
}
