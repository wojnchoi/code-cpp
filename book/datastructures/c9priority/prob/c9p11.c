#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
    char work[15];
    int key;
}element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}heaptype;

heaptype *create() {
    return (heaptype*)malloc(sizeof(heaptype));
}
void init(heaptype *h) {
    h->heap_size = 0;
}
void insert_max_heap(heaptype *h, element item) {
    int i;
    i = ++(h->heap_size);
    while((i!=1) && (item.key) > h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item;
}
element delete_max_heap(heaptype *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h->heap_size) {
        if((child < h->heap_size) && (h->heap[child].key < h->heap[child +1].key)) child++;
        if(temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
int main() {
    char input = '\0';
    
    heaptype *heap;
    heap = create();
    init(heap);

    element m;
    while(input != 'q'){
        printf("ins or del (i / d): ");
        scanf(" %c", &input);
        if(input == 'i') {
            printf("work: ");
            scanf(" %s",m.work);
            printf("prior: ");
            scanf(" %d", &m.key);
            insert_max_heap(heap,m);
        }else if(input == 'd') {
            m = delete_max_heap(heap);
                printf("most prior work: %s\n", m.work);
        }
    }
    return 0;
}