#include "def.h"
//   5 线性表 8 集合 7 二叉树 6 无向图 -1 nil  5 6  5 7 6 7 7 8 -1 -1
status MyCreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    G.kind = UDG;
    int cnt1 = 0;
    int cnt2 = 0;
    G.vexnum = G.arcnum = 0;
    while(V[cnt1].key != -1)
    {
        G.vertices[G.vexnum].data = V[cnt1];
        int flag = 0;
        for(int kk = 0; kk < G.vexnum; kk++)
            if(G.vertices[kk].data.key == V[cnt1].key)
            {
                flag = 1;
                break;
            }
        if(flag)    return ERROR;
        cnt2 = 0;
        G.vertices[G.vexnum].firstarc = NULL;
        while(VR[cnt2][0] != -1)
        {
            if(VR[cnt2][0] == V[cnt1].key)
            {
                G.arcnum++;
                int k = 0;
                for(k = 0; V[k].key != -1; k++)
                    if(V[k].key == VR[cnt2][1])
                        break;
                if(!G.vertices[G.vexnum].firstarc)
                {
                    ArcNode *temp;
                    temp = (ArcNode*)malloc(sizeof(ArcNode));
                    temp->adjvex = k;
                    temp->nextarc = NULL;
                    G.vertices[G.vexnum].firstarc = temp;
                }
                else
                {
                    ArcNode *temp;
                    temp = G.vertices[G.vexnum].firstarc;
                    ArcNode *ttemp;
                    ttemp = (ArcNode*)malloc(sizeof(ArcNode));
                    ttemp->adjvex = k;
                    ttemp->nextarc = temp;
                    G.vertices[G.vexnum].firstarc = ttemp;
                }
            }
            if(VR[cnt2][1] == V[cnt1].key)
            {
                G.arcnum++;
                int k = 0;
                for(k = 0; V[k].key != -1; k++)
                    if(V[k].key == VR[cnt2][0])
                        break;
                if(!G.vertices[G.vexnum].firstarc)
                {
                    ArcNode *temp;
                    temp = (ArcNode*)malloc(sizeof(ArcNode));
                    temp->adjvex = k;
                    temp->nextarc = NULL;
                    G.vertices[G.vexnum].firstarc = temp;
                }
                else
                {
                    ArcNode *temp;
                    temp = G.vertices[G.vexnum].firstarc;
                    ArcNode *ttemp;
                    ttemp = (ArcNode*)malloc(sizeof(ArcNode));
                    ttemp->adjvex = k;
                    ttemp->nextarc = temp;
                    G.vertices[G.vexnum].firstarc = ttemp;
                }
            }
            cnt2++;
        }
        G.vexnum++;
        cnt1++;
    }
    if(cnt1 == 0)   return ERROR;
    G.arcnum /= 2;
