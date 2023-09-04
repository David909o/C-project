#include<iostream>
#include<string.h>
#include<fstream>
#include<ostream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<windows.h>

using namespace std;

class Dovidka
{
protected:

    char NameFirm[200];
    char Owner_Name[200];
    char ADRESS[200];
    int Phone;
    char Type_Work[200];
    char City[200];
public:
    Dovidka()
    {
        NameFirm[100] = NULL;
        Owner_Name[100] = NULL;
        ADRESS[100] = NULL;
        Phone = 0;
        Type_Work[100] = NULL;
        City[100] = NULL;
    }
    Dovidka(char N, char O, char A, int P, char T,char C)
    {
        NameFirm[100] = N;
        Owner_Name[100] = O;
        ADRESS[100] = A;
        Phone = P;
        Type_Work[100] = T;

    }
    void Show()
    {
        cout << NameFirm << endl;
        cout << Owner_Name << endl;
        cout << ADRESS << endl;
        cout << Phone << endl;
        cout << Type_Work << endl;
    }
    void SetNameFirm(char* key)
    {
        cout << "введіть назву фірми";
        cin >> NameFirm;
    }
    char  GetNameFirm()
    {
        return NameFirm[100];
    }
    void SetNameOwner(char* key)
    {
        cout << "введіть ім'я власника" << endl;
        cin >> Owner_Name;
    }

    char GetNameOwner()
    {
        return Owner_Name[100];
    }
    void SetAdress(char* key)
    {
        cout << "введіть адресу фірми" << endl;
        cin >> ADRESS;
    }
    char GetAdress()
    {
        return ADRESS[100];
    }
    void SetPhone(int const& key)
    {
        cout << "введіть номер телефону " << endl;
        cin >> Phone;
    }
    int GetPhone()
    {
        return Phone;
    }
    void SetTypeWork(char* key)
    {
        cout << "введіть вид діяльності" << endl;
        cin >> Type_Work;
    }
    char GetTypeWork()
    {
        return Type_Work[100];
    }
    vector<Dovidka>l;
    void AddInfo()
    {
        Dovidka tmp;
        tmp.Owner_Name;
        tmp.ADRESS;
        tmp.NameFirm;
        tmp.Phone;
        tmp.Type_Work;
        l.push_back(tmp);
    }


    friend std::istream& operator>>(istream& in, Dovidka& obj)
    { //Перезавантаження оператора вводу в консоль
        cout << "Додавання нових записів:\n\n";
        cout << "Им'я.: "; in >> obj.Owner_Name;
        cout << "Номер телефону: "; in >> obj.Phone;
        cout << "Назва фірми: "; in >> obj.NameFirm;
        cout << "вид діяльності"; in >> obj.Type_Work;
        cout << "Адреса фірми"; in >> obj.ADRESS;
        return in;
    }

    friend std::ostream& operator<<(ostream& out, Dovidka& obj)
    { //Перезавантаження оператора виводу в консоль
        out << obj.Owner_Name << "\n";
        out << obj.ADRESS << "\n";
        out << obj.Phone << "\n";
        out << obj.Type_Work << "\n";
        out << obj.NameFirm << "\n";

        return out;
    }

    void clear() { //Функція очистки файла
        ofstream in("d:\\git HUB\\input.txt", ios::out | ios::trunc);
        in.close();
    }

    void clear_new() { //Функція очистки нового файла
        ofstream in("d:\\git HUB\\input_new.txt", ios::out | ios::trunc);
        in.close();
    }

    bool is_file_empty() { //Функція перевірки файла на пустоту
        ifstream in("d:\\git HUB\\input.txt");
        in.seekg(0, ios::end);
        if (in.tellg() == 0) {
            return true;
        }
        in.close();
        return false;
    }
    void save_into_file() { //Функція збереження списка в файл
        clear();
        ofstream out("d:\\git HUB\\input.txt");
        for (const Dovidka& data : l) {
            out << data.NameFirm << "\n";
            out << data.Owner_Name << "\n";
            out << data.Phone << "\n";
            out << data.Type_Work << "\n";
        }
        out.close();
    }
    void read_from_file(Dovidka& data)
    { //Функція додавання записів із файла в список
        ifstream in("d:\\git HUB\\input.txt");
        while (in >> data) {
            l.push_back(data);
        }
        in.close();
    }

