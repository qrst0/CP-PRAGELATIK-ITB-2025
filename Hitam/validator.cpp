#include <bits/stdc++.h>
using namespace std;

int ac() {
    exit(42);
}

int wa() {
    exit(43);
}

const long double PRECISION = 1e-6;

int main(int argc, char *argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);

    int n;
    if (!(tc_in >> n)){
        cout << "Cannot read N from input file";
        return wa();
    }
    int a;
    for (int i = 0; i < n; i++){
        if (!(tc_in >> a)){
            cout << "Cannot read A array elements";
            return wa();
        }
    }
    for (int i = 0; i < n; i++){
        if (!(tc_in >> a)){
            cout << "Cannot read B array elements";
            return wa();
        }
    }
    
    long double ans;
    tc_out >> ans;
    long double con_ans;
    if (!(cin >> con_ans)){
        cout << "Cannot read answer from contestant's output";
        return wa();
    }
    if (fabs(con_ans - ans) > PRECISION){
        cout << "Wrong answer";
        return wa();
    }

    cout << "Output correct\n";
    return ac();
}