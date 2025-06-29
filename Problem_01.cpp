#include<iostream>

using namespace std;

class user_account {
    private:
        int acc_number ;
        string acc_holder_name ;
        float acc_balance ;
        string bankname ;
    public:
        void setnumber ( int number ) {
            acc_number = number ;
        }
        void setname ( string name ) {
            acc_holder_name = name ;
        }
        void setbalance ( float balance ) {
            acc_balance = balance ;
        }
        void setbankname ( string b_name ) {
            bankname = b_name ;
        }

        int getnumber () {
            return acc_number ;
        }
        string getname () {
            return acc_holder_name ;
        }
        float getbalance () {
            return acc_balance ;
        }
        string getbankname () {
            return bankname ;
        }

        void detail_user () {
            cout << "\n  Account Number: " << acc_number << endl;
            cout << "  Account Holder Name: " << acc_holder_name << endl;
            cout << "  Account Balance: " << acc_balance << endl;
            cout << "  Bank Name: " << bankname << endl;
            cout << endl;
        }
} ;

int main() {
    user_account acc[5] ;

    acc[0].setnumber(123456);
    acc[0].setname("Muhammad Ali");
    acc[0].setbalance(1000.0);
    acc[0].setbankname("Bank of Punjab");

    acc[1].setnumber(654321);
    acc[1].setname("Muhammad Ahmed");
    acc[1].setbalance(500.0);
    acc[1].setbankname("Habib Metro");

    acc[2].setnumber(987654);
    acc[2].setname("Abdul Hadi");
    acc[2].setbalance(750.0);
    acc[2].setbankname("Habib Bank Limited");

    acc[3].setnumber(123123);
    acc[3].setname("Arman Bin Tahir");
    acc[3].setbalance(2500.0);
    acc[3].setbankname("Allied Bank");

    acc[4].setnumber(456456);
    acc[4].setname("Eman Murtaza");
    acc[4].setbalance(10000.0);
    acc[4].setbankname("Alfalah Bank");

    int choice, ac_num ;
    float new_balance;
    bool found = false;

    cout << "Existing Account Numbers\n  123456, 654321, 987654, 123123, 456456\n" ;

    cout << "Enter Account Number: " ;
    cin >> ac_num ;
    for (int i = 0; i < 5; i++) {
        if (acc[i].getnumber() == ac_num) {
            found = true;
            cout << "  Enter 1 if you want to check Account Details\n" ;
            cout << "  Enter 2 if you want to Modify Account Balance\n" ;
            cout << "  Enter 0 if you want to exit\n" ;
            cout << "  Enter Choice : " ;
            cin >> choice ;

            if (choice==1) {
                acc[i].detail_user();
            }
            
            else if (choice==2) {
                cout << "  Enter new balance: ";
                cin >> new_balance;
                acc[i].setbalance(new_balance);
                cout << "Account balance updated successfully." << endl;
            }
            
            else if (choice==0) {
                return 0;
            }
            
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    if (!found) {
        cout << "Account not found.\n" ;
    }


    return 0;
}