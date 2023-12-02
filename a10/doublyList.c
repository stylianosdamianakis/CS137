#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct dlnode{
    int data;
    struct dlnode *next;
    struct dlnode *prev;
}dlnode;

typedef struct ndlst{
    dlnode *head;	//points to the first element otherwise NULL
    dlnode *tail;	//points to the last element otherwise NULL
    int len;	// number of elements
}ndlst;

//Pre: None
//Post: Creates a null list
ndlst *dlistCreate(void){
    ndlst *ret = malloc(sizeof(ndlst));
    ret->head = NULL;
    ret->tail = NULL;
    ret->len = 0;
    return ret;
}

//Pre: lst is a valid list ( even null )
//Post: Destroys the list
void dlistDestroy(ndlst *lst){

    //free each node
    struct dlnode *node = lst->head;
    for (int i = 0; i < lst->len; i++) {

        //use a temporary variable to save the current node location
        struct dlnode *temp = node;
        node = node->next;
        free(temp);
    }

    free(lst);
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst){
    return lst->len;
}

//Pre: lst is a valid list with length of at least n
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n){

    //base case
    if (n == 0 || n > lst->len) return;

    //find the correct node to remove
    struct dlnode *node = lst->head;
    for (int i = 1; i < n; i++) node = node->next;

    //correct the pointers
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        lst->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        lst->tail = node->prev;
    }

    //remove the node
    free(node);

    //update the length
    lst->len--;
}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem){

    //creating the new node
    dlnode *newNode = malloc(sizeof(dlnode));
    newNode->data = elem;
    newNode->next = lst->head;
    newNode->prev = NULL;

    //increasing the length
    lst->len++;

    //if the list is empty, add the first node
    if (lst->len == 1) {
        lst->head = newNode;
        lst->tail = newNode;
        return;
    }

    //otherwise update the pointers of the adjacent nodes
    lst->head->prev = newNode;
    lst->head = newNode;
}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem){

    //creating the new node
    dlnode *newNode = malloc(sizeof(dlnode));
    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = lst->tail;

    //increasing the length
    lst->len++;

    //if the list is empty, add the first node
    if (lst->len == 1) {
        lst->head = newNode;
        lst->tail = newNode;
        return;
    }

    //otherwise update the pointers of the adjacent nodes
    lst->tail->next = newNode;
    lst->tail = newNode;
}

//Pre: lst is valid
//prints the items in the list from start to end.
void dlistPrint(ndlst *lst){
    dlnode *node = lst->head;
    // iterate over the nodes (items) until node is NULL
    // and print the data
    for (; node; node = node->next)
        printf("%d  ", node->data);
    printf("\n");
}

void dlistPrintReverse(ndlst *lst){
    dlnode *node = lst->tail;
    // iterate over the nodes (items) until node is NULL
    // and print the data
    for (; node; node = node->prev)
        printf("%d  ", node->data);
    printf("\n");
}

void dlistSort(ndlst *lst){

    //loop through the entire list
    for (struct dlnode *index = lst->head; index != NULL; index = index->next) {

        //save the smallest values
        int smallest = index->data;
        struct dlnode *containsSmallest = index;

        //loop through the rest of the list
        for (struct dlnode *nextIndex = index->next; nextIndex != NULL; nextIndex = nextIndex->next) {

            //find the smallest element
            if (smallest > nextIndex->data) {
                smallest = nextIndex->data;
                containsSmallest = nextIndex;
            }
        }

        //switch the smallest with the current
        containsSmallest->data = index->data;
        index->data = smallest;
    }

}

// rotate the list n times to the left, assume, list not empty
void dlistRotateLeft(ndlst *lst, int n){

    //rotate n times
    for (int i = 0; i < n; i++) {

        //saving the current value
        int tempVal = lst->head->data;

        //move every element by 1
        for (struct dlnode *index = lst->tail; index != NULL; index = index->prev) {

            //update the values
            int tempVal2 = tempVal;
            tempVal = index->data;
            index->data = tempVal2;
        }
    }
}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n){

    //rotate n times
    for (int i = 0; i < n; i++) {

        //saving the current value
        int tempVal = lst->tail->data;

        //move every element by 1
        for (struct dlnode *index = lst->head; index != NULL; index = index->next) {

            //update the values
            int tempVal2 = tempVal;
            tempVal = index->data;
            index->data = tempVal2;
        }
    }
}

/*int main(void){
    ndlst *lst1 = dlistCreate();
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 0);
    dlistAddToEnd(lst1, 10);
    dlistAddToFront(lst1, -20);
    dlistAddToFront(lst1, 0);
    dlistAddToEnd(lst1, 9);
    dlistAddToFront(lst1, -9);
    dlistAddToFront(lst1, 7);
    dlistAddToEnd(lst1, 40);
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 7);
    dlistPrint(lst1);
    dlistPrintReverse(lst1);
    dlistRemoveElem(lst1, 5);
    dlistRemoveElem(lst1, 1);
    dlistRemoveElem(lst1, 5);
    dlistAddToEnd(lst1, 100);
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 5);
    dlistPrint(lst1);
    dlistPrintReverse(lst1);
    dlistSort(lst1);
    dlistPrint(lst1);
    dlistRotateLeft(lst1, 2);
    dlistPrint(lst1);
    dlistRotateRight(lst1, 3);
    dlistPrint(lst1);
    dlistDestroy(lst1);

    return 0;
}*/
