#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "class.h"

using namespace std;

void gohome(Emotion*,Emotion*,Emotion*);
void menu(Emotion*,Emotion*,Emotion*);
char menuchoice(Emotion*,Emotion*,Emotion*);
void feeltoday(Emotion*,Emotion*,Emotion*);
int checkday(Emotion*,Emotion*,Emotion*);
void selectday(Emotion*,Emotion*,Emotion*);
void load_save(Emotion*,Emotion*,Emotion*);
void delfile(Emotion* head,Emotion* tail,Emotion*hh);

FILE *fp;
int a=0, z=0;

int main()
{
    Emotion *head=NULL,*tail=NULL,*hh;
    menu(head,tail,hh);
}

void menu(Emotion* head,Emotion* tail,Emotion*hh)
{
    char choice;
    do
    {
        choice=menuchoice(head,tail,hh);
        switch(choice)
        {
        case '1':
            feeltoday(head,tail,hh);
            break;
        case '2':
            selectday(head,tail,hh);
            break;
        case '3':
            Emotion::sorting(head,tail,hh);
            break;
        case '4':
            load_save(head,tail,hh);
            break;
        case '5':
            delfile(head,tail,hh);
            break;
        case '6':
            exit(0);
            break;

        default:
            system("cls");
            break;
        }
    }
    while(choice!='6');
}

char menuchoice(Emotion* head,Emotion* tail,Emotion*hh)
{
    char n;
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t                       EMOTION :)                       \n\n"<<endl;
    cout<<"\t\t\t1.>>             HOW DO YOU FEEL TODAY?              <<"<<endl;
    cout<<"\t\t\t2.>>                SHOW PREVIOUS DAY                <<"<<endl;
    cout<<"\t\t\t3.>>            MAXIMUM OR MINIMUM FEELS             <<"<<endl;
    cout<<"\t\t\t4.>>                 Load Your Save                  <<"<<endl;
    cout<<"\t\t\t5.>>                 Delete Your Save                <<"<<endl;
    cout<<"\t\t\t6.>>                     QUIT                        <<"<<endl;
    cout<<"\t\t\tYOUR CHOICE -->  ";
    n=getche();
    return n;
}

void gohome(Emotion* head,Emotion* tail,Emotion*hh)
{
    char m;
    do
    {
        cout<<"\n\n\t\t\tPRESS --> H <-- TO GO BACK TO MENU"<<endl;
        m=getch();
    }
    while(m!='H'&&m!='h');
    system("cls");
    menu(head,tail,hh);
}

void feeltoday(Emotion* head,Emotion* tail,Emotion*hh)
{
    system("cls");

    int rate=0;
    string mood;
    std::fstream file;//start file save
    file.open("detail.txt",std::ios::in | std::ios::out | std::ios::app);
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t>>             HOW DO YOU FEEL TODAY?              <<"<<endl;

    do
    {
        cout<<"\t\t\tHAPPY/SAD/ANGRY/STRESS? : ";
        cin>>mood;
        for(int i=0; i<mood.size(); i++)
        {
            char c=tolower(mood[i]);
            mood[i]=c;
        }
    }

    while(mood.compare("happy")!=0&&mood.compare("sad")!=0&&mood.compare("angry")&&mood.compare("stress")!=0);
    file<<mood<<" ";//save mood

    cout<<"\t\t\tRATE (0-100%) : ";
    cin>>rate;

    while(!cin>>rate)
    {
        cout<<"\t\t\tWRONG INPUT ! ";
        cin.clear();
        cin.ignore(50,'\n');
        cout<<"TRY AGAIN !(0-100%): ";
        cin>>rate;
    }
    while(rate<0||rate>100)
    {
        cout<<"\t\t\tWRONG INPUT ! ";
        cout<<"TRY AGAIN !(0-100%): ";
        cin>>rate;
    }

    file<<rate<<endl;

    if(!head)
    {
        if(mood.compare("happy")==0)
        {
            head=new happy(rate);
            hh=head;
            tail=head;
        }
        else if(mood.compare("sad")==0)
        {
            head=new sad(rate);
            hh=head;
            tail=head;
        }
        else if(mood.compare("angry")==0)
        {
            head=new angry(rate);
            hh=head;
            tail=head;
        }
        else if(mood.compare("stress")==0)
        {
            head=new stress(rate);
            hh=head;
            tail=head;
        }
    }
    else
    {
        if(mood.compare("happy")==0)
        {
            tail->append(new happy(rate));
            tail=tail->movenext();
        }
        else if(mood.compare("sad")==0)
        {
            tail->append(new sad(rate));
            tail=tail->movenext();
        }
        else if(mood.compare("angry")==0)
        {
            tail->append(new angry(rate));
            tail=tail->movenext();
        }
        else if(mood.compare("stress")==0)
        {
            tail->append(new stress(rate));
            tail=tail->movenext();
        }

    }
    cout<<"\t\t\tYour detail will be auto save."<<endl;
    file.close();
    gohome(head,tail,hh);
}

