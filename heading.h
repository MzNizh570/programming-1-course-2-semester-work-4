#pragma once



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       Подключенные библиотеки                                          //
#include <iostream>                                     //ввод/вывод
#include <cstring>                                      //strlen(),strcpy()
#include <fstream>                                      //работа с файловыми потоками
#include <iomanip>                                      //форматирование вывода
#include <cstdlib>                                      //exit(), atoi()
#include <string>                                       //строки string для функции выравнивания вывода в таблицу
                                  


using std::cin;
using std::cout;
using std::endl;
using std::cerr;



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                               переменные для смены цвета текста в консоли                              //
const std::string red("\x1B[0;31m");
const std::string yellow("\x1B[1;33m");
const std::string cyan("\x1B[0;36m");
const std::string magenta("\x1B[0;35m");
const std::string reset("\x1B[0m");
const std::string flicker("\x1B[0;5m");



//                        Функция проверки массива char на содержание только цифр                         //
int CheckInputNumbers(char *str); 



//                            Функции для получения кол-ва пунктов таблицы                                //
int GetQuantityOfPoints();                
int GetQuantityOfPoints(char *argv);      



//                           Функции для проверки открытия файлового потока                               //
void CheckFile(std::ofstream &file);       
void CheckFile(std::ifstream &file);



//                                       Функции для оформления                                           //
void PrintLogotip();                                                   //Функция вывода логотипа
void PrintHat(const int jubNumber, const int optionNumber);            //функция вывода шапки
void PrintShortreferens();                                             //функция вывода краткой справки
void PrintFullReferens(const double release, const double update);     //функция вывода полной справки
void PrintErrorFlag();                                                 //функция для вывода предупреждения при задании неверного флага при запуске
void PrintWarning();                                                   //функция для вывода предупреждения во время записи

