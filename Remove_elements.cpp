// LeetCode Problem 27: Remove Element
// Difficulty: Easy
// -----------------------------------------------
// 🧩 Problem Description:
// Given an integer array 'nums' and an integer 'val', remove all occurrences of 'val' in-place.
// The order of the elements may change.
// Return the number of elements in 'nums' that are not equal to 'val'.
//
// Example:
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: The first two elements of nums contain 2, and the rest are ignored.
//
// -----------------------------------------------
// 💡 Intuition:
// Instead of actually removing elements (which would shift everything left each time),
// we can use a pointer to "overwrite" unwanted elements.
// We'll move all valid (non-val) elements to the start of the array.
//
// -----------------------------------------------
// ⚙️ Approach (Two Pointer Method):
// 1. Create a pointer 'k' to keep track of the next index to place a valid number.
// 2. Loop through all elements using index 'i'.
// 3. If nums[i] != val, copy nums[i] to nums[k] and increment k.
// 4. At the end, 'k' will represent the number of valid elements remaining.
// 5. Elements beyond index 'k' do not matter.
//
// -----------------------------------------------
// ⏱️ Time Complexity:  O(n)   (We traverse the array once.)
// 💾 Space Complexity: O(1)   (We modify the array in-place.)
// -----------------------------------------------
// ✅ Example Walkthrough:
// nums = [0,1,2,2,3,0,4,2], val = 2
//
// Step by step:
// i=0 → 0 != 2 → nums[0]=0, k=1
// i=1 → 1 != 2 → nums[1]=1, k=2
// i=2 → 2 == 2 → skip
// i=3 → 2 == 2 → skip
// i=4 → 3 != 2 → nums[2]=3, k=3
// i=5 → 0 != 2 → nums[3]=0, k=4
// i=6 → 4 != 2 → nums[4]=4, k=5
// i=7 → 2 == 2 → skip
//
// Final nums = [0,1,3,0,4,_,_,_] and k = 5
// -----------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // pointer for the position of next valid element

        for (int i = 0; i < nums.size(); i++) {
            // If current element is not equal to val, keep it
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // move to next position
            }
        }

        // Optional: print valid elements for debugging
        cout << "[";
        for (int i = 0; i < k; i++) {
            cout << nums[i];
            if (i < k - 1) cout << ",";
        }
        cout << "]" << endl;

        return k; // total count of non-val elements
    }
};

// -----------------------------------------------
// 🧠 Summary:
// - Topic: Array / Two Pointer
// - Technique: In-place overwrite
// - Key idea: Shift valid numbers forward, skip unwanted ones
// -----------------------------------------------
