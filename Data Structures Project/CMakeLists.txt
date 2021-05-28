cmake_minimum_required(VERSION 3.19)
project(Data_Structures_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures_Project
        main.cpp
        UnsortedArray.cpp
        UnsortedArray.h
        Cell.cpp
        Cell.h
        SortedArray.cpp
        SortedArray.h
        OpenAddressHashTable.cpp
        OpenAddressHashTable.h
        AVLTree.cpp
        AVLTree.h
        BinarySearchTree.cpp
        BinarySearchTree.h
        )