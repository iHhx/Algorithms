cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# Allocators
add_executable (LinearAllocator ./Allocators/LinearAllocator.cpp)
add_executable (StandardAllocator ./Allocators/StandardAllocator.cpp)
set_target_properties (LinearAllocator StandardAllocator PROPERTIES FOLDER "Allocators")

# Cryptography
add_executable (CaesarCipher ./Cryptography/CaesarCipher.cpp)
add_executable (CryptoRandom ./Cryptography/CryptoRandom.cpp)
add_executable (Hex ./Cryptography/Hex.cpp)
add_executable (RC4Cipher ./Cryptography/RC4.cpp)
set_target_properties (CaesarCipher CryptoRandom Hex RC4Cipher PROPERTIES FOLDER "Cryptography")

# DataStructures
add_executable (CircularBuffer ./DataStructures/CircularBuffer.cpp)
add_executable (LinkedList ./DataStructures/LinkedList.cpp)
add_executable (XORLinkedList ./DataStructures/XORLinkedList.cpp)
set_target_properties (CircularBuffer LinkedList XORLinkedList PROPERTIES FOLDER "DataStructures")

# Others 
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (ReversalForwardList ./Others/ReversalForwardList.cpp)
add_executable (ReverseMatrixDiagonals ./Others/ReverseMatrixDiagonals.cpp)
add_executable (RotateMatrix ./Others/RotateMatrix.cpp)
set_target_properties (Fibonacci ReversalForwardList ReverseMatrixDiagonals RotateMatrix PROPERTIES FOLDER "Others")

# Search
add_executable (BinarySearch ./Search/BinarySearch.cpp)
add_executable (LinearSearch ./Search/LinearSearch.cpp)
add_executable (TernarySearch ./Search/TernarySearch.cpp)
set_target_properties (BinarySearch LinearSearch TernarySearch PROPERTIES FOLDER "Search")

# SetOperations
add_executable (DifferenceBetweenOrderedSets ./SetOperations/DifferenceBetweenOrderedSets.cpp)
add_executable (GenerationOfAllPermutationsFromSet ./SetOperations/GenerationOfAllPermutationsFromSet.cpp)
add_executable (GenerationOfAllSubsetsOfTheSet ./SetOperations/GenerationOfAllSubsetsOfTheSet.cpp)
add_executable (IntersectionOfTheOrderedSets ./SetOperations/IntersectionOfTheOrderedSets.cpp)
add_executable (SymmetricDifferenceOfOrderedSets ./SetOperations/SymmetricDifferenceOfOrderedSets.cpp)
add_executable (UnionOfTheOrderedSets ./SetOperations/UnionOfTheOrderedSets.cpp)
add_executable (UnionOfTheOrderedSetsWD ./SetOperations/UnionOfTheOrderedSetsWD.cpp)
set_target_properties (DifferenceBetweenOrderedSets GenerationOfAllPermutationsFromSet GenerationOfAllSubsetsOfTheSet IntersectionOfTheOrderedSets SymmetricDifferenceOfOrderedSets UnionOfTheOrderedSets UnionOfTheOrderedSetsWD PROPERTIES FOLDER "SetOperations")

# SmartPtr
add_executable (UniquePtr ./SmartPtr/UniquePtr.cpp)
add_executable (SharedPtr ./SmartPtr/SharedPtr.cpp)
set_target_properties (SharedPtr UniquePtr PROPERTIES FOLDER "SmartPtr")

# Sorting
add_executable (BubbleSorting ./Sorting/BubbleSorting.cpp)
add_executable (BucketSorting ./Sorting/BucketSorting.cpp)
add_executable (CountingSort ./Sorting/CountingSort.cpp)
add_executable (InsertionSorting ./Sorting/InsertionSorting.cpp)
add_executable (MergeSorting ./Sorting/MergeSorting.cpp)
add_executable (MoveElementsToLeftOrRight ./Sorting/MoveElementsToLeftOrRight.cpp)
add_executable (QuickSorting ./Sorting/QuickSorting.cpp)
add_executable (SelectionSorting ./Sorting/SelectionSorting.cpp)
add_executable (ShellSorting ./Sorting/ShellSorting.cpp)
add_executable (StupidSorting ./Sorting/StupidSorting.cpp)
set_target_properties (BubbleSorting BucketSorting CountingSort InsertionSorting MergeSorting MoveElementsToLeftOrRight QuickSorting SelectionSorting ShellSorting StupidSorting PROPERTIES FOLDER "Sorting")

# Templates
add_executable (CopyString ./Templates/CopyString.cpp)
add_executable (NumberToString32Bits ./Templates/NumberToString32Bits.cpp)
set_target_properties (CopyString NumberToString32Bits PROPERTIES FOLDER "Templates")