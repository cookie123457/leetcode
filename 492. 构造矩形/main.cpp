//
//  main.cpp
//  leetcode
//
//  Created by clown on 2018/5/7.
//  Copyright © 2018 clown. All rights reserved.
//

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int num = area;
        vector<int> vec(2);
        int end = (int)sqrt(area);
        for(int i=1;i<=end;i++)
        {
            if(area % i == 0)
            {
                int j = area / i;
                if(j>=i && (j-i)<=num)
                {
                    num = j - i;
                    vec[0] = j;
                    vec[1] = i;
                }
            }
        }
        return vec;
    }
};
