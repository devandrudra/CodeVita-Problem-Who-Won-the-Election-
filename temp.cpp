#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 13;
    int k = n;
    vector<int> arr(n, 1);

    while(n != 1) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) {
                int j = i+1;
                while(arr[j % k] != 1) {
                    j++;
                }
                arr[j % k] = 0;
            }
        }
        n /= 2;
    }
    for(int i = 0; i < k; i++) {
        cout << arr[i] << ' ';
        if(arr[i] == 1)
        cout << i+1 << ' ';
    }
    
    return 0;
}