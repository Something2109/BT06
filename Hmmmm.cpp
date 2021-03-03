#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Bai A1
/*void f(int a[]) {
	cout << "Array in f: " << &a << endl;
	cout << "First element in f: " << &a[0] << endl;
}

int main() {
	int a[2];
	cout << "Array in main: " << &a << endl;
	cout << "First element in main: " << &a << endl;
	f(a);
}*/
// địa chỉ phàn tử đầu tiên không đổi khi truyền, địa chỉ mảng trong hàm là địa chỉ phần tử đầu
// mảng được truyền vào hàm bằng cách truyền phần tử đầu tiên

//Bai A2
/*double H(int N) {
	return H(N - 1) + 1.0 / N;
}*/
//loop vô tận do thiếu base case để dừng

//Bai A3
/*double H(int N) {
	if (N == 1) return 1.0;
	return H(N) + 1.0 / N;
}*/
//loop vô tận do công thức không đổi 

//Bai A4
/*double H(int N) {
	if (N == 1) return 0.0;
	return H(N - 1) + 1.0 / N;
}*/
//stackOverFlow quá tải bộ nhớ do gọi quá nhiều

//Bai A5
/*long F(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return F(n - 1) + F(n - 2);
}

long F(int n) {
	int n1 = 0,
		n2 = 1;
	if (n == 0) return n1;
	if (n == 1) return n2;
	long F = 0;
	for (int i = 2; i <= n; i++) {
		F = n2 + n1;
		n1 = n2;
		n2 = F;
	}
	return F;
}

int main() {
	int N;
	cin >> N;
	cout << F(N);
}*/

//Bai A6
/*void deQuy(int n) {
	if (n == 0) {
		int i = 8;
	}
	else {
		int a[n];
		deQuy(n - 1);
	}
}

int main() {
	int n;
	cin >> n; 
	deQuy(n);
}*/

//Bai A7
/*void swap(int* arr, int pos_1, int pos_2) {
	int swapChar = arr[pos_1];
	arr[pos_1] = arr[pos_2];
	arr[pos_2] = swapChar;
}

void output(int* arr, int arrangeMentLen) {
	for (int i = 0; i < arrangeMentLen; i++) {
		cout << arr[i] << ' ';
	}
	cout << "     ";
}

void permutation(int* arr, int elementNumber, int scanNumber, int arrangeMentLen) {
	if (scanNumber == arrangeMentLen) {
		output(arr, arrangeMentLen);
	}
	else {
		for (int i = scanNumber; i < elementNumber; i++) {
			swap(arr, scanNumber, i);
			permutation(arr, elementNumber, scanNumber + 1, arrangeMentLen);
			swap(arr, scanNumber, i);
		}
	}
}

int main() {
	int elementNumber, arrangeMentLen;
	cin >> elementNumber >> arrangeMentLen;
	int *arr = new int[elementNumber];
	for (int i = 0; i < elementNumber; i++) {
		arr[i] = i;
	}
	int scanFromBegin = 0;
	permutation(arr, elementNumber, scanFromBegin, arrangeMentLen);
	delete[] arr;
}*/

//Bai A8
/*void output(bool* arr, int* numArr, int n) {
	cout << "[ ";
	for (int i = 0; i < n; i++) {
		if (arr[i]) {
			cout << numArr[i] << ' ';
		}
	}
	cout << ']' << endl;
}

void combination(bool* arr, int* numArr, int n, int scanNumb) {
	if (scanNumb == n) {
		output(arr, numArr, n);
	}
	else {
		arr[scanNumb] = true;
		combination(arr, numArr, n, scanNumb + 1);
		arr[scanNumb] = false;
		combination(arr, numArr, n, scanNumb + 1);
	}
}

int main() {
	int n = 0;
	cin >> n;
	int* numArr = new int[n];
	bool* arr = new bool[n];
	for (int i = 0; i < n; i++) {
		numArr[i] = i;
	}
	combination(arr, numArr, n, 0);
}*/

//Bai C1
/*void output(int* queen, int maxRow) {
	for (int i = 0; i <= maxRow; i++) {
		for (int j = 0; j <= maxRow; j++) {
			if (j != queen[i]) {
				cout << "[ ]";
			}
			else {
				cout << "[|]";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void fillQueenForbid(bool* queenForbid, int maxRow) {
	for (int i = 0; i <= maxRow; i++) {
		queenForbid[i] = false;
	}
}

void forbidCheck(int* queen, bool* queenForbid, int maxRow, int row) {
	for (int i = maxRow; i > row; i--) {
		queenForbid[queen[i]] = true;
		int backward = queen[i] - (i - row);
		if (backward >= 0) {
			queenForbid[backward] = true;
		}
		int forward = queen[i] + (i - row);
		if (forward <= maxRow) {
			queenForbid[forward] = true;
		}
	}
}

void placeQueen(int* queen, int maxRow, int row) {
	if (row < 0) {
		output(queen, maxRow);
		return;
	}
	bool* queenForbid = new bool[maxRow + 1];
	fillQueenForbid(queenForbid, maxRow);
	forbidCheck(queen, queenForbid, maxRow, row);
	for (int i = 0; i <= maxRow; i++) {
		if (queenForbid[i] == false) {
			queen[row] = i;
			placeQueen(queen, maxRow, row - 1);
		}
	}
	delete[] queenForbid;
}

int main() {
	int n;
	cin >> n;
	int* queen = new int[n];
	int maxRow = n - 1;
	placeQueen(queen, maxRow, maxRow);
	delete[] queen;
}*/

//Bai C2
/*void swap(char* arr, int pos_1, int pos_2) {
	char swapChar = arr[pos_1];
	arr[pos_1] = arr[pos_2];
	arr[pos_2] = swapChar;
}

void output(char* arr, int arrangeMentLen) {
	for (int i = 0; i < arrangeMentLen; i++) {
		cout << arr[i];
	}
	cout << "     ";
}

void permutation(char* arr, int elementNumber, int scanNumber, int arrangeMentLen) {
	if (scanNumber == arrangeMentLen) {
		output(arr, arrangeMentLen);
	}
	else {
		for (int i = scanNumber; i < elementNumber; i++) {
			swap(arr, scanNumber, i);
			permutation(arr, elementNumber, scanNumber + 1, arrangeMentLen);
			swap(arr, scanNumber, i);
		}
	}
}

int main() {
	int elementNumber, arrangeMentLen;
	cin >> elementNumber >> arrangeMentLen;
	char *arr = new char[elementNumber];
	for (int i = 0; i < elementNumber; i++) {
		char add = ('a' + i);
		arr[i] = add;
	}
	int scanFromBegin = 0;
	permutation(arr, elementNumber, scanFromBegin, arrangeMentLen);
	delete[] arr;
}*/

//Bai C3
/*void output(bool* arr, char* numArr, int n) {
	cout << '"';
	for (int i = 0; i < n; i++) {
		if (arr[i]) {
			cout << numArr[i];
		}
	}
	cout << "\"     ";
}

void combination(bool* arr, char* numArr, int n, int scanNumb) {
	if (scanNumb == n) {
		output(arr, numArr, n);
	}
	else {
		arr[scanNumb] = true;
		combination(arr, numArr, n, scanNumb + 1);
		arr[scanNumb] = false;
		combination(arr, numArr, n, scanNumb + 1);
	}
}

int main() {
	int n = 0;
	cin >> n;
	char* numArr = new char[n];
	bool* arr = new bool[n];
	for (int i = 0; i < n; i++) {
		numArr[i] = ('a' + i);
	}
	combination(arr, numArr, n, 0);
}*/

