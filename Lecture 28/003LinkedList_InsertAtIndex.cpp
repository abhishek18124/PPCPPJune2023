#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getNode(ListNode* temp, int j) {

	// returns the address of the node at the jth index

	int k = 0;
	while (temp != NULL and k < j) {
		temp = temp->next;
		k++;
	}

	return temp;

}

// time : O(n)

void insertAtIndex(ListNode*& head, int i, int val) {

	if (i == 0) {

		insertAtHead(head, val);
		return;

	}

	// 1. create a new node on the heap with the given val

	ListNode* n = new ListNode(val);

	// 2. get hold of the pointer to the node at the (i-1)th index

	ListNode* prev = getNode(head, i - 1);

	if (prev == NULL) {

		// i exceeds the length of the LL

		return;

	}

	// 3. update the next pointer of the newly created node to point to the node that comes after the prev node

	n->next = prev->next;

	// 4. update the next pointer of the prev node to point to the newly created node

	prev->next =  n;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	insertAtIndex(head, 0, 60);

	printLinkedList(head);

	return 0;
}