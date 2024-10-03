#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <algorithm>
#include <limits> 
#include <utility> 
#include "Array_ch10.h"
#include <stdexcept>
#include <sstream>
#include "E10_8.h"
#include "BPCE_ch12.h"
#include "CE_ch12.h"
#include "SE_ch12.h"
#include "E_ch12.h"
#include <fstream>
#include <cstring>
#include <sstream>
#include <assert.h>
#include <queue>
#include <thread>
#include <iterator>
#include <vector>        // For std::vector
#include <deque>         // For std::deque
#include <list>          // For std::list
#include <array>         // For std::array
#include <map>           // For std::map
#include <unordered_map> // For std::unordered_map
#include <set>           // For std::set
#include <unordered_set> // For std::unordered_set
#include <stack>         // For std::stack
#include <queue>         // For std::queue and std::priority_queue
#include <algorithm>     // For standard algorithms (e.g., std::sort, std::find)
#include <iostream>      // For input and output streams
#include <string>        // For std::string

using namespace std;
	
#define E_DFS

#ifdef E3_10

int main() {
	E7_mergesort
	Invoice inv1{ "1234", "Hammer", 10, 100 };

	inv1.setQuantity(6969);

	cout << inv1.getInvoiceAmount() << endl;

}

#elif defined(E3_11)

int main() {

	Employee emp1{ "John", "Doe", 1000 };

	cout << emp1.getFirstName() << " " << emp1.getLastName() << " " << emp1.getMonthlySalary() << endl;

}

#elif defined(E4_13)

int main() {

	int miles{ 0 };
	int gallons{ 0 };
	int totalMiles{ 0 };
	int totalGallons{ 0 };

	cout << "\nEnter miles driven (-1 to quit): ";
	cin >> miles;

	while (miles != -1) {

		totalMiles += miles;

		cout << "Enter gallons used: ";
		cin >> gallons;
		totalGallons += gallons;

		cout << "MPG this trip: " << static_cast<double>(miles) / gallons << endl;

		cout << "\nEnter miles driven (-1 to quit): ";
		cin >> miles;

	};

	if (totalGallons != 0) {
		cout << "\nTotal MPG: " << static_cast<double>(totalMiles) / totalGallons << endl;
	}
	else {
		cout << "No data entered" << endl;
	}


};

#elif defined(E4_14)
	
int main() {

	int accountNumber{ 0 };
	double balance{ 0 };
	double totalCharges{ 0 };
	double totalCredits{ 0 };
	double creditLimit{ 0 };

	cout << "Enter account number (-1 to quit): ";
	cin >> accountNumber;

	while (accountNumber != -1) {

		cout << "Enter beginning balance: ";
		cin >> balance;

		cout << "Enter total charges: ";
		cin >> totalCharges;

		cout << "Enter total credits: ";
		cin >> totalCredits;

		cout << "Enter credit limit: ";
		cin >> creditLimit;

		double newBalance = balance + totalCharges - totalCredits;

		cout << "New balance is " << newBalance << endl;

		if (newBalance > creditLimit) {
			cout << "Account:      " << accountNumber << endl;
			cout << "Credit limit: " << creditLimit << endl;
			cout << "Balance:      " << newBalance << endl;
			cout << "Credit Limit Exceeded." << endl;
		}

		cout << "\nEnter account number (-1 to quit): ";
		cin >> accountNumber;

	};

};

#elif defined(E5_29)

int main() {
	// set floating-point number format
	cout << fixed << setprecision(2);

	double principal{ 24.00 }; // initial amount before interest
	//double rate{ 0.05 }; // interest rate
	int years{ 2026-1626 }; // number of years

	cout << "Initial principal: " << principal << endl;

	// display headers
	cout << "\nYear" << setw(30) << "Amount on deposit" << endl;

	// calculate amount on deposit for each of 40 years
	for (unsigned int year{ 0 }; year <= years; year+=40) {
		// calculate amount on deposit at the end of the specified year

		cout << setw(4) << "\n" << year;

		for (double rate{0.05}; rate<=0.1; rate+=0.01)
		{
			// calculate amount on deposit at the end of the specified year
			double amount = principal * pow(1.0 + rate, year);

			// display the year and the amount
			 cout << setw(30) << amount ;
		}

	}
}

#elif defined(E5_30)

int main() {
	DollarAmount d1{ 123, 45 }; // $123.45
	DollarAmount d2{ 15, 76 }; // $15.76

	cout << "After adding d2 (" << d2.toString() << ") into d1 ("
		<< d1.toString() << "), d1 = ";
	d1.add(d2); // modifies object d1
	cout << d1.toString() << "\n";

	cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
		<< d1.toString() << "), d1 = ";
	d1.subtract(d2); // modifies object d1
	cout << d1.toString() << "\n";

	cout << "After subtracting d1 (" << d1.toString() << ") from d2 ("
		<< d2.toString() << "), d2 = ";
	d2.subtract(d1); // modifies object d2
	cout << d2.toString() << "\n\n";



	cout << "Enter integer interest rate and divisor. For example:\n"
		<< "for     2%, enter:    2 100\n"
		<< "for   2.3%, enter:   23 1000\n"
		<< "for  2.37%, enter:  237 10000\n"
		<< "for 2.375%, enter: 2375 100000\n> ";
	int rate; // whole-number interest rate
	int divisor; // divisor for rate 
	cin >> rate >> divisor;

	DollarAmount balance{ 1000, 0 }; // initial principal amount in pennies
	cout << "\nInitial balance: " << balance.toString() << endl;

	// display headers
	cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

	// calculate amount on deposit for each of ten years
	for (unsigned int year{ 1 }; year <= 10; year++) {
		// increase balance by rate % (i.e., rate / divisor)
		balance.addInterest(rate, divisor);

		// display the year and the amount
		cout << setw(4) << year << setw(20) << balance.toString() << endl;
	}
}


#elif defined(E6_17)

double roundToNearest(double, int);

int main() {
	double x{ 0.0 };
	double y{ 0.0 };
	int divisor {0 };

	cout << "Enter a number: ";
	cin >> x;

	cout << "\nEnter round divisor: ";
	cin >> divisor ;

	y = roundToNearest(x, divisor);

	cout << "The number rounded to the nearest integer is: " << y << endl;
	cout << "The original number is: " << x << endl;

}

double roundToNearest(double number, int divisor) {
	return (floor(number * divisor + 0.5)/divisor);
}




#elif defined(E6_36)

	double recExp(double, int);
	
	int main() {

		double x{ 0.0 };
		int n{ 0 };

		while (1) {

			cout << "Enter a number: ";
			cin >> x;

			if (x == -1) {break;}

			cout << "Enter an integer: ";
			cin >> n;

			cout << "The result is: " << recExp(x, n) << endl;

		}

	}

	double recExp(double x, int n) {
		if (n <= 1) {
			return x;
		}
		else {
			return x * recExp(x, n - 1);
		}
	}


#elif defined(E7_22)

class tourOfKnight {

public:


