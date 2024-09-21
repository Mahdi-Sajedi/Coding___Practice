I coded this up pretty quickly.
```python
def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode()
    prev = dummy
    carry = 0
    head1 = l1
    head2 = l2
    while head1 or head2 or carry:
        temp = ListNode()
        ## compute sum and carry on
        sum1 = head1.val if head1 else 0
        sum2 = head2.val if head2 else 0
        sum3 = sum1 + sum2 + carry 
        temp.val, carry = sum3%10, sum3//10
        ## 
        curr = temp
        prev.next = curr
        prev = curr
        head1 = head1.next if head1 else None
        head2 = head2.next if head2 else None
    
    return dummy.next
```

And ChatGPT helped me with a few bugs in my Cpp code:
```cpp
/* struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* prev = dummy;
    int carry = 0;
    while (l1 || l2 || carry){
        ListNode* tmp = new ListNode();
        //
        int sum1 = l1 ? l1->val: 0;
        int sum2 = l2 ? l2->val: 0;
        int add = sum1 + sum2 + carry;
        tmp->val = add % 10;
        carry = add / 10; 
        //
        prev->next = tmp;
        prev = tmp;
        l1 = l1? l1->next: l1;
        l2 = l2? l2->next: l2;
    }
    return dummy->next;
}
```
We can combine prev and temp into one.
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode *t = &dummy;
    int carry = 0;
    while (l1 || l2 || carry){
        //
        carry += (l1? l1->val: 0) + (l2? l2->val: 0);
        t->next = new ListNode(carry%10);
        carry /= 10; 
        t = t->next;
        l1 = l1? l1->next: l1; // if(l1) l1 = l1->next
        l2 = l2? l2->next: l2;
    }
    return dummy.next; // dummy->next gives error: dummy is not pointer; did you mean to use '.'?

}
```
Beware of correct usage of pointers:
```cpp
ListNode* t;
t = dummy; // should be t = &summy 
//error: assigning to 'ListNode *' from incompatible type 'ListNode'; take the address with &
```
if you try to avoid setting up t as pointer (```ListNode t```), ```t = t.next``` will give error.
