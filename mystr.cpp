#include "mystr.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Файл реализации библиотеки mystr                                    //
//                                        Лабораторной работы №4                                          //
//                                              Вариант №12                                               //
//                                  Разработчик: студент группы 19-ИВТ-3                                  //
//                                         Сапожников Владислав                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////
///            Реализация методов и конструкторов класса TCharArray(динамическая строка)                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                 Конструктор по умолчанию TCharArray                                    //
TCharArray::TCharArray():str(nullptr), SIZE(0){};



//                                         Деструктор TCharArray                                          //
TCharArray::~TCharArray(){ 
    if(this->str != nullptr){
        delete[] this->str;
        str = nullptr;
    }
}    



//                           метод at - безопасный доступ к элементу массива                             //
char& TCharArray::at(int i){
    if(this->str == nullptr){
        cerr << endl << red << " Ошибочный индекс: " << i  << "! Выход за пределы массива!!!" << endl;
        cerr << " Данная строка нулевой длины и не содержит символов!" << endl;
        cerr << " Исправте ошибку и попробуйте еще раз!" << reset << endl << endl;
        exit(1);  
    }
    if(i<0 || i>= SIZE){
        cerr << red << endl << "Ошибочный индекс: "  << i << "! Выход за пределы массива!!!" << endl;
        cout << "Исправте ошибку и попробуйте еще раз!" << reset << endl << endl;
        exit(1);
    }
    return str[i];
}



