#include "def.h"
//1 a 2 b 0 null  0 null 3 c 4 d  0 null  0 null 5 e  0 null  0 null -1 null
//1 a 3 b 0 null 0 null 4 d 5 e 0 null 0 null -7 f 0 null 20 g 0 null 0 null -1 null
int check[1000];
int cc[1000];
int cnt = 0;
std:: stack<BiTree> s;
BiTree start;
void buildtree(TElemType definition[],int &signal);
void Check(BiTree &T,KeyType e,int &cnt);
void show(BiTree &T)
{
    if(!T) return ;
    printf("%d %s ",T->data.key,T->data.others);
    show(T->lchild);
    show(T->rchild);
    return ; 
}
status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    T=p[1];
    return OK;
}

status MyCreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    if(T)   return INFEASIBLE;
    for(int i = 0; i <= 999; i++)   cc[i] = check[i] = 0;
    cnt = 0;
    int signal = 0;
    start = (BiTree)malloc(sizeof(BiTNode));
    start->data.key = 0;
    start->data.others[0] = 'N';
    start->rchild = NULL;
    buildtree(definition,signal);
    int cnt = 0;
    while(!s.empty())   s.pop();
    //if(signal == 1) return ERROR;
    int temp_cnt = 0;
    while(definition[temp_cnt].key != -1)
    {
        if(definition[temp_cnt].key == 0)
        {
            temp_cnt++;
            continue;
        }
        cnt = 0;
        Check(start->lchild,definition[temp_cnt++].key,cnt);
        if(cnt >= 2)
        {
            signal = 1;
            break;
        }

    }
    if(signal == 1) return ERROR;
    if(start->lchild  and signal == 0)   T = start->lchild;
    return OK;
}
void buildtree(TElemType definition[],int &signal)
{
//    if(s.empty())   return ;
    int flag;
    char temp[20];
    flag = definition[cnt++].key;
    strcpy(temp,definition[cnt-1].others);
    if(flag == -1)  return ;
    if(s.empty())
    {
        BiTree ttemp;
        ttemp = (BiTree)malloc(sizeof(BiTNode));
        ttemp->data.key = flag;
        strcpy(ttemp->data.others,temp);
        if(flag == 0)
        {
            start->lchild = NULL;
            return ;
        }
        //if(!check[flag])   check[flag]++;
        start->lchild = ttemp;
        s.push(ttemp);
        buildtree(definition,signal);
    }
    else
    {
        BiTree ttemp;
        while(1)
        {
            ttemp = s.top();
            if(cc[ttemp->data.key] == 0)
            {
                BiTree temp1;
                temp1 = (BiTree)malloc(sizeof(BiTNode));
                temp1->data.key = flag;
                strcpy(temp1->data.others,temp);
                cc[ttemp->data.key]++;
                if(temp1->data.key != 0)
                {
                    /*if(check[temp1->data.key] != 0)
                    {
                        signal = 1;
                        return ;
                    }
                    */
                    //check[temp1->data.key]++;
                    ttemp->lchild = temp1;
                    s.push(ttemp->lchild);
                }
                else
                    ttemp->lchild = NULL;
                buildtree(definition,signal);
                break;
            }
            else
            {
                if(cc[ttemp->data.key] == 1)
                {
                    BiTree temp1;
                    temp1 = (BiTree)malloc(sizeof(BiTNode));
                    temp1->data.key = flag;
                    strcpy(temp1->data.others,temp);
                    cc[ttemp->data.key]++;
                    if(temp1->data.key != 0)
                    {
                        /*if(check[temp1->data.key] != 0)
                        {
                            signal = 1;
                            return ;
                        }
                        check[temp1->data.key]++;
                        */
                        ttemp->rchild = temp1;
                        s.push(ttemp->rchild);
                    }
                    else
                        ttemp->rchild = NULL;
                    buildtree(definition,signal);
                    break;
                }
                else
                    s.pop();
            }
        }
        
    }
    return ;
}

status DestroyBitree(BiTree &T)
{
    if(!T)  return INFEASIBLE;
    else
    {
        DestroyBitree(T->lchild);
        DestroyBitree(T->rchild);
        free(T);
        T = NULL;
        return OK;
    } 
}

status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return INFEASIBLE;
    ClearBiTree(T->lchild);
    ClearBiTree(T->rchild);
    free(T);
    T = NULL;
    return OK;
    /********** End **********/
}

status BiTreeEmpty(BiTree T)
{
    if(!T)  return INFEASIBLE;
    else
    {
        if(T->data.key == 0)   return FALSE;
        else    return OK;    
    }
}
//1 a 0 null 0 null -1 null
int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return 0;
    int m,n;
    m = n = 0;
    m = BiTreeDepth(T->lchild);
    n = BiTreeDepth(T->rchild);
    int ans = 0;
    if(m > n)   ans = m;
    else    ans = n;
    ans++;
    return ans;
    /********** End **********/
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return NULL;
    if(T->data.key == e)    return T;
    BiTree temp;
    temp = LocateNode(T->lchild,e);
    if(temp)    return temp;
    temp = LocateNode(T->rchild,e);
    if(temp)    return temp;
    return NULL;
    /********** End **********/
}

