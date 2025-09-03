#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

const int NUMBER_STUDENTS = 2;
const int NUMBER_QUIZZES = 3;
void readScores(int (*scores)[NUMBER_QUIZZES]){
    for(int i = 0; i<NUMBER_STUDENTS; i++){
        for(int j = 0; j<NUMBER_QUIZZES; j++) cin >> scores[i][j];
    }
}
void display(int (*scores)[NUMBER_QUIZZES]){
    for(int i = 0; i<NUMBER_STUDENTS; i++){
        for(int j = 0; j<NUMBER_QUIZZES; j++) cout << scores[i][j] << '\t';
        cout << '\n';
    }
}
void display(float* score, const int index){
    for(int i = 0; i<index; i++) printf("%6f\t", score[i]);
    cout << '\n';
}
void computeStudentAverage(int (*scores)[NUMBER_QUIZZES], float* studentAverage){
    for(int i = 0; i<NUMBER_STUDENTS; i++){
        int sum = 0;
        for(int j = 0; j<NUMBER_QUIZZES; j++){
            sum += scores[i][j];
        }
        studentAverage[i] = sum/3.0;
    }
}
void computeQuizAverage(int (*scores)[NUMBER_QUIZZES], float* quizAverage){
    for(int i = 0; i<NUMBER_QUIZZES; i++){
        int sum = 0;
        for(int j = 0; j<NUMBER_STUDENTS; j++){
            sum += scores[j][i];
        }
        quizAverage[i] = sum/2.0;
    }
}
int main() {
	int scores[NUMBER_STUDENTS][NUMBER_QUIZZES];
	float studentAverage[NUMBER_STUDENTS];
	float quizAverage[NUMBER_QUIZZES];

	readScores(scores);

	printf("Student/Quiz Scores:\n");
	display(scores);

	computeStudentAverage(scores, studentAverage);
	printf("Student Average:\n");
	display(studentAverage, NUMBER_STUDENTS);

	computeQuizAverage(scores, quizAverage);
	printf("Quiz Average:\n");
	display(quizAverage, NUMBER_QUIZZES);
}