//    std::cout << cnt2 << std::endl;
    if(G.arcnum != cnt2)  return ERROR; 
    return OK;
    /********** End **********/
}
status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    int vex = G.vexnum;
    int arc = G.arcnum;
    if(!vex)    return INFEASIBLE;
    for(int i = 0; i < vex; i++)
    {
        ArcNode *temp;
        temp = G.vertices[i].firstarc;
        ArcNode *pri;
        pri = G.vertices[i].firstarc;
        if(temp)    temp = temp->nextarc;
        while(temp)
        {
            //pri = pri->nextarc;
            free(pri);
            pri = temp;
            temp = temp->nextarc;
            //pri = temp;
        }
        if(pri) free(pri);
        G.vertices[i].firstarc = NULL;
        G.vertices[i].data.key = -1;
        G.vertices[i].data.others[0] = 'N';
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(G.vexnum == 0)   return INFEASIBLE;
    int flag = 0;
    int ans = 0;
    for(int i = 0; i < G.vexnum; i++)
        if(G.vertices[i].data.key == u)
        {
            flag = 1;
            ans = i;
            break;
        }    
    if(!flag)   return -2;
    return ans;
    /********** End **********/
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = 0;
    int cnt = 0;
    if(!G.vexnum)   return INFEASIBLE;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u)
            flag = 1;
        if(G.vertices[i].data.key == value.key)
            cnt++;
    }
    if(!flag)   return ERROR;
    if(u == value.key)  cnt--;
    if(cnt >= 1)    return ERROR;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u)
        {
            G.vertices[i].data = value;
            break;
        }
    }
    return OK;
    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = 0;
    int ans = 0;
    if(!G.vexnum)   return INFEASIBLE;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u)
        {
            flag = 1;
            ans = G.vertices[i].firstarc->adjvex;
            break;
        }
    }
    if(!flag)   return INFEASIBLE;
    return ans;
    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = 0;
    int ans = 0;
    if(!G.vexnum)   return INFEASIBLE;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode *temp;
            temp = G.vertices[i].firstarc;
            while(temp)
            {
                if(G.vertices[temp->adjvex].data.key == w)
                {
                    if(temp->nextarc)
                    {
                        ans = temp->nextarc->adjvex;
                        flag = 1;
                    }
                }
                temp = temp->nextarc;
            }
        }
    }
    if(!flag)   return INFEASIBLE;
    return ans;
    /********** End **********/
}
status GraphTraverse(ALGraph G)
{
    if(!G.vexnum)   return INFEASIBLE;
    for(int i = 0; i < G.vexnum; i++)
    {
        std::cout << G.vertices[i].data.others << " " << G.vertices[i].data.key << " ";
        ArcNode *temp;
        temp = G.vertices[i].firstarc;
        while(temp)
        {
            std::cout << temp->adjvex << " ";
            temp = temp->nextarc;
        }
        std::cout << std::endl;
    }
    return OK;
}
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = 0;
    for(int i = 0; i < G.vexnum; i++)
        if(G.vertices[i].data.key == v.key) 
        {
            flag = 1;
            break;
        }
    if(G.vexnum == MAX_VERTEX_NUM ) return ERROR;
    if(flag)   return ERROR;
    G.vertices[G.vexnum++].data = v;
    G.vertices[G.vexnum - 1].firstarc = NULL;
    return OK;
    /********** End **********/
}

