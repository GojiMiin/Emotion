#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include<iostream>

using namespace std;

class Emotion
{
protected:
    int rate;
    Emotion *next;
public:
    virtual void name(){}
    virtual void quote(){}
    static void sorting(Emotion*,Emotion*,Emotion*);
    Emotion(int a=0){
        rate=a;
        next=NULL;
    }
    void append(Emotion *a){
        next=a;
    }
    Emotion* movenext(){
        return next;
    }

};

class happy :public Emotion{
private:
    string happya="\t\t\tYou are absolutely delighted";
    string happyb="\t\t\tYou are over the moon";
    string happyc="\t\t\tYou could not be happier";
public:
    void name()
    {
        cout<<"\t\t\t         HAPPY   "<<rate<<"%"<<endl;
    }
    /*void quote()
    {
        cout<<"happy    ";//ได้แล้ว
    }*/
    happy(int a):Emotion(a)
    {
        if(a>60)
        {
            cout<<happyc<<endl;
            //quote();
        }
        else if(a>30&&a<=60)
        {
            cout<<happyb<<endl;
        }
        else if(a>=0&&a<=30)
        {
            cout<<happya<<endl;
        }

    }
};

class sad :public Emotion{
private:
    string sada="\t\t\tYou feel blue";
    string sadb="\t\t\tYou are down in dumps";
    string sadc="\t\t\tYour heart sink";
public:
    void name()
    {
        cout<<"         SAD   "<<rate<<"%"<<endl;
    }
    /*void quote()
    {
        cout<<"sad  ";
    }*/
    sad(int a):Emotion(a)
    {
        if(a>60)
        {
            cout<<sadc<<endl;
            //quote();
        }
        else if(a>30&&a<=60)
        {
            cout<<sadb<<endl;
        }
        else if(a>=0&&a<=30)
        {
            cout<<sada<<endl;
        }
    }

};

class angry :public Emotion{
private:
    string angrya="\t\t\tYou are angry";
    string angryb="\t\t\tYou are pissed";
    string angryc="\t\t\tYou are enraged";
public:
    void name()
    {
        cout<<"         ANGRY   "<<rate<<"%"<<endl;
    }
    /*void quote()
    {
        cout<<"angry    ";
    }*/
    angry(int a):Emotion(a)
    {
        if(a>60)
        {
            cout<<angryc<<endl;
            //quote();
        }
        else if(a>30&&a<=60)
        {
            cout<<angryb<<endl;
        }
        else if(a>=0&&a<=30)
        {
            cout<<angrya<<endl;
        }
    }
};

class stress :public Emotion{
private:
    string stressa="\t\t\tYou are anxiety";
    string stressb="\t\t\tYou are worry";
    string stressc="\t\t\tYou are stressed";
public:
    void name()
    {
        cout<<"         STRESS   "<<rate<<"%"<<endl;
    }
    /*void quote()
    {
        cout<<"stress   ";
    }*/
    stress(int a):Emotion(a)
    {
        if(a>60)
        {
            cout<<stressc<<endl;
            //quote();
        }
        else if(a>30&&a<=60)
        {
            cout<<stressb<<endl;
        }
        else if(a>=0&&a<=30)
        {
            cout<<stressa<<endl;
        }
    }
};


#endif // CLASS_H_INCLUDED
