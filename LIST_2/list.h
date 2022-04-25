#include "def.h"

status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(!L)
    {
        L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        return OK;
    }
    else
        return INFEASIBLE;
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        LinkList tm = L;
        LinkList temp = L;
        L = L->next;
        while(L)
        {
            temp = L->next;
            free(L);
            L = temp;
        }
        L = tm;
        L->next = NULL;
        L = NULL;
        return OK;
    } 
}


status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        LinkList tm = L;
        LinkList temp = L;
        L = L->next;
        while(L)
        {
            temp = L->next;
            free(L);
            L = temp;
        }
        L = tm;
        L->next = NULL;
        return OK;
    } 
}

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        if(!(L->next))  return TRUE;
        return FALSE;
    }
}

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        int cnt = 0;
        LinkList temp;
        temp = L->next;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
}

status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        int cnt = ListLength(L);
        if(i <= 0 or i > cnt)   return ERROR;
        else
        {
            int temp = 0;
            L = L->next;
            while(1)
            {
                temp++;
                if(temp == i)
                {
                    e = L->data;
                    break;
                }
                L = L->next;
            }
        }
        return OK;
    }
}

status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        int cnt = 0;
        L = L->next;
        int flag = 0;
        while(L)
        {
            cnt++;
            if(L->data == e)
            {
                flag = 1;
                break;
            }   
            L = L->next;
        }
        if(flag)    return cnt;
        else
            return ERROR;
    }
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        LinkList before;
        before = L;
        if(L->next) L = L->next;
        if(L->data == e)    return ERROR;
        while(L)
        {
            if(L->data == e)    
            {
                pre = before->data;
                return OK;
            }
            L = L->next;
            before = before->next;
        }
        return ERROR;
    }
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        L = L->next;
        while(L)
        {
            if(L->data == e)
            {
                if(!L->next)    return ERROR;
                else
                {
                    next = L->next->data;
                    return OK;
                }
            }
            L = L->next;
        }
        return ERROR;
    }
}

status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L)  return INFEASIBLE;
    else
    {
        LinkList ini = L;
        int cnt = ListLength(L);
        if(i <= 0 or (i > cnt + 1 and cnt > 0))   return ERROR;
        if(cnt == 0)
        {
            if(i != 1)  return ERROR;
            else
            {
                LinkList temp1;
                temp1 = (LinkList)malloc(sizeof(LNode));
                temp1->next = NULL;
                temp1->data = e;
                L->next = temp1;
                L = ini;
                return OK;
            }
        }
        LinkList pre;
        pre = L;
        L = L->next;
        int temp = 1;
        while(L)
        {
            if(temp == i)
            {
                LinkList temp1;
                temp1 = (LinkList)malloc(sizeof(LNode));
                temp1->data = e;
                pre->next = temp1;
                temp1->next = L;
                L= ini;
                return OK; 
            }
            L = L->next;
            pre = pre->next;
            temp++;
        }
        if(cnt + 1 == i)
        {
            LinkList temp1;
            temp1 = (LinkList)malloc(sizeof(LNode));
            temp1->data = e;
            pre->next = temp1;
            temp1->next = NULL;
            L = ini;
            return OK;
        }
        L = ini;
        return ERROR;
    }

    /********** End **********/
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        int cnt = ListLength(L);
        LinkList temp = L;
        if(i <= 0 or i >= cnt + 1)  return ERROR;
        int temp1 = 1;
        LinkList pre = L;
        temp = temp->next;
        while(temp)
        {
            if(temp1 == i)
            {
                e = temp->data;
                pre->next = temp->next;
                free(temp);
                return OK;
            }
            pre = pre->next;
            temp = temp->next;
            temp1++;
        }
        return ERROR;
    }
}

status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        if(ListLength(L) == 0)  return ERROR;
        L = L->next;
        while(L)
        {
            printf("%d ",L->data);
            L = L->next;
        }
        return OK;
    }
}

status ReverseList(LinkList L)
{
    if(!L)  return INFEASIBLE;
    else
    {
        int len = ListLength(L);
        if(!len)    return ERROR;
        LinkList temp;
        temp = NULL;
        InitList(temp);
        for(int i = len; i >= 1; i--)
        {
            int e;
            GetElem(L,i,e);
            ListInsert(temp,len - i + 1,e);
        }
        ClearList(L);
        for(int i = 1; i <= len; i++)
        {
            int e;
            GetElem(temp,i,e);
            ListInsert(L,i,e);
        }
        DestroyList(temp);
        return OK;
    }
}

status RemoveNthFromEnd(LinkList L,int n)
{
    if(!L)  return INFEASIBLE;
    {
        int len = ListLength(L);
        if(n <= 0 or n > len) return ERROR;
        int e;
        ListDelete(L,len - n + 1,e);
        return OK;
    }
}

