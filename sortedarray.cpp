#include<iostream>
using std::cout;
using std::endl;


template <typename T>
class Array {
private:
	T* mData;
	unsigned mCapacity;
	int mSize = 0;

public:
	Array(unsigned capacity):mData (new (T [capacity])),mCapacity(capacity){}

	void insert(T data) {
		int index = mSize;
		while (index>0 && data<mData[index-1])
		{
			mData[index] = mData[index-1];
			index--;
		}
		mData[index] = data;
		mSize++;
	}
	bool search(T data) {
		int i = 0;
		int j = mSize-1;
		while (i <= j) {
			int m = (i + j) / 2;
			if (mData[m] == data) {
				
				return true;
			}
			else if (mData[m] < data) {
				i = m+1;
			}
			else {
				j = m-1;
			}
		}
		return false;


	}
	void print() {
		for (int i = 0; i < mSize; i++)
		{
			cout << mData[i] << endl;
		}
	}
	void remove(T data) {
		int index;
		if (search(data))
		{
			for (int i = 0; i < mSize; i++) {
				if (mData[i] == data)
				{
					index = i;
				}
		}
		}
		else
		{
			return;
		}
		for (index; index < (mSize-2); index++)
		{
			mData[index] = mData[index + 1];

		}
		
		mSize -= 1;
	}
};




int main() {
	Array<int> a(5);
	a.insert(2);
	a.insert(25);
	a.insert(5);
	a.insert(1);
	a.insert(100);
	a.print();
	a.remove(100);
	a.print();
	cout<<a.search(100);
}


