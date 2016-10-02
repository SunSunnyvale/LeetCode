#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *sumLL=NULL,*currNode=NULL,*temp=NULL;
        int sum=0;
        int sumVal=0;
        int carryForward=0;
        while(l1 !=NULL && l2 !=NULL){
        	// cout<<"\nl1->val :::"<<l1->val<<"....l2->val :::"<<l2->val;
        	sum=l1->val + l2->val + carryForward;
            sumVal=sum%10;
            temp=new ListNode(sumVal);
            carryForward=sum/10;
            
            if(sumLL==NULL){
                sumLL=temp;
                currNode=temp;
            }else{
                currNode->next=temp;
                currNode=currNode->next;
            }
            
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 !=NULL){
        	cout<<"\nl1->val :::"<<l1->val;
            sum=l1->val +  carryForward;
            sumVal=sum%10;
            temp=new ListNode(sumVal);
            carryForward=sum/10;
            currNode->next=temp;
            currNode=currNode->next;
            l1=l1->next;
        }
        
        while(l2 !=NULL){
        	cout<<"\nl2->val :::"<<l2->val;
            sum=l2->val +  carryForward;
            sumVal=sum%10;
            temp=new ListNode(sumVal);
            carryForward=sum/10;
            currNode->next=temp;
            currNode=currNode->next;
            l2=l2->next;
            
        }
        if(carryForward !=0){
        	temp=new ListNode(carryForward);
            currNode->next=temp;

        }
        return sumLL;
        
    }
};


int main() {
  Solution obj;
  
  ListNode *val1,*val2;
  val1=new ListNode(5);

  val2=new ListNode(5);


  //obj.sortByColor("abccbba");
  ListNode *result=obj.addTwoNumbers(val1,val2);
  ListNode *temp=NULL;
  cout<<"\nresult :::";
  while(result !=NULL){
  	cout<<" "<<result->val;
  	temp=result;
  	result=result->next;
  	delete temp;
  }

  return 0;
}