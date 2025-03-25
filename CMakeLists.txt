cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# Cryptography
add_executable (CaesarCipher ./Cryptography/CaesarCipher.cpp)
add_executable (CryptoRandom ./Cryptography/CryptoRandom.cpp)
add_executable (Hex ./Cryptography/Hex.cpp)
add_executable (RC4 ./Cryptography/RC4.cpp)
set_target_properties (CaesarCipher CryptoRandom Hex RC4 PROPERTIES FOLDER "Cryptography")

# DataStructures
add_executable (CircularBuffer ./DataStructures/CircularBuffer.cpp)
set_target_properties (CircularBuffer PROPERTIES FOLDER "DataStructures")

# Others
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (ReversalForwardList ./Others/ReversalForwardList.cpp)
add_executable (RotateMatrix ./Others/RotateMatrix.cpp)
set_target_properties (Fibonacci ReversalForwardList RotateMatrix PROPERTIES FOLDER "Others")

# Search
add_executable (BinarySearch ./Search/BinarySearch.cpp)
add_executable (LinearSearch ./Search/LinearSearch.cpp)
add_executable (TernarySearch ./Search/TernarySearch.cpp)
set_target_properties (BinarySearch LinearSearch TernarySearch PROPERTIES FOLDER "Search")

# SmartPtr
add_executable (UniquePtr ./SmartPtr/UniquePtr.cpp)
set_target_properties (UniquePtr PROPERTIES FOLDER "SmartPtr")

# Sorting
add_executable (CountingSort ./Sorting/CountingSort.cpp)
add_executable (MoveElementsToLeftOrRight ./Sorting/MoveElementsToLeftOrRight.cpp)
set_target_properties (CountingSort MoveElementsToLeftOrRight PROPERTIES FOLDER "Sorting")

# Templates
add_executable (NumberToString ./Templates/NumberToString.cpp)
set_target_properties (NumberToString PROPERTIES FOLDER "Templates")