cmake_minimum_required(VERSION 3.27)

project (Algorithms)

set (CMAKE_CXX_STANDARD 17)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# Others
add_executable (Fibonacci ./Others/Fibonacci.cpp)
add_executable (MoveElementsToLeftOrRight ./Others/MoveElementsToLeftOrRight.cpp)
set_target_properties (Fibonacci MoveElementsToLeftOrRight PROPERTIES FOLDER "Others")