#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int QMAX =1e5;
    const int AMAX = 1e5;
    const ll KMAX = 1e5;
    const ll XMAX = 1e12;

    int N, Q;
    vector<int> arr;
    vector<int> type;
    vector<vector<ll>> data;

    vector<ll> ans;
    void InputFormat() {
        LINE(N, Q);
        LINE(arr % SIZE(N));

        LINES(type, data) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= Q && Q <= QMAX);
        CONS(arr_cons(arr));
        CONS(query_cons(type, data));
    }

private:
    bool arr_cons(vector<int> &arr){
        if (arr.size() != N) return false;
        for (int x: arr){
            if (x > AMAX || x < -AMAX) return false;
        }
        return true;
    }

    bool query_cons(vector<int>& type, vector<vector<ll>>& query){
        if (type.size() != Q) return false;
        if (query.size() != Q) return false;
        for (int i = 0; i < Q; i++){
            if (type[i] != 1 && type[i] != 2) return false;
            if (type[i] == 1){
                if (query[i].size() != 2) return false;
                ll x = query[i][0], k = query[i][1];
                if (x < -XMAX || x > XMAX) return false;
                if (k < -KMAX || k > KMAX) return false;
            }
            else{
                if (query[i].size() != 1) return false;
                ll j = query[i][0];
                if (j < 1 || j > N) return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 5",
            "2 3 2 4 3",
            "1 2 2",
            "2 1",
            "1 4 5",
            "2 3",
            "2 2",
        });
        Output({
            "4",
            "9",
            "3",
        });
    }

    void BeforeTestCase() {
        arr.clear();
        type.clear();
        data.clear();
    }

    void TestCases() {
        for (int i = 0; i < 10; i++) {
            CASE(N = 10, Q = 10, random_array(N, 100), random_queries(Q, N, 100*100, 100));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = 100, Q = 100, random_array(N, 1000), random_queries(Q, N, 1000*1000, 1000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = 1000, Q = 1000, random_array(N, 10000), random_queries(Q, N, 10000*10000, 10000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, Q = 1000, random_array(N, AMAX), random_queries(Q, N, XMAX, KMAX));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = 1000, Q = QMAX, random_array(N, AMAX), random_queries(Q, N, XMAX, KMAX));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, Q = QMAX, random_array(N, AMAX), random_queries(Q, N, XMAX, KMAX));
        }
        CASE(N = NMAX, Q = QMAX, rata_array(N), rata_queries(Q, N));
    }

private:
    void random_array(int n, int amax){
        arr.resize(n);
        for (int i = 0; i < n; i++){
            arr[i] = rnd.nextInt(1, amax);
        }
    }

    void random_queries(int q, int n, ll xmax, ll kmax){
        type.resize(q);
        data.resize(q);
        for (int i = 0; i < q; i++){
            type[i] = rnd.nextInt(1, 2);
            if (type[i] == 1){
                ll x = rnd.nextLongLong(-xmax, xmax);
                ll k = rnd.nextLongLong(-kmax, kmax);
                data[i].push_back(x);
                data[i].push_back(k);
            }
            else{
                ll j = rnd.nextInt(1, n);
                data[i].push_back(j);
            }
        }
    }

    void rata_array(int n){
        arr.resize(n, 0);
    }

    void rata_queries(int q, int n){
        type.resize(q);
        data.resize(q);
        for (int i = 0; i < q-1; i++){
            type[i] = 1;
        }
        type[q-1] = 2;
        for (int i = 0; i < q; i++){
            if (type[i] == 1){
                data[i].push_back(i);
                data[i].push_back(1);
            }
            else{
                data[i].push_back(rnd.nextInt(1, n));
            }
        }
    }
};