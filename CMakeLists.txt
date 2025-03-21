cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# Cryptography
add_executable (CaesarCipher ./Cryptography/CaesarCipher.cpp)
set_target_properties (CaesarCipher PROPERTIES FOLDER "Others")

# DataStructures
add_executable (CircularBuffer ./DataStructures/CircularBuffer.cpp)
set_target_properties (CircularBuffer PROPERTIES FOLDER "Others")

# Others
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (RotateMatrix ./Others/RotateMatrix.cpp)
set_target_properties (Fibonacci RotateMatrix PROPERTIES FOLDER "Others")

# Search
add_executable (BinarySearch ./Search/BinarySearch.cpp)
set_target_properties (BinarySearch PROPERTIES FOLDER "Others")

# Sorting
add_executable (MoveElementsToLeftOrRight ./Sorting/MoveElementsToLeftOrRight.cpp)
set_target_properties (MoveElementsToLeftOrRight PROPERTIES FOLDER "Others")