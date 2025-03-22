#include <iostream>
#include <memory>

template<typename T>
struct Node
{
    Node(const T& val = 0, std::shared_ptr<Node> node = nullptr) noexcept
        : value(val)
        , next(std::move(node)) {}

    T value;
    std::shared_ptr<Node> next;
};

template<class T>
void reversalForwardList(std::shared_ptr<Node<T>>& head) noexcept
{
    std::shared_ptr<Node<T>> reversed = nullptr;
    while (head)
    {
        auto temp = head->next;
        head->next = reversed;
        reversed = head;
        head = temp;
    }
    head = reversed;
}

int main()
{
    auto head = std::make_shared<Node<int>>(1,
                std::make_shared<Node<int>>(2,
                std::make_shared<Node<int>>(3)));

    reversalForwardList(head);

    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }

    return 0;
}