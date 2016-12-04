
//
//
//  main.h
//  C
//
//  Created by wongziihou on 2/12/16.
//  Copyright © 2016 wongziihou. All rights reserved.
//
#include "DataBase.hpp"
#define OUTSCANFAGAIN(obj, dline, uline) {if(obj<dline||obj>uline){printf("输入错误,请重新输入\n");continue;}}

int list[1500];				//名单,里面保存的是学生的下标
int list2[1500];
int list3[1500];
int n;
int i;                      //for
int temp,temp2;
char *temp3;
Chart form1;
Chart *OperateChart;




void SortList();
void SearchStudentByUnit();
void AddNewInformationUnit();
void DeleteInformationUnit();
void AddNewStudent();
void ChangeStudentInformation();
void DeleteAStudentFromList();
void ReadFromFile();
void WriteToFile();







//
//
//
//     printf("\n取得第n个人的姓名\n");
//     printf("%s\n", GetString(list, n-1, SearchHeadIndex("姓名")));
//     printf("将数据保存到new.ini\n");
//     WriteIni("new.ini", list, n);
//     */
//    printf("\n删除成绩1列\n");
//    DeleteUnit(SearchHeadIndex("成绩1"));
//    display(list, n);
//
//    //释放内存之后,不能再对表进行操作
//    DestroyStudentList();
//    system("pause");

int main() {
    
    ReadIni("data.ini", OperateChart);		//读取data.ini
    GetList(list, &n);
    
    int mode = 0;
    
    
    printf(" 0.显示所有学生信息\n"
           " 1.排序\n"
           " 2.查找学生\n"
           " 3.新增数据列\n"
           " 4.删除数据列\n"
           " 5.新增学生\n"
           " 6.修改学生信息\n"
           " 7.删除指定学生\n"
           " 8.读取学生信息\n"
           " 9.保存学生信息\n"
           "-1.退出"
           );
    while(scanf("%d",&mode),mode==-1){                                          //当输入mode
        switch (mode) {
            case 0://"0.显示所有学生信息"//缺循环，单独选择显示一个或多个学生信息表，退出
                display(list, n, 1);
                break;
                
            case 1://"1.排序"
                SortList();//允许排任何一列数据列，支持升降序使用                                   //完成
                break;
                
            case 2://"2.查找学生"
                SearchStudentByUnit();//缺循环，第二条件，第三条件，无限条件，退出
                break;
                
            case 3://"3.新增数据列\n"//缺循环，同时新增多个数据列，退出
                AddNewInformationUnit();
                break;
                
            case 4://"4.删除数据列\n"//缺循环，同时删除多个数据列，退出
                DeleteInformationUnit();
                break;
                
            case 5://"5.新增学生\n"//缺循环，同时新增多个学生，退出
                AddNewStudent();
                break;
                
            case 6://"6.修改学生信息\n"//缺循环，同时修改多个学生的信息，同时修改学生的多个信息，退出
                ChangeStudentInformation();
                break;
                
            case 7://"7.删除指定学生\n"//缺循环，同时修删除多个指定学生的同一个信息，同时删除同一个学生的多个指定信息，退出
                DeleteAStudentFromList();
                break;
                
            case 8://"8.读取学生信息\n"//缺循环，同时读取多个文件，退出
                ReadFromFile();
                break;
                
            case 9://"9.保存学生信息\n"//缺循环,同时保持多个学生信息表，退出
                WriteToFile();
                break;
                
        }
    }
    return 0;
}

