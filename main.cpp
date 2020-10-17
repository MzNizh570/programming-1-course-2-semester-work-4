#include "car.h" 

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                              клиентский код                                            //
int main (int argc, char* argv[]){  
  switch (argc){

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               2 аргумента                                              //
    case 2:{

      //                                флаг -h/--help для вывода справки                               // 
      if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"--help")) 
      {
        PrintFullReferens(04.05, 04.05); 
        exit(0);
      };



      //                           флаг -strtest для проверки класса MySting                            // 
      if(!strcmp(argv[1],"-strtest")){
        MyString_check();
        break;
      }



      //Если 2 аргумента, но не 1 из флагов не совпал, то выводим сообщение об ошибке и завершаем работу// 
      PrintErrorFlag();
      break;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               3 аргумента                                              //
    case 3:{
      //                          флаг -c для создания записей об автомобилях                           // 
      if (!strcmp(argv[1],"-c")){
        std::ofstream res(argv[2], std::ofstream::binary); //открытие и проверка открытия файлового потока для записи
        CheckFile(res);


        PrintLogotip();
        PrintHat(4, 12);

 
        int numberOfLines = GetQuantityOfPoints();         //Ввод кол-ва пунктов для записи


        Car *arrayOfCar = new Car[numberOfLines];          //создание массива объектов класса и его заполнение 
        PrintWarning();
        for(int i = 0; i < numberOfLines; i++){
          arrayOfCar[i].SetInfo();
          res.write(reinterpret_cast<char*>(&arrayOfCar[i]), sizeof(arrayOfCar[i]));
        }

        cout << endl << "\t\t  Записи успешно сохранены!" << endl;


        delete[] arrayOfCar;                               //освобождение памяти от динамического массива объектов класса      
        res.close();                                       //закрытие файловго потока записи
        cout << endl << red << "\t\tЗавершение работы программы!" << reset << endl;
        break;
      }


      //                             флаг -r для чтения записей из файла                                // 
      if (!strcmp(argv[1],"-r"))
      {
        std::ifstream text(argv[2], std::ifstream::binary);//открытие файла для чтения 
        CheckFile(text);

 
      
        Car car;                                           //чтение и вывод информации через перезапись 1 объекта         
        GetInfoFromFile(car, text); 
      
         
        text.close();                                      //закрытие файлового потока чтения
        cout << endl << red << "\t\tЗавершение работы программы!" << reset << endl;
        break;
      }  
      //Если 3 аргумента, но не 1 из флагов не совпал, то выводим сообщение об ошибке и завершаем работу// 
      PrintErrorFlag(); 
      break; 
    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               4 аргумента                                              //
    case 4:{

      //               флаги -c -n для создания определенного кол-ва записей об автомобилях            //  
      if (!strcmp(argv[1],"-c"))
      {
        int numberOfLines = GetQuantityOfPoints(argv[2]);  //Получение кол-ва пунктов для записи из аргументов запуска

        std::ofstream res(argv[3]);                        //открытие и проверка открытия файлового потока для записи 
        CheckFile(res);

        PrintLogotip();
        PrintHat(4, 12);



        Car *arrayOfCar = new Car[numberOfLines];          //создание массива объектов класса и его заполнение 
        PrintWarning();
        for(int i = 0; i < numberOfLines; i++){
          arrayOfCar[i].SetInfo();
          res.write(reinterpret_cast<char*>(&arrayOfCar[i]), sizeof(arrayOfCar[i]));
        }

        cout << endl << "\t\t  Записи успешно сохранены!" << endl;
 
        res.close();                                       //закрытие файла
        cout << endl << red << "\t\tЗавершение работы программы!" << reset << endl;
        break;
      }

      //                 флаги -r -n для чтениия определенного кол-ва записей из файла                 //  
      if (!strcmp(argv[1],"-r"))
      {
        std::ifstream text(argv[3]);                       //открытие файла для чтения 
        CheckFile(text);


        int numberOfLines = GetQuantityOfPoints(argv[2]);  //Получение кол-ва пунктов для записи из аргументов запуска
          
        Car car;                                           //Чтение и вывод информации из файла через перезапись одного объекта
        GetInfoFromFile(car, text, numberOfLines);
      

        text.close();                                      //закрытие файла
        cout << endl << red << "\t\tЗавершение работы программы!" << reset << endl;
        break;
      }   
      PrintErrorFlag(); 
      break;
    } 

    //Если 4 аргумента, но не 1 из флагов не совпал, то выводим сообщение об ошибке и завершаем работу// 
    default:{        
      PrintShortreferens(); 
      exit(1);
      break;
    }
  }
  return 0;
}
  

    




    
    
