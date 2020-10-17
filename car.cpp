#include "car.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Объявление методов и конструкторов класса Car (записи об автомобилях)                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Car::descriptor = 0;                               //инициализация статической переменной



//                         Реализация вынесенного конструктора по умолчанию                               //
Car::Car(){
    yearOfIssue = 0;            
    mileage = 0;                
    price = 0;                  
    descriptor++;                                               //при создании объекта увеличиваем счетчик дескриптора
    ID = descriptor;                                            //в поле ID записываем значение дескриптора
}


//                           Метод SetInfo для заполнения полей объекта класса                           //
void Car::SetInfo(){
    char Mark[256]; 
    char Manufacturer[256];
    char Year[11];            
    char Mileage[11];                
    char Price[10]; 


    cout << "---------------------------------------------- Автомобиль №" << ID << " ----------------------------------------------" << endl;

    cout << " Введите марку: ";                                 //ввод марки автомобиля 
    cin.get(Mark,256);
    mark = Mark;
    cin.ignore(256, '\n');


 
    cout << " Введите изготовителя: ";                          //ввод марки автомобиля
    cin.get(Manufacturer,256);
    manufacturer = Manufacturer;
    cin.ignore(256, '\n');



    while(true){
       cout << " Введите год выпуска: ";                        //ввод года выпуска с проверкой на корректность
       cin >> Year;
            if(cin.good() && CheckInputNumbers(Year)  && (atoi(Year) > 1900 && atoi(Year) < 2021)){
                yearOfIssue = atoi(Year);
                cin.ignore(10, '\n');
                break;
            }
        cin.clear();
        cerr << red << endl << "\t\tГод введен неверно!" << reset << endl;
        cin.ignore(10, '\n');
    }


    while(true){
       cout << " Введите пробег(только целое кол-во км): ";     //ввод года выпуска с проверкой на корректность
       cin >> Mileage;
            if(cin.good() && CheckInputNumbers(Mileage) && atoi(Mileage) >= 0){
                mileage = atoi(Mileage);
                cin.ignore(10, '\n');
                break;
            }
        cin.clear();
        cerr << red << endl << "\t\tПробег введен неверно!" << reset << endl;
        cin.ignore(10, '\n');
    }


    while(true){
        cout << " Введите цену (в рублях без копеек): ";        //ввод стоимости автомобиля с проверкой на корректность
        cin >> Price;
            if(cin.good() && CheckInputNumbers(Price) && atoi(Price) > 0){
                price = atoi(Price);
                cin.ignore(10, '\n');
                break;
            }
          cin.clear();
          cerr << red << endl << "\t\tЦена введена неверное!" << reset << endl;
          cin.ignore(10, '\n');
    }
}



//                  Метод PrintInfoConsole для вывода инф-ии об объекта класса в консоль                  //
void Car::PrintInfoConsole(){
    cout << "-------------------------------------------------------- Автомобиль №" << ID << " ------------------------------------------------------------------------------------------" << std::endl;
    cout << "| \tМарка: " << MyString_stat::alignLinesOfMyStr(mark, 15); 
    cout << "| \tГод выпуска:  " << yearOfIssue << "  "; 
    cout << "| \tПробег(км): " << std::setw(8) << mileage <<"  "; 
    cout << "| \tИзготовитель: " << MyString_stat::alignLinesOfMyStr(manufacturer,15); 
    cout << "| \tЦена: " << std::setw(8) << price; 
    cout << "| \tID: " << std::setw(3) << ID << " | " << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//               Функции которые не являются атрибутами класса, но работают с его объектами               //



//                      Функция для записи инф-ии об объекте класса в бинарный файл                      //
void PrintInfoToFile(Car *car, size_t sizeOfarray, std::ofstream &file){
     for(int i=0; i < sizeOfarray; i++){
         file.write(reinterpret_cast<char*>(&car), sizeof(*car)); 
     }
};



//                  Функция чтения и вывода инф-ии обо всех объектах из бинарного файла                   //
void GetInfoFromFile(Car &car, std::ifstream &file){

    file.seekg(0, std::ios::end);
    int endposition = file.tellg();
    int counter = endposition / sizeof(car);
    if(counter == 0){
        cout << red << endl << "\t\t\t\tЧитаемый файл пуст!!!" << reset << endl;
        cout << red << "======================     Досрочное завершение программы...     ======================" << reset << endl << endl; 
        exit(1);
    }
     
    PrintLogotip();
    PrintHat(4, 12);

    cout << " \tЕсли во время вывода таблица " << magenta << "\"съехала\"" << reset << ", то перезаполните таблицу согласно её размерам." << reset << endl << endl;
    cout << endl << "\t\t\tВсего автомобилей в таблице: " << magenta << counter << reset << endl << endl;

    
    int position;


    for(int i=0; i < counter; i++){
        position = (i)*sizeof(car);
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&car), sizeof(car));
        car.PrintInfoConsole();
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}



//            Функция чтения и вывода инф-ии об определенном кол-ве объектов из бинарного файла           //
void GetInfoFromFile(Car &car, std::ifstream &file, int numberOfObj){

    file.seekg(0, std::ios::end);
    int endposition = file.tellg();
    int counter = endposition / sizeof(car);
    if(counter == 0){
        cout << red << endl << "\t\t\t\tЧитаемый файл пуст!!!" << reset << endl;
        cout << red << "======================     Досрочное завершение программы...     ======================" << reset << endl << endl; 
        exit(1);
    }
     

    if(numberOfObj > counter){
        cout << red << endl << "\t\t\tВ файле нет указанного кол-ва пунктов!" << reset << endl;
        cout << "\t\t\t       Кол-во пунктов в файле: " << counter << endl;
        cout << red << "========================     Досрочное завершение программы...     ========================" << reset << endl << endl; 
        exit(2);
    }

    if(numberOfObj < 1){
        cout << red << "\t\t\tВведено неверное кол-во пунктов для чтения!" << reset << endl << endl;
        cout << flicker << red << "========================     Досрочное завершение программы...     ========================"<< reset << endl << endl; 
        exit(2);
    }

    PrintLogotip();
    PrintHat(4, 12);

    cout << "  Если во время вывода таблица " << magenta << "\"съехала\"" << red << ", то перезаполните таблицу её размерсноти согласно размерам." << reset << endl << endl;
    cout << endl << "\t\t\tВсего автомобилей в таблице: " << magenta << counter << reset << endl << endl;



    int position;

    for(int i=0; i < numberOfObj; i++){
        position = (i)*sizeof(car);
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&car), sizeof(car));
        car.PrintInfoConsole();
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////








 