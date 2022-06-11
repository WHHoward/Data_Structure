#include "graph.h"
//   5 线性表 8 集合 7 二叉树 6 无向图 -1 nil  5 6  5 7 6 7 7 8 -1 -1
using namespace std;
ALGraph Gs[20];
VertexType V[200];
KeyType VR[200][2];
int NUM = 0;
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
int main()
{
    int op;
    op = 1;
    while(op)
    {
        printf("      Menu for Linear Table On Sequence Structure \n");
	    printf("-------------------------------------------------\n");
	    printf("    	  1.CreateGraph     7.InsertVex\n");
	    printf("    	  2.DestroyGraph    8.DeleteVex\n");
	    printf("    	  3.LocateVex       9.InsertArc \n");
	    printf("    	  4.PutVex          10.DeleteArc\n");
	    printf("    	  5.FirstAdjVex     11.DFSTraverse\n");
	    printf("    	  6.NextAdjVex      12.BFSTraverse\n");
        printf("          13.SaveGraph      14.LoadGraph\n");
        printf("          15.VerticesSetLessThanK\n");
        printf("          16.ShortestPathLenGth\n");
        printf("          17.ConnectedComponentsNums\n");
	    printf("    	  0. Exit\n");
	    printf("-------------------------------------------------\n");
	    printf("    请选择你的操作[0~24]:");
        cin >> op;
        cout << "请输入你要对第几个图进行操作" << endl;
        cin >> NUM;
        switch (op)
        {
            case 0:
                return 0;
            case 1:
            {
                memset(V,0,sizeof(V));
                memset(VR,0,sizeof(VR));
                if(Gs[NUM].vexnum)
                    cout << "图已存在" << endl;
                else
                {
                    int cnt = 0;
                    do
                    {
                        cin >> V[cnt].key >> V[cnt].others;
                    }while (V[cnt++].key != -1);
                    cnt = 0;
                    do
                    {
                        cin >> VR[cnt][0] >> VR[cnt][1];
                    }while (VR[cnt++][0] != -1);
                    int temp = MyCreateGraph(Gs[NUM],V,VR);
                    if(temp == ERROR)
                        cout << "图创建失败" << endl;
                    else
                        cout << "图创建成功" << endl;
                }
                break;
            }
            case 2:
            {
                int temp = DestroyGraph(Gs[NUM]);
                if(temp == INFEASIBLE)  cout << "图不存在,销毁失败" << endl;
                else
                    cout << "销毁成功" << endl;
                break;
            }
            case 3:
            {
                cout << "请输入你要查找的节点的关键字" << endl;
                KeyType u;
                cin >> u;
                int temp = LocateVex(Gs[NUM],u);
                if(temp == INFEASIBLE)
                    cout << "图不存在" << endl;
                else
                {
                    if(temp == -2)
                        cout << "节点不存在" << endl;
                    else
                    {
                        cout << "节点的位序为: " << temp << endl;
                        cout << "该节点为:" << endl << Gs[NUM].vertices[temp].data.key << " " << Gs[NUM].vertices[temp].data.others<< endl;
                    }
                        
                }
                break;
            }
            case 4:
            {
                cout << "请输入节点的关键字和value值" << endl;
                KeyType u;
                VertexType value;
                cin >> u >> value.key >> value.others;
                int temp = PutVex(Gs[NUM],u,value);
                if(temp == INFEASIBLE)
                    cout << "图不存在" << endl;
                else
                {
                    if(temp == ERROR)
                        cout << "节点不存在 或 关键字不唯一" << endl;
                    else
                        cout << "赋值完成" << endl;
                }
                break;
            }
            case 5:
            {
                cout << "请输入你要查找的节点的关键字" << endl;
                KeyType u;
                cin >> u;
                int temp = FirstAdjVex(Gs[NUM],u);
                if(temp == -1)
                    cout << "查找失败" << endl;
                else
                {
                    cout << "查找成功,该节点为:" << endl;
                    cout << Gs[NUM].vertices[temp].data.key << " " << Gs[NUM].vertices[temp].data.others << endl;
                }
                break;
            }
            case 6:
            {
                cout << "请输入你要查找的节点的关键字和其邻接顶点的关键字" << endl;
                KeyType u,v;
                cin >> u >> v;
                int temp = NextAdjVex(Gs[NUM],u,v);
                if(temp == INFEASIBLE)
                    cout << "查找失败" << endl;
                else
                {
                    cout << "查找成功,该节点为:" << endl;
                    cout << Gs[NUM].vertices[temp].data.key << " " << Gs[NUM].vertices[temp].data.others << endl;
                }
                break;
            }
            case 7:
            {
                cout << "请输入你要插入的顶点" << endl;
                VertexType v;
                cin >> v.key >> v.others;
                int temp = InsertVex(Gs[NUM],v);
                if(temp == ERROR)
                    cout << "插入失败" << endl;
                else
                    cout << "插入成功" << endl;
                break;
            }
            case 8:
            {
                cout << "请输入你要删除的顶点的关键字" << endl;
                KeyType v;
                cin >> v;
                int temp = DeleteVex(Gs[NUM],v);
                if(temp == ERROR)
                    cout << "删除失败" << endl;
                else
                    cout << "删除成功" << endl;
                break;
            }
            case 9:
            {
                cout << "请输入你要插入的弧" << endl;
                KeyType v,w;
                cin >> v >> w;
                int temp = InsertArc(Gs[NUM],v,w);
                if(temp == ERROR)   cout << "插入失败" << endl;
                else    
                    cout << "插入成功" << endl;
                break;
            }
            case 10:
            {
                cout << "请输入你要删除的弧" << endl;
                KeyType v,w;
                cin >> v >> w;
                int temp = DeleteArc(Gs[NUM],v,w);
                if(temp == ERROR)   cout << "删除失败" << endl;
                else
                    cout << "删除成功" << endl;
                break;
            }
            case 11:
            {
                int temp = DFSTraverse(Gs[NUM],visit);
                if(temp == INFEASIBLE)  
                    cout << "图不存在" << endl;
                else
                    cout << endl << "图深搜遍历完成" << endl;
                break;
            }
            case 12:
            {
                int temp = BFSTraverse(Gs[NUM],visit);
                if(temp == INFEASIBLE)
                    cout << "图不存在" << endl;
                else
                    cout << endl << "图广搜完成" << endl;
                break;
            }
            case 13:
            {
                char *s;
                s = (char*)malloc(sizeof(char) * 100);
                cout << "请输入你要保存的文件名" << endl;
                cin >> s;
                int temp = SaveGraph(Gs[NUM],s);
                if(temp == INFEASIBLE)
                    cout << "图不存在" << endl;
                else
                {
                    if(temp == ERROR)
                        cout << "文件打开失败" << endl;
                    else
                        cout << "文件保存成功" << endl;
                }
                free(s);
                break;
            }
            case 14:
            {
                char *s;
                s = (char*)malloc(sizeof(char) * 100);
                cout << "请输入你要加载的文件名" << endl;
                cin >> s;
                int temp = LoadGraph(Gs[NUM],s);
                if(temp == INFEASIBLE)
                    cout << "图已存在" << endl;
                else
                {
                    if(temp == ERROR)
                        cout << "文件打开失败" << endl;
                    else
                        cout << "文件加载成功" << endl;
                }
                free(s);
                break;  
            }
            case 15:
            {
                KeyType v;
                int k;
                cout << "请输入节点的关键字和长度" << endl;
                cin >> v >> k;
                int temp = VerticesSetLessThanK(Gs[NUM],v,k);
                if(temp == INFEASIBLE)  cout << "图不存在" << endl;
                else
                {
                    if(temp == ERROR)
                        cout << "节点不存在 或 没有规定距离内的邻接节点" << endl;
                    else
                        cout << "查找完毕" << endl;
                }
                break;
            }
            case 16:
            {
                KeyType v,w;
                cout << "请输入要查询的两个节点的关键字" << endl;
                cin >> v >> w;
                int temp = ShortestPathLength(Gs[NUM],v,w);
                if(temp == INFEASIBLE)  cout << "图不存在" << endl;
                else
                {
                    if(temp == 0)
                        cout << "节点错误 或 没有路径" << endl;
                    else
                        cout << "最短路径为: " << temp << endl;
                }
                break;
            }
            case 17:
            {
                int temp = ConnectedComponentsNums(Gs[NUM]);
                if(temp == INFEASIBLE)
                    cout << "图不存在" << endl;
                else
                    cout << "图的连通分量为: " << temp << endl;
                break;
            }
            case 88:
            {
                GraphTraverse(Gs[NUM]);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}