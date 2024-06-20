#include <iostream>
#include <vector>

using namespace std;

class Human {
public:
    string full_name;                  //фио
    string date_of_birth;              //дата рождения
    string gender;                     //пол
    int phone_number;
    string email;
    string get_full_name() {
        return this->full_name;
    }
};

class Medical_officer: private Human {

    string uniform;                    //униформа 
    int salary;                        //зарплата
    int expirience;                    //стаж  
    int ID;                            
};

class Doctor: private Medical_officer{
    string specializatioin;             //специализация   
    string education;                   //образование  
    int category;
    int cabinet_number;
};

class Nurse: private Medical_officer {  //медсестра
    string education;
    string post;                        //должность
};

class Staff : private Medical_officer { //работники
    string post;                        //должность
};

class Patient:private Human {
    string diagnosis;
    int ID;
    bool hospital;
    
public:
    Patient(string full_name, string date_of_birth, string gender, int phone_number, string email, string diagnosis, int ID, bool hospital) {
        this->full_name =  full_name;
        this->date_of_birth = date_of_birth;
        this->gender = gender;
        this->phone_number = phone_number;
        this->email = email;
        this->diagnosis = diagnosis;
        this->ID = ID;
        this->hospital = hospital;
    }

    string get_diagnosis() {
        return diagnosis;
    }
    string get_full_name() {
        return full_name;
    }
    string get_date_of_birth() {
        return date_of_birth;
    }
    string get_gender() {
        return gender;
    }
    bool get_hospital() {
        return hospital; 
    }
    string get_email() {
        return email;
    }
    int get_phone_number() {
        return phone_number;
    }
    int get_ID() {
        return ID;
    }
};

class Department {                         //отделение
    int floors;           
    int offices;          
    vector<int> ID_equipment;              //массивы с айди оборудованием
    vector<Medical_officer> employees;     //массивы с работниками
    vector<Patient> patients;
};

class Hospital {
    vector<Department> departments;        //массив отделений
    string adress;
    string get_adress() {                  //метод 
        return adress;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Patient a("Басков Соломон Валерьевич", "05.09.1989", "мужской", 98901574849, "jabdsj@mail.com", "отит", 159489, true);
    Patient b("Градов Прокофий Ильич", "14.08.2001", "мужской", 98948915789, "lskdsdkfns@mail.com", "ОРВИ", 147896, true);
    Patient c("Кузнецова Любовь Васильевна", "28.02.1999", "женский", 9151544488, "pfakskjdn@mail.com", "ангина", 258957, false);

    cout << "Диагноз: " << a.get_diagnosis() << "; ФИО: " << a.get_full_name() << "; Пол: " << a.get_gender() << endl;
    cout << "Диагноз: " << b.get_diagnosis() << "; ФИО: " << b.get_full_name() << "; Пол: " << b.get_gender() << endl;
    cout << "Диагноз: " << c.get_diagnosis() << "; ФИО: " << c.get_full_name() << "; Пол: " << c.get_gender() << endl;

    return 0;
}
