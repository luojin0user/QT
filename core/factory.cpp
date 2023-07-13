#pragma once
#include "factory.h"
#include "device.h"
#include <sstream>


//排序部分

bool compare_type(DeviceInfo* s1, DeviceInfo* s2);
bool compare_oid(DeviceInfo* s1, DeviceInfo* s2);
bool compare_oem(DeviceInfo* s1, DeviceInfo* s2);
bool compare_work(DeviceInfo* s1, DeviceInfo* s2);
bool compare_condition(DeviceInfo* s1, DeviceInfo* s2);

//Large特有
bool compare_port_in_large(DeviceLarge* s1, DeviceLarge* s2);
bool compare_port_out_large(DeviceLarge* s1, DeviceLarge* s2);
bool compare_pfail_large(DeviceLarge* s1, DeviceLarge* s2);
bool compare_efficiency_large(DeviceLarge* s1, DeviceLarge* s2);
bool compare_temperature_large(DeviceLarge* s1, DeviceLarge* s2);

//Small特有
bool compare_revert_small(DeviceSmall* s1, DeviceSmall* s2);
bool compare_user_small(DeviceSmall* s1, DeviceSmall* s2);
bool compare_start_date_small(DeviceSmall* s1, DeviceSmall* s2);
bool compare_end_date_small(DeviceSmall* s1, DeviceSmall* s2);

//读写文件函数，调用DeviceInfo类里的虚函数read_from_file以及write_to_file实现
int Factory::read_from_file()
{
    string line;    //临时储存

    ifstream LFile;
    LFile.open("file/LargeInfo.csv", ios::in);
    getline(LFile, line);	//剔除标题行
    while (getline(LFile, line))
    {
        DeviceLarge* DL = new DeviceLarge;
        DL->read_from_file(line);   //调用虚函数read_from_file
        D.push_back(DL);
    }

    LFile.close();

    ifstream SFile;
    SFile.open("file/SmallInfo.csv", ios::in);
    getline(SFile, line);	//剔除标题行

    while (getline(SFile, line))
    {
        DeviceSmall* DS = new DeviceSmall;
        DS->read_from_file(line);
        D.push_back(DS);
    }

    SFile.close();

    return 0;
}

int	Factory::write_to_file()
{
    //多态
    ofstream LFile;
    ofstream SFile;
    LFile.open("file/LargeInfo.csv", ios::out | ios::trunc);	//out,trunc覆盖写
    SFile.open("file/SmallInfo.csv", ios::out | ios::trunc);

    LFile << "设备类型" << ',' << "OID" << ',' << "OEM" << ',' << "是否使用" << ',' << "是否故障" << ',';
    LFile<< "损坏概率" << ',' << "输入接口" << ',' << "输出接口" << ',' << "效率" << ',' << "温度" << endl;

    SFile << "设备类型" << ',' << "OID" << ',' << "OEM" << ',' << "是否使用" << ',' << "是否故障" << ',';
    SFile << "是否归还" << ',' << "用户" << ',' << "借出时间" << ',' << "归还时间" << endl;


    for (Diter = D.begin(); Diter != D.end(); Diter++)
    {
        if (typeid(**Diter).name() == typeid(DeviceLarge).name())
            (*Diter)->write_to_file(LFile);
        else
            (*Diter)->write_to_file(SFile);
    }

    LFile.close();
    SFile.close();
    return 0;
}

//删除vector操作，会释放内存
void Factory::factory_ui_delete_large()
{
    for(Diter = D.begin();Diter != D.end();)
    {
        if(typeid(**Diter).name() == typeid(DeviceLarge).name())
        {
            delete *Diter;
            *Diter = nullptr;
            Diter = D.erase(Diter);
        }
        else
            Diter++;
    }
}
void Factory::factory_ui_delete_small()
{
    for(Diter = D.begin();Diter != D.end();)
    {
        if(typeid(**Diter).name() == typeid(DeviceSmall).name())
        {
            delete *Diter;
            *Diter = nullptr;
            Diter = D.erase(Diter);
        }
        else
            Diter++;
    }
}

//添加，与ui的交互，传入一个数据集合add
void Factory::factory_ui_add(DeviceLargeInfo &add)
{
    DeviceLarge *d = new DeviceLarge(add);  //新建一个设备,调用构造函数
    D.push_back(d);
}
void Factory::factory_ui_add(DeviceSmallInfo &add)
{
    DeviceSmall *d = new DeviceSmall(add);
    D.push_back(d);
}

