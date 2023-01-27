#include <iostream>

using namespace std;
struct ListNode {
 int val;
 ListNode* next;

};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void insertFirst(int d,ListNode** head);
ListNode* insertEnd(int x , ListNode* head);
void print(ListNode* head);
int main()
{
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* l3 = NULL;
    l1=insertEnd(2,l1);
    insertEnd(4,l1);
    insertEnd(3,l1);
    print(l1);

    l2=insertEnd(5,l2);
    insertEnd(6,l2);
    insertEnd(4,l2);
    print(l2);

    l3= addTwoNumbers(l1, l2);
    print(l3);
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int sum;
      int carry=0;
       ListNode* temp =NULL;
       while(l1!=NULL || l2!=NULL)
       {
           sum=carry;
           if(l1!=NULL)
           {
               sum+=(l1->val);
               l1=l1->next;
           }
           if(l2!=NULL)
           {
               sum+=(l2->val);
               l2=l2->next;
           }
           temp = insertEnd((sum%10) ,temp);
           carry=sum/10;
       }
       if(carry>0){
            temp = insertEnd((carry) ,temp);
       }

       return temp;
    }

  void insertFirst(int d,ListNode** head){
    ListNode* temp = (ListNode*) malloc (sizeof(ListNode));
    temp->val = d;
    temp->next = *head;
    *head = temp;
}




ListNode* insertEnd(int x , ListNode* head){
      ListNode* temp = new ListNode;
      temp->val =x;
      temp->next=NULL;
      if(head == NULL){
          head=temp;
      }
      else{
          ListNode* temp1=head;
          while((temp1->next) !=NULL){
             temp1=temp1->next;
          }
          temp1->next=temp;

      }
      return head;
  }

  void print( ListNode* head){
    while(head!=NULL){
        cout << head->val<<endl;
        head=head->next;
    }
}
