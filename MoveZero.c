/*
*题目：移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例：
输入: [0,1,0,3,12]    输出: [1,3,12,0,0]
注意：
必须在原地操作，不能复制数组。尽量减少操作的总次数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 该方法将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 * 1. 创建一个数组 distNums，用于存储非零元素
 * 2. 遍历nums数组，将非零元素存储到distNums中
 * 3. 使用 memcpy 函数将 distNums 数组拷贝到 nums 中
 * 时间复杂度: O(n)，其中 n 为数组 nums 的长度
 * 空间复杂度: O(n)，由于使用了额外的数组 distNums
 */
void moveZeroes(int *nums, int numSize)
{
    // int distNums[numSize] = {0};因为numSize是不确定的，所以不行
    int distNums[numSize];
    memset(distNums, 0, sizeof(distNums)); // 初始化数组为 0
    int j = 0;
    for (int i = 0; i < numSize; i++)
    {
        if (nums[i] != 0)
        {
            distNums[j] = nums[i]; // 将非零元素存储到 distNums 中
            j++;                   // 更新 distNums 的索引
        }
    }

    memcpy(nums, distNums, sizeof(distNums));
}

/**
 * 该函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 * 1. 遍历nums数组
 * 2. 将所有非零元素往前移动
 * 3. 将所有零元素往后移动
 * 时间复杂度: O(n*n),其中 n 为数组 nums 的长度
 * 空间复杂度: O(1)
 */
void moveZeroes2(int *nums, int numSize)
{
    int isOK = 1;
    while (isOK)
    {
        isOK = 0;
        for (int i = 0; i < numSize; i++)
        {
            if (nums[i] == 0 && nums[i + 1] != 0)
            {
                for (int j = i; j < numSize - 1; j++)
                {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
                isOK = 1;
            }
        }
    }
}

/**
 * 该函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 * 1. 创建一个变量 j，用于保存非零元素的索引
 * 2. 遍历nums数组，将非零元素存储到 nums[j] 中
 * 3. 更新 j
 * 时间复杂度: O(n)，其中 n 为数组 nums 的长度
 * 空间复杂度: O(1)，只使用了额外的常数个变量
 */
void moveZeroes3(int *nums, int numSize)
{
    int j = 0; // j 保存非零元素的索引
    for (int i = 0; i < numSize; i++)
    {
        if (nums[i] != 0)
        {
            if (i != j)
            {                      // 避免不必要的交换
                nums[j] = nums[i]; // 将非零元素存储到 nums[j] 中
                nums[i] = 0;       // 将 nums[i] 设置为 0
            }
            j++; // 更新 j
        }
    }
}

int main(void)
{
    // int nums[] = {0, 0, 1, 0, 3, 0, 0, 12, 0};
    int nums[] = {1, 2, 3, 0, 0, 1, 2, 3};
    int numSize = sizeof(nums) / sizeof(nums[0]);

    // moveZeroes(nums, numSize);
    moveZeroes2(nums, numSize);
    // moveZeroes3(nums, numSize);

    printf("Result: ");
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}