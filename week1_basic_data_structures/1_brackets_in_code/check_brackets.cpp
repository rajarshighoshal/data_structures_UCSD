#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int ans = -1;
    std::stack <Bracket> opening_brackets_stack;
    for (size_t position = 0; position < text.length(); ++position) {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position+1));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty() || !opening_brackets_stack.top().Matchc(next)) {
                ans = position + 1;
                break;
            }
            opening_brackets_stack.pop();
        }
    }

    if(ans == -1 && opening_brackets_stack.empty())
        std::cout << "Success" << '\n';
    else if(ans == -1)
        std::cout << opening_brackets_stack.top().position << '\n';
    else
        std::cout << ans << '\n';
    return 0;
}
