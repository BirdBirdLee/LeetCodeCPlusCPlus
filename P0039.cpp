//
// Created by dell on 2019/10/13.
//

#include "P0039.h"

//P0039::P0039() {cout<<"this is P0039"<<endl;}
//void P0039::test() {cout<<"p0039 success"<<endl;}

vector<int> P0039::generate() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    return nums;
}

vector<vector<int>> P0039::permute(vector<int>& nums){
//    vector<vector<int>> result;
    vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        cout<<*it<<endl;
    }
//    cout<<"输出全排列"<<endl;
    int size = nums.size();
    vector<int> one;
    quanpailie(nums, 0, size);
    return result;
}

void P0039::quanpailie(vector<int>& nums, int begin, int size){
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

void P0039::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void P0039::run() {
    vector<int> nums = generate();
    permute(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout<<"一个排列：";
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
