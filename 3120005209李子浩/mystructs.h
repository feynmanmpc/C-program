// 本系统所用结构体
#ifndef TASK5_HEA_H     // 防止头文件在同一编译单元被重复引用
#define TASK5_HEA_H

/*学生打卡信息结构体*/
struct clockData {
    char id[20];            // 学号
    char className[20];     // 班级
    char name[20];          // 姓名
    char clockInDate[30];   // 打卡日期 年.月.日 2020.12.21
} cData;


// 班级内学生打卡统计
struct ClassClockTotal{
    char id[20];    // 学号
    char name[20];  // 学生姓名
    int clockCount; // 打卡次数
}classClockTotal[50];
int classClockTotalCount = 0;    // 统计个数

#endif //TASK5_HEA_H
