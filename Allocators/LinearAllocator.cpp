#include <iostream>
#include <stdexcept>

class LinearAllocator
{
public:
    explicit LinearAllocator(const LinearAllocator&) = delete;
    LinearAllocator& operator=(const LinearAllocator&) = delete;
public:
    explicit LinearAllocator(std::size_t memorySize);
    explicit LinearAllocator(LinearAllocator&& obj) noexcept;
    LinearAllocator& operator=(LinearAllocator&& obj) noexcept;
    void* allocate(std::size_t allocatedSize) noexcept;
    void deallocate() noexcept;
   ~LinearAllocator();
private:
    std::size_t mMemorySize = 0;
    std::size_t mMemoryOffset = 0;
    void* mBasePointer = nullptr;
};

LinearAllocator::LinearAllocator(std::size_t memorySize) : mMemorySize(memorySize)
{
    if (mMemorySize == 0)
        throw std::runtime_error("Could not allocate 0 byte of the memory.");

    mBasePointer = malloc(mMemorySize);
    if (!mBasePointer)
        throw std::runtime_error("Memory was not allocated for allocator.");
}

LinearAllocator::LinearAllocator(LinearAllocator&& obj) noexcept
{
    mMemorySize = obj.mMemorySize;
    mMemoryOffset = obj.mMemoryOffset;
    mBasePointer = obj.mBasePointer;
    obj.mBasePointer = nullptr;
    obj.deallocate();
}

LinearAllocator& LinearAllocator::operator=(LinearAllocator&& obj) noexcept
{
    if (this != &obj)
    {
        mMemorySize = obj.mMemorySize;
        mMemoryOffset = obj.mMemoryOffset;
        mBasePointer = obj.mBasePointer;
        obj.mBasePointer = nullptr;
        obj.deallocate();
    }
    return *this;
}

void* LinearAllocator::allocate(std::size_t allocatedSize) noexcept
{
    if (mMemoryOffset + allocatedSize > mMemorySize)
        return nullptr; // Allocator is full

    const std::size_t allocatedAddress = reinterpret_cast<std::size_t>(mBasePointer) + mMemoryOffset;
    mMemoryOffset += allocatedSize;
    return reinterpret_cast<void*>(allocatedAddress);
}

void LinearAllocator::deallocate() noexcept
{
    mMemorySize = 0;
    mMemoryOffset = 0;
}

LinearAllocator::~LinearAllocator()
{
    free(mBasePointer);
}

int main()
{
    // Test structure for checking allocator
    struct Vector3d
    {
        int x, y, z;
    };

    try
    {
        LinearAllocator allocator(sizeof(Vector3d) * 3);
        Vector3d* vector1 = static_cast<Vector3d*>(allocator.allocate(sizeof(Vector3d)));
        Vector3d* vector2 = static_cast<Vector3d*>(allocator.allocate(sizeof(Vector3d)));
        allocator.deallocate();

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error! Cause: " << e.what() << std::endl;

        return EXIT_FAILURE;
    }
}