#ifndef YUFA_H
#define YUFA_H
#include <string>
#include <stdio.h>
#include <sstream>
#include "string.h"
#include <iostream>

using namespace std;

int code_num[1000] = {0};
string code_str[1000];
int x = 0;
string Quadruples[500][4];

const int reserve_num = 17;

char ch;
char token[10];
int syn = 52;

int n = 0;
int m = 0;
int sum_int = 0;
float sum_float = 0.0;
int row = 1;

struct val
{
    string name;
    int type;
    string value;
} V[1500];

char reserve[reserve_num][10] =
{
    "main", "return",
    "void", "int", "double", "char", "bool",
    "if", "else", "while", "for", "break", "continue",
    "true", "false",
    "read", "write"
};
string num_str(int num);

void A();
void C();
void D();
void S();
void E();
void B();
void F();
void G();
void O();

void R();
void H();
void I();
void J();

void Q();
int  L();
int  W();
int  X();
int  K();
int  T();
int  U();
int  P();

class quater
{
    static int row;
public:
    void emit1(string s1,string s2,string s3,string s4)
    {
        Quadruples[row][0] = s1;
        Quadruples[row][1] = s2;
        Quadruples[row][2] = s3;
        Quadruples[row][3] = s4;
        row++;
    }
    void disp(FILE *fp)
    {
        for(int i=0; i<row; i++)
        {
            fprintf(fp,"(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
            printf("(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
        }
    }
};
int quater::row = 0;

class lexical
{
    int n;
    char str[100];
public:
    lexical()
    {
        int n = 0;
    }
    void save(FILE *fp)
    {
        int k = 0;
        while(!feof(fp))
        {
            fscanf(fp, "%d %s", &n, str);
            code_num[k] = n;
            code_str[k] = str;
            k++;
        }
    }
    int getsym()
    {
        return code_num[x++];
    }
    int get_num()
    {
        for(int i=0; (V[i].name).size(); i++)
            if(V[i].name == code_str[x-1])
                return i;
        return -1;
    }
};

class syntactic
{
    static int i, j, reg;
    static int count_label;
    lexical Lex;
    quater Qua;
public:
    int sym;
    syntactic()
    {
        sym = 52;
    }
    void A()
    {
        if(sym == 4)
        {
            cout << "'int' OK " << endl;
            sym = Lex.getsym();
            if(sym == 1)
            {
                cout << "'main' OK " << endl;
                sym = Lex.getsym();
                if(sym == 48)
                {
                    cout << "'(' OK " << endl;
                    sym = Lex.getsym();
                    if(sym == 49)
                    {
                        cout << "')' OK " << endl;
                        sym = Lex.getsym();
                        B();
                    }
                    else
                        cout << "error! not find')'" << endl;
                }
                else
                    cout << "error! not find'('" << endl;
            }
            else
                cout << "error! not find'main'" << endl;
        }
        else
            cout << "error! not find'int'" << endl;
    }
    void C()
    {
        D();
        E();
        if(sym == 48)
        {
            cout << "'(' OK " << endl;
            sym = Lex.getsym();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
                B();
            }
            else
                cout << "error! not find')'" << endl;
        }
        else
            cout << "error! not find'('" << endl;
    }
    void D()
    {
        switch(sym)
        {
            case 3: cout << "'void' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 4: cout << "'int' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 5: cout << "'double' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 6: cout << "'char' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 7: cout << "'bool' OK " << endl;
                    sym = Lex.getsym();
                    break;
            default: cout << "error! not find<type>" << endl;
                    break;
        }
    }
    void S()
    {
        switch(sym)
        {
            case 3: cout << "'void' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 4: cout << "'int' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 5: cout << "'double' OK " << endl;
                    sym = Lex.getsym();
                    break;
            case 6: cout << "'char' OK " << endl;
                    sym = Lex.getsym();
                    break;
            default: cout << "error! not find<type>" << endl;
                    break;
        }
    }
    void E()
    {
        if(sym == 21)
        {
            cout << "<name> OK " << endl;
            sym = Lex.getsym();
        }
        else
            cout << "error! not find<name>" << endl;
    }
    void B()
    {
        if(sym == 46)
        {
            cout << "'{' OK " << endl;
            sym = Lex.getsym();
            while(sym==46||(sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11))
            {
                if(sym == 46)
                    B();
                else
                    F();
            }
            if(sym == 47)
            {
                cout << "'}' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find'}'" << endl;
        }
        else
            cout << "error! not find'{'" << endl;
    }
    void F()
    {
        G();
        while((sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11)||sym==2)
            G();
    }
    void G()
    {
        if(sym>=3 && sym<=7)
            O();
        else if(sym == 21)
            H();
        else if(sym == 8)
            I();
        else if(sym==10 || sym==11)
            J();
        else if(sym == 2)
            Q();
        else
            cout << "error! not find<yuju>" << endl;
    }
    void O()
    {
        V[i].type = sym;
        if(sym == 7)
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<name>' OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                V[i].name = code_str[x-1];
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    int t = L();
                    if(V[i].type != V[t].type)
                    {
                        cout << "yuyierror bianliangleixing not match" << endl;
                        exit(0);
                    }
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else
                        cout << "error! not find';'" << endl;
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find'=' or ';'" << endl;
            }
            else
            {
                cout << "error! not find<name>" << endl;
                exit(0);
            }
        }
        else
        {
            S();
            if(sym == 21)
            {
                cout << "<name> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                V[i].name = code_str[x-1];
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    int t = K();
                    if(V[i].type != V[t].type)
                    {
                        cout << "yuyierror bianliangleixing not match" << endl;
                        exit(0);
                    }
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else
                        cout << "error! not find';'" << endl;
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find'=' or ';'" << endl;
            }
            else
            {
                cout << "error! not find<name>" << endl;
                exit(0);
            }
        }
    }
    void R()
    {
        if(sym == 21)
        {
            cout << "<name> OK " << endl;
            int num = Lex.get_num();
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7)
                    t = L();
                else
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
            }
            else
                cout << "error! not find'='" << endl;
        }
        else
            cout << "error! not find<name>" << endl;
    }
    void H()
    {
        if(sym == 21)
        {
            cout << "<token> OK " << endl;
            int num = Lex.get_num();
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7)
                    t = L();
                else
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                if(sym==59)
                {
                    cout<<"'++' OK"<<endl;
                    sym=Lex.getsym();
                    if(sym == 44)
                    {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                    }
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
                    Qua.emit1("++","_","_",V[num].name);
                }
                else if(sym==61)
                {
                    cout<<"'--' OK"<<endl;
                    sym=Lex.getsym();
                    if(sym == 44)
                    {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                    }
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
                    Qua.emit1("--","_","_",V[num].name);
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
                }
                else
                {
                    cout << "error! not find';'" << endl;
                    Qua.emit1("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
                }

            }
            else if(sym==58)
            {
                cout << "'+=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7)
                    t = L();
                else
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
                Qua.emit1("+=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
             }
             else if(sym ==60)
             {

                cout << "'-=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7)
                    t = L();
                else
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
                Qua.emit1("-=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
             }
             else if(sym==59)
             {
                cout<<"'++' OK"<<endl;
                sym = Lex.getsym();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                 else
                    cout << "error! not find';'" << endl;
                Qua.emit1("++","_","_",V[num].name);
             }
              else if(sym==61)
             {
                cout<<"'--' OK"<<endl;
                sym = Lex.getsym();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                 else
                    cout << "error! not find';'" << endl;
                Qua.emit1("--","_","_",V[num].name);
             }
             else
                cout << "error! not find'=''+=''-='" << endl;
        }
        else
            cout << "error! not find<name>" << endl;
    }
    void I()
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' OK " << endl;
                sym = Lex.getsym();
                int t1 = L();
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find')'" << endl;
                string label1 = "label" + num_str(count_label++);
                string label2 = "label" + num_str(count_label++);
                Qua.emit1("JZ",(V[t1].value.size())?V[t1].value:V[t1].name,"_",label1);
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                {
                    G();
                    Qua.emit1("JP","_","_",label2);
                }
                else if(sym == 46)
                {
                    B();
                    Qua.emit1("JP","_","_",label2);
                }
                Qua.emit1(label1,"_","_","_");
                if(sym == 9)
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                        G();
                    else if(sym == 46)
                        B();
                    Qua.emit1(label2,"_","_","_");
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                {
                    printf("error! not findFollow\n");
                }
            }
            else
                cout << "error! not find'('" << endl;
        }
        else
            cout << "error! not find'if'" << endl;
    }
    void J()
    {
        if(sym == 10)
        {
            cout << "'while' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find'('" << endl;
            string label1 = "label" + num_str(count_label++);
            string label2 = "label" + num_str(count_label++);
            Qua.emit1(label1,"_","_","_");
            int t = L();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            Qua.emit1("JZ",(V[t].value.size())?V[t].value:V[t].name,"_",label2);
            B();
            Qua.emit1("JP","_","_",label1);
            Qua.emit1(label2,"_","_","_");
        }
        else if(sym == 11)
        {
            cout << "'for' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find'('" << endl;
            if(sym == 21)
                H();
            else
                O();
            string label1 = "label" + num_str(count_label++);
            string label2 = "label" + num_str(count_label++);
            string label3 = "label" + num_str(count_label++);
            string label4 = "label" + num_str(count_label++);
            Qua.emit1(label1,"_","_","_");
            int t = L();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find';'" << endl;
            Qua.emit1("JZ",(V[t].value.size())?V[t].value:V[t].name,"_",label4);
            Qua.emit1("JP","_","_",label2);
            Qua.emit1(label3,"_","_","_");
            R();
            Qua.emit1("JP","_","_",label1);
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            Qua.emit1(label2,"_","_","_");
            B();
            Qua.emit1("JP","_","_",label3);
            Qua.emit1(label4,"_","_","_");
        }
        else
            cout << "'while' or 'for' fail" << endl;
    }
    void Q()
    {
        if(sym == 2)
        {
            cout << "'return' OK " << endl;
            sym = Lex.getsym();
            int t = K();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find';'" << endl;
            Qua.emit1("return",(V[t].value.size())?V[t].value:V[t].name,"_","_");
        }
        else
            cout << "ERROR! 'return' missing" << endl;
    }
    int L()
    {
        int t1 = W();
        int t = t1;
        while(sym == 57)
        {
            cout << "'|' OK " << endl;
            sym = Lex.getsym();
            int t2 = W();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            Qua.emit1("|",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);
        }
        return t;
    }
    int W()
    {
        int t1 = X();
        int t = t1;
        while(sym == 56)
        {
            cout << "'&' OK " << endl;
            sym = Lex.getsym();
            int t2 = X();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            Qua.emit1("&",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);
        }
        return t;
    }
    int X()
    {
        int t1;
        if(sym == 48)
        {
            cout << "'(' OK " << endl;
            sym = Lex.getsym();
            t1 = L();
            if(sym == 49)
            {
                cout << "')' OK "<< endl;
                sym = Lex.getsym();
            }
            else
                cout << "ERROR! ')' missing" << endl;
            return t1;
        }
        else if((sym>=21 && sym<=23)||sym==14||sym==15)
        {
            if(sym==14 || sym==15)
                t1 = P();
            else
                t1 = K();
            if(sym>=37 && sym<=42)
            {
                cout << "<relop> OK " << endl;
                int op = sym;
                sym = Lex.getsym();
                int t2;
                if(sym==14 || sym==15)
                    t2 = P();
                else
                    t2 = K();
                V[j].name = "tmp" + num_str(1000-j);
                V[j].type = V[t1].type;
                int t3 = j--;
                switch(V[t2].type)
                {
                    case 3:
                    {
                        cout << "yuyierror bianliangleixing not match" << endl;
                        exit(0);
                    }
                    case 4:
                    case 5:
                    case 6:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "yuyierror bianliangleixing not match" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: Qua.emit1("<",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 38: Qua.emit1("!=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 39: Qua.emit1("<=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 40: Qua.emit1(">",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 41: Qua.emit1(">=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 42: Qua.emit1("==",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                        }
                        V[t3].type = 7;
                        break;
                    }
                }
                return t3;
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                printf("error! not findFollow\n");
                exit(0);
            }
            else
                return t1;
        }
        else
        {
            cout << "error! not find<boolyinzi>" << endl;
            exit(0);
        }
    }
    int K()
    {
        int t1 = T();
        int t = t1;
        while(sym==31 || sym==32)
        {
            int op = sym;
            if(sym == 31)
            {
                cout << "'+' OK " << endl;
                sym = Lex.getsym();
            }
            else if(sym == 32)
            {
                cout << "'-' OK " << endl;
                sym = Lex.getsym();
            }
            int t2 = T();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            if(V[t].type != V[t2].type)
            {
                cout << "yuyi error bianliangleixing not match" << endl;
                exit(0);
            }
            switch(op)
            {
                case 31:Qua.emit1("+",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 32:Qua.emit1("-",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
            }
        }

        return t;
    }
    int T()
    {

        int t1 = U();
        int t = t1;
        while(sym==33 || sym==34 ||sym==55)
        {
            int op = sym;
            if(sym == 33)
            {
                cout << "'*' OK " << endl;
                sym = Lex.getsym();
            }
            else if(sym == 34)
            {
                cout << "'/' OK " << endl;
                sym = Lex.getsym();
            }
            else if(sym == 55)
            {
                cout << "'%' OK"<<endl;
                sym= Lex.getsym();
            }
            int t2 = U();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            if(V[t].type != V[t2].type)
            {
                cout << "yuyierror bianliangleixing not match" << endl;
                exit(0);
            }
            switch(op)
            {
                case 33:Qua.emit1("*",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 34:Qua.emit1("/",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 55:Qua.emit1("%",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
            }
        }
        return t;
    }
    int U()
    {
        int t;
        if(sym == 48)
        {
            cout << "'(' OK " << endl;
            sym = Lex.getsym();
            t = K();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
        }
        else if(sym>=21 || sym<=23)
            t = P();
        else
            cout << "error! not find<yinzi>" << endl;
        return t;
    }
    int P()
    {
        int num;
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK " << endl;
            if(sym == 21)
                num = Lex.get_num();
            else
            {
                V[1000+reg].value = code_str[x-1];
                V[1000+reg].type = sym - 18;
                num = 1000 + reg++;
            }
            sym = Lex.getsym();
            return num;
        }
        else if(sym==14 || sym==15)
        {
            cout << "'true' or 'false' OK " << endl;
            V[1000+reg].value = code_str[x-1];
            V[1000+reg].type = 7;
            num = 1000 + reg++;
            sym = Lex.getsym();
            return num;
        }
        else
        {
            cout << "error! not find<ID|NUM>" << endl;
            return -1;
        }
    }
};
int syntactic::count_label = 1;
int syntactic::i = 0;
int syntactic::j = 999;
int syntactic::reg = 0;



#endif // YUFA_H
