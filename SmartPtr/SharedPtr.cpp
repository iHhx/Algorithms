#include <iostream>

template<class T>
class SharedPtr
{
public:
    explicit SharedPtr(T* ptr) noexcept
        : pointer(ptr)
        , count(new std::uint16_t(1)) {}
    explicit SharedPtr(const SharedPtr&) noexcept;
    SharedPtr& operator=(const SharedPtr&) noexcept;
    T operator*() const noexcept;
    T* operator->() const noexcept;
    operator bool() const noexcept;
    T* get() const noexcept;
    bool unique() const noexcept;
    std::uint16_t getCount() const noexcept;
    void reset(T* ptr = nullptr) noexcept;
   ~SharedPtr();
private:
    T* pointer;
    std::uint16_t* count;
};

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr& obj) noexcept
{
    pointer = obj.pointer;
    count = obj.count;
    ++(*count);
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& obj) noexcept
{
    if (this != &obj)
    {
        if (--(*count) == 0)
            delete pointer;

        pointer = obj.pointer;
        ++(*count);
    }
    return *this;
}

template<class T>
T SharedPtr<T>::operator*() const noexcept
{
    return *pointer;
}

template<class T>
T* SharedPtr<T>::operator->() const noexcept
{
    return pointer;
}

template<class T>
SharedPtr<T>::operator bool() const noexcept
{
    return pointer != nullptr;
}

template<class T>
T* SharedPtr<T>::get() const noexcept
{
    return pointer;
}

template<class T>
bool SharedPtr<T>::unique() const noexcept
{
    return *count == 1;
}

template<class T>
std::uint16_t SharedPtr<T>::getCount() const noexcept
{
    return *count;
}

template<class T>
void SharedPtr<T>::reset(T* ptr) noexcept
{
    if (--(*count) == 0)
    {
        delete pointer;
        delete count;
    }
    if (pointer)
    {
        pointer = ptr;
        count = new std::uint16_t(1);
    }
}

template<class T>
SharedPtr<T>::~SharedPtr()
{
    if (pointer && --(*count) == 0)
    {
        delete pointer;
        delete count;
    }
}
#include<vector>
int main()
{
    // Test structure for testing
    struct Vector2d
    {
        double x, y;
    };
    
    SharedPtr<Vector2d> ptr1(new Vector2d());
    SharedPtr<Vector2d> ptr2(ptr1);

    std::cout << "ptr1: x = " << ptr1->x << ", y = " << ptr1->y << "\n";
    std::cout << "ptr2: x = " << ptr2->x << ", y = " << ptr2->y << "\n";
    
    return 0;
}