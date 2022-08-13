
// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>

//CMPE13 Support Library
#include "BOARD.h"


// User libraries
#include "LinkedList.h"


// **** Declare any function prototypes here ***
ListItem *CreateUnsortedList(void); //this function has been written for you
ListItem *SelectionSort(ListItem* list);
ListItem *InsertionSort(ListItem* list);


/* Students should not need to modify main! */
int main(void)
{
    BOARD_Init();

    printf("\n\nWelcome to CRUZID's sort.c, compiled on %s %s.\n", __DATE__, __TIME__);

    ListItem* listToSort;

    //Do a timing test 
    printf("\nStarting stopwatch for selection sort...\n");
    listToSort = CreateUnsortedList();
    __asm("nop"); //put a breakpoint on this line
    listToSort = SelectionSort(listToSort);
    __asm("nop"); //put a breakpoint on this line, and record the stopwatch time
    LinkedListPrint(listToSort);


    printf("\nStarting stopwatch for insertion sort...\n");
    listToSort = CreateUnsortedList();
    __asm("nop"); //put a breakpoint on this line
    listToSort = InsertionSort(listToSort);
    __asm("nop"); //put a breakpoint on this line, and record the stopwatch time
    LinkedListPrint(listToSort);

    BOARD_End();
    while (1);
    return 0;
}

/**
 * SelectionSort() performs a selection sort on a passed to it.  The list is sorted alphabetically,
 * as determined by string.h's strcmp().  
 *
 * @param list Any element in a linked list to sort.  
 * @return a pointer to the head of the sorted list.
 * 
 * SelectionSort() assumes that no list items have a NULL data member.  It also assumes that 'list'
 * is a valid, non-NULL pointer to a linked list.
 * 
 * This function does not print.
 */
ListItem *SelectionSort(ListItem* list)
{
   //YOUR CODE GOES HERE!
   /*FU is pointer to first item
         while FU is not tail:
            S is pointer to FU’s nextItem
            while S is in list:
               if FU > S:
                  swap FU and S contents
               advance S
            advance FU
   */
   //printf("Selection Sort Start:\n");
   ListItem *FU = LinkedListGetFirst(list);
   //printf("First Item in List:%p\n",FU->data);
   while(FU->nextItem !=NULL){
       //printf("S:%p\n",FU->nextItem);
       ListItem *S = FU->nextItem;
       while(S !=NULL){
           if(strcmp((FU->data),(S->data))>0)
           {
               //printf("Swap:%s and %s\n",FU->data,S->data);
               LinkedListSwapData(FU,S);
           }
           S = S->nextItem;
           //printf("S(increment):%p\n",FU->nextItem);
       }
       FU = FU->nextItem;
       //printf("FU(increment):%p\n",FU->nextItem);
   }
   //printf("\nSORT FINISHED\n");
   return LinkedListGetFirst(list);
   
   
}

/**
 * InsertionSort() performs an insertion sort on a passed to it.  The list is sorted alphabetically,
 * as determined by string.h's strcmp().  
 *
 * @param list Any element in a linked list to sort.  
 * @return a pointer to the head of the sorted list.
 * 
 * SelectionSort() assumes that no list items have a NULL data member.  It also assumes that 'list'
 * is a valid, non-NULL pointer to a linked list.
 * 
 * This function does not print.
 */
