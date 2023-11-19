#include<stdio.h>
#include<stdlib.h>
//creating Node structure
struct Node{
    int data;
    struct Node* next;
};

//linkedlist traversal
void linkedlistTraversal(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("Element is: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

//insert at first
struct Node* insertAtFirst(struct Node* head,int val){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node* p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
//insert at the last
struct Node* insertAtLast(struct Node* head,int val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node* p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}
//insert at an index
struct Node* insertAtIndex(struct Node* head,int index,int val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    ptr->data=val;
    int i=1;
    while(i!=index-1){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//insert after a node
struct Node* insertAfterNode(struct Node* head,struct Node* node,int val){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=node->next;
    node->next=ptr;
    return head;
}
//Deleting the first Node
struct Node* deletingFirstNode(struct Node* head){
    struct Node* ptr = head;
    struct Node* p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=head->next;
    head=head->next;
    free(ptr);
    return head;
}

//deleting last node of linkedlist
struct Node* deletingLastNode(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
    return head;
}
//delete at the index
struct Node* deleteIndex(struct Node* head,int index){
    struct Node* p=head;
    int i=1;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    struct Node* ptr = p->next;
    p->next=ptr->next;
    free(ptr);
    return head;
    
}
//delete after a Node
struct Node* deleteAfterNode(struct Node* head,int index){
    struct Node* ptr=head;
    int i=1;
    while(i!=index){
        ptr=ptr->next;
        i++;
    }
    struct Node* q= ptr->next;
    ptr->next=q->next;
    free(q);
    return head;
}

int main(){
    struct Node* head ;
    struct Node* second;
    struct Node* third ;
    struct Node* forth ;
    struct Node* fifth ;

    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));
    forth=(struct Node*) malloc(sizeof(struct Node));
    fifth=(struct Node*) malloc(sizeof(struct Node));

    head->data=12;
    head->next=second;

    second->data=23;
    second->next=third;

    third->data=34;
    third->next=forth;

    forth->data= 87;
    forth->next= fifth;

    fifth->data= 33;
    fifth->next = head;

    printf("Before operation: \n");
    linkedlistTraversal(head);

    printf("After operation: \n");
    // head = insertAtFirst(head,7777);
    // head = insertAtLast(head,8888);
    // head = insertAtIndex(head,2,44444);
    // head = insertAfterNode(head,second,34343434);
    // head=deletingFirstNode(head);
    // head = deletingLastNode(head);
    // head = deleteIndex(head,3);
    head = deleteAfterNode(head,3);
    linkedlistTraversal(head);

    return 0;
}