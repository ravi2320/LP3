#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int solve(int idx, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp){
        
        if(idx == 0){
            if(wt[idx] <= W)
                return val[idx];
            else
                return 0;
        }
        
        if(dp[idx][W] != -1){
            return dp[idx][W];
        }
        
        int notTake = 0 + solve(idx-1, val, wt, W, dp);
        
        int take = -1e9;
        if(wt[idx] <= W){
            take = val[idx] + solve(idx-1, val, wt, W - wt[idx], dp);
        }
        
        return dp[idx][W] = max(take, notTake);
    }
    
    int knapSack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return solve(n-1, val, wt, W, dp);
    }
};

int main()
{
    int n;
    cout << "Enter no of records : ";
    cin >> n;
    
    vector<int> val(n), wt(n);
    cout << "\n";
    for(int i=0; i<n; i++){
        cout << "\nEnter value and weight of item : ";
        cin >> val[i] >> wt[i];
    }
    
    int capacity;
    cout << "\nEnter Total capacity of knapsack : ";
    cin >> capacity;
    
    Solution s;
    int knapsackVal = s.knapSack(capacity, val, wt);
    cout << "Total maximum value of item we can have is "<< knapsackVal <<" from the given capacity of sack.";

    return 0;
}

/*
Enter no of records : 3


Enter value and weight of item : 60 10

Enter value and weight of item : 100 20

Enter value and weight of item : 120 30

Enter Total capacity of knapsack : 50
Total maximum value of item we can have is 220 from the given capacity of sack.
*/