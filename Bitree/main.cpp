#include "bitree.h"
using namespace std;
void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}
BiTree T = NULL;
int main()
{
    int op = 1;
    while(op)
    {
        printf("      Menu for Linear Table On Sequence Structure \n");
	    printf("-------------------------------------------------\n");
	    printf("    	  1. CreateBitree       7. Assign\n");
	    printf("    	  2. DestroyBitree    8. GetSibling\n");
	    printf("    	  3. ClearBitree      9. InsertNode \n");
	    printf("    	  4. BitreeEmpty      10. DeleteNode\n");
	    printf("    	  5. BitreeDepth    11. PreOrderTraverse\n");
	    printf("    	  6. LocateNode        12. InOrderTraverse\n");
        printf("          13. PostOrderTraverse   14.LevelOrderTraverse\n");
        printf("          15.SortList       16.SaveList\n");
        printf("          17.LoadList       18.AddList_1\n");
        printf("          19.AddList_2      20.LocateList\n");
        printf("          21.RemoveList     22.ShowList\n");
        printf("          23.SwitchList     24.UpdateList\n");
	    printf("    	  0. Exit\n");
	    printf("-------------------------------------------------\n");
	    printf("    请选择你的操作[0~24]:");
        cin >> op;
        switch (op)
        {
            case 0:
                break;
            case 1:
            {
                cout << "构建一个二叉树" << endl;
                TElemType definition[100];
                int cnt = 0;
                while(1)
                {
                    cin >> definition[cnt].key >> definition[cnt++].others;
                    if(definition[cnt - 1].key == -1)   break;
                }
                int temp = CreateBiTree(T,definition);
                if(temp == INFEASIBLE)  cout << "二叉树已存在" << endl;
                else
                {
                    if(temp == ERROR)
                        cout << "关键字不唯一" << endl;
                    else    
                    {
                        show(T);
                        cout << "二叉树创建成功" << endl;
                    }        
                }
                memset(definition,0,sizeof(definition));
                break;
            }
            case 2:
            {
                int temp = DestroyBitree(T);
                if(temp == INFEASIBLE)
                    cout << "二叉树不存在无法销毁" << endl;
                else
                    cout << "二叉树已销毁" << endl;
                break;
            }
            case 3:
            {
                if(!T)
                    cout << "二叉树不存在" << endl;
                else
                {
                    ClearBiTree(T->lchild);
                    ClearBiTree(T->rchild);
                    T->data.key = 0;
                    T->data.others[0] = 'n';
                    cout << "二叉树清空成功" << endl;
                }
                break;
            }
            case 4:
            {
                int temp = BiTreeEmpty(T);
                if(temp == INFEASIBLE)  cout << "二叉树不存在" << endl;
                else
                {
                    if(temp == FALSE)   cout << "二叉树为空" << endl;
                    else
                        cout << "二叉树不为空" << endl;
                }
                break;
            }
            case 5:
            {
                int temp = BiTreeDepth(T);
                if(!T)  cout << "二叉树不存在" << endl;
                else
                    cout << "二叉树的长度为: " << temp << endl;
                break;
            }
            case 6:
            {
                if(!T)
                {
                    cout << "二叉树不存在" << endl;
                    break;
                }
                KeyType e = 0;
                cout << "请输入你要查找的节点的关键字" << endl;
                cin >> e;
                BiTree temp = LocateNode(T,e);
                if(temp)
                    cout << "查找成功,该节点如下:" << endl << temp->data.key << " " << temp->data.others << endl;
                else
                    cout << "该节点不存在" << endl;
                break;
            }
            case 7:
            {
                KeyType e;
                TElemType value;
                cin >> e;
                cin >> value.key >> value.others;
                int temp = Assign(T,e,value);
                if(temp == INFEASIBLE)  
                    cout << "二叉树不存在" << endl;
                else
                {
                    if(temp == ERROR)   
                        cout << "节点不存在" << endl;
                    else    
                        cout << "赋值完成" << endl;
                }
                break;
            }
            case 8:
            {
                if(!T)
                {
                    cout << "二叉树不存在" << endl;
                    break;
                }
                else
                {
                    KeyType e;
                    cin >> e;
                    BiTree temp;
                    temp = GetSibling(T,e);
                    if(temp)
                        cout << "查找成功,节点如下:" << endl << temp->data.key << " " << temp->data.others << endl;
                    else
                        cout << "没有兄弟节点" << endl;
                }
                break;
            }
            case 9:
            {
                KeyType e;
                int LR;
                TElemType c;
                cin >> e >> LR >> c.key >> c.others;
                status temp;
                temp = InsertNode(T,e,LR,c);
                if(temp == INFEASIBLE)
                    cout << "节点关键字不唯一" << endl;
                else
                {
                    if(temp == ERROR)   
                        cout << "插入操作失败" << endl;
                    else
                        cout << "插入成功" << endl;
                }
                break;
            }
            case 10:
            {
                if(!T)  
                    cout << "二叉树不存在" << endl;
                else    
                {
                    status temp;
                    KeyType e;
                    cin >> e;
                    temp = DeleteNode(T,e);
                    if(temp == ERROR)   
                        cout << "删除操作失败" << endl;
                    else
                        cout << "删除成功" << endl;
                }
                break;
            }
            case 11:
            {
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    cout << "前序遍历如下" << endl;
                    PreOrderTraverse(T,visit);
                    cout << endl;
                }
                break;
            }
            case 12:
            {
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    cout << "中序遍历如下" << endl;
                    InOrderTraverse(T,visit);
                    cout << endl;
                }
                break;
            }
            case 13:
            {
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    cout << "后序遍历如下" << endl;
                    PostOrderTraverse(T,visit);
                    cout << endl;
                }
                break;
            }
            case 14:
            {
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    cout << "按层序遍历如下" << endl;
                    LevelOrderTraverse(T,visit);
                    cout << endl;
                }
                break;
            }
            case 15:
            {
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    int ans = 0;
                    ans = MaxPathSum(T);
                    cout << "最大路径和为: " << ans << endl;
                }
                break;
            }
            default:
                break;
        }
    }
    return 0;
}