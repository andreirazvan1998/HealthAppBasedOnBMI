#ifndef PERSOANE_C_INCLUDED
#define PERSOANE_C_INCLUDED
#include "persoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFromFile(char filename[],int *index,Data* dateStructure){

      char textFromFile[1300];
      char lineFromTextFile[1300][1300];
      char *pointerForTextFromFile;
      pointerForTextFromFile=textFromFile;
      FILE* file=fopen(filename,"r");

      if (file == NULL){
            printf("Could not open file ");  //these lines declare a File type object that takes as parameter a given filename and we verify if the path is correct
        }
      int lineCounter=0;
      while(fgets(pointerForTextFromFile,1000,file)!=NULL){ //in this section we read the file content using while loop and fgets() function and copy every line of the file in
           char proposition[255];    //proposition cointain the plain text from the file
           int indexPropozitie=0;
           while(*pointerForTextFromFile!=NULL)
           {                                                // the lineFormTextFile array.
               proposition[indexPropozitie]=*pointerForTextFromFile;
               pointerForTextFromFile++;
               indexPropozitie++;
           }
           proposition[indexPropozitie]='\0';
           for(int indexLinie=0;indexLinie<strlen(proposition);indexLinie++)
           {
               lineFromTextFile[lineCounter][indexLinie]=proposition[indexLinie];
           }
           lineCounter++;
      }
            int indexStruct=0;
            for(int indexLinieText=1;indexLinieText<lineCounter;indexLinieText++){  //in this section we parse the lineFromTextFile array and we split every data by coma
                 char *pointerForStructureDate;                                      //using strtok, and then we add the data to the stucture (without the first line wich is the header)
                 char strVarsta[255];
                 int lStrVarsta=0;
                 pointerForStructureDate=strtok(lineFromTextFile[indexLinieText],",");
                 sscanf(pointerForStructureDate,"%s",dateStructure[indexStruct].pers.name);
                 pointerForStructureDate=strtok(NULL,",");
                 sscanf(pointerForStructureDate,"%s",dateStructure[indexStruct].pers.surname);
                 pointerForStructureDate=strtok(NULL,",");
                 sscanf(pointerForStructureDate,"%s",dateStructure[indexStruct].phone_nr);
                 pointerForStructureDate=strtok(NULL,",");
                 strcpy(strVarsta,pointerForStructureDate);
                 dateStructure[indexStruct].age=atoi(strVarsta);  //atoi convert the age from string to int
                 pointerForStructureDate=strtok(NULL,",");
                 strcpy(strVarsta,pointerForStructureDate);
                 dateStructure[indexStruct].height=atoi(strVarsta);
                 pointerForStructureDate=strtok(NULL,",");
                 strcpy(strVarsta,pointerForStructureDate);
                 dateStructure[indexStruct].weight=atoi(strVarsta);
                 pointerForStructureDate=strtok(NULL,",");


                indexStruct++;
            }

            *index=indexStruct; //we send the length of Date structure array using pointer

            fclose(file);
}

 void copystr(char *dest,char *src)
{
    while(*src!='\0')      //this function copy a given string to a destination string
    *dest++=*src++;
    *dest='\0';
    return;
}

