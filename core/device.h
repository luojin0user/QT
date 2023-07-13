#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>

#include "struct_transfer.h"

using namespace std;

//把这个看出基类，类型是他的派生类，基类排序，虚函数，友元 设备信息类
class DeviceInfo
{
protected:
	string type;	//设备类型
	string OID;	//设备OID
	string OEM;	//设备厂家
	bool work;	//是否投入使用,0为未使用，1为使用
    bool condition;	//是否故障，0为正常，1为故障

public:
    DeviceInfo(){}
    DeviceInfo(DeviceSmallInfo& init)
    {
        type = init.type;
        OID = init.OID;
        OEM = init.OEM;
        work = init.work;
        condition = init.condition;
    }
    DeviceInfo(DeviceLargeInfo& init)
    {
        type = init.type;
        OID = init.OID;
        OEM = init.OEM;
        work = init.work;
        condition = init.condition;
    }
    virtual ~DeviceInfo(){} //虚析构函数，用于指针调用各派生类的析构函数

    virtual int write_to_file(ofstream&) = 0;   //写入文件，一次一行
    virtual int read_from_file(string&) = 0;	//从文件读入，一次读取一行,从文件传输流iss中读取,传入参数line是一行所有的数据
    virtual bool find_info(string&) = 0;    //查找this（当前对象）里的设备，传入参数find是要查找的数据的字符串，查找成功返回true
    bool working(); //是否工作，工作返回true

    //排序
    friend bool compare_type(DeviceInfo* s1, DeviceInfo* s2);
    friend bool compare_oid(DeviceInfo* s1, DeviceInfo* s2);
    friend bool compare_oem(DeviceInfo* s1, DeviceInfo* s2);
    friend bool compare_work(DeviceInfo* s1, DeviceInfo* s2);
    friend bool compare_condition(DeviceInfo* s1, DeviceInfo* s2);
};

//小型设备，无接口
class DeviceSmall :public DeviceInfo
{
public:
    DeviceSmall():DeviceInfo(){}
    DeviceSmall(DeviceSmallInfo& init):DeviceInfo(init)
    {
        user = init.user;
        start_date = init.start_date;
        end_date = init.end_date;
        revert = init.revert;
        condition = init.condition;
    }
    ~DeviceSmall(){}
    void amend_device(DeviceSmallInfo&);    //用于修改设备信息，将传入的add信息赋值到当前的类中
    void read_to_info(DeviceSmallInfo&);    //将当前对象的数据写入info中
    int write_to_file(ofstream&);
    int read_from_file(string&);
    bool find_info(string&);    //查找自己现在的位置是否有string的oid等等，有则返回true

    //排序
    friend bool compare_revert_small(DeviceSmall* s1, DeviceSmall* s2);
    friend bool compare_user_small(DeviceSmall* s1, DeviceSmall* s2);
    friend bool compare_start_date_small(DeviceSmall* s1, DeviceSmall* s2);
    friend bool compare_end_date_small(DeviceSmall* s1, DeviceSmall* s2);

    friend ostream& operator<<(ostream& os, DeviceSmall& m);

private:
	string user;	//使用者
	string start_date;	//开始使用日期
	string end_date;	//归还日期
	bool revert;	//是否归还，归还为true
};

//固定资产设备（大型设备），生产设备，有接口
class DeviceLarge :public DeviceInfo
{
public:
    DeviceLarge():DeviceInfo(){}
    DeviceLarge(DeviceLargeInfo &init):DeviceInfo(init)
    {
        port_in = init.port_in;
        port_out = init.port_out;
        PFail = init.PFail;
        efficiency = init.efficiency;
        temperture = init.temperture;
        //-1代表没有值
    }
    ~DeviceLarge(){}
    void amend_device(DeviceLargeInfo&);    //用于修改设备信息，将传入的add信息赋值到当前的类中
    int write_to_file(ofstream&);
    int read_from_file(string&);
    void read_to_info(DeviceLargeInfo&);    //将当前对象的数据写入info中
    bool find_info(string&);

    void RT_refresh(RTinfoString&); //刷新vector里实时RT数据

    //排序
    friend bool compare_port_in_large(DeviceLarge* s1, DeviceLarge* s2);
    friend bool compare_port_out_large(DeviceLarge* s1, DeviceLarge* s2);
    friend bool compare_pfail_large(DeviceLarge* s1, DeviceLarge* s2);
    friend bool compare_efficiency_large(DeviceLarge* s1, DeviceLarge* s2);
    friend bool compare_temperature_large(DeviceLarge* s1, DeviceLarge* s2);

    friend ostream& operator<<(ostream& os, DeviceLarge& m);    //输出到文件的os运算符重载

private:
	string port_in;	//输入接口类型
	string port_out;	//输出接口类型
	float PFail;	//损坏概率
	float efficiency;	//效率，表示为89.1，无百分号
	float temperture;	//温度
};

