//
//  main.cpp
//  CleanBot
//
//  Created by Bilge Çimen on 13.10.2015.
//  Copyright © 2015 Bilge Çimen. All rights reserved.
//
/*
 00
 b-d--
 -d-d-
 -ddd-
 ---d-
 d--d-

*/
#include <iostream>
#include <math.h>
static int ds=0;
static int bk1;
static int bk2;
static int bokpesinde;
static int dk1[24];
static int dk2[24];
static int indeks;
using namespace std;
void islemyap(){
    int f1=0;
    int f2=0;
    bool esit1 = false;
    bool ustunde;
    char rl='n';
    char du='n';
    if(bk1<dk1[indeks])
    {
    du='d';
        f1=dk1[indeks]-bk1;
    }
    else if(dk1[indeks]<bk1)
    {
    du='u';
        f1=bk1-dk1[indeks];
    }
    else {
        f1=0;
        esit1 = 1;
    }
    if(bk2<dk2[indeks])
    {
        rl='r';
        f2=dk2[indeks]-bk2;
    }
    else if(dk2[indeks]<bk2)
    {
        rl='l';
        f2=bk2-dk2[indeks];
    }
    else {
        f2=0;
        if(esit1==1)
        {
            ustunde=1;
        }
    }
if(ustunde==1)
{
cout<<"CLEAN\n ";
    for(int i = indeks ;i<ds+1;i++)
    {
        if(i==ds){

        }
        else{
        dk1[i]=dk1[i+1];
        dk2[i]=dk2[i+1];

        }
    }
    ds=ds-1;
    ustunde=0;
    bokpesinde=0;
}
else {

    for(int i=0;i<ds;i++)
    {

    }
    for(int i =0;i<f1;i++){
        if(du=='d')
        {
        cout<<"DOWN\n";
            bk1=bk1+1;

        }
        if(du=='u')
        {
            cout<<"UP\n";
            bk1=bk1-1;
        }

    }
    for(int i =0;i<f2;i++){
        if(rl=='r')
        {

            cout<<"RIGHT\n";
            bk2=bk2+1;
        }
        if(rl=='l')
        {
            cout<<"LEFT\n";
            bk2=bk2-1;
        }

    }
}

}
void enkisabul(){
    bokpesinde = 0;
    double uzaklik[24];
    double enkisa;
    if(bokpesinde==0){
        if(ds==1){indeks=0;}
        else{
    for(int i=0;i<ds;i++)
    {
        int kareu;
        kareu=(bk1-dk1[i])*(bk1-dk1[i])+(bk2-dk2[i])*(bk2-dk2[i]);
        uzaklik[i]=sqrt(kareu);

    }
    if(uzaklik[0]<uzaklik[1])
    {
        enkisa=uzaklik[0];
        indeks=0;
    }
    else {
        enkisa=uzaklik[1];
        indeks =1;
    }

    for(int i=0;i<ds;i++)
    {
        if(uzaklik[i]<enkisa)
        {enkisa=uzaklik[i];
            indeks=i;
        }
    }
        bokpesinde=1;





    }
            islemyap();
    }

}
int main(int argc, const char * argv[]) {

    char b;

  bokpesinde = 0;

    cin>>bk1>>bk2;
    for(int i=0;i<5;i++){
        for(int a=0;a<5;a++)
        {
            cin>>b;
            if(b=='d'){
                dk1[ds]=i;
                dk2[ds]=a;
                ds++;
            }


        }


    }
  

    enkisabul();


    return 0;
}