void readFromCsv(char file[],int *index,BmiMenu* bmiMenuStructure){

    char textFromFile[1000];
    char lineFromTextFile[255][255];
    char *pointerForTextFromFil;
     pointerForTextFromFil=textFromFile;

    FILE* f=fopen(file,"r");                                 //these lines declare a File type object that takes as parameter a given filename and we verify if the path is correct
    if (f == NULL){
            printf("Could not open file ");
        }
    int lineCounter=0;
    while(fgets( pointerForTextFromFil,1000,f)!=NULL){
            //printf("%s",textFromFile);
            char proposition[1000];                         //proposition cointain the plain text from the file
            int indexPropozitie=0;
            while(*pointerForTextFromFil!=NULL){
                proposition[indexPropozitie]=* pointerForTextFromFil;
                 pointerForTextFromFil++;
                indexPropozitie++;                        //in this section we read the file content using while loop and fgets() function and copy every line of the file in
                                                          // the lineFormTextFile array.
            }
            proposition[indexPropozitie]='\0';
           // printf("%s",proposition);

            for(int pozitieLinie=0;pozitieLinie<strlen(proposition);pozitieLinie++){
                lineFromTextFile[lineCounter][pozitieLinie]=proposition[pozitieLinie];
                //strcpy(lineFromTextFile[lineCounter][l],proposition[l]);
            }
        lineCounter++;
    }

    int indexStruct=0;

    //char dublu[255][255];
    for(int iterator=0;iterator<lineCounter;iterator++){   // here we take the first line wich is the line with bmi ranges and we split them by coma and store them in bmiMenuStructure
        char lineWithBmiCoefficient[255]="";
        strcpy(lineWithBmiCoefficient,lineFromTextFile[iterator]);
        char *pointerForBmi;
        if(iterator==0){
            pointerForBmi=strtok(lineWithBmiCoefficient,",");
            while(pointerForBmi!=NULL){
                pointerForBmi=strtok(NULL,",");
                if(pointerForBmi!=NULL){
                    copystr(bmiMenuStructure[indexStruct].bmi, pointerForBmi);
                indexStruct++;
                }
            }
        }
    }


 /*
    int countForComa=0;
    char *pointerForComa;
    pointerForComa=strchr(lineFromTextFile[1],',');
    while(pointerForComa!=NULL){
       countForComa++;
        pointerForComa=strchr(pointerForComa+1,',');
    }*/

    char lines[50][50][100];
    int rowForLines=0;
    int columnForLines=0;

    for(int lineIndex=1;lineIndex<lineCounter;lineIndex++,rowForLines++){ //in this section we take the menu contents by days
        int ind=0;
        char empty[10][255]={"",""};
        char tempStringForLine[255]="";
        strcpy(tempStringForLine,lineFromTextFile[lineIndex]);
        char *pointerForLine;
        pointerForLine=strtok(tempStringForLine,",");

        while(pointerForLine!= NULL){
            pointerForLine=strtok(NULL,",");
            if(pointerForLine!=NULL){
                copystr(empty[ind],pointerForLine);
                //printf("%s\n",empty[ind]);
                //sprintf(lines[rowForLines][columnForLines],"%s",pointerForLine);
            ind++;}
        }
        columnForLines=0;
        for(int indexEmptyElement=0;indexEmptyElement<ind;indexEmptyElement++,columnForLines++ ){
            copystr(lines[rowForLines][columnForLines],empty[indexEmptyElement]);
        }
    }

    for(int structure=0,column=0;column<2;structure++,column++){    //in this section we add the info from lines in bmiMenuStructure
         for(int row=0,dayIndex=0;row<7;row++,dayIndex++){
               // printf("%s\n",lines[row][column]);
                char *pointerForLines;
                pointerForLines=strtok(lines[row][column],";");
                copystr(bmiMenuStructure[structure].day[dayIndex].breakfast,pointerForLines);
                pointerForLines=strtok(NULL,";");
                copystr(bmiMenuStructure[structure].day[dayIndex].lunch,pointerForLines);
                pointerForLines=strtok(NULL,";");
                copystr(bmiMenuStructure[structure].day[dayIndex].dinner,pointerForLines);
         }
    }
    *index=indexStruct;
}


void printBmiMenu(BmiMenu bmiMenuStructure,int *index){
    printf("%s\n",bmiMenuStructure.bmi);                  //this function print the bmiMenu structure
    for(int iterator=0;iterator<*index;iterator++){
        printf("%s %s %s \n",bmiMenuStructure.day[iterator].breakfast,bmiMenuStructure.day[iterator].lunch,bmiMenuStructure.day[iterator].dinner);
    }
}


void printing(Data *dateStructure,int *indexStruct){

    for(int iterator=0;iterator<*indexStruct;iterator++){  //this funtion print the Data structure
            printf("%s %s %s %d %d %d \n",dateStructure[iterator].pers.name,dateStructure[iterator].pers.surname,dateStructure[iterator].phone_nr,dateStructure[iterator].age,dateStructure[iterator].height,dateStructure[iterator].weight);
    }
}

boolean wordValidation(char name[]){
    boolean validName=True;            //this function take a word as parameter and verify if it starts with an uppercase letter and if the word cointain eny digits
    if(name[0]>='A' && name[0]<='Z')   // if the word contain digit and it want start with a uppercase letter function will return false;
        validName=validName&True;
    else
        validName=validName&False;
    for(int i=1;name[i]!='\0';i++){
        if(name[i]>='0' && name[i]<='9' ){
            validName=validName&False;
            break;
        }
    }
    return validName;
}

