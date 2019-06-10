# Algorithms
Solution for random algorithms from "Elements of Programming Interviews" in C++.

# Contents
* SubstringSearchEfficient.cpp:
Given an array of strings and a set of keywords, finds the smallest subarray containing all keywords. O(n^2)
* LowestCommonAncestorEfficient.cpp:
Finds the lowest common ancestor of 2 nodes in a binary tree in O(distance from node to LCA node), given that each node contains a pointer to its parent.
* InOrderIt.cpp: Iterative implementation of in order traversal of a binary tree given that nodes have a pointer to their parent.
* IntersectionOfTwoSortedArrays.cpp: Given 2 sorted arrays, return a set containing the common elements.
* BinaryManipulation.cpp: Contains various problems solved in O(1).
    * unsigned long long closestIntSameWeight(const unsigned long long x): Define the weight of an integer as the number of 1's it has in its binary representation. Given an integer, the function finds the closest integer to it having the same weight.
    * bool testIfPow2(unsigned long long x): returns true if x is a power of 2.
    * unsigned long long modPower2(const unsigned long long x, const int p): returns x mod 2^p.
    * unsigned long long swapBits(unsigned long long x, const int i, const int j): Swaps the ith and jth bits of x.
* IntervalsUnion.cpp: Given a set of intervals (with endpoints being either open or closed), finds their union. O(nlogn) time and O(1) space where n is the number of intervals.
* checkBST.cpp: Give the root of a binary tree, checks if the tree satisfies the BST property.
* hasCycle.cpp: Given a linked list, checks if it has a cycle. O(n) time and O(1) space.
* PreorderToBST.cpp: Given Preorder traversal data of a BST, reconstructs it. O(n) time O(h) space.
* SortedArrayToMinBST.cpp: Given a sorted array, builds the minimum height BST. O(n) time, O(logn) space.
* CyclicSortedArray.cpp: Given a cyclic sorted array (Array that can be made sorted by shifting), finds the required shift amount. O(logn) time O(1) space.
* HeapMaxK.cpp: Given an array representation of a heap, find the maximum k elements without modifying the array. O(k logk) time, O(k) space.
* MaxQueue.cpp: Implementation of a queue with a max() operation. Max is returned in O(1), insertion worst case is O(n).
* MaxKElements.cpp: Given an array of integers, and an integer k, finds the maximum k elements in the array. O(nlogk).
* KthLargest.cpp: Given an array of integers, and an integer k, finds the kth largest element. Average case is O(n) and worst case is O(n^2). The complexity analysis here is similar to quicksort's.

# Notes
* In all functions, I assumed valid input --checking is not necessary.
* Every cpp file has its own implementation of the data structure if needed.
