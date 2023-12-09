/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class ListNode {

public :

	int K;
	int V;
	ListNode* next;

	ListNode(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	ListNode** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(ListNode* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap

		ListNode* temp = head;
		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer

		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity

		ListNode** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity

		N = 2 * N;
		T = new ListNode*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
		M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap

		for (int i = 0; i < oldN; i++) {
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap

		delete [] oldT;
	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new ListNode*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. create a ListNode with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index
		ListNode* n = new ListNode(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created ListNode

		n->next = T[hashIdx];
		T[hashIdx] = n;

		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		double LF = M * 1.0 / N;

		if (LF > L) {
			// rehash
			cout << "rehasing due to LF = " << LF << endl;
			rehash();
		}

	}

	ListNode* find(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. search for the ListNode with the given key in the  linkedList
		//    stored at the hash index

		ListNode* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				// you've found the node you were looking for
				break;
			}
			temp = temp->next;
		}

		return temp;

	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. delete the ListNode with the given key from the linkedList
		//    stored at the hash index

		ListNode* temp = T[hashIdx];

		if (temp == NULL) {

			// LinkedList does not exist at hashIdx

			return;

		} else {

			if (temp->K == K) {

				// delete at head

				T[hashIdx] = temp->next;
				delete temp;
				M--;


			} else {

				ListNode* prev = NULL;

				while (temp != NULL) {

					if (temp->K == K) {

						// delete the temp node

						prev->next = temp->next;
						delete temp;
						M--;

						break;

					}

					prev = temp;
					temp = temp->next;

				}

			}

		}

	}

	void printLinkedList(ListNode* head) {
		while (head) { // head != NULL
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int key) {
		ListNode* temp = find(key);
		if (temp == NULL) {
			int value;
			insert(key, value);
			temp = find(key);
		}
		return temp->V;
	}
};

int main() {

	HashMap hm;

	hm.insert(1, 1);
	hm.insert(7, 49);
	hm.insert(2, 4);

	hm.printHashMap();

	hm.insert(4, 16);

	hm.printHashMap();

	int key = 13;

	ListNode* temp = hm.find(key);

	if (temp != NULL) {

		// key is present in the hashMap

		cout << temp->K << " " << temp->V << endl;

	} else {

		cout << key << " not found" << endl;

	}

	key = 21;

	hm.erase(key);

	hm.printHashMap();

	key = 2;

	cout << hm[key] << endl; // hm.operator[](key)

	key = 1;

	hm[12] = 144;

	// hm.operatr[](12) = 144;

	cout << hm[12] << endl;

	hm.printHashMap();

	hm[12] = 0;

	cout << hm[12] << endl;

	hm.printHashMap();

	return 0;
}