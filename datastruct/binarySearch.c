#include <stdio.h>
#include <stdlib.h>

int search1(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

int search2(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    if (left >= numsSize || nums[left] != target) {
        return -1;
    }
    return left;
}

int search3(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void)
{
    int nums[] = {1, 8, 12, 19, 19, 19, 19, 25, 92, 93};
    int res;

    res = search1(nums, ARRAY_SIZE(nums), 19);
    printf("%d, %d\n", res, res == -1 ? -1 : nums[res]);
    res = search2(nums, ARRAY_SIZE(nums), 19);
    printf("%d, %d\n", res, res == -1 ? -1 : nums[res]);
    res = search3(nums, ARRAY_SIZE(nums), 19);
    printf("%d, %d\n", res, res == -1 ? -1 : nums[res]);

    return 0;
}
