#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> L, R;
    vector<int> Result;

    void InputFormat() {
        LINE(N);
        LINES(L, R) % SIZE(N);
    }

    void OutputFormat() {
        LINES(Result) % SIZE(N);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(validRanges(L, R, 1, 1000000));
    }

private:
    bool validRanges(const vector<int>& L, const vector<int>& R, int lo, int hi) {
        if (L.size() != R.size()) return false;
        for (int i = 0; i < L.size(); i++) {
            if (!(lo <= L[i] && L[i] <= R[i] && R[i] <= hi)) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "1 10",
            "11 15"
        });
        Output({
            "4",
            "2"
        });
    }

    void BeforeTestCase() {
        N = 0;
        L.clear();
        R.clear();
        Result.clear();
    }

    void TestCases() {
        for (int i = 0; i < 10; i++) {
            CASE(generateTestCase(100, 1, 1000000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(generateTestCase(1000, 1, 1000000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(generateTestCase(10000, 1, 1000000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(generateTestCase(100000, 1, 1000000));
        }
        for (int i = 0; i < 10; i++) {
            CASE(generateTestCase2(100000, 1, 100, 100000, 1000000));
        }
    }

private:
    void generateTestCase(int sz, int minVal, int maxVal) {
        N = sz;
        for (int i = 0; i < sz; i++) {
            int l = rnd.nextInt(minVal, maxVal);
            int r = rnd.nextInt(l, maxVal);
            L.push_back(l);
            R.push_back(r);
        }
    }

    void generateTestCase2(int sz, int l1, int r1, int l2, int r2) {
        N = sz;
        for (int i = 0; i < sz; i++) {
            L.push_back(rnd.nextInt(l1, r1));
            R.push_back(rnd.nextInt(l2, r2));
        }
    }
};
