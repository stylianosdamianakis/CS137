#include <stdio.h>

int grades(){

    int quizGrade, assignmentGrade, midtermGrade, requiredFinalExamGrade;

    scanf("%d %d %d", &quizGrade, &assignmentGrade, &midtermGrade);

    //get the minimum required exam grade based on standard grade calculation requirements
    requiredFinalExamGrade = (int)((50 - (0.05*quizGrade + 0.2*assignmentGrade + 0.3*midtermGrade))/0.45);

    //get the minimum required exam grade based on weighted exam average requirements, and select the larger requirement
    requiredFinalExamGrade = (requiredFinalExamGrade < (int)((37.5 - 0.3*midtermGrade)/0.45)?(int)((37.5 - 0.3*midtermGrade)/0.45):requiredFinalExamGrade);

    printf("%d", requiredFinalExamGrade);

    return 0;
}