#include <iostream>

using namespace std;

class DATE {
private:
    int date;
    int month;
    int year;
    int checkmonth();
    bool leapyear();

public:
    void setdate(int d);
    void setmonth(int m1);
    void setyear(int y1);

    int getdate();
    int getmonth();
    int getyear();

    int dayBetween(DATE d1, DATE d2);
};

int DATE::checkmonth() {
    if (month == 2) {
        if (leapyear()) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void DATE::setdate(int d) {
    date = d;
}

void DATE::setmonth(int m1) {
    month = m1;
}

void DATE::setyear(int y1) {
    year = y1;
}

int DATE::getdate() {
    return date;
}

int DATE::getmonth() {
    return month;
}

int DATE::getyear() {
    return year;
}

bool DATE::leapyear() {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

int DATE::dayBetween(DATE d1, DATE d2) {
    int y_difference ;
    y_difference = d2.year - d1.year;

    int m_difference ;
    m_difference = d2.month - d1.month;

    int d_difference ;
    d_difference = d2.date - d1.date;

    int totaldays ;
    totaldays = (y_difference * 365) + (m_difference * 30) + d_difference;
    
    return totaldays;
}

int main() {
    DATE d1, d2;

    int n1, m1, y1;
    int n2, m2, y2;

    cout << "From\n";
    cout << "  Date: ";
    cin >> n1;
    cout << "  Month: ";
    cin >> m1;
    cout << "  Year: ";
    cin >> y1;
    d1.setdate(n1);
    d1.setmonth(m1);
    d1.setyear(y1);

    cout << "To\n";
    cout << "  Date: ";
    cin >> n2;
    cout << "  Month: ";
    cin >> m2;
    cout << "  Year: ";
    cin >> y2;
    d2.setdate(n2);
    d2.setmonth(m2);
    d2.setyear(y2);

    int days = d2.dayBetween(d1, d2);

    cout << "Days between " << d1.getdate() << "-" << d1.getmonth() << "-" << d1.getyear() << " and " << d2.getdate() << "-" << d2.getmonth() << "-" << d2.getyear() << " is: " << days << endl;

    return 0;
}
