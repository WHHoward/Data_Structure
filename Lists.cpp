#include "list.h"
using namespace std;
int main()
{
    SqList L;
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
	    printf("    	  0. Exit\n");
	    printf("-------------------------------------------------\n");
	    printf("    请选择你的操作[0~12]:");
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
                    cout << "线性表初始化失败" << endl;
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
                    cout << "线性表为空" << endl;
                break;
            }
            case 12:
            {
                cout << "当前线性表如下" << endl;
                int flag = ListTraverse(L);
                if(flag != INFEASIBLE)
                    if(flag == ERROR)   cout << "线性表为空" << endl;
                    else
                        cout <<endl << "线性表遍历完成" << endl;
                else
                    cout << "线性表为空" << endl;
                break;
            }
        }
    }
    return 0;
}