//
//  main.cpp
//  leetcode
//
//  Created by clown on 2018/5/7.
//  Copyright © 2018 clown. All rights reserved.
//

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec(2);
        for(int i=0;i<nums.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    vec[0] = i;
                    vec[1] = j;
                    flag=true;
                }
            }
            if(flag)
                break;
        }
        return vec;
    }
};
