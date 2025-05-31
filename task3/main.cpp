#include <iostream>       
#include <fstream>        
#include <openssl/sha.h>  // Для функций SHA256 из OpenSSL
#include <opencv2/opencv.hpp> // Для работы с изображениями через OpenCV
#include "func3.h"

int main(){

    cv::Mat image = cv::imread("pythonc.jpg"); //загрузка изображения

    std::string hsh1 = calculate(image); //вычисление хэша изображения

    cv::Mat image2 = image.clone(); //копия для изменения пикселя
    cv::Vec3b& pixel = image2.at<cv::Vec3b>(0, 0); //Получение ссылки на пиксель
    pixel[0] += 1; //увеличение синего канала на 1

    std::string hsh2 = calculate(image2); //хэш 2 изображения

    bool eq = (hsh1 == hsh2); //сравнение хэшей

    std::cout << "Orig:    " << hsh1 << std::endl;
    std::cout << "After changing:    " << hsh2 << std::endl;
    if(eq) std::cout << "equal";
    else std::cout << "not equal";

    std::ofstream file("task3.txt");
    file << "Orig:   " << hsh1 << std::endl;
    file << "After changing:   " << hsh2 << std::endl;
    if(eq) file << "equal";
    else file << "not equal";
    file.close();


    return 0;
}