cmake_minimum_required(VERSION 3.11)

project(SearchTree CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Указываем пути к исходным файлам относительно корня проекта
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Добавляем библиотеку
add_library(_tree SHARED
    ${INCLUDE_DIR}/SearchTree.h
    ${SRC_DIR}/SearchTree.cc
    ${INCLUDE_DIR}/experiment.h
 "include/task.h")
target_include_directories(_tree PUBLIC ${INCLUDE_DIR})

# Добавляем исполняемый файл
add_executable(main ${SRC_DIR}/main.cc "include/task.h")
target_link_libraries(main _tree)
