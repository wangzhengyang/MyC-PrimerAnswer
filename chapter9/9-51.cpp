#include <iostream>
#include <string>

using namespace std;

class Date{
public:
    Date()=default;
    Date(const string &s);
private:
    unsigned int year = 1970;
    unsigned int month = 1;
    unsigned int day = 1;
};

Date::Date(const string &s)
{
    string::size_type start = 0;
    string::size_type end = 0;
    end = s.find_first_of(" ,/");
    string smonth = s.substr(start, end - start);
    start = end + 1;
    end = s.find_first_of(" ,/", start);
    string sday = s.substr(start, end - start);
    start = end + 1;
    end = s.find_first_of(" ,/", start);
    string syear = s.substr(start, end - start);

    cout << "month:" << smonth << endl;
    cout << "day:" << sday << endl;
    cout << "year:" << syear << endl;

    year = stoi(syear);
    day = stoi(sday);
    //月份通过其他方式实现
}

int main()
{
    Date date1("January 1,1900");
    Date data2("1/1/1990");
    Date data3("Jan 1 1900");
    return 0;
}