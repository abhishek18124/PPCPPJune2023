#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0; // we will update it from insert()
	}

};

class trie {
	node* root;

public :

	trie() {
		root = new node('#');
	}

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
	}

	string uniquePrefix(string word) {
		string prefix = "";
		node* cur = root;
		for (char ch : word) { // coding
			prefix += ch;
			cur = cur->childMap[ch];
			if (cur->freq == 1) return prefix;
		}
		return "";
	}


};

int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.uniquePrefix(word) << endl;
	}

	return 0;
}