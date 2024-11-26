#include <iostream>
#include <deque>

using namespace std;

int main(){
    std::deque<vector<int>> d;
    vector<int> a {1, 2, 3};
    vector<int> b {4, 5, 6};
    d.push_back(vector<int> ());
    d.push_back(vector<int> ());
    d.insert(d.begin(), a);
    d.insert(d.begin() + 1, b);
    for (int x = 0; x < 2; x++){
            for (int y = 0; y < 3; y++){
                cout << d.at(x).at(y) << " ";
            }
            cout << endl;
    }
    cout << endl;
    d[0] = b;
    for (int x = 0; x < 2; x++){
            for (int y = 0; y < 3; y++){
                cout << d.at(x).at(y) << " ";
            }
            cout << endl;
    }
    return 0;
}