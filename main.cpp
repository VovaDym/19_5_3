//Что нужно сделать
//Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:
//имя и фамилия человека;
//количество денег, которые были выплачены лицу;
//дата выплаты в формате ДД.ММ.ГГГГ.
//На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::vector<std::string> strVec;

    std::string str;
    std::fstream file;

    file.open("C:\\Users\\777\\CLionProjects\\19.5.3\\Bank.text");
    if (!file.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        std::cout << "File is open: " << std::endl;
        while (!file.eof())
        {
            file >> str;
            strVec.push_back(str);
        }
    }
    file.close();

    int indexTemp = 0;
    int temp = 0;
    int sum = 0;

    for(int i = 2;i + 1 < strVec.size(); i += 4)
    {
        sum += stoi(strVec[i]);
        if (stoi(strVec[i]) > temp)
        {
            temp = stoi(strVec[i]);
            indexTemp = i;
        }
    }
    std::cout << strVec[indexTemp - 2] << " " << strVec[indexTemp - 1] << " " << strVec[indexTemp]<<std::endl;
    std::cout << sum;
}
