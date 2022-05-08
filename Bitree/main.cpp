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
	    printf("    	  2. DestroyBitree      8. GetSibling\n");
	    printf("    	  3. ClearBitree        9. InsertNode \n");
	    printf("    	  4. BitreeEmpty        10. DeleteNode\n");
	    printf("    	  5. BitreeDepth        11. PreOrderTraverse\n");
	    printf("    	  6. LocateNode         12. InOrderTraverse\n");
        printf("          13.PostOrderTraverse  14.LevelOrderTraverse\n");
        printf("          15.MaxPathSum         16.LowestCommonAncestor\n");
        printf("          17.InvertTree         18.SaveBitree\n");
        printf("          19.LoadBitree         20.AddBiTree1\n");
        printf("          21.AddBiTree2         22.DeleteBiTree\n");
        printf("          23.ShowBiTree         24.UpdateBiTree\n");
	    printf("    	  25.SwitchBiTree       0. Exit\n");
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
            case 16:
            {
                KeyType e1,e2;
                if(!T)  cout << "二叉树不存在" << endl;
                else
                {
                    cin >> e1 >> e2;
                    BiTree temp;
                    temp = LowestCommonAncestor(T,e1,e2);
                    cout << "最近公共祖先如下:" << endl << temp->data.key << " " << temp->data.others << endl;
                }
                break;
            }
            case 17:
            {
                status temp = InvertTree(T);
                if(temp == INFEASIBLE)
                    cout << "二叉树不存在" << endl;
                else
                    cout << "二叉树翻转完成" << endl;
                break;
            }
            case 18:
            {
                char *s;
                cout << "请输入你要保存的文件的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                int temp = SaveBiTree(T,s);
                if(temp == INFEASIBLE)
                    cout << "二叉树不存在" << endl;
                else
                    if(temp == ERROR)
                        cout << "文件打开失败" << endl;
                    else
                        cout << "保存成功" << endl;
                free(s);
                break;
            }
            case 19:
            {
                char *s;
                cout << "请输入你要保存的文件的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                int temp = LoadBiTree(T,s);
                if(temp == INFEASIBLE)
                    cout << "二叉树已存在,无法加载" << endl;
                else
                    if(temp == ERROR)
                        cout << "文件打开失败" << endl;
                    else
                        cout << "加载成功" << endl;
                free(s);
                break;
            }
            case 20:
            {
                char *s;
                cout << "请输入你要保存的空的二叉树的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                AddBiTree_1(s);
                free(s);
                cout << "插入成功" << endl;
                break;
            }
            case 21:
            {
                char *s;
                cout << "请输入你要保存的二叉树的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                AddBiTree_2(T,s);
                free(s);
                cout << "插入成功" << endl;
                break;
            }
            case 22:
            {
                char *s;
                cout << "请输入你要删除二叉树的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                int temp = DeleteBiTree(s);
                free(s);
                if(temp == OK)
                    cout << "删除成功" << endl;
                else
                    cout << "该二叉树不存在" << endl;
                break;
            }
            case 23:
            {
                cout << "二叉树组如下" << endl;
                ShowBiTree();
                break;
            }
            case 24:
            {
                char *s;
                cout << "请输入你要更新的二叉树的名字" << endl;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                int temp = UpdateBiTree(T,s);
                free(s);
                if(temp == OK)
                    cout << "更新成功" << endl;
                else
                    cout << "该二叉树不存在" << endl;
                break;
            }
            case 25:
            {
                cout << "请输入你要切换二叉树的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 100);
                cin >> s;
                int temp = SwitchBiTree(T,s);
                free(s);
                if(temp == OK)
                    cout << "切换成功" << endl;
                else
                    cout << "该二叉树不存在" << endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}