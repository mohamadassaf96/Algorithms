#include<memory>
#include<vector>
#include<stack>

template <typename T>
struct BTNode {
    T data;
    std::shared_ptr<BTNode<T>> left, right;
};

template <typename T>
void insertRight(const std::shared_ptr<BTNode<T>>& node, const T& x){
    node -> right = std::make_shared<BTNode<T>>(BTNode<T>{x, nullptr, nullptr});
}

template <typename T>
void insertLeft(const std::shared_ptr<BTNode<T>>& node, const T& x){
    node -> left = std::make_shared<BTNode<T>>(BTNode<T>{x, nullptr, nullptr});
}

template <typename T>
bool isLeave(const std::shared_ptr<BTNode<T>>& node){
    return (!node->left && !node->right);
}

template <typename T>
void pushLeft(std::shared_ptr<BTNode<T>>& root, std::vector<std::shared_ptr<BTNode<T>>*>& result){
    if (!root){
        return;
    }
    if (!isLeave(root)){
        result.emplace_back(&root);
    }
    pushLeft(root->left, result);
}

template <typename T>
void pushRight(std::shared_ptr<BTNode<T>>& root, std::vector<std::shared_ptr<BTNode<T>>*>& result){
    if (!root){
        return;
    }
    pushRight(root->right, result);
    if (!isLeave(root)){
        result.emplace_back(&root);
    }
}


template <typename T>
void findLeaves(std::shared_ptr<BTNode<T>>& root, std::vector<std::shared_ptr<BTNode<T>>*>& result){
    if (!root){
        return;
    }
    if (isLeave(root)){
        result.emplace_back(&root);
    }
    else {
        findLeaves(root->left, result);
        findLeaves(root->right, result);
    }
}

template <typename T>
std::vector<std::shared_ptr<BTNode<T>>*> BTExterior (std::shared_ptr<BTNode<T>>& root){
    std::vector<std::shared_ptr<BTNode<T>>*> result;
    pushLeft(root, result);
    findLeaves(root, result);
    pushRight(root, result);
    result.pop_back();
    return result;
}