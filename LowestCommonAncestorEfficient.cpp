#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

struct Node {
    int data;
    std::shared_ptr<Node> right, left, parent;
};

void insertRight(const std::shared_ptr<Node>& node, const int& x){
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->data = x;
    node -> right = new_node;
    new_node->parent = node;
}

void insertLeft(const std::shared_ptr<Node>& node, const int& x){
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->data = x;
    node -> left = new_node;
    new_node->parent = node;
}

Node* LCA(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2){
    std::unordered_set<std::shared_ptr<Node>> visited;
    std::shared_ptr<Node> temp1 = node1;
    std::shared_ptr<Node> temp2 = node2;

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