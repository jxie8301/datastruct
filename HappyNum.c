#include <stdio.h>
#include <stdbool.h>

/*
 * 快乐数是指一个数字经过反复替换为其各位数字的平方和后，最终会变成1的数字。
 * 19-> 1*1+9*9=82-> 8*8+2*2=68-> 6*6+8*8=100-> 1*1+0*0+0*0=1
 */

/*
 * 计算一个数字的各位数字的平方和
 * @param n 需要计算的数字
 * @return 该数字的各位数字的平方和
 */
int getSum(int n)
{
    int sum = 0;
    int mod = 0;
    while (n > 0)
    {
        mod = n % 10;
        sum += mod * mod;
        n = n / 10;
        return sum;
    }
}

/**
 * @brief 一个数字是否是一个快乐数
 * @details 一个数字经过反复替换为其各位数字的平方和后，最终会变成1的数字
 * 使用快慢指针法，慢指针每次移动一步，快指针每次移动两步，如果在循环的话，快指针和慢指针一定会相遇
 * @param n 需要判断的数字
 * @return 该数字是否是一个快乐数
 */
bool isHappy(int n)
{
    int slow = n;
    int fast = n;
    // 使用快慢指针法，慢指针每次移动一步，快指针每次移动两步
    // 如果在循环的话，快指针和慢指针一定会相遇
    do
    {
        slow = getSum(slow);
        fast = getSum(getSum(fast));
    } while (slow != fast);

    // 最后如果 slow == 1那么这个数是一个快乐数
    return slow == 1;
}

int main()
{
    int num = 19;
    if (isHappy(num))
    {
        printf("is a happy number.\n");
    }
    else
    {
        printf("not a happy number.\n");
    }
    return 0;
}