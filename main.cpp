//Что нужно сделать
//Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:
//имя и фамилия человека;
//количество денег, которые были выплачены лицу;
//дата выплаты в формате ДД.ММ.ГГГГ.
//На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {

    std::string str,strMax;
    int payoutMax = 0;
    std::fstream file;
    int sum = 0;
    file.open("Bank.text");
    if (!file.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        std::cout << "File is open: " << std::endl;
        while (getline(file, str))
        {
            std::stringstream ss(str);
            std::string name,surname,date;
            int payout;
            ss >> name >> surname >> payout >> date;
            if (payout > payoutMax)
            {
                payoutMax = payout;
                strMax = str;
            }
            sum += payout;
        }
    }
    file.close();
    std::cout << " The highest payout: " << strMax << std::endl;
    std::cout << " Total amount of payments: " <<sum;
    return 0;
}
