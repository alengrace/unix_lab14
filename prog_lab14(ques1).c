/**
 * Ques-1=> Create Multiple Process
 **************************************************************************************
 *           +-------------------------------------------------------------+          *
 *           |                     FILE HEADER                             |          *
 *           +-------------------------------------------------------------+          *
 *                                                                                    *
 * Program Statement: Write a program that creates four processes.The original        *
 *                    process creates two children processes and then prints out      *
 *                    “parent”. The children process print “child1” and “child2”      *
 *                    respectively. The second child process creates a child process  *
 *                    that prints out “grandchild”. Each process should print out its *
 *                    process id and the process id of its parent                     *
 *                                                                                    *
 *                                                                                    *
 * Register N0:      1947203                                                          *
 *                                                                                    *
 *@Author:           Alen Grace Skaria                                                *                                             
 **************************************************************************************
 **/
   

/***********************************Standard Header Files***********************************/
#include<unistd.h>  //for built in funciton fork() and exec()
#include<stdio.h>   //for standard input and output
#include<stdlib.h>  //for exit(0)
/******************************************************************************************/

int main()
{
 int pid, pid2;
 printf ("\nI'm the original process with PID %d and PPID %d.\n\n",getpid (),getppid ());
 pid = fork ();						
 if (pid != 0) 					   
   {
     printf ("I'm the parent process with PID %d and PPID %d.\n",getpid (), getppid ());
     printf ("My child's PID is %d\n", pid);
   }
 else 					
   {
     printf ("I'm the child process with PID %d and PPID %d.\n",getpid(), getppid());
     pid2= fork(); 		
     printf ("I'm the child's child with PID %d and PPID %d.\n",getpid(), getppid());    
   }
 printf ("PID %d terminates.\n", getpid());
 return 0;
}
