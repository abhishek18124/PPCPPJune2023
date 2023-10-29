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
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* removeDuplicates(ListNode* head) {

	// base case

	if (head == NULL || head->next == NULL) {
		return head;
	}

	// recursive case

	// LL has >= 2

	if (head->val != head->next->val) {

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		head->next = headFromMyFriend;
		return head;

	} else {

		while (head->next != NULL and head->val == head->next->val) {
			head = head->next;
		}

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		return headFromMyFriend;

	}

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 5);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLinkedList(head);

	head = removeDuplicates(head);

	printLinkedList(head);

	return 0;
}