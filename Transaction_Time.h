#ifndef TRANSACTION_TIME_H
#define TRANSACTION_TIME_H

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
struct Transaction_Time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    void save(ofstream &out)const
    {
        out<<year<<" "<<month<<" "<<day<<" "<<hour<<" "<<minute<<" "<<second<<" ";
    }
    void load(ifstream &in)
    {
        in >> year >> month >> day >> hour >> minute >> second;
    }
    void print()const
    {
        string the_time=to_string(year)+"年"+to_string(month)+"月"+to_string(day)+"日"+to_string(hour)+"时"+to_string(minute)+"分"+to_string(second)+"秒";
        cout<<left<<setw(30)<<the_time;
        return;
    }
};

void Cin_Transaction_Time(Transaction_Time &t);
bool Whether_Time_Is_Legal(Transaction_Time &t);
void Get_The_Time(Transaction_Time &t);//获取当前时间
#endif