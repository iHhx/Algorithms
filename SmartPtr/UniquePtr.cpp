#include <iostream>
#include <cassert>
#include <type_traits>

template<class T>
class UniquePtr
{
    T* ptr;
public:
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
public:
    explicit UniquePtr(T* p = nullptr) noexcept
        : ptr(p) {}

    ~UniquePtr() { delete ptr; }

    explicit UniquePtr(UniquePtr&& obj) noexcept
        : ptr(obj.release()) {}

    template<class U>
    explicit UniquePtr(UniquePtr<U>&& obj) noexcept
        : ptr(obj.release())
    {
        static_assert(std::is_convertible<T*, U*>::value, "Conversion is impossible");
    }

    UniquePtr& operator=(UniquePtr&& obj) noexcept
    {
        reset(obj.release());
        return *this;
    }

    template<class U>
    UniquePtr& operator=(UniquePtr<U>&& obj) noexcept
    {
        static_assert(std::is_convertible<T*, U*>::value, "Conversion is impossible");
        reset(obj.release());
        return *this;
    }

    void swap(UniquePtr&& obj) noexcept
    {
        using std::swap;
        swap(ptr, obj.ptr);
    }

    T* release() noexcept
    {
        T* tmp_ptr = ptr;
        ptr = nullptr;
        return tmp_ptr;
    }

    void reset(T* p = nullptr) noexcept
    {
        if (p != ptr)
        {
            delete ptr;
            ptr = p;
        }
    }

    T* get() const noexcept
    {
        return ptr;
    }

    T& operator*() const noexcept
    {
        assert(ptr && "Pointer is invalid");
        return *ptr;
    }

    T* operator->() const noexcept
    {
        assert(ptr && "Pointer is invalid");
        return ptr;
    }

    operator bool() const noexcept
    {
        return ptr != nullptr;
    }
};

int main()
{
    // Test structure for testing
    struct Vector2d
    {
        double x, y;
    };

    UniquePtr<Vector2d> ptr1(new Vector2d());
    std::cout << "\nptr1: x = " << ptr1->x << ", y = " << ptr1->y << std::endl;

    UniquePtr<Vector2d> ptr2(std::move(ptr1));
    std::cout << "\nptr1: " << ptr1.get() << "\nptr2: x = " << ptr2->x << ", y = " << ptr2->y << std::endl;

    return 0;
}