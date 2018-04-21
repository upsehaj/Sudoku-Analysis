#include<iostream>
using namespace std;

bool findrow(int arr[9][9], int x, int num){
	for (int i = 0; i < 9; i++){
		if (arr[x][i] == num)
			return true;

	}
	return false;
}

bool findcol(int arr[9][9], int y, int num){
	for (int i = 0; i < 9; i++){
		if (arr[i][y] == num)
			return true;

	}
	return false;
}

bool findblock(int arr[9][9], int x, int y,int num){
	int a = x - x % 3;
	int b = y - y % 3;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (arr[i + a][j + b] == num)
				return true;
		}

	}
	return false;
}

void compare(int arr[9][9], int x, int y){
	for (int num = 1; num < 10; num++){

		if ((!findrow(arr, x, num)) && (!findcol(arr, y,num)) && (!findblock(arr, x, y,num))){
			cout<<x<<" "<<y<<"::"<<num<<endl;
			arr[x][y] = num;
			return;
		}


	}
}

void solve(int arr[9][9]){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (arr[i][j] == 0){
				cout<<i<<" "<<j<<endl;
				compare(arr, i, j);
			}
		}
	}
}
void display(int arr[9][9]){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}



int main(){
	int arr[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++)
//			cin >> arr[i][j];

	solve(arr);
	display(arr);
}



