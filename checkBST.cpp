#include<iostream>
#include <memory>
#include <limits>

struct Node {
    int data;
    std::shared_ptr<Node> left, right;
};

void insertRight(const std::shared_ptr<Node>& node, const int& x){
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->data = x;
    node -> right = new_node;
}

void insertLeft(const std::shared_ptr<Node>& node, const int& x){
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->data = x;
    node -> left = new_node;
}

bool checkBST(const std::shared_ptr<Node>& root, const int& min=std::numeric_limits<int>::min(), const int& max=std::numeric_limits<int>::max()){
    if (root){
        if ( (root->data < min) ||(root->data > max)){
            return false;
        }
        return checkBST(root->right, root->data, max) && checkBST(root->left, min, root->data);
    }
    return true;
}