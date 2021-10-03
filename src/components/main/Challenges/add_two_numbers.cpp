
/**
 Problem Name:Add Two Numbers
 Problem link : https://leetcode.com/problems/add-two-numbers/
 **/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
      ListNode* reverse(ListNode* head){
      
      ListNode* curr = head;
      ListNode* prev = NULL;
      
      while(curr!=nullptr){
          ListNode* temp = curr->next;
          if(prev==NULL){
              curr->next = prev;
              prev = curr;
              curr = temp;
         
          }
          else{
               curr->next = prev;
               prev = curr;
              curr = temp;
             
          }
      }
      
      head = prev;
      return head;
  }
    int len(ListNode* head)
    {
        int c=0;
        while(head!=nullptr){
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
     
    int n = len(first);
    int m = len(second);
    ListNode* curr1;
    ListNode* head;
    ListNode* curr2;
    if(n>m)
    {
     curr1 = first;
     head = curr1;
     curr2 = second;
    }
    else{
     curr1 = second;
     head = curr1;
     curr2 = first;  
    }
    
    if(curr2==NULL){
        return curr1;
    }
    int carry =0;
    ListNode* prev =NULL;
    while(curr1!= nullptr && curr2!=nullptr){
     int s= (curr1->val+curr2->val);
     s+=carry;
     if(s>=10){
         s=s%10;
       
         carry = 1;
     }
     else{
        
         carry = 0;
     }
     
     curr1->val =s;
         prev = curr1;
     curr1 = curr1->next;
    
     curr2 = curr2->next;
     
     
        
    }
    
    while(curr1!=nullptr)
    {
        int s = curr1->val;
        s+=carry;
    if(s>=10)
    {
        s=s-10;
        carry = 1;
    }
    else{
        carry = 0;
    }
    
        curr1->val =s;
        prev = curr1;
        curr1 = curr1->next;
        
    }
    
    if(carry){
         ListNode* kk = (ListNode*)new ListNode;
        kk->val = 1;
        kk->next = nullptr;
        prev->next = kk;
        
    }
    
    return head;
    
    
    }
};