/*
题目名称: 只出现一次的数字
题目描述: 给定一个非空整数数组，数组中每个元素都出现两次，只有一个元素出现一次。找出那个只出现一次的元素。
注意:
你的算法应该具有线性时间复杂度。你能在不使用额外内存的情况下实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief  在给定的数组中找到只出现一次的元素
 * @details 给定一个非空的整数数组，每个元素都出现两次，只有一个元素出现一次。找到那个只出现一次的元素
 * @note   该算法使用嵌套循环来遍历数组，对于每个元素，它都计算该元素在数组中出现的次数。如果该元素只出现了一次，它就返回该元素。否则，它将继续到下一个元素
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(1)
 * @param[in] nums  给定的整数数组
 * @param[in] numsSize  给定的数组的大小
 * @return  该数组中只出现一次的元素
 */
int singleNumber(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
                count++;
        }

        if (count == 1)
            return nums[i];

        return EOF;
    }
}

/**
 * @brief  在给定的数组中找到只出现一次的元素
 * @details 使用异或运算来找到只出现一次的元素
 *          1. 初始化结果 res = 0
 *          2. 遍历数组 nums
 *          3. 对于每个元素 nums[i]，执行异或运算 res ^= nums[i]
 *          4. 返回结果 res
 * @note   该算法使用异或运算来找到只出现一次的元素
 *         异或运算的性质是：
 *         1. a ^ 0 = a
 *         2. a ^ a = 0
 *         3. a ^ b ^ a = b
 *         4. a ^ b ^ c ^ a = b ^ c
 *         5. a ^ b ^ c ^ d ^ a = b ^ c ^ d
 *         6.  ...
 */
int singleNumber2(int *nums, int numsSize)
{
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        res ^= nums[i];
    }
    return res;
}

int main(void)
{
    int nums[] = {4, 1, 2, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = singleNumber(nums, numsSize);
    printf("%d\n", res);
    return 0;
}