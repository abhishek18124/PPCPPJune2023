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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
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

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {

		deleteAtHead(head);
		return;

	}

	// 1. get hold of the pointer to the node at the ith index
	ListNode* curr = getNode(head, i);

	if (curr == NULL) {

		// i >= n i.e. invalid index

		return;

	}

	// 2. get hold of the pointer to the node at the (i-1)th index
	ListNode* prev = getNode(head, i - 1);

	prev->next = curr->next;

	delete curr;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 0);

	printLinkedList(head);

	return 0;
}