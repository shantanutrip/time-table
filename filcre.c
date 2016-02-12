#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void fc();
void fr();
char st[9][10]={"08:00:00",
            "09:00:00",
            "10:00:00",
            "11:00:00",
            "12:00:00",
            "14:00:00",
            "15:00:00",
            "16:00:00",
            "17:00:00"
            };
char et[9][10]={ "08:50:00",
            "09:50:00",
            "10:50:00",
            "11:50:00",
            "12:50:00",
            "14:50:00",
            "15:50:00",
            "16:50:00",
            "17:50:00"
            };
char ct[9][10]={"07:55:00",
            "08:55:00",
            "09:55:00",
            "10:55:00",
            "11:55:00",
            "13:55:00",
            "14:55:00",
            "15:55:00",
            "16:55:00"
            };


struct info
{
    char stdname[20];
    char regno[20];
    char pass[20];

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
    char ch='\0';
    FILE *fp;
    int i=0,j=0;

    printf("Enter registration number\n");
    fflush(stdin);
    gets(fname);
    system("cls");
    strcpy(temp,fname);
    strcat(fname,".txt");
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("Can't create file\n");
        return;
    }
    strcpy(A.regno,temp);
    fwrite(A.regno, 20 , 1, fp);

    printf("Enter name\n");
    gets(A.stdname);
    fwrite(A.stdname, 20 , 1, fp);

    system("cls");
    do
    {
    i++;
    if(i>1)printf("Pass doesn't match");
    strset(recpass,'\0');
    strset(A.pass,'\0');
    printf("Enter pass\n");
    gets(A.pass);
    /*&while((ch=getch())!='\x0D')
    {
        //ch=getch();
        printf("*");
        A.pass[j++]=ch;
    }*/
    //system("cls");
    //puts(A.pass);
    j=0;
    printf("Reconfirm pass\n");
    gets(recpass);
    /*while((ch=getch())!='\x0D')
    {
        //ch=getch();
        printf("*");
        recpass[j++]=ch;
    }*/
    //puts(recpass);
    //getch();
    //system("cls");
    if(i>1)
    {
        printf("Pass doesn't match");

    }
    }while(strcmp(A.pass,recpass)!=0);
    fwrite(A.pass, 20 , 1, fp);
    j=0;
    for(i=0;i<5;i++)
    {
        strset(A.day[i],'\0');
        if(i==0){strcpy(A.day[i],"Monday");fflush(stdin);}
        else if(i==1){strcpy(A.day[i],"Tuesday");fflush(stdin);}
        else if(i==2){strcpy(A.day[i],"Wednesday");fflush(stdin);}
        else if(i==3){strcpy(A.day[i],"Thursday");fflush(stdin);}
        else if(i==4){strcpy(A.day[i],"Friday");fflush(stdin);}
        fwrite(A.day[i], 10 , 1, fp);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("\n%s Period %d\n",A.day[i],(j+1));

            if(i==0){gets(A.mon[i]);fwrite(A.mon[i], 25 , 1, fp);}
            else if(i==1){gets(A.tue[i]);fwrite(A.tue[i], 25 , 1, fp);}
            else if(i==2){gets(A.wed[i]);fwrite(A.wed[i], 25 , 1, fp);}
            else if(i==3){gets(A.thurs[i]);fwrite(A.thurs[i], 25 , 1, fp);}
            else if(i==4){gets(A.fri[i]);fwrite(A.fri[i], 25 , 1, fp);}


        }
    }

    fclose(fp);
}
void fr()
{

    struct info A;
    FILE *fp;
    int i=0,j=0,m=0,k;
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
    char ch;
    strset(pass,'\0');
    //strset(tim,'\0');
    printf("Enter your name\n");
    fflush(stdin);
    gets(name);
    system("cls");
    printf("Enter your registration number\n");
    gets(reg);
    system("cls");
    strcpy(regcopy,reg);
    strcat(regcopy,".txt");
    fp=fopen(regcopy,"r");
    if(fp==NULL)
    {
        printf("No such account found\n");
        return;
    }
    fread(A.regno, 20 , 1, fp);
    fread(A.stdname, 20 , 1, fp);
    fread(A.pass, 20 , 1, fp);

    for(i=1;i<=3;i++)
    {
        j=0;
        printf("Enter password--%d chances left",(4-i));
        gets(pass);
        /*while((ch=getch())!='\x0D')
        {
            //ch=getch();
            printf("*");
            pass[j++]=ch;
        }*/
        puts(A.pass);
        if(strcmp(pass,A.pass)==0)
        {
            puts("\nWelcome\n");
            puts(A.stdname);
            printf("\nRegistration Number-\n");
            puts(A.regno);

            //system("cls");
            break;
        }
        else
        {
            puts("Wrong pass");

        }
    }
     if(i==4)
     {
         puts("Wrong id or password-----Try after sometime");
         //system("cls");
         return;
     }
    i=0;
    j=0;
    for(i=0;i<20;i++)
    printf("%c",' ');
    for(i=0;i<5;i++)
    {
    fread(A.day[i], 10 , 1, fp);
    printf("%s",A.day[i]);
    for(j=strlen(A.day[i]);j<10;j++)printf("%c",' ');
    if(i==4)printf("%c",'\n');
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<9;j++)
        {
            if(i==0){fread(A.mon[j], 25 , 1, fp);strcpy(mon[j],A.mon[j]);}
            else if(i==1){fread(A.tue[j], 25 , 1, fp);strcpy(tue[j],A.tue[j]);}
            else if(i==2){fread(A.wed[j], 25 , 1, fp);strcpy(wed[j],A.wed[j]);}
            else if(i==3){fread(A.thurs[j], 25 , 1, fp);;strcpy(thurs[j],A.thurs[j]);}
            else if(i==4){fread(A.fri[j], 25 , 1, fp);;strcpy(fri[j],A.fri[j]);}
        }
    }
    for(j=0;j<9;j++)
    {
        strset(tim,'\0');
        strcat(tim,st[j]);
        strcat(tim,"-");
        strcat(tim,et[j]);
        printf("%s",tim);
        for(m=strlen(tim);m<20;m++)printf("%c",' ');
        for(i=0;i<5;i++)
        {
            if(i==0)
            {
                printf("%s",mon[j]);
                m=strlen(mon[j]);
            }
            else if(i==1)
            {
                printf("%s",tue[j]);
                m=strlen(tue[j]);
            }
            else if(i==2)
            {
                printf("%s",wed[j]);
                m=strlen(wed[j]);
            }
            else if(i==3)
            {
                printf("%s",thurs[j]);
                m=strlen(thurs[j]);
            }
            else if(i==4)
            {
                printf("%s",fri[j]);
                m=strlen(fri[j]);
            }

            for(;m<10;m++)printf("%c",' ');
        }
        printf("%c",'\n');
    }

fclose(fp);
}
main()
{
    int choice;
    do
    {
        printf("1 ---> Create a new profile\n");
        printf("2 ---> Open existing profile\n");
        printf("3 ---> Exit\n");
        scanf("%d",&choice);
        system("cls");
        if(choice==1)
        {
            fc();
        }
        else if(choice==2)
        {
            fr();
        }
        else if(choice==3)
        {
            printf("Thanks for using the program");
        }
        else
        {
            printf("Sorry! Input once again");
        }
    }while(choice!=3);
    //return 0;
}
