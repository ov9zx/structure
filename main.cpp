#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct coustmer {
    string sureName;
    string adress;
    int discount;
};

coustmer input_customer() {
    coustmer c;
    string temp;

    cout << "Введите ФИО: ";
    getline(cin, c.sureName);

    cout << "Введите адрес: ";
    getline(cin, c.adress);

    cout << "Введите скидку: ";
    getline(cin, temp);
    stringstream ss(temp);
    ss >> c.discount;

    return c;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    coustmer c1 = {"Ivanov I.I.", "Moscow, Lenina 1", 10};
    coustmer c2 = {"Ivanov I.I.", "Moscow, Lenina 1", 10};
    coustmer c3 = {"Ivanov I.I.", "Moscow, Lenina 1", 10};

    vector<coustmer> coustmers;
    coustmers.push_back(c1);
    coustmers.push_back(c2);
    coustmers.push_back(c3);

   
    int n = 0;
    cout << "Сколько клиентов вы хотите добавить? ";
    string temp_n;
    getline(cin, temp_n);
    stringstream ss(temp_n);
    ss >> n;

    for (int i = 0; i < n; i++) {
        coustmers.push_back(input_customer());
    }

    
    vector<coustmer> unique_customers;
    for (const auto& c : coustmers) {
        bool exists = false;
        for (const auto& uc : unique_customers) {
            if (c.sureName == uc.sureName && c.adress == uc.adress) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            unique_customers.push_back(c);
        }
    }

   
    cout << "\n--- Список уникальных клиентов ---\n";
    for (const auto& c : unique_customers) {
        cout << c.sureName << " , " << c.adress << " ,Скидка: " << c.discount << "%" << endl;
    }

    return 0;
}
