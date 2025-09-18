#include <iostream>
#include <vector>
#include <map>
#include <filesystem>
#include "Tree.h"
namespace fs = std::filesystem;

class InSearchEngine {
private:
	std::vector<std::string> documentNames;
	std::vector<std::string> documentContent;
	std::map<std::string, std::string> invertedIndex;
	std::string basePath = "C:/Users/Vlad/Desktop/Projects/C++/In_MemorySearch/Documents";



public:

	//loading all the documents from all the folders
	void loadDocuments() {
		for (const auto& entry : fs::directory_iterator(this->basePath)) {
			std::cout << entry.path() << std::endl;
		}

	}

	void buildTree(Tree* t1) {

		for (const auto& entry : fs::recursive_directory_iterator(basePath)) {
			std::cout << entry.path() << std::endl;
		}
	}
	//build the inverted index
	void buildIndex() {
		for (const auto& entry : fs::directory_iterator(this->basePath)) {

		}
	}
	//search for the keywords.
	void search() {

	}


};

int main() {
	Tree* t1 = new Tree();
	InSearchEngine* searchEngine = new InSearchEngine();
	searchEngine->buildTree(t1);

	/*Node* root = t1->getRoot();
	Node* usr = t1->insertNode(root, "usr/");
	Node* bin = t1->insertNode(root, "bin/");
	Node* home = t1->insertNode(root, "home/");

	t1->insertNode(usr, "local/");
	t1->insertNode(usr, "share/");
	t1->insertNode(home, "user1/");
	t1->insertNode(home, "user2/");
	t1->insertNode(bin, "scripts/");

	std::cout << "Directory structure:\n";*/
	//std::cout << "The directory tree is: "<< t1->findChild(t1->getRoot(), "Architecture.txt")->value<< std::endl;
	//t1->print(t1->getRoot(), 0);


	delete t1; // (optional: we’d add destructors to clean nodes properly)
}
