// Buy Two Chocolates

// Task
// You are given an integer array prices representing the prices of various chocolates in a store.
// You are also given a single integer money, which represents your initial amount of money.
// You must buy exactly two chocolates in such a way that you still have some non-negative leftover money.
// You would like to minimize the sum of the prices of the two chocolates you buy.
// Return the amount of money you will have leftover after buying the two chocolates.
// If there is no way for you to buy two chocolates without ending up in debt, return money.
// Note that the leftover must be non-negative.

// Example 1:
// Input: prices = [1,2,2], money = 3
// Output: 0

// Example 2:
// Input: prices = [3,2,3], money = 3
// Output: 3

// Solution
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int tmp = money - (prices[0] + prices[1]);
        if (tmp >= 0) {
            return tmp;
        } else {
            return money;
        }
    }
};

// Results
// Runtime:
// 6 ms (Beats 92.30%)
// Memory:
// 47.18 MB (Beats 16.22%)