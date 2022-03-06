cmake_minimum_required(VERSION 3.21)
project(LinkedList)

set(TEST test/)

add_executable(${PROJECT_NAME} main.cpp
                                simple.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})

add_executable(${PROJECT_NAME}_test ${TEST}/test_linkedList.cpp
                                    ${TEST}/test_Simple.cpp
                                    LinkedList.cpp
                                    simple.cpp)

target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${CONAN_LIBS})