#include <bits\stdc++.h>
#include <iostream>
using namespace std;

class separator {
public :
    int day = 0, month = 0;

    separator setDayMonth(string x = "") {
        int finder = x.find("/");
        month = stoi(x.substr(0, finder));
        day = stoi(x.substr(finder + 1));
        //return *this;
    }
};
class MonthError : public separator{
public:
    class smaller {};
    class bigger {};
    int  checkMonth (int m)
    {
        if (m<1 )
        {
            throw smaller{};
        }
        else if (m>12)
        {
            throw bigger{};
        }
        else if (m ==1 )
            cout << " January";
        else if (m == 2 )
            cout << " February";
        else if (m ==3 )
            cout << " March";
        else if (m ==4 )
            cout << " April";
        else if (m ==5 )
            cout << " May" ;
        else if (m ==6 )
            cout << " June";
        else if (m ==7 )
            cout << " July ";
        else if (m ==8 )
            cout << " August";
        else if (m ==9)
            cout << " Septemper";
        else if (m ==10 )
            cout << " October";
        else if (m ==11 )
            cout << " November";
        else if (m ==12 )
            cout << " December";
        return m;
    }

};


class DayError : public separator{
public:
    class notvalid1 {};
    class notvalid2 {};
    class notvalid3 {};
    int checkDayWithinMonth (int day , int month)
    {
        if ((month ==1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day<1 || day> 31))
        {
            throw notvalid1();
        }
        else if ((month ==4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
        {throw notvalid2();}
        else if ((month ==2 )&& (day < 1 || day > 29))
        {throw notvalid3();}
        else cout << " " << day << endl;
    }


};


int main() {
    cout << "============= Welcome to alphabetic month/day convertor =============\n\n\n";
    cout << "Enter the number of dates to be checked :\n";
    int x ; cin >> x;
    while (x--) {
        string date;
        cin >> date;
        separator ob1;
        ob1.setDayMonth(date);
        MonthError month;
        DayError day;
        try {
            month.checkMonth(ob1.month);
            day.checkDayWithinMonth(ob1.day, ob1.month);

        }
        catch (MonthError::smaller) {
            cout << "unvalid month number , there are no months less than 1 try another value\n";
        }
        catch (MonthError::bigger) {
            cout << "unvalid month number , there are no months greater than 12 try another value\n";
        }
        catch (DayError::notvalid1) {
            cout << "'s available range of days is from 1 to 31 , please try another value within that range \n";
        }
        catch (DayError::notvalid2) {
            cout << "'s available range of days is from 1 to 30 , please try another value within that range\n";
        }
        catch (DayError::notvalid3) {
            cout << "'s available range of days is from 1 to 29 , please try another value within that range\n";
        }
    }
}
