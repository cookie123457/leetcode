//
//  main.cpp
//  633. 平方数之和
//
//  Created by clown on 2018/5/6.
//  Copyright © 2018 clown. All rights reserved.
//

#include <cmath>
class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            int i = 0, j = (int)sqrt(c);
            while (i <= j) {
                int powSum = i * i + j * j;
                if (powSum == c)
                    return true;
                if (powSum > c)
                    j--;
                else
                    i++;
            }
            return false;
        }
};
