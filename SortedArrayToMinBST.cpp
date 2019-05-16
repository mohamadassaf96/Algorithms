#include<memory>
#include<vector>

struct BTNode{
    int data;
    std::shared_ptr<BTNode> left, right;
};

std::shared_ptr<BTNode> sortedArrayToMinBST (const std::vector<int>& sorted_array){
    if (sorted_array.empty()){
        return nullptr;
    }
    else if (sorted_array.size() == 1){
        return std::make_shared<BTNode>(BTNode{sorted_array[0], nullptr, nullptr});
    }
    int n = sorted_array.size();
    std::shared_ptr<BTNode> root = std::make_shared<BTNode>(BTNode{sorted_array[n/2], nullptr, nullptr});
    std::vector<int> left_sub(sorted_array.begin(), sorted_array.begin() + n/2);
    root -> left = sortedArrayToMinBST(left_sub);
    std::vector<int> right_sub(sorted_array.begin() + n/2 + 1, sorted_array.end());
    root -> right = sortedArrayToMinBST(right_sub);
    return root;
}