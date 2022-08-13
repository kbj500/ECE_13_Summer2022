/*******************************************************************************

                TEST HARNESS FOR MATRIX MATH FUNCTIONS
        This file outputs test results for functions in MatrixMath.c
    **Must have MatrixMath.h header file in directory for compilation**

db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b
88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'    
88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo
Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ 
`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.   
`8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P 
    
*******************************************************************************/

// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//User Library
#include "LinkedList.h"

//CMPE13 Support Library
#include "BOARD.h"


int main()
{
    char *alphabet[] = {"a","b","c","d","e","f","g"}; //sample list of chars for testing
    /* varaibles for each function (except MatrixPrint), to count # of tests passed */
    int llnPass = 0;
    int llcaPass = 0;
    int llrPass = 0;
    int llsPass = 0;
    int llgfPass = 0;
    int llglPass = 0;
    void testPassedAddress(ListItem* l, ListItem* h, int* pass)
  {
    if (l->nextItem == h->previousItem)
    {
        *pass = *pass + 1;
    }
     
  }
     void testPassedAddressAfter(ListItem* l, ListItem* h, int* pass)
  {
    if (l->nextItem == h)
    {
        *pass = *pass + 1;
    }
     
  }
    void testPassedData(ListItem* l, char* c, int* pass)
  {
    if (strcmp((l->data),c)==0)
    {
        *pass = *pass + 1;
    }
     
  }
    
    
    printf ("************************** \n");
    printf("***TEST HARNESS START:***\n");
    printf ("**************************\n");
    
    printf ("************************** \n");
    printf ("** LinkedListNew() Check **\n");
    printf ("**************************\n");
    
    ListItem* l1 = LinkedListNew(alphabet[0]);       //created new List Item
    printf("\nAction: Created new Linked List L1\n");
    printf("\nOutput:\n");
    printf("\nL1Data:%c\n",*(l1->data));
    printf("L1Prev:%p\n",l1->previousItem);
    printf("L1Next:%p\n",l1->nextItem);
    printf("\nExpected Output:\n");
    printf("\nL1Data:%s\n","a");
    printf("L1Prev:%p\n",NULL);
    printf("L1Next:%p\n",NULL);
    
    
    testPassedAddress(l1,l1,&llnPass);
    testPassedData(l1,alphabet[0],&llnPass);
    
    
    printf ("**************************\n");
    
    ListItem* h1 = LinkedListNew(alphabet[1]);       //created new List Item
    printf("\nAction: Created new Linked List H1\n");
    printf("\nOutput:\n");
    printf("\nH1Data:%c\n",*(h1->data));
    printf("H1Prev:%p\n",(h1->previousItem));
    printf("H1Next:%p\n",(h1->nextItem));
    printf("\nExpected Output:\n");
    printf("\nH1Data:%s\n","b");
    printf("H1Prev:%p\n",NULL);
    printf("H1Next:%p\n",NULL);
    
    testPassedAddress(h1,h1,&llnPass);
    testPassedData(h1,alphabet[1],&llnPass);
    
     printf ("**************************\n");
    
    ListItem* g1 = LinkedListNew(alphabet[2]);       //created new List Item
    printf("\nAction: Created new Linked List G1(G1 set to NULL)\n");
    printf("\nOutput:\n");
    printf("\nG1Data:%c\n",*(g1->data));
    printf("G1Prev:%p\n",(g1->previousItem));
    printf("G1Next:%p\n",(g1->nextItem));
    printf("\nExpected Output:\n");
    printf("\nG1Data:%s\n","c");
    printf("G1Prev:%p\n",NULL);
    printf("G1Next:%p\n",NULL);
    
    testPassedAddress(g1,g1,&llnPass);
    testPassedData(g1,alphabet[2],&llnPass);
    
    
     printf ("**************************\n");
    
    char *c;
    c = '\0';
    ListItem* k1 = LinkedListNew(c);     //created new List Item
    printf("\nAction: Created new Linked List K1(Data Pointer set to NULL)\n");
    printf("\nOutput:\n");
    printf("\nK1Data:%s\n",k1->data);
    printf("K1Prev:%p\n",(k1->previousItem));
    printf("K1Next:%p\n",(k1->nextItem));
    printf("\nExpected Output:\n");
    printf("\nK1Data:%s\n",NULL);
    printf("K1Prev:%p\n",NULL);
    printf("K1Next:%p\n",NULL);
    
    
    testPassedAddress(k1,k1,&llnPass);
    
    
    printf ("**************************\n");
    
    printf ("***********************************\n");
    printf ("** LinkedListCreateAfter() Check **\n");
    printf ("***********************************\n");
    printf("\nAction: Add L2 to L1\n");
    ListItem* l2 = LinkedListCreateAfter(l1,alphabet[3]);
    printf("\nOutput:\n");
    printf("\nL1Data:%c\n",*(l1->data));
    printf("L1Prev:%p\n",l1->previousItem);
    printf("L1NextData:%s\n",(l1->nextItem->data));
    printf("\nL2Data:%c\n",*(l2->data));
    printf("L2Next:%p\n",(l2->nextItem));
    printf("\nExpected Output:\n");
    printf("\nL1Data:%c\n",'a');
    printf("L1Prev:%p\n",NULL);
    printf("L1NextData:%s\n","d");
    printf("\nL2Data:%c\n",'d');
    printf("L2Next:%p\n",NULL);
    
    testPassedAddressAfter(l1,l2,&llnPass);
    testPassedData(l2,alphabet[3],&llnPass);
    
    printf ("**************************\n");
    
    printf("\nAction: Add L3 to L2\n");
    ListItem* l3 = LinkedListCreateAfter(l2,alphabet[4]);
    printf("\nOutput:\n");
    printf("\nL2Data:%c\n",*(l2->data));
    printf("L2NextData:%s\n",(l2->nextItem->data));
    printf("\nL3Data:%c\n",*(l3->data));
    printf("L3Next:%p\n",(l3->nextItem));
    printf("\nExpected Output:\n");
    printf("\nL2Data:%c\n",'d');
    printf("L2NextData:%s\n","e");
    printf("\nL3Data:%c\n",'e');
    printf("L3Next:%p\n",NULL);
    
    testPassedAddressAfter(l2,l3,&llnPass);
    testPassedData(l3,alphabet[4],&llnPass);
    
    printf ("**************************\n");
    
    printf("\nAction: Add L4 to L1\n");
    ListItem* l4 = LinkedListCreateAfter(l1,alphabet[5]);
    printf("\nOutput:\n");
    printf("\nL1Data:%c\n",*(l1->data));
    printf("L1NextData:%s\n",(l1->nextItem->data));
    printf("\nL4Data:%c\n",*(l4->data));
    printf("\nExpected Output:\n");
    printf("\nL1Data:%c\n",'a');
    printf("L1NextData:%s\n","f");
    printf("\nL4Data:%c\n",'f');
    
    testPassedAddressAfter(l1,l4,&llnPass);
    testPassedData(l4,alphabet[5],&llnPass);
    
    printf ("***********************************\n");
    printf ("** LinkedListRemove() Check **\n");
    printf ("***********************************\n");
    
    printf("\nAction: Remove L1(HEAD) where L4 is new HEAD from List\n");
    LinkedListRemove(l1);
    printf("\nOutput:\n");
    printf("\nL1Data:%c\n",*(l1->data));
    printf("\nL4Prev:%p\n",(l4->previousItem));
    printf("\nL4Next:%d\n",(l4->nextItem==l2));
    printf("\nExpected Output:\n");
    printf("\nL1Data:%c\n",'a');
    printf("\nL4Prev:%p\n",NULL);
    printf("L1Next:%d\n",1);
    
    testPassedAddress(l1,l1,&llrPass);
    testPassedAddressAfter(l1,l4,&llrPass);
    testPassedData(l1,alphabet[0],&llrPass);
    
    printf ("***********************************\n");
    
     printf("\nAction: Remove L3(TAIL) where L2 is new TAIL from List\n");
    LinkedListRemove(l3);
    printf("\nOutput:\n");
    printf("\nL3Data:%c\n",*(l1->data));
    printf("\nL2Prev:%p\n",(l2->previousItem==l4));
    printf("\nL2Next:%p\n",(l2->nextItem));
    printf("\nExpected Output:\n");
    printf("\nL3Data:%c\n",'a');
    printf("\nL2Prev:%d\n",1);
    printf("L2Next:%p\n",NULL);
    
    testPassedAddress(l3,l3,&llrPass);
    testPassedAddressAfter(l3,l2,&llrPass);
    testPassedData(l3,alphabet[0],&llrPass);
    
    printf ("***********************************\n");
    printf ("** LinkedListSize() Check **\n");
    printf ("***********************************\n");
    
    printf("\nAction: Get Size of List L4,L2\n");
    printf("\nOutput:%d\n",LinkedListSize(l2));
    printf("\nExpected Output:%d\n",2);
    if(LinkedListSize(l2)==2) llsPass++;
    
    LinkedListRemove(l2);
    printf("\nAction: Get Size of List L4\n");
    printf("\nOutput:%d\n",LinkedListSize(l4));
    printf("\nExpected Output:%d\n",1);
    if(LinkedListSize(l4)==1) llsPass++;
    
    ListItem* l5 = LinkedListCreateAfter(l4,alphabet[6]);
    ListItem* l6 = LinkedListCreateAfter(l5,alphabet[7]);
    ListItem* l7 = LinkedListCreateAfter(l6,alphabet[8]);
    printf("\nAction: Get Size of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListSize(l4));
    printf("\nExpected Output:%d\n",4);
    if(LinkedListSize(l4)==4) llsPass++;
    
    
    printf ("**************************\n");
    
    printf ("***********************************\n");
    printf ("** LinkedListGetFirst() Check **\n");
    printf ("***********************************\n");
    
    
    printf("\nAction: Get First at L4 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetFirst(l4)==l4);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l4)==l4) llgfPass++;
    
    printf ("**************************\n");
    
    printf("\nAction: Get First at L6 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetFirst(l6)==l4);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l6)==l4) llgfPass++;
    
    printf ("**************************\n");
    
    printf("\nAction: Get First at L7 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetFirst(l7)==l4);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l7)==l4) llgfPass++;
    
    
    printf ("**************************\n");
    
    printf ("***********************************\n");
    printf ("** LinkedListGetLast() Check **\n");
    printf ("***********************************\n");
    
    printf("\nAction: Get Last at L4 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetLast(l4)==l7);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l4)==l7) llglPass++;
    
    printf ("**************************\n");
    
    printf("\nAction: Get Last at L6 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetLast(l6)==l7);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l6)==l7) llglPass++;
    
    printf ("**************************\n");
    
    printf("\nAction: Get Last at L7 of List L4,L5,L6,L7\n");
    printf("\nOutput:%d\n",LinkedListGetLast(l7)==l7);
    printf("\nExpected Output:%d\n",1);
    if(LinkedListGetFirst(l7)==l7) llglPass++;
    
    printf ("**************************\n");
    
    printf ("***********************************\n");
    printf ("** LinkedListSwapData() Check **\n");
    printf ("***********************************\n");
    
    printf("\nAction: Swap Data at L4 with L6(void function check)\n");
    
    printf ("**************************\n");
    
    printf ("***********************************\n");
    printf ("** LinkedListPrint() Check **\n");
    printf ("***********************************\n");
    
    int i = 0;
    ListItem* head = LinkedListNew(alphabet[i]);
    ListItem* tail = head;
    for (i = 1; alphabet[i] != NULL; i++) {
        tail = LinkedListCreateAfter(tail, alphabet[i]);
        if(tail == NULL){
            FATAL_ERROR();
        }
    }
    LinkedListPrint(head);
    
    
    printf("LinkedListNew Tests Passed:%d",llnPass);
    printf("LinkedListCreateAfter Tests Passed:%d",llcaPass);
    printf("LinkedListRemove Tests Passed:%d",llrPass);
    printf("LinkedListSize Tests Passed:%d",llsPass);
    printf("LinkedListGetFirst Tests Passed:%d",llgfPass);
    printf("LinkedListgetLast Tests Passed:%d",llglPass);
    
    
    /*
    */
    
    
}
