#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <dirent.h>
#include <memory.h>
#include "mystructs.h"

// 打卡系统用到的文件操作相关函数


/*创建文件夹*/
void createFolder(char *folderName)
{
    // 文件夹不存在则创建文件夹
    if (access(folderName, 0) == -1) 
    {
        mkdir(folderName, 0775);
    }
}

/*将数据写入文件*/
int writeFile(char *fileName, char *data, int mode) 
{
    FILE *file;
    if (mode == 0) 
    {
        file = fopen(fileName, "a+");
    } 
    else 
    {
        file = fopen(fileName, "w+");
    }
    if (file == NULL) 
    {
        printf("文件打开错误!\n");
        return 1;
    }
    fputs(data, file);
    fclose(file);
    return 0;
}

/*读取文件数据并保存到打卡信息结构体*/
void readData(char *fileName) {
    // 遍历数据文件目录，打开文件并加载数据到结构体studentsData
    DIR *dir;
    struct dirent *ptr;
    dir = opendir(fileName);
    FILE *pFile;
    classClockTotalCount = 0;
    while ((ptr = readdir(dir)) != NULL) 
    {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) 
        {
            char readFileName[40];
            sprintf(readFileName, "./%s/%s", fileName, ptr->d_name);
            printf("正在读取%s\n", readFileName);
            // 读取文件数据并保存到结构体
            char mystring[100];
            int dataCount = 0;
            pFile = fopen(readFileName, "r");
            if (pFile == NULL) perror("文件打开错误");
            else {
                while (fgets(mystring, 100, pFile) != NULL) 
                {
                    char *p;
                    p = strtok(mystring, " ");
                    sscanf(p, "%s", cData.id);
                    p = strtok(NULL, " ");
                    sscanf(p, "%s", cData.name);
                    p = strtok(NULL, " ");
                    sscanf(p, "%s", cData.className);
                    p = strtok(NULL, " ");
                    sscanf(p, "%s", cData.clockInDate);
                    dataCount++;
                }
                fclose(pFile);
            }
            sscanf(cData.id, "%s", classClockTotal[classClockTotalCount].id);
            sscanf(cData.name, "%s", classClockTotal[classClockTotalCount].name);
            classClockTotal[classClockTotalCount].clockCount = dataCount;
            classClockTotalCount++;
        }
    }
    closedir(dir);
}

/*添加学生打卡信息*/
void addStudentData(char *filePath) {
    printf("格式：学号 姓名（注：姓名以最后一次打卡输入的为准） 班级 打卡日期\n请输入:");
    struct clockData stu;
    scanf("%s %s %s %s", stu.id, stu.name, stu.className, stu.clockInDate);
    // 根据学生的班级生成文件名，打开数据文件并写入
    char fileName[40];
    sprintf(fileName, "%s/%s.txt", filePath, stu.id);
    printf("%s", fileName);
    // 拼接学生打卡信息
    char data[80];
    sprintf(data, "%s %s %s %s\n", stu.id, stu.name, stu.className, stu.clockInDate);
    // 追加方式写入文件
    writeFile(fileName, data, 0);
    printf("添加成功!(按任意键继续)");
    getchar();
}