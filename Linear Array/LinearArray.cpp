#include <iostream>

using namespace std;

class LinearArray {

public:
	int itemCount;
	int capacity;
	int *array;

	LinearArray(int maxSize) {
		itemCount = 0;
		capacity = maxSize;
		array = new int[maxSize];
	}

	void insertLast(int x) {
		if (itemCount < capacity) {
			array[itemCount++] = x;
		}
		else {
			cout << "Array is full" << endl;
		}
	}

	void insertFirst(int x) {
		if (itemCount < capacity) {
			for (int i = itemCount; i > 0; i--) {
				array[i] = array[i - 1];
			}
			array[0] = x;
			itemCount++;
		}
		else {
			cout << "Array is full" << endl;
		}
	}

	int linearSearch(int x) {
		for (int i = 0; i < itemCount; i++) {
			if (array[i] == x) {
				return i;
			}
		}
		return -1;
	}

	void deleteEl(int x) {
		int pos = this->linearSearch(x);
		if (pos == -1) {
			cout << "Element not found" << endl;
		}
		else {
			for (int i = pos; i < itemCount - 1; i++) {
				array[i] = array[i + 1];
			}
			itemCount--;
		}
	}

	void displayArray() {
		cout << "Array: ";
		for (int i = 0; i < itemCount; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	~LinearArray() {
		delete array;
	}

};



int main() {

	LinearArray* LA = new LinearArray(5);
	LA->insertFirst(5);
	LA->displayArray();
	LA->insertFirst(4);
	LA->displayArray();
	LA->insertLast(6);
	LA->displayArray();
	LA->deleteEl(5);
	LA->displayArray();
	cout << "Index: " << LA->linearSearch(6) << endl;
	cout << "Index: " << LA->linearSearch(5) << endl;
	delete LA;


	return 0;
}