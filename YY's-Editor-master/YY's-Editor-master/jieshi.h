#ifndef JIESHI_H
#define JIESHI_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
#pragma execution_character_set("utf-8")
char fileread3[] = "D:/YY's-Editor-master/YY's-Editor-master/CIFA.txt";
char filewrite3[] = "D:/YY's-Editor-master/YY's-Editor-master/JIESHI.txt";

int code_num1[1000] = {0};
string code_str1[1000];
int xx = 0;
string result;

struct vall
{
    string name;
    int type;
    string value;
} VV[1000];

void A();void B();void C();void D();void E();void F();
void G();void H();void I();void J();int K();int L();
void O();int P();void Q();void R();void S();int T();
int U();int W();int X();
void A1();void B1();void C1();void D1();void E1();
void F1();void G1();void H1();void I1();void J1();
void K1();void K1_();void L1();void L1_();void O1();
void P1();void Q1();void R1();void S1();


class transform1
{
public:
    string num_str(int num)
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }
    int str_int(string s)
    {
        int num;
        stringstream ss;
        ss << s;
        ss >> num;
        return num;
    }
    string num_str(double num)
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }
    double str_double(string s)
    {
        double num;
        stringstream ss;
        ss << s;
        ss >> num;
        return num;
    }
    char str_char(string s)
    {
        char c;
        stringstream ss;
        ss << s;
        ss >> c;
        return c;
    }
};
class output1
{
    string p[8];
public:
    output1()
    {
        p[3] = "void";
        p[4] = "int";
        p[5] = "double";
        p[6] = "char";
        p[7] = "bool";
    }
    void define(FILE* fp)
    {
        fprintf(fp, "%s\n", "define bianliang:");
        printf("%s\n", "define bianliang:");
        for(int k=0; VV[k].name.size(); k++)
        {
            fprintf(fp,"%s %s %s\n",VV[k].name.c_str(),p[VV[k].type].c_str(),VV[k].value.c_str());
            printf("%s %s %s\n",VV[k].name.c_str(),p[VV[k].type].c_str(),VV[k].value.c_str());
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    void middle(FILE* fp)
    {
        fprintf(fp, "%s\n", "zhongjianbianliang:");
        printf("%s\n", "zhongjianbianliang:");
        for(int k=999; VV[k].name.size(); k--)
        {
            fprintf(fp,"%s %s %s\n",VV[k].name.c_str(),p[VV[k].type].c_str(),VV[k].value.c_str());
            printf("%s %s %s\n",VV[k].name.c_str(),p[VV[k].type].c_str(),VV[k].value.c_str());
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    void answer(FILE* fp)
    {
        cout << "result:" << endl;
        cout << result << endl;
        fprintf(fp,"result:\n");
        fprintf(fp,result.c_str());
        fprintf(fp,"\n");
    }
};

class lexical1
{
    int n;
    char str[100];
public:
    lexical1()
    {
        int n = 0;
    }
    void save(FILE *fp)
    {
        int k = 0;
        while(!feof(fp))
        {
            fscanf(fp, "%d %s", &n, str);
            code_num1[k] = n;
            code_str1[k] = str;
            k++;
        }
    }
    int getsym()
    {
        return code_num1[xx++];
    }
    int get_num()
    {
        for(int i=0; (VV[i].name).size(); i++)
            if(VV[i].name == code_str1[xx-1])
                return i;
        return -1;
    }
};

class jieshi
{
    static int i, j;
    lexical1 Lex;
    transform1 Tra;
public:
    int sym;
    jieshi()
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
                    VV[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 4: cout << "'int' OK " << endl;
                    VV[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 5: cout << "'double' OK " << endl;
                    VV[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 6: cout << "'char' OK " << endl;
                    VV[i].type = sym;
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
            cout << "<hanshuming> OK " << endl;
            sym = Lex.getsym();
        }
        else
            cout << "error! not find<bianliangming>" << endl;
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
        VV[i].type = sym;
        if(sym == 7)
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<bianliangming>' OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                VV[i].name = code_str1[xx-1];
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    int t = L();

                    VV[i++].value = VV[t].value;

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
                cout << "error! not find<bianliangming>" << endl;
                exit(0);
            }
        }
        else
        {
            S();
            if(sym == 21)
            {
                cout << "<bianliangming> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                VV[i].name = code_str1[xx-1];
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    int t = K();
                    if(VV[i].type != VV[t].type)
                    {
                        cout << "yuyierror bianliangleixing not match" << endl;
                        exit(0);
                    }
                    VV[i++].value = VV[t].value;
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
                cout << "error! not find<bianliangming>" << endl;
                exit(0);
            }
        }
    }

    void R()
    {
        if(sym == 21)
        {
            cout << "<bianliangming> OK " << endl;
            int num = Lex.get_num();
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(VV[num].type == 7) // bool
                    t = L();
                else
                    t = K();
                if(VV[num].type != VV[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                else
                    VV[num].value = VV[t].value;
            }
            else
                cout << "error! not find'='" << endl;
        }
        else
            cout << "error! not find<bianliangming>" << endl;
    }

    void H()
    {
        if(sym == 21)
        {
            cout << "<bianliangming> OK " << endl;
            int num = Lex.get_num();
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(VV[num].type == 7) // bool
                    t = L();
                else
                    t = K();
                if(VV[num].type != VV[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                else
                    VV[num].value =VV[t].value;
                if(sym==59)
                {
                    cout<<"'++' OK"<<endl;
                    sym=Lex.getsym();
                    if(sym == 44)
                    {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                    }
                    VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)+1);
                    VV[j].name = "tmp" + Tra.num_str(1000-j);
                    VV[j].type = VV[num].type;
                    VV[j].value = VV[num].value;
                    j--;

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
                    VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)-1);

                    VV[j].name = "tmp" + Tra.num_str(1000-j);
                    VV[j].type = VV[num].type;
                    VV[j].value = VV[num].value;
                    j--;

                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else if(sym==58)
            {
                cout << "'+=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(VV[num].type == 7)
                    t = L();
                else
                    t = K();
                if(VV[num].type != VV[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                else if(VV[num].type==4)
                {
                    VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)+Tra.str_int(VV[t].value));
                }
                else if(VV[num].type==5)
                {
                    VV[num].value = Tra.num_str(Tra.str_double(VV[num].value)+Tra.str_double(VV[t].value));
                }

                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else if(sym==60)
            {
                cout << "'-=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(VV[num].type == 7)
                    t = L();
                else
                    t = K();
                if(VV[num].type != VV[t].type)
                {
                    cout << "yuyierror bianliangleixing not match" << endl;
                    exit(0);
                }
                else if(VV[num].type==4)
                {
                    VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)-Tra.str_int(VV[t].value));
                }
                else if(VV[num].type==5)
                {
                    VV[num].value = Tra.num_str(Tra.str_double(VV[num].value)-Tra.str_double(VV[t].value));
                }
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
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
                VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)+1);
                VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].type = VV[num].type;
                VV[j].value = VV[num].value;
                j--;

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
               VV[num].value = Tra.num_str(Tra.str_int(VV[num].value)-1);
               VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].type = VV[num].type;
                VV[j].value = VV[num].value;
                j--;

            }
            else
                cout << "error! not find'=''+=''-='" << endl;
        }
        else
            cout << "error! not find<bianliangming>" << endl;
    }

    void I()
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' succed " << endl;
                sym = Lex.getsym();
                int t1 = L();
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find')'" << endl;
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                {
                    if(VV[t1].value[0] == 't') // true
                        G();
                    else
                        G1();
                }
                else if(sym == 46)
                {
                    if(VV[t1].value[0] == 't') // true
                        B();
                    else
                        B1();
                }
                if(sym == 9) // else
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                    {
                        if(VV[t1].value[0] == 't') // true
                            G1();
                        else
                            G();
                    }
                    else if(sym == 46)
                    {
                        if(VV[t1].value[0] == 't') // true
                            B1();
                        else
                            B();
                    }
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                    cout << "error! not findFollow" << endl;
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
            int x1 = xx;
            int t = L();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            if(VV[t].value[0] == 'f')
                B1();
            else
            {
                int x2 = xx;
                while(VV[t].value[0] == 't')
                {
                    B();
                    x2 = xx;
                    xx = x1 - 1;
                    sym = Lex.getsym();
                    cout << "sym=" << sym << endl;
                    cout << "x=" << xx << endl;
                    t = L();
                    if(sym == 49)
                    {
                        cout << "')' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else
                        cout << "error! not find')'" << endl;
                }
                xx = x2 - 1;
                sym = Lex.getsym();
            }
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
            int x1 = xx;
            int t = L();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find';'" << endl;
            int x2 = xx;
            R1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            int x3 = xx;
            if(VV[t].value[0] == 'f')
                B1();
            else
            {
                int x4 = xx;
                while(VV[t].value[0] == 't')
                {
                    B();
                    x4 = xx;
                    xx = x2 - 1;
                    sym = Lex.getsym();
                    R();
                    xx = x1 - 1;
                    sym = Lex.getsym();
                    t = L();
                    xx = x3 - 1;
                    sym = Lex.getsym();
                }
                xx = x4 - 1;
                sym = Lex.getsym();
            }
        }
        else
            cout << "error! not find'while' or 'for'" << endl;
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
            result = VV[t].value;
        }
        else
            cout << "error! not find'return'" << endl;
    }

    int L()
    {
        int t1 = W();

        int t3;
        if(VV[t1].type != 7)
        {
           VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t1].type;
            VV[j].value = VV[t1].value;
            t3 = j--;
            if(VV[t3].type == 3) // void
                VV[t3].value = "false";
            else if(VV[t3].type == 4) // int
                VV[t3].value = Tra.str_int(VV[t3].value)>0?"true":"false";
            else if(VV[t3].type == 5) // double
                VV[t3].value = Tra.str_double(VV[t3].value)>0?"true":"false";
            else if(VV[t3].type == 6) // char
                VV[t3].value = VV[t3].value!="\0"?"true":"false";
            VV[t3].type = 7;
        }
        else
            t3 = t1;
        int t = t3;
        while(sym == 57)
        {
            cout << "'|' OK " << endl;
            sym = Lex.getsym();
            int t2 = W();

            int t4;
            if(VV[t4].type != 7)
            {
                VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].type = VV[t2].type;
                VV[j].value = VV[t2].value;
                t4 = j--;
                if(VV[t4].type == 3)
                    VV[t4].value = "false";
                else if(VV[t4].type == 4)
                    VV[t4].value = Tra.str_int(VV[t4].value)>0?"true":"false";
                else if(VV[t4].type == 5)
                    VV[t4].value = Tra.str_double(VV[t4].value)>0?"true":"false";
                else if(VV[t4].type == 6)
                    VV[t4].value = VV[t4].value!="\0"?"true":"false";
                VV[t4].type = 7;
            }
            else
                t4 = t2;
            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t].type;
            VV[j].value = VV[t].value;
            t=j--;
            if(VV[t3].value[0]=='t' ||VV[t4].value[0]=='t')
                VV[t].value = "true";
            else
                VV[t].value = "false";
        }
        return t;
    }

    int W()
    {

        int t1 = X();

        int t3;
        if(VV[t1].type != 7)
        {

            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t1].type;
            VV[j].value = VV[t1].value;
            t3 = j--;
            if(VV[t3].type == 3)
                VV[t3].value = "false";
            else if(VV[t3].type == 4)
                VV[t3].value = Tra.str_int(VV[t3].value)>0?"true":"false";
            else if(VV[t3].type == 5)
                VV[t3].value = Tra.str_double(VV[t3].value)>0?"true":"false";
            else if(VV[t3].type == 6)
                VV[t3].value = VV[t3].value!="\0"?"true":"false";
            VV[t3].type = 7;
        }
        else
        {

            t3 = t1;
        }
        int t = t3;
        while(sym == 56)
        {
            cout << "'&' OK " << endl;
            sym = Lex.getsym();
            int t2 = X();
            int t4;
            if(VV[t4].type != 7)
            {
                VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].type = VV[t2].type;
               VV[j].value = VV[t2].value;
                t4 = j--;
                if(VV[t4].type == 3)
                    VV[t4].value = "false";
                else if(VV[t4].type == 4)
                    VV[t4].value = Tra.str_int(VV[t4].value)>0?"true":"false";
                else if(VV[t4].type == 5)
                    VV[t4].value = Tra.str_double(VV[t4].value)>0?"true":"false";
                else if(VV[t4].type == 6)
                    VV[t4].value = VV[t4].value!="\0"?"true":"false";
                VV[t4].type = 7;
            }
            else
                t4 = t2;
            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t].type;
            VV[j].value = VV[t].value;
            t=j--;
            if(VV[t3].value[0]=='t' && VV[t4].value[0]=='t')
                VV[t].value = "true";
            else
                VV[t].value = "false";
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
                cout << "error! not find')'" << endl;
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
                VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].type = VV[t1].type;
                VV[j].value = VV[t1].value;
                int t3 = j--;

                switch(VV[t2].type)
                {
                    case 3:
                    {
                        cout << "yuyierror bianliangleixing not match" << endl;
                        exit(0);
                    }
                    case 4:
                    {
                        if(VV[t3].type != VV[t2].type)
                        {
                            cout << "yuyierror bianliangleixing not match" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: VV[t3].value=Tra.str_int(VV[t3].value)<Tra.str_int(VV[t2].value)?"true":"false";break;
                            case 38: VV[t3].value=Tra.str_int(VV[t3].value)!=Tra.str_int(VV[t2].value)?"true":"false";break;
                            case 39: VV[t3].value=Tra.str_int(VV[t3].value)<=Tra.str_int(VV[t2].value)?"true":"false";break;
                            case 40: VV[t3].value=Tra.str_int(VV[t3].value)>Tra.str_int(VV[t2].value)?"true":"false";break;
                            case 41: VV[t3].value=Tra.str_int(VV[t3].value)>=Tra.str_int(VV[t2].value)?"true":"false";break;
                            case 42: VV[t3].value=Tra.str_int(VV[t3].value)==Tra.str_int(VV[t2].value)?"true":"false";break;
                        }
                        VV[t3].type = 7;
                        break;
                    }
                    case 5:
                    {
                        if(VV[t3].type != VV[t2].type)
                        {
                            cout << "yuyierror bianliangleixing not match" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: VV[t3].value=Tra.str_double(VV[t3].value)<Tra.str_double(VV[t2].value)?"true":"false";break;
                            case 38: VV[t3].value=Tra.str_double(VV[t3].value)!=Tra.str_double(VV[t2].value)?"true":"false";break;
                            case 39: VV[t3].value=Tra.str_double(VV[t3].value)<=Tra.str_double(VV[t2].value)?"true":"false";break;
                            case 40: VV[t3].value=Tra.str_double(VV[t3].value)>Tra.str_double(VV[t2].value)?"true":"false";break;
                            case 41: VV[t3].value=Tra.str_double(VV[t3].value)<=Tra.str_double(VV[t2].value)?"true":"false";break;
                            case 42: VV[t3].value=Tra.str_double(VV[t3].value)==Tra.str_double(VV[t2].value)?"true":"false";break;
                        }
                        VV[t3].type = 7;
                        break;
                    }
                    case 6:
                    {
                        if(VV[t3].type !=VV[t2].type)
                        {
                            cout << "yuyierror bianliangleixing not match" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: VV[t3].value=Tra.str_char(VV[t3].value)<Tra.str_char(VV[t2].value)?"true":"false";break;
                            case 38: VV[t3].value=Tra.str_char(VV[t3].value)!=Tra.str_char(VV[t2].value)?"true":"false";break;
                            case 39: VV[t3].value=Tra.str_char(VV[t3].value)<=Tra.str_char(VV[t2].value)?"true":"false";break;
                            case 40: VV[t3].value=Tra.str_char(VV[t3].value)>Tra.str_char(VV[t2].value)?"true":"false";break;
                            case 41: VV[t3].value=Tra.str_char(VV[t3].value)<=Tra.str_char(VV[t2].value)?"true":"false";break;
                            case 42: VV[t3].value=Tra.str_char(VV[t3].value)==Tra.str_char(VV[t2].value)?"true":"false";break;
                        }
                       VV[t3].type = 7;
                        break;
                    }
                }
                return t3;
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                cout << "error! not findFollow" << endl;
                exit(0);
            }
            else
            {

                return t1;
            }

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
            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t].type;
            VV[j].value =VV[t].value;
            t = j--;
            if(VV[t].type != VV[t2].type)
            {
                cout << "yuyierror bianliangleixing not match" << endl;
                exit(0);
            }
            if(VV[t].type == 4)
            {
                switch(op)
                {
                    case 31: VV[t].value=Tra.num_str(Tra.str_int(VV[t].value)+Tra.str_int(VV[t2].value));break;
                    case 32: VV[t].value=Tra.num_str(Tra.str_int(VV[t].value)-Tra.str_int(VV[t2].value));break;
                }
            }
            else if(VV[t].type == 5)
            {
                switch(op)
                {
                    case 31: VV[t].value=Tra.num_str(Tra.str_double(VV[t].value)+Tra.str_double(VV[t2].value));break;
                    case 32: VV[t].value=Tra.num_str(Tra.str_double(VV[t].value)-Tra.str_double(VV[t2].value));break;
                }
            }
            else
            {
                cout << "yuyierror bianliangleixing not match" << endl;
                exit(0);
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
                cout<<"'%' OK"<<endl;
                sym = Lex.getsym();
            }
            int t2 = U();
            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].type = VV[t].type;
            VV[j].value = VV[t].value;
            t = j--;
            if(VV[t].type != VV[t2].type)
            {
                cout << "yuyierror bianliangleixing not match" << endl;
                exit(0);
            }
            if(VV[t].type==4)
            {
                switch(op)
                {
                    case 33: VV[t].value=Tra.num_str(Tra.str_int(VV[t].value)*Tra.str_int(VV[t2].value));break;
                    case 34: VV[t].value=Tra.num_str(Tra.str_int(VV[t].value)/Tra.str_int(VV[t2].value));break;
                    case 55: VV[t].value=Tra.num_str(Tra.str_int(VV[t].value)%Tra.str_int(VV[t2].value));break;
                }
            }
            else if(VV[t].type==5) // double
            {
                switch(op)
                {
                    case 33: VV[t].value=Tra.num_str(Tra.str_double(VV[t].value)*Tra.str_double(VV[t2].value));break;
                    case 34: VV[t].value=Tra.num_str(Tra.str_double(VV[t].value)/Tra.str_double(VV[t2].value));break;
                }
            }
            else
            {
                cout << "yuyierror bianliangleixing not match" << endl;
                exit(0);
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
        else if(sym>=21 && sym<=23)
        {
             t = P();
        }

        else
            cout << "error! not find<yinzi>" << endl;
        return t;
    }

    int P()
    {
        int num;
        if(sym>=21 && sym<=23)
        {

            cout<<"<ID or NUM> ok"<<endl;
            if(sym == 21)
             {
                cout<<"if"<<endl;
                num = Lex.get_num();
                cout<<"num"<<endl;
            }
            else
            {
                cout<<"else"<<endl;
                VV[j].name = "tmp" + Tra.num_str(1000-j);
                VV[j].value = code_str1[xx-1];
                VV[j].type = sym - 18;
                num = j--;
            }
            sym = Lex.getsym();
//            cout<<"xx="<<xx<<endl;
//            cout<<"code_num"<<code_num1[xx]<<endl;
//            sym=code_num1[xx];
//            cout<<sym<<endl;
//            xx=xx+1;
//            cout<<(sym);
            return num;
        }
        else if(sym==14 || sym==15)
        {
            cout << "'true' or 'false' OK " << endl;
            VV[j].name = "tmp" + Tra.num_str(1000-j);
            VV[j].value = code_str1[xx-1];
            VV[j].type = 7;
            num = j--;
            sym = Lex.getsym();
            return num;
        }
        else
        {
            cout << "error! not find<ID|NUM>" << endl;
            return -1;
        }
    }

    void S1()
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

    void B1()
    {
        if(sym == 46)
        {
            cout << "'{' OK " << endl;
            sym=Lex.getsym();
            while(sym==46||(sym>=3&&sym<=7)||sym==21||sym==8||sym==10||sym==11)
            {
                if(sym==46)
                    B1();
                else
                    F1();
            }
            if(sym == 47)
            {
                cout << "'}' OK " << endl;
                sym=Lex.getsym();
            }
            else
                cout << "error! not find'}'" << endl;
        }
        else
            cout << "error! not find'{'" << endl;
    }

    void F1()
    {
        G1();
        while(sym==21||(sym>=3&&sym<=7)||sym==8||sym==10||sym==11||sym==2)
            G1();
    }

    void G1()
    {
        if(sym>=3 && sym<=7)
            O1();
        else if(sym == 21)
            H1();
        else if(sym == 8)
            I1();
        else if(sym==10 || sym==11)
            J1();
        else if(sym == 2)
            Q1();
        else
            cout << "error! not find<yuju>" << endl;
    }

    void O1()
    {
        if(sym == 7)
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<token>' OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    L1();
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
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find'=' or ';'" << endl;
            }
            else
            {
                cout << "error! not find<bianliangming>" << endl;
                exit(0);
            }
        }
        else
        {
            S1();
            if(sym == 21)
            {
                cout << "<bianliangming> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "yuyierror bianliangchongfudingyi" << endl;
                    exit(0);
                }
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    K1();
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
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find'=' or ';'" << endl;
            }
            else
            {
                cout << "error! not find<bianliangming>" << endl;
                exit(0);
            }
        }
    }

    void P1()
    {
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK" << endl;
            if(sym == 21)
                int num=Lex.get_num();
            sym=Lex.getsym();
        }
        else if(sym==14 || sym==15)
        {
            cout << "true or false OK" << endl;
            sym=Lex.getsym();
        }
        else
            cout << "error! not find<ID|NUM>" << endl;
    }

    void Q1()
    {
        if(sym == 2)
        {
            cout << "'return' OK " << endl;
            sym = Lex.getsym();
            K1();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find';'" << endl;
        }
        else
            cout << "error! not find'return'" << endl;
    }

    void R1()
    {
        if(sym == 21)
        {
            cout << "<bianliangming> OK " << endl;
            int num = Lex.get_num();
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                if(VV[num].type == 7)
                    L1();
                else
                    K1();
            }
            else
                cout << "error! not find'='" << endl;
        }
        else
            cout << "error! not find<bianliangming>" << endl;
    }

    void H1()
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
                if(VV[num].type == 7)
                    L1();
                else
                    K1();
                if(sym==59)
                {
                    cout<<"'++' OK"<<endl;
                    sym = Lex.getsym();
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
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
                }
                else if(sym == 44)
                {
                    cout<<"';' OK"<<endl;
                    sym = Lex.getsym();
                }
                else
                    cout<<"error! not found';'"<<endl;
            }
            else if(sym==58)
            {
                cout << "'+=' OK " << endl;
                sym = Lex.getsym();
                if(VV[num].type == 7)
                    L1();
                else
                    K1();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else if(sym==60)
            {
                cout << "'-=' OK " << endl;
                sym = Lex.getsym();
                if(VV[num].type == 7)
                    L1();
                else
                    K1();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else if(sym == 59)
            {
                cout<<"'++' OK "<<endl;
                sym = Lex.getsym();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else if(sym == 61)
            {
                cout<<"'--' OK "<<endl;
                sym = Lex.getsym();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find';'" << endl;
            }
            else
                cout << "error! not find'=''+=''-='" << endl;
        }
        else
            cout << "error! not find<bianliangming>" << endl;
    }

    void I1()
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' succed " << endl;
                sym = Lex.getsym();
                L1();
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "error! not find')'" << endl;
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                    G1();
                else if(sym == 46)
                    B1();
                if(sym == 9)
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                        G1();
                    else if(sym == 46)
                        B1();
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                    cout << "error! not findFollow" << endl;
            }
            else
                cout << "error! not find'('" << endl;
        }
        else
            cout << "error! not find'if'" << endl;
    }

    void J1()
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
            L1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            B1();
        }
        else if(sym == 11) // for
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
                H1();
            else
                O1();
            L1();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find';'" << endl;
            R1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            B1();
        }
        else
            cout << "error! not find'for'" << endl;
    }

    void L1()
    {
        if((sym>=21&&sym<=23) || sym==14 || sym==15)
        {
            P1();
            if(sym>=37 && sym<=42)
            {
                cout << "<relop> OK " << endl;
                sym = Lex.getsym();
                P1();
                L1_();
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                cout << "error! not findFollow" << endl;
                exit(0);
            }
            else
                L1_();
        }
        else if(sym == 48)
        {
            cout << "'(' OK " << endl;
            sym = Lex.getsym();
            L1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
            L1_();
        }
        else
        {
            cout << "error! not find<bool biaodashi>" << endl;
            exit(0);
        }
    }

    void L1_()
    {
        if(sym==56 || sym==57)
        {
            sym = Lex.getsym();
            L1();
            L1_();
        }
        else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
        {
            cout << "error! not findFollow" << endl;
            exit(0);
        }
    }

    void K1()
    {
        if(sym == 48)
        {
            cout << "'(' OK " << endl;
            sym = Lex.getsym();
            K1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "error! not find')'" << endl;
        }
        else if(sym>=21 && sym<=23)
            P1();
        else
            cout << "error! not find<suanshubiaodashi>" << endl;
        K1_();
    }

    void K1_()
    {
        if(sym>=31 && sym<=34)
        {
            cout << "'+-*/' OK " << endl;
            sym = Lex.getsym();
            K1();
            K1_();
        }
        else if((sym<31||sym>34)&&sym!=44&&sym!=49)
        {
            cout << "error! not find Follow" << endl;
            exit(0);
        }
    }
};
int jieshi::i = 0;
int jieshi::j = 999;

#endif // JIESHI_H
