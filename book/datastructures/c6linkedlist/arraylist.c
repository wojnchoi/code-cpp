#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef int element;
typedef struct {
    element array[MAX_SIZE];
    int size;
}ArrayList;

void error(const char *msg) {
    fprintf(stderr,"%s\n",msg);
    exit(1);
}
void init(ArrayList *L) {
    L->size = 0;
}
int is_empty(ArrayList *L) {
    return L->size == 0;
}
int is_full(ArrayList *L) {
    return L->size == MAX_SIZE;
}
element get_entry(ArrayList *L,int pos) {
    if(pos<0 || pos >= L->size)
        error("pos error");
    return L->array[pos];
}
void print_list(ArrayList *L) {
    int i;
    for(i=0;i<L->size;i++)
        printf("%d->",L->array[i]);
    printf("\n");
}
void insert_last(ArrayList *L,element item) {
    if(L->size >=MAX_SIZE)
        error("list overflow");
    L->array[L->size++] = item;
}
void insert(ArrayList *L,int pos, element item) {
    if(!is_full(L) && pos >= 0 && pos <= L->size) {
        for(int i= L->size -1; i>=pos; i--)
            L->array[i+1] = L->array[i];
        L->array[pos] = item;
        L->size++;
    }
}
void insert_first(ArrayList *L, element item) {
    for(int i=L->size-1;i>=0;i--)
        L->array[i+1] = L->array[i];
    L->array[0] = item;
    L->size++;
}
element delete(ArrayList *L, int pos) {
    element item;
    if(pos < 0||pos>= L->size) {
        error("pos error");
    }
    item = L->array[pos];
    for(int i= pos; i<L->size -1; i++) {
        L->array[i] = L->array[i+1];
    }
    L->size--;
    return item;
}
void clear(ArrayList *L) {
    while(!is_empty(L)) {
        delete(L,0);
    }
}
void replace(ArrayList *L,int pos, element item) {
    if(pos >= MAX_SIZE || pos < 0)
        error("pos error");
    L->array[pos] = item;
}
int get_length(ArrayList *L) {
    return L->size;
}
int main() {
    ArrayList list;

    init(&list); print_list(&list);
    insert(&list,0,10);print_list(&list);
    insert(&list,0,20);print_list(&list);
    insert(&list,0,30);print_list(&list);
    insert_last(&list,40);print_list(&list);
    delete(&list,0);print_list(&list);
    insert_first(&list,50); print_list(&list);
    replace(&list,1, 60); print_list(&list);
    printf("%d\n",get_length(&list));
    insert_last(&list,70);
    clear(&list); print_list(&list);
    return 0;
}
