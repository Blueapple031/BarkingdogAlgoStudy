#include <iostream>

using namespace std;

int N, j_x = 0, j_y = 0;
int map[65][65] = {-2};
bool down[65][65] = {false};
int pre_j_y = 0, pre_j_x = 0;

void jump(int n){//n칸 jump
    if(down[j_y][j_x]) j_y += n;
    else j_x += n;
}

void start(){
    if(map[j_y][j_x] == -1){
        cout << "HaruHaru";
        return;
    }
    while(j_y<N && j_x<N) {//칸을 넘어가면 전으로 되돌리고 return
        pre_j_y = j_y;
        pre_j_x = j_x;
        down[j_y][j_x] = true;
        jump(map[j_y][j_x]);
        start();
    }

        j_y = pre_j_y;
        j_x = pre_j_x;
        return;
    
}

int main(){
    cin >> N;
    for(int j = 0; j <N; j++){
        for(int i = 0; i <N; i++) cin >> map[j][i];
    }
    start();
}