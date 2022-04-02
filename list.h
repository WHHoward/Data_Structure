#include "def.h"
status InitList(SqList& L)
{
    if(!L.elem)
    {
        L.elem=(ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else
        return INFEASIBLE;
}

status DestroyList(SqList& L)
{
    if(L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        return OK;
    }
    else
        return INFEASIBLE;
}


status ClearList(SqList& L)
{
    if(L.elem)
    {
        free(L.elem);
        L.length = 0;
        return OK;
    }
    else 
        return INFEASIBLE;
}

status ListEmpty(SqList L)
{
    if(!L.elem) return INFEASIBLE;
    else
    {
        if(L.length)    return FALSE;
        else    return TRUE;
    }
}

status ListLength(SqList L)
{
    if(L.elem)  return L.length;
    else    return INFEASIBLE;
}

status GetElem(SqList L,int i,ElemType &e)
{
    if(L.elem)
    {
        if(i <= 0 or i > L.length)   return ERROR;
        e = L.elem[i-1];
        return OK;
    }
    return INFEASIBLE;
}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        for(int i = 0; i < L.length; i++)
            if(L.elem[i] == e)  return i + 1;
        return 0;   
    }
    return INFEASIBLE;
    /********** End **********/
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        for(int i = 0; i < L.length; i++)
        {
            if(L.elem[i] == e)
                if(i != 0)
                {
                    pre = L.elem[i - 1];
                    return OK;
                }
                else
                    return ERROR;
        }
        return ERROR;
    }
    return INFEASIBLE;

    /********** End **********/
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        for(int i = 0; i < L.length; i++)
        {
            if(L.elem[i] == e)
                if(i != L.length - 1)
                {
                    next = L.elem[i + 1];
                    return OK;
                }
                else
                    return ERROR;
        }
        return ERROR;
    }
    return INFEASIBLE;

    /********** End **********/
}

status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L.elem) return INFEASIBLE;
    else
    {
        if(i <= 0 or i > L.length + 1)     return ERROR;
        else
        {
            if(L.length == L.listsize)  
            {
                int *temp;
                temp = (int *)realloc(L.elem,sizeof(int) * (L.listsize + LISTINCREMENT));
                if(temp)    L.elem = temp;
                L.listsize += LISTINCREMENT;
            }
            for(int j = L.length; j >= i; j--)
                L.elem[j] = L.elem[j - 1];
            L.elem[i - 1] = e;
            L.length++;
            return OK;
        }
    }
    /********** End **********/
}

status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L.elem)     return INFEASIBLE;
    else
    {
        if(i <= 0 or i > L.length)  return ERROR;
        else
        {
            e = L.elem[i - 1];
            for(int j = i; j < L.length; j++)
                L.elem[j - 1] = L.elem[j];
            L.length--;
            return OK;
        }
    }  

    /********** End **********/
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L.elem) return INFEASIBLE;
    else
    {
        for(int i = 0; i < L.length - 1; i++)
            printf("%d ",L.elem[i]);
        if(L.length != 0)
        printf("%d",L.elem[L.length - 1]);
        return OK;
    }

    /********** End **********/
}

status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L.elem) return INFEASIBLE;
    FILE *p;
    p = fopen(FileName,"w");
    for(int i = 0; i < L.length; i++)
        fprintf(p,"%d",L.elem[i]);
    fclose(p);
    return OK;
    /********** End **********/
}

status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)  return INFEASIBLE;
    else
    {
        L.elem = (int *)malloc(sizeof(int) * L.listsize);
        FILE *p;
        p = fopen(FileName,"r");
        int temp;
        int cnt = 1;
        return OK;
        while(fscanf(p,"%d",&temp))
        {
            ListInsert(L,cnt++,temp);
            return OK;
        }
        fclose(p);
        return OK;
    }

    /********** End **********/
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    SqList temp;
    temp.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
    temp.length = 0;
    temp.listsize = LIST_INIT_SIZE;
    Lists.elem[Lists.length++].L = temp;
    strcpy(Lists.elem[Lists.length-1].name,ListName);
    /********** End **********/
}

#include<string.h>
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i = 0; i < Lists.length; i++)
    {
        if(strcmp(Lists.elem[i].name,ListName) == 0)
        {
            for(int j = i; j < Lists.length - 1; j++)
                Lists.elem[j] = Lists.elem[j + 1];
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
    /********** End **********/
}

#include<string.h>
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i = 0; i < Lists.length; i++)
    {
        if(strcmp(Lists.elem[i].name,ListName) == 0)
            return i + 1;
    }
    return 0;

    /********** End **********/
}
