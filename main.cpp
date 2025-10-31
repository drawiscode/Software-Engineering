#include "Transaction_Information.h"
#include "Transaction_Time.h"
#include "Account.h"

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    Login_with_Account();
    Read_Lists();//读取账单记录表
    while(1)
    {
        cout<<"请选择你要进行的操作(输入不同的值代表不同的操作):"<<endl;
        cout<<"1(插入新记录),2(删除旧记录),3(显示所有记录),4(设置常用账号)-1(退出app)"<<endl;;
        int oper;
        cin>>oper;
        if(oper==-1)//终止程序运行
        {
            //终止程序前需要将当前账单记录表存储起来
            Store_The_Lists();
            break;
        }
        switch (oper)
        {
            case 1:
                Write_Transaction_Information();
                break;
            case 2:
                Delete_Transaction_Information();
                break;
            case 3:
                Show_Transaction_Information();
                break;
            case 4:
                Set_Often_Used_Account();
            default:
                break;
        }
    }
    return 0;
}