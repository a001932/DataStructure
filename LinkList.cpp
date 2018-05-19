// 
// This is HW3 created by c++ code
//

#include <iostream>
using namespace std;

class LinkList;							// for Linklist 

class ListNode							// create a node
{
private:
	int data;
	ListNode *next;

public:
	ListNode():data(0),next(0){};
	ListNode(int a):data(a),next(0){};

	friend class LinkList;
};

class LinkList							// help node to connect
{
private:
	ListNode *first;
public:
	LinkList():first(0){};
	void PrintList();
	void Push_front(int x);
	void Push_back(int x);
	void clear();						// free the memory here
	void Reverse();						// reverse the list
};

void LinkList::PrintList()
{
	if (first==0)
	{
		cout << " list is empty.\n";
		return;
	}
	ListNode *current = first;
	while (current != 0)
	{
		cout << current -> data << " ";
		current = current -> next;
	}
	cout << endl;
};


void LinkList::Push_front(int x)		// add new node at font
{
	ListNode *newnode = new ListNode(x);
	newnode -> next = first;
	first = newnode; 
};


void LinkList::Push_back(int x)
{
	ListNode *newnode = new ListNode(x);

	if(first ==0)
	{
		first = newnode;
		return; 
	}

	ListNode *current = first;
	while(current -> next != 0)
		current = current -> next;
	current -> next = newnode;			// push newnode at the end of list
};

void LinkList::clear()
{
	while(first != 0)
	{
		ListNode *current = first;
		first = first -> next;
		delete current;
		current = 0;
	}
}


void LinkList::Reverse()
{
	if(first ==0 && first -> next ==0)
		return;									// means the list is empty

	ListNode *previous = 0;
	ListNode *current = first;
	ListNode *preceding = first -> next;

	while(preceding != 0)
	{
		current -> next = previous;				// change direction
		previous = current;						// move to next node for reversing the whole list
		current = preceding;
		preceding = preceding -> next;
	}

	current -> next = previous;
	first = current;
};

int main()
{
	LinkList list;						// create list
	list.PrintList();					// print the list
	list.Push_back(5);   				// add number
    list.Push_front(3);   
	list.Push_back(7);   
    list.Push_front(8);	
    list.Push_back(11);   
    list.Push_back(9);   
    list.PrintList();					// print the list again
    list.Reverse();						// reverse the list
    list.PrintList(); 					// make sure they reverse
    list.clear();
}


