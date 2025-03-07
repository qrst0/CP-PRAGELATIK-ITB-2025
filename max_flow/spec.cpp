#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, D;
    vector<long long> A, L, R, VAL;
    long long res;

    void InputFormat() {
        LINE(N, D);
        LINE(A % SIZE(N));
        LINES(L, R, VAL) % SIZE(D);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(1 <= D && D <= 100000);

        CONS(eachElementBetween(A, 1, 1000000000));
        CONS(eachElementBetween(VAL, 1, 1000000000));
        CONS(eachElementBetween(L, R, 1, N));
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

    bool eachElementBetween(const vector<long long>& v1, const vector<long long>& v2, long long lo, long long hi) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < lo || v1[i] > hi || v2[i] < lo || v2[i] > hi) {
                return false;
            }

            if (v1[i] > v2[i]) {
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
                "4 4",
                "5 4 3 2",
                "1 2 4",
                "1 1 3",
                "2 4 1",
                "3 3 4"
            });
            Output({
                "12"
            });
        }
    
        void BeforeTestCase() {
            L.clear();
            R.clear();    
            VAL.clear();
            A.clear();
        }
    
        void TestCases() {
            CASE(N = 1, D = 5, A = {10}, L = {1, 1, 1, 1, 1}, R = {1, 1, 1, 1, 1}, VAL = {1, 2, 3, 4, 5});
            CASE(N = 2, D = 5, A = {100, 1}, L = {1, 1, 1, 1, 1}, R = {2, 2, 2, 2, 2}, VAL = {69, 69, 69420, 177013, 42});

            for (int i = 1; i <= 10; i++) {
              CASE(N = rnd.nextInt(2, 100000), D = rnd.nextInt(2, 100), randomElements(N, D, rnd.nextInt(1, min(10, min(N, D)))));
            }

            for (int i = 1; i <= 10; i++) {
              CASE(N = rnd.nextInt(2, 100000), D = rnd.nextInt(2, 100), randomElements(N, D, rnd.nextInt(1, min(100, min(N, D)))));
            }

            for (int i = 1; i <= 5; i++) {
              CASE(N = rnd.nextInt(2, 100000), D = rnd.nextInt(2, 100000), randomElements(N, D, rnd.nextInt(1, min(100, min(N, D))), 10, 1e9));
              CASE(N = rnd.nextInt(2, 100000), D = rnd.nextInt(2, 100000), randomElements(N, D, rnd.nextInt(1, min(100, min(N, D))), 1e9, 10));
              CASE(N = rnd.nextInt(2, 100000), D = rnd.nextInt(2, 100000), randomElements(N, D, rnd.nextInt(1, min(N, D)), 1e9, 1e9));
            }
        }
    
    private:
        void randomElements(int N, int D, int splitInto, int maxVal = 1e9, int maxCap = 1e9) {
          vector<pair<int, int>> lines;
          vector<int> num_of_pair;

          int l = 1;
          for (int i = 0; i < splitInto; i++) {
            int r = rnd.nextInt(l, N - (splitInto - i - 1));
            lines.push_back({l, r});
            l = r + 1;
          }

          int sum = D;
          for (int i = 0; i < splitInto - 1; i++) {
            int num = rnd.nextInt(1, sum - splitInto + i + 1);
            num_of_pair.push_back(num);

            sum -= num;
          }
          num_of_pair.push_back(sum);

          for (int i = 0; i < splitInto; i++) {
            for (int j = 0; j < num_of_pair[i]; j++) {
              int l = rnd.nextInt(lines[i].first, lines[i].second);
              int r = rnd.nextInt(l, lines[i].second);
              int val = rnd.nextInt(1, maxVal);
              
              L.push_back(l);
              R.push_back(r);
              VAL.push_back(val);
            }
          }

          for (int i = 0; i < N; i++) {
            A.push_back(rnd.nextInt(1, maxCap));
          }
        }
    };