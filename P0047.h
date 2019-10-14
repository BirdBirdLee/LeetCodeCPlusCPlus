//
// Created by dell on 2019/10/14.
//

#ifndef LEETCODECPLUSPLUS_P0047_H
#define LEETCODECPLUSPLUS_P0047_H


#include "common.h"



class P0047: public Problem{
public:
    //生成输入
    vector<int> generate();
    vector<vector<int>> permuteUnique(vector<int>& nums);
    void run() override;

private:
    vector<vector<int>> result;
    void quanpailie(vector<int>& nums, int begin, int size);
    void swap(int &a, int &b);

};


#endif //LEETCODECPLUSPLUS_P0047_H
