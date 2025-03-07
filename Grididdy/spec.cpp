#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1000;

    int N, first;
    vector<string> grid;
    string ans;
    void InputFormat() {
        LINE(N, first);
        LINES(grid);
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
        CONS(grid_cons());
    }

private:
    bool grid_cons(){
        if (grid.size() != N) return false;
        for (string x: grid){
            if (x.size() != N) return false;
            for (char c: x){
                if (c != '1' && c != '0') return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 1",
            "10001",
            "11011",
            "10101",
            "10101",
            "10001",
        });
        Output({
            "MIRIS",
        });
    }

    void BeforeTestCase() {
        grid.clear();
    }

    void TestCases() {

        for (int i = 10; i <= NMAX; i *= 10) {
            for (int j = 0; j < 10; j++){
                CASE(N = i, first = rnd.nextInt(0, 1), random_grid(N));
            }
        }
        CASE(N = 1, first = 0, one_grid("1"));
        CASE(N = 1, first = 1, one_grid("1"));
        CASE(N = 1, first = 0, one_grid("0"));
        CASE(N = 1, first = 1, one_grid("0"));
        
    }

private:
    void one_grid(string c){
        grid.resize(1);
        grid[0] = c;
    }

    void random_grid(int n){
        grid.resize(n);
        for (int i = 0; i < n; i++){
            string str = "";
            for (int j = 0; j < n; j++){
                str += (char)(rnd.nextInt(0, 1) + '0');
            }
            grid[i] = str;
        }
    }
};