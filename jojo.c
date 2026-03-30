#include<stdio.h>
int main()
{

    int x = 15;
    FILE *fptr = fopen("readme.txt","w");
    if(fptr!= NULL)
    {

        printf("Hehe hoise");
    }
    else
    {

        printf("Niqqa!");
    }

    fprintf(fptr, "%d", x);   //file e data store



    fclose(fptr);


}


//redme.txt

//15



#include<stdio.h>
int main()
{

    FILE *fptr = fopen ("read,e.txt","w");

    for(int i=1;i<=5;i++)
    {

        fprintf(fptr, "%d", i);
    }

    fclose(fptr);
    int x;
fptr = fopen("read,e.txt" ,"r");



        fscanf(fptr, "%d", &x);
        printf("%d", x);

}























