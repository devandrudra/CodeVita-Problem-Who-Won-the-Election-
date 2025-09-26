#include<bits/stdc++.h>
using namespace std;

void BruteForce(string &q) {
    int a = 0;
    int b = 0;
    int n = q.size();

    for(int i = 0; i < n; i++) {
        if(q[i] == 'A') a++;
        else if(q[i] == 'B') b++;
        else {
            int left = i - 1;
            int right = i + 1;

            // expand left until B found
            while(left >= 0 && q[left] != 'B') left--;
            // expand right until A found
            while(right < n && q[right] != 'A') right++;

            int distB = (left >= 0) ? (i - left) : INT_MAX;
            int distA = (right < n) ? (right - i) : INT_MAX;

            cout << "Index " << i << " -> distA: " << distA << ", distB: " << distB << endl;

            if(distA < distB) a++;
            else if(distB < distA) b++;
            // else tie → stay neutral
        }
    }

    if(a == b) cout << "Coalition government\n";
    else if(a > b) cout << "A\n";
    else cout << "B\n";

    cout << "Final A votes = " << a << "\n";
    cout << "Final B votes = " << b << "\n";
}


void Optimised(string &q) {
    int n = q.size();
    vector<int> distA(n, INT_MAX);
    vector<int> distB(n, INT_MAX);

    int a = -1;
    for(int i = n-1; i >= 0; i--) {
        if(q[i] == 'A') a = i;
        if(a != -1) {
            distA[i] = a - i;
        }
    }
    int b = -1;

    for(int i = 0; i < n; i++) {
        if(q[i] == 'B') b = i;
        if(b != -1) distB[i] = i - b;
    }

    a = 0; b = 0;
    for(int i = 0; i < n; i++) {
        if(distA[i] > distB[i]) {
            b++;
        }
        else if(distA[i] < distB[i]) {
            a++;
        }
    }
    cout << "A score is: " << a << endl;
    cout << "B score is: " << b << endl;

    if(a > b) cout << "Winner is: A" << endl;
    else if(a < b) cout << "Winner is: B" << endl;
    else cout << "Coaliation";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string q;
    cin >> q;
    cout << q << endl;
    

    Optimised(q);


    return 0;
}