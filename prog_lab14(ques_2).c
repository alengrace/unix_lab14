/**
 Ques-2 => Program on Child and Parent Process
 **************************************************************************************
 * +-------------------------------------------------------------+                    *
 * |                     FILE HEADER                             |                    *
 * +-------------------------------------------------------------+                    *
 *                                                                                    *
 * Program Statement:  Write a C program in UNIX platform to create a child process   *
 *					   using fork() system call and make the child process to compute *
 *                     the Factorial of a given number and make the parent process to *
 *                     compute the multiplication table of a given range.             *
 *                                                                                    *
 *                                                                                    *
 * Register No:        1947203                                                        *
 *                                                                                    *
 * @Author:             Alen Grace Skaria                                             *                                             
 **************************************************************************************
 **/
 

/***********************************Standard Header Files***********************************/
#include<unistd.h>   //for built in funciton fork() and exec()
#include<stdio.h>    //for standard input and output
#include<sys/wait.h> //for wait function
/*******************************************************************************************/

/***********************************Function Declaration************************************/
void child_factorial();
void parent_multiplication();
/*******************************************************************************************/

/**********************************Funciton Definition**************************************/

void child_factorial()
{
printf("\n[Child] Process \n");
int num,fact=1;
int i;
printf("\nEnter the n number to generate the factorial series: ");
scanf("%d",&num);
for(i=1;i<=num;i++)
{
fact*=i;
}
printf("Factorial of number executed by Child Process will be: %d",fact);
}


void parent_multiplication()
{
	int pro_table,num1,num2;
	int i,product;
	printf("\n[Parent] Process\n");
	printf("Enter the Mulpication Number: ");
	scanf("%d",&pro_table);
	printf("Enter the range [n n]: ");
	scanf("%d %d",&num1,&num2);
	printf("Multiplication in Range Specified by parent process");
	for(i=num1;i<=num2;i++)
	{
		product=pro_table*i;
		printf("\n%d * %d = %d",pro_table,i,product);
	}
}

/******************************************************************************************/
 //START OF MAIN
int main() 
{
int pid;
pid=fork();
if(pid == 0) //if pid returns 0,it means child process
{
wait(10); //wait funciton in order to execute the parent process
child_factorial(); //function call
}
else
{
	wait(10);  //wait funciton in order to execute the child process
	parent_multiplication();
}
//END OF MAIN
}
