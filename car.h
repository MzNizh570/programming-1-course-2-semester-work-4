#pragma once
#include "mystr.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//               Объявление методов и конструкторов класса Car (записи об автомобилях)                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Car{
 private:
  MyString_stat mark;                             //поле для указания марки - статическая строка библиотеки MyString_stat 
  MyString_stat manufacturer;                     //поле изготовителя       - статическая строка библиотеки MyString_stat
  int yearOfIssue;                                //поле для указания годы выпуска
  int mileage;                                    //поле для пробега
  int price;                                      //поле для цены
  unsigned int ID;                                //поле ID для различения одинаковых авто

 public:
  Car();                                         //конструктор по умолчанию
                                                 //нет смысла описывать деструктор, т. к. все поля объекта класса статические
  static unsigned int descriptor;                //объявим static переменную - дескриптор
 
 

  void SetInfo();                                //метод для заполнения полей объекта
  void PrintInfoConsole(); /* метод для вывода информации об объекте в стандартный поток вывода. Данный метод не вызывается явно в
                              данный метод включен в функции GetInfoFromFile(обе перегрузки), но сам по себе явно нигде не вызывается */
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//             Определение функции не являющимися атрибутами, но работающих с объектами класса            //
void PrintInfoToFile(Car *car, size_t sizeOfarray, std::ofstream &file);    //Определение функции для записи инфомарции массива объектов в файл. 
void GetInfoFromFile(Car &car, std::ifstream &file);                        //Определение функции для считывания инфомарции обо всех объектах из файла. 
void GetInfoFromFile(Car &car, std::ifstream &file, int numberOfObj);       //Определение функции для определенного кол-ва объектов из файла. 