boolean phoneValidation(char tel[]){
    boolean validPhone=True;                 //this function take a phone nr as parameter and verify if is the proper length and if the word doesn't contain ent letter
    if(strlen(tel)>10 || strlen(tel)<10){
        validPhone=False;
    }
    for(int i=1;tel[i]!='\0';i++){
        if(tel[i]<'0' || tel[i]>'9' ){
            validPhone=False;
        }
    }
    return validPhone;
}



void badName(Data *dateStructure,int *indexStruct,int badNameIndex[],int *length){
    int index=0;                                                        //this function verify if the name is in the proper format otherwise  add the line index in the badNameIndex array
    for(int iterator=0;iterator<*indexStruct;iterator++){
        if(wordValidation(dateStructure[iterator].pers.name)==False ){
            badNameIndex[index++]=iterator;
        }
    }
    *length=index;
}

void badSurname(Data *dateStructure,int *indexStruct,int badSurnameIndex[],int *length){
    int index=0;                                                         //this function verify if the surname is in the proper format otherwise  add the line index in the badSurnameIndex array
    for(int iterator=0;iterator<*indexStruct;iterator++){
        if(wordValidation(dateStructure[iterator].pers.surname)==False){
            badSurnameIndex[index++]=iterator;
        }
    }
    *length=index;
}

void badPhone(Data *dateStructure,int *indexStruct,int badPhoneIndex[],int *length){
    int index=0;                                                        //this function verify if the phone nr is in the proper format otherwise add the line index in the badPhoneIndex array
    for(int iterator=0;iterator<*indexStruct;iterator++){
        if(phoneValidation(dateStructure[iterator].phone_nr)==False){
            badPhoneIndex[index++]=iterator;
            //printf("%d",iterator);
        }
  }
    *length=index;
}

void deleteStructureFromVector(Data *dateStructure,int badNameIndex,int *lungimeStructura){
    int iterator;                                                       //this function delete a given line form structure
    for(iterator=badNameIndex;iterator<*lungimeStructura;iterator++){
            dateStructure[iterator]=dateStructure[iterator+1];
    }
    *lungimeStructura-=1;
}

double bmi(Data dateStructure){
    return (double)dateStructure.weight/((dateStructure.height*dateStructure.height)/10000.0);  //this function calculate the bmi of a person
}

void sortare(Data *dateStructure,int *indexStruct){
    boolean sort=False;                                         //this function use bubblesort algorthm to sort the persons in Data structure
    while(sort==False){
        sort=True;
        for(int i=0;i<*indexStruct-1;i++){
            if(bmi(dateStructure[i])>bmi(dateStructure[i+1])){
                Data aux=dateStructure[i];
                dateStructure[i]=dateStructure[i+1];
                dateStructure[i+1]=aux;
                sort=False;
            }
        }
    }
}

void splitBmi(BmiMenu bmiMenuStructure,double split[]){
    char bmiInterval[50];                               //this function take a bmi interval from the bmiMenuStructure and split it(ex interval is "12.5 and 20") this function
    char *pointerForBmi;                                //will split that in 12.5 and 20 and will store these values in split array.
    char firstNr[30];
    char secondNr[30];
    char *pointerForStrtod;
    strcpy(bmiInterval,bmiMenuStructure.bmi);
    pointerForBmi=strtok(bmiInterval,"-");
    copystr(firstNr,pointerForBmi);
    double min=strtod(firstNr,&pointerForStrtod);
    split[0]=min;
    pointerForBmi=strtok(NULL," ");
    copystr(secondNr,pointerForBmi);
    double max=strtod(secondNr,&pointerForStrtod);
    split[1]=max;
}

boolean bmiConvert(BmiMenu bmiMenuStructure,double *bmi){
    boolean valid=False;                                //this function verify in wich bmi range is a given person's bmi
    double bmiValues[2];
    splitBmi(bmiMenuStructure,bmiValues);
    if((bmiValues[0]<=*bmi)&&(bmiValues[1]>=*bmi)){
             valid=True;
    }
    return valid;
}

