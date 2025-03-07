#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q;
    vector<int> A, B, X;
    vector<int> Result;

    void InputFormat() {
        LINE(N);
        LINE(A);
        LINE(B);
        LINE(Q);
        LINE(X);
    }

    void OutputFormat() {
        LINES(Result);
    }

    void GradingConfig() {
        TimeLimit(3);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(1 <= Q && Q <= 10000);
        CONS(eachElementBetween(A, 1, (1 << 14) - 1));
        CONS(eachElementBetween(B, 1, (1 << 15) - 1));
        CONS(eachElementBetween(X, 1, (1 << 14) - 1));
    }

private:
    bool eachElementBetween(const vector<int>& X, int lo, int hi) {
        for(const int &x: X){
            if(x < lo || x > hi){
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
            "3",
            "1 2 3",
            "6 5 4",
            "3",
            "2 3 1"
        });
        Output({
            "5",
            "4",
            "5"
        });
    }

    void BeforeTestCase() {
        A.clear();
        B.clear();
        X.clear();
        Result.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(5, 100),
                    Q = rnd.nextInt(5, 100),
                    randomArray(N, A, 1, (1 << 14) - 1),
                    randomArray(N, B, 1, (1 << 15) - 1),
                    randomArray(Q, X, 1, (1 << 14) - 1)
                );
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(500, 1000),
                    Q = rnd.nextInt(500, 1000),
                    randomArray(N, A, 1, (1 << 14) - 1),
                    randomArray(N, B, 1, (1 << 15) - 1),
                    randomArray(Q, X, 1, (1 << 14) - 1)
                );
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(10000, 100000),
                    Q = 10000,
                    randomArray(N, A, 1, (1 << 14) - 1),
                    randomArray(N, B, 1, (1 << 15) - 1),
                    randomArray(Q, X, 1, (1 << 14) - 1)
                );
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = 100000,
                    Q = 10000,
                    randomArray(N, A, 1, (1 << 14) - 1),
                    randomArray(N, B, 1, (1 << 15) - 1),
                    randomArray(Q, X, 1, (1 << 14) - 1)
                );
        }
    }

private:
    void randomArray(int m, vector<int>& w, int minW = 0, int maxW = 1000000000) {
        for (int i = 0; i < m; i++) {
            int randomNum = rnd.nextInt(minW, maxW);
            w.push_back(randomNum);
        }
    }
};