#include "list.h"
using namespace std;
LinkList L;
ListsGroup LL;
LISTS Lists;
int main()
{
    L = NULL;
    LL = (ListsGroup)malloc(sizeof(ListsNode));
    LL->next = NULL;
    int op = 1;
    while(op)
    {
        printf("      Menu for Linear Table On Sequence Structure \n");
	    printf("-------------------------------------------------\n");
	    printf("    	  1. InitList       7. LocateElem\n");
	    printf("    	  2. DestroyList    8. PriorElem\n");
	    printf("    	  3. ClearList      9. NextElem \n");
	    printf("    	  4. ListEmpty      10. ListInsert\n");
	    printf("    	  5. ListLength     11. ListDelete\n");
	    printf("    	  6. GetElem        12. ListTraverse\n");
        printf("          13. ReverseList   14.NumRemoveNthFromEnd\n");
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
                return 0;
            case 1:
            {
                if(InitList(L) == OK)   
                    cout << "线性表初始化完成"<<endl;
                else    
                    cout << "线性表无需初始化" << endl;
                break;
            }
            case 2:
            {
                if(DestroyList(L) == OK)    
                    cout << "线性表销毁完成" << endl;
                else
                    cout << "线性表销毁失败" << endl;
                break;
            }
            case 3:
            {
                if(ClearList(L) == OK)  
                    cout << "线性表清除完成" << endl;
                else    
                    cout << "线性表清除失败" << endl;
                break;
            }
            case 4:
            {
                int temp = ListEmpty(L);
                if(temp == TRUE)    cout << "线性表为空" << endl;
                else    
                    if(temp == FALSE)   cout << "线性表不为空" << endl;
                    else    
                        cout << "线性表不存在" << endl;
                break;
            }
            case 5:
            {
                int temp = ListLength(L);
                if(temp != INFEASIBLE)  cout << "线性表的长度为: " << temp << endl; 
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 6:
            {
                cout << "请输入要取出的元素位置" << endl;
                int temp;
                cin >> temp;
                int temp2;
                int temp3 = GetElem(L,temp,temp2);
                if(temp3 != INFEASIBLE)
                    if(temp3 != ERROR)
                        cout << "你所取出的元素为 " <<  temp2 << endl;
                    else    
                        cout << "输入了错误的位置"<< endl;
                else
                    cout << "线性表不存在" << endl;
                break;
            }
            case 7:
            {
                cout << "请输入你要定位的元素" << endl;
                int temp;
                cin >> temp;
                int flag = LocateElem(L,temp);
                if(flag != INFEASIBLE)  
                    if(flag == 0)   cout << "该元素不在该线性表中" << endl;
                    else
                        cout << "元素所在位置为" << flag << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 8:
            {
                cout << "请输入你要取得前继的元素" << endl;
                int temp,temp1;
                cin >> temp;
                int flag = PriorElem(L,temp,temp1);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)
                        cout << "该元素不在该线性表中或该元素位于该线性表的首位" << endl;
                    else    
                        cout << "该元素的前继为" << temp1 << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 9:
            {
                cout << "请输入你要取得前继的元素" << endl;
                int temp,temp1;
                cin >> temp;
                int flag = NextElem(L,temp,temp1);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)
                        cout << "该元素不在该线性表中或该元素位于该线性表的末位" << endl;
                    else    
                        cout << "该元素的后继为" << temp1 << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 10:
            {
                cout << "请输入你要插入的元素以及其位置" << endl;
                int pos,value;
                cin >> value >> pos;
                int flag = ListInsert(L,pos,value);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)
                        cout << "你输入了一个非法的位置" << endl;
                    else   
                        cout << "插入成功" << endl;
                else
                    cout << "线性表不存在" << endl;
                break;
            }
            case 11:
            {
                cout << "请输入你要删除的元素的位置" << endl;
                int pos,value;
                cin >> pos;
                int flag = ListDelete(L,pos,value);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)
                        cout << "你输入了一个非法的位置" << endl;
                    else    
                        {
                            cout << "删除成功" << endl;
                            cout << "你删除的元素为" << value << endl;
                        }
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 12:
            {
                cout << "当前线性表如下" << endl;
                int flag = ListTraverse(L);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)   cout << "线性表为空" << endl;
                    else
                        cout << endl << "线性表遍历完成" << endl;
                else
                    cout << "线性表不存在" << endl;
                break;
            }
            case 13:
            {
                cout << "将当前线性表进行翻转" << endl;
                int flag = ReverseList(L);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)   cout << "线性表为空" << endl;
                    else    
                        cout << "线性表翻转完成" << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 14:
            {
                cout << "请输入你要删除倒数第几个节点" << endl;
                int temp;
                cin >> temp;
                int flag = RemoveNthFromEnd(L,temp);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)
                        cout << "输入了一个非法的位置" << endl;
                    else
                        cout << "删除成功" << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 15:
            {
                cout << "将当前的线性表进行排序" << endl;
                int temp;
                temp = SortList(L);
                if(temp != INFEASIBLE)
                    if(temp == ERROR)   cout << "线性表为空" << endl;
                    else    
                        cout << "排序成功" << endl;
                else    
                    cout << "线性表不存在" << endl;
                break;
            }
            case 16:
            {
                cout << "请输入你要保存线性表的文件的文件名" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = SaveList(L,s);
                if(temp != INFEASIBLE)     
                    if(temp == OK)  cout << "线性表保存成功" << endl;
                    else    cout << "文件打开失败" << endl;
                else
                    cout << "线性表不存在" << endl;   
                free(s);
                break;
            }
            case 17:
            {
                cout << "请输入你要加载的文件的文件名" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp =  LoadList(L,s);
                if(temp != INFEASIBLE)     
                    if(temp == OK)  cout << "线性表加载成功" << endl;
                    else    cout << "文件打开失败" << endl;
                else
                    cout << "线性表已存在无法写入" << endl;   
                free(s);
                break;
            }
            case 18:
            {
                cout << "将创建一个空的线性表插入在线性表组的末尾" << endl;
                cout << "请输入该线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = AddList_1(LL,s);
                cout << "插入成功" << endl;
                free(s);
                break;
            }
            case 19:
            {
                cout << "将当前的线性表插入到线性表组的末尾" << endl;
                cout << "请输入该线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = AddList_2(LL,s,L);
                if(temp != INFEASIBLE)
                    cout << "插入成功" << endl;
                else
                    cout << "线性表不存在" << endl;
                free(s);
                break;
            }
            case 20:
            {
                cout << "请输入需要定位的线性的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = LocateList(LL,s);
                if(temp)
                    cout << "线性表在组中的位置为 " << temp << endl;
                else    
                    cout << "未在线性表组中找到该线性表" << endl;
                free(s);
                break;
            }
            case 21:
            {
                cout << "请输入需要删除的线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = RemoveList(LL,s);
                if(temp != ERROR)
                    cout << "删除成功！" << endl;
                else
                    cout << "该线性表不在该线性表组中" << endl;
                free(s);
                break;
            }
            case 22:
            {
                cout << "线性表组如下" << endl;
                int temp = ShowList(LL);
                if(temp == 0)   
                    cout << "该线性表组为空" << endl;
                break;
            }
            case 23:
            {
                int temp;
                cout << "请输入要切换的线性表的序号" << endl;
                cin >> temp;
                int temp1 = SwitchList(LL,temp,L);
                if(temp1 == OK) 
                    cout << "切换成功" << endl;
                else    
                    cout << "输入了错误的序号" << endl;
                break;
            }
            case 24:
            {
                int temp;
                cout << "将线性表组中的某一线性表更新为该线性表" << endl;
                cout << "请输入要更新的线性表的序号" << endl;
                cin >> temp;
                int temp1 = UpdateList(LL,temp,L);
                if(temp1 == OK) 
                    cout << "更新成功" << endl;
                else    
                    cout << "输入了错误的序号" << endl;
                break;
            }
        }
    }
    return 0;
}
/*
            case 15:
            {
                cout << "对线性表进行排序" << endl;
                int temp = SortList(L);
                if(temp != INFEASIBLE)
                    if(temp == ERROR)   cout << "线性表为空" << endl;
                    else
                        cout << "排序已完成" << endl;
                else    
                    cout << "线性表不存在" << endl; 
                break;
            }
            case 16:
            {
                cout << "请输入你要保存线性表的文件的文件名" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = SaveList(L,s);
                if(temp != INFEASIBLE)     
                    if(temp == OK)  cout << "线性表保存成功" << endl;
                    else    cout << "文件打开失败" << endl;
                else
                    cout << "线性表不存在" << endl;   
                free(s);
                break;
            }
            case 17:
            {
                cout << "请输入你要加载的文件的文件名" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp =  LoadList(L,s);
                if(temp != INFEASIBLE)     
                    if(temp == OK)  cout << "线性表加载成功" << endl;
                    else    cout << "文件打开失败" << endl;
                else
                    cout << "线性表已存在无法写入" << endl;   
                free(s);
                break;
            }
            case 18:
            {
                cout << "将创建一个空的线性表插入在线性表组的末尾" << endl;
                cout << "请输入该线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = AddList_1(Lists,s);
                cout << "插入成功" << endl;
                free(s);
                break;
            }
            case 19:
            {
                cout << "将当前的线性表插入到线性表组的末尾" << endl;
                cout << "请输入该线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = AddList_2(Lists,s,L);
                if(temp != INFEASIBLE)
                    cout << "插入成功" << endl;
                else
                    cout << "线性表不存在" << endl;
                free(s);
                break;
            }
            case 20:
            {
                cout << "请输入需要定位的线性的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = LocateList(Lists,s);
                if(temp)
                    cout << "线性表在组中的位置为 " << temp << endl;
                else    
                    cout << "未在线性表组中找到该线性表" << endl;
                free(s);
                break;
            }
            case 21:
            {
                cout << "请输入需要删除的线性表的名字" << endl;
                char *s;
                s = (char *)malloc(sizeof(char) * 1000);
                cin >> s;
                int temp = RemoveList(Lists,s);
                if(temp != ERROR)
                    cout << "删除成功！" << endl;
                else
                    cout << "该线性表不在该线性表组中" << endl;
                free(s);
                break;
            }
            case 22:
            {
                cout << "线性表组如下" << endl;
                int temp = ShowList(Lists);
                if(temp == 0)   
                    cout << "该线性表组为空" << endl;
                break;
            }
            case 23:
            {
                int temp;
                cout << "请输入要切换的线性表的序号" << endl;
                cin >> temp;
                int temp1 = SwitchList(Lists,temp,L);
                if(temp1 == OK) 
                    cout << "切换成功" << endl;
                else    
                    cout << "输入了错误的序号" << endl;
                break;
            }
            case 24:
            {
                int temp;
                cout << "将线性表组中的某一线性表更新为该线性表" << endl;
                cout << "请输入要更新的线性表的序号" << endl;
                cin >> temp;
                int temp1 = UpdateList(Lists,temp,L);
                if(temp1 == OK) 
                    cout << "更新成功" << endl;
                else    
                    cout << "输入了错误的序号" << endl;
                break;
            }
*/