//排序操作
void Factory::factory_ui_sort(int sel)
{
    /*实现原理:首先使用DL与DS两个指针容器分别指向容器D的Large与Small类型,然后使用sort函数进行排序
      这样对两者特有的成员排序不会出现问题*/
    vector<DeviceLarge *> DL;
    vector<DeviceSmall *> DS;
    //首先将大小设备分开，仅仅是指针指向，利于排序
    if(sel > 10)
        for(Diter = D.begin(); Diter != D.end(); Diter++)
        {
            if(typeid(**Diter).name() == typeid(DeviceLarge).name())
                DL.push_back(static_cast<DeviceLarge*>(*Diter));
            else
                DS.push_back(static_cast<DeviceSmall*>(*Diter));
        }
    //调用sort排序
    switch(sel)
    {
    case 1:
        sort(D.begin(),D.end(),compare_type);
        break;
    case 2:
        sort(D.begin(),D.end(),compare_oid);
        break;
    case 3:
        sort(D.begin(),D.end(),compare_oem);
        break;
    case 4:
        sort(D.begin(),D.end(),compare_work);
        break;
    case 5:
        sort(D.begin(),D.end(),compare_condition);
        break;
    case 11:
        sort(DL.begin(),DL.end(),compare_pfail_large);
        break;
    case 12:
        sort(DL.begin(),DL.end(),compare_port_in_large);
        break;
    case 13:
        sort(DL.begin(),DL.end(),compare_port_out_large);
        break;
    case 14:
        sort(DL.begin(),DL.end(),compare_efficiency_large);
        break;
    case 15:
        sort(DL.begin(),DL.end(),compare_temperature_large);
        break;
    case 21:
        sort(DS.begin(), DS.end(),compare_revert_small);
        break;
    case 22:
        sort(DS.begin(), DS.end(),compare_user_small);
        break;
    case 23:
        sort(DS.begin(), DS.end(),compare_start_date_small);
        break;
    case 24:
        sort(DS.begin(), DS.end(),compare_end_date_small);
        break;
    default:
        break;
    }
    //将排好序后的指针所指向的位置重新赋给vector D
    if(sel > 10)
    {
        int i = 0, j = 0;
        for(Diter = D.begin(); Diter != D.end(); Diter++)
        {
            if(typeid(**Diter).name() == typeid(DeviceLarge).name())
                *Diter = DL[i++];
            else
                *Diter = DS[j++];
        }
    }
    //全程只有指针指向内存的操作，速度较快
}
//输出一个设备的信息,num指该类设备输出个数,初始置零，输出当前Diter的数据，返回0即访问完，返回1代表还有数据
int Factory::factory_ui_show_iter(DeviceLargeInfo& info, int& num)
{
    if (num == 0)   //输出0置Diter为begin
    {
        Diter = D.begin();
        num = 1;
    }

    if (Diter == D.end())   //迭代到end了,退出函数返回0
        return 0;
    //迭代器输出
    while (typeid(**Diter).name() != typeid(DeviceLarge).name())    //不是相应的设备
    {
        Diter++;
        if (Diter == D.end())
            return 0;
    }
    //是需要查找的设备
    static_cast<DeviceLarge*>(*Diter)->read_to_info(info);
    Diter++;    //记得自加
    return 1;   //表示没有到end
}
int Factory::factory_ui_show_iter(DeviceSmallInfo& info, int& num)
{
    if (num == 0)
    {
        Diter = D.begin();
        num = 1;
    }
    //进函数前要将Diter指为开始
    if (Diter == D.end())
    {
        return 0;
    }

    while (typeid(**Diter).name() != typeid(DeviceSmall).name())
    {
        Diter++;
        if (Diter == D.end())
            return 0;
    }

    static_cast<DeviceSmall*>(*Diter)->read_to_info(info);
    Diter++;
    return 1;
}
//输出某一行的数据，采用随机访问的形式，行数为num(从0开始)，返回0表示该行设备不是需要的类型(Large or Small)，1表示是,并会写入引用info中
int Factory::factory_ui_show_line(DeviceLargeInfo &info, int num)
{
    if(typeid(*D[num]).name() != typeid(DeviceLarge).name())
        return 0;
    else
    {
        static_cast<DeviceLarge *>(D[num])->read_to_info(info);
        return 1;
    }
}
int Factory::factory_ui_show_line(DeviceSmallInfo &info,int num)
{
    if(typeid(*D[num]).name() != typeid(DeviceSmall).name())
        return 0;
    else
    {
        static_cast<DeviceSmall *>(D[num])->read_to_info(info);
        return 1;
    }
}

