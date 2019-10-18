//
// author: BirdBirdLee
// create:  2019/10/18 21:19.
// description: 矩阵反转，https://leetcode-cn.com/problems/rotate-image/
//

#ifndef LEETCODECPLUSPLUS_P0048_H
#define LEETCODECPLUSPLUS_P0048_H

#include "common.h"

class P0048: public Problem{
public:
    void generate(vector<vector<int>> &matrix);
    void rotate(vector<vector<int>>& matrix);
    void run() override;

private:
    void my_print(vector<vector<int>> matrix);

};


#endif //LEETCODECPLUSPLUS_P0048_H
