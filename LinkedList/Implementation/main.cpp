#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};
Node* insertFirst(int d,Node* head);
void insertFirst2(int d,Node** head);
struct Node* insertEnd(int x , struct Node * head);
void print(struct Node* head);
void reverse (struct Node** head);

int main()
{
    struct Node* head=NULL;
   //head = insertEnd(5 , head);
   //head = insertEnd(7 , head);
   //print( head);
   //reverse(&head);

    //head = insertFirst(5,head);
    //head = insertFirst(6,head);
    //head = insertFirst(7,head);
    //print( head);

    //insertFirst2(4,&head);
    //insertFirst2(5,&head);
    //insertFirst2(6,&head);
    //print( head);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Single Linked List

// Insert Node At First
//There Are Three ways for head ====>  global , local , local without return pointer to Node (using Reference)

//Type One (local)
Node* insertFirst(int d,Node* head){
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->data = d;
    temp->next = head;
    head = temp;
}

// Type Two (Reference)
void insertFirst2(int d,Node** head){
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->data = d;
    temp->next = *head;
    *head = temp;
}

// Type Three (Global) It Is Easy Way


//Insert Node At End
  struct Node* insertEnd(int x , struct Node * head){
      struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
      temp->data =x;
      temp->next=NULL;
      if(head == NULL){
          head=temp;
      }
      else{
          struct Node* temp1=head;
          while((temp1->next) !=NULL){
             temp1=temp1->next;
          }
          temp1->next=temp;

      }
      return head;
  }


//Print All Nodes
  void print(struct Node* head){
    while(head!=NULL){
        cout << head->data<<endl;
        head=head->next;
    }
}



// Reverse LinkedList Using Iterative Method
void reverse (struct Node** head){
    struct Node *prev , *curr , *next;
    curr = *head;
    prev=NULL;

    while(curr !=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    *head=prev;
}

