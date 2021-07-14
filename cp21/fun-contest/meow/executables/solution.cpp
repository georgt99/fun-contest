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
        int result = 1;
        while(count%2==0){
            count /= 2;
        }

        for(int j = 3; j * j <= count; j +=2){
            int divs = 0;

            while(count % j == 0){
                count /= j;
                ++divs;
            }
            result*=divs +1;
        }
        if (count > 2){
            result *= 2;
        }
        cout << result -1 << "\n";
    }
    return 0;
}



