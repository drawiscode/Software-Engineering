#include "Account.h"
#include "Transaction_information.h"
void Store_The_Lists()//关闭程序前将新的记录表存入文件中
{
    //不同账号用不同文件储存
    string filename=account+"Transaction_lists.txt";
    ofstream out(filename,ios::in|ios::out|ios::trunc);//可写可读并且覆盖原文件
    if(lists.size()==0)
    {
        //记录表内不存在内容，直接返回
        return;
    }
    if(!out.is_open())
    {
        //文件打开失败
        cerr<<"存在错误!尝试存储记录表时发现Transaction_lists.txt文件不存在!"<<endl;
        return;
    }
    out<<lists.size()<<endl;
    for(size_t i=0;i<lists.size();i++)
    {
        lists[i].save(out);
    }
    out.close();
    return;
}


void Login_with_Account()
{
    ifstream in("often_used_account.txt");
    if(!in.is_open())//没有这个文件，打开失败
    {
        cout<<"请输入您此次登录的账号:"<<endl;
        cin>>account;
        return;
    }
    //打开成功
    in>>account;
    in.close();//记得关闭文件

    cout<<"是否选择用常用账户登录？(yes/no)"<<endl;
    string whether_often_used;
    cin>>whether_often_used;
    if(whether_often_used!="yes")
    {
        cout<<"请输入您此次登录的账号:"<<endl;
        cin>>account;
        return;
    }
}

void Set_Often_Used_Account()//设置常用账号
{
    ofstream out("often_used_account.txt");
    if(out.is_open()==false)
    {
        cerr<<"文件打开失败,设置失败!"<<endl;
        return;
    }
    //文件打开成功!
    cout<<"设置您的常用账号:";
    
    //常用账号存储至文件
    string temp;
    cin>>temp;
    out<<temp;

    //关闭文件
    out.close();

    return;
}