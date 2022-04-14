#include "def.h"
/*
函数名称：InitList
函数作用:对（当前表）一个没有被初始化的顺序表进行初始化，如果顺序表初始化成功则返回OK 否则返回INFEASIBLE
函数参数:SqList &L(对一个线性表的引用)
函数类型：status
*/
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
/*
函数名称: DestroyList
函数作用: 对一个已存在的线性表进行销毁，如果销毁成功则返回OK，否则返回INFEASIBLE；
函数参数: SqList &L(对一个线性表的引用)
函数类型: status
*/
status DestroyList(SqList& L)
{
    if(L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else
        return INFEASIBLE;
}

/*
函数名称: ClearList
函数作用: 对一个已存在的线性表进行清空，如果清空成功则返回OK，否则返回INFEASIBLE；
函数参数: SqList &L(对一个线性表的引用)
函数类型: status
*/
status ClearList(SqList& L)
{
    if(L.elem)
    {
        free(L.elem);
        L.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
        L.length = 0;
        return OK;
    }
    else 
        return INFEASIBLE;
}

status ListEmpty(SqList L)
{/*
函数名称: ListEmpty
函数作用: 对一个已存在的线性表查询是否为空，如果为空则返回OK，如钩不为空则返回FALSE,若线性表不存在返回INFEASIBLE；
函数参数: SqList &L(对一个线性表的引用)
函数类型: status
*/
    if(!L.elem) return INFEASIBLE;
    else
    {
        if(L.length)    return FALSE;
        else    return TRUE;
    }
}
/*
函数名称: ListLength
函数作用: 对一个已存在的线性表求其长度，如果求成功则返回其长度，如果线性表不存在返回INFEASIBLE；
函数参数: SqList &L(对一个线性表的引用)
函数类型: status
*/
status ListLength(SqList L)
{
    if(L.elem)  return L.length;
    else    return INFEASIBLE;
}
/*
函数名称: GetElem
函数作用: 对一个已存在的线性表进行对i个元素的查询，并将返回值保存在参数e中，如果查询成功则返回OK，如果参数i非法则返回ERROR，如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，int i(需要查询的位置) ,ElemType &e(用以保存查询到的值)
函数类型: status
*/
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
/*
函数名称: LocateElem
函数作用: 对一个已存在的线性表进行对值为e的元素进行定位，如果定位成功则返回其位置的值，如果没有定位到则返回ERROR，如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，ElemType i(需要定位的元素)
函数类型: status
*/
int LocateElem(SqList L,ElemType e)
{
    if(L.elem)
    {
        for(int i = 0; i < L.length; i++)
            if(L.elem[i] == e)  return i + 1;
        return 0;   
    }
    return INFEASIBLE;
}
/*
函数名称: PriorElem
函数作用: 对一个已存在的线性表进行对值为e的元素进行求其前继元素的地址，如果求成功则返回OK，并将地址值赋给pre，如果没有定位到或没有前继则返回ERROR，如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，ElemType e(需要定位的元素), Elemtype &pre(用于储存前继的位置)
函数类型: status
*/
status PriorElem(SqList L,ElemType e,ElemType &pre)
{
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
}
/*
函数名称: NextElem
函数作用: 对一个已存在的线性表进行对值为e的元素进行求其后继元素的地址，如果求成功则返回OK，并将地址值赋给Next，如果没有定位到或没有后继则返回ERROR，如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，ElemType e(需要定位的元素), Elemtype &Next(用于储存后继的位置)
函数类型: status
*/
status NextElem(SqList L,ElemType e,ElemType &next)
{
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

}
/*
函数名称: ListInsert
函数作用: 对一个已存在的线性表在位置i上插入元素e,如果插入成功则返回OK，如果i非法则返回ERROR,如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，int e(需要插入的位置), Elemtype e(需要插入的元素)
函数类型: status
*/
status ListInsert(SqList &L,int i,ElemType e)
{
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
}
/*
函数名称: ListDelete
函数作用: 对一个已存在的线性表在位置i上删除元素e,如果删除成功则返回OK，如果i非法则返回ERROR,如果线性表不存在则返回INFEASIBLE
函数参数: SqList &L(对一个线性表的引用)，int e(需要删除的位置), Elemtype e(需要删除的元素)
函数类型: status
*/
status ListDelete(SqList &L,int i,ElemType &e)
{
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
}
/*
函数名称: ListTraverse
函数作用: 对一个已存在的线性表进行遍历并输出线性表的元素，如果遍历成功则返回OK,如果线性表不存在则返回INFEASIBLE
函数参数: SqList L(线性表)
函数类型: status
*/
status ListTraverse(SqList L)
{
    if(!L.elem) return INFEASIBLE;
    else
    {
        if(L.length == 0)   return ERROR;
        for(int i = 0; i < L.length - 1; i++)
            printf("%d ",L.elem[i]);
        if(L.length != 0)
        printf("%d",L.elem[L.length - 1]);
        return OK;
    }
}
/*
函数名称: SaveList
函数作用: 将一个已存在的线性表保存至指定的文件FileName，如果保存成功则返回OK,如果文件打开失败则返回ERROR,如果线性表不存在则返回INFEASIBLE
函数参数: SqList L(线性表), char FileName[](文件的名称)
函数类型: status
*/
status  SaveList(SqList L,char FileName[])
{
    if(!L.elem) return INFEASIBLE;
    FILE *p;
    p = fopen(FileName,"w+");
    if(!p)  return ERROR;
    /*for(int i = 0; i < L.length; i++)
        fprintf(p,"%d ",L.elem[i]);
    */
    fwrite(L.elem,sizeof(int),L.length,p);
    fclose(p);
    return OK;
}
/*
函数名称: LoadList
函数作用: 将一个未初始化的线性表从指定的文件FileName加载数据，如果加载成功则返回OK,如果文件打开失败则返回ERROR,如果线性表存在则返回INFEASIBLE
函数参数: SqList L(线性表), char FileName[](文件的名称)
函数类型: status
*/
status  LoadList(SqList &L,char FileName[])
{
    if(L.elem)  return INFEASIBLE;
    else
    {
        L.elem = (int *)malloc(sizeof(int) * L.listsize);
        L.length = 0;
        FILE *p;
        p = fopen(FileName,"rb+");
        if(!p)  return ERROR;
        int temp;
        int cnt = 1;
        //return OK;
        while(fread(&temp,sizeof(int),1,p))
            ListInsert(L,cnt++,temp);
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
status AddList_1(LISTS &Lists,char ListName[])
{
    SqList temp;
    temp.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
    temp.length = 0;
    temp.listsize = LIST_INIT_SIZE;
    Lists.elem[Lists.length++].L = temp;
    strcpy(Lists.elem[Lists.length-1].name,ListName);
    return OK;
}
/*
函数名称: AddList_2
函数作用: 将一个已存在的线性表插入到线性表组L的末尾并为该线性表命名，如果插入成功则返回OK，如果该线性表不存在,则返回INFEASIBLE
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称), SqList &L(对线性表的引用)
函数类型: status
*/
int AddList_2(LISTS &Lists,char ListName[],SqList &L)
{
    if(!L.elem) return INFEASIBLE;
    Lists.elem[Lists.length++].L = L;
    strcpy(Lists.elem[Lists.length-1].name,ListName);
    return OK;
}
/*
函数名称: RemoveList
函数作用: 将一个线性表名字为ListName的线性表从线性表组L中删除，如果删除成功则返回OK,如果该线性表不存在则返回ERROR
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称)
函数类型: status
*/
status RemoveList(LISTS &Lists,char ListName[])
{
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
}
/*
函数名称: LocateList
函数作用: 查询名字为ListName的线性表在线性表组中的位置,如果查找成功则返回位置,如果不存在则返回ERROR
函数参数: LISTS &Lists(线性表组的引用), char ListName[](线性表的名称)
函数类型: int
*/
int LocateList(LISTS Lists,char ListName[])
{
    for(int i = 0; i < Lists.length; i++)
    {
        if(strcmp(Lists.elem[i].name,ListName) == 0)
            return i + 1;
    }
    return 0;
}
/*
函数名称: MaxSubArray
函数作用: 查询一个线性表组的最大连续子数列的和,如果查询成功则返回OK，并将首尾保存至frone_pos和end_pos中,如果线性表长度为零,则返回ERROR,如果线性表不存在,则返回INFEASBILE
函数参数: SqList L(线性表),int &result(结果和)，int &frone_pos(首),int &end_pos(尾)
函数类型: int
*/
int MaxSubArray(SqList L,int &result,int &front_pos,int &end_pos)
{
    if(!L.elem) return INFEASIBLE;
    if(L.length == 0)   return ERROR;
    int *temp;
    temp = (int *)malloc(sizeof(int) * (L.length + 1));
    temp[0] = 0;
    for(int i = 1; i <= L.length; i++)
        temp[i] = temp[i - 1] + L.elem[i - 1];
    int temp1 = -999999;
    for(int i = 1; i <= L.length; i++)
        for(int j = i; j <= L.length; j++)
        {
            if(temp1 < temp[j] - temp[i - 1])
            {
                temp1 = temp[j] - temp[i - 1];
                front_pos = i;
                end_pos = j;
            }
        }
    free(temp);
    temp = NULL;
    result = temp1;
    return OK;
}
/*
函数名称: SubArrayNum
函数作用: 查询一个线性表组的连续子数列和为k的数量,如果查询成功则返回OK，并将值保存在k中,如果线性表长度为零,则返回ERROR,如果线性表不存在,则返回INFEASBILE
函数参数: SqList L(线性表),int k(连续子数列的和)
函数类型: int
*/
int SubArrayNum(SqList L,int k)
{
    if(!L.elem) return INFEASIBLE;
    if(L.length == 0)   return -2;
    int *temp;
    temp = (int *)malloc(sizeof(int) * (L.length + 1));
    temp[0] = 0;
    for(int i = 1; i <= L.length; i++)
        temp[i] = temp[i - 1] + L.elem[i - 1];
    int cnt = 0;
    for(int i = 1; i <= L.length; i++)
        for(int j = i; j <= L.length; j++)
            if(temp[j] - temp[i - 1] == k)  cnt++;
    return cnt;
}
/*
函数名称: SortList
函数作用: 将一个线性表进行从小到大的排序,如果排序成功则返回OK,如果线性表长度为零,则返回ERROR,如果线性表不存在,则返回INFEASBILE
函数参数: SqList L(线性表)
函数类型: int
*/
int SortList(SqList L)
{
    if(!L.elem) return INFEASIBLE;
    if(L.length == 0)   return ERROR;
    else
        std::sort(L.elem,L.elem + L.length);
    return OK;
}
/*
函数名称: ShowList
函数作用: 展示一个线性表组，如果展示成功则返回OK,如果线性表组长度为0,则返回ERROR
函数参数: LISTS Lists(线性表组),
函数类型: int
*/
int ShowList(LISTS Lists)
{
    if(Lists.length == 0)   return ERROR;
    else
    {
        for(int i = 1; i <= Lists.length; i++)
            printf("%d %s\n",i,Lists.elem[i - 1].name);
        return OK;
    }
}
/*
函数名称: SwitchList
函数作用: 将当前线性表切换为线性表组中第i个线性表,如果切换成功则返回OK,如果i非法则返回ERROR
函数参数: LISTS Lists(线性表组),int i(线性表的位置),SqList &L(当前线性表的引用)
函数类型: int
*/
int SwitchList(LISTS Lists,int i,SqList &L)
{
    if(i <= 0 or i > Lists.length)  return ERROR;
    else
    {
        L = Lists.elem[i - 1].L;
        return OK;
    }
}
/*
函数名称: UpdateList
函数作用: 将当前线性表更新（覆盖）到线性表组中第i个线性表,如果更新成功则返回OK,如果i非法则返回ERROR
函数参数: LISTS Lists(线性表组),int i(线性表的位置),SqList &L(当前线性表的引用)
函数类型: int
*/
int UpdateList(LISTS &Lists,int i, SqList &L)
{
    if(i <= 0 or i > Lists.length)  return ERROR;
    else
    {
        Lists.elem[i - 1].L.elem = L.elem;
        Lists.elem[i - 1].L.length = L.length;
        Lists.elem[i - 1].L.listsize = L.listsize;
        return OK;
    }
}