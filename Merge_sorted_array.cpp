// Intuition

// When merging two sorted arrays nums1 and nums2, we can take advantage of their sorted nature. Instead of merging from the start and needing extra space, we can fill nums1 from the back since it already has enough space to hold both arrays.

// Approach

// We have two arrays:

// nums1 of size m + n, where the last n elements are empty (0s or placeholders).

// nums2 of size n.

// We use three pointers:

// i = m - 1 (points to the last element of the initialized part of nums1)

// j = n - 1 (points to the last element of nums2)

// k = m + n - 1 (points to the last index of nums1)

// Compare elements from the end:

// If nums1[i] > nums2[j], place nums1[i] at index k and move i and k one step left.

// Otherwise, place nums2[j] at index k and move j and k one step left.

// If any elements remain in nums2, copy them into nums1 (since nums1’s remaining elements are already in correct order).

// This approach avoids using extra space and efficiently merges in-place.

// Complexity

// Time Complexity: O(m + n) — Each element from both arrays is compared and placed exactly once.

// Space Complexity: O(1) — Merging is done in-place without using extra arrays.

// Code
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;   // pointer for nums1
        int j = n - 1;   // pointer for nums2
        int k = m + n - 1; // pointer for merged position

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
