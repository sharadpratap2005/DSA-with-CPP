 /*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if(!head) return head;
        
        //find the length
        int n = 0;
        Node* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        //if k is greater than n
        if(k>n) return head;
        //if kth node from begining and kth from ending are same
        if(2*k-1==n)return head;
        
        
        //find the kth node and its previous node from the begining
        Node* x_prev=NULL;
        Node* x=head;
        for(int i=1;i<k;i++){
            x_prev=x;
            x=x->next;
        }
        
        //find the kth node from the end of linked list
        Node* y_prev=NULL;
        Node* y=head;
        for(int i=1;i<n-k+1;i++){
            y_prev=y;
            y=y->next;
        }
        
        //if x is not head
        if(x_prev){
            x_prev->next=y;
        }
        else{
            head=y;
        }
        
        //if y is not head
        if(y_prev){
            y_prev->next=x;
        }
        else{
            head=x;
        }
        
        //swap next pointers
        Node* tempNext=x->next;
        x->next=y->next;
        y->next=tempNext;
        
        return head;

    }
};


//another method just to swap the data
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) { 
        // first find the length of a Linkedin List
        // base case
        if(head == NULL) {
            return NULL;
        }
        int length = 0;
        ListNode* temp = head;
        while(temp) {
            length++;
            temp = temp -> next;
        }
        // reach to the kth node
        ListNode* first = head;
        for(int i = 1; i < k; i++) {
            first = first -> next;
        }

        ListNode* last = head;
        // reach to the kth node from the end 
        for(int i = 1; i < length - k + 1; i++) {
            last = last -> next;
        }
        swap(first -> val, last -> val);
        return head;
    }
};

