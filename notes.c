#include<stdio.h>
#include<string.h> //functions used to handle the  strings are defined in this headerfile
#include<conio.h>

void add();
void delet();
void update();
void delet();
void printlist();
void stitle();
void read();

int main()
{
    int ch;
    unsigned flag=0;
    while(1)
    {
        if(flag==0)
        {
            printf("######********######********######-WELCOME-######********######********######********######");
            printf("\n\n\t\t\t\t\t\t WELCOME!");
        }

        printf("\n what you want to do?\n\t");
        printf("\n\n        1, add new record                  2, update previous records");
        printf("\n\n        3, delete record from library      4, check list of all files");
        printf("\n\n        5, read from library               6, exit the application....\n\t\t\t");
        scanf("%d",&ch);
        flag=1;
        switch(ch)
            {
                case 1: add();
                    break;

                case 2: update();
                    break;

                case 3: delet();
                    break;

                case 4: printlist();
                    break;

                case 5: read();
                    break;

                case 6: exit(0);

                default: printf("\n\n PLEASE RE-ENTER THE VALID CHOICE :)\n\t");

            }
    }

}

void add()
{
    int ch;
    printf("\n\n          what kind of file you want to add?\n\n");
    printf("\n     1, people you met                 2, special incident ");
    printf("\n     3, dreams/bucket list             4, Quite!!!\n\t\t\t\there : ");
    printf("\n \n \n \n");
    scanf("%d",&ch);
     switch(ch)
            {
                case 1: ideal();
                    break;

                case 2: incident();
                    break;

                case 3: dream();
                    break;


                case 4: exit(0);

                default: printf("\n\n PLEASE RE-ENTER THE VALID CHOICE :)");

            }

}


void delet()
{
    char title[50];
    printlist();
    printf("\n\n here : ");
    printf("\n enter the name of file you want to delete :");
    scanf("%s",title);
    remove(title);
    printf("deleted %s:)",title);
}

void update()
{
    FILE *fp;
    char pick[50],reenter[60];

        printf("\n enter the title from notes displaying below : ");
        printlist();
        printf("\n\n Enter here : ");
        scanf("%s",pick);
        fp=fopen(pick,"ab+");
        printf("\n opening the file>>");
    if(fp==NULL)
    {
        printf("\n\n failed to open, please type precise name : ");
    }
    else
    {
        while(fwrite(gets(reenter),sizeof(reenter),1,fp)==1)
            {

            }
            fclose(fp);

    }

}

void ideal()
{
    FILE *fp;
    char name[40],detail[100];

    printf("\n so who is he impressed you, or you want to sneak in? \n");
    scanf("%s",name);
    fp=fopen(name,"wb");
    if(fp==NULL)
    {
        printf("\n failed to open file");
    }
    else
    {
        stitle(name);
        printf("\n note down all the things you really liked in %s\n",name);

        while(fwrite(gets(detail),sizeof(detail),1,fp)==1)
        {
        }
        fclose(fp);
    }


}


void incident()
{
    FILE *fp;
    char title[200],data[100];
    printf("\n appropriate title for incident : ");
    scanf("%s",title);
    fp=fopen(title,"wb+");
    if(fp==NULL)
    {
        printf("\n failed to open the file ");
    }
    else
    {
        stitle(title);
        printf("\n\n\n enter the data to the %s file -->",title);

       while(fwrite(gets(data),sizeof(data),1,fp)==1)
        {

        }
        fclose(fp);
    }

}



void dream()
{
    FILE *dream;
    char str[100],title[200];
    printf("\n enter the title to the dream :");
    scanf("%s",title);
    dream=fopen(title,"wb+");
    if(dream==NULL)
    {
        printf("\n\t failed to open the file, we're sorry");
    }
    else
    {

        stitle(title);

        printf("\n what's your %s dream!!",title);

        while(fwrite(gets(str),sizeof(str),1,dream)==1)
        {

        }
    fclose(dream);
    }
}


void read()
{
    FILE *fp;
    char pick[50],read[50];
    int ch;
    printf("\n enter the title from notes displaying below :)\n");
    printlist();
    printf("\n\n here : ");
    scanf("%s",pick);
    fp=fopen(pick,"rb");
    if(fp==NULL)
    {
        printf("\n\nplease type precise name : ");
    }
    else
    {
        while(fread(read,sizeof(read),1,fp)==1)
            {
                    puts(read);
            }
    }
    fclose(fp);
}


void printlist()
{
    int ch;
    char copy[50];
    FILE *fp;
    fp=fopen("save title","rb");
    if(fp==NULL)
    {
        printf("\n we're sorry, failed to open the file..");
    }
    else
    {
        printf("\n printing the names of the all your notes\n\n");
        while(!feof(fp))
        {
           ch=fgetc(fp);
           printf("%c",ch);
        }
        fclose(fp);
    }

}


void stitle(char title[])
{
    FILE *fp;
    fp=fopen("save title","ab");
    if(fp==NULL)
    {
        printf("\n failed to open the file...");
    }
    else
    {
        strcat(title,"\n");
        fputs(title,fp);
    }
    fclose(fp);
}

