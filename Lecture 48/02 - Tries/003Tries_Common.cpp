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
	int n; // no. of words in the trie

public :

	trie() {
		root = new node('#');
		n = 0;
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
		n++;
	}

	string longestCommonPrefix(string word) {
		string prefix = "";
		node* cur = root;
		for (char ch : word) {
			cur = cur->childMap[ch];
			if (cur->freq != n) break;
			prefix += ch;
		}
		return prefix;
	}


};


int main() {

	string words[] = {"flys", "cat"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl; // you can pass any word

	return 0;
}