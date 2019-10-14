//
// Created by dell on 2019/10/14.
//

#ifndef LEETCODECPLUSPLUS_P0022_H
#define LEETCODECPLUSPLUS_P0022_H

#include "common.h"
class P0022: public Problem{
public:
    int generate();
    vector<string> generateParenthesis(int n);
    void run() override;

private:
    vector<string> result;
    void permute(int n, string one, int left, int right);

};


#endif //LEETCODECPLUSPLUS_P0022_H
