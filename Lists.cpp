#include "list.h"
using namespace std;
int main()
{
    SqList L;
    int op;
    while(op)
    {
        printf("      Menu for Linear Table On Sequence Structure \n");
	    printf("-------------------------------------------------\n");
	    printf("    	  1. InitList       7. LocateElem\n");
	    printf("    	  2. DestroyList    8. PriorElem\n");
	    printf("    	  3. ClearList      9. NextElem \n");
	    printf("    	  4. ListEmpty      10. ListInsert\n");
	    printf("    	  5. ListLength     11. ListDelete\n");
	    printf("    	  6. GetElem        12. ListTrabverse\n");
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
        }
    }
    return 0;
}