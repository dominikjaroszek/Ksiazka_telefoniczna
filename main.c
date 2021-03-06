#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct Person
{
    int personid;
    char name[20];
    char last_name[20];
    char address[30];
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
    printf("\n\n\n\n\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
    system("cls");
}

void Title(void)
{
    printf("\n\n\t--------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t         KSIAZKA TELEFONICZNA        ");
    printf("\n\t--------------------------------------------------------------------------------------------\n\n\n");
}

int checkFileid()
{
    temp=head_Person;
    while(temp->next!=NULL)
    {
        if(temp->personid==current_Person->personid)
        {
            printf("\n\tBlad! W pliku wystepuje problem z id");
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}

int checkFileadres()
{
    int valid=0;
    if(!(strlen(current_Person->address)<=30&&strlen(current_Person->address)>=4))
    {
        printf("\n\tBlad! Adres w pliku powinien miec od 4 do 30 liter");
        fflush(stdin);
        return 0;
    }
    else
    {
        valid=1;
    }
    return valid;
}

int lastpersonid()
{
    current_Person=head_Person;
    int max=0;
    while (current_Person)
    {
        max=current_Person->personid;
        current_Person = current_Person->next;
    }
    return max;
}

int maxcountpersonid()
{
    current_Person=head_Person;
    int max=0;
    while (current_Person)
    {
        max++;
        current_Person = current_Person->next;
    }
    return max;
}

int checkFilenumber()
{
    int i=0,valid=0;
    if(!(strlen(current_Person->contact)==9))
    {
        printf("\n\tBlad! Numer w pliku powinien miec 9 cyfr");
        return 0;
    }
    else
    {
        for (i=0; i<strlen(current_Person->contact); i++)
        {
            if (isdigit(current_Person->contact[i]))
            {
                valid=1;
            }
            else
            {
                printf("\n\tUzyj cyfr przy numerze w pliku!  Sprobuj ponownie");
                return 0;
                break;
            }
        }
    }
    temp=head_Person;
    while(temp->next!=NULL)
    {
        if(strcmp(temp->contact,current_Person->contact)==0)
        {
            return 0;
        }
        temp=temp->next;
    }
    return valid;
}

int checkFilelastname()
{
    int i=0,valid=0;
    if(!(strlen(current_Person->last_name)<=20&&strlen(current_Person->last_name)>=2))
    {
        printf("\n\tBlad! Nazwisko w pliku powinno miec od 2 do 20 liter");
        return 0;
    }
    else
    {
        for (i=0; i<strlen(current_Person->last_name); i++)
        {
            if (isalpha(current_Person->last_name[i]))
            {
                valid= 1;
            }
            else
            {
                printf("\n\tUzyj liter przy nazwisku w pliku! Sprobuj ponownie");
                return 0;
                break;
            }
        }
    }
    return valid;
}

int checkFilename()
{
    int i=0,valid=0;
    if(!(strlen(current_Person->name)<=20&&strlen(current_Person->name)>=2))
    {
        printf("\n\tBlad! Imie w pliku powinno miec od 2 do 20 liter");
        return 0;
    }
    else
    {
        for (i=0; i<strlen(current_Person->name); i++)
        {
            if (isalpha(current_Person->name[i]))
            {
                valid= 1;
            }
            else
            {
                printf("\n\tUzyj liter przy imieniu w pliku! Sprobuj ponownie");
                return 0;
                break;
            }
        }
    }
    return valid;
}

int checksign()
{
    FILE *fp = fopen("Person.txt","r");
    if(fp == NULL)
    {
        printf("\n\tBlad otwarcia pliku!\n");
        return 0;
    }
    char znak;
    int count=0;
    while((znak=fgetc(fp))!=EOF)
    {
        if(znak==59)
        {
            count++;
        }
    }
    if(count!=(maxcountpersonid()*5))
    {
        printf("\tBlad! Liczba ';' sie nie zgadza!");
        return 0;
    }
    if(fclose(fp))
    {
        printf("\tBlad zamkniecia pliku!\n");
        return 0;
    }
    return 1;
}

int writePersonFile()
{
    FILE *fp = fopen("Person.txt","w");
    if(fp == NULL)
    {
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
    {
        fprintf (fp, "%d;%s;%s;%s;%s;\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->contact, current_Person->address );
    }
    if(fseek(fp,0,SEEK_SET)==-1)
    {
        printf("Blad operacji przesuwania wskaznika pliku!\n");
        return 0;
    }
    if(fclose(fp))
    {
        printf("Blad zamkniecia pliku!\n");
        return 0;
    }
    printf("\n\n\nZapis sie udal!\n");
    return 1;
}

void displayPerson()
{
    system("cls");
    Title();
    printf("\t%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
    printf("\t--------------------------------------------------------------------------------------------\n");
    for(current_Person =head_Person; current_Person; current_Person = current_Person->next)
        printf ("\t%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
    printf("\t--------------------------------------------------------------------------------------------\n");
}

int insertname(char name[22])
{
    int i=0,valid=0;
    memset(name, '\0', 30*sizeof(char));
    printf("\n\n\n\t\t\tWprowadz imie: ");
    scanf("%30s",name);
    i=0;
    while(name[i])
    {
        name[i]=tolower(name[i]);
        i++;
    }
    name[0]=toupper(name[0]);
    if( !strcmp(name,"0"))
    {
        printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
        getch();
        return 2;
    }
    if(!(strlen(name)<=20&&strlen(name)>=2))
    {
        printf("\n\tBlad! Wprowadz imie z przedzialu od 2 do 20 liter");
        memset(name, '\0', 30*sizeof(char));
        fflush(stdin);
    }
    else
    {
        for (i=0; i<strlen(name); i++)
        {
            if (isalpha(name[i]))
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
            printf("\n\tUzyj poprawnych liter przy imieniu  Sprobuj ponownie");
        }
    }
    return valid;
}

int insertlastname(char last_name[22])
{
    int i=0,valid=0;
    memset(last_name, '\0', 30*sizeof(char));
    printf("\n\t\t\tWprowadz nazwisko: ");
    scanf("%30s",last_name);
    i=0;
    while(last_name[i])
    {
        last_name[i]=tolower(last_name[i]);
        i++;
    }
    last_name[0]=toupper(last_name[0]);
    if(!(strlen(last_name)<=20&&strlen(last_name)>=2))
    {
        printf("\n\tBlad! Wprowadz nazwisko z przedzialu od 2 do 20 liter");
        memset(last_name, '\0', 30*sizeof(char));
        fflush(stdin);
    }
    else
    {
        for (i=0; i<strlen(last_name); i++)
        {
            if (isalpha(last_name[i]))
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
            printf("\n\tUzyj poprawnych liter przy nazwisku  Sprobuj ponownie");
        }
    }
    return valid;
}

int insertaddress(char address[32])
{
    int valid=0;
    printf("\n\t\t\tWprowadz adres: ");
    fgets(address, 32, stdin);
    strtok(address,"\n");
    if(!(strlen(address)<=30&&strlen(address)>=4))
    {
        printf("\n\tBlad! Wprowadz adres z przedzialu od 4 do 30 liter");
        fflush(stdin);
        valid=0;
    }
    else
    {
        valid=1;
    }
    return valid;
}

int insertphonenumber(char pcontact[11])
{
    int i=0,valid=0;
    memset(pcontact, '\0', 9*sizeof(char));
    printf("\n\t\t\tWprowadz numer telefonu: ");
    scanf("%11s",pcontact);
    if(!(strlen(pcontact)==9))
    {
        printf("\n\tBlad! Wprowadz numer telefonu o dlugosci 9 cyfr");
        memset(pcontact, '\0', 11*sizeof(char));
        fflush(stdin);
    }
    else
    {
        for (i=0; i<strlen(pcontact); i++)
        {
            if (isdigit(pcontact[i]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                memset(pcontact, '\0', 11*sizeof(char));
                break;
            }
        }
        if(!valid)
        {
            printf("\n\tUzyj cyfr przy wprowadzaniu numeru telefonu  Sprobuj ponownie");
            fflush(stdin);
        }
    }
    temp=head_Person;
    while(temp)
    {
        if(strcmp(temp->contact,pcontact)==0)
        {
            printf("\n\tPodaj numer, ktory sie nie powtorzyl");
            valid=0;
        }
        temp=temp->next;
    }
    return valid;
}

int modifyPerson()
{
    system("cls");
    int valid=0;
    char choose[2];
    memset(choose, '\0', 2*sizeof(char));
    while(!valid)
    {
        choose[0]=' ';
        choose[1]=' ';
        Title();
        displayPerson();
        Person t;
        int waga=0,i;
        int idss;
        char array[10];
        printf ("\n\t\t\t\tWpisz 0 w przypadku checi powrotu do menu");
        while(!valid)
        {
            memset(array, '\0', 10*sizeof(char));
            printf ("\n\n\t\t\t\tWprowadz ID osoby do modyfikacji: ");
            scanf("%11s", array) ;
            for (i=0; i<strlen(array); i++)
            {
                if (isdigit(array[i]))
                {
                    idss=atoi(array);
                }
                else
                {
                    valid=0;
                    memset(array, '\0', 10*sizeof(char));
                    idss=-1;
                    break;
                }
            }
            if( idss==0)
            {
                valid=1;
                printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
                getch();
                return 2;
            }
            current_Person=head_Person;
            if(idss>=current_Person->personid&&idss<=lastpersonid())
            {
                current_Person=head_Person;
                while(current_Person)
                {
                    if(idss==current_Person->personid)
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
        scanf("%3s", choose);
        fflush(stdin);
        if(choose[0]==48&&choose[1]=='\0')
            valid=1;
        else  if(choose[0]==49&&choose[1]=='\0')
        {
            while(!valid)
            {
                valid=insertname(t.name);
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
                valid=insertlastname(t.last_name);
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
                valid=insertaddress(t.address);
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
                    strcpy(current_Person->address,t.address);
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
            while(!valid)
            {
                valid=insertphonenumber(t.contact);
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
            memset(choose, '\0', 3*sizeof(char));
            fflush(stdin);
            getch();
            system("cls");
        }
    }
    printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
    return 1;
}

void searchPerson()
{
    system("cls");
    int pid;
    char name[22];
    char last_name[22];
    char paddress[30];
    char pcontact[11];
    int valid=0;
    char choose[2];
    memset(choose, '\0', 2*sizeof(char));
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
        scanf("%3s", choose);
        if(choose[0]==48&&choose[1]=='\0')
        {
            valid=1;
            break;
        }
        else if(choose[0]==49&&choose[1]=='\0')
        {
            while(!valid)
            {
                char array[10];
                memset(array, '\0', 10*sizeof(char));
                printf ("\n\n\t\t\t\tWprowadz ID osoby do znalezienia: ");
                scanf("%11s", array) ;
                for (int i=0; i<strlen(array); i++)
                {
                    if (isdigit(array[i]))
                    {
                        pid=atoi(array);
                    }
                    else
                    {
                        valid=0;
                        memset(array, '\0', 10*sizeof(char));
                        pid=-1;
                        break;
                    }
                }
                if(pid>=1&&pid<=lastpersonid())
                {
                    valid=1;
                }
                else
                {
                    printf("\t\t\t\tPodaj poprawne id osoby");
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
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
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
                memset(name, '\0', 30*sizeof(char));
                printf("\n\n\n\t\t\tWprowadz imie: ");
                scanf("%30s",name);
                i=0;
                while(name[i])
                {
                    name[i]=tolower(name[i]);
                    i++;
                }
                name[0]=toupper(name[0]);
                if(!(strlen(name)<=20&&strlen(name)>=1))
                {
                    printf("\n\tBlad! Wprowadz imie z przedzialu od 1 do 20 liter");
                    memset(name, '\0', 30*sizeof(char));
                    fflush(stdin);
                }
                else
                {
                    for (i=0; i<strlen(name); i++)
                    {
                        if (isalpha(name[i]))
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
                        printf("\n\tUzyj poprawnych liter przy imieniu  Sprobuj ponownie");
                    }
                }
            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->name, name))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
                }
                else if(!strncmp(current_Person->name, name,strlen(name)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
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
                memset(last_name, '\0', 30*sizeof(char));
                printf("\n\t\t\tWprowadz nazwisko: ");
                scanf("%30s",last_name);
                i=0;
                while(last_name[i])
                {
                    last_name[i]=tolower(last_name[i]);
                    i++;
                }
                last_name[0]=toupper(last_name[0]);
                if(!(strlen(last_name)<=20&&strlen(last_name)>=1))
                {
                    printf("\n\tBlad! Wprowadz nazwisko z przedzialu od 1 do 20 liter");
                    memset(last_name, '\0', 30*sizeof(char));
                    fflush(stdin);
                }
                else
                {
                    for (i=0; i<strlen(last_name); i++)
                    {
                        if (isalpha(last_name[i]))
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
                        printf("\n\tUzyj poprawnych liter przy nazwisku  Sprobuj ponownie");
                    }
                }
            }
            current_Person = head_Person;
            printf("%-5s%-21s%-21s%-31s%-10s\n","ID","Imie","Nazwisko","Adres","Numer_Telefonu");
            printf("--------------------------------------------------------------------------------------------\n");
            while (current_Person!=NULL)
            {
                if(!strcmp(current_Person->last_name, last_name))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
                }
                else if(!strncmp(current_Person->last_name, last_name,strlen(last_name)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
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
                printf("\n\t\t\tWprowadz adres: ");
                fgets(paddress, 32, stdin);
                strtok(paddress,"\n");
                if(!(strlen(paddress)<=30&&strlen(paddress)>=1))
                {
                    printf("\n\tBlad! Wprowadz adres z przedzialu od 1 do 30 liter");
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
            char currentaddress[30],currentaddress2[30];
            strcpy(currentaddress,paddress);
            int i=0;
            while(currentaddress[i])
            {
                if(isalpha(currentaddress[i]))
                {
                    currentaddress[i]=tolower(currentaddress[i]);
                }
                i++;
            }
            while (current_Person!=NULL)
            {
                strcpy(currentaddress2,current_Person->address);
                i=0;
                while(currentaddress[i])
                {
                    if(isalpha(currentaddress2[i]))
                    {
                        currentaddress2[i]=tolower(currentaddress2[i]);
                    }
                    i++;
                }
                if(!strcmp(currentaddress2,currentaddress))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
                }
                else if(!strncmp(currentaddress2, currentaddress,strlen(currentaddress)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
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
                memset(pcontact, '\0', 9*sizeof(char));
                printf("\n\t\t\tWprowadz numer telefonu: ");
                scanf("%11s",pcontact);
                if((strlen(pcontact)>9))
                {
                    printf("\n\tBlad! Wprowadz numer telefonu o dlugosci 9 cyfr");
                    memset(pcontact, '\0', 11*sizeof(char));
                    fflush(stdin);
                }
                else
                {
                    for (i=0; i<strlen(pcontact); i++)
                    {
                        if (isdigit(pcontact[i]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            memset(pcontact, '\0', 11*sizeof(char));
                            break;
                        }
                    }
                    if(!valid)
                    {
                        printf("\n\tUzyj cyfr przy wprowadzaniu numeru telefonu  Sprobuj ponownie");
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
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
                }
                else if(!strncmp(current_Person->contact, pcontact,strlen(pcontact)))
                {
                    printf ("%-5d%-21s%-21s%-31s%-10s\n", current_Person->personid, current_Person->name, current_Person->last_name,current_Person->address,current_Person->contact);
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
            memset(choose, '\0', 3*sizeof(char));
            fflush(stdin);
            getch();
        }
    }
    printf("\nWcisnij dowolny, klawisz zeby kontynuowac...\n");
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
    strcpy(x,temp->address);
    strcpy(temp->address,temp->next->address);
    strcpy(temp->next->address,x);
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
    char idss[10];
    int found=0,valid=0,i;
    printf("\n\t\t\t\tW przypadku checi powrotu wstecz wpisz 0");
    while(!valid)
    {
        memset(idss, '\0', 10*sizeof(char));
        printf ("\n\n\t\t\t\tWprowadz ID osoby do usuniecia: ");
        current_Person=head_Person;
        scanf("%11s", idss) ;
        for (i=0; i<strlen(idss); i++)
        {
            if (isdigit(idss[i]))
            {
                t.personid=atoi(idss);
            }
            else
            {
                valid=0;
                memset(idss, '\0', 10*sizeof(char));
                t.personid=-1;
                break;
            }
        }
        if( t.personid==0)
        {
            valid=1;
            break;
            return 2;
        }
        if(t.personid>=current_Person->personid&&t.personid<=lastpersonid())
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
            printf("\n\t\t\t\tCzy jestes pewny usuniecia? T/N:");
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
                printf("\n\n\t\t\t\tOsoba usunieta poprawnie!");
                writePersonFile();
            }
            else
            {
                printf("\n\n\t\t\t\tNie udalo sie usunac osoby!");
            }
        }
        else
            fflush(stdin);
    }
    printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
    return 1;
}

int autoIncrementPerson()
{
    int id=1;
    temp = head_Person;
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
    }
    temp = head_Person;
}

int addPerson()
{
    system("cls");
    Title();
    Person t, * node;
    int valid=0;
    char question[2];
    do
    {
        printf("\n\t\t\t\tWpisz '0', aby powrocic, '1' aby przejsc dalej: ");
        memset(question, '\0', 3*sizeof(char));
        fflush(stdin);
        scanf("%3s",question);
        if(question[0]==48&&question[1]=='\0')
        {
            return 2;
        }
    }
    while(!((question[0]==48&&question[1]=='\0')||(question[0]==49&&question[1]=='\0')));
    fflush(stdin);
    system("cls");
    Title();
    node = (Person*)malloc (sizeof (Person));
    while(!valid)
    {
        valid=insertname(t.name);
        if(valid)
            strcpy(node->name,t.name);
    }
    valid=0;
    while(!valid)
    {
        valid=insertlastname(t.last_name);
        if(valid)
            strcpy(node->last_name,t.last_name);
    }
    fflush(stdin);
    valid=0;
    while(!valid)
    {
        valid=insertaddress(t.address);
        if(valid)
            strcpy(node->address,t.address);
    }
    fflush(stdin);
    valid=0;
    char pcontact[9];
    while(!valid)
    {
        valid=insertphonenumber(pcontact);
        if(valid)
            strcpy(node->contact,pcontact);
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
    printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
    return 2;
}

int readPersonFile()
{
    head_Person = NULL,current_Person = NULL;
    FILE *fp = fopen("Person.txt","r");
    if(fp == NULL)
    {
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    Person tl, *node;
    int valid=1;
    while ((fscanf (fp,"%d;%[^;];%[^;];%[^;];%31[^;\n];", &tl.personid, tl.name,tl.last_name,tl.contact,tl.address)!=EOF)&&valid)
    {
        node = (Person*)malloc (sizeof (Person) );
        node->personid = tl.personid;
        strcpy(node->name,tl.name) ;
        strcpy(node->last_name,tl.last_name);
        strcpy(node->address,tl.address) ;
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
        valid= checkFileid();
        if(!valid)
        {
            return valid;
        }
        valid=checkFilename();
        if(!valid)
        {
            return valid;
        }
        valid=checkFilelastname();
        if(!valid)
        {
            return valid;
        }
        valid=checkFileadres();
        if(!valid)
        {
            return valid;
        }
        valid=checkFilenumber();
        if(!valid)
        {
            return valid;
        }
    }
    valid=checksign();
    if(!valid)
    {
        return valid;
    }
    if(fclose(fp))
    {
        printf("Blad zamkniecia pliku!\n");
        return 0;
    }
    return valid;
}

void sort()
{
    system("cls");
    int valid = 0,falid=0;
    while(!valid&&!falid)
    {
        Title();
        char choose[3];
        memset(choose, '\0', 3*sizeof(char));
        printf("\t\t\t\tPo jakim polu chcesz posortowac?");
        printf("\n\n\t\t\t\t0. Wroc\n");
        printf("\n\t\t\t\t1. Id malejaco\n");
        printf("\n\t\t\t\t2. Id rosnaco\n");
        printf("\n\t\t\t\t3. Imiona alfabetycznie\n");
        printf("\n\t\t\t\t4. Imiona alfabetycznie odwrotnie\n");
        printf("\n\t\t\t\t5. Nazwiska alfabetycznie\n");
        printf("\n\t\t\t\t6. Nazwiska alfabetycznie odwrotnie\n");
        printf("\n\t\t\t\t7. Numery telefonow malejaco\n");
        printf("\n\t\t\t\t8. Numery telefonow rosnaco\n");
        printf("\n\t\t\t\t9. Adresy alfabetycznie\n");
        printf("\n\t\t\t\t10. Adresy alfabetycznie odwrotnie\n");
        printf("\n\n\n \n\t\t\t\tWprowadz opcje pomiedzy 0 a 10 : ");
        scanf("%4s", choose);
        if(choose[0]==48&&choose[1]=='\0')
        {
            valid=1;
            falid=1;
            break;
        }
        else  if(choose[0]==49&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==50&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==51&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==52&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==53&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==54&&choose[1]=='\0')
        {
            temp = head_Person;
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==56&&choose[1]=='\0')
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
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else  if(choose[0]==57&&choose[1]=='\0')
        {
            for(current_Person = head_Person; current_Person; current_Person = current_Person->next)
            {
                temp = head_Person;
                while(temp->next != NULL)
                {
                    if(strcmp(temp->address,temp->next->address) > 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
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
                    if(strcmp(temp->address,temp->next->address) < 0)
                    {
                        sort_help();
                    }
                    temp = temp->next;
                }
            }
            temp = head_Person;
            valid=1;
            break;
        }
        else
        {
            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            memset(choose, '\0', 4*sizeof(char));
            fflush(stdin);
            getch();
            system("cls");
        }
    }
    if(!falid)
    {
        displayPerson();
        temp = head_Person;
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
        }
        temp = head_Person;
    }
    current_Person = head_Person;
    printf("\nWcisnij dowolny klawisz, zeby kontynuowac...\n");
    getch();
}

void beforestart()
{
    if(!readPersonFile())
    {
        printf("\n\n\tPlik jest uszkodzony !\n");
        exit(0);
    }
}

void MainMenu(void)
{
    beforestart();
    WelcomeScreen();
    while(1)
    {
        system("cls");
        char choose[2];
        memset(choose, '\0', 2*sizeof(char));
        Title();
        printf("\n\n\n\n\n\t\t\t\t1. Dodawanie osoby do ksiazki telefonicznej\n");
        printf("\n\t\t\t\t2. Lista osob w ksiazce telefonicznej\n");
        printf("\n\t\t\t\t3. Szukaj osoby w ksiazce telefonicznej\n");
        printf("\n\t\t\t\t4. Edytowanie wprowadzonej osoby w ksiazce telefonicznej\n");
        printf("\n\t\t\t\t5. Usuwanie osoby z ksiazki telefonicznej\n");
        printf("\n\t\t\t\t6. Sortowanie osob w ksiazce telefoniczej po danym polu\n");
        printf("\n\t\t\t\t7. Wyjscie z programu\n");
        printf("\n\n\n \n\t\t\t\tWybierz od 1 do 7 : ");
        scanf("%3s", choose);
        if(choose[0]==49&&choose[1]=='\0')
        {
            addPerson();
        }
        else  if(choose[0]==50&&choose[1]=='\0')
        {
            displayPerson();
            printf("\n\n\tWcisnij dowolny klawisz, zeby kontynuowac...\n");
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
        else  if(choose[0]==55&&choose[1]=='\0')
        {
            printf("\n\t\t\t\tDziekuje za skorzystanie z ksiazki");
            getch();
            exit(0);
        }
        else
        {
            printf("\n\t\t\t\tBlad! Podaj poprawna opcje z menu\n");
            memset(choose, '\0', 3*sizeof(char));
            fflush(stdin);
            getch();
        }
    }
}

int main()
{
    MainMenu();
    return 0;
}

