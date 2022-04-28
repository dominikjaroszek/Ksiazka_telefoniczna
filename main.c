#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

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
    printf("\n\n\n\n\n Wcisnij dowolny klawisz zeby kontynuowac......\n");
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
        fprintf (fp, "%d; %s; %s; %s; %s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->contact, current_Person->adress );
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
void modifyPerson()
{
    system("cls");
        int choose,valid=0,i;
    while(!valid){
    Title();
    displayPerson();
    Person t;
    int waga=0;
int idss;
    printf ("\n\nWprowadz ID osoby do modyfikacji : ");
    scanf("%d", &idss) ;
current_Person=head_Person;
    while (current_Person!=NULL&&waga==0)
    {
        if(current_Person->next->personid == idss)
        {
            waga=1;
        }
        current_Person = current_Person->next;
    }



    printf("Po jakim polu chcesz edytowac?");
    printf("\n\n\n\n\n\t\t\t\t0. Wroc\n");
    printf("\n\t\t\t\t1. Imie\n");
    printf("\n\t\t\t\t2. Nazwisko\n");
    printf("\n\t\t\t\t3. Adres\n");
    printf("\n\t\t\t\t4. Numer telefonu\n");
    printf("\n\n\n \n\t\t\t\tWprowadz opcje od 0 a 4:");
    scanf("%d", &choose);
    fflush(stdin);
    switch(choose)
{


case 0:
    valid=1;
    break;
    case 1:
        {


            while(!valid)
            {


                printf("\n\t\t\tWprowadz imie: ");
                scanf("%s",t.name);
                t.name[0]=toupper(t.name[0]);
                if(strlen(t.name)>20||strlen(t.name)<2)
                {
                    printf("\n\t Blad! Wprowadz imie z przedzialu od 2 do 20 liter");

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
                        printf("\n\t\t Uzyj poprawnych liter przy imieniu :(  Sproboj ponownie :)");

                    }
                }
    }
    char ans;
while(!(ans=='T'||ans=='N'))
    {
    printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
    fflush(stdin);
    scanf("%c",&ans);
    ans = toupper(ans);
    }
    if(ans=='T')
    {
         strcpy(current_Person->name,t.name);
          writePersonFile();
    }
break;
        }

            case 2 :
                {
valid=0;
            while(!valid)
            {


                printf("\n\t\t\tWprowadz nazwisko: ");
                scanf("%s",t.last_name);
                t.last_name[0]=toupper(t.last_name[0]);
                if(strlen(t.last_name)>20||strlen(t.last_name)<2)
                {
                    printf("\n\t Blad! Wprowadz nazwisko z przedzialu od 2 do 20 liter :>");

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
                        printf("\n\t\t Uzyj poprawnych liter przy nazwisku :(  Sproboj ponownie :)");

                    }
                }
            }
            char ans;
    while(!(ans=='T'||ans=='N'||valid==0))
    {
    printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
    fflush(stdin);
    scanf("%c",&ans);
    ans = toupper(ans);
    }
    if(ans=='T')
    {
         strcpy(current_Person->last_name,t.last_name);
          writePersonFile();
    }
            fflush(stdin);
            break;
                }
            case 3:
                {
            valid=0;
            while(!valid)
            {
                printf("\n\t\t\tWprowadz adres : ");
                fgets(t.adress, 30, stdin);
                strtok(t.adress,"\n");
                t.adress[0]=toupper(t.adress[0]);
                if(strlen(t.adress)>30||strlen(t.adress)<4)
                {
                    printf("\n\t Blad! Wprowadz adres z przedzialu od 4 do 30 liter :>");
                    valid=0;
                }
                valid=1;
            }
                        char ans;
while(!(ans=='T'||ans=='N'))
    {
    printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
    fflush(stdin);
    scanf("%c",&ans);
    ans = toupper(ans);
    }
    if(ans=='T')
    {
        strcpy(current_Person->adress,t.adress);
          writePersonFile();
    }
    fflush(stdin);
break;
                }
            case 4:
                {


            fflush(stdin);
            valid=0;
            while(!valid)
            {
                printf("\n\t\t\tWprowadz numer telefonu : ");
                scanf ("%s", t.contact);
                if(strlen(t.contact)>9||strlen(t.contact)!=9)
                {
                    printf("\n\t Blad! Wprowadz numer telefonu o dlugosci 9 cyfer :>");

                }
                else
                {
                    for (i=0; i<strlen(t.contact); i++)
                    {
                        if (!isalpha(t.contact[i]))
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
                        printf("\n\t\t Uzyj cyfer przy wprowadzaniu numeru telefonu :(  Sproboj ponownie :)");

                    }
                }

            }
                            char ans;
while(!(ans=='T'||ans=='N'))
    {
    printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
    fflush(stdin);
    scanf("%c",&ans);
    ans = toupper(ans);
    }
    if(ans=='T')
    {
        strcpy(current_Person->contact,t.contact);
         writePersonFile();
    }
fflush(stdin);
break;
                }
                        default:
                            {


printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
fflush(stdin);
getch();
system("cls");
                            }
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
    int choose,valid=0;
    while(!valid){
                Title();
    displayPerson();
    printf("Po jakim polu chcesz znalezc?");
    printf("\n\n\n\n\n\t\t\t\t0. Wroc\n");
    printf("\n\t\t\t\t1. Id\n");
    printf("\n\t\t\t\t2. Imie\n");
    printf("\n\t\t\t\t3. Nazwisko\n");
    printf("\n\t\t\t\t4. Adres\n");
    printf("\n\t\t\t\t5. Numer telefonu\n");
    printf("\n\n\n \n\t\t\t\tWprowadz opcje od 0 a 5:");
    scanf("%d", &choose);
    switch(choose)
    {

    case 0:
        valid=1;
        break;

    case 1:
    {
        printf ("Wprowadz id : ");
        scanf("%d", &pid) ;
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


    case 2:
    {

        printf ("Wprowadz imie : ");
        scanf("%s", pname) ;
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
    }
    break;

    case 3:
    {
        printf ("Wprowadz nazwisko : ");
        scanf("%s", plast_name) ;
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



    case 4:
    {
        printf ("Wprowadz adres : ");
        fflush(stdin);
        fgets(padress, 30, stdin);
        strtok(padress,"\n");
        //fflush(stdin);
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
    case 5:
    {
        printf ("Wprowadz numer telefonu : ");
        //scanf("%s", pcontact) ;
        fflush(stdin);
        fgets(pcontact, 10, stdin);
        strtok(pcontact,"\n");
        fflush(stdin);
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
                            default:
                            {


printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
fflush(stdin);
getch();

    }


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
void deletePerson()
{
    system("cls");
    Title();
    displayPerson();
    int pid, found=0;
    printf("\n\t\t\t\tW przypadku checi powrotu wstecz wpisz 0");
    printf ("\n\n\t\tWprowadz Id osoby do usuniecia : ");
    scanf("%d", &pid) ;
    if(pid !=0)
    {

        char ans;
while(!(ans=='T'||ans=='N'))
    {
    printf("Czy jestes pewny/pewna usuniecia? T/N :");
    fflush(stdin);
    scanf("%c",&ans);
    ans = toupper(ans);
    }
        if(ans=='T')
        {
            current_Person = head_Person;
            if(current_Person->personid == pid)
            {
                head_Person = current_Person -> next;
                free (current_Person);
                found=1;

            }

            while (current_Person->next!=NULL)
            {
                Person *tmp = current_Person -> next;
                if(tmp->personid==pid)
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
                printf("\n\nOsoba usunieta poprawnie....!");
                writePersonFile();
            }
            else
            {
                printf("Nie udalo sie usunac osoby");



            }
        }
    }

    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
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
    while(!valid)
    {

        printf("\n\t\t\t\tW przypadku checi powrotu wstecz wpisz 0");
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
        if(strlen(t.name)>20||strlen(t.name)<2)
        {
            printf("\n\t Blad! Wprowadz imie z przedzialu od 2 do 20 liter");

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
                printf("\n\t\t Uzyj poprawnych liter przy imieniu :(  Sproboj ponownie :)");

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
        if(strlen(t.last_name)>20||strlen(t.last_name)<2)
        {
            printf("\n\t Blad! Wprowadz nazwisko z przedzialu od 2 do 20 liter :>");

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
                printf("\n\t\t Uzyj poprawnych liter przy nazwisku :(  Sproboj ponownie :)");

            }
        }
    }
    fflush(stdin);
    valid=0;
    while(!valid)
    {
        printf("\n\t\t\tWprowadz adres : ");
        fgets(t.adress, 30, stdin);
        strtok(t.adress,"\n");
        t.adress[0]=toupper(t.adress[0]);
        if(strlen(t.adress)>30||strlen(t.adress)<4)
        {
            printf("\n\t Blad! Wprowadz adres z przedzialu od 4 do 30 liter :>");

        }
         else
        {
            for (i=0; i<strlen(t.adress); i++)
            {
                if (isalnum(t.adress[i]))
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
                printf("\n\t\t Uzyj poprawnych znakow przy adresie :(  Sproboj ponownie :)");

            }
    }
    }
    fflush(stdin);
    valid=0;
    while(!valid)
    {
        printf("\n\t\t\tWprowadz numer telefonu : ");
        scanf ("%s", t.contact);
        fflush(stdin);
        if(strlen(t.contact)>9||strlen(t.contact)!=9)


        {
            printf("\n\t Blad! Wprowadz numer telefonu o dlugosci 9 cyfr");

            continue;

        }

        else
        {
            for (i=0; i<strlen(t.contact); i++)
            {
                if (!isalpha(t.contact[i]))
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
                printf("\n\t\t Uzyj cyfer przy wprowadzaniu numeru telefonu :(  Sproboj ponownie :)");

            }
        }



    }
    fflush(stdin);
    char ans;
    while(!(ans=='T'||ans=='N'))
    {
    printf("Czy na pewno chcesz zapisac ta osobe? T/N :");
    scanf("%c",&ans);
    ans = toupper(ans);
    }
    if(ans=='T')
    {
        node = (Person*)malloc (sizeof (Person));
        node->personid = autoIncrementPerson();
        strcpy(node->name,t.name);
        strcpy(node->adress,t.adress);
        strcpy(node->last_name,t.last_name);
        strcpy(node->contact,t.contact);
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

    while (fscanf (fp,"%d; %[^;]; %[^;]; %[^;]; %[^;\n]", &tl.personid, tl.name,tl.last_name,tl.contact,tl.adress)!=EOF)
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
    int valid = 0;
    while(!valid){
    Title();

    int choose;
    printf("Po jakim polu chcesz posortowac?");
    printf("\n\n\n\n\n\t\t\t\t0. Wroc\n");
    printf("\n\t\t\t\t1. Id\n");
    printf("\n\t\t\t\t2. Imie\n");
    printf("\n\t\t\t\t3. Nazwisko\n");
    printf("\n\t\t\t\t4. Numer telefonu\n");
    printf("\n\n\n \n\t\t\t\tWprowadz opcje od 0 a 4:");
    scanf("%i", &choose);
    switch(choose)
    {
    case 0:
        valid=1;
        break;
    case 1:
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
    case 2:
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
    case 3:
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
    case 4:
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
                        default:
                            {


printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
fflush(stdin);
getch();
system("cls");
    }
    }
    }
    displayPerson();
    current_Person = head_Person;
    printf("\nWcisnij dowolny klawisz zeby kontynuowac......\n");
    getch();
}
void MainMenu(void)
{
    readPersonFile();
    while(1)
    {
        system("cls");

        int choose;


        Title();
        printf("\n\n\n\n\n\t\t\t\t1. Dodawanie do ksiazki telefonicznej\n");
        printf("\n\t\t\t\t2. Lista osob z numerami\n");
        printf("\n\t\t\t\t3. Szukaj osoby w ksiazce\n");
        printf("\n\t\t\t\t4. Edytowanie osoby wprowadzonej\n");
        printf("\n\t\t\t\t5. Usuwanie osoby z ksiazki\n");
        printf("\n\t\t\t\t6. Sortuj osoby w ksiazce po danym polu\n");
        printf("\n\t\t\t\t7. Wyjscie\n");
        printf("\n\n\n \n\t\t\t\tWybierz od 1 do 7:");
        scanf("%d", &choose);
        switch(choose)
        {

        case 1:
            addPerson();
            break;


        case 2:
            displayPerson();
            printf("\n\nWcisnij dowolny klawisz zeby kontynuowac......\n");
            getch();
            break;
        case 3:
            searchPerson();
            break;
        case 4:
            modifyPerson();

            break;
        case 5:
            deletePerson();
            break;
        case 6:
            sort();

            break;
        case 7:
            printf("Dziekuje za skorzystanie z ksiazki");
            getch();
            exit(0);
            break;

        default:
printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
fflush(stdin);
            getch();
        }

    }
}
int main()
{
    WelcomeScreen();
    MainMenu();
    return 0;
}
