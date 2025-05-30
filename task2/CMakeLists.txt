cmake_minimum_required(VERSION 3.10)
project(my_app2)

# Добавляем все исходные файлы
add_executable(my_app2 
    main.cpp 
    func2.cpp
)

# Указываем компилятору где искать заголовки
target_include_directories(my_app2 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)