/// Have : () [] {} types of parenthesis
/// Need : check if the sequence is correct

class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stack.push_back(c);
            else if (stack.size() == 0)
                return false;
            else if (stack[stack.size() - 1] == '(' && c != ')' ||
                     stack[stack.size() - 1] == '[' && c != ']' ||
                     stack[stack.size() - 1] == '{' && c != '}')
                return false;
            else stack.pop_back();
        }
        if (stack.size() != 0)
            return false;
        return true;
    }
};