void addToPersonDiet(BmiMenu *bmiMenuStructure,Data *dateStructure,PersonDiet *personDietStructure,int *lengthOfPersonDiet,int *lungimeDate,int *lungimeMeniu){
    int dietStructureIndex=0;                                                        // this function will asign a diet to a person by their bmi
    for(int dateStructureIndex=0;dateStructureIndex<*lungimeDate;dateStructureIndex++){
              double bmiPersoana=bmi(dateStructure[dateStructureIndex]);
           // printf("%f\n",bmiPersoana);
        for(int personDietIndex=0;personDietIndex<*lungimeMeniu;personDietIndex++){
            if(bmiConvert(bmiMenuStructure[personDietIndex],&bmiPersoana)==True){
                personDietStructure[dietStructureIndex].dateStructure=dateStructure[dateStructureIndex];
                personDietStructure[dietStructureIndex].bmiMenuStructure=bmiMenuStructure[personDietIndex];
                dietStructureIndex++;
            }
        }
    }
    *lengthOfPersonDiet=dietStructureIndex;
}

void printPersonDiet(PersonDiet personDietStructure){          //this funtion will print a person information and their diet
    printf("name: %s \n",personDietStructure.dateStructure.pers.name);
    printf("surname: %s \n",personDietStructure.dateStructure.pers.surname);
    printf("weight: %d \n",personDietStructure.dateStructure.weight);
    printf("height: %d\n",personDietStructure.dateStructure.height);
    printf("phone_nr: %s\n",personDietStructure.dateStructure.phone_nr);
    printf("age: %d\n",personDietStructure.dateStructure.age);
    printf("person bmi: %lf \n",bmi(personDietStructure.dateStructure));
    printf("bmi range is: %s \n",personDietStructure.bmiMenuStructure.bmi);
    for(int iterator=0;iterator<7;iterator++){
        printf("%s %s %s \n",personDietStructure.bmiMenuStructure.day[iterator].breakfast, personDietStructure.bmiMenuStructure.day[iterator].lunch, personDietStructure.bmiMenuStructure.day[iterator].dinner);
    }
     printf(" ---------------------------------------------------------------------------------------------------------\n");
}
void writeToFile(PersonDiet *personDietStructure,int *lengthOfPersonDiet,char outputFilePath[]){

   FILE *fptr;                                                                                        // this function will write in a file  a person information and their diet
   fptr = fopen(outputFilePath,"w");                                                                  //for that we use the fopen() function
   char zile[7][255]={"luni","marti","miercuri","joi","vineri","sambata","duminica"};
   for(int iteratorStruct=0;iteratorStruct<*lengthOfPersonDiet;iteratorStruct++){
        printPersonDiet(personDietStructure[iteratorStruct]);
        fprintf(fptr,"NUME \t PRENUME \t GREUTATE\t INALTIME\t TELEFON\t VARSTA\t  BMI\t \n");
        fprintf(fptr,"%s \t",personDietStructure[iteratorStruct].dateStructure.pers.name);
        fprintf(fptr," %s \t",personDietStructure[iteratorStruct].dateStructure.pers.surname);
        fprintf(fptr," %5d \t",personDietStructure[iteratorStruct].dateStructure.weight);
        fprintf(fptr," %13d \t",personDietStructure[iteratorStruct].dateStructure.height);
        fprintf(fptr," %17s \t",personDietStructure[iteratorStruct].dateStructure.phone_nr);
        fprintf(fptr," %5d \t",personDietStructure[iteratorStruct].dateStructure.age);
        fprintf(fptr," %5lf \t\n",bmi(personDietStructure[iteratorStruct].dateStructure));
        fprintf(fptr,"\n");
        for(int iteratorZile=0;iteratorZile<7;iteratorZile++){
            fprintf(fptr,"%s %s %s %s \n",zile[iteratorZile],personDietStructure[iteratorStruct].bmiMenuStructure.day[iteratorZile].breakfast, personDietStructure[iteratorStruct].bmiMenuStructure.day[iteratorZile].lunch, personDietStructure[iteratorStruct].bmiMenuStructure.day[iteratorZile].dinner);
        }
        fprintf(fptr," ---------------------------------------------------------------------------------------------------------\n");
   }


 fclose(fptr);

}



#endif // PERSOANE_C_INCLUDED !NU STERGE!
