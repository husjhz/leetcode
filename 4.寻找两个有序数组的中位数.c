/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int k;
    int len = nums1Size + nums2Size;
    int left = -1;
    int right = -1;

    for (k = 0; k <= len / 2; k++) {
        left = right;
        if (i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j])) {
            right = nums1[i++];
        }
        else {
            right = nums2[j++];
        }
    }
    if ((len & 1) == 0) {
        return (left + right) / 2.0;
    }
    else {
        return right;
    }
}


// @lc code=end

