//
// Created by dell on 2019/10/14.
//

#include <set>
#include "P0047.h"

vector<int> P0047::generate() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    return nums;
}

vector<vector<int>> P0047::permuteUnique(vector<int>& nums){
//    vector<vector<int>> result;
//    set<int> nums_set(nums.begin(), nums.end());
//    nums.assign(nums_set.begin(), nums_set.end());
//    vector<int>::iterator it;
//    for(it=nums.begin();it!=nums.end();it++){
//        cout<<*it<<endl;
//    }
//    cout<<"输出全排列"<<endl;
    int size = nums.size();
    vector<int> one;
    quanpailie(nums, 0, size);
    //利用set去重
    set<vector<int>> result_set(result.begin(), result.end());
    //放回
    result.assign(result_set.begin(), result_set.end());
    return result;
}

void P0047::quanpailie(vector<int>& nums, int begin, int size){
    if(begin==size){
        vector<int> one;
        for (int i = 0; i < size; ++i) {
            one.push_back(nums[i]);
//            cout<<one[i]<<" ";
        }
        result.push_back(one);
//        cout<<endl;
    } else{
        for (int i = begin; i < size; ++i) {
            swap(nums[begin], nums[i]);
            quanpailie(nums, begin+1, size);
            swap(nums[begin], nums[i]);
        }
    }

}

void P0047::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void P0047::run() {
    vector<int> nums = generate();
    permuteUnique(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout<<"一个排列：";
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
