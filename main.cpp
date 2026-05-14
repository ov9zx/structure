



/*

//4.1 (вариант№2)

#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct coustmer {
    string sureName;
    string adress;
    int discount;
};

coustmer input_customer() {
    coustmer c;

    cout << "Введите ФИО: ";
    getline(cin, c.sureName);

    cout << "Введите адрес: ";
    getline(cin, c.adress);

    cout << "Введите скидку: ";
    cin >> c.discount;
    cin.ignore();

    return c;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    coustmer c1 = {"Ivanov I.I.", "Moscow, Lenina 1", 10};
    coustmer c2 = {"Petrov P.P.", "Kazan, Mira 5", 5};
    coustmer c3 = {"Sidorov S.S.", "Sochi, Rose 10", 15};

    vector<coustmer> coustmers;
    coustmers.push_back(c1);
    coustmers.push_back(c2);
    coustmers.push_back(c3);

    int n = 0;
    cout << "Сколько клиентов вы хотите добавить? ";
    cin >> n;
    cin.ignore();

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
        cout << c.sureName << " , " << c.adress << " , Скидка: " << c.discount << "%" << endl;
    }

    return 0;
}
*/
//-------------------------------------------------------------------------------------------------------------------------

/*
//4.2 (вариант№3)
#include <iostream>
#include <windows.h>
using namespace std;

struct st {
    char value;
    st* next;
};

class List {
private:
    st* head;

public:
    List() {
        head = NULL;
    }

    ~List() {
        while (head != NULL) {
            st* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(char val) {
        st* newNode = new st;
        newNode->value = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            st* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void duplicateDigits() {
        st* curr = head;
        while (curr != NULL) {
            if (curr->value >= '0' && curr->value <= '9') {
                st* newNode = new st;
                newNode->value = curr->value;
                newNode->next = curr->next;
                curr->next = newNode;
                curr = newNode->next;
            } else {
                curr = curr->next;
            }
        }
    }

    void show() {
        st* temp = head;
        while (temp != NULL) {
            cout << temp->value;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List myList;
    char input;

    cout << "Введите строку (точка '.' в конце): " << endl;
    while (cin >> input && input != '.') {
        myList.add(input);
    }

    myList.duplicateDigits();

    cout << "Результат: ";
    myList.show();

    return 0;
}
/*

//----------------------------------------------------------------------------------------------------------------------
/*
//4.3 (вариант№2)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

class Worker {
public:
    string sureName;
    int employeeId;
    string position;
    int year, day, month;
    int salary;

    Worker() {}

    Worker(string sn, int id, string pos, int y, int d, int m, int sal) {
        sureName = sn;
        employeeId = id;
        position = pos;
        year = y;
        day = d;
        month = m;
        salary = sal;
    }

    void input() {
        cout << "Введите фамилию и инициалы: ";
        getline(cin, sureName);

        cout << "Введите табельный номер: ";
        cin >> employeeId;
        cin.ignore();

        cout << "Введите должность: ";
        getline(cin, position);

        cout << "Введите год поступления: ";
        cin >> year;
        while (year < 1950 || year > 2026) {
            cout << "Ошибка! Введите корректный год: ";
            cin >> year;
        }

        cout << "Введите месяц: ";
        cin >> month;
        while (month < 1 || month > 12) {
            cout << "Ошибка! Введите месяц (1-12): ";
            cin >> month;
        }

        cout << "Введите день: ";
        cin >> day;
        while (day < 1 || day > 31) {
            cout << "Ошибка! Введите день (1-31): ";
            cin >> day;
        }

        cout << "Введите заработную плату: ";
        cin >> salary;
        cin.ignore();
        cout << "-----------------------" << endl;
    }

    void show() const {
        cout << sureName << " | ID: " << employeeId
             << " | Job: " << position
             << " | Date: " << year << "/" << day << "/" << month
             << " | Salary: " << salary << endl;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Worker> workers;
    int n;
    int currentYear = 2026;

    workers.push_back(Worker("Ivanov I.I.", 101, "Developer", 2015, 10, 5, 150000));
    workers.push_back(Worker("Sidorov A.P.", 102, "Manager", 2021, 20, 1, 120000));
    workers.push_back(Worker("Petrov B.V.", 103, "Designer", 2018, 15, 3, 135000));

    cout << "Добавлено 3 случайных сотрудника." << endl;
    cout << "Сколько еще сотрудников добавить? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Worker w;
        w.input();
        workers.push_back(w);
    }


    sort(workers.begin(), workers.end(), [](const Worker& a, const Worker& b) {
        return a.sureName < b.sureName;
    });

    int expLimit;
    cout << "\nВведите минимальный стаж работы: ";
    cin >> expLimit;

    cout << "\n--- Результаты (а): Стаж более " << expLimit << " лет ---" << endl;
    for (int i = 0; i < workers.size(); i++) {
        if ((currentYear - workers[i].year) > expLimit) {
            workers[i].show();
        }
    }

    int minSalary, maxSalary;
    cout << "\nВведите диапазон зарплаты (от и до): ";
    cin >> minSalary >> maxSalary;

    cout << "\n--- Результаты (б): Зарплата من " << minSalary << " إلى " << maxSalary << " ---" << endl;
    for (int i = 0; i < workers.size(); i++) {
        if (workers[i].salary >= minSalary && workers[i].salary <= maxSalary) {
            workers[i].show();
        }
    }

    string targetPos;
    cout << "\nВведите должность для фильтрации: ";
    cin.ignore();
    getline(cin, targetPos);

    cout << "\n--- Результаты (в): Должность " << targetPos << " ---" << endl;
    for (int i = 0; i < workers.size(); i++) {
        if (workers[i].position == targetPos) {
            workers[i].show();
        }
    }

    return 0;
}
*/
