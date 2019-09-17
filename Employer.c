//This is one of the First C programs that I ever wrote. This is also among the first peices of software that I have written in general.


#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>


//This is our template for our main pointer. It holds the date type for Employees
struct xrec {
char firstName[30];
char lastName[30];
char gender;
char SSN[12];
int age;
int worked;
int rate;
struct xrec *next; //otherwise his/her own SSN is stored
};
typedef struct xrec employee;


////Prototypes
void quit(employee * EmployeeAddress); //Function for Employee who quits
void showmarriage(employee *EmployeeAddress); //Function for Hanling Employees who are married
void highestsalary(employee * EmployeeAddress); //Function for Sorting, who has the highest pay
employee * deleteemployee(employee * EmployeeAddress);//Deleting employee memory handle
employee * AddEmployee(employee * EmployeeAddress, employee temp);//Temp Add Employee Handler
employee * tempemployee(employee * EmployeeAddress); //Temp employee  handler to generate linked list
int listemployees(employee *EmployeeAddress);// Employee count
int displaymenu(void); 
void listfemales(employee * EmployeeAddress);
void listovertime(employee * EmployeeAddress);
employee * alphabetize(employee * EmployeeAddress, int number);
void addmarriage(employee * EmployeeAddress);
void divorce(employee * EmployeeAddress);
void ImAFunction(int function);

//Main, this is generally Just a looping function.
int main(void){
FILE * infile;//This is a pointer (Address) for the file.\
			  //The Pointer might be null or not null (ie, Ex90029)

int menu; int LengthHolder; int number=0;
employee temp;
employee *EmployeeAddress=NULL;

infile=fopen("EmployeeFile.txt","r");
if(infile==NULL)
{ printf(" File not found\n");
exit(0);}
//c++ version: cin>> ;
//c version: scanf();

//c++ version(file): ?
//c version(file): fscanf()

while(fscanf(infile,"%s %s %c %s %d %d %d %s", temp.firstName, temp.lastName, &temp.gender,
temp.SSN, &temp.age, &temp.worked, &temp.rate, temp.marriage)!=EOF)
 {
   LengthHolder=strlen(temp.firstName);//Get the length of current string processed in loop.
temp.firstName[LengthHolder+1]='\0';
LengthHolder=strlen(temp.lastName);
temp.lastName[LengthHolder+1]='\0';
temp.SSN[11]='\0';
temp.marriage[11]='\0';
EmployeeAddress=AddEmployee(EmployeeAddress, temp);
number++;
 }
fclose(infile); //similar to 


do {
menu=displaymenu();
//Interactions with user will occur here. 
switch (menu){
case 1: listemployees(EmployeeAddress); break;   //Press one to list all employees            
case 2: EmployeeAddress=tempemployee(EmployeeAddress); number++; break; //Press two to add new employee
case 3: EmployeeAddress=deleteemployee(EmployeeAddress); number--; break;//Press two to delete employee
case 4: listfemales(EmployeeAddress); break; //Sort females
case 5: listovertime(EmployeeAddress); break; //Sort overtime
case 6: EmployeeAddress=alphabetize(EmployeeAddress, number); break;//list in alphabetical order
case 7: highestsalary(EmployeeAddress); break;//Locate highest salary
case 11: quit(EmployeeAddress); break;//Exit program/Empty memory    
default: printf("Bad input\n");}
}
while (menu!=11);

system("pause");


return 0;
}


employee * AddEmployee(employee * EmployeeAddress, employee temp){
employee * new;

new=malloc(sizeof(employee));
(*new)=temp;
new->next=EmployeeAddress;

return new;
}

//Just a general list for visuallizoing employee tracker
int displaymenu(void){
int c;

printf(".._________________________________________..  \n");
printf("| 1. List of all employees with salary     |  \n");
printf("| 2. Add an employee to payroll            |  \n");
printf("| 3. Delete an employee from payroll       |  \n");
printf("| 4. List all female employees             |  \n");
printf("| 5. List all employees with overtime      |  \n");
printf("| 6. Alphabetize the list of employees     |  \n");
printf("| 7. Who gets the highest salary?          |  \n");
printf("| 8. Add a marriage                        |  \n");
printf("| 9. Divorce two people                    |  \n");
printf("| 10. Show marriges                        |  \n");
printf("| 11. Quit and save                        |  \n");
printf(".._________________________________________..\n");
fflush(stdin);
printf("Your choice:");
scanf("%d",&c);
 return c;
}


