#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include<iostream>
int countLower(char s[]){
    int n=0,i=0;
while(s[i]!='\0'){
    if(s[i]>='a'&&s[i]<='z')
        n++;
    i++;
        }

return n;
}
int countU(char s[]){
    int n=0,i=0;
while(s[i]!='\0'){
    if(s[i]>='a'&&s[i]<='z')
        n++;
    i++;
        }

return n;
}
int countlength(char s[]){
int i;
    for(i=0;s[i]!='\0';i++);
return i;
}
int countgreaterL(char s[],char ss[]){

if(countlength(s)>countlength(ss))
    return countlength(s);
else
    return countlength(ss);

}
int countValue(char s[]){
int i,n=0;
    for(i=0;s[i]!='\0';i++)n+=s[i];
return n;
}
int countchar(char s[],char c){
int Count=0;
for(int i=0;s[i]!='\0';i++)
    if(s[i]==c)
        Count++;
return Count;
}


void cp(char s[],char ss[]){
int i=0;
while(ss[i]!='\0'){
        s[i]=ss[i];
        i++;
        }
        s[i]='\0';
}
void cut(char s[],char ss[]){

int i=0;
while(ss[i]!='\0'){
        s[i]=ss[i];
        ss[i]=NULL;
        i++;
        }
        s[i]='\0';
}


bool Larger(char s[],char ss[]){
    int n=0,i=0;
    while(s[i]!='\0')
        i++;
    while(ss[n]!='\0')
        n++;
    return i>n?true:false;
}


void convU(char s[]){
int i;
for(i=0;s[i]!='\0';i++)
    if(s[i]>='a'&&s[i]<='z')
        s[i]-=32;
    else
        s[i]+=32;

}
void convL(char s[]){
int i;
for(i=0;s[i]!='\0';i++)
    if(!(s[i]>='a'&&s[i]<='z'))
        s[i]+=32;

}

bool chack(char s[],char ss[]){
for(int i=0;;i++){
    if(s[i]!=ss[i])return false;
    if(i==countgreaterL(s,ss))return true;
    }
}
int chackS(char s[],char ss[]){
int i,c=0;
for(i=0;i<countgreaterL(s,ss);i++)
    if(s[i]!=ss[i])
        c++;
    if( (countValue(s)<countValue(ss)&&countlength(s)==countlength(ss)) || countlength(ss)>countlength(s) )
        c*=-1;
return c;
}
int chackin(char s[],char ss[]){
int i,c=0;
    for(i=0;i<countgreaterL(s,ss);i++)
        if(s[i]!=ss[i]&&s[i]!=ss[i]-32&&s[i]!=ss[i]+32)
            c++;
    if(countlength(s)<countlength(ss))
        c*=-1;
return c;
}


void null(char (&q)[50]){
    int i=0;
for(auto &s : q){s=NULL;i++;}
}


void show(char s[]){
for(int i=0;s[i]!='\0';i++)
    std::cout<<s[i];
}

#endif // MYSTRING_H_INCLUDED
