#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>

typedef struct Person
{
    int personid;
    char name[20];
    char last_name[20];
    char adress[30];
    char contact[9];
    struct Person *next;
} Person;

Person *head_Person = NULL,*current_Person = NULL, *temp = NULL;
void WelcomeScreen(void)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#                WITAJ                  #");
    printf("\n\t\t\t\t#         W KSIAZCE TELEFONICZNEJ       #");
    printf("\n\t\t\t\t#                                       #");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\n\n Wcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
    system("cls");

}

void Title(void)
{
    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\t\t\t\t         KSIAZKA TELEFONICZNA        ");
    printf("\n\t\t----------------------------------------------------------------------------------\n\n\n");
}
void writePersonFile()
{
    FILE *fp = fopen("Person.txt","w");

    for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
    {
        fprintf (fp, "%d;%s;%s;%s;%s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->contact, current_Person->adress );
    }


    fclose (fp);
    printf("\n\n\nZapis sie udal!\n");
}
void displayPerson()
{
    system("cls");
    Title();
    printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
    printf("--------------------------------------------------------------------------------------------\n");
    for(current_Person =head_Person; current_Person; current_Person = current_Person->next)
        printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
    printf("--------------------------------------------------------------------------------------------\n");
}
int maxpersonid()
{
    current_Person=head_Person;
    int max=0;
    while (current_Person->next!=NULL)
    {
        max=current_Person->personid;
        current_Person = current_Person->next;
    }
    return max+1;
}
void modifyPerson()
{

    system("cls");
    int valid=0,i;
    char choose[1];
    while(!valid)
    {
        choose[0]=' ';
choose[1]=' ';
        Title();
        displayPerson();
        Person t;
        int waga=0;
        int idss;

        while(!valid)
        {
            printf ("\n\n\t\t\t\tWprowadz ID osoby do modyfikacji : ");
            scanf("%d", &idss) ;
            if(idss>=1&&idss<=maxpersonid())
            {
                valid =1;
            }
            else
            {


                printf("\t\t\t\tPodaj poprawne id osoby");
                fflush(stdin);
            }

        }
        current_Person=head_Person;
        while (current_Person->next!=NULL&&waga==0)
        {
            if(current_Person->personid == idss)
            {
                waga=1;
            }
            else
                current_Person = current_Person->next;
        }
        valid=0;
        printf("\n\t\t\t\tPo jakim polu chcesz edytowac?");
        printf("\n\n\t\t\t\t0. Wroc\n");
        printf("\n\t\t\t\t1. Imie\n");
        printf("\n\t\t\t\t2. Nazwisko\n");
        printf("\n\t\t\t\t3. Adres\n");
        printf("\n\t\t\t\t4. Numer telefonu\n");
        printf("\n\n\n \n\t\t\t\tWprowadz opcje od 0 a 4:");
        scanf("%s", choose);
        fflush(stdin);



         if(choose[0]==48&&choose[1]=='\0')
            valid=1;


        else  if(choose[0]==49&&choose[1]=='\0')
        {


            while(!valid)
            {


                printf("\n\t\t\tWprowadz imie: ");
                scanf("%s",t.name);
                t.name[0]=toupper(t.name[0]);
                if(!(strlen(t.name)<=20&&strlen(t.name)>=2))
                {
                    printf("\n\tBlad! Wprowadz imie z przedzialu od 2 do 20 liter");

                }
                else
                {
                    for (i=0; i<strlen(t.name); i++)
                    {
                        if (isalpha(t.name[i]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            break;
                        }
                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj poprawnych liter przy imieniu  Sproboj ponownie :)");

                    }
                }
            }
            char ans[1];
            while((!(ans[0]=='T'||ans[0]=='N')))
            {
                printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
                fflush(stdin);
                scanf("%s",ans);
                if(ans[1]=='\0')
                {
                    ans[0] = toupper(ans[0]);

                }
                else
                    fflush(stdin);

                if(ans[0]=='T')
                {
                    strcpy(current_Person->name,t.name);
                    writePersonFile();
                }
                else
                    fflush(stdin);
            }
            break;
        }

        else  if(choose[0]==50&&choose[1]=='\0')
        {
            valid=0;
            while(!valid)
            {


                printf("\n\t\t\tWprowadz nazwisko: ");
                scanf("%s",t.last_name);
                fflush(stdin);
                t.last_name[0]=toupper(t.last_name[0]);
                if(!(strlen(t.last_name)<=20&&strlen(t.last_name)>=2))
                {
                    printf("\n\tBlad! Wprowadz nazwisko z przedzialu od 2 do 20 liter");

                }
                else
                {
                    for (i=0; i<strlen(t.last_name); i++)
                    {
                        if (isalpha(t.last_name[i]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            break;
                        }
                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj poprawnych liter przy nazwisku  Sproboj ponownie :)");

                    }
                }
            }
            char ans[1];
            while((!(ans[0]=='T'||ans[0]=='N')))
            {
                printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
                fflush(stdin);
                scanf("%s",ans);
                if(ans[1]=='\0')
                {
                    ans[0] = toupper(ans[0]);

                }
                else
                    fflush(stdin);

                if(ans[0]=='T')
                {
                    strcpy(current_Person->last_name,t.last_name);
                    writePersonFile();
                }
                else
                    fflush(stdin);
            }
            break;
        }
        else  if(choose[0]==51&&choose[1]=='\0')
        {
            valid=0;
            fflush(stdin);
            while(!valid)
            {
                printf("\n\t\t\tWprowadz adres : ");
                fgets(t.adress, 32, stdin);
                strtok(t.adress,"\n");
                t.adress[0]=toupper(t.adress[0]);
                if(!(strlen(t.adress)<=30&&strlen(t.adress)>=4))
                {
                    printf("\n\tBlad! Wprowadz adres z przedzialu od 4 do 30 liter");
                    fflush(stdin);
                    valid=0;
                }
                else
                {


                    valid=1;

                }
            }
            char ans[1];
            while((!(ans[0]=='T'||ans[0]=='N')))
            {
                printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
                fflush(stdin);
                scanf("%s",ans);
                if(ans[1]=='\0')
                {
                    ans[0] = toupper(ans[0]);

                }
                else
                    fflush(stdin);

                if(ans[0]=='T')
                {
                    strcpy(current_Person->adress,t.adress);
                    writePersonFile();
                }
                else
                    fflush(stdin);
            }
            break;
        }
        else  if(choose[0]==52&&choose[1]=='\0')
        {


            fflush(stdin);
            valid=0;
            char pcontact[9];
            while(!valid)
            {
                printf("\n\t\t\tWprowadz numer telefonu : ");
                scanf("%s",pcontact);
                if(!(strlen(pcontact)==9))


                {
                    printf("\n\tBlad! Wprowadz numer telefonu o dlugosci 9 cyfr");
                    fflush(stdin);

                }

                else
                {
                    for (i=0; i<strlen(pcontact); i++)
                    {
                        if (!isalpha(pcontact[i]))
                        {
                            valid=1;

                        }
                        else
                        {
                            valid=0;
                            break;
                        }



                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj cyfr przy wprowadzaniu numeru telefonu  Sproboj ponownie :)");
                        fflush(stdin);

                    }
                }

            }
            char ans[1];
            while((!(ans[0]=='T'||ans[0]=='N')))
            {
                printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
                fflush(stdin);
                scanf("%s",ans);
                if(ans[1]=='\0')
                {
                    ans[0] = toupper(ans[0]);

                }
                else
                    fflush(stdin);

                if(ans[0]=='T')
                {
                    strcpy(current_Person->contact,t.contact);
                    writePersonFile();
                }
                else
                    fflush(stdin);
            }
        }
        else
        {


            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            fflush(stdin);
            getch();
            system("cls");
        }
        }





    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
}
void searchPerson()
{
    system("cls");

    int pid;
    char pname[30];
    char plast_name[30];
    char padress[30];
    char pcontact[9];
    int valid=0;
    char choose[1];
    while(!valid)
    {
        choose[0]=' ';
choose[1]=' ';
        Title();
        displayPerson();
        printf("\n\n\t\t\t\tPo jakim polu chcesz znalezc?");
        printf("\n\n\t\t\t\t0. Wroc\n");
        printf("\n\t\t\t\t1. Id\n");
        printf("\n\t\t\t\t2. Imie\n");
        printf("\n\t\t\t\t3. Nazwisko\n");
        printf("\n\t\t\t\t4. Adres\n");
        printf("\n\t\t\t\t5. Numer telefonu\n");
        printf("\n\n\n \n\t\t\t\tWprowadz opcje od 0 a 5:");
        scanf("%s", choose);

        if(choose[0]==48&&choose[1]=='\0')
        {


            valid=1;
            break;
        }
        else if(choose[0]==49&&choose[1]=='\0')
        {
            while(!valid)
            {
                printf ("\n\nWprowadz ID szukanej osoby : ");
                scanf("%d", &pid) ;
                if(pid>=1&&pid<=maxpersonid())
                {
                    valid =1;
                }
                else
                {


                    printf("Podaj poprawne id osoby");
                    fflush(stdin);
                }

            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(current_Person->personid == pid)
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
                }
                current_Person = current_Person->next;
            }
            printf("--------------------------------------------------------------------------------------------\n");
            valid=1;
            break;
        }


        else if(choose[0]==50&&choose[1]=='\0')
        {


            int valid=0,i;
            while(!valid)
            {

                printf("\n\n\n\t\t\tWprowadz imie: ");
                scanf("%s",pname);
                fflush(stdin);

                if(!(strlen(pname)<=20&&strlen(pname)>=2))
                {
                    printf("\n\tBlad! Wprowadz imie z przedzialu od 2 do 20 liter");

                }
                else
                {
                    for (i=0; i<strlen(pname); i++)
                    {
                        if (isalpha(pname[i]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            break;
                        }
                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj poprawnych liter przy imieniu  Sproboj ponownie :)");

                    }
                }
            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->name, pname))
                {

                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);

                }
                else if(!strncmp(current_Person->name, pname,strlen(pname)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
                }
                current_Person = current_Person->next;
            }
            printf("--------------------------------------------------------------------------------------------\n");
                valid=1;
        break;
        }


        else if(choose[0]==51&&choose[1]=='\0')
        {
            valid=0;
            int i;
            while(!valid)
            {


                printf("\n\t\t\tWprowadz nazwisko: ");
                scanf("%s",plast_name);
                fflush(stdin);
                if(!(strlen(plast_name)<=20&&strlen(plast_name)>=2))
                {
                    printf("\n\tBlad! Wprowadz nazwisko z przedzialu od 2 do 20 liter");

                }
                else
                {
                    for (i=0; i<strlen(plast_name); i++)
                    {
                        if (isalpha(plast_name[i]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            break;
                        }
                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj poprawnych liter przy nazwisku  Sproboj ponownie :)");

                    }
                }
            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->last_name, plast_name))
                {

                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);

                }
                else if(!strncmp(current_Person->last_name, plast_name,strlen(plast_name)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
                }
                current_Person = current_Person->next;
            }
            printf("--------------------------------------------------------------------------------------------\n");
            valid=1;
            break;
        }



        else if(choose[0]==52&&choose[1]=='\0')
        {
            fflush(stdin);
            valid=0;
            while(!valid)
            {
                printf("\n\t\t\tWprowadz adres : ");
                fgets(padress, 32, stdin);
                strtok(padress,"\n");
                if(!(strlen(padress)<=30&&strlen(padress)>=4))
                {
                    printf("\n\tBlad! Wprowadz adres z przedzialu od 4 do 30 liter");
                    fflush(stdin);
                    valid=0;
                }
                else
                {


                    valid=1;

                }
            }
            current_Person = head_Person;

            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");

            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->adress,padress))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
                }
                else if(!strncmp(current_Person->adress, padress,strlen(padress)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);
                }
                current_Person = current_Person->next;
            }
            printf("--------------------------------------------------------------------------------------------\n");
            valid=1;
            break;
        }
        else if(choose[0]==53&&choose[1]=='\0')
        {
            int i;
            valid=0;
            while(!valid)
            {
                printf("\n\t\t\tWprowadz numer telefonu : ");
                scanf("%s",pcontact);
                if(!(strlen(pcontact)==9))


                {
                    printf("\n\tBlad! Wprowadz numer telefonu o dlugosci 9 cyfr");
                    fflush(stdin);

                }

                else
                {
                    for (i=0; i<strlen(pcontact); i++)
                    {
                        if (!isalpha(pcontact[i]))
                        {
                            valid=1;

                        }
                        else
                        {
                            valid=0;
                            break;
                        }



                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj cyfr przy wprowadzaniu numeru telefonu  Sproboj ponownie :)");
                        fflush(stdin);

                    }
                }

            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->contact,pcontact))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->adress,current_Person->contact);


                }
                current_Person = current_Person->next;
            }
            printf("--------------------------------------------------------------------------------------------\n");
            valid=1;
            break;
        }
        else
        {


            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            fflush(stdin);
            getch();

        }



    }
    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();

}
void sort_help()
{
    char x[100];
    int idd;
    idd = temp->personid;
    temp->personid = temp->next->personid;
    temp->next->personid = idd;

    strcpy(x,temp->name);
    strcpy(temp->name,temp->next->name);
    strcpy(temp->next->name,x);

    strcpy(x,temp->last_name);
    strcpy(temp->last_name,temp->next->last_name);
    strcpy(temp->next->last_name,x);

    strcpy(x,temp->adress);
    strcpy(temp->adress,temp->next->adress);
    strcpy(temp->next->adress,x);

    strcpy(x,temp->contact);
    strcpy(temp->contact,temp->next->contact);
    strcpy(temp->next->contact,x);
}
int deletePerson()
{
    system("cls");
    Title();
    displayPerson();
    Person t;
    int found=0,valid=0;
    printf("\n\t\t\t\tW przypadku checi powrotu wstecz wpisz 0");
    while(!valid)
    {
        printf ("\n\n\t\t\t\tWprowadz ID osoby do usuniecia : ");

        scanf("%d", &t.personid) ;
        if( t.personid==0)
        {
            valid=1;
            break;
            return 2;

        }
        current_Person=head_Person;
        if(t.personid>=current_Person->personid&&t.personid<=maxpersonid())
        {
            current_Person=head_Person;

            while(current_Person)
            {
                if(t.personid==current_Person->personid)
                {
                    valid=1;
                }
                current_Person=current_Person->next;
            }
            if(!valid)
            {

            printf("\n\t\t\t\tPodaj poprawne id osoby");
            }
        }
        else
        {


            printf("\n\t\t\t\tPodaj poprawne id osoby");
            fflush(stdin);
        }

    }
    if(t.personid !=0)
    {
        char ans[2];
        while(!(ans[0]=='T'||ans[0]=='N'))
        {
            printf("\n\t\t\t\tCzy jestes pewny/pewna usuniecia? T/N :");
            fflush(stdin);
            scanf("%s",ans);
            if(ans[1]=='\0')
            ans[0] = toupper(ans[0]);

        }
            if(ans[0]=='T')
            {
                current_Person = head_Person;
                if(current_Person->personid == t.personid)
                {
                    head_Person = current_Person -> next;
                    free (current_Person);
                    found=1;

                }

                while (current_Person->next!=NULL)
                {
                    Person *tmp = current_Person -> next;
                    if(tmp->personid==t.personid)
                    {
                        current_Person -> next=tmp->next;
                        free(tmp);
                        found=1;
                        break;
                    }
                    current_Person = current_Person->next;
                }

                if (found)
                {
                    printf("\n\n\t\t\t\tOsoba usunieta poprawnie....!");
                    writePersonFile();
                }
                else
                {
                    printf("\n\n\t\t\t\tNie udalo sie usunac osoby");



                }
            }
            else
                fflush(stdin);
        }


    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
        return 1;
}
int autoIncrementPerson()
{
    int id=1;
    temp = head_Person;
    //struct node* end = NULL;

    while(temp->next != NULL)
    {
        temp = temp->next;

    }
    temp = head_Person;
    for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
    {
        temp = head_Person;
        while(temp->next != NULL)
        {

            if(temp->personid>temp->next->personid)
            {
                int idd;
                idd = temp->personid;
                temp->personid = temp->next->personid;
                temp->next->personid = idd;

            }
            temp = temp->next;
        }
        //end = temp;
    }
    temp = head_Person;
    for(current_Person=head_Person; current_Person; current_Person=current_Person->next,id++)
        if(id!=current_Person->personid)
        {


            return id;
        }
    return id;
}
void id_sort()
{

    temp = head_Person;
    //struct node* end = NULL;

    while(temp->next != NULL)
    {
        temp = temp->next;

    }
    temp = head_Person;
    for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
    {
        temp = head_Person;
        while(temp->next != NULL)
        {

            if(temp->personid>temp->next->personid)
            {
                sort_help();
            }
            temp = temp->next;
        }
        //end = temp;
    }
    temp = head_Person;
}
int addPerson()
{
    system("cls");
    Title();
    Person t, * node;
    int valid=0,i;
    printf("\n\t\t\t\tW przypadku checi powrotu wstecz wpisz 0");
    node = (Person*)malloc (sizeof (Person));
    while(!valid)
    {


        printf("\n\n\n\t\t\tWprowadz imie: ");
        scanf("%s",t.name);
        fflush(stdin);
        t.name[0]=toupper(t.name[0]);
        if( !strcmp(t.name,"0"))
        {
            printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
            getch();
            return 2;
        }
        if(!(strlen(t.name)<=20&&strlen(t.name)>=2))
        {
            printf("\n\tBlad! Wprowadz imie z przedzialu od 2 do 20 liter");

        }
        else
        {
            for (i=0; i<strlen(t.name); i++)
            {
                if (isalpha(t.name[i]))
                {
                    valid=1;
                    strcpy(node->name,t.name);
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\tUzyj poprawnych liter przy imieniu  Sproboj ponownie :)");

            }
        }
    }

    //fflush(stdin);
    valid=0;
    while(!valid)
    {


        printf("\n\t\t\tWprowadz nazwisko: ");
        scanf("%s",t.last_name);
        fflush(stdin);
        t.last_name[0]=toupper(t.last_name[0]);
        if(!(strlen(t.last_name)<=20&&strlen(t.last_name)>=2))
        {
            printf("\n\tBlad! Wprowadz nazwisko z przedzialu od 2 do 20 liter");

        }
        else
        {
            for (i=0; i<strlen(t.last_name); i++)
            {
                if (isalpha(t.last_name[i]))
                {
                    valid=1;
                    strcpy(node->last_name,t.last_name);
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\tUzyj poprawnych liter przy nazwisku  Sproboj ponownie :)");

            }
        }
    }
    fflush(stdin);
    valid=0;
    while(!valid)
    {
        printf("\n\t\t\tWprowadz adres : ");
        fgets(t.adress, 32, stdin);
        strtok(t.adress,"\n");
        t.adress[0]=toupper(t.adress[0]);
        if(!(strlen(t.adress)<=30&&strlen(t.adress)>=4))
        {
            printf("\n\tBlad! Wprowadz adres z przedzialu od 4 do 30 liter");
            fflush(stdin);
            valid=0;
        }
        else
        {


            valid=1;
            strcpy(node->adress,t.adress);
        }
    }
    fflush(stdin);
    valid=0;
    char pcontact[9];
    while(!valid)
    {
        printf("\n\t\t\tWprowadz numer telefonu : ");
        scanf("%s",pcontact);
        if(!(strlen(pcontact)==9))


        {
            printf("\n\tBlad! Wprowadz numer telefonu o dlugosci 9 cyfr");
            fflush(stdin);

        }

        else
        {
            for (i=0; i<strlen(pcontact); i++)
            {
                if (!isalpha(pcontact[i]))
                {
                    valid=1;
                    strcpy(node->contact,pcontact);

                }
                else
                {
                    valid=0;
                    break;
                }



            }
            if(!valid)
            {
                printf("\n\tUzyj cyfr przy wprowadzaniu numeru telefonu  Sproboj ponownie :)");
                fflush(stdin);

            }
        }

    }


    fflush(stdin);
    char ans[1];
    while((!(ans[0]=='T'||ans[0]=='N')))
    {
        printf("\n\t\t\tCzy na pewno chcesz zapisac ta osobe? T/N :");
        scanf("%s",ans);

        if(ans[1]=='\0')
        {
            ans[0] = toupper(ans[0]);

        }
        else
            fflush(stdin);
    }
    if(ans[0]=='T')
    {

        node->personid = autoIncrementPerson();




        node->next = NULL;

        if(head_Person==NULL)
        {
            head_Person = node;
        }
        else
        {
            current_Person=head_Person;
            while(current_Person->next!=NULL)
                current_Person = current_Person -> next;
            current_Person -> next = node;
        }
        id_sort();
        writePersonFile();
        fflush(stdin);
    }

    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
    return 2;
}
void readPersonFile()
{

    head_Person = NULL,current_Person = NULL;

    FILE *fp = fopen("Person.txt","r");

    Person tl, *node;

    while (fscanf (fp,"%d;%[^;];%[^;];%[^;];%[^;\n]", &tl.personid, tl.name,tl.last_name,tl.contact,tl.adress)!=EOF)
    {

        node = (Person*)malloc (sizeof (Person) );
        node->personid = tl.personid;
        strcpy(node->name,tl.name) ;
        strcpy(node->last_name,tl.last_name);
        strcpy(node->adress,tl.adress) ;
        strcpy(node->contact,tl.contact) ;
        node->next = NULL;
        if(head_Person == NULL)
        {
            current_Person = head_Person =node;
        }
        else
        {
            current_Person = current_Person -> next = node;
        }
    }
    fclose(fp);

}
void sort()
{
    system("cls");
    int valid = 0,falid=0;
    while(!valid&&!falid)
    {
        Title();

        char choose[2];
        printf("\t\t\t\tPo jakim polu chcesz posortowac?");
        printf("\n\n\t\t\t\t0. Wroc\n");
        printf("\n\t\t\t\t1. Id w gore\n");
        printf("\n\t\t\t\t2. Id w dol\n");
        printf("\n\t\t\t\t3. Imie alfabetycznie w gore\n");
        printf("\n\t\t\t\t4. Imie alfabetycznie w dol\n");
        printf("\n\t\t\t\t5. Nazwisko alfabetycznie w gore\n");
        printf("\n\t\t\t\t6. Nazwisko alfabetycznie w dol\n");
        printf("\n\t\t\t\t7. Numer telefonu w gore\n");
        printf("\n\t\t\t\t8. Numer telefonu w dol\n");
        printf("\n\t\t\t\t9. Adresy alfabetycznie w gore\n");
        printf("\n\t\t\t\t10. Adresy alfabetycznie w dol\n");
        printf("\n\n\n \n\t\t\t\tWprowadz opcje pomiedzy 0 a 10:");
        scanf("%s", choose);

        if(choose[0]==48&&choose[1]=='\0'){
            valid=1;
            falid=1;
            break;
        }
        else  if(choose[0]==49&&choose[1]=='\0')
        {
            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {

                    if(temp->personid<temp->next->personid)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;

            break;


        }
        else  if(choose[0]==50&&choose[1]=='\0')
        {
            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {

                    if(temp->personid>temp->next->personid)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==51&&choose[1]=='\0')
        {

            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->name,temp->next->name) > 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;


            break;
        }
        else  if(choose[0]==52&&choose[1]=='\0')
        {

            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->name,temp->next->name) < 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;


            break;
        }
        else  if(choose[0]==53&&choose[1]=='\0')
        {
            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->last_name,temp->next->last_name) > 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
       else  if(choose[0]==54&&choose[1]=='\0')
        {
            temp = head_Person;
            //struct node* end = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;

            }
            temp = head_Person;
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->last_name,temp->next->last_name) < 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==55&&choose[1]=='\0')
        {

            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->contact,temp->next->contact) > 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==58&&choose[1]=='\0')
        {

            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->contact,temp->next->contact) < 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==59&&choose[1]=='\0')
        {

            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->adress,temp->next->adress) > 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[1]==48&&choose[0]==49&&choose[2]=='\0')
        {

            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->adress,temp->next->adress) < 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
                //end = temp;
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else
        {


            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            fflush(stdin);
            getch();
            system("cls");
        }

    }
    if(!falid)
    {
        displayPerson();
        temp = head_Person;
        //struct node* end = NULL;

        while(temp->next != NULL)
        {
            temp = temp->next;

        }
        temp = head_Person;
        for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
        {
            temp = head_Person;
            while(temp->next != NULL)
            {

                if(temp->personid>temp->next->personid)
                {
                    sort_help();
                }
                temp = temp->next;
            }
            //end = temp;
        }
        temp = head_Person;
    }
    current_Person = head_Person;
    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
}
void MainMenu(void)
{
    WelcomeScreen();

    readPersonFile();
    while(1)
    {
        system("cls");

        char choose[1];
choose[0]=' ';
choose[1]=' ';
        Title();
        printf("\n\n\n\n\n\t\t\t\t1. Dodawanie do ksiazki telefonicznej\n");
        printf("\n\t\t\t\t2. Lista osob z numerami\n");
        printf("\n\t\t\t\t3. Szukaj osoby w ksiazce\n");
        printf("\n\t\t\t\t4. Edytowanie osoby wprowadzonej\n");
        printf("\n\t\t\t\t5. Usuwanie osoby z ksiazki\n");
        printf("\n\t\t\t\t6. Sortuj osoby w ksiazce po danym polu\n");
        printf("\n\t\t\t\t7. Wyjscie\n");
        printf("\n\n\n \n\t\t\t\tWybierz od 1 do 7:");
        scanf("%s", choose);

        if(choose[0]==49&&choose[1]=='\0')
        {


            addPerson();
            break;
        }

        else  if(choose[0]==50&&choose[1]=='\0')
        {


            displayPerson();
            printf("\n\nWcisnij dowolny klawisz zeby kontynuowac......\n");
            getch();
        }
         else  if(choose[0]==51&&choose[1]=='\0')
            searchPerson();

         else  if(choose[0]==52&&choose[1]=='\0')
            modifyPerson();

         else  if(choose[0]==53&&choose[1]=='\0')
            deletePerson();

        else  if(choose[0]==54&&choose[1]=='\0')
            sort();

         else  if(choose[0]==51&&choose[1]=='\0')
         {


            printf("\t\t\t\tDziekuje za skorzystanie z ksiazki");
            getch();
            exit(0);
         }

        else
        {


            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            fflush(stdin);
            getch();
        }
        }
        Sleep(500);
    }
int main()
{
    MainMenu();
    return 0;
}
