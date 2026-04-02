cmake_minimum_required(VERSION 4.1)
project(ds_linked_list)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

#Ejecutable principal
add_executable(ds_linked_list
        src/main.cpp
        src/Node.cpp
        src/LinkedList.cpp
        include/StackComposicion.h
        src/StackComposicion.cpp
        include/QueueComposicion.h
        src/QueueComposicion.cpp
)

# Google Test
find_package(GTest REQUIRED)



# Ejecutable de tests
add_executable(ds_linked_list_test
        test/NodeTest.cpp
        src/Node.cpp
        src/LinkedList.cpp
        test/LinkedListTest.cpp
        src/StackComposicion.cpp
        test/StackComposicionTest.cpp
        src/QueueComposicion.cpp
        test/QueueComposicionTest.cpp
)

#target_include_directories(ds_linked_list_test PRIVATE include)
target_link_libraries(ds_linked_list_test GTest::gtest GTest::gtest_main)