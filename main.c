/************************************************************************************
 * Project name : LIBRARY MANAGEMENT SYSTEM                                         *
 * Authors : GROUP 3                                                                *
 * Purpose : The purpose is to provide interface to manage a library                *
 * Date : 03/06/2022                                                                *
 ************************************************************************************/




#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void welcomeMessage();
void login();
void addbooks(void);

typedef struct
	{
	    int id;
	    char type[20];
	    char name[30];
	    char address[20];
	    char phone[30];
	    char email[30];
	    char UN[20];
		char password[20];
	} subscribers;

typedef struct
{
    char books_id[30]; // declare the integer data type
    char bookName[30];// declare the character data type
    char authorName[30];
    char publisher[30];
    char prodyear[10];
    char copies[30];
}bookinfo;
typedef struct
{
    int dd,mm,yy;

}dates;
typedef struct
	{
	    char bookid[30];
	    char type[20];
	    char title[30];
	    char username[20];
	    dates borrowdate;

	} borrow;

int main(){

    welcomeMessage();
    login();
}
void welcomeMessage()
{       system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                   GROUP 3                         ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void login()
{
     system("cls");
    int choice = 0;
    do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  LOGIN  \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Login as Admin.  \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> Login as User.\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> New member? Register.\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            userlogin();
            break;
        case 3:
            registration();
            break;
        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }

    }while(choice!=0);
}
void adminLogin(){
     system("cls");
    char userName[50];
    char password[50];
    char un[50],pw[50];
    int L=0;

    FILE *fp= fopen("admin.txt","r");
    fscanf(fp,"%s %s",un,pw);
    fclose(fp);

    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  WELCOME ADMIN,ENTER YOUR INFORMATION TO LOGIN  \xB2\xB2\xB2\xB2\xB2\xB2\n");
    do
    {
        printf("\n\n\t\t\t\t\xB2=>Username: ");
        scanf("%s",userName);
        printf("\n\t\t\t\t\xB2=>Password: ");
        scanf("%s",password);
        if((strcmp(userName,un)==0) && (strcmp(password,pw)==0))
        {
            printf("\n\t\t\t\tLogin Succesful! \n\n\t\t\t\tEnter any key to continue.....");
            getch();
            adminmenu();
            break;
        }
        else
        {
            printf("\n\t\t\t\tLogin Failed Enter Again Username & Password(%d trials left)",3-L);
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        printf("\n\n\t\t\t\tLogin Failed!\n\n");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}

void adminmenu(){
    system("cls");
    int choice = 0;
    do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  ADMIN MENU  \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Add Books  \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> Delete Books\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> Edit Book's Record\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 4=> view book list\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 5=> Print reports of overdue borrowed items\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
            addBooks();
            break;
        case 2:
            deleteBooks();
            break;
        case 3:
            editbooks();
            break;
        case 4:
            bookList();
            break;
        case 5:
            printrec();
            break;
        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
        }while(choice!=0);
}

void addBooks(){
    int choice;
    bookinfo addBookInfoInDataBase = {0};
    FILE * ff;
    system("cls");
      do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 SELECT LIBRARY CATEGORY \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
        system("cls");
        ff= fopen("CampusLib.txt","ab+");
        printf("\n\n\t\t\tENTER BOOK DETAILS BELOW:");
        printf("\n\t\t\t---------------------------------------------------------------------------\n");

            printf("\n\t\t\t\xB2\=>Book ID NO  = ");
            fflush(stdin); //fflush(stdin) is used to flush the output buffer of the stream.
            gets(addBookInfoInDataBase.books_id);

            printf("\n\t\t\t\xB2\=>Book Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.bookName);

            printf("\n\t\t\t\xB2\=>Author Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.authorName);

            printf("\n\t\t\t\xB2\=>Publisher Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.publisher);

            printf("\n\t\t\t\xB2\=>Production Year  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.prodyear);
            printf("\n\t\t\t\xB2\=>Number of copies  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.copies);

        fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, ff);

        fclose(ff);
        printf("\n\n\t\t\t\tThe Record Is Sucessfully Saved");
        printf("\n\n\t\t\t\tDo you want to save more?(Y / N):");
        if(getch()=='n' ||getch()=='N')
        adminmenu();
        else
        system("cls");
        addBooks();

            break;
        case 2:
           system("cls");
        ff= fopen("CSlib.txt","ab+");
        printf("\n\n\t\t\tENTER BOOK DETAILS BELOW:");
        printf("\n\t\t\t---------------------------------------------------------------------------\n");

            printf("\n\t\t\t\xB2\=>Book ID NO  = ");
            fflush(stdin); //fflush(stdin) is used to flush the output buffer of the stream.
            gets(addBookInfoInDataBase.books_id);

            printf("\n\t\t\t\xB2\=>Book Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.bookName);

            printf("\n\t\t\t\xB2\=>Author Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.authorName);

            printf("\n\t\t\t\xB2\=>Publisher Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.publisher);

            printf("\n\t\t\t\xB2\=>Production Year  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.prodyear);
            printf("\n\t\t\t\xB2\=>Number of copies  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.copies);

        fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, ff);

        fclose(ff);
        printf("\n\n\t\t\t\tThe Record Is Sucessfully Saved");
        printf("\n\n\t\t\t\tDo you want to save more?(Y / N):");
        if(getch()=='n' ||getch()=='N')
        adminmenu();
        else
        system("cls");
        addBooks();

            break;
        case 3:
            system("cls");
        ff= fopen("EngLib.txt","ab+");
        printf("\n\n\t\t\tENTER BOOK DETAILS BELOW:");
        printf("\n\t\t\t---------------------------------------------------------------------------\n");

            printf("\n\t\t\t\xB2\=>Book ID NO  = ");
            fflush(stdin); //fflush(stdin) is used to flush the output buffer of the stream.
            gets(addBookInfoInDataBase.books_id);

            printf("\n\t\t\t\xB2\=>Book Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.bookName);

            printf("\n\t\t\t\xB2\=>Author Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.authorName);

            printf("\n\t\t\t\xB2\=>Publisher Name  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.publisher);

            printf("\n\t\t\t\xB2\=>Production Year  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.prodyear);
            printf("\n\t\t\t\xB2\=>Number of copies  = ");
            fflush(stdin);
            gets(addBookInfoInDataBase.copies);

        fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, ff);

        fclose(ff);
        printf("\n\n\t\t\t\tThe Record Is Sucessfully Saved");
        printf("\n\n\t\t\t\tDo you want to save more?(Y / N):");
        if(getch()=='n' ||getch()=='N')
        adminmenu();
        else
        system("cls");
        addBooks();

            break;

        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    }while(choice!=0);
}
void bookList(){

    system("cls");
    FILE * fp;
    int choice;
     bookinfo BookInfoInDataBase;
     do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 SELECT LIBRARY CATEGORY \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CampusLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            adminmenu();

            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CSlib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            adminmenu();
            break;
        case 3:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("EngLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            adminmenu();
            break;

        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    }while(choice!=0);

}

void deleteBooks(){


    system("cls");
    int choice;
    int f=0;
    char *id;
     FILE *ft,*fp;
     bookinfo BookInfoInDataBase;
            do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 SELECT LIBRARY CATEGORY TO DELETE FROM \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:

                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("\n\t\t\t\t\t\xB2\<== Remove Books From Main Campus Library ==>\xB2\n\n");
                    printf("\n\n\n\t\t\tEnter Book id to remove: ");
                    scanf("%s", id);

                    fp = fopen("CampusLib.txt", "rb");
                    ft = fopen("temp.txt", "wb");

                    while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, fp) == 1){
                        if(strcmp(id,BookInfoInDataBase.books_id)==0){
                            f=1;
                        }else{
                            fwrite(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, ft);
                        }
                    }

                    if(f==1){
                        printf("\n\n\n\t\t\t\xB2\xB2\ Deleted Successfully.\xB2\xB2");
                    }else{
                        printf("\n\n\n\t\t\t\xB2\xB2\ Record Not Found !");
                    }

                    fclose(fp);
                    fclose(ft);

                    remove("CampusLib.txt");
                    rename("temp.txt", "CampusLib.txt");
                    printf("\n\n\n\t\t\t Enter any key to continue.....");
                        getch();
                        adminmenu();
                        break;
                       /*printf("\n\n\t\t\t\tDo you want to delete another book?(Y / N):");
                        if(getch()=='n' ||getch()=='N')
                        adminmenu();
                        else
                        deleteBooks(); */


            break;
        case 2:

                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("\n\t\t\t\t\t\xB2\<== Remove Books From The CS Library ==>\xB2\n\n");
                    printf("\n\n\n\t\t\tEnter Book id to remove: ");
                    scanf("%s", id);

                    fp = fopen("CSlib.txt", "rb");
                    ft = fopen("temp.txt", "wb");

                    while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, fp) == 1){
                        if(strcmp(id,BookInfoInDataBase.books_id)==0){
                            f=1;
                        }else{
                            fwrite(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, ft);
                        }
                    }

                    if(f==1){
                        printf("\n\n\n\t\t\t\xB2\xB2\ Deleted Successfully.\xB2\xB2");
                    }else{
                        printf("\n\n\n\t\t\t\xB2\xB2\ Record Not Found !");
                    }

                    fclose(fp);
                    fclose(ft);

                    remove("CSlib.txt");
                    rename("temp.txt", "CSlib.txt");
                      printf("\n\n\n\t\t\t Enter any key to continue.....");
                        getch();
                        adminmenu();
                        break;

            break;
        case 3:

                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("\n\t\t\t\t\t\xB2\<== Remove Books From The Engineering Library ==>\xB2\n\n");
                    printf("\n\n\n\t\t\tEnter Book id to remove: ");
                    scanf("%s", id);

                    fp = fopen("EngLib.txt", "rb");
                    ft = fopen("temp.txt", "wb");

                    while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, fp) == 1){
                        if(strcmp(id,BookInfoInDataBase.books_id)==0){
                            f=1;
                        }else{
                            fwrite(&BookInfoInDataBase, sizeof(BookInfoInDataBase), 1, ft);
                        }
                    }

                    if(f==1){
                        printf("\n\n\n\t\t\t\xB2\xB2\ Deleted Successfully.\xB2\xB2");
                    }else{
                        printf("\n\n\n\t\t\t\xB2\xB2\ Record Not Found !");
                    }

                    fclose(fp);
                    fclose(ft);

                    remove("EngLib.txt");
                    rename("temp.txt", "EngLib.txt");

                        printf("\n\n\n\t\t\t Enter any key to continue.....");
                        getch();
                        adminmenu();
                        break;

            break;
        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            break;
        }

    }while(choice!=0);
}
void printrec(){
        FILE * fp;
        borrow b;
        system("cls");
            printf("\n\n\n\n\n");
             printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 RECORDS OF BORROWED BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("  %-20s || %-10s || %-20s || %-20s || %-15s  \n","UserName", "Book ID", "Book Name", "Category","Borrow Date");
            fp = fopen("Borrow.txt", "rb");
            while(fread(&b, sizeof(b),1 ,fp)){

               printf("\n  %-20s || %-10s || %-20s || %-20s || %d/%d/%d  ", b.username, b.bookid , b.title, b.type,b.borrowdate.dd,b.borrowdate.mm,b.borrowdate.yy);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            adminmenu();



}

void editbooks()  //edit information about book
{
    system("cls");
    char id[20];
    FILE *fp;
    int c=0;
    int e;
    int choice;
    char another='y';

     bookinfo a;
    while(another=='y'){

    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\ SELECT LIBRARY CATEGORY TO EDIT FROM\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\ 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
                system("cls");
                printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\ Edit Books Section\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\n\t\t\tEnter Book id to edit: ");
                    scanf("%s",id);
        fp=fopen("CampusLib.txt","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {

                if(strcmp(id,a.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {
                printf("\n\n\n\t\t\tThe Book Is Available !");

                printf("\n\n\n\t\t\tThe Book ID:%s",a.books_id);

                printf("\n\n\n\t\t\t\xB2\ Enter New Name:");
                fflush(stdin);
                gets(a.bookName);

                printf("\n\n\n\t\t\t\xB2\ Enter New Author:");
                fflush(stdin);
                gets(a.authorName);

                printf("\n\n\n\t\t\t\xB2\ Add New Publisher:");
                fflush(stdin);
                gets(a.publisher);

                printf("\n\n\n\t\t\t\xB2\ Enter New Production Year:");
                scanf("%s",a.prodyear);

                printf("\n\n\n\t\t\t\xB2\ Enter New number of copies:");
                scanf("%s",a.copies);

                printf("\n\n\n\t\t\t\tThe record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);

                c=1;
            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }
        printf("\n\n\n\t\t\t\tModify another Record?(Y/N)");
        fflush(stdin);

        another=getch();


            break;
        case 2:
                system("cls");
                printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\ Edit Books Section\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\n\t\t\tEnter Book id to edit: ");
                    scanf("%s",id);
        fp=fopen("CSlib.txt","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {

                if(strcmp(id,a.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {
                printf("\n\n\n\t\t\tThe Book Is Available !");

                printf("\n\n\n\t\t\tThe Book ID:%s",a.books_id);

                printf("\n\n\n\t\t\t\xB2\ Enter New Name:");
                fflush(stdin);
                gets(a.bookName);

                printf("\n\n\n\t\t\t\xB2\ Enter New Author:");
                fflush(stdin);
                gets(a.authorName);

                printf("\n\n\n\t\t\t\xB2\ Add New Publisher:");
                fflush(stdin);
                gets(a.publisher);

                printf("\n\n\n\t\t\t\xB2\ Enter New Production Year:");
                scanf("%s",a.prodyear);

                printf("\n\n\n\t\t\t\xB2\ Enter New number of copies:");
                scanf("%s",a.copies);

                printf("\n\n\n\t\t\t\tThe record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);

                c=1;
            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }
        printf("\n\n\n\t\t\t\tModify another Record?(Y/N)");
        fflush(stdin);

        another=getch();


            break;
        case 3:
            system("cls");
                printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\ Edit Books Section\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\n\t\t\tEnter Book id to edit: ");
                    scanf("%s",id);
        fp=fopen("EngLib.txt","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {

                if(strcmp(id,a.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {
                printf("\n\n\n\t\t\tThe Book Is Available !");

                printf("\n\n\n\t\t\tThe Book ID:%s",a.books_id);

                printf("\n\n\n\t\t\t\xB2\ Enter New Name:");
                fflush(stdin);
                gets(a.bookName);

                printf("\n\n\n\t\t\t\xB2\ Enter New Author:");
                fflush(stdin);
                gets(a.authorName);

                printf("\n\n\n\t\t\t\xB2\ Add New Publisher:");
                fflush(stdin);
                gets(a.publisher);

                printf("\n\n\n\t\t\t\xB2\ Enter New Production Year:");
                scanf("%s",a.prodyear);

                printf("\n\n\n\t\t\t\xB2\ Enter New number of copies:");
                scanf("%s",a.copies);

                printf("\n\n\n\t\t\t\tThe record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);

                c=1;
            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }
        printf("\n\n\n\t\t\t\tModify another Record?(Y/N)");
        fflush(stdin);

        another=getch();



            break;

        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }



    }
}
void maincamplib(){
    system("cls");
    FILE * fp;
    int choice;
     bookinfo BookInfoInDataBase;
     printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CampusLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
}
void cslib(){
    system("cls");
    FILE * fp;
    int choice;
     bookinfo BookInfoInDataBase;
     printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CSlib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
}
void englib(){
    system("cls");
    FILE * fp;
    int choice;
     bookinfo BookInfoInDataBase;
     printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2\<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("EngLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
}
void bookListUser(){

    system("cls");
    FILE * fp;
    int choice;
     bookinfo BookInfoInDataBase;
     do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 SELECT LIBRARY CATEGORY \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CampusLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            usermenu();

            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("CSlib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            usermenu();
            break;
        case 3:
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n\t\t\t\t\t\xB2<== Available Books ==>\xB2\n\n");
            printf("  %-10s || %-20s || %-20s || %-20s || %-15s  ||  %-10s\n", "Book id", "Book Name", "Author", "Publisher","Production Year","Copies");
            fp = fopen("EngLib.txt", "rb");
            while(fread(&BookInfoInDataBase, sizeof(BookInfoInDataBase),1 ,fp)){

               printf("\n  %-10s || %-20s || %-20s || %-20s || %-15s  ||    %-10s", BookInfoInDataBase.books_id, BookInfoInDataBase.bookName , BookInfoInDataBase.authorName, BookInfoInDataBase.publisher,BookInfoInDataBase.prodyear,BookInfoInDataBase.copies);
               printf("\n");

            }
            fclose(fp);
            printf("\n\n\n\t\t\t Enter any key to continue.....");
            getch();
            usermenu();
            break;

        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            //Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    }while(choice!=0);

}


void usermenu(){
    system("cls");
    int choice = 0;
    do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  USER MENU  \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 1=> View Book List \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 2=> Borrow Book\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 3=> Return Book\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
            bookListUser();
            break;
      case 2:
            borrowbooks();
            break;
        case 3:
            returnBooks();
            break;
        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep("3000");
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
        }while(choice!=0);
}

void userlogin(){
     system("cls");
    subscribers user;
    char userName[50];
    char password[50];
    char un[50],pw[50];
    int L=0;
    int e=1;

do{
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  WELCOME DEAR USER,ENTER YOUR INFORMATION TO LOGIN  \xB2\xB2\xB2\xB2\xB2\xB2\n");


        printf("\n\n\t\t\t\t\xB2=>Username: ");
        scanf("%s",userName);
        printf("\n\t\t\t\t\xB2=>Password: ");
        scanf("%s",password);

     FILE *fp= fopen("users.txt","rb");
           /* fscanf(fp,"%s %s",un,pw);
            fclose(fp);*/
                while(fread(&user, sizeof(user),1 ,fp)==1){

                if((strcmp(user.name,userName)==0) && (strcmp(user.password,password)==0))
                    e=0;
                else
                    e=1;
                if(e==0)
                {
                    printf("\n\t\t\t\tLogin Succesful!\n\t\t\t\t  \n\n\t\t\t\tEnter any key to continue.....");
                    getch();
                    usermenu();
                    break;
                }
                else if(e==1 && feof(fp)==0)
                {
                    printf("\n\t\t\t\tLogin Failed Enter Again Username & Password(%d trials left)",3-L);
                    L++;
                }

                }            fclose(fp);}


    while(L<=3);
    if(L>3)
    {
        printf("\n\n\t\t\t\tLogin Failed!\n\n");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}

void registration(){
    system("cls");
	int choice,chc,phone[20];
	FILE *fp;
	subscribers user;
	fp= fopen("users.txt","ab+");

	printf("Hello!Do you wish to suscribe?\n\n");
	printf("Press '1' to sucribe or '0' to exit\n\n");

	//choice=2;
	do{
	printf("Enter your choice:");
	scanf("%d",&choice);
    }while(choice!=1&&choice!=0);


system("cls");

	if(choice==1){
		printf("What suscriber do you want to be?\n\n");
		printf("1.Golden\n");
		printf("Golden suscribers can borrow books for up to 03 months\n\n");
		printf("2.Regular\n");
		printf("Regular suscribers can borrow books fo up to 03 weeks\n\n");

		//chc=3;
		do{
		printf("Enter your choice:");
		scanf("%d",&chc);
	    }while(chc!=1&&chc!=2);
	}

system("cls");

		if(chc==1){
			user.type[20] = "Golden";
			//fprintf(fp,"%s\n",user.type);
			printf("For this subscription,you need to pay 5,000frs for registration and 10,000frs/month\n");
			printf("\nMake the above deposits to this number:6 92 24 72 91\n");
			printf("\nNext,send a screen capture of your deposit on WhatsApp via the number:6 92 24 72 91\n");
			printf("\nEnter your username:");
			scanf("%s",user.name);
//fprintf(fp,"%s\n",user.name);
			printf("\nEnter your password:");
			scanf("%s",user.password);
//fprintf(fp,"%s\n",user.password);
			printf("\nEnter your address:");
			scanf("%s",user.address);
	//		fprintf(fp,"%s\n",user.address);
			printf("\nEnter your e-mail:");
			scanf("%s",user.email);
		//	fprintf(fp,"%s\n",user.email);
			printf("\nEnter your phone no:");
			scanf("%s",user.phone);
			//fprintf(fp,"%s\n",user.phone);

			fwrite(&user,sizeof(user), 1, fp);

			fclose(fp);
			 printf("\nRegistration completed!Welcome new user!");
			 printf("\n\n\t\t\t\tEnter any key to continue.....");
                getch();
            login();

		}

		else if(chc==2){
			user.type[20] = "Regular";
			printf("For this subscription,you need to pay 5,000frs for registration and 5,000frs/month\n");
			printf("\nMake the above deposits to this number:6 92 24 72 91\n");
			printf("\nNext,send a screen capture of your deposit on WhatsApp via the number:6 92 24 72 91\n");
				printf("\nEnter your username:");
			scanf("%s",user.name);
			printf("\nEnter your password:");
			scanf("%s",user.password);
			printf("\nEnter your address:");
			scanf("%s",user.address);
			printf("\nEnter your e-mail:");
			scanf("%s",user.email);
			printf("\nEnter your phone no:");
			scanf("%s",user.phone);

			fwrite(&user,sizeof(user), 1, fp);
			fclose(fp);
			printf("\nRegistration completed!Welcome new user!");
			 printf("\n\n\t\t\t\tEnter any key to continue.....");
                getch();
            login();
		}
	else if(choice==0){
		printf("Exit");
	}

}
void borrowbooks(){
    system("cls");
    char id[20];
    dates date;
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 BORROW MENU  \xB2\xB2\xB2\xB2\xB2\xB2\n");
    FILE * fp,*ff;
    borrow b;
    int choice,e;
     bookinfo BookInfoInDataBase;
     do
    {
    printf("\n\n\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 SELECT LIBRARY CATEGORY \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 1=> Main Campus Libray \n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 2=> CS Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 3=> Engineering Library\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 0=> Close Application\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\tEnter your choice => ");
        scanf("%d",&choice);
       switch(choice)
        {
        case 1:
            system("cls");
            maincamplib();
            printf("\n");
            fp = fopen("CampusLib.txt", "rb");
            ff=fopen("Borrow.txt","ab+");

            printf("\n\n\t\t\t\tEnter the ID of the book you will like to borrow: ");

            scanf("%s",id);

           // while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)){
//printf("In while");
                while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)==1)
        {

                if(strcmp(id,BookInfoInDataBase.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {

                printf("\n\n\t\t\t\tThe Book Record Is Available!");

                printf("\n\n\t\t\t\tThere are %s unissued books in library ",BookInfoInDataBase.copies);

                    printf("\n\n\t\t\t\tThe name of book is %s",BookInfoInDataBase.bookName);
                    printf("\n\n\t\t\t\tEnter your user name:");
                    fflush(stdin);
                    gets(b.username);
                    strcpy(b.title,BookInfoInDataBase.bookName);
                    strcpy(b.bookid,id);
                    strcpy(b.type,"Main Campus Lib");
                    printf("\n\n\t\t\t\tEnter the Day of borrow(dd/mm/yy): ");
                    scanf("\n\t\t\t\t%d/%d/%d",&b.borrowdate.dd,&b.borrowdate.mm,&b.borrowdate.yy);

                    fwrite(&b,sizeof(b), 1, ff);

                    fclose(fp);
                    fclose(ff);
                    printf("\n\n\t\t\t\tYou have borrowed The BOOK of ID %s succesfully",id);
                    getch();
                    usermenu();

            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }

            break;
        case 2:
            system("cls");
            cslib();
            printf("\n");
            fp = fopen("CSlib.txt", "rb");
            ff=fopen("Borrow.txt","ab+");

            printf("\n\n\t\t\t\tEnter the ID of the book you will like to borrow: ");

            scanf("%s",id);

           // while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)){
//printf("In while");
                while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)==1)
        {

                if(strcmp(id,BookInfoInDataBase.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {

                printf("\n\n\t\t\t\tThe Book Record Is Available!");

                printf("\n\n\t\t\t\tThere are %s unissued books in library ",BookInfoInDataBase.copies);

                    printf("\n\n\t\t\t\tThe name of book is %s",BookInfoInDataBase.bookName);
                    printf("\n\n\t\t\t\tEnter your user name:");
                    fflush(stdin);
                    gets(b.username);

                    strcpy(b.bookid,id);
                    strcpy(b.type,"CS Library");
                    printf("\n\n\t\t\t\tEnter the Day of borrow(dd/mm/yy): ");
                    scanf("\n\t\t\t\t%d/%d/%d",&b.borrowdate.dd,&b.borrowdate.mm,&b.borrowdate.yy);

                    fwrite(&b,sizeof(b), 1, ff);

                    fclose(fp);
                    fclose(ff);
                    printf("\n\n\t\t\t\tYou have borrowed The BOOK of ID %s succesfully",id);
                    getch();
                    usermenu();

            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }
            break;
        case 3:
            system("cls");
            englib();
            printf("\n");
            fp = fopen("EngLib.txt", "rb");
            ff=fopen("Borrow.txt","ab+");

            printf("\n\n\t\t\t\tEnter the ID of the book you will like to borrow: ");

            scanf("%s",id);

           // while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)){
//printf("In while");
                while(fread(&BookInfoInDataBase,sizeof(BookInfoInDataBase),1,fp)==1)
        {

                if(strcmp(id,BookInfoInDataBase.books_id)==0)
                    e=0;
                else
                    e=1;

        if(e==0)
            {

                printf("\n\n\t\t\t\tThe Book Record Is Available!");

                printf("\n\n\t\t\t\tThere are %s unissued books in library ",BookInfoInDataBase.copies);

                    printf("\n\n\t\t\t\tThe name of book is %s",BookInfoInDataBase.bookName);
                    printf("\n\n\t\t\t\tEnter your user name:");
                    fflush(stdin);
                    gets(b.username);

                    strcpy(b.bookid,id);
                    strcpy(b.type,"Engineering Library");
                    printf("\n\n\t\t\t\tEnter the Day of borrow(dd/mm/yy): ");
                    scanf("\n\t\t\t\t%d/%d/%d",&b.borrowdate.dd,&b.borrowdate.mm,&b.borrowdate.yy);

                    fwrite(&b,sizeof(b), 1, ff);

                    fclose(fp);
                    fclose(ff);
                    printf("\n\n\t\t\t\tYou have borrowed The BOOK of ID %s succesfully",id);
                    getch();
                    usermenu();

            }
            else if(e==0 && feof(fp)==0)
            {
                printf("No record found");

            }

        }
            break;

        case 0:
            system("cls");
            printf("\n\n\n\t\t\tExiting in 3 second...........>");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    }while(choice!=0);

}/*
void fees(char id[20]){
    int daysinfeb,doy,daysborrow,difday,duration,daysreturn,e;
    borrow a;
    FILE *fl;
        fl=fopen("Borrow.txt","rb");
        //fseek(fl,0,SEEK_SET);
                        while(fread(&a, sizeof(a), 1, fl) == 1){
                        printf("  in while okkkk");

                        if(strcmp(a.bookid,id)==0){
                                printf("okkkk");
                                e=0;
                        }else{
                            continue;
                        }
                    }
                    if(e==0){
                    daysinfeb = 28;

                    doy = a.borrowdate.dd;

                    if( (a.borrowdate.yy % 4 == 0 && a.borrowdate.yy % 100 != 0 ) || (a.borrowdate.yy % 400 == 0) )
                    {
                        daysinfeb = 29;
                    }

                    switch(a.borrowdate.mm)
                    {
                        case 2:
                            doy += 31;
                            break;
                        case 3:
                            doy += 31+daysinfeb;
                            break;
                        case 4:
                            doy += 31+daysinfeb+31;
                            break;
                        case 5:
                            doy += 31+daysinfeb+31+30;
                            break;
                        case 6:
                            doy += 31+daysinfeb+31+30+31;
                            break;
                        case 7:
                            doy += 31+daysinfeb+31+30+31+30;
                            break;
                        case 8:
                            doy += 31+daysinfeb+31+30+31+30+31;
                            break;
                        case 9:
                            doy += 31+daysinfeb+31+30+31+30+31+31;
                            break;
                        case 10:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30;
                            break;
                        case 11:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31;
                            break;
                        case 12:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31+30;
                            break;
                    }
                    daysborrow=doy;

                    if(strcmp(a.type,"Golden")==0)
                    {
                        difday=daysreturn-daysborrow;
                        duration=84;
                        if(difday>duration){
                            printf("\n\n\n\t\t\t\xB2\xB2\ Dear Golden user,You  have exceeded your return time of %ddays\nYou will have to pay a fee of 5000f",difday-duration);
                        }
                        else
                            printf("\n\n\n\t\t\tThank you for using our library, You submited the book in time :)");

                    }
                    else if(strcmp(a.type,"Regular")==0)
                    {
                        duration=28;
                        if(difday>duration){
                            printf("\n\n\n\t\t\t\xB2\xB2\ Dear Regulat user,You  have exceeded your return time of %ddays\nYou will have to pay a fee of 10000f",difday-duration);
                        }
                        else
                            printf("\n\n\n\t\t\tThank you for using our library, You submited the book in time :)");
                    }

                    fclose(fl);
                    }

}*/
void returnBooks(){


        system("cls");
        char id[20];
            dates date;
            int f=0;
                      printf("\n\n\n\n\n");
            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 RETURN MENU  \xB2\xB2\xB2\xB2\xB2\xB2\n");
            FILE * fp,*ff,*ft,*fl;
            borrow b,a;
            char idd[20];
             int  daysinfeb = 28,duration;


            int choice,e,daysreturn,doy,daysborrow,difday;
             bookinfo BookInfoInDataBase;


               printf("\n\n\n\t\t\tEnter the id of the book you want to return: ");
               fflush(stdin);
                    gets(id);
                    strcpy(idd,id);
                printf("\n\n\t\t\t\tEnter the Return Day (dd/mm/yy): ");
                    scanf("%d/%d/%d",&date.dd,&date.mm,&date.yy);

                    doy = date.dd;

                    if( (date.yy % 4 == 0 && date.yy % 100 != 0 ) || (date.yy % 400 == 0) )
                    {
                        daysinfeb = 29;
                    }

                    switch(date.mm)
                    {
                        case 2:
                            doy += 31;
                            break;
                        case 3:
                            doy += 31+daysinfeb;
                            break;
                        case 4:
                            doy += 31+daysinfeb+31;
                            break;
                        case 5:
                            doy += 31+daysinfeb+31+30;
                            break;
                        case 6:
                            doy += 31+daysinfeb+31+30+31;
                            break;
                        case 7:
                            doy += 31+daysinfeb+31+30+31+30;
                            break;
                        case 8:
                            doy += 31+daysinfeb+31+30+31+30+31;
                            break;
                        case 9:
                            doy += 31+daysinfeb+31+30+31+30+31+31;
                            break;
                        case 10:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30;
                            break;
                        case 11:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31;
                            break;
                        case 12:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31+30;
                            break;
                    }

                    daysreturn=doy;
                    fp = fopen("Borrow.txt", "rb");
                    ft = fopen("temp.txt", "wb");

                    while(fread(&b, sizeof(b), 1, fp) == 1){
                        if(strcmp(id,b.bookid)==0){
                            f=1;
                        }else{
                            fwrite(&b, sizeof(b), 1, ft);
                        }
                    }

                    if(f==1){
                        printf("\n\n\n\t\t\t\xB2\xB2\ Book Returned Successfully.\xB2\xB2");
                    }else{
                        printf("\n\n\n\t\t\t\xB2\xB2\ Record Not Found !");
                    }

                    fclose(fp);
                    fclose(ft);

                    remove("Borrow.txt");
                    rename("temp.txt", "Borrow.txt");
        printf("\n\n\n\t\t\tDear Golden user,You  have exceeded your return time of days\n\n\n\t\t\tYou will have to pay a fee of 5000f\n\n\n\t\t\tThank you for using our library,Hope to see you again :)");
                            fl=fopen("Borrow.txt","rb");
        //fseek(fl,0,SEEK_SET);
                        while(fread(&a, sizeof(a), 1, fl) == 1){


                        if(strcmp(a.bookid,id)==0){

                                e=0;
                        }else{

                            continue;
                        }
                    }
                    if(e==0){
                    daysinfeb = 28;

                    doy = a.borrowdate.dd;

                    if( (a.borrowdate.yy % 4 == 0 && a.borrowdate.yy % 100 != 0 ) || (a.borrowdate.yy % 400 == 0) )
                    {
                        daysinfeb = 29;
                    }

                    switch(a.borrowdate.mm)
                    {
                        case 2:
                            doy += 31;
                            break;
                        case 3:
                            doy += 31+daysinfeb;
                            break;
                        case 4:
                            doy += 31+daysinfeb+31;
                            break;
                        case 5:
                            doy += 31+daysinfeb+31+30;
                            break;
                        case 6:
                            doy += 31+daysinfeb+31+30+31;
                            break;
                        case 7:
                            doy += 31+daysinfeb+31+30+31+30;
                            break;
                        case 8:
                            doy += 31+daysinfeb+31+30+31+30+31;
                            break;
                        case 9:
                            doy += 31+daysinfeb+31+30+31+30+31+31;
                            break;
                        case 10:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30;
                            break;
                        case 11:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31;
                            break;
                        case 12:
                            doy += 31+daysinfeb+31+30+31+30+31+31+30+31+30;
                            break;
                    }
                    daysborrow=doy;

                    if(strcmp(a.type,"Golden")==0)
                    {
                        difday=daysreturn-daysborrow;
                        duration=84;
                        if(difday>duration){
                            printf("\n\n\n\t\t\t\xB2\xB2\ Dear Golden user,You  have exceeded your return time of %ddays\nYou will have to pay a fee of 5000f",difday-duration);
                        }
                        else
                            printf("\n\n\n\t\t\tThank you for using our library, You submited the book in time :)");

                    }
                    else if(strcmp(a.type,"Regular")==0)
                    {
                        duration=28;
                        if(difday>duration){
                            printf("\n\n\n\t\t\t\xB2\xB2\ Dear Regulat user,You  have exceeded your return time of %ddays\nYou will have to pay a fee of 10000f",difday-duration);
                        }
                        else
                            printf("\n\n\n\t\t\tThank you for using our library, You submited the book in time :)");
                    }

                    fclose(fl);
                    }



                        printf("\n\n\n\t\t\t Enter any key to continue.....");
                        getch();
                        usermenu();


}

