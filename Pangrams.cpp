#include <vector>

std::string isPangram(const std::string& s) {
    std::vector<int> letters_freq(26, 0);
    for (char c : s) {
        int ascii_code = c;
        if (ascii_code <= 90 && ascii_code >= 65) {
            letters_freq[ascii_code-65]++;
        }
        else if (ascii_code <= 122 && ascii_code >= 97) {
            letters_freq[ascii_code-97]++;
        }
    }
    for (int el : letters_freq) {
        if (el == 0) {
            return "not pangram";
        }
    }
    return "pangram";
}