
#include "newfile.h"
using namespace std;


head = cur;

void List::createList(int k){
    ListNode *cur = NULL;
    
    for(int i=1; i<=k; i++){
        
        cur = new ListNode;
        cur->item = i;
        
        cur->next = head;
        head = cur;
    }
    
    size = k;
}