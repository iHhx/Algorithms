#include <iostream>

template<class T>
class CircularBuffer
{
public:
    CircularBuffer()
        : capacity(8)
        , element_count(0)
        , head(0)
        , tail(0) { p = new T[capacity]; }

    ~CircularBuffer() { delete[] p; }

    bool empty() const noexcept;
    void reserve(std::size_t new_capacity) noexcept;
    void push_front(int val) noexcept;
    void push_back(int val) noexcept;
    void pop_front() noexcept;
    void pop_back() noexcept;
    void print() const noexcept;

private:
    T* p;
    std::size_t element_count;
    std::size_t capacity;
    std::size_t head;
    std::size_t tail;

    
};

template<class T>
bool CircularBuffer<T>::empty() const noexcept { return !element_count; }

template<class T>
void CircularBuffer<T>::reserve(std::size_t new_capacity) noexcept
{
    if (new_capacity < 1)
            new_capacity = 1;

    T* new_p = new T[new_capacity];

    for (std::size_t i = 0; i < new_capacity; i++)
    {
        new_p[i] = p[(head + i) % capacity];
    }

    delete[] p;
    p = new_p;
    capacity = new_capacity;
    head = 0;
    tail = element_count;
}

template<class T>
void CircularBuffer<T>::push_front(int val) noexcept
{
    if (capacity == element_count)
    {
        reserve(capacity << 1);
    }
    head = (!head ? capacity - 1 : head - 1);
    p[head] = val;

    ++element_count;
}

template<class T>
void CircularBuffer<T>::push_back(int val) noexcept
{
    if (capacity == element_count)
    {
        reserve(capacity << 1);
    }
    p[tail] = val;
    tail = (tail + 1) % capacity;

    ++element_count;
}

template<class T>
void CircularBuffer<T>::pop_front() noexcept
{
    head = (head + 1) % capacity;

    --element_count;
}

template<class T>
void CircularBuffer<T>::pop_back() noexcept
{
    tail = (!tail ? capacity - 1 : tail - 1);

    --element_count;
}

template<class T>
void CircularBuffer<T>::print() const noexcept
{
    std::cout << "\nelement_count = " << element_count
        << ",\ncapacity = " << capacity
        << "\nhead = " << head
        << ",\ntail = " << tail
        << "\n";
    std::cout << "\n--------head - tail--------\n";
    if(!element_count)
        std::cout << "CircularBuffer Empty";
    for (std::size_t i = 0; i < element_count; ++i)
    {
        std::cout << p[(head + i) % capacity] << " ";
    }
    std::cout << "\n\n--------real memory--------\n";
    for (std::size_t i = 0; i < capacity; ++i)
    {
        std::cout << p[i] << " ";
    }
    std::cout << "\n===========================\n\n";
}

int main() {

	CircularBuffer<int> buffer;
    buffer.reserve(4);

	buffer.push_back(1);
    buffer.push_back(2);
    //buffer.push_back(3);
    //buffer.push_back(4);
    //buffer.push_back(5);
    buffer.push_front(6);
    buffer.push_front(7);
    buffer.print();
    buffer.push_back(8);
    //buffer.pop_front();
    buffer.print();
    buffer.pop_front();

    buffer.print();

	return 0;
}