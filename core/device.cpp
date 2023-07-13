#pragma once
#include "device.h"
#include <sstream>

//是否工作
bool DeviceInfo::working()
{
    return this->work;
}

//用于修改设备信息，将传入的add信息赋值到当前的类中
void DeviceSmall::amend_device(DeviceSmallInfo &add)
{
    this->type = add.type;
    this->OEM = add.OEM;
    this->OID = add.OID;
    this->work = add.work;
    this->condition = add.condition;
    this->revert = add.revert;
    this->user = add.user;
    this->start_date = add.start_date;
    this->end_date = add.end_date;
}
void DeviceLarge::amend_device(DeviceLargeInfo &add)
{
    this->type = add.type;
    this->OEM = add.OEM;
    this->OID = add.OID;
    this->work = add.work;
    this->condition = add.condition;
    this->PFail = add.PFail;
    this->port_in = add.port_in;
    this->port_out = add.port_out;
    this->efficiency = add.efficiency;
    this->temperture = add.temperture;
}

//从文件读入，一次读取一行,从文件传输流iss中读取,传入参数line是一行所有的数据
int DeviceLarge::read_from_file(string& line)
{
    istringstream iss(line);    //将line中的数据写入传输流iss中，以在后续中进行截取
    string strin;	//临时储存字符串

    getline(iss, strin, ',');
    this->type = strin;

    getline(iss, strin, ',');
    this->OID = strin;

    getline(iss, strin, ',');
    this->OEM = strin;

    getline(iss, strin, ',');
    this->work = (strin == "0") ? false : true; //转布尔型

    getline(iss, strin, ',');
    this->condition = (strin == "0") ? false : true;

    getline(iss, strin, ',');
    this->PFail = stof(strin);	//转浮点型

    getline(iss, strin, ',');
    this->port_in = strin;

    getline(iss, strin, ',');
    this->port_out = strin;

    getline(iss, strin, ',');
    this->efficiency = stof(strin);

    getline(iss, strin, ',');
    this->temperture = stof(strin);

    return 0;
}
int DeviceSmall::read_from_file(string &line)
{
    istringstream iss(line);
    string strin;	//临时储存字符串
    //以逗号为分隔符分开所有数据，并写入现在的对象中this，内部需要string对其他的转换
    getline(iss, strin, ',');
    this->type = strin;

    getline(iss, strin, ',');
    this->OID = strin;

    getline(iss, strin, ',');
    this->OEM = strin;

    getline(iss, strin, ',');
    this->work = (strin == "0") ? false : true;

    getline(iss, strin, ',');
    this->condition = (strin == "0") ? false : true;

    getline(iss, strin, ',');
    this->revert = (strin == "0") ? false : true;

    getline(iss, strin, ',');
    this->user = strin;

    getline(iss, strin, ',');
    this->start_date = strin;

    getline(iss, strin, ',');
    this->end_date = strin;
    return 0;
}
//写入文件，一次一行
int DeviceLarge::write_to_file(ofstream &LFile)
{
    LFile << *this; //<<被重载过，要写入一个对象
    return 0;
}
int DeviceSmall::write_to_file(ofstream &SFile)
{
    SFile << *this;
    return 0;
}
//将现在这个对象this写入info，以供Factory类调用
void DeviceLarge::read_to_info(DeviceLargeInfo &info)
{
    info.type = this->type;
    info.OEM = this->OEM;
    info.OID = this->OID;
    info.work = this->work;
    info.condition = this->condition;
    info.PFail = this->PFail;
    info.efficiency = this->efficiency;
    info.port_in = this->port_in;
    info.port_out = this->port_out;
    info.temperture = this->temperture;
}
void DeviceSmall::read_to_info(DeviceSmallInfo &info)
{
    info.type = this->type;
    info.OEM = this->OEM;
    info.OID = this->OID;
    info.work = this->work;
    info.condition = this->condition;
    info.revert = this->revert;
    info.user = this->user;
    info.start_date = this->start_date;
    info.end_date = this->end_date;
}
//查找this（当前对象）里的设备，传入参数find是要查找的数据的字符串，查找成功返回true
bool DeviceLarge::find_info(string &find)
{
    if(this->type == find || this->OID == find || this->OEM == find || this->port_in == find || this->port_out == find)
        return true;
    else
        return false;
}
bool DeviceSmall::find_info(string &find)
{
    if(this->type == find || this->OID == find || this->OEM == find || this->user == find || this->start_date == find || this->end_date == find)
        return true;
    else
        return false;
}
//刷新vector里RT数据，RTtemp里的数据都是字符串string
void DeviceLarge::RT_refresh(RTinfoString& RTtemp)
{
    this->PFail = stof(RTtemp.PFail);
    this->efficiency = stof(RTtemp.efficiency);
    this->temperture = stof(RTtemp.temperture);
    this->condition = RTtemp.condition == "是" ? true : false;
}

//运算符重载，用于输出到文件，传入一个对象的引用*this
ostream& operator<<(ostream& os, DeviceSmall& m)
{
    os << m.type << ',' << m.OID << ',' << m.OEM << ',' << m.work << ',' << m.condition << ',';
    os << m.revert << ',' << m.user << ',' << m.start_date << ',' << m.end_date << endl;

    return os;
}
ostream& operator<<(ostream& os, DeviceLarge& m)
{
    os << m.type << ',' << m.OID << ',' << m.OEM << ',' << m.work << ',' << m.condition << ',';
    os << m.PFail << ',' << m.port_in << ',' << m.port_out << ',' << m.efficiency << ',' << m.temperture << endl;

    return os;
}

