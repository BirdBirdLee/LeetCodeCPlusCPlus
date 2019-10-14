//
// Created by dell on 2019/10/14.
//

#include "P0019.h"

ListNode* P0019::generate() {
    ListNode* listNode = new ListNode(0);
    ListNode* p = listNode;
    for (int i = 0; i < 10; ++i) {
        ListNode* newListNode = new ListNode(i+1);
        p->next = newListNode;
        p = p->next;
        p->next = nullptr;
    }
    return listNode;
}

ListNode* P0019::removeNthFromEnd(ListNode *head, int n) {
    //添加一个头结点，方便处理特殊情况
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    int size = 0;
    int pos = 0;
    for (ListNode* p = newHead; p!= nullptr; p=p->next) {
        size++;
    }
    for (ListNode* p = newHead; p!= nullptr; p=p->next) {
        pos++;
//        正序
//        if(pos == n - 1){
//            p->next = p->next->next;
//        }
//        倒序
        if(pos == size - n){
            p->next = p->next->next;
        }
    }
    return newHead->next;


}

void P0019::run() {
    ListNode* result = removeNthFromEnd(generate()->next, 3);
    for (ListNode* p = result; p!= nullptr; p=p->next) {
        cout<<p->val<<" ";
    }
    cout<<endl;
}