status temp_Assign(BiTree &T,KeyType e,TElemType value);

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return INFEASIBLE;
    int cnt = 0;
    Check(T,value.key,cnt);
    if(e == value.key)  cnt--;
    if(cnt >= 1)    return ERROR;
    return temp_Assign(T,e,value);
    /********** End **********/
}
status temp_Assign(BiTree &T,KeyType e,TElemType value)
{
    if(!T)  return ERROR;
    if(T->data.key == e)
    {
        T->data = value;
        return OK;
    }
    if(temp_Assign(T->lchild,e,value))  return OK;
    if(temp_Assign(T->rchild,e,value))  return OK;
    return ERROR;
}
void Check(BiTree &T,KeyType e,int &cnt)
{
    if(!T)  return ;
    if(T->data.key == e)    cnt++;
    Check(T->lchild,e,cnt);
    Check(T->rchild,e,cnt);
    return ;
}

BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return NULL;
    if((T->lchild) and T->lchild->data.key == e) return T->rchild;
    if((T->rchild) and T->rchild->data.key == e) return T->lchild;
    BiTNode* temp;
    temp = GetSibling(T->lchild,e);
    if(temp)    return temp;
    temp = GetSibling(T->rchild,e);
    if(temp)    return temp;
    return NULL;
    /********** End **********/
}

status temp_InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
{
    int cnt = 0;
    Check(T,c.key,cnt);
    if(cnt >= 1)    return INFEASIBLE;
    else
        return temp_InsertNode(T,e,LR,c);
}
status temp_InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return ERROR;
    if(LR == -1)
    {
        BiTree temp;
        temp = (BiTree)malloc(sizeof(BiTNode));
        temp->data = c;
        temp->rchild = T;
        T = temp;
        return OK;
    }
    if(T->data.key == e)
    {
        if(LR == 0)
        {
            BiTree temp;
            temp = T->lchild;
            BiTree temp2;
            temp2 = (BiTree)malloc(sizeof(BiTNode));
            temp2->data = c;
            T->lchild = temp2;
            temp2->rchild = temp;
        }
        else
        {
            BiTree temp;
            temp = T->rchild;
            BiTree temp2;
            temp2 = (BiTree)malloc(sizeof(BiTNode));
            temp2->data = c;
            T->rchild = temp2;
            temp2->rchild = temp;
        }
        return OK;
    }
    status ttemp;
    ttemp = temp_InsertNode(T->lchild,e,LR,c);
    if(ttemp)   return ttemp;
    ttemp = temp_InsertNode(T->rchild,e,LR,c);
    if(ttemp)   return ttemp;
    return ERROR;
    /********** End **********/
}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return ERROR;
    if(T->data.key == e)
    {
        if(!T->rchild and !T->lchild)  
        {
            BiTree temptemp;
            temptemp = T;
            free(temptemp);
            T = NULL;
            temptemp = NULL;
            return OK;
        } 
        if(T->lchild and !T->rchild)
        {
            BiTree temptemp;
            temptemp = T;
            T = T->lchild;
            free(temptemp);
            return OK;
        }
        if(!T->lchild and T->rchild)
        {
            BiTree temptemp;
            temptemp = T;
            T = T->rchild;
            free(temptemp);
            return OK;
        }
        BiTree temp;
        BiTree pri;
        temp = T->lchild->rchild;
        pri = T->lchild;
        while(temp)
        {
            temp = temp->rchild;
            pri = pri->rchild;
        }
        pri->rchild = T->rchild;
        BiTree temptemp;
        temptemp = T;
        T = T->lchild;
        free(temptemp);
        return OK;
    }
    status temp;
    temp = DeleteNode(T->lchild,e);
    if(temp)    return temp;
    temp = DeleteNode(T->rchild,e);
    if(temp)    return temp;
    return ERROR;
    /********** End **********/
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    while(!s.empty())   s.pop();
    s.push(T);
    while(!s.empty())
    {
        
        BiTree temp;
        temp = s.top();
        visit(temp);s.pop();
        if(temp->rchild)  s.push(temp->rchild);
        if(temp->lchild)  s.push(temp->lchild);
        
    }
    return OK;
    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return OK;
    if(T->lchild)
        InOrderTraverse(T->lchild,visit);
    visit(T);
    if(T->rchild)
        InOrderTraverse(T->rchild,visit);
    return OK;
    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T)  return OK;
    if(T->lchild)   PostOrderTraverse(T->lchild,visit);
    if(T->rchild)   PostOrderTraverse(T->rchild,visit);
    visit(T);
    return OK;
    /********** End **********/
}

std:: queue<BiTree> q;
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    while(!q.empty())   q.pop();
    /********** Begin *********/
    q.push(T);
    while(!q.empty())
    {
        visit(q.front());
        if(q.front()->lchild) q.push(q.front()->lchild);
        if(q.front()->rchild) q.push(q.front()->rchild);
        q.pop();
    }
    /********** End **********/
    return OK;
}

