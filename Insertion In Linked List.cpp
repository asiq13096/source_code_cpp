#include <iostream>
using namespace std;

class Node {
public:
	int Value;
	Node* Next;
};

//Display the content of a Linked List using while loop
void printList(Node* n) {
	while (n != NULL) {
		cout << n->Value << endl;
		n = n->Next;
	}
}

//Following function works on same principle as main function
void insertAtFront(Node** head, int newValue) {
	//1. Prepare new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	//2. Put it in front of current head
	newNode->Next = *head;
	//3.Move head of the list to point to the newNode
	*head = newNode;
}

void insertAtTheEnd(Node** head, int newValue) {
	//1. Prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	//2. If linked list is empty, newNode will be head node
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	//3. Find the last node
	Node* last = *head;
	while (last->Next!=NULL) {
		last = last->Next;
	}
	//4. Insert newNode after last node (at the end)
	last->Next = newNode;
}

void insertAfter(Node*previous,  int newValue) {
	//1. Check if previous node is null
	if (previous == NULL) {
		cout << "Previous can not be null.";
		return;
	}
	//2. Prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	//3. Insert newNode after previous node
	newNode->Next = previous->Next; //Always Connect next node first, So the next location will never lost.
	previous->Next = newNode; //After performing next, we may connect previous node to new one.
}

int main() {
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 3;
	head->Next = second;
	second->Value = 4;
	second->Next = third;
	third->Value = 5;
	third->Next = NULL;

	//Find Out Why 2 and 1 Changed Order
	//insertAtFront(&head, 2);
	//insertAtFront(&head, 1);

	//insertAtTheEnd(&head, 6);

	//insertAfter(second, -1);

	printList(head);
}
