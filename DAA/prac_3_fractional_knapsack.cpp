#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b){
        return a.first > b.first;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<double, pair<int, int>>> v;
        int n = val.size();
        
        for(int i=0; i<n; i++){
            double valPerUnit = (1.0 * val[i]) / wt[i];
            v.push_back({valPerUnit, {val[i], wt[i]}});
        }
        
        sort(v.begin(), v.end(), cmp);
        double totalValue = 0;
        
        for(int i=0; i<n; i++){
            
            if(v[i].second.second > capacity){
                totalValue += (capacity * v[i].first);
                capacity = 0;
            }
            else{
                totalValue += v[i].second.first;
                capacity -= v[i].second.second;
            }
        }
        
        return totalValue;
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
    double knapsackVal = s.fractionalKnapsack(val, wt, capacity);
    cout << "Total maximum value of item we can have is "<< knapsackVal <<" from the given capacity of sack.";

    return 0;
}

/*
Enter no of records : 3


Enter value and weight of item : 60 10

Enter value and weight of item : 100 20

Enter value and weight of item : 120 30

Enter Total capacity of knapsack : 50
Total maximum value of item we can have is 240 from the given capacity of sack.
*/