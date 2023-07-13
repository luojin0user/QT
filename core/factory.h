#pragma once
#include "device.h"
#include "struct_transfer.h"

class Factory
{
private:
    vector<DeviceInfo *> D;
    vector<DeviceInfo*>::iterator Diter;

    vector<vector<RTinfoString>> allRTdata; //所有设备实时数据，均为String型
    vector<string> RTname;  //实时数据读取时，与allRTdata相对应的名字，与allRTdata相对应的映射

    static Factory* privateFactory;   //单例类的指针
    //string fileAddress; //当前文件夹的目录

    Factory()
    {
        Diter = D.begin();
    }

    ~Factory()
    {
        for (vector<DeviceInfo*>::iterator iter = D.begin(); iter != D.end(); iter++)
        {
            //delete每一个指针指向的内容，delete会自动调用*iter对应的析构函数
            delete (*iter);
            *iter = nullptr;
        }
        vector<DeviceInfo*>().swap(D);
        vector<vector<RTinfoString>>().swap(allRTdata);
        vector<string>().swap(RTname);
        //释放所有vector
    }


public:
    //得到单例类的实例
    static Factory* GetInstance()
    {
        return privateFactory;
    }
    //删除单例类的实例，delete自动调用析构函数
    static void deleteInstance()
    {
        if (privateFactory)
        {
            delete privateFactory;
            privateFactory = nullptr;
        }
    }

    //读写文件函数，调用DeviceInfo类里的虚函数read_from_file以及write_to_file实现
    int read_from_file();	//通过文件获取设备信息
    int write_to_file();	//把信息写入文件

    //删除vector操作，会释放内存
    void factory_ui_delete_large();
    void factory_ui_delete_small();

    //输出一个设备的信息,num指该类设备输出个数,初始置零，输出当前Diter的数据，返回0即访问完，返回1代表还有数据
    int factory_ui_show_iter(DeviceLargeInfo &info, int &num);
    int factory_ui_show_iter( DeviceSmallInfo &info,int &num);

    //输出某一行的数据，采用随机访问的形式，行数为num，从0开始，返回0表示该行设备不是需要的类型(Large or Small)，1表示是
    int factory_ui_show_line( DeviceLargeInfo &info, int num);
    int factory_ui_show_line( DeviceSmallInfo &info,int num);

    //添加，传入一个数据集合add
    void factory_ui_add(DeviceLargeInfo &add);//增加信息
    void factory_ui_add(DeviceSmallInfo &add);//增加信息

    //排序操作
    void factory_ui_sort(int sel); //排序

    //修改操作,loction指在vector中的位置
    void factory_ui_amend(int location,DeviceLargeInfo &info);
    void factory_ui_amend(int location,DeviceSmallInfo &info);

    //删除操作，调用该函数会保存到文件中，以oid参数查找，如果没有相应的设备，则不进行操作
    void factory_ui_delete(string oid);   //删除操作

    //查找操作，可以查找type，oem，oid，user，date等等，返回行数nRow，有多个都会写入nRow
    void factory_ui_find(string find,vector<int> &nRow);
    //读写实时文件RTfile
    void write_RTfile();
    void read_RTfile();

    void factory_ui_RTinfo_to_ui(int refreshCol);   //更新所有设备的RT信息
    int factory_ui_RTinfo_find_row(int vectorRow);  //找到在vector D中所在的行数所对应的allRTdata中的行数，返回int，没有就返回-1
    bool factory_ui_RTinfo_to_ui_line(RTinfoString &RTtemp,int nRow, int refreshCol); //传出RTtemp，refreshCol当前的列数,nRow当前的行数
};