	tourOfKnight(int startRow, int startCol, int boardRow, int boardCol) : 
		startRow{ startRow }, startCol{ startCol }, boardRow{ boardRow }, boardCol{ boardCol } {
	
		tour();
	}

	void constructAccessibility(int boardRow, int boardCol) {

		accessibility.resize(boardRow);
		for (int i = 0; i < boardRow; ++i) {
			accessibility[i].resize(boardCol);
			for (int j = 0; j < boardCol; ++j) {
				accessibility[i][j] = validMoves(i,j);
			}
		}

	}

	int validMoves(int currentRow, int currentCol) {

		int validCount{ 0 };
		for (int valid : knightMoves) {

			int tempRow = { currentRow + vertical[valid] };
			int tempCol = { currentCol + horizontal[valid] };

			if (tempRow < 0 || tempRow > boardRow-1 || tempCol < 0 || tempCol > boardCol-1 || (board[tempRow][tempCol] == 0)) {
				continue;
			}

			else {
				++validCount;
			}

		}

		return validCount;

	}

	void initBoard(int boardRow, int boardCol) {

		int k = 1;
		board.resize(boardRow);
		for (int i = 0; i < boardRow; ++i) {
			board[i].resize(boardCol);
			for (int j = 0; j < boardCol; ++j) {
				board[i][j] = k++;
			}
		}

	}

	int getTouredSquares() const {
		return touredSquares;
	}

	void tour() {

		srand(static_cast<unsigned int>(time(nullptr)));

		initBoard(boardRow, boardCol);
		constructAccessibility(boardRow, boardCol);
		touredSquares = 0;

		currentRow = startRow ;
		currentCol = startCol ;
		board[currentRow][currentCol] = 0;

		int moveNumber;
		bool stuck = false;

		int tempRow;
		int tempCol;

		while (!stuck) {

			vector<int> validMoves{};
			cout << "The valid moves are: ";

			for (int valid : knightMoves) {

				tempRow = { currentRow + vertical[valid] };
				tempCol = { currentCol + horizontal[valid] };

				if (tempRow < 0 || tempRow > boardRow-1 || tempCol < 0 || tempCol > boardCol-1 || (board[tempRow][tempCol] == 0)) {
					continue;
				}

				else {
					cout << valid << " ";
					validMoves.push_back(valid);
				}

			}

			if (validMoves.empty()) {
				cout << "No valid moves left" << endl;
				for (const auto& row : board) {
					for (const auto& element : row) {
						if (element == 0) {
							++touredSquares;
						}
					}
				}

				stuck = true;
				cout << "Toured " << touredSquares << " squares" << endl;

				//check for closed tour

				for (int checkClosed : knightMoves){
				
					tempRow = { currentRow + vertical[checkClosed] };
					tempCol = { currentCol + horizontal[checkClosed] };

					if (tempCol == startCol && tempRow == startRow) {
						cout << "Closed tour" << endl;
					}

				}

				break;
			}

			cout << endl;

			//update accessibility of places to be reached
			for (int valid : validMoves) accessibility[currentRow + vertical[valid]][currentCol + horizontal[valid]]--;

			int minAcc = 99;
			for (int findAcc : validMoves) {

				if (accessibility[currentRow + vertical[findAcc]][currentCol + horizontal[findAcc]] < minAcc) {
					minAcc = accessibility[currentRow + vertical[findAcc]][currentCol + horizontal[findAcc]];
					moveNumber = findAcc;
				}

			}

			//int randomIndex = std::rand() % validMoves.size();
			//int moveNumber = validMoves[randomIndex];

			currentRow += vertical[moveNumber];
			currentCol += horizontal[moveNumber];

			board[currentRow][currentCol] = 0;

		}

	}

private:
	
	int startCol{ 0 };
	int startRow{ 0 };
	int boardRow{ 0 };
	int boardCol{ 0 };
	int currentRow{ 0 };
	int currentCol{ 0 };
	int touredSquares;

	vector<vector<int>> accessibility;
	vector<vector<int>> board;


	array<int, 8> horizontal{ 2, 1, -1, -2, -2, -1 ,1 ,2 };
	array<int, 8> vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };
	array<int, 8> knightMoves{ 0, 1, 2, 3, 4, 5, 6, 7 };

};

int main() {

	tourOfKnight knightTour{ 4, 7, 8, 8 };

	return 0;
}

#elif defined(E7_24)

class nQH { //nQueenHeuristic

public:


	nQH(int startRow, int startCol, int boardRow, int boardCol) :
		startRow{ startRow }, startCol{ startCol }, boardRow{ boardRow }, boardCol{ boardCol } {

		tour();
	}

	void constructAccessibility(int boardRow, int boardCol) {

		accessibility.resize(boardRow);
		for (int i = 0; i < boardRow; ++i) {
			accessibility[i].resize(boardCol);
			for (int j = 0; j < boardCol; ++j) {
				accessibility[i][j] = validMoves(i, j);
			}
		}

	}

	int validMoves(int currentRow, int currentCol) {

		int upRight = min(boardRow - currentCol - 1, boardCol - currentRow - 1);
		int upLeft = min(boardRow - currentCol - 1, currentRow);
		int downRight = min(currentCol, boardCol - currentRow - 1);
		int downLeft = min(currentCol, currentRow);
		

		return upRight + upLeft + downRight + downLeft + 15;

	}

	void initBoard(int boardRow, int boardCol) {

		int k = 1;
		board.resize(boardRow);
		for (int i = 0; i < boardRow; ++i) {
			board[i].resize(boardCol);
			for (int j = 0; j < boardCol; ++j) {
				board[i][j] = k++;
			}
		}

	}

	void elaminateRow(int row) {

		for (int i = 0; i < boardCol; ++i) {
			accessibility[row][i] = 0;
		}

	}
	
	void elaminateCol(int col) {

		for (int i = 0; i < boardRow; ++i) {
			accessibility[i][col] = 0;
		}

	}

	void elaminateDiag(int row, int col) {

		int tempRow = row;
		int tempCol = col;

		while (tempRow < boardRow && tempCol < boardCol) {
			accessibility[tempRow][tempCol] = 0;
			++tempRow;
			++tempCol;
		}

		tempRow = row;
		tempCol = col;

		while (tempRow >= 0 && tempCol >= 0) {
			accessibility[tempRow][tempCol] = 0;
			--tempRow;
			--tempCol;
		}

		tempRow = row;
		tempCol = col;

		while (tempRow >= 0 && tempCol < boardCol) {
			accessibility[tempRow][tempCol] = 0;
			--tempRow;
			++tempCol;
		}

		tempRow = row;
		tempCol = col;

		while (tempRow < boardRow && tempCol >= 0) {
			accessibility[tempRow][tempCol] = 0;
			++tempRow;
			--tempCol;
		}

	}

	void elaminateQueen(int row, int col) {

		elaminateRow(row);
		elaminateCol(col);
		elaminateDiag(row, col);

	}

