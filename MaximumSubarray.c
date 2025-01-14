/*
题目：最大子数组
给定一个整数数组 nums，找到具有最大和的连续子数组（至少包含一个数字），并返回其和。
示例：
输入：[-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：子数组 [4,-1,2,1] 的和最大，为 6。
进阶：
如果你已经找到了 O(n) 的解法，尝试使用分治法来编写另一个解法，这种方法更为巧妙。
 */

#include <stdio.h>
#include <stdlib.h>

/*
使用了双重循环来检查所有可能的子数组,时间复杂度是 O(n^2)，是使用暴力枚举法来求解最大子数组和问题。其核心思想是枚举所有可能的子数组，计算每个子数组的和，并找到其中的最大值。
1. 初始化
    定义一个变量 maxSubSum，用于存储全局的最大子数组和。
    将 maxSubSum 初始化为数组的第一个元素 nums[0]。

2. 枚举所有子数组
    使用双重循环枚举所有可能的子数组：
    外层循环：从 i = 0 到 i = numsSize - 1，表示子数组的起始位置。
    内层循环：从 j = i 到 j = numsSize - 1，表示子数组的结束位置。
    对于每个子数组 nums[i..j]，计算其和 maxSum。

3. 计算子数组和
    在内层循环中，初始化 maxSum = 0。
    从 i 到 j 遍历子数组的元素，累加每个元素到 maxSum 中。
    在每次累加后，检查是否需要更新 maxSubSum：
    如果 maxSum > maxSubSum，则更新 maxSubSum = maxSum。

4. 返回结果
    遍历结束后，maxSubSum 就是整个数组中最大子数组的和。
*/
int maxSubArray1(int *nums, int numsSize){
    int maxSubSum = nums[0];
    for(int i = 0; i < numsSize; i++){
        int maxSum = 0;
        for(int j=i; j<numsSize;j++){
            maxSum +=nums[j];
            // printf("%d -  %d = %d\n", i, j, maxSum);
            if(maxSubSum < maxSum)
                maxSubSum = maxSum;
        }
    }
    return maxSubSum;
}

/*
Kadane算法是一种用于解决最大子数组和问题的高效算法，其时间复杂度为 O(n)。该算法的核心思想是通过动态规划的思想，在遍历数组时，不断更新当前子数组的最大和，并记录全局的最大和。
1. 初始化
    定义两个变量：
    maxCurrent：表示当前子数组的最大和。
    maxGlobal：表示全局的最大子数组和。
    将 maxCurrent 和 maxGlobal 初始化为数组的第一个元素 nums[0]。

2. 遍历数组
    从数组的第二个元素开始（i = 1 到 i = numsSize - 1），依次处理每个元素 nums[i]。
    对于每个元素 nums[i]，决定是否将其加入当前的子数组，或者从该元素开始一个新的子数组：
    如果 nums[i] 大于 maxCurrent + nums[i]：
    说明从当前元素开始一个新的子数组更有利，因此更新 maxCurrent = nums[i]。
    否则：
    将当前元素加入现有的子数组，更新 maxCurrent = maxCurrent + nums[i]。

3. 更新全局最大值
    在每次更新 maxCurrent 后，检查是否需要更新 maxGlobal：
    如果 maxCurrent > maxGlobal：
    更新 maxGlobal = maxCurrent。

4. 返回结果
    遍历结束后，maxGlobal 就是整个数组中最大子数组的和。
*/
int maxSubArray2(int *nums, int numsSize){
    int maxCurrent = nums[0];
    int maxGlobal = nums[0];
    for(int i=1;i<numsSize;i++){
        if(maxCurrent + nums[i] < nums[i])
            maxCurrent = nums[i];
        else
            maxCurrent += nums[i];

        if(maxCurrent > maxGlobal)
            maxGlobal = maxCurrent;
    }
    return maxGlobal;
}

int main(void){
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int len = sizeof(nums)/sizeof(nums[0]);
    int max = maxSubArray2(nums, len);
    printf("max = %d", max);
}