#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> right, left, parent;
};

void insertRight(const shared_ptr<Node>& node, const int& x){
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->data = x;
    node -> right = new_node;
    new_node->parent = node;
}

void insertLeft(const shared_ptr<Node>& node, const int& x){
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->data = x;
    node -> left = new_node;
    new_node->parent = node;
}

Node* LCA(const shared_ptr<Node>& node1, const shared_ptr<Node>& node2){
    unordered_set<shared_ptr<Node>> visited;
    shared_ptr<Node> temp1 = node1;
    shared_ptr<Node> temp2 = node2;

    while(true){
        temp1 = temp1->parent ? temp1->parent : temp1;
        temp2 = temp2->parent ? temp2->parent : temp2;
        if (visited.count(temp1) == 0)
            visited.emplace(temp1);
        else
            return temp1.get();
        if (visited.count(temp2) == 0)
            visited.emplace(temp2);
        else
            return temp2.get();
    }
}