	pair<int, int> findNonZeroMin(const vector<vector<int>>& array) {
		int minNonZero = numeric_limits<int>::max(); // Initialize to the largest possible integer
		int minRow = -1;
		int minCol = -1;

		for (int i = 0; i < array.size(); ++i) {
			for (int j = 0; j < array[i].size(); ++j) {
				if (array[i][j] != 0 && array[i][j] < minNonZero) {
					minNonZero = array[i][j];
					minRow = i;
					minCol = j;
				}
			}
		}

		// If no non-zero element is found, return an indicator value, e.g., (-1, -1)
		if (minNonZero == numeric_limits<int>::max()) {
			return make_pair(-1, -1);
		}

		return make_pair(minRow, minCol);
	}

	int getTouredSquares() const {
		return touredSquares;
	}

	void printChessboard(const vector<int>& x, const vector<int>& y, int n) {
		// Initialize an empty board filled with dashes '-'
		vector<vector<char>> board(n, vector<char>(n, '-'));

		// Place queens on the board
		for (int i = 0; i < x.size(); ++i) {
			int row = x[i];
			int col = y[i];
			board[row][col] = 'Q';
		}

		// Print the board
		cout << "   ";
		for (int col = 0; col < n; ++col) {
			cout << col << " ";
		}
		cout << endl;

		for (int row = 0; row < n; ++row) {
			cout << row << "  ";
			for (int col = 0; col < n; ++col) {
				cout << board[row][col] << " ";
			}
			cout << endl;
		}
	}

	void printMatrix(const vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) {
			cout << "Empty matrix" << endl;
			return;
		}
		int cols = matrix[0].size();

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void tour() {

		vector<int> xVal{};
		vector<int> yVal{};

		srand(static_cast<unsigned int>(time(nullptr)));

		initBoard(boardRow, boardCol);
		constructAccessibility(boardRow, boardCol);

		printMatrix(accessibility);
		touredSquares = 0;

		currentRow = startRow;
		currentCol = startCol;
		
		int moveNumber;
		bool stuck = false;

		int tempRow;
		int tempCol;

		while (!stuck) {

			touredSquares++;

			elaminateQueen(currentRow, currentCol);
			printMatrix(accessibility);


			pair<int, int> move = findNonZeroMin(accessibility);
			//can bruteforce here


			xVal.push_back(currentRow);
			yVal.push_back(currentCol);

			currentRow = move.first;
			currentCol = move.second;

			if (currentRow == -1 && currentCol == -1) {
				stuck = true;
				cout << "Toured " << touredSquares << " squares" << endl;
				printChessboard(xVal, yVal, 8);

				break;
			}


		}

	}

private:

	int startCol{ 0 };
	int startRow{ 0 };
	int boardRow{ 0 };
	int boardCol{ 0 };
	int currentRow{ 0 };
	int currentCol{ 0 };
	int touredSquares;

	vector<vector<int>> accessibility;
	vector<vector<int>> board;


	array<int, 8> horizontal{ 2, 1, -1, -2, -2, -1 ,1 ,2 };
	array<int, 8> vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };
	array<int, 8> knightMoves{ 0, 1, 2, 3, 4, 5, 6, 7 };

};

int main() {

	nQH nQueen{ 0, 3, 8, 8 };

	return 0;
}



#elif defined(E7_27)

int main() {


	const int size = 1000;
	vector<int> arr(size, 1);
	
	arr[0] = 0;
	arr[1] = 0;

	//sieve of eratosthenes
	for (int i = 2; i < sqrt(size); ++i) {
		if (arr[i] == 1) {
			for (int j = i * i; j < size; j += i) {
				arr[j] = 0;
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		if (arr[i] == 1) {
			cout << i << " ";
		}
	}

}

#elif defined(E7_28)

void isPalindrome(string word) {
		
	//base case
	if (word.size() == 1) {
		cout << "Palindrome" << endl;
		return;
	}

	else if (word[0] == word[word.size() - 1]) {
		isPalindrome(word.substr(1, word.size() - 2));
	}

	else {
		cout << "Not a palindrome" << endl;
		return;
	}
}


int main() {

	string word = "radars";
	
	isPalindrome(word);

}

#elif defined(E7_29)

void printArray(vector<int> arr, int start, int end) {

	if (start == end) return;

	else {
		cout << arr[start] << " ";
		printArray(arr, start + 1, end);
	}
	

}

int main() {

	vector<int> arr{ 1,2,3,4,5,6,7,8,9,10 };

	printArray(arr, 6, 9);

}

#elif defined(E7_31)

void stringReverse(string word, int index = 0) {

	if (index == word.size()) return;

	else {

		stringReverse(word, index + 1);
		cout << word[index];
	}
	
}

int main() {

	string word = "hello";

	stringReverse(word);

}

#elif defined(E7_32)

void findMin(vector<int> arr, int start, int end ) {

	static int min = numeric_limits<int>::max();

	if (start == end) { cout << "Minimum is: " << min; }

	else if (arr[start] <= arr[start + 1]) {

		if (arr[start] < min) {
			min = arr[start];
		}

		findMin(arr, start + 1, end);
	}

	else {
		if (arr[start + 1] < min) {
			min = arr[start + 1];
		}

		findMin(arr, start + 1, end);
	

	}

}

int main() {

	vector<int> arr{ 1,2,3,4,-10,2,7,-7,9,10 };

	findMin(arr, 0, arr.size()-1);

}

#elif defined(E7_33)

const int MAZE_SIZE = 12;
const char WALL = '#';
const char PATH = '.';
const char ENTRY = 'E';
const char EXIT = 'X';

void initializeMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; ++i) {
		for (int j = 0; j < MAZE_SIZE; ++j) {
			maze[i][j] = WALL;
		}
	}
}

void generatePaths(char maze[MAZE_SIZE][MAZE_SIZE]) {
	// Simple random path generation algorithm
	for (int i = 1; i < MAZE_SIZE - 1; ++i) {
		for (int j = 1; j < MAZE_SIZE - 1; ++j) {
			if (rand() % 3 != 0) {
				maze[i][j] = PATH;
			}
		}
	}
}

void setEntryAndExit(char maze[MAZE_SIZE][MAZE_SIZE], int& entryRow, int& entryCol) {
	entryRow = 1;
	entryCol = 0;
	maze[entryRow][entryCol] = ENTRY;

	int exitRow = MAZE_SIZE - 2;
	int exitCol = MAZE_SIZE - 1;
	maze[exitRow][exitCol] = EXIT;
}

void mazeGenerator(char maze[MAZE_SIZE][MAZE_SIZE], int& entryRow, int& entryCol) {
	initializeMaze(maze);
	generatePaths(maze);
	setEntryAndExit(maze, entryRow, entryCol);
}

