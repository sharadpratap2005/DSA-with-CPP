/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head==NULL||head->next==NULL) return head;
        Node* currNode=head;
        Node* prevNode=NULL;
        
        while(currNode!=NULL){
            //swap the previous and next pointers of the current node
            prevNode=currNode->prev;//prevNode is previous of the current node
            currNode->prev=currNode->next;//change the previous of the current node to next of the current node
            currNode->next=prevNode;//change the next of the current node to the previous
            //by doing so previous and next pointers of cuuurentNOde are swapped
            
            //Move to the next node in the original linkedlist
            // which is now the previous node 
            currNode=currNode->prev;
            
        }
        if(prevNode!=NULL)
            head= prevNode->prev;
        return head;

    }
};