int listemployees(employee *EmployeeAddress){


while (EmployeeAddress!=NULL){
printf("%s %s %c %s %d %d %d\n", EmployeeAddress->firstName, EmployeeAddress->lastName, EmployeeAddress->gender,
EmployeeAddress->SSN, EmployeeAddress->age, EmployeeAddress->worked, EmployeeAddress->rate);
EmployeeAddress=EmployeeAddress->next;
}
return 0;
}

//List Of Increment/Decrement employee functions
employee * tempemployee(employee * EmployeeAddress){
employee temp;

fflush(stdin);
printf("firstName name: ");
gets(temp.firstName);
fflush(stdin);
printf("lastName name: ");
gets(temp.lastName);
fflush(stdin);
printf("Gender: ");
scanf("%c", &temp.gender);
fflush(stdin);
printf("SSN: ");
gets(temp.SSN);
printf("Age: ");
scanf("%d", &temp.age);
printf("Hours worked: ");
scanf("%d", &temp.worked);
printf("Rate: ");
scanf("%d", &temp.rate);
//strcpy(temp.marriage, temp.SSN);
EmployeeAddress=AddEmployee(EmployeeAddress, temp);

return EmployeeAddress;}



employee * deleteemployee(employee *EmployeeAddress){
char social[12];
employee * one;
employee * two;
employee * three;
one=EmployeeAddress;
two=EmployeeAddress;
three=EmployeeAddress;
fflush(stdin);
printf("Social security of person you want to remove from payroll: ");
gets(social);

while((strcmp(one->SSN, social))!=0){
if (two!=one)
two=two->next;
one=one->next;
}



if (strcmp(one->SSN,one->marriage)!=0){
while (three!=0){
if (strcmp(one->marriage,three->SSN)==0){
strcpy(three->marriage,three->SSN);
break;}
three=three->next;}
}


if (one==EmployeeAddress)
EmployeeAddress=EmployeeAddress->next;

else
two->next=one->next;

free(one);
return EmployeeAddress;
}





//List of Void Functions
void listfemales(employee * EmployeeAddress){

while (EmployeeAddress!=NULL){
if (EmployeeAddress->gender=='F'){
printf("%s %s %c %s %d %d %d\n", EmployeeAddress->firstName, EmployeeAddress->lastName, EmployeeAddress->gender,
EmployeeAddress->SSN, EmployeeAddress->age, EmployeeAddress->worked, EmployeeAddress->rate);
}
EmployeeAddress=EmployeeAddress->next;
}

}

void listovertime(employee * EmployeeAddress){

while (EmployeeAddress!=NULL){
if (EmployeeAddress->worked>40){
printf("%s %s %c %s %d %d %d\n", EmployeeAddress->firstName, EmployeeAddress->lastName, EmployeeAddress->gender,
EmployeeAddress->SSN, EmployeeAddress->age, EmployeeAddress->worked, EmployeeAddress->rate);
}
EmployeeAddress=EmployeeAddress->next;
}

}


employee * alphabetize(employee * EmployeeAddress, int number){
employee * one;
employee * two;
employee * three;
employee * four;
int i;


for (i=0; i<number;i++){
two=EmployeeAddress;
one=two->next;
three=EmployeeAddress;
while (one!=NULL){
if (one->lastName[0]<two->lastName[0]){
if (two==EmployeeAddress){
three=one;
EmployeeAddress=one;}
two->next=one->next;
one->next=two;
four=one;
one=two;
two=four;
if (three!=two)
three->next=two;
}
two=two->next;
one=one->next;
if (three->next!=two )
three=three->next;

}}

return EmployeeAddress; }

void highestsalary(employee * EmployeeAddress){
employee * adress;
double highest=0; double temp;

while (EmployeeAddress!=NULL){
if (EmployeeAddress->worked >40)
temp=(((EmployeeAddress->worked)-40)*(EmployeeAddress->rate)*1.5+40*(EmployeeAddress->rate));
else
temp=(EmployeeAddress->worked)*(EmployeeAddress->rate);

if (temp>highest){
highest=temp;
adress=EmployeeAddress;}

EmployeeAddress=EmployeeAddress->next;
}
printf("%s %s %s has highest salary with $%5.2f\n", adress->firstName, adress->lastName, adress->SSN, highest);
}




void quit(employee * EmployeeAddress){
FILE * outfile;

outfile=fopen("result.txt", "w");

while (EmployeeAddress!=0){
fprintf(outfile, "%s %s %c %s %d %d %d %s\n", EmployeeAddress->firstName, EmployeeAddress->lastName, EmployeeAddress->gender, EmployeeAddress->SSN,
EmployeeAddress->age, EmployeeAddress->worked, EmployeeAddress->rate, EmployeeAddress->marriage);
EmployeeAddress=EmployeeAddress->next;}

fclose(outfile);
}

