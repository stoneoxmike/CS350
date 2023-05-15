#include <iostream>
#include <cstdlib>

// The linked list nodes are instances of this class
class Node {
public:
    explicit Node(int v) : value(v), next(nullptr), prev(nullptr) { }
    int value;
    Node *next;
    Node *prev;
};

int main()
{
    Node *head;

    // TODO: initialize the empty list (by assigning to head and tail)
    head = new Node(0);
    // Get values from the user
    std::cout << "Enter integer values (-1 to end):" << std::endl;

    bool done = false;
    while (!done) {
        int userVal;
        std::cin >> userVal;

        if (userVal < 0) {
            done = true;
        } else {
            // TODO: append the value to the end (tail) of the linked list

            Node *userNode = new Node(userVal);
            head->next = userNode;
            userNode->next = head;

        }
    }

    std::cout << "Here are your values:" << std::endl;

    // TODO: print out the values, in order


    // TODO: Cleanup memory


    return 0;
}
