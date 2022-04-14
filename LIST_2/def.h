#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;

typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

struct lists
{
    char name[30];
    LinkList L;
};
typedef struct LISTS
{
    lists L;
    LISTS *next;
}ListsNode,*ListsGroup;
/*struct lists
{
    char name[30];
    SqList L;
};
struct LISTS{  //线性表的管理表定义
    lists elem[100];
    int length;
    int listsize;
};
*/