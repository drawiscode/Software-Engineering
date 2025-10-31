#include "Transaction_Time.h"

bool Whether_Time_Is_Legal(Transaction_Time &t)
{
    //TODO
    return true;
}

void Cin_Transaction_Time(Transaction_Time &t)
{
    //TODO
    cin>>t.year>>t.month>>t.day>>t.hour>>t.minute>>t.second;
    while(Whether_Time_Is_Legal(t)==false)//判断输入的交易时间是否合法
    {
        //不合法
        cout<<"您输入的时间不合法,请重新输入:"<<endl;
        cin>>t.year>>t.month>>t.day>>t.hour>>t.minute>>t.second;
    }
}

void Get_The_Time(Transaction_Time &t)//获取当前时间
{
    std::time_t now = std::time(nullptr);
    std::tm *lt = std::localtime(&now);

    t.year   = lt->tm_year + 1900;
    t.month  = lt->tm_mon + 1;
    t.day    = lt->tm_mday;
    t.hour   = lt->tm_hour;
    t.minute = lt->tm_min;
    t.second = lt->tm_sec;
}
