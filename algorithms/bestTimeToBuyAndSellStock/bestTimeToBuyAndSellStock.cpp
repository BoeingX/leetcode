/**
 * Say you have an array for which the ith element is the price of a given stock on day i.

 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * problem: min_{0<=i<j<n}max(x_j-x_i, 0)
 * naive implementation gaves a O(n^2) solution
 * a key observation is that we only need to record 
 * left and right s.t. prices[left] < prices[right]
 * and the index of minimum until now noted min
 * 
 * pseudo code:
 * for each element in the array
 *      if it is smaller than prices[min]
 *          update min
 *      else
 *          if prices[i] - prices[min] > prices[left] - prices[right]:= profit
 *              update profit, left, right
 * return profit
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t left = 0, right = 0, min = 0;
        int profit = 0;
        for(size_t i = 0; i < prices.size(); i++){
            if(prices[i] < prices[min])
                min = i;
            else{
                int tmp = prices[i] - prices[min];
                if(tmp > profit){
                    profit = tmp;
                    left = min;
                    right = i;
                }
            }
        }
        return profit;
    }
};

int main(){
    Solution solution;
    vector<int> test1 = {0, 1, -10, 0}, 
                test2 = {10, 3, 7, 0},
                test3 = {4, 3, 2, 1},
                test4 = {3, 1, 4, 1, 5, 9, 2, 6};
    cout<<solution.maxProfit(test1)<<endl;
    cout<<solution.maxProfit(test2)<<endl;
    cout<<solution.maxProfit(test3)<<endl;
    cout<<solution.maxProfit(test4)<<endl;
    return 0;
}       
