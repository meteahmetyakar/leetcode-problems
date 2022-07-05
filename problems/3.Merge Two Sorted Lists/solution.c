struct ListNode* insert(struct ListNode* list, int val)
{    
    
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(list->val >= val)
    {
        temp->val = val;
        temp->next = list;
        return temp;
    }
    
    struct ListNode* iter = list;
    while(iter->next != NULL && iter->next->val < val)
    {
        iter = iter->next;
    }
    
    temp->next = iter->next;
    temp->val = val;
    iter -> next = temp;
    
    return list;
    

    
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    
    struct ListNode *shortList, *longList, *iter1, *iter2;
    
    shortList = list2;
    longList = list1;
    
    iter1 = list1;
    iter2 = list2;
    
    while(iter1 != NULL && iter2 != NULL)
    {
        if(iter1->next == NULL && iter2->next != NULL)
        {
            shortList = list1;
            longList = list2;
            break;
        }
        
        iter1 = iter1->next;
        iter2 = iter2->next;
        
    }
    
    while(shortList != NULL)
    {
        longList = insert(longList, shortList->val);
        shortList = shortList->next;
    }
    
    
    return longList;
}