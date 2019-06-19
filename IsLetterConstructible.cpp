#include<unordered_map>

bool isLetterConstructible(std::string& letter, std::string& magazine) {
    std::unordered_map<char, int> chars_count;
    for (char c : letter){
        if (chars_count.count(c)){
            ++chars_count[c];
        }
        else {
            chars_count[c] = 1;
        }
    }
    for (char c : magazine){
        auto it = chars_count.find(c);
        if (it != chars_count.end()){
            -- it->second;
            if (it ->second == 0){
                chars_count.erase(c);
            }
            if (chars_count.empty()){
                return true;
            }
        }
    }
    return chars_count.empty();
}