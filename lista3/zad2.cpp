#include <iostream>

struct Link
{
    int value;
    Link* next = nullptr;
};

void release(Link** phead)
{
    if (*phead == nullptr)
        return;

    Link* tmp = *phead;
    *phead = (*phead)->next;
    delete tmp;

    release(phead);
}

int main()
{
    Link* head = new Link{ 1 };
    head->next = new Link{ 2 };
    head->next->next = new Link{ 3 };

    release(&head);

    if (head == nullptr)
        std::cout << "Lista została zwolniona pomyślnie.\n";
    else
        std::cout << "Wystąpił błąd podczas zwalniania listy.\n";

    return 0;
}
