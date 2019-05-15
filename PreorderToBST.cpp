#include<memory>
#include<vector>
#include<stack>

struct BTNode {
    int data;
    std::shared_ptr<BTNode> left, right;
};

std::shared_ptr<BTNode> ReconstructBST (const std::vector<int>& Preorder){
    std::shared_ptr<BTNode> root = std::make_shared<BTNode>();
    root -> data = Preorder[0];
    std::shared_ptr<BTNode> temp = std::make_shared<BTNode>();
    std::stack<std::shared_ptr<BTNode>> rec;
    rec.push(root);
    for (int i = 1; i < Preorder.size(); ++i){
        if (Preorder[i] < rec.top()->data){
            rec.top()->left = std::make_shared<BTNode>();
            rec.top()->left->data = Preorder[i];
            rec.push(rec.top()->left);
        }
        else{
            while ( !rec.empty() && rec.top()->data < Preorder[i]){
                temp = rec.top();
                rec.pop();
            }
            temp->right = std::make_shared<BTNode>();
            temp->right->data = Preorder[i];
            rec.push(temp->right);
        }
    }
    return root;
}