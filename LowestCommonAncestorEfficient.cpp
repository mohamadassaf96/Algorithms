#include <memory>
#include <unordered_set>

struct BTNode {
    int data;
    std::shared_ptr<BTNode> left, right, parent;
};

void insertRight(const std::shared_ptr<BTNode>& node, const int& x){
    node -> right = std::make_shared<BTNode>(BTNode{x, nullptr, nullptr, node});
}

void insertLeft(const std::shared_ptr<BTNode>& node, const int& x){
    node -> left = std::make_shared<BTNode>(BTNode{x, nullptr, nullptr, node});
}

BTNode* LCA(const std::shared_ptr<BTNode>& node1, const std::shared_ptr<BTNode>& node2){
    std::unordered_set<std::shared_ptr<BTNode>> visited;
    std::shared_ptr<BTNode> _node1 = node1;
    std::shared_ptr<BTNode> _node2 = node2;

    while(true){
        _node1 = _node1->parent ? _node1->parent : _node1;
        _node2 = _node2->parent ? _node2->parent : _node2;
        if (visited.count(_node1) == 0)
            visited.emplace(_node1);
        else
            return _node1.get();
        if (visited.count(_node2) == 0)
            visited.emplace(_node2);
        else
            return _node2.get();
    }
}