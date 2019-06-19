#include<iostream>
#include <memory>
#include <limits>

struct BTNode {
    int data;
    std::shared_ptr<BTNode> left, right;
};

void insertRight(const std::shared_ptr<BTNode>& node, const int& x){
    node -> right = std::make_shared<BTNode>(BTNode{x, nullptr, nullptr});
}

void insertLeft(const std::shared_ptr<BTNode>& node, const int& x){
    node -> left = std::make_shared<BTNode>(BTNode{x, nullptr, nullptr});
}

bool checkBST(const std::shared_ptr<BTNode>& root, const int& min=std::numeric_limits<int>::min(), const int& max=std::numeric_limits<int>::max()){
    if (root){
        if ( (root->data < min) ||(root->data > max)){
            return false;
        }
        return checkBST(root->right, root->data, max) && checkBST(root->left, min, root->data);
    }
    return true;
}