ListItem *InsertionSort(ListItem* list)
{
   //YOUR CODE GOES HERE!
//     printf("Insertion Sort Start:\n");
   /* FS = tail of list
 while FS is not head of list:
    LU = FS’s previous item
    if LU < FS:
FS = LU else:
         S = FS
         while (S is not tail of list):
            if S's next item is greater than LU:
               break
            else:
               S = S's next item
         remove LU item
         re-insert after S*/
    //printf("--------------------------\n");
//    printf("Start List:\n");
//    printf("--------------------------\n");
//    LinkedListPrint(list);
//    printf("--------------------------\n");
    ListItem *FS = LinkedListGetLast(list);
//     printf("\nList Last:%p\n",LinkedListGetLast(list));
//    printf("\nList Last Data:%s\n",LinkedListGetLast(list)->data);
//    //printf("List Last Next Data:%s",LinkedListGetLast(list)->nextItem);
//    printf("\nFS Last:%p\n",FS);
//    printf("\nFS Last Data:%s\n",FS->data);
    //printf("FS Last Next Data:%s",FS->nextItem);
    ListItem *S;
    ListItem *LU;
    //printf("\nFS ASSIGNED\n");
    while(FS->previousItem != NULL){
//        printf("\nFS->previous NOT NULL\n");
        LU = FS->previousItem;
//        printf("\nLU ASSIGNED:%s\n",LU->data);       
        if(strcmp((FS->data),(LU->data))>0)
        {
            FS = LU;
//            printf("\nFS = LU DONE\n");
//            
        }
        else
        {
            S = FS;
//            printf("\nBeginning of S loop\n");
//            printf("\nS = FS DONE\n");
//            printf("\nS:%s\n",S->data);
            //printf("\nS->Next:%p\n",S->nextItem);
            //
            while(S->nextItem != NULL)
            {
                if(strcmp((S->nextItem->data),(LU->data))>0)
                {
//                    printf("\nNO INSERTION NEEDED for %s and %s.\n",(S->nextItem->data),(LU->data));
                    break;
                }
                else
                {
//                    printf("Advancing S\n");
//                    printf("--------------------------\n");
//                    printf("\nSDATA:%s\n",S->data);
                  
//                    printf("\nList Last:%p\n",LinkedListGetLast(list));
//                    printf("\nList Last Data:%s\n",LinkedListGetLast(list)->data);
                    S = S->nextItem;
                    
//                    printf("\nList Last:%p\n",LinkedListGetLast(list));
//                    printf("\nList Last Data:%s\n",LinkedListGetLast(list)->data);
//                    printf("\nS = S->NEXT DONE\n");
//                    printf("\nSDATA:%s\n",S->data);
                    //printf("\nWhat is S:%p\n",S);
//                    printf("--------------------------\n");
    //                
                }
//            printf("\nLast of S Loop\n");
//            printf("\nFS Last:%p\n",FS);
//            printf("\nFS Last Data:%s\n",FS->data);
//            printf("\nS Last:%p\n",S);
//            printf("\nS Last Data:%s\n",S->data);
            //LinkedListGetLast(list)->nextItem = NULL;
//            printf("\nList Last:%p\n",LinkedListGetLast(list));
//            printf("\nList Last Data:%s\n",LinkedListGetLast(list)->data);
//            printf("\nS:%s\n",S->data);
//            printf("\nS->Next:%p\n",S->nextItem);
            }
//            printf("\nREINSERT STARTED\n");
            LinkedListRemove(LU);
//            printf("\nItem to Insert after:%s\n",S->data);
//            printf("\nS equals null?%p\n",S->data);
//            printf("\nLU:%s\n",LU->data);
            //printf("FS next item:%p\n",FS->nextItem);
            //printf("LU(next):%s\n",LU->data);
            //printf("S next previous item:%p\n",S->nextItem->previousItem);
            LinkedListCreateAfter(S,LU->data);
            
            //printf("FS Last:%p\n",FS);
            //printf("FS Last Data:%s\n",FS->data);
            //LU->nextItem = FS->nextItem;
            /*printf("LU(Created):%s\n",LU->data);
            printf("--------------------------\n");
            printf("Current List:\n");
            printf("--------------------------\n");
            LinkedListPrint(LU);
            printf("--------------------------\n");*/
//            printf("--------------------------\n");
//            LinkedListPrint(S);
//            printf("--------------------------\n");
//            LinkedListPrint(list);
//            printf("\nS Item:%p\n",LinkedListGetLast(S)->data);
//            printf("\nS Item's Next Item:%p\n",LinkedListGetLast(S)->nextItem);
            
        }
        //LinkedListPrint(list);
//        printf("\nEND OF FS LOOP ITERATION\n");
    }
//    printf("\nSORT FINISHED\n");
    return LinkedListGetFirst(list);
   
}

/* CreateUnsortedList() uses the functions in the LinkedList library to
 * generate an unsorted list.  
 * 
 * Students should not modify this function!
 * If an error occurs in this function, there is almost certainly 
 * a bug in your implementation of LinkedList.h.
 *   
 * @return A pointer to a ListItem which is the head of a new unsorted list. 
 */
ListItem *CreateUnsortedList(void)
/// <editor-fold defaultstate="collapsed" desc="CreateUnsortedList definition">
{
 char* wordList[] = {
        "decide",   "toothpaste",   "lowly",        "robin",        "reign",        "crowd",
        "pies",     "reduce",       "tendency",     "surround",     "finger",       "rake", 
        "alleged",  "hug",          "nest",         "punishment",   "eggnog",       "side", 
        "beef",     "exuberant",    "sort",         "scream",       "zip",          "hair", 
        "ragged",   "damage",       "thought",      "jump",         "frequent",     "substance",
        "head",     "step",         "faithful",     "sidewalk",     "pig",          "raspy",
        "juggle",   "shut",         "maddening",    "rock",         "telephone",    "selective",
        NULL};
    //  char* wordList[] = {"D", "A", "C", "E", "B", NULL};


    int i = 0;
    ListItem* head = LinkedListNew(wordList[i]);
    ListItem* tail = head;
    for (i = 1; wordList[i] != NULL; i++) {
        tail = LinkedListCreateAfter(tail, wordList[i]);
        if(tail == NULL){
            printf("ERROR:  Heap full! Please increase heap size.\n");
            FATAL_ERROR();
        }
    }
    return head;
}
// </editor-fold>
