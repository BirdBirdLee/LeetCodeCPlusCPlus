//
// Created by dell on 2019/10/14.
//

#ifndef LEETCODECPLUSPLUS_P0019_H
#define LEETCODECPLUSPLUS_P0019_H


#include "common.h"


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class P0019: public Problem{
public:
    ListNode* generate();
    ListNode* removeNthFromEnd(ListNode* head, int n);
    void run() override;

};


#endif //LEETCODECPLUSPLUS_P0019_H
