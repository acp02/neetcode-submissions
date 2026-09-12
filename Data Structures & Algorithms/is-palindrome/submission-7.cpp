class Solution {
public:
    bool isPalindrome(string s) {
        const char* left = s.data();
        const char* right = left + s.length() - 1; // '/0'

        while(left < right) {
            while(!std::isalnum(*left) && left < right) left++;
            while(!std::isalnum(*right) && left < right) right--;
            char l = std::tolower(*left);
            char r = std::tolower(*right);
            if(l != r) return false;

            left++;
            right--;
        }
        return true;
    }
};
