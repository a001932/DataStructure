// 
// This is HW8 created by c++ code
//

// HW8_1 here
#include <iostream>
using namespace std;

class aQueue;							// create aQueue, for the big picture(like the array)

class QueueNode							// create a node(like the element)
{
private:
	int data;
	QueueNode *rear;

public:
	QueueNode():data(0),rear(0){};
	QueueNode(int a):data(a),rear(0){};

	friend class aQueue;
};

class aQueue							// help node to connect, def the aQueue and the function of it
{
private:
	QueueNode *first;
    QueueNode *back;
public:
	aQueue():first(0),back(0){};        // pointer is 0 initially
	void PrintaQueue();                 // show the result of every step
	void enqueue(int x);                // First in (add back)
	void dequeue(int x);                // First out (delete front first)
	void clear();						// free the memory here
};


void aQueue::enqueue(int x)             // add new node at back
{
	QueueNode *newnode = new QueueNode(x);  // create node to add

	if(first == 0 & back == 0)
	{
		first = newnode;
        back = first;
		return; 
	}

	QueueNode *current = new QueueNode(x);
    back -> rear = current;
    back = current;
};

void aQueue::PrintaQueue()
{
	if (first == 0)
	{
		cout << " the Queue is empty.\n";
		return;
	}

	QueueNode *current = first;         // like the index, helping printing
	while (current != 0 )
	{
		cout << current -> data << " ";
		current = current -> rear;
	}
	cout << endl;
};



void aQueue::dequeue(int x)		        // delete the node from front
{
    if (first == 0)  cout << "the Queue is empty";
    else
    {
        QueueNode *current = first;
        delete current;
        current = 0;
    }
};

// C++ code
void aQueue::clear(){

    while (first != 0) 
    {            // Traversal
        QueueNode *current = first;
        first = first->rear;
        delete current;
        current = 0;
    }
}

int main()
{
    int Num1 = 65, Num2 = 81, Num3 = 42;
    
    aQueue aaQueue;                         // misuse the name in front, using aaQueue instead
    aaQueue.enqueue(Num1);					// print the Queue
    aaQueue.enqueue(Num2);
    aaQueue.PrintaQueue();					// print the Queue
    aaQueue.dequeue(Num1);
    aaQueue.PrintaQueue();					// print the Queue
    int input = Num2-Num3;
    aaQueue.enqueue(input);
    aaQueue.PrintaQueue();					// print the Queue
    aaQueue.enqueue(Num1);
    aaQueue.PrintaQueue();					// print the Queue
    aaQueue.enqueue(Num3);
    aaQueue.PrintaQueue();					// print the Queue
    aaQueue.clear();
    cout << Num1 << " " << Num2 << " "<< Num3 << endl;
}

// HW8_2 here
//
// Ans: 
// 假設有一個List的資料而且是Link Based，在Insertion sort時每次最多比較n次，1+2+3+...+n ~= n^2
// 所以需要 O(n^2) operations



