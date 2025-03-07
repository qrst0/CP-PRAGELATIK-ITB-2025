#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;

    int N;
    vector<int> arr;

    ll ans;
    void InputFormat() {
        LINE(N);
        LINE(arr % SIZE(N*2));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(arr_cons(arr));
    }

private:
    bool arr_cons(vector<int> &arr){
        if (arr.size() != N*2) return false;
        vector<int> freq(N+1);
        for (int x: arr){
            if (x > N || x <= 0) return false;
            if (freq[x] >= 2) return false;
            freq[x]++;
        }
        for (int i = 1; i <= N; i++){
            if (freq[i] != 2) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "1 2 2 3 1 3"
        });
        Output({
            "16"
        });
    }

    void BeforeTestCase() {
        arr.clear();
    }

    void TestCases() {
        for (int i = 1; i <= 10; i++) {
            CASE(N = i, sorted_permutation(N));
        }

        for (int i = 10; i <= NMAX; i *= 10) {
            for (int j = 0; j < 10; j++){
                CASE(N = i, random_permutation(N));
            }
        }
    }

private:
    void random_permutation(int n){
        arr.resize(n*2);
        iota(arr.begin(), arr.begin() + n, 1);
        iota(arr.begin() + n, arr.end(), 1);

        for (int i = arr.size() - 1; i > 0; i--) {
            int j = rnd.nextInt(0, i);
            swap(arr[i], arr[j]);
        }
    }

    void sorted_permutation(int n){
        arr.resize(n*2);
        for (int i = 0; i < n*2; i += 2){
            arr[i] = i/2+1;
            arr[i+1] = i/2+1;
        }
    }
};