status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(G.vexnum <= 1)   return ERROR;
    int flag = 0;
    int mark = 0;
    for(int i = 0; i < G.vexnum; i++)
        if(G.vertices[i].data.key == v)
        {
            flag = 1;
            mark = i;
            break;
        }
    if(!flag)   return ERROR;
    for(int i = 0; i < G.vexnum; i++)
    {
        ArcNode *temp;
        ArcNode *pri;
        temp = G.vertices[i].firstarc;
        pri = temp;
        if(G.vertices[i].data.key == v)
        {
            while(pri)
            {
                temp = pri->nextarc;
                free(pri);
                pri = temp;
            }
            G.vertices[i].firstarc = NULL;
            continue;
        }
        if(!temp)   continue;
        if(G.vertices[temp->adjvex].data.key == v)
        {
            G.arcnum--;
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free(temp);
            continue;
        }
        temp = temp->nextarc;
        while(temp)
        {
            if(G.vertices[temp->adjvex].data.key == v)
            {
                G.arcnum--;
                pri->nextarc = temp->nextarc;
                free(temp);
                temp = pri->nextarc;
                continue;
            }
            temp = temp->nextarc;
            pri = pri->nextarc;
        }
    }
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            for(int j = i; j < G.vexnum - 1; j++)
                G.vertices[j] = G.vertices[j + 1];
            break;
        }
    }
    G.vexnum--;
    for(int i=0;i<G.vexnum;i++)
	{
        ArcNode *p=G.vertices[i].firstarc;
        while (p)
        {
            if(p->adjvex > mark)  p->adjvex--;
            p=p->nextarc;
        }
	} 
    return OK;
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int mark1 = 0;
    int mark2 = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
            mark1 = i + 1;
        if(G.vertices[i].data.key == w)
            mark2 = i + 1;
    }
    if(!mark1 or !mark2)    return ERROR;
    mark1--;
    mark2--;
    int flag = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode *temp;
            temp = G.vertices[i].firstarc;
            while(temp)
            {
                if(temp->adjvex == mark2)    
                {
                    flag = 1;
                    break;
                }
                temp = temp->nextarc;
            }
        }
    }
    if(flag)    return ERROR;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode *temp;
            temp = (ArcNode*)malloc(sizeof(ArcNode));
            temp->adjvex = mark2;
            temp->nextarc = G.vertices[i].firstarc;
            G.vertices[i].firstarc = temp;
        }
        if(G.vertices[i].data.key == w)
        {
            ArcNode *temp;
            temp = (ArcNode*)malloc(sizeof(ArcNode));
            temp->adjvex = mark1;
            temp->nextarc = G.vertices[i].firstarc;
            G.vertices[i].firstarc = temp;
        }
    }
    G.arcnum++;
    return OK;
    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int mark1 = -1;
    int mark2 = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
            mark1 = i;
        if(G.vertices[i].data.key == w)
            mark2 = i;
    }
    if(mark1 == -1 or mark2 == -1)  return ERROR;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode *temp;
            temp = G.vertices[i].firstarc;
            int flag = 0;
            while(temp)
            {
                if(temp->adjvex == mark2)
                {
                    flag = 1;
                    break;
                }
                temp = temp->nextarc;
            }
            if(!flag)   return ERROR;
        }
    }
    G.arcnum--;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode *temp;
            ArcNode *pri;
            temp = G.vertices[i].firstarc;
            pri = temp;
            if(temp->adjvex == mark2)
            {
                G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
                free(temp);
                continue;
            }
            temp = temp->nextarc;
            while(temp)
            {
                if(temp->adjvex == mark2)
                {
                    pri->nextarc = temp->nextarc;
                    free(temp);
                    temp = pri->nextarc;
                    break;
                }
                temp = temp->nextarc;
                pri = pri->nextarc;
            }
        }
        if(G.vertices[i].data.key == w)
        {
            ArcNode *temp;
            ArcNode *pri;
            temp = G.vertices[i].firstarc;
            pri = temp;
            if(temp->adjvex == mark1)
            {
                G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
                free(temp);
                continue;
            }
            temp = temp->nextarc;
            while(temp)
            {
                if(temp->adjvex == mark1)
                {
                    pri->nextarc = temp->nextarc;
                    free(temp);
                    temp = pri->nextarc;
                    break;
                }
                temp = temp->nextarc;
                pri = pri->nextarc;
            }
        }
    }
    return OK;
    /********** End **********/
}
bool vis[10000] = {false};
void DFS(ALGraph G,ArcNode *temp,void (*visit)(VertexType))
{
    if(!temp)   return ;
    if(vis[temp->adjvex] == true)    return;
    visit(G.vertices[temp->adjvex].data);
    vis[temp->adjvex] = true;
    temp = G.vertices[temp->adjvex].firstarc;
    while(temp)
    {
        DFS(G,temp,visit);
        temp = temp->nextarc;
    }
    return ;
}
status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
    if(!G.vexnum)   return INFEASIBLE;
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < G.vexnum; i++)
    {
        if(vis[i] == false) visit(G.vertices[i].data);
        vis[i] = true;
        ArcNode *temp;
        temp = G.vertices[i].firstarc;
        while(temp)
        {
            DFS(G,temp,visit);
            temp = temp->nextarc;
        }
    }
    return OK;
    /********** End **********/
}
std:: queue<int> q;
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    while(!q.empty())   q.pop();
    if(!G.vexnum)   return INFEASIBLE;
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!vis[i]) q.push(i);
        while(!q.empty())
        {
            int temp = q.front();
            if(!vis[temp])  visit(G.vertices[temp].data);
            vis[temp] = true;
            ArcNode *ttemp;
            ttemp = G.vertices[temp].firstarc;
            while(ttemp)
            {
                if(!vis[ttemp->adjvex])
                {
                    visit(G.vertices[ttemp->adjvex].data);
                    vis[ttemp->adjvex] = true;
                    q.push(ttemp->adjvex);
                }
                ttemp = ttemp->nextarc;
            }
            q.pop();
        }
    }
    
    return OK;
    /********** End **********/
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *p;
    p = fopen(FileName,"w+");
    if(!G.vexnum)   return INFEASIBLE;
    if(!p)  return ERROR;
    fwrite(&G.vexnum,sizeof(int),1,p);
    for(int i = 0; i < G.vexnum; i++)
        fwrite(&G.vertices[i].data,sizeof(VertexType),1,p);
    for(int i = 0; i < G.vexnum; i++)
    {
        int cnt = 0;
        ArcNode *temp;
        temp = G.vertices[i].firstarc;
        while(temp)
        {
            cnt++;
            temp = temp->nextarc;
        }
        fwrite(&cnt,sizeof(int),1,p);
        temp = G.vertices[i].firstarc;
        while(temp)
        {
            fwrite(&temp->adjvex,sizeof(int),1,p);
            temp = temp->nextarc;
        }
    }
    fclose(p);
    return OK;
    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *p;
    p = fopen(FileName,"r+");
    int cnt = 0;
    if(G.vexnum)    return INFEASIBLE;
    if(!p)  return ERROR;
    fread(&cnt,sizeof(int),1,p);
    for(int i = 0; i < cnt; i++)
        fread(&G.vertices[i].data,sizeof(VertexType),1,p);
    G.vexnum = cnt;
    G.arcnum = 0;
    for(int i = 0; i < cnt; i++)
    {
        int num = 0;
        fread(&num,sizeof(int),1,p);
        ArcNode *head = NULL;
        ArcNode *temp = NULL;
        for(int j = 0; j < num ; j++)
        {
            G.arcnum++;
            ArcNode *ttemp;
            ttemp = (ArcNode*)malloc(sizeof(ArcNode));
            ttemp->nextarc = NULL;
            fread(&ttemp->adjvex,sizeof(int),1,p);
            if(!temp)
            {
                temp = ttemp;
                head = temp;
            }
            else
            {
                temp->nextarc = ttemp;
                temp = temp->nextarc;
            }
        }
        G.vertices[i].firstarc = head;
    }
    G.arcnum /= 2;
    fclose(p);
    return OK;
    /********** End 2 **********/
}