    void output_from_file() { //Функція виводу записів із файлу в консоль
        if (!is_file_empty()) {
            ifstream in("d:\\git HUB\\input.txt");
            if (in) {
                int k = 0;
                while (in >> *this) {
                    k++;
                    cout << "Запис #" << k << ":\n\n";
                    cout << *this;
                    cout << "\n";
                }
                in.close();
            }
            else {
                cout << "Файл input.txt не знайдено!\n\n";
            }
        }
        else {
            cout << "Файл input.txt пуст!\n\n";
        }
    }

    void output_from_new_file(Dovidka& data) { //Функція виводу записів з нового файлу в консоль
        ifstream in("d:\\git HUB\\input_new.txt");
        if (in) {
            int k = 0;
            while (in >> data.NameFirm >> data.Owner_Name >> data.Phone >> data.ADRESS >> data.Type_Work) {
                k++;
                cout << "Запись #" << k << ":\n\n";
                cout << data.NameFirm << "\n";
                cout << data.Owner_Name << "\n\n";
                cout << data.Phone << "\n\n";
                cout << data.ADRESS << "\n\n";
                cout << data.Type_Work << "\n\n";
            }
            in.close();
        }
        else {
            cout << "Файл input_new.txt не знайдено!\n\n";
        }
    }

    void add_client(Dovidka& data) { //Додавання нового запису в список (записи додаються в кінец списку)
        int k;
        cout << "Введіть число записів, які треба додати: ";
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cout << "\nЗапись #" << i << ":\n";
            cin >> data;
            l.push_back(data);
        }
        cout << "\nЗаписи додані!\n\n";
        save_into_file(); //зберігаємо результат в файл
    }
    void output_client(string* const key) { //Функція виводу списку клієнтів
        ifstream in("d:\\git HUB\\input.txt");
        bool flag = false;
        cout << "виведення всіх записів: ";
        for (auto it = l.begin(); it != l.end(); ++it)
        {

            cout << it->Owner_Name << "\n";
            cout << it->NameFirm << "\n";
            cout << it->ADRESS << "\n";
            cout << it->Phone << "\n";
            cout << it->Type_Work << "\n";
            flag = true;
        }
        in.close();
        if (!flag) {
            cout << "клиентів не знайдено!\n\n";
        }
    }
};
void Menu_()
{
    cout << "\t\t\t\t\tДля роботи з довідником додайте дані" << endl;
    cout << "Довідник:" << endl;
    cout << "1 - Додавання даних" << endl;
    cout << "2 - пошук по назві фірми" << endl;
    cout << "3 - пошук по імені власника" << endl;
    cout << "4 - пошук по виду діяльності" << endl;
    cout << "5 - пошук по номеру телефону" << endl;
    cout << "6 - Показ всіх записів " << endl;
    cout << "7 -запис інформації в файл " << endl;
    cout << "8 - Exit" << endl;
}

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    Dovidka S;
    int n;
    char* key = new char[100];
    n = 10;
    int Menu = 0;
    do
    {
        system("cls");
        Menu_();
        cin >> Menu;
        cin.ignore();
        switch (Menu)
        {
        case 1:
            cout << "Додавання даних" << endl;
            S.add_client(S);
            break;
        case 2:
            cout << "пошук по назві фірми" << endl;
            cout << "введіть назву фірми" << endl;
            cin.getline(key, 100);
            S.SetNameFirm(key);
            cout << "В довідникунема такої фірми" << endl;
            break;
        case 3:

            cout << "пошук по імені власника" << endl;
            cout << "введіть ім'я власника" << endl;
            cin.getline(key, 100);
            S.SetNameOwner(key);
            cout << "В довіднику нема такого власника" << endl;
            break;
        case 4:

            cout << "пошук по виду діяльгості" << endl;
            cout << "введіть вид діяльності" << endl;
            cin.getline(key, 100);
            S.SetTypeWork(key);

            cout << "нема такого виду діяльності" << endl;
            break;
        case 5:
            int str;
            cout << "пошук по номеру телефона" << endl;
            cout << "введіть номер телефона" << endl;
            cin >> str;
            S.SetPhone(746874186);
            S.GetPhone();
            if (S.GetPhone() == str)
                cout << "нема такого номера телефона" << endl;
            break;
        case 6:
            cout << "вывод всех записей" << endl;
            S.output_from_file();
        case 7:
            cout << "запис інформації в файл" << endl;
            S.save_into_file();

        default:cout << "No such number menu item" << endl;
        }
        system("pause");
    } while (Menu != 8);
    system("pause");
    return 0;
}