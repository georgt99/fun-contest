#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200;
const int MAX_A = 40;
const int MAX_K = 20;
const int MAX_M = 500;


const string_view SAMPLE1 = R"(2 2
4 4
0 1
0 2
1 3
2 3
)";


const string_view SAMPLE2 = R"(2 3
5 7
0 1
0 2
0 3
2 3
1 4
2 4
3 4
)";

const string_view SAMPLE3 = R"(4 2
3 2
0 1
1 2
)";

const string_view SAMPLE_IND_SET = R"(1 1
1000 0
)";

template <class F>
void testcase(string name, string desc, F f) {
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    f();
}

void predefined(string name, string desc, string_view content) {
    testcase(name, desc, [&]() { cout << content; });
}

void sample(int num, string_view content) {
    auto num_str = toString(num);
    predefined("sample" + num_str, "Sample #" + num_str, content);
}

void fixed_rows_testcase(string name, string desc, vector<string> rows) {
    testcase(name, desc, [&]() {
        for (auto r : rows)
            println(r);
    });
}

string lineOfPair(int x, int y) {
    return toString(x) + " " + toString(y);
}

void clique_testcase(string name, string desc, int a, int k, int n) {
    int m = (n*n-1) / 2;
    vector<string> rows(m + 2);
    rows[0] = lineOfPair(a, k);
    rows[1] = lineOfPair(n, m);
    int counter = 0;
    for (int x = 0; x < n; x++) {
        for (int y = x+1; y < n; y++) {
            rows[2 + counter] = lineOfPair(y, x);
            counter++;
        }
    }
    fixed_rows_testcase(name, desc, rows);
}

void rnd_testcase(string name, string desc) {
    int a = rnd.next(1, MAX_A);
    int n = rnd.next(2, MAX_N);
    int m = rnd.next(0, MAX_M);
    int k = rnd.next(1, MAX_K);
    vector<string> rows(m + 2);
    rows[0] = lineOfPair(a, k);
    rows[1] = lineOfPair(n, m);
    for (int i=0; i < m; i++) {
        int y;
        int x = rnd.next(n);
        do {
            y = rnd.next(n);
        } while (x == y);
        rows[i+2] = lineOfPair(x, y);
    }
    fixed_rows_testcase(name, desc, rows);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(7403802613515010878ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    sample(3, SAMPLE3);

    predefined("sample4", "Independent Set", SAMPLE_IND_SET);
    clique_testcase("sample5", "Small clique 1", 4, 3, 10);
    clique_testcase("sample6", "Small clique 2", 3, 7, 10);
    clique_testcase("sample7", "Big clique 1", MAX_A / 2, 13, MAX_N);
    clique_testcase("sample8", "Big clique 2", MAX_A, MAX_K, MAX_N);

    int num_random_samples = 9;
    for (int i = 0; i < num_random_samples; i++) {
        rnd_testcase("sample" + toString(num_random_samples+i), "Random Sample #" + toString(i+1));
    }
    return 0;
}