//修改操作,loction指在vector中的位置
void Factory::factory_ui_amend(int location,DeviceLargeInfo &info)
{
    static_cast<DeviceLarge*>(D[location])->amend_device(info);
}
void Factory::factory_ui_amend(int location,DeviceSmallInfo &info)
{
    static_cast<DeviceSmall*>(D[location])->amend_device(info);
}

//删除操作，调用该函数会保存到文件中，以oid参数查找，如果没有相应的设备，则不进行操作
void Factory::factory_ui_delete(string oid)
{
    for(Diter = D.begin(); Diter != D.end();)
    {
        if((*Diter)->find_info(oid))    //找到了该设备
        {
            delete *Diter;  //删除设备,释放内存
            *Diter = nullptr;
            Diter = D.erase(Diter); //在vector中删除该指针 Diter会自加
            break;
        }
        else
            Diter++;
    }
    write_to_file();   //写入到文件
}
//查找操作，可以查找type，oem，oid，user，date等等，返回行数nRow，有多个都会写入容器nRow
void Factory::factory_ui_find(string find,vector<int> &nRow)
{
    int i = 0;
    for(Diter = D.begin();Diter != D.end();Diter++, i++)
    {
        if((*Diter)->find_info(find))   //有该设备
            nRow.push_back(i);
    }
}

//读取实时数据
/*刷新RT文件*/
void Factory::write_RTfile()
{
    ofstream RTFileWrite;
    ifstream RTFile;

    //写数据
    RTFileWrite.open("file/RTFile.csv", ios::out | ios::trunc);   //覆盖写
    srand(time(0));

    DeviceLargeInfo DL;

    int num = 0;
    while(Factory::GetInstance()->factory_ui_show_iter(DL,num) == 1)
    {

        RTFileWrite << DL.OID;
        for (int j = 0; j < 120; j++)
        {
            RTFileWrite << ',';

    //三个 概率 效率 温度 状况
        float f = rand() / double(RAND_MAX) * 20;  //产生0-20的随机数 float
        RTFileWrite << stof(DL.OID)-10000 << ' ';

        f = rand() / double(RAND_MAX) * 40 + 50;  //产生50-90的随机数 float
        RTFileWrite << f << ' ';

        f = rand() / double(RAND_MAX) * 200 + 200;  //产生200-400的随机数 float
        RTFileWrite << f << ' ';

        int i = rand() % 10;
        if(i < 1)
            RTFileWrite << "1";
        else
            RTFileWrite << "0";
        }
        RTFileWrite << endl;
    }

    RTFileWrite.close();
}
/*读RT文件*/
void Factory::read_RTfile()
{
    /*读取文件*/
    ifstream RTFile;    //文件对象
    RTFile.open("file/RTFile.csv", ios::in);
    string temp;
    RTinfoString RTtemp;
    vector<RTinfoString> vtemp; //用于临时储存一行的RT数据,以写入allRTdata容器中

    //找到相应该行的数据
    while (getline(RTFile, temp))
    {
        string strin;	//临时储存字符串
        istringstream iss(temp);

        getline(iss, strin, ',');
        RTname.push_back(strin);    //写入行标题(oid)

        for (int i = 0; i < 120; i++)
        {
            getline(iss, strin, ' ');
            RTtemp.PFail = strin;   //当没有RT数据时，所有的数据都为-1

            getline(iss, strin, ' ');
            RTtemp.efficiency = strin;

            getline(iss, strin, ' ');
            RTtemp.temperture = strin;

            getline(iss, strin, ',');
            RTtemp.condition = (strin == "1" ? "是" : "否");

            //getline(iss, strin, ',');
            vtemp.push_back(RTtemp);
        }
        allRTdata.push_back(vtemp);
        vtemp.clear();
    }
    RTFile.close();
    vector<RTinfoString>().swap(vtemp); //清空vtemp容器
}

