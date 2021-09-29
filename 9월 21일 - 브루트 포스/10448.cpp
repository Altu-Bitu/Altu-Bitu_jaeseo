#include <iostream>
#include <vector>
using namespace std;

int triangle[45], result[4000] = { 0 }; //44^2=1,936

int main() {
    int t, input;

    //초기
    for (int i = 1; i < 46; i++) triangle[i] = triangle[i - 1] + i;

    for (int i = 1; i < 46; i++)
        for (int j = 1; j < 46; j++)
            for (int k = 1; k < 46; k++)
                result[triangle[i] + triangle[j] + triangle[k]] = 1;

    cin >> t;
    while (t--) {
        cin >> input;
        cout << result[input] << '\n';
    }
}