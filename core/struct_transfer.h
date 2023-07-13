#ifndef STRUCT_TRANSFER_H
#define STRUCT_TRANSFER_H
#pragma once
#include <iostream>
//用于数据传输,接口数据
typedef struct
{
    std::string type;	//设备类型
    std::string OID;	//设备OID
    std::string OEM;	//设备厂家
    bool work;	//是否投入使用,0为未使用，1为使用
    bool condition;	//是否故障，0为正常，1为故障
    std::string user;	//使用者
    std::string start_date;	//开始使用日期
    std::string end_date;	//归还日期
    bool revert;	//是否归还，归还为true

}DeviceSmallInfo;

typedef struct
{
    std::string type;	//设备类型
    std::string OID;	//设备OID
    std::string OEM;	//设备厂家
    bool work;	//是否投入使用,0为未使用，1为使用
    bool condition;	//是否故障，0为正常，1为故障
    std::string port_in;	//输入接口类型
    std::string port_out;	//输出接口类型
    float PFail;	//损坏概率
    float efficiency;	//效率，表示为89.1，无百分号
    float temperture;	//温度
}DeviceLargeInfo;

typedef struct
{
    std::string efficiency;
    std::string temperture;
    std::string PFail;
    std::string condition;
}RTinfoString;

#endif // STRUCT_TRANSFER_H
