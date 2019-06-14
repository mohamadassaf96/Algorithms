#include<memory>

template <typename T>
struct LNode {
    T data;
    std::shared_ptr<LNode<T>> next;
};

template <typename T>
void insertAfterTail(const std::shared_ptr<LNode<T>>& head, const T& data){
    std::shared_ptr<LNode<T>> temp = head;
    while (temp->next) temp = temp->next;
    temp->next = std::make_shared<LNode<T>>(LNode<T>{data, nullptr});
}

template <typename T>
void insertAfterTail(const std::shared_ptr<LNode<T>>& head, const std::shared_ptr<LNode<T>>& new_node){
    std::shared_ptr<LNode<T>> temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
}

template <typename T>
bool hasCycle(const std::shared_ptr<LNode<T>>& head){
    std::shared_ptr<LNode<T>> turtle = head;
    std::shared_ptr<LNode<T>> rabbit = head;
    while (rabbit){
        turtle = turtle->next;
        rabbit = rabbit->next ? rabbit->next->next : rabbit ->next;
        if ((turtle == rabbit) && rabbit){
            return true;
        }
    }
    return false;
}