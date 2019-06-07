#include<vector>
#include<queue>

std::vector<int> maxKElements (const std::vector<int>& list, int k){
    std::priority_queue<int, std::vector<int>, std::greater<int>> maxK;
    for (int x : list){
        maxK.emplace(x);
        if (maxK.size() > k){
            maxK.pop();
        }
    }
    std::vector<int> result;
    while (!maxK.empty()){
        result.emplace_back(maxK.top());
        maxK.pop();
    }
    return  result;
}