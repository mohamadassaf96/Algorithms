#include<vector>
#include <queue>
#include <functional>

struct HeapElement {
    int data, index;
};

std::vector<int> heapMaxK (const std::vector<int>& heap_array, const int& k){
    std::vector<int> result;
    std::priority_queue<HeapElement, std::vector<HeapElement>, std::function<bool(HeapElement, HeapElement)> > temp([](const HeapElement& a, const HeapElement& b) {return a.data <= b.data;} );
    temp.push({heap_array[0], 0});
    while (result.size() < k){
        int index = temp.top().index;
        result.emplace_back(temp.top().data);
        temp.pop();
        if (index*2 + 1 < heap_array.size()) temp.push({ heap_array[index*2 + 1], index*2 + 1});
        if (index*2 + 2 < heap_array.size()) temp.push({ heap_array[index*2 + 2], index*2 + 2});
    }
    return result;
}