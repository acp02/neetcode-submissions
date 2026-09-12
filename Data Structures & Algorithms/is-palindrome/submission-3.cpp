class Solution {
public:
    bool isPalindrome(string s) {
        std::vector<char> str;
        for(char& c : s) {
            c = std::tolower(c);
            if(std::isalnum(c)) str.push_back(c);
        }
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != str[str.size() - 1 - i]) return false;
        }
        return true;
    }
};
