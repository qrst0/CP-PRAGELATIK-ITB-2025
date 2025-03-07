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