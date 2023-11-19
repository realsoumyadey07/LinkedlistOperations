#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void linkedlistTraversal(struct Node* ptr){
    while (ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
//insert at the first 
struct Node* insertAtFirst(struct Node* head,int val){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=head;
    return ptr;
}
//insert at index
struct Node* insertAtIndex(struct Node* head,int index,int val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head;
    int i=1;
    while (i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=val;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//insert at the end
struct Node* insertAtEnd(struct Node* head,int val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node* p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr=p->next;
    ptr->next=NULL;
    return head;
    
}
// insertion after a Node
struct Node* insertAfterNode(struct Node* head,struct Node* node,int val){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=node->next;
    node->next=ptr;
    return head;
}
//Deleting the first Node
struct Node* deleteFirstNode(struct Node* head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
// Deleting a Node in between
struct Node* deleteNodeInbetween(struct Node* head,int index){
    struct Node* p=head;
    int i=1;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    struct Node* q=p->next;
    p->next=q->next;
    free(q);
    return head;
}
//Deleting the last Node
struct Node* deletingLastNode(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//Reverse a linkedlist
struct Node* reverselist(struct Node* head){
    struct Node* c=head;
    struct Node* p=NULL;
    while(c!=NULL){
        struct Node* temp=c->next;
        c->next=p;
        p=c;
        c=temp;
    }
    return p;
}


int main(){
    //declearing Nodes
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;
    struct Node* fifth;

    //memory allocating
    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));
    forth=(struct Node*) malloc(sizeof(struct Node));
    fifth=(struct Node*) malloc(sizeof(struct Node));
     
    //creating links
    head->data=7;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=34;
    third->next=forth;

    forth->data=45;
    forth->next=fifth;

    fifth->data=56;
    fifth->next=NULL;

    printf("Linkedlist before insertion: \n");
    linkedlistTraversal(head);
    // head= insertAtFirst(head,34);
    // head = insertAtIndex(head,2,777);
    // head=insertAfterNode(head,third,8888);
    // head = deleteFirstNode(head);
    // head= deleteNodeInbetween(head,3);
    // head= deletingLastNode(head);
    // head = reverselist(head);
    printf("Linkedlist after insertion: \n");
    linkedlistTraversal(head);
    return 0;
}