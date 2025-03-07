#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M, K;
    vector<long long> X, Y, D;
    long long res;

    void InputFormat() {
        LINE(N, M, K);
        LINES(X, Y, D) % SIZE(K);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(2 <= N && N <= 1000);
        CONS(2 <= M && M <= 1000);
        CONS(2 <= (N+M)*(N+M) <= 1000000);
        CONS(0 <= K && K <= N*M && K <= 100000);

        CONS(eachElementBetween(X, 1, N));
        CONS(eachElementBetween(Y, 1, M));
        CONS(eachElementBetween(D, 1, N+M));
    }

private:
    bool eachElementBetween(const vector<long long>& v, long long lo, long long hi) {
        for (long long x : v) {
            if (x < lo || x > hi) {
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
                "5 6 3",
                "1 1 4",
                "2 3 2",
                "5 2 5",
            });
            Output({
                "10"
            });
        }
    
        void BeforeTestCase() {
            X.clear();
            Y.clear();    
            D.clear();
        }
    
        void TestCases() {
            for (int i = 1; i <= 3; i++) {
                CASE(N = rnd.nextInt(2, 10), M = rnd.nextInt(800, 1000), K = rnd.nextInt(10, min(100000, N*M)), randomElements(N, M, K));
                CASE(N = rnd.nextInt(800, 1000), M = rnd.nextInt(2, 10), K = rnd.nextInt(10, min(100000, N*M)), randomElements(N, M, K));
            }
            for (int i = 1; i <= 10; i++) {
                CASE(N = rnd.nextInt(25, 50), M = rnd.nextInt(25, 50), K = rnd.nextInt(0, min(100, N*M)), randomElements(N, M, K));
            }
            for (int i = 1; i <= 10; i++) {
              CASE(N = rnd.nextInt(5, 1000), M = rnd.nextInt(5, 1000),  K = rnd.nextInt(10, min(100000, N*M)), randomElements(N, M, K, 10));
              CASE(M = rnd.nextInt(5, 1000), N = rnd.nextInt(5, 1000),  K = rnd.nextInt(10, min(100000, N*M)), randomElements(N, M, K, 10));
          }
            for (int i = 1; i <= 5; i++) {
                CASE(N = rnd.nextInt(5, 1000), M = rnd.nextInt(5, 1000),  K = rnd.nextInt(10, min(100000, N*M/10)), randomElements(N, M, K, 10));
                CASE(M = rnd.nextInt(5, 1000), N = rnd.nextInt(5, 1000),  K = rnd.nextInt(10, min(100000, N*M/10)), randomElements(N, M, K, 10));
            }
            
        }
    
    private:
        void randomElements(int N, int M, int K) {
            for (int i = 1; i <= K; i++) {
                X.push_back(rnd.nextInt(1, N));
                Y.push_back(rnd.nextInt(1, M));
                D.push_back(rnd.nextInt(1, N+M));
            }
        }

        void randomElements(int N, int M, int K, int maxD) {
            for (int i = 1; i <= K; i++) {
                X.push_back(rnd.nextInt(1, N));
                Y.push_back(rnd.nextInt(1, M));
                D.push_back(rnd.nextInt(1, maxD));
            }
        } 
    };