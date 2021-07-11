#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

int calc_distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(int argc, char* argv[]) {
    setName("describe your interactor here");
    registerInteraction(argc, argv);

    // Use inf (.in file) and ans (.ans file).
    // Read queries from the solution using ouf, and write to it using cout.
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf).
    // Remember that you should probably have a query limit and enforce it.
    const auto target_xy = inf.readInts(2);
    const auto target_x = target_xy[0];
    const auto target_y = target_xy[1];

    const auto MAX_QUERIES = 50;

    auto last_x = 512;
    auto last_y = 512;
    auto last_distance = calc_distance(target_x, target_y, last_x, last_y);

    for(auto query = 0; query < MAX_QUERIES; ++query) {
        string t = ouf.readToken("w|e|n|s");
        auto steps = ouf.readInt(1, 1000000000);

        int x_steps = 0;
        int y_steps = 0;
        if (t == "w"){
            x_steps = -1 * steps;
        }
        else if (t == "e"){
            x_steps = steps;
        }
        else if (t == "n"){
            y_steps = steps;
        }
        else if (t == "s"){
            y_steps = -1 * steps;
        }

        auto query_x = last_x + x_steps;
        auto query_y = last_y + y_steps;

        auto new_distance = calc_distance(target_x, target_y, query_x, query_y);

        if (new_distance == 0){
            cout << "found" << endl;
            quit(_ok, "Congrats, you found the hardware wallet.");
        }
        else if (new_distance < last_distance){
            cout << "hot" << endl;
        }
        else{
            cout << "cold" << endl;
        }

        last_x = query_x;
        last_y = query_y;
        last_distance = new_distance;
    }

    cout << -1 << endl;
    quit(_wa, "too many queries");
}