int MaxPathSum(BiTree T)
{
    if(!T)  return -99999;
    int temp1 = MaxPathSum(T->lchild);
    int temp2 = MaxPathSum(T->rchild);
    int temp3 = std::max(temp1,temp2);
    if(temp3 < 0)   return T->data.key;
    if(temp3 + T->data.key >= 0)    return T->data.key + temp3;
    return T->data.key + temp3;
}
int LCA(BiTree T,KeyType e1,KeyType e2,BiTree &ans,int &flag);
BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2)
{
    if(!T)  return NULL;
    BiTree ans;
    int flag = 0;
    LCA(T,e1,e2,ans,flag);
    return ans;
}
int LCA(BiTree T,KeyType e1,KeyType e2,BiTree &ans,int &flag)
{
    if(!T)  return 0;
    int temp_cnt = 0;
    int signal = 0;
    if(T->data.key == e1 or T->data.key == e2)  
        temp_cnt++;
    temp_cnt += LCA(T->lchild,e1,e2,ans,flag) + LCA(T->rchild,e1,e2,ans,flag);
    if(temp_cnt == 2)
    {
        if(!flag)
        {
            flag = 1;
            ans = T;
        }
    }
    return temp_cnt;
}

status InvertTree(BiTree &T)
{
    if(!T)  return INFEASIBLE;
    InvertTree(T->lchild);
    InvertTree(T->rchild);
    BiTree temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    return OK;
}

std:: stack<BiTree> ss;
TElemType tempdefinition[200];
char *tempname;
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *p;
    p = fopen(FileName,"w+");
    if(!T)  return INFEASIBLE;
    if(!p)  return ERROR;
    while(!ss.empty())  ss.pop();
    ss.push(T);
    while(!ss.empty())
    {
        BiTree temp;
        temp = ss.top();
        ss.pop();
        if(!temp)
        {
            TElemType* ttemp;
            ttemp = (TElemType*)malloc(sizeof(TElemType));
            ttemp->key = 0;
            ttemp->others[0] = 'n';
            fwrite(ttemp,sizeof(TElemType),1,p);
            continue;
        }
        fwrite(&temp->data,sizeof(TElemType),1,p);
        ss.push(temp->rchild);
        ss.push(temp->lchild);
    }
    TElemType* ttemp;
    ttemp = (TElemType*)malloc(sizeof(TElemType));
    ttemp->key = -1;
    ttemp->others[0] = 'n';
    fwrite(ttemp,sizeof(TElemType),1,p);
    fclose(p);
    return OK;
    /********** End 1 **********/
}

status LoadBiTree(BiTree &T,  char FileName[])
{
    memset(tempdefinition,0,sizeof(tempdefinition));
    if(T)   return INFEASIBLE;
    FILE *p;
    //T = (BiTree)malloc(sizeof(BiTNode));
    p = fopen(FileName,"r+");
    if(!p)  return ERROR;
    TElemType temp;
    cnt = 0;
    while(fread(&temp,sizeof(temp),1,p))
        tempdefinition[cnt++] = temp;
    int flag = 0;
    flag = MyCreateBiTree(T,tempdefinition);
    fclose(p);
    return OK;
}

void AddBiTree_1(char name[])
{
    BiTree temp;
    temp = (BiTree)malloc(sizeof(BiTNode));
    Ts[num_t].T = NULL;
    strcpy(Ts[num_t].name,name);
    num_t++;
    return ;
}

void AddBiTree_2(BiTree T,char name[])
{
    Ts[num_t].T = T;
    strcpy(Ts[num_t].name,name);
    num_t++;
    return ;
}

status DeleteBiTree(char name[])
{
    int flag = 0;
    for(int i = 0; i < num_t; i++)
    {
        if(strcmp(Ts[i].name,name) == 0)
        {
            for(int j = i; j < num_t - 1; j++)
                Ts[i] = Ts[i + 1];
            num_t--;
            flag = 1;
            break;
        }
    }
    if(flag)    return OK;
    return ERROR;
}

void ShowBiTree()
{
    for(int i = 0; i < num_t; i++)
        std::cout << i + 1 << " " << Ts[i].name << std::endl;
    return ;
}

status UpdateBiTree(BiTree T,char name[])
{
    int flag = 0;
    for(int i = 0; i < num_t; i++)
    {
        if(strcmp(Ts[i].name,name) == 0)
        {
            Ts[i].T = T;
            flag = 1;
            break;
        }
    }
    if(flag)    return OK;
    return ERROR;
}

status SwitchBiTree(BiTree &T,char name[])
{
    int flag = 0;
    for(int i = 0; i < num_t; i++)
    {
        if(strcmp(Ts[i].name,name) == 0)
        {
            T = Ts[i].T;
            flag = 1;
            break;
        }
    }
    if(flag)    return OK;
    return ERROR;
}