status VerticesSetLessThanK(ALGraph G,KeyType v,int k)
{
    if(!G.vexnum)   return INFEASIBLE;
    int mark = -1;
    for(int i = 0; i < G.vexnum; i++)
        if(G.vertices[i].data.key == v)
        {
            mark = i;
            break;
        }
    if(mark == -1)  return ERROR;
    int cnt = 0;
    int *ans;
    ans = (int*)malloc(sizeof(int)*(G.vexnum+10));
    while(!q.empty())   q.pop();
    memset(vis,false,sizeof(vis));
    int start = 0;
    int tail = 0;
    int t = 0;
    int num = 0;
    if(G.vertices[mark].firstarc)   q.push(mark);
    vis[mark] = true;
    while(!q.empty())
    {
        int now =  q.front();
        ArcNode *temp;
        temp = G.vertices[now].firstarc;
        while(temp)
        {
            if(vis[temp->adjvex] == false)
            {
                vis[temp->adjvex] = true;
                t++;
                q.push(temp->adjvex);
            }
            temp = temp->nextarc;
        }
        if(cnt < k and cnt > 0) ans[num++] = now;
        if(start == tail)
        {
            tail += t;
            t = 0;
            cnt++;
        }
        start++;
        q.pop();
        if(cnt >= k)    break;
    }
    while(!q.empty())   q.pop();
    if(!num)
    {
        free(ans);
        return OK;
    }
    else
    {
        for(int i = 0; i < num; i++)
            std::cout << G.vertices[ans[i]].data.key << " " << G.vertices[ans[i]].data.others << std::endl;
    }
    free(ans);
    return OK;
}

status ShortestPathLength(ALGraph G,KeyType v,KeyType w)
{
    int mark1 = -1;
    int mark2 = -1;
    if(!G.vexnum)   return INFEASIBLE;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
            mark1 = i;
        if(G.vertices[i].data.key == w)
            mark2 = i;
    }
    if(mark1 == -1 or mark2 == -1)  return ERROR;
    int ans = 0;
    int start = 0;
    int tail = 0;
    int t = 0;
    memset(vis,false,sizeof(vis));
    while(!q.empty())   q.pop();
    if(G.vertices[mark1].firstarc)  q.push(mark1);
    vis[mark1] = true;
    while(!q.empty())
    {
        int now = q.front();
        if(now == mark2)    break;
        ArcNode *temp;
        temp = G.vertices[now].firstarc;
        while(temp)
        {
            if(vis[temp->adjvex] == false)
            {
                vis[temp->adjvex] = true;
                t++;
                q.push(temp->adjvex);
            }
            temp = temp->nextarc;
        }
        if(start == tail)
        {
            tail += t;
            t = 0;
            ans++;
        }
        start++;
        q.pop();
    }
    while(!q.empty())   q.pop();
    return ans;
}

void hhh(VertexType a)
{
    return ;
}

status ConnectedComponentsNums(ALGraph G)
{
    if(!G.vexnum)   return INFEASIBLE;
    memset(vis,false,sizeof(vis));
    int ans = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(vis[i] == false) ans++;
        vis[i] = true;
        ArcNode *temp;
        temp = G.vertices[i].firstarc;
        while(temp)
        {
            DFS(G,temp,hhh);
            temp = temp->nextarc;
        }
    }
    return ans;
}
