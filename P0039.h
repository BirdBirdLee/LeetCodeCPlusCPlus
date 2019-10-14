//
// Created by dell on 2019/10/13.
//

#ifndef LEETCODECPLUSPLUS_P0039_H
#define LEETCODECPLUSPLUS_P0039_H

#include "common.h"



class P0039: public Problem{
public:
//    P0039();
//    void test();
    //生成输入
    vector<int> generate();
    vector<vector<int>> permute(vector<int>& nums);
    void run() override;

private:
    vector<vector<int>> result;
    void quanpailie(vector<int>& nums, int begin, int size);
    void swap(int &a, int &b);

};


#endif //LEETCODECPLUSPLUS_P0039_H
