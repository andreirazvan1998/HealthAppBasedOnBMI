#include "persoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filename "C:\\Users\\ASUS\\Documents\\GestiunePersoane\\date.csv"
#define excel "C:\\Users\\ASUS\\Documents\\GestiunePersoane\\bmi2.csv"
#define outputFile"C:\\Users\\ASUS\\Documents\\GestiunePersoane\\output.csv"

int main()
{
    // boolean b=verificareCuvant("Maria");
    int dateLength;
    int lengthOfWrongNameVector;
    int lengthOfWrongSurnameVector;
    int lengthOfWrongPhoneVector;
    int lenghtOfCsv;
    int lengthOfPersonDiet;
    Data dateStructure[30];
    BmiMenu bm[30];
    PersonDiet dp[30];
    int badNameIndex[255];
    int badSurnameIndex[255];
    int badPhoneIndex[255];
    double bmiSplit[2];
    readFromFile(filename,&dateLength,dateStructure);


    //printing(dateStructure,&dateLength);

    //printf("-------AFTER BED NUME---------\n");
    badName(dateStructure,&dateLength,badNameIndex,&lengthOfWrongNameVector);
    for(int i=0;i<lengthOfWrongNameVector;i++){
        deleteStructureFromVector(dateStructure,badNameIndex[i]-i,&dateLength);
    }
    //printing(dateStructure,&dateLength);

    //printf("------AFTER BED SURNAME-----------\n");
    badSurname(dateStructure,&dateLength,badSurnameIndex,&lengthOfWrongSurnameVector);
    for(int i=0;i<lengthOfWrongSurnameVector;i++){
        deleteStructureFromVector(dateStructure,badSurnameIndex[i]-i,&dateLength);
    }
   // printing(dateStructure,&dateLength);

    //printf("------AFTER BED PHONE-----------\n");
    /*
    boolean b=phoneValidation("0763773920");
    printf("%s",b? "True":"False");*/

    badPhone(dateStructure,&dateLength,badPhoneIndex,&lengthOfWrongPhoneVector);
    for(int i=0;i<lengthOfWrongPhoneVector;i++){
        deleteStructureFromVector(dateStructure,badPhoneIndex[i]-i,&dateLength);
    }
    //printing(dateStructure,&dateLength);

   // printf("------AFTER sort-----------\n");
    sortare(dateStructure,&dateLength);
   // printing(dateStructure,&dateLength);
      for(int i=0;i<dateLength;i++){
        //printf("%lf \n",bmi(dateStructure[i]));
    }

    //printf("------FROM CSV-----------\n");

    readFromCsv(excel,&lenghtOfCsv,bm);
    //printBmiMenu(bm[1],&lenghtOfCsv);

   // printf("------BMI SPLIT-----------\n");

    /*
    splitBmi(bm[0],bmiSplit);
    double l=12;
    boolean r=bmiConvert(bm[1],&l);
    printf("%s",r? "True":"False")
    */

    addToPersonDiet(bm,dateStructure,dp,&lengthOfPersonDiet,&dateLength,&lenghtOfCsv);


   // printPersonDiet(PersonDiet dp[0]);
    writeToFile(dp,&lengthOfPersonDiet,outputFile);




}

