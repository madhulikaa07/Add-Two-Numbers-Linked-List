#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* add_node(struct ListNode* head,int val)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!temp)
    {
        printf("Error allocating memory\n");
    }
    temp->val = val;
    temp->next = NULL;

    if(head == NULL)//if list is empty
    {
        head = temp;
        return head;
    }
    else
    {
        //iterate to the last node of the list
        struct ListNode* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        return head;
    }

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int sum=0,carry=0;
    struct ListNode* result = NULL;
    struct ListNode* l1_tmp = l1;
    struct ListNode* l2_tmp = l2;
    
    while( l1_tmp != NULL || l2_tmp != NULL)
    {
        if(l1_tmp != NULL && l2_tmp != NULL)
        {
            sum = l1_tmp->val + l2_tmp->val + carry;
            
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
            {
                carry=0;
            }
            
            result = add_node(result,sum);
            l1_tmp = l1_tmp->next;
            l2_tmp = l2_tmp->next;
        }
        else if(l2_tmp == NULL && l1_tmp != NULL)
        {
            sum = l1_tmp->val + carry;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
            {
                carry=0;
            }
            result = add_node(result,sum);
            l1_tmp = l1_tmp->next;
        }
        else if(l2_tmp != NULL && l1_tmp == NULL)
        {
            sum = l2_tmp->val + carry;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
            {
                carry=0;
            }
            result = add_node(result,sum);
            l2_tmp = l2_tmp->next;
        }
    }
    if(carry)
    {
        result = add_node(result,carry);
    }

    return result;
    
}

void print(struct ListNode* head)
{
    printf("\n");
    struct ListNode* temp = head;
    while(temp != NULL)
    {
        printf(" %d",temp->val);
        temp = temp->next;
    }
    printf("\n");
    
    return;
}


int main()
{
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* result = NULL;
    
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l1 = add_node(l1,9);
    l2 = add_node(l2,9);
    l2 = add_node(l2,9);
    l2 = add_node(l2,9);
    l2 = add_node(l2,9);
    
    printf("L1:");
    print(l1);
    printf("L2:");
    print(l2);
    
    result = addTwoNumbers(l1,l2);
    
    printf("Result:");
    print(result);
    
    
	
    
}