void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; ++i) {
		for (int j = 0; j < MAZE_SIZE; ++j) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

bool mazeTraverse(char maze[MAZE_SIZE][MAZE_SIZE], int row, int col) {
	// Check boundaries and walls
	if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE || maze[row][col] == WALL) {
		return false;
	}

	// Check if the exit is found
	if (maze[row][col] == EXIT) {
		return true;
	}

	// Mark the path as visited
	if (maze[row][col] != ENTRY) {
		maze[row][col] = '.';
	}

	// Recursive exploration: right, down, left, up
	if (mazeTraverse(maze, row, col + 1) || // right
		mazeTraverse(maze, row + 1, col) || // down
		mazeTraverse(maze, row, col - 1) || // left
		mazeTraverse(maze, row - 1, col)) { // up
		return true;
	}

	// Unmark the visited path (backtrack)
	if (maze[row][col] != ENTRY) {
		maze[row][col] = PATH;
	}

	return false;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	char maze[MAZE_SIZE][MAZE_SIZE];
	int entryRow, entryCol;

	mazeGenerator(maze, entryRow, entryCol);
	printMaze(maze);


	return 0;
}


#elif defined(E7_mergesort)

class intArray {

protected:
	int* _storage;
	int _size;
	int _capacity;
	const int _growthFactor = 20;

public:
	intArray();
	intArray(int num);
	intArray(const char* fileName);
	~intArray();
	int& operator[] (int index);
	void grow();
	int* getArray() { return _storage; }
	int getSize() const { return _size; }
	void printArray() const;


};

intArray::intArray(): _size{0}, _capacity{_growthFactor} {
	_storage = new int[_capacity];
}

intArray::intArray(int num): _size{num-1}, _capacity{num} 
{
	_storage = new int[_capacity];

	for (int i = 0; i < _capacity; ++i)
	{
		_storage[i] = rand() % 100;
	}
}

intArray::intArray(const char* fileName) : _capacity(_growthFactor), _size(0) {
	_storage = new int[_capacity];

	ifstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		int number;
		while (ss >> number) {
			if (_size == _capacity) {
				grow();
			}
			_storage[_size++] = number;
		}
	}
	file.close();
}

intArray::~intArray() {
	delete[] _storage;
	_size = 0;
}

int& intArray::operator [](int index)
{
	assert(index < _size);
	return _storage[index];
}

void intArray::grow() {
	_capacity += _growthFactor;
	int* newStorage = new int[_capacity];
	memcpy(newStorage, _storage, _size * sizeof(int));
	delete[] _storage;
	_storage = newStorage;
}

void intArray::printArray() const {
	for (int i = 0; i < _size; ++i) {
		std::cout << _storage[i] << " ";
	}
	std::cout << std::endl;
}

//pass by ptr and use the intArray class
void merge(int* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	std::copy(arr + left, arr + mid + 1, L.begin());
	std::copy(arr + mid + 1, arr + right + 1, R.begin());

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
}
void mergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}
void mergeSort(intArray* arr) {
	if (arr == nullptr) {
		std::cerr << "Error: null pointer passed to mergeSort." << std::endl;
		return;
	}
	cout << arr->getSize() << endl;
	mergeSort(arr->getArray(), 0, arr->getSize() - 1);
}


//pass by reference
void mergeArr(vector<int>& arr, vector<int>& left, vector<int>& right) {

	int i{ 0 }, j{ 0 }, k{ 0 };

	while (i < left.size() && j < right.size()) {

		if (left[i] < right[j]) {
			arr[k++] = left[i++];
		}
		else {
			arr[k++] = right[j++];
		}

	}

	while (i < left.size()) {
		arr[k++] = left[i++];
	}

	while (j < right.size()) {
		arr[k++] = right[j++];
	}

}
void mergeSort(vector<int>& arr) {

	vector<int> left;
	vector<int> right;

	//base case
	if (arr.size() < 2) return;

	int mid = arr.size() / 2;

	for (int i = 0; i < mid; ++i) {
		left.push_back(arr[i]);
	}

	for (int i = mid; i < arr.size(); ++i) {
		right.push_back(arr[i]);
	}

	mergeSort(left);
	mergeSort(right);
	mergeArr(arr, left, right);
}

//heapsprt pass by ref
void maxHeapify(vector <int>& A, int i, int heapSize) {

	int leftIndex = 2 * i + 1;
	int rightIndex = 2 * i + 2;
	int largest;

	if (leftIndex < heapSize && A[leftIndex] > A[i]) {
		largest = leftIndex;
	}
	else largest = i;

	if (rightIndex < heapSize && A[rightIndex] > A[largest])
	{
		largest = rightIndex;
	}

	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(A, largest, heapSize);
	}

}
void buildMaxHeap(vector<int>& arr) {

	for (int i = arr.size() / 2 - 1; i >= 0; --i) {
		maxHeapify(arr, i, arr.size());
	}

}
void heapSort(vector<int>& arr) {

	buildMaxHeap(arr);

	for (int i = arr.size() - 1; i >= 1; --i) {

		swap(arr[0], arr[i]);
		maxHeapify(arr, 0, i);

	}
}

//heapsort pass by ptr and use the intArray class
void maxHeapify (intArray* A , int i, int heapSize) {

	int leftIndex = 2 * i + 1;
	int rightIndex = 2 * i + 2;
	int largest;

	if (leftIndex < heapSize && A->getArray()[leftIndex] > A->getArray()[i]) {
		largest = leftIndex;
	}
	else largest = i;

	if (rightIndex < heapSize && A->getArray()[rightIndex] > A->getArray()[largest])
	{
		largest = rightIndex;
	}

	if (largest != i) {
		swap(A->getArray()[i], A->getArray()[largest]);
		maxHeapify(A, largest, heapSize);
	}

}
void buildMaxHeap(intArray* arr) {

	for (int i = arr->getSize() / 2 - 1; i >= 0; --i) {
		maxHeapify(arr, i, arr->getSize());
	}

}
void heapSort(intArray* arr) {

	buildMaxHeap(arr);

	for (int i = arr->getSize() - 1; i >= 1; --i) {

		swap(arr->getArray()[0], arr->getArray()[i]);
		maxHeapify(arr, 0, i);

	}
}

int main() {

	const char* fileName = "C:/Users/Moham/Desktop/C++/learn/Source/numbers.txt"; // Path to your file
	intArray arr(fileName);

	std::cout << "Original array:" << std::endl;
	arr.printArray();

	heapSort(&arr);

	std::cout << "Sorted array:" << std::endl;
	arr.printArray();

	vector<int> arrv{ 5,4,7,9,8 };

	mergeSort(arrv);

	cout << endl;

	for (int i = 0; i < arrv.size(); ++i) {
		cout << arrv[i] << " ";
	}

	cout << endl << endl << endl;

	return 0;
}


#elif defined(E9)

class Member {
public:
	int value;

	Member() : value(0) { // Default constructor
		std::cout << "Member default constructor called\n";
	}

	Member(int v) : value(v) { // Parameterized constructor
		std::cout << "Member parameterized constructor called\n";
	}

	void setValue(int v) {
		value = v;
	}
};

class Container {
private:
	static int count;
	Member member;
public:
	static int getCount() { //no const
		return count;
	}

