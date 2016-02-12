#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void fc();
void fr();
void ft();
struct info
{
    char stdname[20];
    char regno[20];
    char pass[20];
    int sh[12];
    int sm[12];
    int ss[12];
    int eh[12];
    int em[12];
    int es[12];
    char mon[12][25];
    char tue[12][25];
    char wed[12][25];
    char thurs[12][25];
    char fri[12][25];
    char day[5][10];
    };


void fc()
{
    struct info A;
    char fname[20];
    char recpass[20];
    char temp[20];
    FILE *fp;
    int i,j;
    printf("\nEnter registration number\n");
    gets(fname);
    system("cls");
    strcpy(temp,fname);
    strcat(fname,".txt");
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("Can't create file");
        return;
    }
    strcpy(A.regno,temp);

    printf("\nEnter name\n");
    gets(A.stdname);

    system("cls");
    do
    {
    i++;
    strset(recpass,'\0');
    strset(A.pass,'\0');
    printf("\nEnter pass\n");
    gets(A.pass);
    fwrite(&A, sizeof(struct info), 1, fp);
    printf("\nReconfirm pass\n");
    gets(recpass);
    if(i>1)
    {
        printf("Pass doesn't match");
        system("cls");
    }
    }while(strcmp(A.pass,recpass)!=0);
    /*for(j=0;j<12;j++)
    {
    printf("\nEnter starting hour in 24 hour format\n");
    printf("\nEnter starting minute within 00-59\n");
    printf("\nEnter starting second within 0-59\n");
    scanf("%d%d%d",&A.sh[j],&A.sm[j],&A.ss[j]);

    printf("\nEnter ending hour in 24 hour format\n");
    printf("\nEnter ending minute within 0-59\n");
    printf("\nEnter ending second within 0-59\n");
    scanf("%d%d%d",&A.eh[j],&A.em[j],&A.es[j]);
   }*/
    for(i=0;i<5;i++)
    {
        strset(A.day[i],'\0');
        if(i==0){strcpy(A.day[i],"Monday");fflush(stdin);}
        else if(i==1){strcpy(A.day[i],"Tuesday");fflush(stdin);}
        else if(i==2){strcpy(A.day[i],"Wednesday");fflush(stdin);}
        else if(i==3){strcpy(A.day[i],"Thursday");fflush(stdin);}
        else if(i==4){strcpy(A.day[i],"Friday");fflush(stdin);}
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<12;j++)
        {
            printf("\n%s Period %d\n",A.day[i],(j+1));
            fflush(stdin);
            if(i==0){gets(A.mon[i]);}
            else if(i==1){gets(A.tue[i]);}
            else if(i==2){gets(A.wed[i]);}
            else if(i==3){gets(A.thurs[i]);}
            else if(i==4){gets(A.fri[i]);}

            fflush(stdin);

        }
    }
    for(j=0;j<12;j++)
    {
        printf("\nEnter starting hour in 24 hour format\n");
        printf("\nEnter starting minute within 00-59\n");
        printf("\nEnter starting second within 0-59\n");
        scanf("%d%d%d",&A.sh[j],&A.sm[j],&A.ss[j]);

        printf("\nEnter ending hour in 24 hour format\n");
        printf("\nEnter ending minute within 0-59\n");
        printf("\nEnter ending second within 0-59\n");
        scanf("%d%d%d",&A.eh[j],&A.em[j],&A.es[j]);
        system("cls");
        fflush(stdin);

    }
    fwrite(&A, sizeof(struct info), 1, fp);
    fclose(fp);
}
void fr()
{

    struct info A;
    FILE *fp;
    int i,j,m=0,k;
    char tim[20];
    char name[20];
    char reg[20];
    char regcopy[20];
    char pass[20];
    char temp[2];
    char str[20];
    char mon[12][25];
    char tue[12][25];
    char wed[12][25];
    char thurs[12][25];
    char fri[12][25];
    strset(pass,'\0');
    //strset(tim,'\0');
    printf("Enter your name");
    gets(name);
    system("cls");
    printf("Enter your registration number");
    gets(reg);
    system("cls");
    strcpy(regcopy,reg);
    strcat(regcopy,".txt");
    fp=fopen(regcopy,"r");
    if(fp==NULL)
    {
        printf("No such account found");
        return;
    }
    fread(&A, sizeof(struct info), 1, fp);
    for(i=1;i<=3;i++)
    {
        printf("Enter password--%d chances left",(4-i));
        gets(pass);
        if(strcmp(pass,A.pass)==0)
        {
            puts("\nWelcome\n");
            puts(A.stdname);
            system("cls");
            break;
        }
        else
        {
            puts("Wrong pass");
            system("cls");
        }
    }
     if(i==4)
     {
         puts("Wrong id or password-----Try after sometime");
         system("cls");
         return;
     }
    i=0;
    for(i=0;i<20;i++)
    printf("%c",' ');
    for(i=0;i<5;i++)
    {
    fread(&A, sizeof(struct info), 1, fp);
    printf("%s",A.day[i]);
    for(j=strlen(A.day[i]);j<10;j++)printf("%c",' ');
    if(i==4)printf("%c",'\n');
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<12;j++)
        {
            if(i==0){fread(&A, sizeof(struct info), 1, fp);strcpy(mon[j],A.mon[j]);}
            else if(i==1){fread(&A, sizeof(struct info), 1, fp);strcpy(tue[j],A.tue[j]);}
            else if(i==2){fread(&A, sizeof(struct info), 1, fp);strcpy(wed[j],A.wed[j]);}
            else if(i==3){fread(&A, sizeof(struct info), 1, fp);strcpy(thurs[j],A.thurs[j]);}
            else if(i==4){fread(&A, sizeof(struct info), 1, fp);strcpy(fri[j],A.fri[j]);}
        }
    }
    for(j=0;j<12;j++)
    {

        strset(tim,'\0');
        fread(&A, sizeof(struct info), 1, fp);
        //printf("A.sh[j]=%d",A.sh[j]);
        sprintf(str,"%d",A.sh[j]);
        //puts(str);
        //getch();
        strcat(tim,str);
        strset(str,'\0');
        //puts(str);
        //getch();
        strcat(tim,":");
        fread(&A, sizeof(struct info), 1, fp);
        sprintf(str,"%d",A.sm[j]);
        //puts(str);
        //getch();
        strcat(tim,str);
        strset(str,'\0');
        strcat(tim,":");
        fread(&A, sizeof(struct info), 1, fp);
        sprintf(str,"%d",A.ss[j]);
        strcat(tim,str);
        strset(str,'\0');
        //puts(str);
        //getch();
        strcat(tim,"-");
        fread(&A, sizeof(struct info), 1, fp);
        sprintf(str,"%d",A.eh[j]);
        strcat(tim,str);
        strset(str,'\0');
       // puts(str);
        //getch();
        strcat(tim,":");
        fread(&A, sizeof(struct info), 1, fp);
        sprintf(str,"%d",A.em[j]);
        strcat(tim,str);
        strset(str,'\0');
        //puts(str);
        //getch();
        strcat(tim,":");
        fread(&A, sizeof(struct info), 1, fp);
        sprintf(str,"%d",A.es[j]);
        strcat(tim,str);
        strset(str,'\0');
        //puts(str);
        //getch();
        printf("%s",tim);

        for(m=strlen(tim);m<20;m++)printf("%c",' ');
        for(i=0;i<5;i++)

        {
            fread(&A, sizeof(struct info), 1, fp);
            if(i==0)
            {
                //fread(&A, sizeof(struct info), 1, fp);

                printf("%s",mon[j]);
                m=strlen(mon[j]);
            }
            else if(i==1)
            {
                //fread(&A, sizeof(struct info), 1, fp);

                printf("%s",tue[j]);
                m=strlen(tue[j]);
            }
            else if(i==2)
            {
                //fread(&A, sizeof(struct info), 1, fp);

                printf("%s",wed[j]);
                m=strlen(wed[j]);
            }
            else if(i==3)
            {
                //fread(&A, sizeof(struct info), 1, fp);
                printf("%s",thurs[j]);
                m=strlen(thurs[j]);
            }
            else if(i==4)
            {
                //fread(&A, sizeof(struct info), 1, fp);
                printf("%s",fri[j]);
                m=strlen(fri[j]);
            }

            for(;m<10;m++)printf("%c",' ');
        }
        printf("%c",'\n');
    }

