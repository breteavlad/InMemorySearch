#include <iostream>
#include <vector>

#define ALPHABET_LETTERS 26

struct TrieNode {
	TrieNode* children[ALPHABET_LETTERS];
	bool isEnd;
	char ch;
	TrieNode(char c);
};


class Trie {
public:
	TrieNode* root;
	Trie() {
		root = new TrieNode('\0');
	}
	
	bool startsWith(std::string key);
	void insert( const std::string key);
	void search( const std::string key);
	void print(int depth, TrieNode* root);
	TrieNode* getRoot();
	TrieNode* createNode(char ch);
	std::vector < std::string> findWords(TrieNode* node, std::string prefix, std::vector < std::string>& wordCollector);

private:
	void clear(TrieNode* node) {
		if (!node) {
			return;
		}
		for (int i = 0;i < ALPHABET_LETTERS;i++) {
			clear(node->children[i]);
		}
		delete(node);
	}


};