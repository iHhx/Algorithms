#include <iostream>
//#include <cinttypes>

template<class T>
class XORLinkedList
{
public:
    struct Node
    {
        T value;
        Node* link;
    };

    void push_back(const T& value)
    {
        Node* new_node = new Node{ value, nullptr };
        new_node->link = XOR(new_node, tail);
        tail = new_node;
    }

    template<class Comparator>
    void foreach(Comparator comparator) const noexcept
    {
        Node* iterator = tail;
        while (iterator)
        {
            try {
                comparator(iterator);
            }
            catch (...) {}
            iterator = XOR(iterator, iterator->link);
        }
    }

    void print() const noexcept
    {
        Node* iterator = tail;
        while (iterator)
        {
            std::cout << it->value << "\n";
            iterator = XOR(iterator, iterator->link);
        }
    }

    ~XORLinkedList()
    {
        Node* iterator = tail;
        while (iterator) {
            Node* temp = iterator;
            iterator = XOR(iterator, iterator->link);
            operator delete(temp);
        }
    }
private:
    Node* tail = nullptr;
    Node* XOR(const Node* lhs, const Node* rhs) const noexcept
    {
        return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(lhs) ^ reinterpret_cast<uintptr_t>(rhs));
    }
private:
    static void operator delete(void* ptr)
    {
        std::cout << "delete: " << reinterpret_cast<Node*>(ptr)->value << "\n";
        ::operator delete(ptr);
    }
};


int main()
{
    XORLinkedList<int> list;
    list.push_back(1);
    list.push_back(22);
    list.push_back(333);

    list.foreach([](auto it) {
        std::cout << it->value << "\n";
        });

    return 0;
}