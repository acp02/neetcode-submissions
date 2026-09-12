class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false;
        std::stack<char> characters;
        for(const char c : s) {
            if(c == '[' || c == '(' || c == '{') characters.push(c);
            else if(!characters.empty()){
                char top = characters.top();
                if(top == '[' && c != ']') return false;
                else if(top == '(' && c != ')') return false;
                else if(top == '{' && c != '}') return false;
                characters.pop();
            } else return false;
        }
        if(characters.empty()) return true;
        else return false;
    }
};
