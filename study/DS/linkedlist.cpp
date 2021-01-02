#include<iostream>
#include<cstdlib>

using namespace std;
struct node
{
    void *data;

    struct node *next;
};

void push(struct node** head_ref, void* new_data,size_t data_size)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);

    int i;
    for(i=0;i<data_size;i++)
        *(char*)(new_node->data+i) = *(char*)(new_data + i);
    
    (*head_ref) = new_node;
}
void printList(struct node *Node, void (*fptr)(void *))
{
    while(Node != NULL)
    {
        (*fptr)(Node->data);
        Node = Node->next;
    }
    cout<<"\n";
}

void printInt(void *n)
{
    cout<<" "<<*(int*)n;
}
void printFloat(void *f)
{
    cout<<" "<<*(float*)f;
}
int main()
{
    struct node *start = NULL;

    unsigned int_size = sizeof(int);
    int arr[] = {10,20,30,40,50},i;
    for(i=4; i>=0; i--)
        push(&start,&arr[i],int_size);
    cout<<"CREATED INTEGER LINKED LIST"<<endl;
    printList(start,printInt);

    unsigned float_size = sizeof(float);
    start = NULL;
    float arr2[] = {10.1,20.2,30.3,40.4,50,5};
    for(i=4;i>=0;i--)
        push(&start,&arr2[i],float_size);
    cout<<"CREATED FLOAT LINKED LIST"<<endl;
    printList(start,printFloat);
    return 0;
}