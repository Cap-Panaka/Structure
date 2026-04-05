/*Write a C program to manage student records using file operations.
Tasks:
Define a structure named student with the following members:
name (string)
dept (string)
cgpa (double)
Take an integer input n representing the number of students.
Create an array of structures to store information of n students.
Input the following details for each student from the user:
Name
Department
CGPA
Open a file named "student.txt" in write mode and store all student data into the file.
Display all student information on the console after taking input.
Reopen the file in read mode and read the stored data into another structure array.
Display the data read from the file.
Handle file opening errors properly. */

#include<stdio.h>
#include<stdlib.h>

struct student
{

    char name[30];
    char dept[30];
    double cgpa;

};

int main()
{

    int n;
    printf("# of student: ");
    scanf("%d", &n);

    struct student s[n],s1[n];

    FILE *fptr;
    fptr = fopen("student.txt","w");

    if(fptr==NULL)
    {
        printf("sussy");
        return 1;
    }

        for(int i=0;i<n;i++)
        {

            printf("\nName: ");
            scanf("%s",s[i].name);
            printf("\nDept: ");
            scanf(" %s",s[i].dept);
            printf("\nCGPA : ");
            scanf("%lf", &s[i].cgpa);
            fprintf(fptr,"%s %s %.2lf\n",s[i].name, s[i].dept, s[i].cgpa);

        }

        for(int i=0;i<n;i++)
        {
            printf("\nName: %s\nDepartment: %s\nCGPA: %.2lf\n",s[i].name,s[i].dept,s[i].cgpa);


        }
        fclose(fptr);

        fptr = fopen("student.txt","r");
        if(fptr == NULL)
        {
            printf("Sussy!");
            return 1;
        }

        for(int i=0;i<n;i++)
        {

            fscanf(fptr,"%s %s %lf",s1[i].name,s1[i].dept, &s1[i].cgpa);
            printf("\nName: %s\nDepartment: %s\nCGPA: %.2lf\n",s1[i].name,s1[i].dept,s1[i].cgpa);
        }
        fclose(fptr);


}


/*Define a structure student with:
name (string)
dept (string)
cgpa (double)
Input an integer n (number of students).
Take input for n students.
Open a file named "student.bin" in write binary mode (wb) and store all student records using fwrite().
Display the entered student information.
Reopen the file in read binary mode (rb) and read the data into another array using fread().
Display the data read from the file.
Handle file errors properly.*/

#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[30];
    char dept[20];
    double cgpa;
};

int main()
{
    int n;

    printf("Number of students: ");
    scanf("%d", &n);

    struct student s[n], s1[n];
    FILE *f;
    f = fopen("student.bin", "wb");
    if(f == NULL)
    {
        printf("File error!\n");
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i+1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Department: ");
        scanf("%s", s[i].dept);

        printf("CGPA: ");
        scanf("%lf", &s[i].cgpa);

        fwrite(&s[i], sizeof(struct student), 1, f);
    }
    fclose(f);
    printf("\n--- Entered Data ---\n");
    for(int i = 0; i < n; i++)
    {
        printf("\nName: %s\nDepartment: %s\nCGPA: %.2lf\n",
               s[i].name, s[i].dept, s[i].cgpa);
    }

    f = fopen("student.bin", "rb");
    if(f == NULL)
    {
        printf("File error!\n");
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        fread(&s1[i], sizeof(struct student), 1, f);
    }

    fclose(f);
    printf("\n--- Data From File ---\n");
    for(int i = 0; i < n; i++)
    {
        printf("\nName: %s\nDepartment: %s\nCGPA: %.2lf\n",
               s1[i].name, s1[i].dept, s1[i].cgpa);
    }

    return 0;
}




