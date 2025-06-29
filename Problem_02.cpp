#include<iostream>

using namespace std ;

class Stock {
    private:
        string symbol ;
        string name ;
        float current_price ;
        float historical_price[5] ;
    public:
        void setsymbol (string sym) {
            symbol = sym ;
        }
        void setname (string nam) {
            name = nam ;
        }
        void setcp (float cp) {
            current_price = cp ;
        }
        void sethp (float hp[]) {
            for(int i = 0 ; i < 5 ; i++) {
                historical_price[i] = hp[i] ;
            }
        }

        string getsymbol () {
            return symbol ;
        }
        string getname () {
            return name ;
        }
        float getcp () {
            return current_price ;
        }
        float gethp (int i) {
            return historical_price[i] ;
        }

        float cal_avg_pr (int timePeriod) {
            float sum = 0 ;
            for(int i = 0 ; i < timePeriod ; i++) {
                sum = sum + historical_price[i] ;
            }
            return sum / timePeriod ;
        }

        string stockValue() {
            float average_price = cal_avg_pr (5) ;
            float value = ((current_price - average_price) / average_price) * 100 ;
            if(value > 10) { 
                if(value > 0) {
                    return "Overvalued" ;
                } else {
                    return "Undervalued" ;
                }
            } else {
                return "Fairly valued" ;
            }
        }
} ;

int main() {
    Stock comp ;

    string sym, nam ;
    float cp, hp[5] ;

    cout << "Ticket Symbol : " ;
    getline(cin,sym) ;
    cout << "Company Name : " ;
    getline(cin,nam) ;
    cout << "Current Price : " ;
    cin >> cp ;
    for(int i = 0 ; i < 5 ; i++) {
        cout << i+1 << " Historical Price : " ;
        cin >> hp[i] ;
    }
    
    comp.setsymbol(sym) ;
    comp.setname(nam) ;
    comp.setcp (cp) ;
    comp.sethp (hp) ;

    int tp ;
    cout << "Input Time Period = " ;
    cin >> tp ;
    float average_price = comp.cal_avg_pr (tp) ;
    cout << "Average price over " << tp << " periods: " << average_price << endl ;

    string value = comp.stockValue() ;
    cout << "Status of Current stock value is " << value << endl ;
    
    return 0 ;
}
