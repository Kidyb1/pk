#include <iostream>

struct Link {
    int value;
    Link* next = nullptr;
};

void reverse(Link*& head) {
    Link* prev = nullptr;
    Link* current = head;
    Link* next = nullptr;

    while (current != nullptr) {
        next = current->next;  
        current->next = prev; 
        prev = current;       
        current = next;  
    }

    head = prev; 
}

void printList(Link* head) {
    while (head != nullptr) {
        std::cout << head->value << "->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Link* head = new Link{ 1 };
    head->next = new Link{ 2 };
    head->next->next = new Link{ 5 };
    head->next->next->next = new Link{ 9 };

    std::cout << "Lista przed odwróceniem: ";
    printList(head);

    reverse(head);

    std::cout << "Lista po odwróceniu: ";
    printList(head);

    while (head != nullptr) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
