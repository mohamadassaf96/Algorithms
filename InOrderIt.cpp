#include<memory>

template <typename T>
struct BTNode {
    T data;
    std::shared_ptr<BTNode<T>> left, right, parent;
};

void insertRight(const std::shared_ptr<BTNode<int>>& node, const int& x){
    node -> right = std::make_shared<BTNode<int>>(BTNode<int>{x, nullptr, nullptr, node});
}

void insertLeft(const std::shared_ptr<BTNode<int>>& node, const int& x){
    node -> left = std::make_shared<BTNode<int>>(BTNode<int>{x, nullptr, nullptr, node});
}

void inOrderRec(const std::shared_ptr<BTNode<int>>& root){
    if (root){
        inOrderRec(root->left);
        std::cout<<root->data<<" ";
        inOrderRec(root->right);
    }
}

void InOrderIt(const std::shared_ptr<BTNode<int>>& root){
    std::shared_ptr<BTNode<int>> rightmost=root,temp=root;
    while(rightmost->right) rightmost = rightmost->right;
    while(temp->left) temp = temp->left; //now temp is leftmost.

    do {
        std::cout<<temp->data<<" ";
        if (temp->right){
            temp = temp->right;
            while(temp->left) temp = temp->left;
            continue;
        }
        else {
            if (temp == (temp->parent)->left )
                temp = temp->parent;
            else
                do {
                    temp = temp->parent;
                    if (temp == root) break;
                } while ( (temp == temp->parent->left));
        }
    } while(temp != rightmost);
    std::cout<<temp->data<<" ";
}