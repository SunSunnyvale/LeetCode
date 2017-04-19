// This beats 93.3% od submitted solutions

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void print(ListNode *result){
        cout<<"\n4.. result::";
        while(result){
            cout<<" "<<result->val;
            result=result->next;
        }
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0,sum=0;
        sum=l1->val+l2->val+carry;
        ListNode *result=new ListNode(sum%10);
        carry=sum/10;
        ListNode *temp=result;
        l1=l1->next;
        l2=l2->next;
        //print(result);
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
            //print(result);
        }
        if(l1 || l2){
            while(l1){
                sum=l1->val+carry;
                carry=sum/10;
                temp->next=new ListNode(sum%10);
                temp=temp->next;
                l1=l1->next;
                //print(result);
            }
            while(l2){
                sum=l2->val+carry;
                carry=sum/10;
                temp->next=new ListNode(sum%10);
                temp=temp->next;
                l2=l2->next;
                //print(result);
            }
        }
        if(carry > 0){ 
            temp->next=new ListNode(carry);
        }
        return result;
    }
};
