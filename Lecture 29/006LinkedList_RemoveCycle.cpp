#include<iostream>

using namespace std;

class ListNode {
public:

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

void removeCycle(ListNode* head) {

	// 1. find the meeting point

	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			// you've reached the meeting point
			break;
		}

	}

	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	// slow->next is equal to fast->next which is the start of the cycle i.e. fast is at the tail

	fast->next = NULL;

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	removeCycle(head);

	printLinkedList(head);

	return 0;
}