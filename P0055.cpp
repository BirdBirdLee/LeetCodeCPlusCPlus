//
// Created by BirdBirdLee on 2019/10/15.
// 题目链接 https://leetcode-cn.com/problems/jump-game/
// 思路 就算全是1也能跳过去，所以只有出现0的时候才会有问题，
//      扫描0的位置（最后一个不算），看看他们是否能跳到0的后一个
//

#include "P0055.h"

vector<int> P0055::generate() {
    vector<int> nums({3, 2, 1, 0, 4});
    return nums;
}

bool P0055::canJump(vector<int> &nums) {
    int size = nums.size();
    int result = true;
    vector<int> zero_pos;
    //统计0的位置，最后一个不统计
    for (int i = 0; i <nums.size()-1; ++i) {
        if(nums[i] == 0){
            zero_pos.push_back(i);
        }
    }
    int zero_size = zero_pos.size();
    if(zero_size == 0){
        return true;
    }
    //检查每个0出现的位置，看看他之前的数字能否到达他后面
    for (int j = 0; j < zero_size; ++j) {
        result = false;
        for (int i = 0; i < zero_pos[j]; ++i) {
            //有一个能到达就行
            if(zero_pos[j] - i < nums[i]){
                result = true;
                break;
            }
        }
        //有一个0没法越过就不能到达
        if(result == false){
            break;
        }
    }
    return result;
}

void P0055::run() {
    vector<int> nums = generate();
    bool result = canJump(nums);
    cout<<result<<endl;
}