//                      перегруженный оператор[], тоже с проверкой на безопасность                       //
char& TCharArray::operator[](int i){
     if(this->str == nullptr){
        cerr << endl << red << " Ошибочный индекс: " << i  << "! Выход за пределы массива!!!" << endl;
        cerr << " Данная строка нулевой длины и не содержит символов!" << endl;
        cerr << " Исправте ошибку и попробуйте еще раз!" << reset << endl << endl;
        exit(1);  
     }
     if(i<0 || i>= SIZE){
        cerr << red << endl << "Ошибочный индекс: "  << i << "! Выход за пределы массива!!!" << endl;
        cout << "Исправте ошибку и попробуйте еще раз!" << reset << endl << endl;
        exit(1);
     }

     return str[i];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////
///            Реализация методов и конструкторов класса MyString (динамическая строка)                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                  Конструктор по умолчанию MyString                                     //
MyString::MyString():TCharArray(){}; 



//                                Оператор тождественно равно MyString                                    //
bool MyString::operator == (MyString &OtherStr) const {
    if(this->SIZE != OtherStr.SIZE){
        return  false;
    } 
    for(int i = 0; i < this->SIZE; i++){
        if(this->str[i] != OtherStr.str[i]){
            return false;
        }
    }
    return true;
};



//                             Оператор тождественно не равно MyString                                  //
bool MyString::operator != (MyString &OtherStr) const {   
    if(this->SIZE != OtherStr.SIZE){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] != OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                    Оператор меньше MyString                                         //
bool MyString::operator < (MyString &OtherStr) const {    
    if(this->SIZE < OtherStr.SIZE){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] < OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                    Оператор больше MyString                                         //
bool MyString::operator > (MyString &OtherStr) const {
    if(strlen(this->str) > strlen(OtherStr.str)){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] > OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                   конкатенация строк MyString                                        //
MyString MyString::operator + (MyString &OtherStr) {
    MyString newStr;

    unsigned int len1 = strlen(this->str);
    unsigned int len2 = strlen(OtherStr.str);
    SIZE = len1+len2;

    newStr.str = new char[SIZE+1];

    int i=0;

    for(       ; i < len1; i++){
        newStr.str[i] = this->str[i];
    }
    for(int j=0; j < len2; i++, j++){
        newStr.str[i] = OtherStr.str[j];
    }
    newStr.str[SIZE] = '\0';
    return newStr;
}



//                                   оператор присваивания MyString                                       //
MyString& MyString::operator =(const char* otherStr){
    if(str != nullptr){
        delete[] this->str;
    }

    SIZE = strlen(otherStr);
    this->str = new char [SIZE+1];

    for(int i = 0; i < SIZE; i++){
        this->str[i] = otherStr[i];
    }

    this->str[SIZE] = '\0';

    return *this;
}



//                                   оператор присваивания MyString                                       //
MyString& MyString::operator =(const MyString& otherStr){
    if(str != nullptr){
        delete[] this->str;
    }

    SIZE = strlen(otherStr.str);
    this->str = new char [SIZE+1];

    for(int i = 0; i < SIZE; i++){
        this->str[i] = otherStr.str[i];
    }
    
    this->str[SIZE] = '\0';
    return *this;
}



//                              Дружественный метод вывода MyString                                      //
std::ostream& operator << (std::ostream& os, const MyString& OtherStr){
    int allStr = strlen(OtherStr.str);
    for(int i = 0; i < allStr; i++){            
            os  << OtherStr.str[i];
        }
    return os;
}; 
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////
///         Реализация методов и конструкторов класса TCharArray_stat(статическая строка)                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                               Конструктор по умолчанию TCharArray_stat                                 //
TCharArray_stat::TCharArray_stat(){
    strcpy(str,"");
    SIZE = strlen(this->str);
};



//                                               метод at()                                               //
char& TCharArray_stat::at(int i){
    if(i<0 || i>= SIZE){
        cerr << red << endl << "Ошибочный индекс: "  << i << "! Выход за пределы массива!!!" << endl;
        cout << "Исправте ошибку и попробуйте еще раз!" << reset << endl << endl;
        exit(1);
    }
    return str[i];
}



//                      перегруженный оператор[], тоже с проверкой на безопасность                       //
char& TCharArray_stat::operator[](int i){
     if(i<0 || i>= SIZE){
         std::cout << std::endl << " Ошибочный индекс: " << i << "! Выход за пределы массива!!!" << std::endl;
         std::cout << " Исправте ошибку и попробуйте еще раз!" << std::endl << std::endl;
         exit(1);
     }

     return str[i];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//           Реализация методов и конструкторов класса MyString_stat(статическая строка)                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////



//                                Конструктор по умолчанию MyString_stat                                  //
MyString_stat::MyString_stat():TCharArray_stat(){}; 



//                                 оператор присваивания MyString_stat                                    //
MyString_stat& MyString_stat::operator =(const char* otherStr){
    strcpy(this->str, otherStr);
    return *this;
}



//                            Дружественный метод вывода MyString_stat                                    //
std::ostream& operator << (std::ostream& os, const MyString_stat& OtherStr){
    int allStr = strlen(OtherStr.str);
    for(int i = 0; i < allStr; i++){            
            os  << OtherStr.str[i];
        }
    return os;
}; 



//                             Оператор тождественно равно MyString_stat                                  //
bool MyString_stat::operator == (MyString_stat &OtherStr) const {
    if(this->SIZE != OtherStr.SIZE){
        return  false;
    } 
    for(int i = 0; i < this->SIZE; i++){
        if(this->str[i] != OtherStr.str[i]){
            return false;
        }
    }
    return true;
};



//                          Оператор тождественно не равно MyString_stat                                //
bool MyString_stat::operator != (MyString_stat &OtherStr) const {   
    if(this->SIZE != OtherStr.SIZE){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] != OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                 Оператор меньше MyString_stat                                       //
bool MyString_stat::operator < (MyString_stat &OtherStr) const {    
    if(this->SIZE < OtherStr.SIZE){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] < OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                 Оператор больше MyString_stat                                       //
bool MyString_stat::operator > (MyString_stat &OtherStr) const {
    if(strlen(this->str) > strlen(OtherStr.str)){
        return true;
    } 
    for(int i=0; i < this->SIZE; i++){
        if(this->str[i] > OtherStr.str[i]){
            return true;
        }
    }
    return false;
};



//                                 Функция проверки класса MyString_stat                                // 
void MyString_check(){
        char buff[256];

        cout << endl << "\tКласс MyString - динамическая строка char" << endl;

        cout << endl << red << "Warning!!!" << reset << " рекомендуемый язык для ввода: " << yellow << "English" << reset << endl << endl;

        cout << "Введите содержимое 1ой строки: "; 
        cin.get(buff,256);
        cin.ignore(256, '\n');
        MyString str1; 
        str1 = buff;

        cout << "Введите содержимое 2ой строки: "; 
        cin.get(buff,256);
        cin.ignore(256, '\n');
        MyString str2;
        str2 = buff;

        cout << "1ая строка: " << endl << "  " << str1 << endl << endl;
        cout << "2ая строка: " << endl << "  " << str2 << endl << endl;

        cout << "Выберите оператор для проверки: " << std::endl;
        cout << "\t1 - \"==\"" << std::endl;
        cout << "\t2 - \"!=\"" << std::endl;
        cout << "\t3 - \">\"" << std::endl;
        cout << "\t4 - \"<\"" << std::endl;
        cout << "\t5 - \"+\"" << std::endl;
        cout << "\t6 - \"at()\"" << std::endl;
        cout << "\t7 - \"[]\"" << std::endl;
        cout << "Ваш выбор: ";

       int answer;

       std::cin >> answer;

       switch(answer){
        case 1:{
            if(str1 == str2){
                std::cout <<" строка №1 равна строке №2" << std::endl;
            }
            else{
                std::cout <<" строка №1 не равна строке №2" << std::endl;
            }
            break;
        }

        case 2:{
            if(str1 != str2){
                std::cout <<" строка №1 не равна строке №2" << std::endl;
            }
            else{
                std::cout <<" строка №1 равна строке №2" << std::endl;
            }
            break;
        }

        case 3:{
            if(str1 > str2){
                std::cout <<" строка №1 больше строки №2" << std::endl;
            }
            else{
                std::cout <<" строка №1 не больше строки №2" << std::endl;
            }
            break;            
        }
        case 4:{
            if(str1 < str2){
                std::cout <<" строка №1 меньше строки №2" << std::endl;
            }
            else{
                std::cout <<" строка №1 не меньше строки №2" << std::endl;
            }
            break;              
        }
        case 5:{
            MyString str3;
            str3 = str1 + str2;
            std::cout << " Результирующая строка:" << std::endl;
            std::cout << str3 << std::endl;
            break;
        }
        case 6:{
            std::cout << " Выберите номер строки с которой хотите работать: ";
            int m; std::cin >> m;
            if(m < 1 || m > 2 ){
                cerr << red << "Выбрана неверная строка!" << reset << endl;
                exit(0);
            }
            switch (m)
            {
            case 1:{
                std::cout << " Введите номер элемента к которому хотите получить доступ(начало отсчета индексов с 1): " << std::endl;
                int n;
                std::cin >> n;
                n -= 1;
                std::cout << "Выбранный элемент: "  << str1.at(n) << std::endl;
                break;
            }
            case 2:{
                std::cout << " Введите номер элемента к которому хотите получить доступ(начало отсчета индексов с 1): " << std::endl;
                int n;
                std::cin >> n;
                n -= 1;
                std::cout << "Выбранный элемент: "  << str2.at(n) << std::endl;
                break;
            }

            }
            break;
        }

        case 7:{
            std::cout << " Выберите номер строки с которой хотите работать: ";
            int m; std::cin >> m;
            if(m < 1 || m > 2 ){
                cerr << red << "Выбрана неверная строка!" << reset << endl;
                exit(0);
            }
            switch (m)
            {
            case 1:{
                std::cout << " Введите номер элемента к которому хотите получить доступ(начало отсчета индексов с 1): " << std::endl;
                int n;
                std::cin >> n;
                n -= 1;
                std::cout << "Выбранный элемент: "  << str1[n] << std::endl;
                break;
            }
            case 2:{
                std::cout << " Введите номер элемента к которому хотите получить доступ(начало отсчета индексов с 1): " << std::endl;
                int n;
                std::cin >> n;
                n -= 1;
                std::cout << "Выбранный элемент: "  << str2[n] << std::endl;
                break;
            }

            }
            break;
        }
    }
} 



//                        статическая функция для выравнивания строк MyString_stat                        //
std::string MyString_stat::alignLinesOfMyStr(MyString_stat &Mystr, int width){
    std::string str = Mystr.str;

    int len = str.length();
    if(len > width){return str;};

    int diff = width -len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;

    return std::string(pad1,' ') + str + std::string(pad2,' ');   
};