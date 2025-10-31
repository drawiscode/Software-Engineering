#include "Transaction_Information.h"

//全局变量定义
string account;
vector<Transaction_Information> lists;

void Write_Transaction_Information()
{
    //新账单的输入
    Transaction_Information insert_information;
    cout<<"请按以下顺序依次输入本次交易信息："<<endl;
    cout<<"交易类型(income or revennue)  对方账户(account)  交易方式(WeChat,Alipay,Cash,Others)  交易金额"<<endl;
    string trans_type;
    string the_other_account;
    string payment_way;
    
    cin>>trans_type>>the_other_account>>payment_way>>insert_information.money;

    //获得当前交易时间
    Get_The_Time(insert_information.transaction_time);
    //Cin_Transaction_Time(insert_information.transaction_time);

    //将字母转化成小写
    auto tolower_str = [](string &s){
        transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c){ return (char)std::tolower(c); });
    };

    tolower_str(payment_way);
    tolower_str(trans_type);

    if(trans_type=="revennue")//支出
    {
        insert_information.trans_type=REVENNUE;
        insert_information.the_other_account=the_other_account;
    }
    else if(trans_type=="income")//收入
    {
        insert_information.trans_type=INCOME;
        insert_information.the_other_account=account;
    }
    else
    {
        insert_information.trans_type=UNKNOW;
    }
    //payment_way
    if(payment_way=="wechat")
    {
        insert_information.payment_way=WeChat;
    }
    else if(payment_way=="alipay")
    {
        insert_information.payment_way=Alipay;
    }
    else if(payment_way=="cash")
    {
        insert_information.payment_way=Cash;
    }
    else 
    {
        insert_information.payment_way=Others;
    }
    lists.emplace_back(insert_information);
    return;
}

void Read_Lists()//读取文件中的记录表
{
    // 从文件读取
    int lists_size=0;
    string filename=account+"Transaction_lists.txt";
    ifstream in(filename);
    if(!in.is_open())
    {
        //打开失败，没有该文件
        lists.resize(0);
        return;
    }

    //读取记录
    in>>lists_size;
    lists.resize(lists_size);
    for(size_t i=0;i<lists.size();i++)
    {
        lists[i].load(in);
    }
    in.close();
    return;
}

/*订单编号  10    交易类型  10   交易金额   12   对方账户   15   交易时间  24    交易方式   5*/
void Show_Transaction_Information()//显示当前交易记录表中的记录
{
    if(lists.size()==0)
    {
        cout<<"暂无交易记录"<<endl;
        return;
    }

    cout<<"当前所有的交易记录如下:"<<endl;
    cout<<left<<setw(10)<<"订单编号"<<setw(10)<<"交易类型"<<setw(12)<<"交易金额"<<setw(15)<<"对方账户"<<setw(30)<<"交易时间"<<setw(5)<<"交易方式"<<endl;
    for(size_t i=0;i<lists.size();i++)
    {
        cout<<left<<setw(10)<<i+1;
        lists[i].print();
    }
    return;
}

void Delete_Transaction_Information()//删除交易记录表中的记录
{
    Show_Transaction_Information();
    cout<<"请输入您想删除的记录编号:";
    int id;
    cin>>id;


    while(id<0||id>static_cast<int>(lists.size()))
    {
        cout<<"输入编号不存在,请您重新输入:";
        cin>>id;
    }
    //删除编号为id的订单
    id--;
    lists.erase(lists.begin()+id);
    id++;
    
    cout<<"编号为"<<id<<"的记录已经删除!"<<endl;
    return;
}
