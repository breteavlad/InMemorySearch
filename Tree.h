#pragma once
#include <vector>
#include <string>

struct Node {
    std::vector<Node*> children;
    std::string value;   // full string in each node
    Node(const std::string v) {
        this->value = v;
    }
};

class Tree {
    Node* root;

public:
    Tree();
    Node* createNode(const std::string data);
    Node* insertNode(Node* parent, const std::string data);
    void print(Node* node, int depth);
    Node* getRoot(Tree* t);
    Node* findChild(const std::string data, Node* root);
    int countNodes(Node* root);
};
