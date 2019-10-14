//
// Created by dell on 2019/10/14.
//

#include "P0022.h"

int P0022::generate() {
    return 3;
}

vector<string> P0022::generateParenthesis(int n) {
    string one;
    permute(n, one, 0, 0);
    return result;
}

void P0022::permute(int n, string one, int left, int right) {
    if(left > n || right > n){ return;}
    if(left == n && right == n){
        result.push_back(one);
    } else{
//        if(left<n){
//            one += "(";
//            permute(n, one, left+1, right);
//        }
//        if(right<left) {
//            one += ")";
//            permute(n, one, left, right+1);
//        }
        if(right <= left){
            permute(n, one + "(", left + 1, right);
            permute(n, one + ")", left, right + 1);
        }
    }
}

void P0022::run() {
    vector<string> r = generateParenthesis(generate());
    int size = r.size();
    for (int i = 0; i < size; ++i) {
        cout<<r[i]<<endl;
    }
}
