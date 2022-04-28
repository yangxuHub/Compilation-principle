#ifndef CIFAFINXI_H
#define CIFAFINXI_H
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include "yufa.h"

using namespace std;
#pragma execution_character_set("utf-8")

class cifafinxi
{
public:
    cifafinxi();
};

char* fileread;
char fileread1[50];
char filewrite[] = "D:/YY's-Editor-master/YY's-Editor-master/CIFA.txt";

void scan(FILE *fp)
{

    for(n=0; n<10; n++)
        token[n] = '\0';
    ch = fgetc(fp);
    while(ch==' '||ch=='\t')
        ch = fgetc(fp);

    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        m = 0;
        do
        {
            token[m++] = ch;
            ch = fgetc(fp);
        }while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||(ch=='_'));
        fseek(fp, -1, SEEK_CUR);
        token[m] = '\0';
        syn = 21;
        for(n=0; n<reserve_num; n++)
            if(strcmp(token, reserve[n])==0)
            {
                syn = n+1;
                break;
            }
    }

    else if(ch>='0' && ch<='9')
    {
        sum_int = 0;
        sum_float = 0.0;
        while(ch>='0' && ch<='9')
        {
            sum_int = sum_int * 10 + ch - '0';
            ch = fgetc(fp);
        }
        if(sum_int > 2147483647)
            syn = -1;
        else
        {
            if(ch == '.')
            {
                int cnt = 0;
                sum_float = float(sum_int);
                ch = fgetc(fp);
                while(ch>='0' && ch<='9')
                {
                    sum_float += (ch-'0') / pow(10, ++cnt);
                    ch = fgetc(fp);
                }
                syn = 23;
            }
            else
                syn = 22;
        }
        fseek(fp, -1, SEEK_CUR);
    }

       else if(ch == '-')
       {
           fseek(fp, -2, SEEK_CUR);
           ch = fgetc(fp);
           if((ch>='0' && ch<='9')||(ch>='A' && ch<='z'))
           {
               ch = fgetc(fp);
               token[0] = ch;
               ch = fgetc(fp);
               if(ch=='=')
               {
                   token[1]=ch;
                   syn=60;
               }
               else if(ch=='-')
               {
                   token[1]=ch;
                   syn=61;
               }
               else
               {
                   syn=32;
                   fseek(fp, -1, SEEK_CUR);
               }
           }
           else
           {
               fseek(fp, 1, SEEK_CUR);
               ch = fgetc(fp);
               if(ch>='0' && ch<='9')
               {
                   sum_int = 0;
                   sum_float = 0.0;
                   while(ch>='0' && ch<='9')
                   {
                       sum_int = sum_int * 10 + ch - '0';
                       ch = fgetc(fp);
                   }
                   if(sum_int > 2147483647)
                       syn = -1;
                   else
                   {
                       if(ch == '.')
                       {
                           int cnt = 0;
                           sum_float = float(sum_int);
                           ch = fgetc(fp);
                           while(ch>='0' && ch<='9')
                           {
                               sum_float += (ch-'0') / pow(10, ++cnt);
                               ch = fgetc(fp);
                           }
                           sum_float = -sum_float;
                           syn = 23;
                       }
                       else
                       {
                           sum_int = -sum_int;
                           syn = 22;
                       }
                   }
                   fseek(fp, -1, SEEK_CUR);
               }
           }
       }

       else switch(ch)
       {
           case'/': token[0] = ch;
                    ch = fgetc(fp);
                    if(ch == '/')
                    {
                        while(fgetc(fp) != '\n');
                        syn = -3;
                    }
                    else if(ch == '*')
                    {
                        while(1)
                        {
                            while(fgetc(fp) != '*');
                            if(fgetc(fp) == '/')
                               break;
                        }
                        syn = -3;
                    }
                    else
                    {
                        syn = 34;
                        fseek(fp, -1, SEEK_CUR);
                    }
                    break;
           case'<': token[0] = ch;
                    ch = fgetc(fp);
                    if(ch == '=')
                    {
                        token[1] = ch;
                        syn = 39;
                    }
                    else
                    {
                        syn = 37;
                        fseek(fp, -1, SEEK_CUR);
                    }
                    break;
           case'>': token[0] = ch;
                    ch = fgetc(fp);
                    if(ch == '=')
                    {
                        token[1] = ch;
                        syn = 41;
                    }
                    else
                    {
                        syn = 40;
                        fseek(fp, -1, SEEK_CUR);
                    }
                    break;
           case'=': token[0] = ch;
                    ch = fgetc(fp);
                    if(ch == '=')
                    {
                        token[1] = ch;
                        syn = 42;
                    }
                    else
                    {
                        syn = 36;
                        fseek(fp, -1, SEEK_CUR);
                    }
                    break;
           case'!': token[0] = ch;
                    ch = fgetc(fp);
                    if(ch == '=')
                    {
                        token[1] = ch;
                        syn = 38;
                    }
                    else
                    {
                        syn = 43;
                        fseek(fp, -1, SEEK_CUR);
                    }
                    break;
           case'*': syn=33;
                    token[0]=ch;
                    break;
           case'+':
                    token[0]=ch;
                    ch=fgetc(fp);
                    if(ch=='=')
                    {
                       token[1]=ch;
                       syn=58;
                    }
                    else if(ch=='+')
                    {
                       token[1]=ch;
                       syn=59;
                    }
                    else
                    {
                       syn=31;
                       fseek(fp, -1, SEEK_CUR);
                    }
                    break;

           case':': syn=35;
                    token[0]=ch;
                    break;
           case';': syn=44;
                    token[0]=ch;
                    break;
           case',': syn=45;
                    token[0]=ch;
                    break;
           case'{': syn=46;
                    token[0]=ch;
                    break;
           case'}': syn=47;
                    token[0]=ch;
                    break;
           case'[': syn=50;
                    token[0]=ch;
                    break;
           case']': syn=51;
                    token[0]=ch;
                    break;
           case'(': syn=48;
                    token[0]=ch;
                    break;
           case')': syn=49;
                    token[0]=ch;
                    break;
           case'#': syn=52;
                    token[0]=ch;
                    break;
           case'"': syn=53;
                    token[0]=ch;
                    break;
           case'.': syn=54;
                    token[0]=ch;
                    break;
           case'%': syn=55;
                    token[0]=ch;
                    break;
           case'&': syn=56;
                    token[0]=ch;
                    break;
           case'|': syn=57;
                    token[0]=ch;
                    break;
           case'\n': syn=-2;
                     break;
           case EOF: syn=0;
                     break;
           default:  syn=-1;
                     break;
       }
   }

#endif // CIFAFINXI_H
