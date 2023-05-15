#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
    std::stack<int> stack;

    while (!std::cin.eof()) {
        std::string tok;
        if (!(std::cin >> tok) || tok == "END") {
            break;
        }

        // Debugging:
        //std::cout << "Token: " << tok << std::endl;

        if (tok == "+") {
            // TODO: plus operator
            int val = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            stack.push(val+val2);
        } else if (tok == "-") {
            // TODO: minus operator
            int val = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            stack.push(val-val2);
        } else if (tok == "*") {
            // TODO: times operator
            int val = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            stack.push(val*val2);
        } else if (tok == "/") {
            // TODO: divide operator
            int val = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            stack.push(val/val2);
        } else {
            int value = atoi(tok.c_str());
            // TODO: an operand
            stack.push(value);
        }

    }

    // print the final result
    std::cout << "Result: " << stack.top() << std::endl;

    return 0;
}
