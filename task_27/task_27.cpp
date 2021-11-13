#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
int main()
{
    string fileName = "InputData.txt";
    ifstream file(fileName);
 
    if (!file)
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    cout << "If you want know what this programm do write HELP" << endl;
    cout << endl;
 
    string line;
    int tmp = 0;
    while (!file.eof())
    {
        getline(file, line);
        tmp++;
    }
    file.close();
    ifstream file1(fileName);
    string** matrix = new string * [tmp];
    for (int i = 0; i < tmp; ++i)
    {
        matrix[i] = new string[5];
        for (int j = 0; j < 5; ++j)
        {
            file1 >> matrix[i][j];
        }
    }
    file1.close();
    string request;
    cin >> request;
    if (request == "Help")
    {
        cout << "First command - Existence" << endl;
        cout << "Write - Existence" << endl;
        cout << "Enter the product number of existence you want to know" << endl;
        cout << endl;
        cout << "Second command - Amount" << endl;
        cout << "Write - Amount" << endl;
        cout << "Calcuates the amount of available products" << endl;
        cout << endl;
        cout << "Third command - Register" << endl;
        cout << "Write - Register" << endl;
        cout << "Lists all items with numbers in a given interval" << endl;
        cout << endl;
        cout << "Fourth command - Maximum" << endl;
        cout << "Write - Maximum" << endl;
        cout << "Looking for the highest price" << endl;
        cout << endl;
        cout << "Fifth command - Letter" << endl;
        cout << "Write - Letter" << endl;
        cout << "List of products, the name of which begins with a given letter" << endl;
        cout << endl;
    }
    if (request == "Existence")//По номеру изделия выдать справку о наличии его на складе
    {
        cout << "Input number" << endl;
        string put;
        cin >> put;
        int numberProduct = stoi(put);
        for (int i = 0; i < tmp; i++)
        {
            string str = matrix[i][0];
            const char* c_str = str.c_str();
            if (atoi(c_str) == numberProduct)
            {
                cout << matrix[i][4] << endl;
                break;
            }
        }
    }
    if (request == "Amount")// Выдает общую стоимость товаров имеющихся на складе
    {
        int allSum = 0;
        for (int i = 0; i < tmp; i++)
        {
            string str = matrix[i][3];
            const char* c_str = str.c_str();
            if (matrix[i][4] == "Yes")
                allSum += atoi(c_str);
        }
        cout << allSum << endl;
    }
    if (request == "Register")// Выдает список всех изделий с номерами в заданном промежутке
    {
        cout << "Input first number" << endl;
        string firstArgument;
        cin >> firstArgument;
        int first = stoi(firstArgument);
        cout << "Input second number" << endl;
        string secondArgument;
        cin >> secondArgument;
        int second = stoi(secondArgument);
        if (first < second)
        {
            for (int i = 0; i < tmp; i++) {
                string str = matrix[i][0];
                const char* c_str = str.c_str();
                if (atoi(c_str) >= first && atoi(c_str) <= second)
                    cout << matrix[i][1] << endl;
                else
                    cout << "No match" << endl;
            }
        }
        else
        {
            for (int i = 0; i < tmp; i++) {
                string str = matrix[i][0];
                const char* c_str = str.c_str();
                if (atoi(c_str) <= first && atoi(c_str) >= second)
                    cout << matrix[i][1] << endl;
            }
        }
    }
    if (request == "Maximum") // Поиск максимальной цены
    {
        int max = 0;
        for (int i = 0; i < tmp; i++) {
            string str = matrix[i][3];
            const char* c_str = str.c_str();
            if (atoi(c_str) > max)
                max = atoi(c_str);
        }
        cout << max << endl;
    }
    if (request == "Letter") // Список изделий, наименование которых начинается с заданной буквы
    {
        cout << "Enter letter " << endl;
        char letter;
        cin >> letter;
        for (int i = 0; i < tmp; i++) {
            if (matrix[i][1][0] == letter)
                cout << matrix[i][1] << endl;
        }
    }
}
