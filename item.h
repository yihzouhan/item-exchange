#ifndef _Item_h
#define _Item_h
#include <iostream>
using namespace std;

class itemList{
private:
    //采用单列表中的节点类保存物品的信息
    struct node{
        string name;//物品名称
        string owner;//物品主人
        string tel;//联系电话
        int num;//物品数量

        node *next;

        node(string &x, string &y, string &z, int &w, node *n=NULL)
            {name=x, owner=y, tel=z, num=w;next = n;}
        node():next(NULL){}
        ~node(){}
    };

    node *head;//头指针


    node *move(int i)const;//返回第i个节点的地址

    public:
        int totalnum;//物品列表的物品数量
        itemList();
        ~itemList(){clear();delete head;}

        void clear();//清空物品列表
        void add();//添加物品
        void remove(int i);//删除物品
        void show();//显示物品列表
        void search(string name);//查找物品

        void readList();//读取物品列表
        void saveList();//保存物品列表
};
#endif