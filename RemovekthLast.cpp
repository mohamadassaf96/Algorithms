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
void removekthLast (std::shared_ptr<LNode<T>> head, int k){
    std::shared_ptr<LNode<T>> rabbit=head, turtle=head, parent=head;
    for (int i = 0; i < k; ++i){
        rabbit=rabbit->next;
        if (!rabbit) return;
    }
    bool c = true;
    while (c) {
        int i,j;
        for (i = 0; i < k; ++i) {
            rabbit = rabbit->next;
            if (!rabbit) {
                c = false;
                break;
            }
        }
        for (j = 0; j < i; ++j) {
            parent = turtle;
            turtle = turtle->next;
        }
    }
    parent->next = turtle->next;
}