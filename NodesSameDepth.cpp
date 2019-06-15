#include<memory>
#include<vector>
#include<unordered_map>

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
void nodesSameDepthRec(const std::shared_ptr<BTNode<T>>& root, int d, std::unordered_map<int, std::vector<const std::shared_ptr<BTNode<T>>*> >& nodes_by_depth){
    if (!root){
        return;
    }
    nodes_by_depth[d].emplace_back(&root);
    nodesSameDepthRec(root->left, d+1, nodes_by_depth);
    nodesSameDepthRec(root->right, d+1, nodes_by_depth);
}

template <typename T>
std::unordered_map<int, std::vector<const std::shared_ptr<BTNode<T>>*>>  nodesSameDepth(const std::shared_ptr<BTNode<T>>& root){
    std::unordered_map<int, std::vector<const std::shared_ptr<BTNode<T>>*>> nodes_by_depth;
    nodesSameDepthRec(root, 1, nodes_by_depth);
    return nodes_by_depth;
}