	Container(Member v) : member{ v } { // Member initializer list
		std::cout << "Container constructor called, member value: " << member.value << "\n";
	}
};

int main() {
	std::cout << "Creating Container with parameterized constructor:\n";
	Member m(100); // Calls parameterized constructor of member

	Container c2(m); // Calls parameterized constructor of member

	return 0;
}



#elif defined(E9_14)

class hugeInt {

public:

	hugeInt(const char* number) {

		input(number);

	}

	void input(const string& number) { //can have const char* number


		for (int i = size - number.size(); i < size ; ++i) {

			hugeIntArr[i] = number[i - size + number.size()] - '0';
		}

	}

	void output() {

		for (int i = 0; i < size; ++i) {
			cout << hugeIntArr[i];
		}

	}

	hugeInt& add(hugeInt number) {

		int carry = 0;

		for (int i = size - 1; i >= 0; --i) {

			hugeIntArr[i] += number.hugeIntArr[i] + carry;

			if (hugeIntArr[i] > 9) {
				hugeIntArr[i] -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}

		}

		return *this;

	}

	hugeInt& subtract(hugeInt number) {

		int borrow = 0;

		for (int i = size - 1; i >= 0; --i) {

			hugeIntArr[i] -= number.hugeIntArr[i] + borrow;

			if (hugeIntArr[i] < 0) {
				hugeIntArr[i] += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}

		}

		return *this;

	}

	bool isEqual(hugeInt number) {

		for (int i = 0; i < size; ++i) {
			if ((*this).hugeIntArr[i] != number.hugeIntArr[i]) {
				return false;
			}
		}

		return true;

	}

private:

	static const int size{ 10 };

	array <int, size> hugeIntArr{0};

};

int main() {

	hugeInt x("895556");

	x.output();

}

#elif defined(E9_23)

enum class Face { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
enum class Suit { Hearts, Diamonds, Clubs, Spades };

class card {
private:
	Face face;
	Suit suit;

public:
	// Static arrays of strings representing faces and suits
	static const std::string faces[];
	static const std::string suits[];

	// Constructor
	card(Face cardFace, Suit cardSuit)
		: face(cardFace), suit(cardSuit) {}

	// Function to convert Card to string
	std::string toString() const {
		return faces[static_cast<int>(face)] + " of " + suits[static_cast<int>(suit)];
	}
};

const std::string card::faces[] = {
	"Ace", "Two", "Three", "Four", "Five", "Six",
	"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const std::string card::suits[] = {
	"Hearts", "Diamonds", "Clubs", "Spades"
};

class DeckOfCards {

public:

	DeckOfCards() {
		for (int suit = 0; suit <= static_cast<int>(Suit::Spades); ++suit) {
			for (int face = 0; face <= static_cast<int>(Face::King); ++face) {
				deck.push_back(card(static_cast<Face>(face), static_cast<Suit>(suit)));
			}
		}
	}

	void shuffle() {
		random_shuffle(deck.begin(), deck.end());
		currentCard = 0;
	}

	card dealCard() {
		return deck[currentCard++];
	}

	bool moreCards() const {
		return currentCard < deck.size();
	}

private:
	vector <card> deck; 
	int currentCard{ 0 };
};

int main() {

	DeckOfCards deck;
	deck.shuffle();

	while (deck.moreCards()) {
		cout << deck.dealCard().toString() << endl;
	}

	return 0;
}

#elif defined(E10)

int main() {
	std::string str;

	string* strPtr{ &str };

	cin >> setw(5) >> str;

	try {
		// Attempt to access an out-of-bounds position
		char& c = str.at(2);
		c = 'z';

		cout << *strPtr << endl;

	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception: " << e.what() << std::endl; // Output: Exception: basic_string::at: __n (which is 20) >= this->size() (which is 13)
	}

	return 0;
}

#elif defined(E10_Array)

using namespace std;

// default constructor for class Array (default size 10)
Array::Array(int arraySize)
	: size{ (arraySize > 0 ? static_cast<size_t>(arraySize) :
		 throw invalid_argument{"Array size must be greater than 0"}) },
	ptr{ new int[size] {} } { /* empty body */
}

// copy constructor for class Array;
// must receive a reference to an Array
Array::Array(const Array& arrayToCopy)
	: size{ arrayToCopy.size }, ptr{ new int[size] } {
	for (size_t i{ 0 }; i < size; ++i) {
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}
}

Array::Array(initializer_list<int> list) : size{ list.size() }, ptr{ new int[size] } {
	size_t i{ 0 };
	for (int element : list) {
		ptr[i++] = element;
	}
}

// destructor for class Array
Array::~Array() {
	delete[] ptr; // release pointer-based array space
}

// return number of elements of Array
size_t Array::getSize() const {
	return size; // number of elements in Array
}

// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const Array& Array::operator=(const Array& right) {
	if (&right != this) { // avoid self-assignment
		// for Arrays of different sizes, deallocate original
		// left-side Array, then allocate new left-side Array
		if (size != right.size) {
			delete[] ptr; // release space
			size = right.size; // resize this object
			ptr = new int[size]; // create space for Array copy
		}

		for (size_t i{ 0 }; i < size; ++i) {
			ptr[i] = right.ptr[i]; // copy array into object
		}
	}

	return *this; // enables x = y = z, for example
}

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==(const Array& right) const {
	if (size != right.size) {
		return false; // arrays of different number of elements
	}

	for (size_t i{ 0 }; i < size; ++i) {
		if (ptr[i] != right.ptr[i]) {
			return false; // Array contents are not equal
		}
	}

	return true; // Arrays are equal
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int& Array::operator[](int subscript) {
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size) {
		throw out_of_range{ "Subscript out of range" };
	}

	return ptr[subscript]; // reference return
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[](int subscript) const {
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size) {
		throw out_of_range{ "Subscript out of range" };
	}

	return ptr[subscript]; // returns copy of this element
}

// overloaded input operator for class Array;
// inputs values for entire Array
istream& operator>>(istream& input, Array& a) {
	for (size_t i{ 0 }; i < a.size; ++i) {
		input >> a.ptr[i];
	}

	return input; // enables cin >> x >> y;
}

// overloaded output operator for class Array 
ostream& operator<<(ostream& output, const Array& a) {
	// output private ptr-based array 
	for (size_t i{ 0 }; i < a.size; ++i) {
		output << a.ptr[i] << "  ";
	}

	output << endl;
	return output; // enables cout << x << y;
}

