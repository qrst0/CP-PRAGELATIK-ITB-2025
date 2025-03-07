#include <tcframe/spec.hpp>
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> A, B, C, D;
    vector<ll> Result;

    void InputFormat() {
        LINE(N);
        LINES(A, B, C, D) % SIZE(N);
    }

    void OutputFormat() {
        LINES(Result) % SIZE(N);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 10);
        CONS(eachValueBetween(A, 1, 10000000));
        CONS(eachValueBetween(B, 1, 10000000));
        CONS(eachValueBetween(C, 1, 1000));
        CONS(eachValueBetween(D, 0, 999));
        CONS(allDLessThanC(D, C));
        CONS(agesInDescendingOrder(B));
    }

private:
    bool eachValueBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) return false;
        }
        return true;
    }
    
    bool allDLessThanC(const vector<int>& d, const vector<int>& c) {
        for (int i = 0; i < d.size(); i++) {
            if (d[i] >= c[i]) return false;
        }
        return true;
    }
    
    bool agesInDescendingOrder(const vector<int>& b) {
        for (int i = 0; i < b.size() - 1; i++) {
            if (b[i] <= b[i+1]) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "1 5 3 1",
            "5 3 2 1",
            "10 2 1 0"
        });
        Output({
            "67",
            "5",
            "10"
        });
    }

    void BeforeTestCase() {
        A.clear();
        B.clear();
        C.clear();
        D.clear();
    }

    void TestCases() {
        // Test case 1: Minimum constraints
        CASE(N = 1,
             A = {1},
             B = {1},
             C = {1},
             D = {0});
        
        // Test case 2: Maximum N with simple values
        CASE(N = 10,
             generateSimpleTestCase(10));
        
        // Test case 3: Maximum values
        CASE(N = 10,
             generateMaxValueTestCase());
        
        // Test case 4: Random small test
        CASE(N = 5,
             generateRandomTestCase(5, 1, 100, 1, 100, 1, 10, 0, 5));
        
        // Test case 5: Random medium test
        CASE(N = 8,
             generateRandomTestCase(8, 1000, 10000, 1000, 10000, 10, 100, 5, 50));
        
        // Test case 6: Random large test
        CASE(N = 10,
             generateRandomTestCase(10, 1000000, 10000000, 1000000, 10000000, 100, 1000, 10, 900));
        
        // Test case 7: Edge case with all D = 0 (no mutation)
        CASE(N = 7,
             generateTestCaseWithAllDZero(7));
        
        // Test case 8: Edge case with all D = C-1 (maximum mutation)
        CASE(N = 6,
             generateTestCaseWithMaxMutation(6));
        
        // Test case 9: Mixed edge cases
        CASE(N = 9,
             generateMixedEdgeCaseTest(9));
        
        // Test case 10: Another random test
        CASE(N = 4,
             generateRandomTestCase(4, 5000, 50000, 5000, 50000, 50, 500, 10, 400));
    }

private:
    vector<int> A, B, C, D;
    
    void generateSimpleTestCase(int n) {
        for (int i = 0; i < n; i++) {
            A.push_back(10 + i);
            B.push_back(n*2 - i*2);  // Ensuring B is in descending order
            C.push_back(2);
            D.push_back(1);
        }
    }
    
    void generateMaxValueTestCase() {
        for (int i = 0; i < 10; i++) {
            A.push_back(10000000);
            B.push_back(10000000 - i * 1000000);  // Ensuring B is in descending order
            C.push_back(1000);
            D.push_back(999);
        }
    }
    
    void generateRandomTestCase(int n, int minA, int maxA, int minB, int maxB, int minC, int maxC, int minD, int maxD) {
        // Generate ages in descending order
        vector<int> ages;
        int currentAge = maxB;
        for (int i = 0; i < n; i++) {
            int ageGap = rnd.nextInt(1, (currentAge - minB) / (n - i) + 1);
            currentAge -= ageGap;
            ages.push_back(currentAge + ageGap);
        }
        
        for (int i = 0; i < n; i++) {
            A.push_back(rnd.nextInt(minA, maxA));
            B.push_back(ages[i]);
            C.push_back(rnd.nextInt(minC, maxC));
            D.push_back(rnd.nextInt(minD, min(maxD, C.back() - 1)));
        }
    }
    
    void generateTestCaseWithAllDZero(int n) {
        // Generate ages in descending order
        vector<int> ages;
        for (int i = 0; i < n; i++) {
            ages.push_back(10000000 - i * 1000000);
        }
        
        for (int i = 0; i < n; i++) {
            A.push_back(rnd.nextInt(1, 10000000));
            B.push_back(ages[i]);
            C.push_back(rnd.nextInt(1, 1000));
            D.push_back(0);  // No mutation
        }
    }
    
    void generateTestCaseWithMaxMutation(int n) {
        // Generate ages in descending order
        vector<int> ages;
        for (int i = 0; i < n; i++) {
            ages.push_back(10000000 - i * 1000000);
        }
        
        for (int i = 0; i < n; i++) {
            A.push_back(rnd.nextInt(1, 10000000));
            B.push_back(ages[i]);
            C.push_back(rnd.nextInt(2, 1000));  // Ensure C > 1
            D.push_back(C.back() - 1);  // Maximum possible mutation
        }
    }
    
    void generateMixedEdgeCaseTest(int n) {
        // Generate ages in descending order
        vector<int> ages;
        for (int i = 0; i < n; i++) {
            ages.push_back(10000000 - i * 1000000);
        }
        
        for (int i = 0; i < n; i++) {
            A.push_back(rnd.nextInt(1, 10000000));
            B.push_back(ages[i]);
            
            if (i % 3 == 0) {
                // No mutation
                C.push_back(rnd.nextInt(1, 1000));
                D.push_back(0);
            } else if (i % 3 == 1) {
                // Maximum mutation
                C.push_back(rnd.nextInt(2, 1000));
                D.push_back(C.back() - 1);
            } else {
                // Random mutation
                C.push_back(rnd.nextInt(1, 1000));
                D.push_back(rnd.nextInt(0, C.back() - 1));
            }
        }
    }
};