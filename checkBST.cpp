#include<memory>

struct Node {
    int data;
    std::shared_ptr<Node> left, right;
};

bool checkBST(const std::shared_ptr<Node>& root){



}