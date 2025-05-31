cmake_minimum_required(VERSION 3.10)
project(my_app3)

# Находим OpenCV
find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)
# Добавляем все исходные файлы
add_executable(my_app3 
    main.cpp 
    func3.cpp
)

# Указываем компилятору где искать заголовки
target_include_directories(my_app3 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    
)

# Связываем с библиотеками OpenCV
target_link_libraries(my_app3 PRIVATE 
    ${OpenCV_LIBS}
    ${OPENSSL_CRYPTO_LIBRARY}
)