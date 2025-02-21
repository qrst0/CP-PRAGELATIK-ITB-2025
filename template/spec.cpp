#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    int A, B;

    int Result;

    void InputFormat() {
        LINE(A, B);
    }

    void OutputFormat() {
        LINE(Result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= A && A <= 1000000000);
        CONS(1 <= B && B <= 1000000000);
    }

private:

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2 3"
        });
        Output({
            "5"
        });
    }

    void BeforeTestCase() {

    }

    void TestCases() {
        for (int i = 0; i < 20; i++) {
            CASE(A = rnd.nextInt(1, 1000000000),
                B = rnd.nextInt(1, 1000000000)
                );
        }
    }

private:
    
};