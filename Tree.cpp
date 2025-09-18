#include <iostream>
#include "Tree.h"

Node* root;

Tree::Tree() {
}

Node* Tree::createNode(const std::string data) {
   
    return new Node(data);
}

Node* Tree:: insertNode(Node* parent,const std::string data) {
    Node* c1=createNode(data);
    if (parent) {
        parent->children.push_back(c1);
    }
    else {
        this->root = c1;
    }
    return c1;
}

Node*  Tree::getRoot(Tree* t) {
    return this->root;
}

void Tree::print(Node* node,int depth) {
    if (node == nullptr) return;
    int i = 0;
    while (i < depth) {
        std::cout << "  ";
        i++;

    }

    std::cout << node->value << std::endl;
    for (Node* n : node->children) {
        
        print(n, depth + 1);
    }

}
int count = 0;
int Tree::countNodes(Node* root) {
    std::cout << "Value of count : " << count << std::endl;
    if (root == nullptr) return 0;
    count++;
    for (Node* n : root->children) {
        countNodes(n);

    }
    return count;
}

//insert root as node always
Node* Tree::findChild(const std::string data,Node* root) {
    if (root == nullptr) return nullptr;

    for (Node* n : root->children) {
        if (n->value == data)
            return n;
    }
    return nullptr;

}




//    int main() {
//        std::cout << "Hello world" << std::endl;
//        Tree* t1 = new Tree();
//        Node* first=t1->insertNode(nullptr,"First");
//        t1->insertNode(first, "Second");
//        Node* child3=t1->insertNode(first, "Third");
//        t1->insertNode(first, "Child4");
//        t1->insertNode(child3, "Child5");
//        t1->print(first, 0);
//        Node* root = t1->getRoot(t1);
//        std::cout << "The root: " << root->value<<std::endl;
//        int nrNodes=t1->countNodes(root);
//        std::cout << "The number of nodes is: " << nrNodes;
//        delete t1;
//}