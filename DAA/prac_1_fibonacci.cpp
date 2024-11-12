#include <iostream>
using namespace std;

int cnt = 0;
int fibbonacci(int n){
    
    if(n < 0) return 0;
    
    if(n <= 1) return n;
    
    return fibbonacci(n-1) + fibbonacci(n-2);
}


void fibSeq(int n){
    int ans = 0;
    int num1 = 0, num2 = 1;
    cout << num1 << " ";
    for(int i=2; i<=10; i++){
        ans = num1 + num2;
        cout << ans << " ";
        num2 = num1;
        num1 = ans;
    }
}

int main()
{
    int n;
    cout << "Enter number to print nFibonacci sequence : ";
    cin >> n;
    fibSeq(n);
    cout << "\nFibonacci of 10 : " << fibbonacci(10); 

    return 0;
}