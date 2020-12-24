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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL||head->next==NULL){
            return head;
        }

        ListNode* prev,*cur,*last;
        prev=head;
        cur=head->next;
        prev->next=cur->next;
        cur->next=prev;
        head=cur;
        last=prev;
        if(prev->next){
            if(prev->next->next){
                cur=prev->next->next;
                prev=prev->next;
            }
            else{
                return head;
            }
        }
        else{
            return head;
        }
        while(cur){
            prev->next=cur->next;

            cur->next=prev;

            last->next=cur;
            last=prev;
           // cout<<"CUR:"<<cur->val<<" "<<"PREV:"<<prev->val;

            if(prev->next){
                if(prev->next->next){
                    cur=prev->next->next;
                    prev=prev->next;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        return head;
    }
};
