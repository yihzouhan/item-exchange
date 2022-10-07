#include "item.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

//itemList的构造函数
itemList::itemList()
{
    head = new node;
    totalnum = 0;
}

//clear()函数的实现
void itemList::clear()
{
    node *p = head->next,*q;

    head->next = NULL;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    totalnum = 0;
}


//私有成员函数move()的实现
itemList::node *itemList::move(int i)const
{
    node *p=head;
    while(i>1)
    {
        p=p->next;
        i--;
    }
    return p;
}


//添加物品add()函数的实现
void itemList::add()
{
    string name;
    string owner;
    string tel;
    int num;

    cin>>name>>owner>>tel;
    cin>>num;

    head->next= new node(name,owner,tel,num,head->next);

    ++totalnum;

}

//删除物品remove()函数的实现
void itemList::remove(int i)
{
    node *pos,*delp;

    pos = move(i);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --totalnum;
}

//显示物品列表show()函数的实现
void itemList::show()
{
    int i = 1;//为物品设定编号
    node *p = head->next;
    while(p != NULL)
    {
        if(p->num==0)
        {
            p=p->next;
            continue;
        }
        else
        {
            cout<<i<<" "<<p->name<<" "<<p->owner<<" "<<p->tel<<" "<<p->num<<endl;
            p = p->next;
            i++;
        }
    }
}

//查找物品search()函数的实现
void itemList::search(string name)
{
    node *p = head->next;
    int i=1;

    while(p !=NULL && p->name != name){p = p->next; ++i;}
    if(p == NULL) cout<<"列表无该物品"<<endl;
    else cout<<"查找到该物品"<<i<<" "<<p->name<<" "<<p->owner<<" "<<p->tel<<" "<<p->num<<endl;
}

//从csv文件读取物品列表readList()函数的实现
void itemList::readList()
{
    ifstream inFile("itemList.csv", ios::in);
    string line;
    head->next=new node();
    node *p = head->next;
    string tmpnum;//读取数据时暂时用字符串保存物品数量

    while (getline(inFile, line))
    {
        istringstream sin(line);
        getline(sin, p->name, ',');
        getline(sin, p->owner, ',');
        getline(sin, p->tel, ',');
        getline(sin, tmpnum);
        p->num = stoi(tmpnum);
        p->next=new node();

        p = p->next;
        totalnum++;


    }
    inFile.close();

    cout<<"物品列表数据读取完成"<<endl;
}

//保存物品列表为csv文件saveList()函数的实现
void itemList::saveList()
{
    ofstream outFile("itemList.csv", ios::out);
    node *p = head->next;
    while(p != NULL)
    {
        outFile<<p->name<<",";
        outFile<<p->owner<<",";
        outFile<<p->tel<<",";
        outFile<<p->num;
        outFile<<endl;
        p = p->next;
    }
    outFile.close();
    cout<<"物品列表数据已保存"<<endl;
}