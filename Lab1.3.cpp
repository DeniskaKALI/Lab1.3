#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> stack;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else {
            if (stack.empty()) return false;
            if ((c == ')' && stack.top() != '(') ||
                (c == ']' && stack.top() != '[') ||
                (c == '}' && stack.top() != '{')) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    setlocale(LC_ALL, "ru");
    std::string input;
    std::cout << "Введите последовательность скобок: ";
    std::cin >> input;

    if (isValidParentheses(input)) {
        std::cout << "Правильная скобочная последовательность" << std::endl;
    }
    else {
        std::cout << "Неправильная скобочная последовательность" << std::endl;
    }

    return 0;
}