int main() {
	Array integers1{ 7 }; // seven-element Array   
	Array integers2; // 10-element Array by default

	// print integers1 size and contents
	cout << "Size of Array integers1 is " << integers1.getSize()
		<< "\nArray after initialization: " << integers1;

	// print integers2 size and contents
	cout << "\nSize of Array integers2 is " << integers2.getSize()
		<< "\nArray after initialization: " << integers2;

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n"
		<< "integers1: " << integers1
		<< "integers2: " << integers2;

	// use overloaded inequality (!=) operator
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if (integers1 != integers2) {
		cout << "integers1 and integers2 are not equal" << endl;
	}

	// create Array integers3 using integers1 as an          
	// initializer; print size and contents                  
	Array integers3{ integers1 }; // invokes copy constructor

	cout << "\nSize of Array integers3 is " << integers3.getSize()
		<< "\nArray after initialization: " << integers3;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Array is smaller

	cout << "integers1: " << integers1 << "integers2: " << integers2;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if (integers1 == integers2) {
		cout << "integers1 and integers2 are equal" << endl;
	}

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1[5] is " << integers1[5];

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1: " << integers1;

	// attempt to use out-of-range subscript
	try {
		cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
		integers1[15] = 1000; // ERROR: subscript out of range
	}
	catch (out_of_range& ex) {
		cout << "An exception occurred: " << ex.what() << endl;
	}
}




#elif defined(E10_8)

Complex::Complex(double realPart, double imaginaryPart)
	: real{ realPart }, imaginary{ imaginaryPart } { }

// addition operator
Complex Complex::operator+(const Complex& operand2) const {
	return Complex{ real + operand2.real, imaginary + operand2.imaginary };
}

// subtraction operator
Complex Complex::operator-(const Complex& operand2) const {
	return Complex{ real - operand2.real, imaginary - operand2.imaginary };
}

istream& operator>>( istream& input, Complex& operand ) {
	input >> operand.real >> operand.imaginary;
	return input;
}

ostream& operator<<( ostream& output, const Complex& operand ) {
	output << "(" << operand.real << ", " << operand.imaginary << ")";
	return output;
}

Complex Complex::operator* (const Complex& operand2) const {
	return Complex{ real * operand2.real - imaginary * operand2.imaginary,
		real * operand2.imaginary + imaginary * operand2.real };
}

bool Complex::operator==(const Complex& operand2) const {
	return real == operand2.real && imaginary == operand2.imaginary;
}

// return string representation of a Complex object in the form: (a, b)
string Complex::toString() const {
	return "("s + to_string(real) + ", "s + to_string(imaginary) + ")"s;
}

int main() {
	Complex x;
	Complex y{ 4.3, 8.2 };
	Complex z{ 3.3, 1.1 };

	//cout << "x: " << x.toString() << "\ny: " << y.toString()
	//	<< "\nz: " << z.toString();

	//x = y + z;
	//cout << "\n\nx = y + z:\n" << x.toString() << " = " << y.toString()
	//	<< " + " << z.toString();

	//x = y - z;
	//cout << "\n\nx = y - z:\n" << x.toString() << " = " << y.toString()
	//	<< " - " << z.toString() << endl;
	
	//

}



#elif defined(E12)

Employee::Employee(const string& first, const string& last,
	const string& ssn)
	: firstName(first), lastName(last), socialSecurityNumber(ssn) {}

// set first name
void Employee::setFirstName(const string& first) { firstName = first; }

// return first name
string Employee::getFirstName() const { return firstName; }

// set last name
void Employee::setLastName(const string& last) { lastName = last; }

// return last name
string Employee::getLastName() const { return lastName; }

// set social security number
void Employee::setSocialSecurityNumber(const string& ssn) {
	socialSecurityNumber = ssn; // should validate
}

// return social security number
string Employee::getSocialSecurityNumber() const {
	return socialSecurityNumber;
}

// toString Employee's information (virtual, but not pure virtual)
string Employee::toString() const {
	return getFirstName() + " "s + getLastName() +
		"\nsocial security number: "s + getSocialSecurityNumber();
}

CommissionEmployee::CommissionEmployee(const string& first,
	const string& last, const string& ssn, double sales, double rate)
	: Employee(first, last, ssn) {
	setGrossSales(sales);
	setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales) {
	if (sales < 0.0) {
		throw invalid_argument("Gross sales must be >= 0.0");
	}

	grossSales = sales;
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const { return grossSales; }

// set commission rate
void CommissionEmployee::setCommissionRate(double rate) {
	if (rate <= 0.0 || rate > 1.0) {
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}

	commissionRate = rate;
}

// return commission rate
double CommissionEmployee::getCommissionRate() const {
	return commissionRate;
}

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const {
	return getCommissionRate() * getGrossSales();
}

// return a string representation of CommissionEmployee's information 
string CommissionEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "commission employee: " << Employee::toString()
		<< "\ngross sales: " << getGrossSales()
		<< "; commission rate: " << getCommissionRate();
	return output.str();
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& first, const string& last, const string& ssn,
	double sales, double rate, double salary)
	: CommissionEmployee(first, last, ssn, sales, rate) {
	setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Salary must be >= 0.0");
	}

	baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + CommissionEmployee::earnings();
}

// return a string representation of a BasePlusCommissionEmployee
string BasePlusCommissionEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "base-salaried " << CommissionEmployee::toString()
		<< "; base salary: " << getBaseSalary();
	return output.str();
}

SalariedEmployee::SalariedEmployee(const string& first,
	const string& last, const string& ssn, double salary)
	: Employee(first, last, ssn) {
	setWeeklySalary(salary);
}

// set salary
void SalariedEmployee::setWeeklySalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Weekly salary must be >= 0.0");
	}

	weeklySalary = salary;
}

// return salary
double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }

// calculate earnings; 
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return getWeeklySalary(); }

// return a string representation of SalariedEmployee's information 
string SalariedEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "salaried employee: "
		<< Employee::toString() // reuse abstract base-class function
		<< "\nweekly salary: " << getWeeklySalary();
	return output.str();
}

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype

int main() {
   cout << fixed << setprecision(2); // set floating-point formatting

   // create derived-class objects                        
   SalariedEmployee salariedEmployee{
      "John", "Smith", "111-11-1111", 800};
   CommissionEmployee commissionEmployee{
      "Sue", "Jones", "333-33-3333", 10000, .06};
   BasePlusCommissionEmployee basePlusCommissionEmployee{
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300};

   // output each Employees information and earnings using static binding
   cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
      << salariedEmployee.toString()
      << "\nearned $" << salariedEmployee.earnings() << "\n\n"
      << commissionEmployee.toString()
      << "\nearned $" << commissionEmployee.earnings() << "\n\n"
      << basePlusCommissionEmployee.toString()
      << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

   // create and initialize vector of three base-class pointers        
   vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
      &basePlusCommissionEmployee};

   cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

   // call virtualViaPointer to print each Employee's information
   // and earnings using dynamic binding
   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

   for (const Employee* employeePtr : employees) {
      virtualViaPointer(employeePtr);
   }

   // call virtualViaReference to print each Employee's information 
   // and earnings using dynamic binding
   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

   for (const Employee* employeePtr : employees) {
      virtualViaReference(*employeePtr); // note dereferencing
   }
}

