#include <iostream>

using namespace std;

class LinearSortedArray {
public:
	int itemCount;
	int capacity;
	int* myArr;

	LinearSortedArray(int maxSize) {
		capacity = maxSize;
		myArr = new int[maxSize];
	}

	void orderedInsert(int x) {
		if (itemCount < capacity) {
			int insertionPos = 0;
			while (insertionPos < itemCount && myArr[insertionPos] < x) {
				insertionPos++;
			}

			for (int k = itemCount; k > insertionPos; k--) {
				myArr[k] = myArr[k - 1];
			}

			myArr[insertionPos] = x;
			itemCount++;
		}
		else {
			cout << "Array is full" << endl;
		}
		

	}

	void display() {
		for (int i = 0; i < itemCount; i++) {
			cout << myArr[i] << " ";
		}
	}

	~LinearSortedArray() {
		delete myArr;
	}

};

int main() {

	LinearSortedArray arr(5);
	arr.orderedInsert(5);
	arr.orderedInsert(2);
	arr.orderedInsert(9);
	arr.orderedInsert(6);

	arr.display();

	return 0;
}