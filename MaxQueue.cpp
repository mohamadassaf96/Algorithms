#include<deque>
#include<queue>

template <typename T>
class MaxQueue {
private:
    std::queue<T> _queue;
    std::deque<T> _max_elements;
public:
    void enqueue(const T& x){
        _queue.emplace(x);
        while (!_max_elements.empty() && _max_elements.back() < x){
            _max_elements.pop_back();
        }
        _max_elements.push_back(x);
    }
    void dequeue(){
        if (_queue.front() == _max_elements.front()){
            _max_elements.pop_front();
        }
        _queue.pop();
    }
    T front(){
        return _queue.front();
    }
    T max(){
        return _max_elements.front();
    }

};