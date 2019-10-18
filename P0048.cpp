//
// author: BirdBirdLee
// create:  2019/10/18 21:19.
// description:
//

#include "P0048.h"
void P0048::generate(vector<vector<int>> &matrix) {
//    vector<int> r1({1, 2, 3, 4});
//    vector<int> r2({5, 6, 7, 8});
//    vector<int> r3({9, 10, 11, 12});
//    vector<int> r4({13, 14, 15, 16});
//    matrix.push_back(r1);
//    matrix.push_back(r2);
//    matrix.push_back(r3);
//    matrix.push_back(r4);
    matrix.push_back({1, 2,   3,  4, 5});
    matrix.push_back({6, 7,   8,  9, 10});
    matrix.push_back({11, 12 ,13, 14, 15});
    matrix.push_back({16, 17, 18, 19, 20});
    matrix.push_back({21, 22, 23, 24, 25});
}

void P0048::rotate(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int column = row;

    ////////////////////////////////////////

    //有错，会有重复复制的地方，部分错误
    //一下子保存一列
//    int* backup = new int[row];
//    for (int i = 0; i < row; ++i) {
//        //保存列
//        for (int k = 0; k < row; ++k) {
//            backup[k] = matrix[k][column - i - 1];
//        }
//
//        //把每一行放到列上
//        for (int j = 0; j < column; ++j) {
//            matrix[j][column - i - 1] = matrix[i][j];
//        }
//    }
//    delete[] backup;


    ////////////////////////////////////


    /////////////////////////////////////////////

    //第二种方法，一次旋转同意位置的四个点
    // 1 2 3 4
    // 4 5 6 7
    // 8 9 10 11 12
    // 13 14 15 16
    //即旋转2, 7, 15, 8
    //分别记2, 7, 15, 8 为a, b, c, d
    //这样子只要遍历1/8三角，即▽的左半边
    //每次只需要一个暂时变量
    //i, j范围很讲究
    for (int i = 0; i < column / 2; ++i) {
        for (int j = i; j < row - i - 1; ++j) {
            //保留a
            int temp = matrix[i][j];

            //把a替换成d
            matrix[i][j] = matrix[row - 1 - j][i];

            //把d替换成c
            matrix[row - 1 - j][i] = matrix[row - i - 1][column - j - 1];

            //把c替换成b
            matrix[row - i - 1][column - j - 1] = matrix[j][column - i - 1];

            //把b替换成a
            matrix[j][column - i -1] = temp;


        }
    }


    /////////////////////////////////////////////


    return;
}

void P0048::my_print(vector<vector<int>> matrix) {
    for (auto itr = matrix.begin(); itr!=matrix.end() ; itr++) {
        for (auto itc = (*itr).begin(); itc!=(*itr).end(); itc++) {
            cout<<*itc<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void P0048::run() {
    vector<vector<int>> matrix;
    generate(matrix);
//    my_print(matrix);
    rotate(matrix);
    my_print(matrix);
}
