#include<memory>
#include<vector>
#include<unordered_set>

struct Indices {
    int start, end;
};

Indices SubstringSearch(const std::vector<std::string>& sentence, const std::vector<std::string>& keywords){

    int i = 0, j = 0;
    Indices result = {0 , (int) sentence.size()};
    std::unordered_set<std::string> hashset;
    for (const std::string& word : keywords) {
        hashset.emplace(word);
    }
    while ( j != sentence.size()){
        std::unordered_set<std::string> temp = hashset;
        for (int k = i; k <=j; ++k){
            if (temp.count(sentence[k]) > 0) {
                temp.erase(sentence[k]);
            }
        }
        if (temp.size() == hashset.size()){
            i = i==j ? ++j : j;
        }
        else if (temp.empty()){
            if ((j - i) < (result.end - result.start)){
                result = {i, j};
            }
            i++;
        }
        else ++j;
    }
    return result;
}
