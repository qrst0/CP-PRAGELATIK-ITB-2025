#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> a, b;
    double Result;

    void InputFormat() {
        LINE(N);
        LINE(a % SIZE(N));
        LINE(b % SIZE(N));
    }

    void OutputFormat() {
        LINE(Result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000000);
        CONS(arrcons(a, N));
        CONS(arrcons(b, N));
    }

private:
    bool arrcons(vector<int> &arr, int n) {
        if (arr.size() != n) return false;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0 || arr[i] > 1000000000) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "2 3",
            "5 5"
        });
        Output({
            "0.634921"
        });
    }

    void BeforeTestCase() {
        a.clear();
        b.clear();
    }

    void TestCases() {
        for (int i = 0; i < 4; i++) CASE(N = 1, random_array(a, N), random_array(b, N));
        CASE(N = 1, a = {0}, b = {0});
        for (int i = 0; i < 5; i++) CASE(N = 10, random_array(a, N), random_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000, random_array(a, N), random_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000000, random_array(a, N), random_array(b, N));
        
        for (int i = 0; i < 5; i++) CASE(N = 100, zero_heavy_array(a, N), random_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 100, random_array(a, N), zero_heavy_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000, zero_heavy_array(a, N), zero_heavy_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000000, zero_heavy_array(a, N), random_array(b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000000, random_array(a, N), zero_heavy_array(b, N));
        
        for (int i = 0; i < 5; i++) CASE(N = 100, large_gap_array(a, b, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000, large_gap_array(b, a, N));
        for (int i = 0; i < 5; i++) CASE(N = 1000000, large_gap_array(a, b, N));
        
    }

private:
    void random_array(vector<int> &arr, int n) {
        arr.clear();
        for (int i = 0; i < n; i++) {
            arr.push_back(rnd.nextInt(0, 1000000000));
        }
    }
    
    void zero_heavy_array(vector<int> &arr, int n) {
        arr.clear();
        for (int i = 0; i < n; i++) {
            arr.push_back(rnd.nextInt(0, 10) == 0 ? 0 : rnd.nextInt(0, 1000000000));
        }
    }
    
    void large_gap_array(vector<int> &a, vector<int> &b, int n) {
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++) {
            int ai = rnd.nextInt(0, 500000000);  // Ensure a[i] is relatively small
            int bi = rnd.nextInt(ai + 500000000, 1000000000);  // Ensure b[i] is much larger
            a.push_back(ai);
            b.push_back(bi);
        }
    }
};