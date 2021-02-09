#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int id;
    int avail;
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
void insert_min_heap(heaptype *h, element item) {
    int i;
    i = ++(h->heap_size);

    while((i!=1) && (item.avail < h->heap[i/2].avail)) {
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item;
}
element delete_min_heap(heaptype *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size) {
        if((child<h->heap_size) && (h->heap[child].avail)> h->heap[child+1].avail)
            child++;
        
        if(temp.avail < h->heap[child].avail) break;
        h->heap[parent] = h->heap[child];
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

#define JOB 7
#define MACHINES 3

int main() {
    int jobs[JOB] = {8,7,6,5,3,2,1};
    element m = {0,0};
    heaptype *h;
    h=create();
    init(h);

    for(int i = 0; i<MACHINES;i++) {
        m.id = i+1;
        m.avail = 0;
        insert_min_heap(h,m);
    }
    for(int i = 0; i<JOB; i++) {
        m = delete_min_heap(h);
        printf("Jobs %d: %d to %d machine %d\n",i,m.avail,m.avail+jobs[i]-1,m.id);
        m.avail += jobs[i];
        insert_min_heap(h,m);
    }
    return 0;
}
