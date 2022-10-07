#include "item.h"
#include <iostream>
using namespace std;

int main()
{
    itemList list;
    int option;//供使用者使用的选项

    cout<<"欢迎使用“你帮我助”物品交换软件"<<endl;

    list.readList();

    cout<<"请选择您需要使用的功能并输入相应的数字"<<endl;
    cout<<"1-添加物品"<<endl;
    cout<<"2-删除物品"<<endl;
    cout<<"3-显示物品列表"<<endl;
    cout<<"4-查找物品"<<endl;
    cout<<"5-退出程序"<<endl;
    cin>>option;

    while(option != 5)
    {
        switch(option)
        {
            case 1:
                cout<<"请依次输入添加物品的名称、主人、电话、数量"<<endl;
                list.add();break;
            case 2:
                cout<<"请输入删除物品的编号"<<endl;
                int i;
                cin>>i;
                list.remove(i);
                break;
            case 3:
                list.show();
                break;
            case 4:
                cout<<"请输入查找物品的名称"<<endl;
                string tmp;
                cin>>tmp;
                list.search(tmp);
                break;
        }
        cout<<" 请输入下一次选择"<<endl;
        cin>>option;
    }
    list.saveList();

    return 0;
}