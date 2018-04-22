#include<bits/stdc++.h>
using namespace std ;

void start(int Arr[], int N)
{
	for(int i =0;i<N;i++)
	{
		Arr[i] = i;
		size[i] = i;
	}
}

//finding root of an element.
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     Arr[i] = Arr[Arr[i]];
     i = Arr[i];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

int union(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}

bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}