fclose(fp);
}
void ft()
{
    struct info A;
    FILE *fp;
    int i,j;
    fp=fopen("14BCE1007.bin","rb");
    fread(&A, sizeof(struct info), 1, fp);
    printf("REG  NO is %s",A.regno);
    fread(&A, sizeof(struct info), 1, fp);
    printf("Student name is %s",A.stdname);
    fread(&A, sizeof(struct info), 1, fp);
    printf("Pass is%s",A.pass);
    for(i=0;i<5;i++)
    {
        printf("%s",A.day[i]);
    }
    fread(&A, sizeof(struct info), 1, fp);puts(A.mon[0]);
    fread(&A, sizeof(struct info), 1, fp);puts(A.mon[1]);
    fread(&A, sizeof(struct info), 1, fp);puts(A.mon[2]);
    fread(&A, sizeof(struct info), 1, fp);puts(A.mon[3]);
    fread(&A, sizeof(struct info), 1, fp);puts(A.mon[4]);
    for(i=0;i<5;i++)
    {
        for(j=0;j<12;j++)
        {

            if(i==0){fread(&A, sizeof(struct info), 1, fp);puts(A.mon[j]);getch();}
            else if(i==1){fread(&A, sizeof(struct info), 1, fp);puts(A.tue[j]);getch();}
            else if(i==2){fread(&A, sizeof(struct info), 1, fp);puts(A.wed[j]);getch();}
            else if(i==3){fread(&A, sizeof(struct info), 1, fp);puts(A.thurs[j]);getch();}
            else if(i==4){fread(&A, sizeof(struct info), 1, fp);puts(A.fri[j]);getch();}


        }
    }

    fclose(fp);

    }


int main()
{

    fc();
    //ft();

    //fr();
}
