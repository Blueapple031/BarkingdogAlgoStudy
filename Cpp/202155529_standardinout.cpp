#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

char printGrade(int score){
    if(score>=90) return 'A';
    else if(score>=80) return 'B';
    else if(score>=70) return 'C';
    else if(score>=60) return 'D';
    else return 'F';
}
int totalScore(int* scores,int count){
    int sum = 0;
    for(int i = 0; i<count; i++){
        sum += scores[i];
    }
    return sum;
}
double averageScore(int sum, int count){
    double average = 0;
    average = sum/(double)count;
    return average;
} 

int main(){
    string name;
    int count = 0;
    int scores[100] = {};
    do {
        cout << "Enter a name and score: "; 
        cin >> name >> scores[count];
        //score 오류시 탈출~
        if(!(scores[count]<=100&&scores[count]>=0)){
            scores[count] = 0;
            break;
        }
        cout << "Hi " << name << "! Your grade is "<< printGrade(scores[count])<<'\n';
        count++;
    } while(true);

    cout << "Bye " << name << "\n\n";
    cout << "Score Count: " << count << '\n';
    cout << "Total Score: " << totalScore(scores,count) << '\n';
    cout << "Score Average: " << fixed << setprecision(2) << averageScore(totalScore(scores,count),count);
}