/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  Node* reverseNode(Node* head,int k){
      Node* curr=head;
      Node* prev=NULL;
      Node* next=NULL;
      int count=0;
      
      while(curr!=NULL&&count<k){
          
          //store the next
          next=curr->next;
          
          //change curr next to prev
          curr->next=prev;
          
          //move the pointers
          prev=curr;
          curr=next;
          
          count++;
      }
      
      head->next=(curr==NULL?NULL:reverseNode(curr,k));
      return prev;
      
      
  }
    Node *reverseKGroup(Node *head, int k) {
        if(!head||k<=1) return head;
        return reverseNode(head,k);
    }
};
