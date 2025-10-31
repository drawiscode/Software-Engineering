/*
系统应支持记录用户的每一笔收入或支出，包括以下信息：
类型（收入/支出）;金额;账户信息（包括本人账户与对方账户）;交易时间（精确到年月日时分秒）;支付或收款方式（如微信、支付宝、现金等）。
*/
#ifndef TRANSACTION_INFORMATION_H
#define TRANSACTION_INFORMATION_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>  // 需要包含这个头文件
#include <cctype>     // 需要包含这个头文件用于tolower
#include "Transaction_Time.h"

using namespace std;

enum Transaction_Type//交易类型的英文
{
    INCOME,//收入
    REVENNUE,//支出
    UNKNOW
};
enum Payment_Way
{
    WeChat,
    Alipay,
    Cash,
    Others
};
struct Transaction_Information
{
    Transaction_Type trans_type;
    long long int money;
    string the_other_account;//对方账户
    Transaction_Time transaction_time;
    Payment_Way payment_way;
    void save(ofstream &out)const
    {
        out<<static_cast<int>(trans_type)<<" "<<money<<" "<<the_other_account<<" ";//static_cast在编译时进行类型转换
        transaction_time.save(out);
        out<<static_cast<int>(payment_way)<<endl;
    }
    void load(ifstream &in)
    {
        int t_type;
        in>>t_type>>money>>the_other_account;
        trans_type=static_cast<Transaction_Type>(t_type);
        transaction_time.load(in);
        int p_way;
        in>>p_way;
        payment_way=static_cast<Payment_Way>(p_way);
    }
    void print()const
    {
        switch (static_cast<int>(trans_type))
        {
            case 0:
            cout<<left<<setw(10)<<"收入";
            break;

            case 1:
            cout<<left<<setw(10)<<"支出";
            break;
            
            default:
            cout<<left<<setw(10)<<"未知";
            break;
        }

        cout<<left<<setw(12)<<money;
        cout<<left<<setw(15)<<the_other_account;
        transaction_time.print();
        switch (static_cast<int>(payment_way))
        {
            case 0:
                cout<<left<<setw(5)<<"微信";
                break;

            case 1:
                cout<<left<<setw(5)<<"支付宝";
                break;

            case 2:
                cout<<left<<setw(5)<<"现金";
                break;

            case 3:
                cout<<left<<setw(5)<<"其他";
                break;

            default:
                break;
        }
        cout<<endl;
    }
};


//全局变量声明
extern string account;
extern vector<Transaction_Information> lists;


void Write_Transaction_Information();//插入新的交易记录

void Read_Lists();//读取文件中的记录表

void Delete_Transaction_Information();//删除交易记录表中的记录
void Show_Transaction_Information();//显示当前交易记录表中的记录

#endif