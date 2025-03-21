cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# DataStructures
add_executable (CircularBuffer ./DataStructures/CircularBuffer.cpp)
set_target_properties (CircularBuffer PROPERTIES FOLDER "Others")

# Others
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (MoveElementsToLeftOrRight ./Others/MoveElementsToLeftOrRight.cpp)
add_executable (RotateMatrix ./Others/RotateMatrix.cpp)
set_target_properties (Fibonacci MoveElementsToLeftOrRight RotateMatrix PROPERTIES FOLDER "Others")