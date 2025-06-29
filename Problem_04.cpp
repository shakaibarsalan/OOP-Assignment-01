#include<iostream>

using namespace std;

class Employee {
    private:
        string name;
        int id;
        float salary;
        string department;

    public:
        void setname(string n) {
            name = n;
        }
        void setid(int i) {
            id = i;
        }
        void setsalary(float s) {
            salary = s;
        }
        void setdepartment(string d) {
            department = d;
        }

        string getname() {
            return name;
        }
        int getid() {
            return id;
        }
        float getsalary() {
            return salary;
        }
        string getdepartment() {
            return department;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Salary: " << salary << endl;
            cout << "Department: " << department << endl;
        }

        void raise_salary(float raise_amount) {
            salary = salary + raise_amount;
        }
};

int main() {
    Employee emp[3];
    int i;
    float s;
    string n, d;
    for(int a=0; a<3; a++) {
        cout << "Employee Name: ";
        getline(cin, n);
        cout << n << " ID: ";
        cin >> i;
        cout << n << " Salary: ";
        cin >> s;
        cout << n << " Department: ";
        cin.ignore();
        getline(cin, d);
        cout << endl ;

        emp[a].setname(n);
        emp[a].setid(i);
        emp[a].setsalary(s);
        emp[a].setdepartment(d);
    }

    int eID;
    float raise;
    cout << "Enter the employee's ID for a salary raise: ";
    cin >> eID;
    bool found = false;
    for(int i=0; i<3; i++) {
        if(emp[i].getid() == eID) {
            cout << "Enter the amount of the salary raise for " << emp[i].getname() << ": ";
            cin >> raise;
            emp[i].raise_salary(raise);
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Employee with ID " << eID << " not found." << endl;
    }

    cout << "====== Updated List of Employees ======" << endl;
    for(int a=0; a<3; a++) {
        emp[a].display();
        cout << endl;
    }

    return 0;
}