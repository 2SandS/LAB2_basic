#include "terminal.h"
using namespace std;

int main() {
    Class1::Terminal sample, paramSource;
    int option;
    bool exitFlag = false;
    try
    {
        while (!exitFlag)
        {
            cout << "\n1)creation of an instance of a class with initialization by terminal type, number connections and signal status\n";
            cout << "2)create an instance of the class with initialization only by terminal type (without compounds)\n";
            cout << "3)create an instance of the class with user's input\n";
            cout << "4)(++) 1 more connections\n";
            cout << "5)(--) 1 less connections\n";
            cout << "6)(>>) connection of output terminal and input (the state is transmitted from output terminals to the input terminal)\n";
            cout << "7)disconnection of the output terminal and the input terminal (it is assumed that the terminals were connected)" << endl;
            cout << "8)exit" << endl;

            try
            {
                cin >> option;
                if (cin.fail()) {
                    cin.clear();  
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                    throw std::invalid_argument("Invalid input. Please enter a valid option.");
                }
                switch (option)
                {
                case 1:
                {
                    paramSource;
                    sample = Class1::Terminal(paramSource.getIsInput(), paramSource.getConnectionCount(), paramSource.getSignalState());
                    cout << sample;
                    break;
                }
                
                case 2:
                {
                    sample = Class1::Terminal(paramSource.getIsInput());
                    cout << sample;
                    break;
                }
                
                case 3:
                {
                    try
                    {
                        // Проверка на успешность ввода
                        if (!(cin >> sample)) {
                            throw invalid_argument("Invalid input. Please enter valid parameters.");
                        }

                        cout << sample;
                    }
                    catch (const invalid_argument& ex)
                    {
                        cout << ex.what() << endl;
                        cin.clear(); // Сброс флагов ошибок
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
                        continue;
                    }
                    break;
                }
               
                case 4:
                {
                    cout << sample << endl;
                    ++sample; 
                    cout << sample;
                    break;
                }
                
                case 5:
                {
                    cout << sample << endl;
                    --sample; 
                    cout << sample;
                    break;
                }
                
                case 6:
                {
                    Class1::Terminal outputSample(false);
                    Class1::Terminal inputSample(true);
                    cout << inputSample << endl;
                    cout << outputSample << endl;
                    outputSample >> inputSample;
                    cout << inputSample;
                    break;
                }
                case 7:
                {
                    Class1::Terminal outputSample(false);
                    Class1::Terminal inputSample(true);
                    cout << inputSample << endl;
                    cout << outputSample << endl;
                    outputSample >> inputSample;
                    cout << inputSample << endl;
                    outputSample.disconnect(inputSample);
                    cout << inputSample;
                    break;
                }
                

                case 8: {
                    exitFlag = true;
                    break;
                }

                default:
                    cout << "Error: choose 1-8" << endl;
                    break;
                }
            }


            catch (const invalid_argument)
            {
                cout << "Invalid argument, try again" << endl;
                continue;
            }

        }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}