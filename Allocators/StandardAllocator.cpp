#include <iostream>
#include <vector>

template<class T>
class allocator
{
public:
    using value_type = T;
    //
    using pointer = value_type*;
    using const_pointer = typename std::pointer_traits<pointer>::template
                            rebind<value_type const>;
    using void_pointer = typename std::pointer_traits<pointer>::template
                            rebind<void>;
    using const_void_pointer = typename std::pointer_traits<pointer>::template
                            rebind<const void>;
    using difference_type = typename std::pointer_traits<pointer>::difference_type;
    using size_type = std::make_unsigned_t<difference_type>;

    template<class U> struct rebind { typedef allocator<U> other; };

    allocator() noexcept {}

    template<class U> allocator(allocator<U> const&) noexcept {}

    value_type* allocate(std::size_t n, const_void_pointer)
    {
        return allocate(n);
    }

    template<class U, class ...Args>
    void construct(U* p, Args&& ...args)
    {
        ::new(p) U(std::forward<Args>(args)...);
    }
    template<class U>
    void destroy(U* p) noexcept
    {
        p->~U();
    }

    std::size_t max_size() const noexcept
    {
        return std::numeric_limits<size_type>::max();
    }

    allocator select_on_container_copy_construction() const
    {
        return *this;
    }

    using propagate_on_container_copy_assignment = std::false_type;
    using propagate_on_container_move_assignment = std::false_type;
    using propagate_on_container_swap = std::false_type;
    //
    value_type* allocate(std::size_t n)
    {
        std::cout << "Items: " << n << ", allocate: " << n * sizeof(value_type) << " bytes\n";
        return static_cast<value_type*>(::operator new(n * sizeof(value_type)));
    }
    void deallocate(value_type* p, std::size_t n) noexcept
    {
        std::cout << "Deallocate: " << n * sizeof(value_type) << " bytes\n";
        ::operator delete(p);
    }
};

template<class T, class U>
bool operator==(allocator<T> const&, allocator<U> const&) noexcept
{
    return true;
}

int main() {

    std::vector<int, allocator<int>> vec;
    vec.reserve(100);

    return 0;
}