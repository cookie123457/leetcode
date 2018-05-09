//
//  main.cpp
//  leetcode
//
//  Created by clown on 2018/5/9.
//  Copyright © 2018 clown. All rights reserved.
//
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> max_num(nums.size());
        max_num[0] = nums[0];
        max_num[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2 ; i < nums.size() ; ++i)
            max_num[i] = max(max_num[i - 2] + nums[i], max_num[i - 1]);
        return max_num[nums.size()-1];
    }
};
