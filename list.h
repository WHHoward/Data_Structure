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
        L.listsize = LIST_INIT_SIZE;
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
        L.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
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
{
    if(L.elem)
    {
        for(int i = 0; i < L.length; i++)
            if(L.elem[i] == e)  return i + 1;
        return 0;   
    }
    return INFEASIBLE;
}

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

status AddList(LISTS &Lists,char ListName[])
{
    SqList temp;
    temp.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
    temp.length = 0;
    temp.listsize = LIST_INIT_SIZE;
    Lists.elem[Lists.length++].L = temp;
    strcpy(Lists.elem[Lists.length-1].name,ListName);
    return OK;
}

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

int LocateList(LISTS Lists,char ListName[])
{
    for(int i = 0; i < Lists.length; i++)
    {
        if(strcmp(Lists.elem[i].name,ListName) == 0)
            return i + 1;
    }
    return 0;
}

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

int SortList(SqList L)
{
    if(!L.elem) return INFEASIBLE;
    if(L.length == 0)   return ERROR;
    else
        std::sort(L.elem,L.elem + L.length);
    return OK;
}