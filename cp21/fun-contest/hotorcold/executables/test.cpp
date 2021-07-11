#include <bits/stdc++.h>

using namespace std;

// This class can be used to test a solution against the interactor
// without setting up a local judge. Also, it validates a solution
// completely and outputs the max queries used.

int calc_distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

class Interactor{
public:
    int last_x;
    int last_y;
    int64_t last_distance;
    int _target_x;
    int _target_y;

    int queries = 0;

    Interactor(int target_x, int target_y){
        _target_x = target_x;
        _target_y = target_y;
        last_x = 512;
        last_y = 512;
        last_distance = calc_distance(target_x, target_y, last_x, last_y);
    }


    string query(char direction, int steps){
        if (steps < 1){
            throw logic_error("Amount of steps must be positive.");
        }

        queries++;
        int x_steps = 0;
        int y_steps = 0;
        if (direction == 'l'){
            x_steps = -1 * steps;
        }
        else if (direction == 'r'){
            x_steps = steps;
        }
        else if (direction == 't'){
            y_steps = steps;
        }
        else if (direction == 'b'){
            y_steps = -1 * steps;
        }

        auto query_x = last_x + x_steps;
        auto query_y = last_y + y_steps;

        auto new_distance = calc_distance(_target_x, _target_y, query_x, query_y);

        string result;
        if (new_distance == 0){
            result = "found";
        }
        else if (new_distance < last_distance){
            result = "hot";
        }
        else{
            result = "cold";
        }

        last_x = query_x;
        last_y = query_y;
        last_distance = new_distance;

        return result;
    }
};

int current_x = 512;
int current_y = 512;

bool find_x(Interactor& interactor, int x_min, int x_max){
    bool found = false;
    while (x_min <= x_max)
    {
        int x_mid = x_min + (x_max-x_min)/2;
        int steps_to_x_mid = x_mid - current_x;

        if (steps_to_x_mid == 0){
            steps_to_x_mid = 1;
            x_mid++;
        }

        string q;
        if (steps_to_x_mid > 0){
            q = interactor.query('r', abs(steps_to_x_mid));
        }
        else{
            q = interactor.query('l', abs(steps_to_x_mid));
        }

        current_x += steps_to_x_mid;

        if (q == "found"){
            found = true;
            break;
        }

        if (abs(steps_to_x_mid) > 1){
            auto q2 = interactor.query('r', 1);
            current_x++;

            if (q2 == "found"){
                found = true;
                break;
            }

            if (q2 == "hot")
                x_min = current_x;
            else
                x_max = current_x - 1;
        }
        else{
            if (steps_to_x_mid > 0){
                if (q == "hot")
                    x_min = current_x;
                else
                    x_max = current_x - 1;
            }
            else{
                if (q == "cold")
                    x_min = current_x;
                else
                    x_max = current_x - 1;
            }
        }
    }

    if (interactor.last_x != interactor._target_x){
        throw logic_error("wrong x");
    }

    return found;
}

bool find_y(Interactor& interactor, int y_min, int y_max){
    bool found = false;
    while (y_min <= y_max)
    {
        int y_mid = y_min + (y_max-y_min)/2;
        int steps_to_y_mid = y_mid - current_y;

        if (steps_to_y_mid == 0){
            steps_to_y_mid = 1;
            y_mid++;
        }

        string q;
        if (steps_to_y_mid > 0){
            q = interactor.query('t', abs(steps_to_y_mid));
        }
        else{
            q = interactor.query('b', abs(steps_to_y_mid));
        }

        current_y += steps_to_y_mid;

        if (q == "found"){
            found = true;
            break;
        }

        if (abs(steps_to_y_mid) > 1){
            auto q2 = interactor.query('t', 1);
            current_y++;

            if (q2 == "found"){
                found = true;
                break;
            }

            if (q2 == "hot")
                y_min = current_y;
            else
                y_max = current_y - 1;
        }
        else{
            if (steps_to_y_mid > 0){
                if (q == "hot")
                    y_min = current_y;
                else
                    y_max = current_y - 1;
            }
            else{
                if (q == "cold")
                    y_min = current_y;
                else
                    y_max = current_y - 1;
            }
        }
    }

    if (interactor.last_y != interactor._target_y){
        throw logic_error("wrong y");
    }

    return found;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_queries = 0;

    for (int target_x = 0; target_x <= 1024; ++target_x){
        for (int target_y = 0; target_y <= 1024; ++target_y){
            current_x = 512;
            current_y = 512;
            auto interactor = Interactor(target_x, target_y);

            auto found = find_x(interactor, 0, 1024);
            if (!found){
                found = find_y(interactor, 0, 1024);
            }

            if (!found){
                throw logic_error("should always find");
            }

            cout << "Found target ( x=" << target_x << ", y=" << target_y << ") in " << interactor.queries << " queries." << endl;
            max_queries = max(max_queries, interactor.queries);
        }
    }

    cout << "Max queries: " << max_queries << endl;
    return 0;
}