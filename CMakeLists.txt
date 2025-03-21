cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# Cryptography
add_executable (CaesarCipher ./Cryptography/CaesarCipher.cpp)
#add_executable (iHhx ./Cryptography/iHhx.cpp)
set_target_properties (CaesarCipher PROPERTIES FOLDER "Cryptography")

# DataStructures
add_executable (CircularBuffer ./DataStructures/CircularBuffer.cpp)
set_target_properties (CircularBuffer PROPERTIES FOLDER "DataStructures")

# Others
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (RotateMatrix ./Others/RotateMatrix.cpp)
set_target_properties (Fibonacci RotateMatrix PROPERTIES FOLDER "Others")

# Search
add_executable (BinarySearch ./Search/BinarySearch.cpp)
add_executable (LinearSearch ./Search/LinearSearch.cpp)
set_target_properties (BinarySearch LinearSearch PROPERTIES FOLDER "Search")

# Sorting
add_executable (MoveElementsToLeftOrRight ./Sorting/MoveElementsToLeftOrRight.cpp)
set_target_properties (MoveElementsToLeftOrRight PROPERTIES FOLDER "Sorting")