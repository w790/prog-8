cmake_minimum_required(VERSION 3.10)
project(my_app)

# Добавляем все исходные файлы
add_executable(my_app 
    main.cpp 
    func1.cpp
)

# Указываем компилятору где искать заголовки
target_include_directories(my_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)