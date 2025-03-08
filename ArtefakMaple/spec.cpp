#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int MAXN = 1e5;
    const int MAXVAL = 1e6;

    int N;
    int Result;
    vector<int> Arr;

    void InputFormat() {
        LINE(N);
        LINE(Arr);
    }

    void OutputFormat() {
        LINE(Result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(Arr.size() == N);
        CONS(eachElementBetween(Arr, 1, MAXVAL));
    }

private:
    bool eachElementBetween(vector<int> &v, int low, int high){
        for(int val : v){
            if(val < low || val > high)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "3 6 9",
        });
        Output({
            "30"
        });
    }

    void BeforeTestCase() {
        Arr.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(randomQuery(10, MAXVAL));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQuery(100, MAXVAL));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQuery(1000, MAXVAL));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQuery(10000, MAXVAL));
        }
        for (int i = 0; i < 20; i++) {
            CASE(randomQuery(100000, MAXVAL));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQueryK(100000, MAXVAL, 2));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQueryK(100000, MAXVAL, 3));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQueryK(100000, MAXVAL, 4));
        }
        for (int i = 0; i < 5; i++) {
            CASE(randomQueryK(100000, MAXVAL, 5));
        }
    }

private:
    void randomQuery(int mx, int high) {
        N = mx;
        for (int i = 0; i < N; i++) {
            Arr.push_back(rnd.nextInt(1, high));
        }
    }

    void randomQueryK(int mx, int high, int k) {
        N = mx;
        for (int i = 0; i < N; i++) {
            Arr.push_back(k * rnd.nextInt(1, high / k));
        }
    }
};
