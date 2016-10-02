/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell] 


*/

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

class Solution {
public:
	int getMaxProfit(vector<int>& prices, uint16_t maxSize,uint16_t buyIndex, uint16_t sellIndex){
		
		while( (sellIndex < maxSize) && (prices[sellIndex] < prices[buyIndex]) ){
			sellIndex++;
		}

		if(sellIndex >= maxSize){
			return 0;
		}
		int profit=prices[sellIndex]-prices[buyIndex] ;
//		for(int i=0;i< size;i++){
//			profit+=
//		}

		return max(+ getMaxProfit(prices,maxSize,sellIndex+2,sellIndex+3), getMaxProfit(prices,maxSize,buyIndex,sellIndex+1) );;

	}
    int maxProfit(vector<int>& prices) {
    	int mxProfit=0;
    	int size=prices.size();
    	int currentProfit=0;
    	for(int i=0;i<size;i++){
    		currentProfit=getMaxProfit(prices,size,i,i+1);
    		cout<<"\ncurrentProfit:: "<<currentProfit<<" i::"<<i;
    		mxProfit=max(mxProfit,currentProfit);
    	}
    	return mxProfit;
    }
};

//[1, 2, 3, 0, 2]
//[6,1,6,4,3,0,2]

int main(){
    Solution sol;
    int size=0;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(0);
    v.push_back(2);
    int val= sol.maxProfit(v);
    cout<<"\nResult...."<<val;


    vector<int> v1;
    v1.push_back(6);
    v1.push_back(1);
    v1.push_back(6);
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(0);
    v1.push_back(2);
    int val1= sol.maxProfit(v1);
    cout<<"\nResult...."<<val1;

   
}