//#define OUTSCANFAGAIN(obj, dline, uline) {if(obj<dline||obj>uline){printf("输入错误,请重新输入\n");continue;}}
void SortList() {
    
    int order;
    int sortbase;
A:                                                                      //标记A
    while(printf(   "0.升序排序\n"
                    "1.降序排序\n"
                    "-1.退出\n\n"),
          scanf("%d", &order), order!=-1) {                      //当输入为-1时,直接跳出
        OUTSCANFAGAIN(order, -1, 1);                            //判断order是否越界,若越界则重新输入
        while (1) {                                             //order必为0或1
            for (i = 0; i < form1.TitleCount; i++) {                   //显示选项
                printf("%d.%s\n", i, form1.ChartTitle[i]);
            }
            scanf("%d", &sortbase);
            switch (order) {
                    
                case 1:                                         //order -> 0 对应 case 1.升序排序
                    OUTSCANFAGAIN(sortbase, 0, form1.TitleCount);      //判断sortbase是否越界,若越界则重新输入
                    Sort(list, n, sortbase, 0);
                    goto A;
                    
                case 2:                                         //order -> 1 对应 case 2.降序排序
                    OUTSCANFAGAIN(sortbase, 0, form1.TitleCount);
                    Sort(list, n, sortbase, 1);
                    goto A;
            }
        }
    }
}

void SearchStudentByUnit() {
    
    int order;
    char searchunit[16];
    char destin;
    
    while(printf("0.kai shi\n"
                 "1.降序排序\n"
                 "-1.退出\n\n"),
          scanf("%d", &order), order!=-1) {
        
    }
        
    //缺循环，第二条件，第三条件，无限条件，退出
    printf("请输入所需寻找的单元(如:姓名,成绩1)\n");
    scanf("%s", searchunit);
    printf("输入所需寻找的信息(如:张三,64)\n");
    scanf("%s", &destin);
    
    temp=Search(list, n, list2, SearchHeadIndex(searchunit), &destin);
    display(list2, n, 0);
    
    
    return;
}
void AddNewInformationUnit() {
    
    char title[16], defaul;
    int unitlimits;
    
    
    printf("请输入:所添加的单元 单元字节范围 初始值\n");
    scanf("%s %d %c", title, &unitlimits, &defaul);
    
    NewUnit(title, unitlimits, defaul);
    display(list, n, 0);
    
    return;
}
void DeleteInformationUnit() {
    char title[16];
    
    printf("请输入:所删除的单元名字\n");
    scanf("%s", title);
    
    DeleteUnit(SearchHeadIndex(title));
    display(list, n, 0);
    
    return;
}
void AddNewStudent() {
    //     printf("\n新增一个学生\n");
    //     NewStudent(list, &n);
    //     display(list, n);
    
    NewStudent(list, &n);
    printf("\n已新增一个学生\n");
    display(list, n, 0);
   
    return;
    
}
void ChangeStudentInformation() {
    
    char getunit[16];
    int list_id;
    char information[16];
    
    display(list, n, 1);
    
    printf("请输入所需更改的单元\n");
    scanf("%s", getunit);
    printf("请输入所需更改的序号\n");
    scanf("%d", &list_id);
    printf("请输入更改的内容\n");
    scanf("%s", information);
    
    temp3 = GetString(list, list_id, SearchHeadIndex(getunit));
    strcpy(temp3, information);
    display(list, n, 1);
    
    return;
    
}
void DeleteAStudentFromList() {
    
    int studentnumber, mode;
    
    printf("请输入所需删除学生所有信息的序号\n");
    scanf("%d", &studentnumber);
    printf("请选择:\n"
           "0.未排序\n"
           "1.已排序\n"
           );
    switch (mode) {
        case 0:
            DeleteStudentInList(list, &n, studentnumber, 0);
            
            display(list, n, 1);
            break;
            
        case 1:
            DeleteStudentInList(list, &n, studentnumber, 0);
            display(list, n, 1);
            break;
    }
    
    return;
}
void ReadFromFile() {
    

    char filename;
    printf("请输入所需读取的文件名字,如(data.ini)");
    scanf("%s", &filename);
    
    ReadIni(&filename, OperateChart);       //读取data.ini
    GetList(list, &n);    		//取得一个名单
    
    return;
}
void WriteToFile() {
    
    char filename;
    
    printf("请输入所需读取的文件名字,如(data.ini)");
    scanf("%s", &filename);
    
    WriteIni(&filename, list, n);
    
    return;
    
}   