int checkday(Emotion* head,Emotion* tail,Emotion*hh)
{
    int n=0;
    hh=head;
    if(head==NULL)
    {
        return n=0;//no linklist
    }
    else
    {
        while(hh!=NULL)
        {
            n++;
            hh=hh->movenext();
        }
    }
    return n;
}

void selectday(Emotion* head,Emotion* tail,Emotion*hh)
{
    system("cls");
    int day,allday,i=1;
    hh=head;
    allday=checkday(head,tail,hh);
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t>>             WHICH DAY YOU WANT TO KNOW ?              <<"<<endl;
    cout<<"\n\n";

    if(allday==0)
    {
        cout<<"\t\t\tDON'T HAVE PREVIOUS DAY"<<endl<<"\t\t\tPLEASE DO YOUR FIRST DAY"<<endl;
        gohome(head,tail,hh);
    }
    else
    {
        do
        {
            cout<<"\t\t\tSELECT DAY (1-"<<allday<<") --> ";
            cin>>day;
        }
        while(day<1||day>allday);

        while(day!=i)
        {
            hh=hh->movenext();
            i++;
        }
        cout<<day;
        hh->name(); //broken here
        gohome(head,tail,hh);
    }

}
void Emotion::sorting(Emotion* head,Emotion* tail,Emotion* hh)
{
    int allday,maxi=-1,mini=101;
    string maxmin;
    system("cls");
    hh=head;
    allday=checkday(head,tail,hh);
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t>>            MAXIMUM OR MINIMUM FEELS          <<"<<endl;

    if(allday==0)
    {
        cout<<"\t\t\tDON'T HAVE PREVIOUS DAY"<<endl<<"\t\t\tPLEASE DO YOUR FIRST DAY"<<endl;
        gohome(head,tail,hh);
    }

    do
    {
        cout<<"\t\t\tCHOOSE (MAX/MIN) --> ";
        cin>>maxmin;
        for(int i=0; i<maxmin.size(); i++)
        {
            char c=tolower(maxmin[i]);
            maxmin[i]=c;
        }
    }
    while(maxmin.compare("max")&&maxmin.compare("min"));

    if(maxmin.compare("max")==0)
    {
        cout<<"\n\t\t\t";
        hh=head;
        while(hh!=NULL)
        {
            if(maxi<hh->rate)
            {
                maxi=hh->rate;
            }
            hh=hh->movenext();
        }
        hh=head;
        while(hh!=NULL)
        {
            if(maxi==hh->rate)
            {
                hh->name();
            }
            hh=hh->movenext();
        }
        gohome(head,tail,hh);
    }

    else if(maxmin.compare("min")==0)
    {
        hh=head;
        cout<<"\n\t\t\t";
        while(hh!=NULL)
        {
            if(mini>hh->rate)
            {
                mini=hh->rate;
            }
            hh=hh->movenext();
        }
        hh=head;
        while(hh!=NULL)
        {
            if(mini==hh->rate)
            {
                hh->name();
            }
            hh=hh->movenext();
        }
        gohome(head,tail,hh);
    }

}

void load_save(Emotion* head,Emotion* tail,Emotion*hh)
{
    ifstream file;
    file.open("detail.txt",std::ios::in);
    string mood_s;
    system("cls");
    int rate_s;
    cout<<"\n\n\n"<<endl;
    if(file)
    {
        if(z==0)
        {
            if(a==0)
            {
                while(file>>mood_s>>rate_s)
                {
                    if(!head)
                    {
                        if(mood_s.compare("happy")==0)
                        {
                            head=new happy(rate_s);
                            hh=head;
                            tail=head;
                        }
                        else if(mood_s.compare("sad")==0)
                        {
                            head=new sad(rate_s);
                            hh=head;
                            tail=head;
                        }
                        else if(mood_s.compare("angry")==0)
                        {
                            head=new angry(rate_s);
                            hh=head;
                            tail=head;
                        }
                        else if(mood_s.compare("stress")==0)
                        {
                            head=new stress(rate_s);
                            hh=head;
                            tail=head;
                        }
                    }
                    else
                    {
                        if(mood_s.compare("happy")==0)
                        {
                            tail->append(new happy(rate_s));
                            tail=tail->movenext();
                        }
                        else if(mood_s.compare("sad")==0)
                        {
                            tail->append(new sad(rate_s));
                            tail=tail->movenext();
                        }
                        else if(mood_s.compare("angry")==0)
                        {
                            tail->append(new angry(rate_s));
                            tail=tail->movenext();
                        }
                        else if(mood_s.compare("stress")==0)
                        {
                            tail->append(new stress(rate_s));
                            tail=tail->movenext();
                        }

                    }
                }
                a++;
            }
            else
                cout<<"\t\t\tYour save already loaded."<<endl;
        }
        else
            cout<<"\t\t\tYou can't load save."<<endl;
    }
    else
        cout<<"\t\t\tNo Save File"<<endl;

    file.close();
    gohome(head,tail,hh);
}

void delfile(Emotion* head,Emotion* tail,Emotion*hh)
{
    system("cls");
    cout<<"\t\t\tYour save file is deleted."<<endl;
    remove("detail.txt");
    a=0;
    gohome(head,tail,hh);
}



