#include "list.h"
#include  "def.h"
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
	    printf("    	  2. DestroyList8. PriorElem\n");
	    printf("    	  3. ClearList       9. NextElem \n");
	    printf("    	  4. ListEmpty     10. ListInsert\n");
	    printf("    	  5. ListLength     11. ListDelete\n");
	    printf("    	  6. GetElem       12. ListTrabverse\n");
	    printf("    	  0. Exit\n");
	    printf("-------------------------------------------------\n");
	    printf("    请选择你的操作[0~12]:");
        cin >> op;
        switch (op)
        {
            case 1:
                if(InitList(L) == OK)   cout << "";
                break;
        
            default:
                break;
        }
    }
    return 0;
}