// call Employee virtual functions toString and earnings off a   
// base-class pointer using dynamic binding                   
void virtualViaPointer(const Employee* const baseClassPtr) {
   cout << baseClassPtr->toString()
      << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

// call Employee virtual functions toString and earnings off a  
// base-class reference using dynamic binding                
void virtualViaReference(const Employee& baseClassRef) {
   cout << baseClassRef.toString()
      << "\nearned $" << baseClassRef.earnings() << "\n\n";
}


#elif defined(E12_)

void func(int num1, int* numptr, char char1, char* string) {
	cout << "Address of num1 on the stack is: " << &num1 << endl;
	cout << "Address of numptr on the stack is: " << &numptr << endl;
	cout << "Address of char1 on the stack is: " << &char1 << endl;
	cout << "Address of string on the stack is: " << &string << endl;
	cout << "num1 holds: " << num1 << endl;
	cout << "numptr holds: " << numptr << endl;
	cout << "char1 holds: " << char1 << endl;
	cout << "string holds: " << string << endl;
}

int get_scores(int number, int** tests)
{
	int i = 0;
	*tests = new int[number];
	for (i = 0; i < number; i++)
	{
		cout << "Enter score " << i << ": ";
		cin >> (*tests)[i];
	}
	return(1);
}



int main() {

//////////////same implementation different methods

	int sales[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

	int(*ip)[3][4];		
	ip = &sales;

	int(*ip4)[4];
	ip4 = &sales[0]; // or = sales directly as sales itself is a pointer to the first element of the array

	cout << (*ip)[0][2] << endl;
	cout << ip4[0][2] << endl;

	//we can linearize the sales by:
	int* ptr = &sales[0][0]; // or (int*)sales as previouslt sales is of type int*[4]
	
	//int* ptr = (int*)sales;
	
	cout << ptr[2] << endl;

	//In a two - dimensional array, the first dimension equates to an array of x
	//integers and not an integer pointer.
	// hence why we cannot use int **ptr as sales is a pointer to an ARRAY of 4 integers not an pointer to an integer pointer

///////////////////////////////////////////////////

	char myName[5] = "hell";

	char (*cptr)[5] = &myName;

	cout << cptr[0] << endl;
	
	int num;
	//std::cout << (bool)(cin >> num) << " " << num << std::endl; //know what is a void pointer

	cout << !(0) << endl;

///////////////////////////////////////////////////

	const char *strings[] = {"Apple"};

	// Determine the current size of the array
	int size = sizeof(strings) / sizeof(strings[0]);

	// Print the current strings
	std::cout << "Current strings:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << strings[i] << std::endl;
	}

////////////////////////////////////////////////////

	//cout << endl << endl << endl;

	////

	//int num5 = 10;
	//int* numptr5 = &num;
	//char char15 = 'A';
	//char str5[] = "Hello";

	//func(num5, numptr5, char15, str5);
	//
	//cout << endl << endl << endl;

	//int i = 0, * test_array = 0;
	//const int test_num = 5;

	//if (!get_scores(test_num, &test_array))
	//{
	//	cerr << "main: FATAL - get_scores failed!\n";
	//	exit(0);
	//}
	//cout << endl;
	///* print out the scores */
	//cout << "test scores: " << endl;
	//for (i = 0; i < test_num; i++)
	//{
	//	if (!i)
	//		cout << test_array[i];
	//	if (i != test_num - 1)
	//		cout << " " << test_array[i];
	//	else
	//		cout << " " << test_array[i] << endl;

	//}

	//delete[] test_array;

	////////////////////////////////////////////////////

	cout << endl << endl << endl;

	const char* str = "Hello";

	const char* subst = str + sizeof(char);

	cout << subst;

	return 0;
}


#elif defined(E_bst)

//AVL node
class Node {

public:
	int key;
	Node* left;
	Node* right;
	int height;
};

Node* getNewNode(int key) {
	Node* newNode = new Node();
	newNode->key = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 0;
	return newNode;
}

void printTree(Node*);

int getHeight(Node* root) {
	if (root == nullptr) {
		return -1;
	}
	return root->height;
}

int getBalance(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight (Node* root) {
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

void rightRotate(Node** root) {
	Node* newRoot = (*root)->left;
	(*root)->left = newRoot->right;
	newRoot->right = *root;

	*root = newRoot;

	updateHeight((*root)->right);
	updateHeight(*root);
}

void leftRotate(Node** root) {
	Node* newRoot = (*root)->right;
	(*root)->right = newRoot->left;
	newRoot->left = *root;
	*root = newRoot;

	updateHeight((*root)->left);
	updateHeight(*root);
}

void printInOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
}

void insertNode(Node **root, int key) { //can use Node* &root and we dont need dereferencing
										//recall that node Node* is a reference to a pointer
										//we can directly modify the pointer (which is the address of the root node) without dereferencing
	
	if (*root == nullptr) {
		*root = getNewNode(key); //now root if of type Node* 
	}

	else if (key < (*root)->key) {
		insertNode(&(*root)->left, key); //recall precedence, we need to dereference the root first, then access the left node, then pass the address of the left node
	}								
											//in this recursion, we take the address of the pointer to node, this is an alias, and in the revcieveing function, we take it in Node** making root an alias 
											//to whatever node from the parent node 
											//this will be useful in rotate as we can directly modify the parent node's left or right node keeping the child node address constantx	

	else {
		insertNode(&(*root)->right, key);// recurse until we find the correct position
	}

	(*root)->height = 1 + max(getHeight((*root)->left), getHeight((*root)->right)); //update the height of the current node this will update the height of any accesed node

	int balance = getBalance(*root); //get the balance of the current node
	//4 cases of rotation
	//if left is heavier, the balance will be positive
	//if right is heavier, the balance will be negative

	if (balance > 1 && getBalance((*root)->left) > 0) { //left left case
		rightRotate(root);
	}
	else if (balance < -1 && getBalance((*root)->right) < 0 ) { //right right case
		leftRotate(root);
	}
	else if (balance > 1 && getBalance((*root)->left) < 0) { //left right case
		leftRotate(&(*root)->left); 
		rightRotate(root);

	}
	else if (balance < -1 && getBalance((*root)->right) > 0) { //right left case
		rightRotate(&(*root)->right); 
		leftRotate(root);
	}
}

Node* findMin (Node* root) {
	if (root == nullptr) {
		return nullptr;
	}
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

void deleteNode (Node** root, int key) {
	if (*root == nullptr) {
		cout << "Key not found\n";
		return;
	}
	if (key < (*root)->key) {
		deleteNode(&(*root)->left, key);
	}
	else if (key > (*root)->key) {
		deleteNode(&(*root)->right, key);
	}
	else { //key found

		if ((*root)->left == nullptr || (*root)->right == nullptr) { //if the node has one child or no child

			Node* temp = (*root)->left ? (*root)->left : (*root)->right; //can still be null and that means a leaf node else it will be the only child(one will be relinked)
			
			if (temp == nullptr) {//case leaf mode
				temp = *root; //assign leaf node
				*root = nullptr;//null the ptr and delete temp(the space taken by the ptr)
			}
			else { //case one child
				*(*root) = *temp; //activates the assignment operator for the class Node ---- check if dangerous or not ---- as node contains pointer members
			}
			delete temp;//delete the node/ space taken by that ptr
		}
		else { //if the node has two children
			Node* temp = findMin((*root)->right);
			(*root)->key = temp->key;
			deleteNode(&(*root)->right, temp->key);
		}
	}

	if (*root == nullptr) {
		return;
	}

	(*root)->height = 1 + max(getHeight((*root)->left), getHeight((*root)->right));

	int balance = getBalance(*root);

	if (balance > 1 && getBalance((*root)->left) >= 0) {
		rightRotate(root);
	}
	else if (balance < -1 && getBalance((*root)->right) <= 0) {
		leftRotate(root);
	}
	else if (balance > 1 && getBalance((*root)->left) < 0) {
		leftRotate(&(*root)->left);
		rightRotate(root);
	}
	else if (balance < -1 && getBalance((*root)->right) > 0) {
		rightRotate(&(*root)->right);
		leftRotate(root);
	}
}

void printSpaces(int count) {
	for (int i = 0; i < count; i++) {
		cout << " ";
	}
}

// Function to calculate the height of the tree
int treeHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// Function to print the tree level by level
void printTree(Node* root) {
	if (root == nullptr) {
		return;
	}

	// Calculate the height of the tree
	int height = treeHeight(root);

	// Use a queue to do level order traversal
	queue<Node*> q;
	q.push(root);

	// Level order traversal to print the tree
	for (int level = 0; level < height; level++) {
		// Number of nodes at the current level
		int levelNodes = q.size();

		// Print leading spaces for the current level
		printSpaces((1 << (height - level)) - 1);

		// Process all nodes at the current level
		for (int i = 0; i < levelNodes; i++) {
			Node* node = q.front();
			q.pop();

			// Print the node key
			if (node) {
				cout << setw(2) << node->key;
				q.push(node->left);
				q.push(node->right);
			}
			else {
				cout << "  ";
				q.push(nullptr);
				q.push(nullptr);
			}

			// Print spaces between nodes
			printSpaces((1 << (height - level + 1)) - 1);
		}

		// Move to the next level
		cout << endl;
	}
}


int main() {

	Node* rootPtr = nullptr;

	insertNode(&rootPtr, 10);
	insertNode(&rootPtr, 11);
	insertNode(&rootPtr, 8);
	insertNode(&rootPtr, 12);
	insertNode(&rootPtr, 9);
	insertNode(&rootPtr, 6);
	insertNode(&rootPtr, 5);
	insertNode(&rootPtr, 7);
	insertNode(&rootPtr, 4);
	insertNode(&rootPtr, 1);

	printTree(rootPtr);

	cout << endl << endl;

	deleteNode(&rootPtr, 6);

	printTree(rootPtr);

	return 0;
}

#elif defined(E_thread)

class background_task
{
public:

	void operator()() const
	{
		do_something();
		do_something_else();
	}

	void do_something() const {
		cout << "Doing something\n";
	}

	void do_something_else() const {
		cout << "Doing something else\n";
	}


};

int main() {

	background_task f;
	thread my_thread{background_task()};

	my_thread.detach();

}

#elif defined(E_15)

int main() {
	cout << "Enter two integers: ";

	// create istream_iterator for reading int values from cin
	istream_iterator<int> inputInt{ cin };

	int number1{ *inputInt }; // read int from standard input
	++inputInt; // move iterator to next input value        
	int number2{ *inputInt }; // read int from standard input

	// create ostream_iterator for writing int values to cout
	ostream_iterator<int> outputInt{ cout };

	cout << "The sum is: ";
	*outputInt = *(++inputInt);
	cout << endl;
}

#elif defined (E_leet)

class SeatManager {

	vector <int> seats;

public:
	SeatManager(int n) {

		for (int i = 0; i < n; i++) {
			seats.push_back(0);
		}

	}

	int reserve() {

		for (int i = 0; i < seats.size(); i++) {

			if (seats[i] == 0) {

				seats[i] = 1;
				return i + 1;
			}

		}

	}

	void unreserve(int seatNumber) {

		seats[seatNumber] = 0;
	}
};

int steps(int val) {

	int loc{ (val % 2 != 0) ? 3 * val + 1 : val/2 };
	
	if (loc == 1) return 1;

	else return 1 + steps(loc);

}

int main() {

	
	std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Erase every other element
	for (int i = 0; i < vec.size(); i+=2) {
		vec.erase(vec.begin() + i);
		// Adjust the index to account for the erased element
		// Since erasing an element shifts the remaining elements to the left
		--i;
	}

	for (int i = 0; i < vec.size(); i += 2) {
		vec.erase(vec.begin() + i);
		// Adjust the index to account for the erased element
		// Since erasing an element shifts the remaining elements to the left
		--i;
	}

	// Output the modified vector
	for (int v : vec) {
		std::cout << v << " ";
	}
	std::cout << std::endl;


	return 0;
}


#elif defined(E_DFS)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
	int V; // Number of vertices
	vector<int>* adj; // Adjacency list

	void APUtil(int u, vector<bool>& visited, vector<int>& disc,
		vector<int>& low, vector<int>& parent, vector<bool>& ap);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void findAPs(); // Function to find and print all articulation points
};

Graph::Graph(int V) {
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v); // Undirected graph
}

void Graph::APUtil(int u, vector<bool>& visited, vector<int>& disc,
	vector<int>& low, vector<int>& parent, vector<bool>& ap) {
	static int time = 0;

	// Count of children in DFS tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	for (int v : adj[u]) {
		// If v is not visited yet, then make it a child of u in DFS tree
		// and recur for it
		if (!visited[v]) {
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent, ap);

			// Check if the subtree rooted at v has a connection back to
			// one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// u is an articulation point in following cases:

			// (1) u is root of DFS tree and has two or more children.
			if (parent[u] == -1 && children > 1)
				ap[u] = true;

			// (2) u is not root and low value of one of its child is more
			// than discovery value of u.
			if (parent[u] != -1 && low[v] >= disc[u])
				ap[u] = true;
		}
		// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::findAPs() {
	// Mark all the vertices as not visited
	vector<bool> visited(V, false);
	vector<int> disc(V); // Stores discovery times of visited vertices
	vector<int> low(V);  // Earliest visited vertex reachable from subtree
	vector<int> parent(V, -1); // Stores parent vertices in DFS tree
	vector<bool> ap(V, false); // To store articulation points

	// Call the recursive helper function to find articulation points
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			APUtil(i, visited, disc, low, parent, ap);

	// Print articulation points
	cout << "Articulation points in the graph:\n";
	for (int i = 0; i < V; i++)
		if (ap[i] == true)
			cout << i << " ";
	cout << endl;
}

int main() {
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(0, 3);
	g.addEdge(0, 1);
	g.addEdge(2, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(5, 4);

	g.findAPs();

	return 0;
}





#endif
