#include <iostream>
#include <fstream>
#include <openssl/sha.h>  // Для функций SHA256 из OpenSSL
#include <opencv2/opencv.hpp> // Для работы с изображениями через OpenCV

std::string calculate(const cv::Mat image){ //функция для подсчета хэша изображения
    unsigned char h[SHA256_DIGEST_LENGTH]; //создание массива для хранения бинарного хэша размером SHA256_DIGEST_LENGTH
    SHA256(image.data, image.total() * image.elemSize(), h); //Вычисление хэша с помощью Openssl.
    /*Image.data - указатель на пиксели изображения
      image.total() * image.elemSize() - общий размер данных в байтах, image.total() - кол-во пикселей, image.elemSize() - общий размер данных в байтах
      h - массив для записи хэша
      */

    std::string res;
    const char* hex = "0123456789abcdef";
    for(int i = 0; i<SHA256_DIGEST_LENGTH; ++i){ //цикл по всем 32 байтам хэша
        unsigned char byte = h[i]; //текущий байт хэша
        res += hex[(byte >> 4) & 0xF]; //сдвиг вправо на 4 бита, получение соответствующего сивмола HEX
        res += hex[byte & 0xF]; //преобразование младшего полубайта
    }
    return res;
}