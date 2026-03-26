//1

#include<stdio.h>

int main()
{
    char name[30];
    int marks;
    char name1[30];
    int marks1;
    FILE *fptr1;
    FILE *fptr2;

    fptr1=fopen("readme.txt","w");

    for(int i=0;i<5;i++)
    {
        scanf("%s",name);
        getchar();
        scanf("%d",&marks);
        fprintf(fptr1,"\nName: %s\nMarks: %d",name,marks);


    }


    fclose(fptr1);

    fptr1=fopen("readme.txt","r");
    for(int i=0;i<5;i++)
    {
        getchar();
        fscanf(fptr1," Name:%s Marks:%d",name1,&marks1);
        printf("Name: %s\nMarks: %d\n",name1,marks1);
    }

}


//2

#include<stdio.h>
#include<stdlib.h>



struct student
{
    char name[30];
    int marks;
};

int main()
{
    struct student s1[2],s2[2];
    FILE *fptr1;
    fptr1=fopen("students.bin","wb");

    for(int i=0;i<2;i++)
    {
        fflush(stdin);
        printf("Enter Name: ");
        scanf("%s",s1[i].name);

        printf("Enter Marks: ");
        scanf("%d",&s1[i].marks);

    }

    fwrite(s1,sizeof(struct student),2,fptr1);

    fclose(fptr1);

    FILE *fptr2;
    fptr2=fopen("students.bin","wb");

    fread(s2,sizeof(s1),1,fptr2);


}




//3

#include<stdio.h>
#include<stdlib.h>



struct student
{
    char name[30];
    int marks;
};

int main()
{
    struct student s1[2],s2[2];
    FILE *fptr1;
    fptr1=fopen("students.bin","wb");

    for(int i=0;i<2;i++)
    {
        fflush(stdin);
        printf("Enter Name: ");
        scanf("%s",s1[i].name);

        printf("Enter Marks: ");
        scanf("%d",&s1[i].marks);

    }

    fwrite(s1,sizeof(struct student),2,fptr1);

    fclose(fptr1);

    FILE *fptr2;
    fptr2=fopen("students.bin","wb");

    fread(s2,sizeof(s1),1,fptr2);


}





