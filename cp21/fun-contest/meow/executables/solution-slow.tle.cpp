#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases;
    cin >> testcases;

    for(int i = 0; i < testcases; i++){
        string s;
        cin >> s;

        int count = 0;

        for(char c : s){
            if(c == 'e' || c == 'o') count++;
        }
        int result = 0;
        for(int j = 1; j < count; j++){
           int sum = 0;
            for(int k = j; k < count ; k++) {
                sum += k;
                if (sum == count) {
                    result++;
                    break;
                }
                if(sum > count) break;
            }
        }
    cout << result << "\n";
    }

    return 0;
}



