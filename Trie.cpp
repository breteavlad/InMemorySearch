#include "Trie.h"
#include <iostream>
#include <vector>
//This is based on trie data structure used to find prefixes.

TrieNode::TrieNode(char c)
{
	isEnd = false;
	this->ch = c;
	for (int i = 0;i < ALPHABET_LETTERS;i++) {
		this->children[i] = nullptr;
	}
}

bool Trie::startsWith( std::string key)
{
	TrieNode* curr = this->getRoot();

	for (char c : key) {
		int idx = c - 'a';
		if (!curr->children[idx]) return false;
		curr=curr->children[idx];
	}

	return true;
}
TrieNode* Trie::createNode(char ch) {
	return new TrieNode(ch);
}

void Trie::insert( const std::string key)
{
	TrieNode* current=this->root;
	for (char c : key) {
		//std::cout << c<<std::endl;
		int idx = c - 'a';
		//std::cout << idx << std::endl;
		if (current->children[idx] == nullptr) {
			//std::cout << "Hello from if " << std::endl;
			current->children[idx] = new TrieNode(c);
			//std::cout << idx<<std::endl;
		}
		current = current->children[idx];
		
	}
	current->isEnd = true;
	

}

TrieNode* Trie::getRoot() {
	return this->root;
}

void Trie::print(int depth,TrieNode* root) {
	//std::cout << "Hello from print"<<std::endl;
	int i = 0;
	while (i < depth) {
		std::cout << " ";
		i++;
	}
	//std::cout << "Hello from print 2"<<std::endl;
	for (TrieNode* node : root->children) {
		if (node != nullptr) {
			//std::cout << "Hello from print 3" << node->ch << std::endl;

			std::cout << node->ch << std::endl;
			print(depth + 1, node);
		}
		}

}

std::vector < std::string> Trie::findWords(TrieNode* node,std::string prefix,std::vector<std::string>& wordCollector) {

	//std::cout << "Hello";
	//std::cout << " The first character is: "<<node->ch;
	if (node->isEnd) {
		
		std::string val = prefix + node->ch;
		//std::cout << "The word is: " << val << std::endl;
		wordCollector.push_back(val);
	}
	else {
		//std::cout << "Hello inside else";
		for (TrieNode* next : node->children) {
			
			if (next != nullptr) {
				findWords(next, prefix + node->ch,wordCollector);
				//std::cout << "Next val is: " << next->ch << std::endl;
			}
			}
		
	}
	return wordCollector;

}

void Trie::search(const std::string key)
{
	std::vector<std::string> wordCollector;
	TrieNode* curr = this->getRoot();
	for (char c : key) {
		int idx = c - 'a';
		if(curr->children[idx]==nullptr){
			std::cout << "Couldn't find such a prefix"<<std::endl;
			return;
		}
			curr = curr->children[idx];
	}
	
	//now get the sufix
	//std::cout << "The key value is : " << key << "and the last letter: "<<curr->ch<<std::endl;
	findWords(curr, key.substr(0, key.size() - 1),wordCollector);
	if (wordCollector.empty()) {
		std::cout << "Empty";
	}
	std::cout << "Your options are: "<<std::endl;
	for (std::string word : wordCollector) {
		 std::cout<< word << std::endl;
	}
	
}

int main() {
	Trie* words = new Trie();
	std::string w = "mark";
	words->insert(w);
	words->insert("immortal");
	words->insert("important");
	words->insert("immerse");
	words->insert("imoral");
	words->insert("impersonation");
	words->insert("imitation");
	words->insert("imagination");
	words->insert("impuls");
	words->insert("crescent");
	words->insert("crow");
	words->insert("crip");
	words->insert("dance");
	words->insert("dart");
	words->insert("dasd");


	std::cout <<"The trie structure is: " <<std::endl;
	TrieNode* root = words->getRoot();
	//std::cout << "Root child is: " << root->children[w[0] - 'a']->children[w[1]-'a']->ch << std::endl;
	//words->print(0,root);
	//std::cout << "Is the word: " << w << " in the tree? " << ( words->startsWith("john") ? "True" : "false");
	std::cout << "Enter a prefix for search: ";
	std::string input;
	std::cin >> input;
	words->search(input);
	
}

