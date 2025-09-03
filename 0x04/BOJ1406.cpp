#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;
int length = 0, cursor = 0;

void stringLink(string K){
    nxt[0] = 1;
    for(char c : K){
        pre[unused] = unused-1;
        dat[unused] = c;
        nxt[unused] = unused+1;
        unused++;
        length++;
        cursor++;
    }
    nxt[unused-1] = -1;
}
void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << (char)dat[cur];
        cur = nxt[cur];
    }
}
void process(char command, char key = '\0'){
    switch(command){
        case 'L':
            //커서를 왼쪽으로 한 칸 옮김
            if(pre[cursor] != -1) cursor = pre[cursor];
            break;
        case 'D':
            //커서를 오른쪽으로 한 칸 옮김
            if(nxt[cursor] != -1) cursor = nxt[cursor];
            break;
        case 'B':
            //커서 왼쪽 문자 삭제
            if(pre[cursor] == -1) break;
            nxt[pre[cursor]] = nxt[cursor];
            if(nxt[cursor]!=-1) pre[nxt[cursor]] = pre[cursor];
            cursor = pre[cursor];
            length--;
            break;//
        case 'P':
            //key를 커서 왼쪽에 추가
            pre[unused] = cursor;//asdfx
            nxt[unused] = nxt[cursor];
            dat[unused] = key;
            
            if(nxt[cursor] != -1) pre[nxt[cursor]] = unused;
            nxt[cursor] = unused;
            cursor = nxt[cursor];
            length++;
            unused++;
            break;
    }
// 커서 컨버터가 있어야함. 커서를 상수로 볼게 아니라 인덱스로 봐야하는구나나
}
int main(){
    int N = 0;
    char command;
    string K;
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    cin >> K >> N;
    stringLink(K);

    for(int i = 0; i<N; i++){
        cin >> command;
        if(command == 'P') {
            char key;
            cin >> key;
            process(command, key);
        }
        else process(command);

    }
    traverse();
}