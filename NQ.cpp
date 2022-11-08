#include "NQ.h"

void board(int N, vector<vector<int>> pos) {//Prints the board for the graphical interface
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "  " << pos[i][j];//Fill the board with queens and empty space
			if (j != (N - 1)) {
				cout << "  |";//Print board grid col
			}
		}
		cout << "\n";
		if (i != (N - 1)) {
			for (int j = 0; j < N; j++) {
				cout << "----- ";//Print board grid row
			}
			cout << "\n";
		}
	}
	cout << "\n\n";
}

int checker(int N, int posRow, int posCol, vector<vector<int>> pos) {//Checks for a valid placement
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pos[i][j] == 1) {//Checks to see if queen is in that pos
				if (posRow == i && posCol == j) {
				}
				else if (posCol == j) {//Checks if any queen in same col
					return 0;
				}
				else if ((posRow - i) == (posCol - j)) {//Checks diagonal
					return 0;
					
				}
			}
		}
	}
	return 1;
}


int NQueens(int inputN) {
	int posRow, posCol;
	const int N = inputN;
	int flag = 0;
	int back = 1;
	int spot = 0;

	struct moves {
		int row;
		int col;
		moves(int Row, int Col) {
			row = Row;
			col = Col;
		}
	};
	stack<moves> movStack;
	vector<vector<int>> pos(N, vector<int>(N));

	for (int i = 0; i < N; i++) {//Starts the board all blank
		for (int j = 0; j < N; j++) {
			pos[i][j] = 0;
		}
	}
	board(N, pos);

	movStack.push(moves(posRow = 0, posCol = 0));
	pos[0][0] = 1;//Place the queen at the first spot

	while (spot != N) {//Keeps going until all queens are in the valid spot
		if (checker(N, posRow, posCol, pos) && (back) == 1) {
			spot++;
			if (spot != N) {
				posRow++;//Moves right 1
				posCol = 0;
				pos[posRow][posCol] = 1;
				movStack.push(moves(posRow, posCol));
			}
		}
		else if ((posCol + 1) <= (N - 1)) {
			pos[posRow][posCol] = 0;//Adds empty tile
			movStack.pop();
			posCol++;//Moves up 1
			pos[posRow][posCol] = 1;//Adds queen
			movStack.push(moves(posRow, posCol));
			back = 1;
		}
		else {
			pos[posRow][posCol] = 0;//Adds empty tile
			movStack.pop();
			posRow = movStack.top().row;
			posCol = movStack.top().col;
			back = 0;
			spot--;
		}
		board(N, pos);
	}
	return 0;
}

int main() {
	int inputN;
	cout << "Enter N: ";
	cin >> inputN;//Gets the value of N
	
	while (inputN <= 0){//Make sures user inputs a valid number
		cout << "Try Again!\n";
		cout << "Enter a greater N value: ";
		cin >> inputN;
	}

	NQueens(inputN);

	if (inputN <= 3) {//If N is less than 3 theres no valid solution
		cout << "Solution does not exist!\n\n";
	}
	else {
		cout << "Solution found!\n\n";
	}
}