//实时数据从写入vector
void Factory::factory_ui_RTinfo_to_ui(int refreshCol)
{
    RTinfoString RTtemp;
    for(int i = 0; i < D.size();i++)    //每一个RTname中的设备（保存oid）
    {
        for(int j = 0; j < RTname.size(); j++)   //找到相对应的设备在vector里的下标
        {
            if(D[i]->find_info(RTname[j]))  //RTname[i]中的名字（oid）与D[j]中的相同
            {
                if(!(D[i]->working()))  //该设备没有工作
                    continue;

                //RTname的下标与allRTdata相同，两者对应
                RTinfoString RTtemp;
                RTtemp.condition = allRTdata[j][refreshCol].condition;
                RTtemp.PFail = allRTdata[j][refreshCol].PFail;
                RTtemp.efficiency = allRTdata[j][refreshCol].efficiency;
                RTtemp.temperture = allRTdata[j][refreshCol].temperture;

                //写入vector,将该行的RT数据写入相应的vector中的行
                static_cast<DeviceLarge *>(D[i])->RT_refresh(RTtemp);
            }
        }
    }
}
//给出该oid在allRTdata中的行数
int Factory::factory_ui_RTinfo_find_row(int vectorRow)
{
    //找到设备的位置
    Diter = D.begin();
    do{
        while(typeid(**Diter).name() != typeid(DeviceLarge).name())
            Diter++;
    }while(vectorRow--);

    if(!((*Diter)->working()))//没有工作，返回-1
        return -1;

    for(int j = 0; j < RTname.size(); j++)   //找到相对应的设备在vector里的下标
    {
        if((*Diter)->find_info(RTname[j]))  //RTname[i]中的名字（oid）与D[j]中的相同
        {
            return j;
        }
    }
    return -1;
}
//输出每一行的实时数据，输入nRow是行数，输出到RTtemp中
bool Factory::factory_ui_RTinfo_to_ui_line(RTinfoString &RTtemp,int nRow,int refreshCol)
{
    if(nRow < 0 || nRow >= allRTdata.size() || allRTdata[nRow][refreshCol].PFail == "-1") //超出了allRTdata的范围或者为空
        return false;

    RTtemp.PFail = allRTdata[nRow][refreshCol].PFail;
    RTtemp.condition = allRTdata[nRow][refreshCol].condition;
    RTtemp.efficiency = allRTdata[nRow][refreshCol].efficiency;
    RTtemp.temperture = allRTdata[nRow][refreshCol].temperture;
    return true;
}

/*排序部分*/
bool compare_type(DeviceInfo* s1, DeviceInfo* s2)
{
    return s1->type < s2->type;
}
bool compare_oid(DeviceInfo* s1, DeviceInfo* s2)
{
    return s1->OID < s2->OID;
}
bool compare_oem(DeviceInfo* s1, DeviceInfo* s2)
{
    return s1->OEM < s2->OEM;
}
bool compare_work(DeviceInfo* s1, DeviceInfo* s2)
{
    return s1->work < s2->work;
}
bool compare_condition(DeviceInfo* s1, DeviceInfo* s2)
{
    return s1->condition > s2->condition;
}
//Large特有
bool compare_port_in_large(DeviceLarge* s1, DeviceLarge* s2)
{
    return s1 -> port_in > s2 -> port_in;
}
bool compare_port_out_large(DeviceLarge* s1, DeviceLarge* s2)
{
    return s1 ->port_out > s2 ->port_out;
}
bool compare_pfail_large(DeviceLarge* s1, DeviceLarge* s2)
{
    return s1 ->PFail > s2 ->PFail ;
}
bool compare_efficiency_large(DeviceLarge* s1, DeviceLarge* s2)
{
    return s1 ->efficiency > s2 ->efficiency ;
}
bool compare_temperature_large(DeviceLarge* s1, DeviceLarge* s2)
{
    return s1 ->temperture > s2 ->temperture ;
}

//Small特有
bool compare_revert_small(DeviceSmall* s1, DeviceSmall* s2)
{
    return s1 ->revert < s2 ->revert ;
}
bool compare_user_small(DeviceSmall* s1, DeviceSmall* s2)
{
    return s1 ->user < s2 ->user ;
}
bool compare_start_date_small(DeviceSmall* s1, DeviceSmall* s2)
{
    return s1 ->start_date < s2 ->start_date ;
}
bool compare_end_date_small(DeviceSmall* s1, DeviceSmall* s2)
{
    return s1 ->end_date < s2 ->end_date ;
}

