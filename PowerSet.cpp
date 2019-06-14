#include<vector>

void generatePowerSetRecursive (const std::vector<int>& set, std::vector<std::vector<int>>& power_set){
    if (set.size() == 1){
        std::vector<int> t;
        power_set.emplace_back(t);
        power_set.emplace_back(set);
        return;
    }
    std::vector<int> new_set(set.begin(), set.end()-1);
    generatePowerSetRecursive(new_set, power_set);
    int n = power_set.size();
    for (int i = 0; i < n; ++i){
        std::vector<int> t = power_set[i];
        t.emplace_back(set.back());
        power_set.emplace_back(t);
    }
}

std::vector<std::vector<int>> generatePowerSet (const std::vector<int>& set){
    std::vector<std::vector<int>> result;
    generatePowerSetRecursive(set, result);
    return result;
}
