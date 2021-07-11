#include <bits/stdc++.h>

using namespace std;

int current_x = 512;
int current_y = 512;

bool find_x(int x_min, int x_max){
    bool found = false;
    while (x_min <= x_max)
    {
        int x_mid = x_min + (x_max-x_min)/2;
        int steps_to_x_mid = x_mid - current_x;

        if (steps_to_x_mid == 0){
            steps_to_x_mid = 1;
            x_mid++;
        }

        if (steps_to_x_mid > 0){
            cout << "r " <<  abs(steps_to_x_mid) << endl;
        }
        else{
            cout << "l " <<  abs(steps_to_x_mid) << endl;
        }

        string q; cin >> q;

        current_x += steps_to_x_mid;

        if (q == "found"){
            found = true;
            break;
        }

        if (abs(steps_to_x_mid) > 1){
            cout << "r 1" << endl;
            string q2; cin >> q;
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

    return found;
}

bool find_y(int y_min, int y_max){
    bool found = false;
    while (y_min <= y_max)
    {
        int y_mid = y_min + (y_max-y_min)/2;
        int steps_to_y_mid = y_mid - current_y;

        if (steps_to_y_mid == 0){
            steps_to_y_mid = 1;
            y_mid++;
        }

        if (steps_to_y_mid > 0){
            cout << "t " <<  abs(steps_to_y_mid) << endl;
        }
        else{
            cout << "b " <<  abs(steps_to_y_mid) << endl;
        }

        string q; cin >> q;

        current_y += steps_to_y_mid;

        if (q == "found"){
            found = true;
            break;
        }

        if (abs(steps_to_y_mid) > 1){
            cout << "t 1" << endl;
            string q2; cin >> q;
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

    return found;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto found = find_x(0, 1024);
    if (!found){
        found = find_y(0, 1024);
    }

    return 0;
}