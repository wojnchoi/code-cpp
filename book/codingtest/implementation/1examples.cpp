#include<iostream>
#include<stdlib.h>
using namespace std;

// 4-1 author answer
int n;
string plans;
int x = 1, y = 1;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main() {
    cin>>n;
    cin.ignore();
    getline(cin,plans);

    for(int i = 0; i< plans.size(); i++) {
        char plan = plans[i];

        int nx = -1, ny = -1;
        for(int j = 0;j<4; j++) {
            if(plan == moveTypes[j]) {
                nx = x+dx[j];
                ny = y+dy[j];
            }
        }
    if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
    x = nx;
    y = ny;
    }

    cout<<x<<" "<<y<<"\n";
    return 0;
}


// 4-2 my answer
int main() {
    string time;
    int h, count = 0;
    cin>>h;
    for(int i = 0; i <h+1; i++) {
        for(int j = 0; j<60;j++) {
            for(int k = 0; k<60; k++) {
                time = to_string(i) + to_string(j) + to_string(k);
                for(int l = 0; l<5;l++)
                    if(time[l] == '3') {
                        count++; break;
                    }
            }
        }
    }
    cout<<count<<endl;
}