status SortList(LinkList L)
{
    if(!L)  return INFEASIBLE;
    else
    {
        int len = ListLength(L);
        if(!len)    return ERROR;
        int* temp;
        temp = (int *)malloc(sizeof(int) * (len + 1));
        for(int i = 1; i <= len; i++)
        {
            int e;
            GetElem(L,i,e);
            temp[i] = e;
        }
        ClearList(L);
        std::sort(temp + 1,temp + len + 1);
        for(int i = 1; i <= len; i++)
            ListInsert(L,i,temp[i]);
        free(temp);
        return OK;
    }
}
status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(!L)  return INFEASIBLE;
    else
    {
        FILE *p;
        p = fopen(FileName,"w+");
        if(!p)  return ERROR;
        L = L->next;
        while(L)
        {
            fwrite(&L->data,sizeof(int),1,p);
            L = L->next;
        }
        fclose(p);
        return OK;
    }
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(L)   return INFEASIBLE;
    else
    {
        FILE *p;
        p = fopen(FileName,"r+");
        if(!p)  return ERROR;
        int temp;
        L = (LinkList)malloc(sizeof(LNode));
        LinkList pre = L;
        while(fread(&temp,sizeof(int),1,p))
        {
            LinkList temp1;
            temp1 = (LinkList)malloc(sizeof(LNode));
            temp1->data = temp;
            L->next = temp1;
            L = L->next;
        }
        L->next = NULL;
        L = pre;
        fclose(p);
        return OK;
    }
}

/*
函数名称: AddList_1
函数作用: 将一个空的线性表插入到线性表组L的末尾并为该线性表命名，如果插入成功则返回OK
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称)
函数类型: status
*/
status AddList_1(ListsGroup Lists,char ListName[])
{
    LinkList temp;
    temp = NULL;
    InitList(temp);
    ListsGroup temp2;
    temp2 = Lists->next;
    ListsGroup pri;
    pri = Lists;
    while(temp2)
    {
        temp2 = temp2->next;
        pri = pri->next;
    }
    temp2 = (ListsGroup)malloc(sizeof(ListsNode));
    pri->next = temp2;
    temp2->next = NULL;
    temp2->L.L = temp;
    strcpy(temp2->L.name,ListName);
    return OK;
}
/*
函数名称: AddList_2
函数作用: 将一个已存在的线性表插入到线性表组L的末尾并为该线性表命名，如果插入成功则返回OK，如果该线性表不存在,则返回INFEASIBLE
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称), SqList &L(对线性表的引用)
函数类型: status
*/
int AddList_2(ListsGroup Lists,char ListName[],LinkList L)
{
    if(!L) return INFEASIBLE;
    ListsGroup temp = Lists->next;
    ListsGroup pri = Lists;
    while(temp)
    {
        temp = temp->next;
        pri = pri->next;
    }
    temp = (ListsGroup)malloc(sizeof(ListsNode));
    temp->L.L = L;
    pri->next = temp;
    temp->next = NULL;
    strcpy(temp->L.name,ListName);
    return OK;
}
/*
函数名称: RemoveList
函数作用: 将一个线性表名字为ListName的线性表从线性表组L中删除，如果删除成功则返回OK,如果该线性表不存在则返回ERROR
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称)
函数类型: status
*/
status RemoveList(ListsGroup Lists,char ListName[])
{
    ListsGroup temp = Lists;
    ListsGroup pri = Lists;
    temp = temp->next;
    while(temp)
    {
        if(strcmp(temp->L.name,ListName) == 0)
        {
            pri->next = temp->next;
            free(temp);
            return OK;
        }
        temp = temp->next;
    }
    return ERROR;
}
/*
函数名称: LocateList
函数作用: 查询名字为ListName的线性表在线性表组中的位置,如果查找成功则返回位置,如果不存在则返回ERROR
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称)
函数类型: int
*/
int LocateList(ListsGroup Lists,char ListName[])
{
    int cnt = 0;
    ListsGroup temp;
    temp = Lists;
    temp = temp->next;
    while(temp)
    {
        if(strcmp(temp->L.name,ListName) == 0)
            return cnt+1;
        temp = temp->next;
        cnt++;
    }
    return 0;
}
/*
函数名称: ShowList
函数作用: 展示一个线性表组，如果展示成功则返回OK,如果线性表组长度为0,则返回ERROR
函数参数: LISTS Lists(线性表组),
函数类型: int
*/
int ShowList(ListsGroup Lists)
{
    if(Lists->next == NULL)   return ERROR;
    else
    {
        ListsGroup temp;
        temp = Lists->next;
        int cnt = 1;
        while(temp)
        {
            printf("%d %s\n",cnt++,temp->L.name);
            temp = temp->next;
        }
        return OK;
    }
}
/*
函数名称: SwitchList
函数作用: 将当前线性表切换为线性表组中第i个线性表,如果切换成功则返回OK,如果i非法则返回ERROR
函数参数: LISTS Lists(线性表组),int i(线性表的位置),SqList &L(当前线性表的引用)
函数类型: int
*/
int SwitchList(ListsGroup Lists,int i,LinkList &L)
{
    ListsGroup temp;
    temp = Lists->next;
    int flag = 0;
    int cnt = 1;
    while(temp)
    {
        if(cnt == i)    
        {
            L = temp->L.L;
            flag = 1;
            return OK;
        }
        cnt++;
        temp = temp->next;
    }
    return ERROR;
}
/*
函数名称: UpdateList
函数作用: 将当前线性表更新（覆盖）到线性表组中第i个线性表,如果更新成功则返回OK,如果i非法则返回ERROR
函数参数: LISTS Lists(线性表组),int i(线性表的位置),SqList &L(当前线性表的引用)
函数类型: int
*/
int UpdateList(ListsGroup Lists,int i, LinkList L)
{
    ListsGroup temp;
    temp = Lists->next;
    int flag = 0;
    int cnt = 1;
    while(temp)
    {
        if(cnt == i)
        {
            temp->L.L = L;
            flag = 1;
            return OK;
        }
        temp = temp->next;
        cnt++;
    }
    return ERROR;
}