#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BOARD.h"

void fail(void){printf("Malloc failed. Memory could not be allocated."); exit(EXIT_FAILURE); }

ListItem *LinkedListNew(char *data){
    //printf("BEGINNING CREATE NEW ITEM:\n");
    ListItem *new = (ListItem *) malloc(sizeof(ListItem));
    //printf("MALLOCed\n");
    if(new==NULL) 
    {
        return NULL;
        fail();
    }
    //printf("MALLOC SUCCESS\n");
    new->data = data;
    new->nextItem = NULL;
    new->previousItem = NULL;
    //printf("DATA ADDED\n");
    //printf("Data:%c\n",*(l->data));
    return new;
}


ListItem *LinkedListCreateAfter(ListItem *item, char *data){
    //printf("BEGINNING CREATE AFTER:\n");
    if(item==NULL){
        //printf("It's null");
        return NULL;
    }
    ListItem *after = LinkedListNew(data);
    
    //printf("CREATED ITEM:\n");
    //printf("Item added Address:%p\n",after);
    if(item->nextItem!=NULL)
    {
        //printf("ITEM NEXT NOT NULL\n");
        after->previousItem = item;
        after->nextItem = item->nextItem;
        item->nextItem->previousItem = after;
        item->nextItem = after;
        
    }
    else
    {
        //printf("ITEM NEXT NOT NULL\n");
        item->nextItem = after;
        //printf("Existing Item, nextItem address:%p\n",item->nextItem);
        after->previousItem = item;
    }
    //printf("Added Item, previousItem address:%p\n",after->previousItem);
    //printf("Added Item, nextItem address:%p\n",after->nextItem);
    return after;
}
/**
 * This function will remove a list item from the linked list and free() the memory that the
 * ListItem struct was using. It doesn't, however, free() the data pointer and instead returns it
 * so that the calling code can manage it.  If passed a pointer to NULL, LinkedListRemove() should
 * return NULL to signal an error.
 *
 * @param item The ListItem to remove from the list.
 * @return The data pointer from the removed item. May be NULL.
 */
char *LinkedListRemove(ListItem *item){
    
    //printf("BEGIN REMOVE\n");
    //printf("--------------------------\n");
    if(item==NULL){
        //printf("It's null");
        return NULL;
    }
    if((item->previousItem) == NULL)
    {
        //printf("Header detected\n");
        item->nextItem->previousItem = NULL;
     //   item->nextItem = NULL;
    }
    else if((item->nextItem) == NULL)
    {
        //printf("Tail detected\n");
        item->previousItem->nextItem = NULL;
    //    item->previousItem = NULL;
    }
    else
    {
        //printf("PreviousItem's Next Item Ref Before Remove:%p\n",item->previousItem->nextItem);
        item->previousItem->nextItem = item->nextItem;
        //printf("PreviousItem's Next Item Ref After Remove:%p\n",item->previousItem->nextItem);
        //printf("NextItem's Previous Item Ref Before Remove:%p\n",item->nextItem->previousItem);
        item->nextItem->previousItem = item->previousItem;
        //printf("NextItem's Previous Item Ref After Remove:%p\n",item->nextItem->previousItem);
    //    item->nextItem = NULL;
    //    item->previousItem = NULL;
    }
    
    char *dp = item->data;
    free(item);
    
    return dp;
    
}

int LinkedListSize(ListItem *list){
    int ls = 1;
    if(list==NULL){
        //printf("It's null");
        //return NULL;
    }
    //printf("BEGIN SIZE CALC\n");
    //printf("--------------------------\n");
    ListItem *prev = (list->previousItem);
    //printf("Prev1:%p\n", list->previousItem);
    //printf("Prev:%p\n", prev);
    ListItem *next = list->nextItem;
    //printf("next1:%p\n", list->nextItem);
    //printf("next:%p\n", next);
    while(prev != NULL)
    {
        prev = prev->previousItem;
        //printf("prev++\n");
        ls++;
    }
    while(next != NULL)
    {
        next = next->nextItem;
        //printf("next:%p\n", next);
        ls++;
    }
    return ls;
}
/**
 * This function returns the head of a list given some element in the list. If it is passed NULL,
 * it will just return NULL. If given the head of the list it will just return the pointer to the
 * head anyways for consistency.
 *
 * @param list An element in a list.
 * @return A pointer to the first element in the list. Or NULL if provided an invalid list.
 */
ListItem *LinkedListGetFirst(ListItem *list){
    /*
    printf("--------------------------\n");
    printf("GET FIRST EXECUTED\n");
    printf("--------------------------\n");*/
    if(list==NULL){
        //printf("It's null");
        return NULL;
    }
    if((list->previousItem) == NULL)
    {
      //printf("prev item null\n");
       return list; 
    }
    else {
    while((list->previousItem) != NULL)
    {
        //printf("prev item not null\n");
        //printf("prev item:%p\n",list->previousItem);
        list = list->previousItem;
    }
    return list;
    }
    
    
}

ListItem *LinkedListGetLast(ListItem *list){
    //printf("BEGIN GET LAST\n");
    //printf("--------------------------\n");
    if(list==NULL){
        //printf("It's null");
        return NULL;
    }
    if((list->nextItem) == NULL)
    {
      //printf("next item null\n");
       return list; 
    }
    else {
    while((list->nextItem) != NULL)
    {
        //printf("next item not null\n");
        //printf("next item:%p\n",list->nextItem);
        list = list->nextItem;
    }
    return list;
    }
}

/**
 * LinkedListSwapData() switches the data pointers of the two provided ListItems. This is most
 * useful when trying to reorder ListItems but when you want to preserve their location. This
 * function should return STANDARD_ERROR if either arguments are NULL, otherwise it should return
 * SUCCESS. If one or both of the data pointers are NULL in the given ListItems, it still does
 * perform the swap and returns SUCCESS.
 *
 * @param firstItem One of the items whose data will be swapped.
 * @param secondItem Another item whose data will be swapped.
 * @return SUCCESS if the swap worked or STANDARD_ERROR if it failed.
 */
int LinkedListSwapData(ListItem *firstItem, ListItem *secondItem){
    // int STANDARD_ERROR, SUCCESS;
    if(((firstItem->data) ==NULL) || ((secondItem->data) == NULL))
    {
        return STANDARD_ERROR;
    }
    else{
        char *first = firstItem->data;
        char *second = secondItem->data;
        firstItem->data = second;
        //printf("firstItem new Data:%c\n",*(firstItem->data));
        secondItem->data = first;
        //printf("secondItem new Data:%c\n",*(secondItem->data));
        return SUCCESS;
    }
}

int LinkedListPrint(ListItem *list){
    // int STANDARD_ERROR, SUCCESS;
    if(list==NULL){
        //printf("It's null");
        return STANDARD_ERROR;
    }
    ListItem *p = LinkedListGetFirst(list);
    //printf("FirstPrint:%p\n ",p);
    while(p !=NULL){
        printf("%s ",(p->data));
        p = p->nextItem;
    }
    printf("\n");
    return SUCCESS;
}
