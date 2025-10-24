
#include <iostream>
#include <vector>
using namespace std;

class BoundedBuffer
{
public:

	BoundedBuffer(int capacity) //Default Constructor
	{
		size = capacity;
		buffer.resize(size);
		in = 0;
		out = 0;

	}

	void produceItem(int item)
	{
		//Check the in and out
		if ( (in + 1) % size == out )
		{
			cout << "Buffer is Full, Keep Waiting / Do nothing! \n";
			return;
		}
		
		//else:
		buffer[in] = item;
		in = (in + 1) % size;
		cout << "Item: " << item << " is inserted! \n";

		
	};

	int consumeItem()
	{
		if (in == out)
		{
			cout << "Buffer is Empty // Do nothing! \n";
			return -1;
		}

		int item = buffer[out];
		out = (out + 1) % size;
		cout << "Item: " << item << " has been removed!\n";
		return item;
	}

	void printBufferStatus() const
	{
		cout << "in: " << in << " || out: " << out << " \n";
	}

	~BoundedBuffer()
	{
		cout << "Buffer Destroyed!/n";
	}

private:
	vector<int> buffer;
	int size = 0;
	int in;
	int out;
};


int main()
{

	BoundedBuffer buffer(5);

	buffer.produceItem(50);
	buffer.produceItem(58);
	buffer.produceItem(93);
	buffer.printBufferStatus();





}