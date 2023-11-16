#include <iostream>
#include <string>
#include <cctype>

bool isIdentifier(const std::string& token) {
    if (!isalpha(token[0]))
        return false;

    for (char c : token) {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}

bool isConstant(const std::string& token) {
    for (char c : token) {
        if (!isdigit(c))
            return false;
    }

    return true;
}

bool isPunctuation(const std::string& token) {
    return token.length() == 1 && ispunct(token[0]);
}

bool isOperator(const std::string& token) {
    // Add your operator recognition logic here
    // For simplicity, let's consider +, -, *, /
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

int main() {
    std::string input;
    std::cout << "Enter text: ";
    std::getline(std::cin, input);

    std::string token;
    for (char c : input) {
        if (isspace(c) || ispunct(c)) {
            if (!token.empty()) {
                if (isIdentifier(token))
                    std::cout << "Identifier: " << token << std::endl;
                else if (isConstant(token))
                    std::cout << "Constant: " << token << std::endl;
                else if (isPunctuation(token))
                    std::cout << "Punctuation: " << token << std::endl;
                else if (isOperator(token))
                    std::cout << "Operator: " << token << std::endl;

                token.clear();
            }

            if (ispunct(c)) {
                std::cout << "Punctuation: " << c << std::endl;
            }
        } else {
            token += c;
        }
    }

    // Check the last token
    if (!token.empty()) {
        if (isIdentifier(token))
            std::cout << "Identifier: " << token << std::endl;
        else if (isConstant(token))
            std::cout << "Constant: " << token << std::endl;
        else if (isOperator(token))
            std::cout << "Operator: " << token << std::endl;
    }

     return 0;
}