#ifndef PERSOANE_H_INCLUDED
#define PERSOANE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum{
    False,True
}boolean;

typedef struct {
    char name [255];
    char surname[255];
}Person;
typedef struct{
    Person pers;
    char phone_nr[30];
    int height;
    int age;
    int weight;
}Data;

typedef struct{
    char breakfast[255];
    char lunch[255];
    char dinner[255];
}OneDayMenu;
typedef struct{
    OneDayMenu day[7];
    char bmi[255];
}BmiMenu;

typedef struct{
    BmiMenu bmiMenuStructure;
    Data dateStructure;
}PersonDiet;

void readFromFile(char filename[],int *index,Data* dateStructure);
void printing(Data *dateStructure,int *index);
void badName(Data *dateStructure,int *indexStruct,int badNameIndex[],int *length);
void badSurname(Data *dateStructure,int *indexStruct,int badPrenumeIndex[],int *length);
void badPhone(Data *dateStructure,int *indexStruct,int badPhoneIndex[],int *length);
boolean wordValidation(char name[]);
boolean phoneValidation(char phone[]);
void deleteStructureFromVector(Data *dateStructure,int badNameIndex,int *lungimeDate);
double bmi(Data dateStructure);
void sortare(Data *dateStructure,int *indexStruct);
void printBmiMenu(BmiMenu bmiMenuStructure,int *index);
void readFromCsv(char filename[],int *index,BmiMenu* bmiMenuStructure);
void splitBmi(BmiMenu bmiMenuStructure,double split[]);
boolean bmiConvert(BmiMenu bmiMenuStructure,double *bmi);
void printPersonDiet(PersonDiet personDietStructure);
void addToPersonDiet(BmiMenu *bmiMenuStructure,Data *dateStructure,PersonDiet *personDietStructure,int *lengthOfPersonDiet,int *lungimeDate,int *lungimeMeniu);
void writeToFile(PersonDiet *personDietStructure,int *lengthOfPersonDiet,char outputFilePath[]);


#endif // PERSOANE_H_INCLUDED
