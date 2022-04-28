#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include<math.h>
using namespace std;

/*��������ļ�*/
char file_in[] = "./eryuanzu.txt";
char file_out[] = "./jieshiqi.txt";
/*�洢�ֱ��뼰����Ӧ����*/
int code_num[1000] = {0};
string code_str[1000]; //�洢�ֱ����Ӧ���ַ���
int x = 0; // x�ǵ��������еļ�����
string result; // ����������

void A();void B();void C();void D();void E();void F();
void G();void H();void I();void J();int K();int L();
void O();int P();void Q();void R();void S();int T();
int U();int W();int X();
void A1();void B1();void C1();void D1();void E1();
void F1();void G1();void H1();void I1();void J1();
void K1();void K1_();void L1();void L1_();void O1();
void P1();void Q1();void R1();void S1();

struct val  // �����ṹ��   ���ű�ṹ
{
    string name; // ������
    int type;  // ֵ���͵��ֱ��� 
    string value; // code_str�����д洢���ַ���(���Դʷ�����)
} V[1000];

class transform // ����ת����
{
public:
    string num_str(int num)//����ת�ַ���
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }
    int str_int(string s)//�ַ���ת����
    {
        int num;
        stringstream ss;
        ss << s;
        ss >> num;
        return num;
    }
    string num_str(double num)//����ת�ַ���
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }
    double str_double(string s)//�ַ���ת����
    {
        double num;
        stringstream ss;
        ss << s;
        ss >> num;
        return num;
    }
    char str_char(string s)//�ַ���ת�ַ�
    {
        char c;
        stringstream ss;
        ss << s;
        ss >> c;
        return c;
    }
};

class output // �����
{
    string p[8];
public:
    output()
    {
        p[3] = "void";
        p[4] = "int";
        p[5] = "double";
        p[6] = "char";
        p[7] = "bool";
    }
    void define(FILE* fp) // ����������
    {
        fprintf(fp, "%s\n", "�������: ");
        printf("%s\n", "�������: ");
        for(int k=0; V[k].name.size(); k++)
        {
            fprintf(fp,"%s %s %s\n",V[k].name.c_str(),p[V[k].type].c_str(),V[k].value.c_str());
            printf("%s %s %s\n",V[k].name.c_str(),p[V[k].type].c_str(),V[k].value.c_str());
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    void middle(FILE* fp) // ����м����
    {
        fprintf(fp, "%s\n", "�м����:");
        printf("%s\n", "�м����:");
        for(int k=999; V[k].name.size(); k--)
        {
            fprintf(fp,"%s %s %s\n",V[k].name.c_str(),p[V[k].type].c_str(),V[k].value.c_str());
            printf("%s %s %s\n",V[k].name.c_str(),p[V[k].type].c_str(),V[k].value.c_str());
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    void answer(FILE* fp)
    {
        cout << "���н��: " << endl;
        cout << result << endl;
        fprintf(fp,"���н��: \n");
        fprintf(fp,result.c_str());
        fprintf(fp,"\n");
    }
};

class lexical // �ʷ���
{
    int n; // �ļ��ж�ȡ�����ֱ���
    char str[100]; // �ļ��ж�ȡ���ĵ���
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
            fscanf(fp, "%d %s", &n, str); //��ȡ��Ԫʽ
            code_num[k] = n; //�洢�ֱ���
            code_str[k] = str; //�洢����
            k++;
        }
    }
    int getsym()
    {
        return code_num[x++]; //��ȡ��һ������
    }
    int get_num() // �������������ַ���ƥ�䣬�����ڷ��ر�������ţ������ڷ���-1,�����±�ʶ���������
    {
        for(int i=0; (V[i].name).size(); i++) // �����������ʱ�ǿ�ʱ��ѭ��
            if(V[i].name == code_str[x-1])
                return i;
        return -1;
    }
};

class interpreter // ���ͳ�����
{
    static int i, j;
    lexical Lex;
    transform Tra;
public:
    int sym; // sym�Ǹõ��ʵ��ֱ���
    interpreter()
    {
        sym = 52;
    }

    void A() // -> <������>
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
                        cout << "�﷨���� δ�ҵ�')'" << endl;
                }
                else
                    cout << "�﷨���� δ�ҵ�'('" << endl;
            }
            else
                cout << "�﷨���� δ�ҵ�'main'" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'int'" << endl;
    }

    void C() // -> <����>
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
                cout << "�﷨���� δ�ҵ�')'" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'('" << endl;
    }

    void D() // -> <��������>
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
            default: cout << "�﷨���� δ�ҵ�<type>" << endl;
                    break;
        }
    }

    void S() // -> <��������>
    {
        switch(sym)
        {
            case 3: cout << "'void' OK " << endl;
                    V[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 4: cout << "'int' OK " << endl;
                    V[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 5: cout << "'double' OK " << endl;
                    V[i].type = sym;
                    sym = Lex.getsym();
                    break;
            case 6: cout << "'char' OK " << endl;
                    V[i].type = sym;
                    sym = Lex.getsym();
                    break;
            default: cout << "�﷨���� δ�ҵ�<type>" << endl;
                    break;
        }
    }

    void E() // -> <������>	    
    {
        if(sym == 21) 
        {
            cout << "<������> OK " << endl;
            sym = Lex.getsym();
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }

    void B() // -> <����>
    {
        if(sym == 46)
        {
            cout << "'{' OK " << endl;
            sym = Lex.getsym();
            while(sym==46||(sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11))
            {
                if(sym == 46) // ����
                    B();
                else
                    F(); // ��䴮
            }
            if(sym == 47)
            {
                cout << "'}' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�'}'" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'{'" << endl;
    }

    void F() // -> <��䴮>	
    {
        G();
        while((sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11)||sym==2)
            G();
    }

    void G() // -> <���>
    {
        if(sym>=3 && sym<=7) // �������
            O();
        else if(sym == 21) // ��ֵ���
            H();
        else if(sym == 8) // �������
            I();
        else if(sym==10 || sym==11) // ѭ�����
            J();
        else if(sym == 2) // �������
            Q();
        else
            cout << "�﷨���� δ�ҵ�<���>" << endl;
    }

    void O() // -> <�������>
    {
        V[i].type = sym;
        if(sym == 7) // bool������
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<������>' OK " << endl;
                if(Lex.get_num() != -1) // �Զ�����������Ѿ����ڸñ���
                {
                    cout << "������� �����ظ�����" << endl;
                    exit(0);
                }
                V[i].name = code_str[x-1];
                sym = Lex.getsym();
                if(sym == 36)
                {
                    cout << "'=' OK " << endl;
                    sym = Lex.getsym();
                    int t = L();
                    V[i++].value = V[t].value;
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else    
                        cout << "�﷨���� δ�ҵ�';'" << endl;
                }       
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }   
                else
                    cout << "�﷨���� δ�ҵ�'='��';'" << endl;
            }
            else
            {
                cout << "�﷨���� δ�ҵ�<������>" << endl; 
                exit(0);
            }
        }
        else // �������Ͷ���
        {
            S();
            if(sym == 21)
            {
                cout << "<������> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "������� �����ظ�����" << endl;
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
                        cout << "������� �������Ͳ�ƥ��" << endl;
                        exit(0);
                    }
                    V[i++].value = V[t].value; 
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else    
                        cout << "�﷨���� δ�ҵ�';'" << endl;
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�'='��';'" << endl;
            }
            else
            {
                cout << "�﷨���� δ�ҵ�<������>" << endl; 
                exit(0);
            }
        }
    }

    void R() // -> <��ֵ���ʽ>
    {
        if(sym == 21)
        {
            cout << "<������> OK " << endl;
            int num = Lex.get_num(); // ���ض���ı����������д洢���±�
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7) // bool
                    t = L();
                else    
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "������� �������Ͳ�ƥ��" << endl;
                    exit(0);
                }
                else
                    V[num].value = V[t].value;
            }
            else
                cout << "�﷨���� δ�ҵ�'='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }

    void H() // -> <��ֵ���>
    {
        if(sym == 21)
        {
            cout << "<������> OK " << endl;
            int num = Lex.get_num(); // ���ض���ı����������д洢���±� 
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7) // bool
                    t = L();
                else    
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "������� �������Ͳ�ƥ��" << endl;
                    exit(0);
                }
                else
                    V[num].value = V[t].value;
                if(sym==59)
                {
                	cout<<"'++' OK"<<endl;
                	sym=Lex.getsym();
                	if(sym == 44)
                	{
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                	}					 
					V[num].value = Tra.num_str(Tra.str_int(V[num].value)+1);   
					V[j].name = "tmp" + Tra.num_str(1000-j);
            		V[j].type = V[num].type;
            		V[j].value = V[num].value;
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
					V[num].value = Tra.num_str(Tra.str_int(V[num].value)-1);    
					
					V[j].name = "tmp" + Tra.num_str(1000-j);
            		V[j].type = V[num].type;
            		V[j].value = V[num].value;
            		j--;    
					  	                	
				}          
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
            }
            else if(sym==58)
            {
            	cout << "'+=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7) // bool
                    t = L();
                else    
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "������� �������Ͳ�ƥ��" << endl;
                    exit(0);
                }
                else if(V[num].type==4)//int
                {
                	V[num].value = Tra.num_str(Tra.str_int(V[num].value)+Tra.str_int(V[t].value));
				}
				else if(V[num].type==5)//double
				{
					V[num].value = Tra.num_str(Tra.str_double(V[num].value)+Tra.str_double(V[t].value));
				}
                    
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
			}
			else if(sym==60)
			{
				cout << "'-=' OK " << endl;
                sym = Lex.getsym();
                int t;
                if(V[num].type == 7) // bool
                    t = L();
                else    
                    t = K();
                if(V[num].type != V[t].type)
                {
                    cout << "������� �������Ͳ�ƥ��" << endl;
                    exit(0);
                }
                else if(V[num].type==4)//int
                {
                	V[num].value = Tra.num_str(Tra.str_int(V[num].value)-Tra.str_int(V[t].value));
				}
				else if(V[num].type==5)//double
				{
					V[num].value = Tra.num_str(Tra.str_double(V[num].value)-Tra.str_double(V[t].value));
				}
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
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
                    cout << "�﷨���� δ�ҵ�';'" << endl;
                V[num].value = Tra.num_str(Tra.str_int(V[num].value)+1);
                V[j].name = "tmp" + Tra.num_str(1000-j);
            	V[j].type = V[num].type;
            	V[j].value = V[num].value;
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
                    cout << "�﷨���� δ�ҵ�';'" << endl;
               V[num].value = Tra.num_str(Tra.str_int(V[num].value)-1);
               V[j].name = "tmp" + Tra.num_str(1000-j);
            	V[j].type = V[num].type;
            	V[j].value = V[num].value;
            	j--;
				
			}
            else
                cout << "�﷨���� δ�ҵ�'=''+=''-='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }

    void I() // -> <�������>
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' succed " << endl;
                sym = Lex.getsym();
                int t1 = L(); // �������Ľ������
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�')'" << endl;
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                {
                    if(V[t1].value[0] == 't') // true
                        G();
                    else
                        G1(); // ���﷨����
                }
                else if(sym == 46)
                {
                    if(V[t1].value[0] == 't') // true
                        B();
                    else
                        B1(); // ���﷨����
                }
                if(sym == 9) // else
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                    {
                        if(V[t1].value[0] == 't') // true
                            G1();
                        else
                            G(); // ���﷨����
                    }
                    else if(sym == 46)
                    {
                        if(V[t1].value[0] == 't') // true
                            B1();
                        else
                            B(); // ���﷨����
                    }
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                    cout << "�﷨���� δ�ҵ�Follow��" << endl;
            }
            else    
                cout << "�﷨���� δ�ҵ�'('" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'if'" << endl; 
    }

    void J() // -> <ѭ�����>
    {
        if(sym == 10) // while
        {
            cout << "'while' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�'('" << endl;
            int x1 = x; // ��סL()�ĵ�һ��λ��
            int t = L();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
            if(V[t].value[0] == 'f')
                B1(); // ���﷨����
            else 
            {
                int x2 = x;
                while(V[t].value[0] == 't')
                {
                    B();
                    x2 = x; // ��¼���������λ��
                    x = x1 - 1; // ����������������ж�
                    sym = Lex.getsym();
                    cout << "sym=" << sym << endl;
                    cout << "x=" << x << endl;
                    t = L();
                    if(sym == 49)
                    {
                        cout << "')' OK " << endl;
                        sym = Lex.getsym(); 
                    }
                    else
                        cout << "�﷨���� δ�ҵ�')'" << endl;
                }
                x = x2 - 1;
                sym = Lex.getsym();
            }
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
                cout << "�﷨���� δ�ҵ�'('" << endl;
            if(sym == 21)
                H();
            else
                O();
            int x1 = x; // ��¼�ж�����λ��
            int t = L();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else    
                cout << "�﷨���� δ�ҵ�';'" << endl;
            int x2 = x; // ��¼for����������λ��
            R1(); // �������Ե����������﷨����
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
            int x3 = x; // ��¼for�����λ��
            if(V[t].value[0] == 'f')
                B1(); 
            else
            {
                int x4 = x;
                while(V[t].value[0] == 't')
                {
                    B(); // ִ������
                    x4 = x; // ��¼�������λ��
                    x = x2 - 1; // ִ�������飬ִ��for�ĵ���������
                    sym = Lex.getsym();
                    R();
                    x = x1 - 1; // ִ����for�ĵ����λص��ж����
                    sym = Lex.getsym();
                    t = L();
                    x = x3 - 1; //ִ�����ж������������ 
                    sym = Lex.getsym();
                }
                x = x4 - 1;
                sym = Lex.getsym();
            }
        }
        else
            cout << "�﷨���� δ�ҵ�'while'��'for'" << endl;
    }

    void Q() // -> <�������>
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
                cout << "�﷨���� δ�ҵ�';'" << endl;
            result = V[t].value; // ����������
        }
        else
            cout << "�﷨���� δ�ҵ�'return'" << endl;
    }

    int L() // -> <�������ʽ>
    {
        int t1 = W();
        int t3;
        if(V[t1].type != 7)
        {
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t1].type;
            V[j].value = V[t1].value;
            t3 = j--;
            if(V[t3].type == 3) // void
                V[t3].value = "false";
            else if(V[t3].type == 4) // int
                V[t3].value = Tra.str_int(V[t3].value)>0?"true":"false";
            else if(V[t3].type == 5) // double
                V[t3].value = Tra.str_double(V[t3].value)>0?"true":"false";
            else if(V[t3].type == 6) // char
                V[t3].value = V[t3].value!="\0"?"true":"false";
            V[t3].type = 7;
        }
        else
            t3 = t1;
        int t = t3; // ������һ���м����
        while(sym == 57)
        {
            cout << "'|' OK " << endl;
            sym = Lex.getsym();
            int t2 = W();
            int t4;
            if(V[t4].type != 7)
            {
                V[j].name = "tmp" + Tra.num_str(1000-j);
                V[j].type = V[t2].type;
                V[j].value = V[t2].value;
                t4 = j--;
                if(V[t4].type == 3) // void
                    V[t4].value = "false";
                else if(V[t4].type == 4) // int
                    V[t4].value = Tra.str_int(V[t4].value)>0?"true":"false";
                else if(V[t4].type == 5) // double
                    V[t4].value = Tra.str_double(V[t4].value)>0?"true":"false";
                else if(V[t4].type == 6) // char
                    V[t4].value = V[t4].value!="\0"?"true":"false";
                V[t4].type = 7;
            }
            else
                t4 = t2;
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t].type;
            V[j].value = V[t].value;
            t=j--;
            if(V[t3].value[0]=='t' || V[t4].value[0]=='t')
                V[t].value = "true";
            else
                V[t].value = "false";
        }
        return t;
    }

    int W() // -> <������>
    {
        int t1 = X();
        int t3;
        if(V[t1].type != 7)
        {
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t1].type;
            V[j].value = V[t1].value;
            t3 = j--;
            if(V[t3].type == 3) // void
                V[t3].value = "false";
            else if(V[t3].type == 4) // int
                V[t3].value = Tra.str_int(V[t3].value)>0?"true":"false";
            else if(V[t3].type == 5) // double
                V[t3].value = Tra.str_double(V[t3].value)>0?"true":"false";
            else if(V[t3].type == 6) // char
                V[t3].value = V[t3].value!="\0"?"true":"false";
            V[t3].type = 7;
        }
        else
            t3 = t1;
        int t = t3; // ������һ���м����
        while(sym == 56)
        {
            cout << "'&' OK " << endl;
            sym = Lex.getsym();
            int t2 = X();
            int t4;
            if(V[t4].type != 7)
            {
                V[j].name = "tmp" + Tra.num_str(1000-j);
                V[j].type = V[t2].type;
                V[j].value = V[t2].value;
                t4 = j--;
                if(V[t4].type == 3) // void
                    V[t4].value = "false";
                else if(V[t4].type == 4) // int
                    V[t4].value = Tra.str_int(V[t4].value)>0?"true":"false";
                else if(V[t4].type == 5) // double
                    V[t4].value = Tra.str_double(V[t4].value)>0?"true":"false";
                else if(V[t4].type == 6) // char
                    V[t4].value = V[t4].value!="\0"?"true":"false";
                V[t4].type = 7;
            }
            else
                t4 = t2;
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t].type;
            V[j].value = V[t].value;
            t=j--;
            if(V[t3].value[0]=='t' && V[t4].value[0]=='t')
                V[t].value = "true";
            else
                V[t].value = "false";
        }
        return t;
    }

    int X() // -> <��������>
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
                cout << "�﷨���� δ�ҵ�')'" << endl;
            return t1;
        }
        else if((sym>=21 && sym<=23)||sym==14||sym==15)
        {
            if(sym==14 || sym==15)  //true false
                t1 = P();
            else //��ʶ�� ���γ��� �����ͳ��� 
                t1 = K();
            if(sym>=37 && sym<=42) //< != <= > >= == 
            {
                cout << "<relop> OK " << endl;
                int op = sym;
                sym = Lex.getsym();
                int t2; 
                if(sym==14 || sym==15)   //
                    t2 = P(); // !!!!??
                else
                    t2 = K();
                V[j].name = "tmp" + Tra.num_str(1000-j);
                V[j].type = V[t1].type;
                V[j].value = V[t1].value;
                int t3 = j--; // �м����
                switch(V[t2].type)
                {
                    case 3:
                    {
                        cout << "������� �������Ͳ�ƥ��" << endl;
                        exit(0);
                    }
                    case 4:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "������� �������Ͳ�ƥ��" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: V[t3].value=Tra.str_int(V[t3].value)<Tra.str_int(V[t2].value)?"true":"false";break;
                            case 38: V[t3].value=Tra.str_int(V[t3].value)!=Tra.str_int(V[t2].value)?"true":"false";break;
                            case 39: V[t3].value=Tra.str_int(V[t3].value)<=Tra.str_int(V[t2].value)?"true":"false";break;
                            case 40: V[t3].value=Tra.str_int(V[t3].value)>Tra.str_int(V[t2].value)?"true":"false";break;
                            case 41: V[t3].value=Tra.str_int(V[t3].value)>=Tra.str_int(V[t2].value)?"true":"false";break;
                            case 42: V[t3].value=Tra.str_int(V[t3].value)==Tra.str_int(V[t2].value)?"true":"false";break;
                        }
                        V[t3].type = 7; // bool��
                        break;
                    }
                    case 5:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "������� �������Ͳ�ƥ��" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: V[t3].value=Tra.str_double(V[t3].value)<Tra.str_double(V[t2].value)?"true":"false";break;
                            case 38: V[t3].value=Tra.str_double(V[t3].value)!=Tra.str_double(V[t2].value)?"true":"false";break;
                            case 39: V[t3].value=Tra.str_double(V[t3].value)<=Tra.str_double(V[t2].value)?"true":"false";break;
                            case 40: V[t3].value=Tra.str_double(V[t3].value)>Tra.str_double(V[t2].value)?"true":"false";break;
                            case 41: V[t3].value=Tra.str_double(V[t3].value)<=Tra.str_double(V[t2].value)?"true":"false";break;
                            case 42: V[t3].value=Tra.str_double(V[t3].value)==Tra.str_double(V[t2].value)?"true":"false";break;
                        }
                        V[t3].type = 7;
                        break;
                    }
                    case 6:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "������� �������Ͳ�ƥ��" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: V[t3].value=Tra.str_char(V[t3].value)<Tra.str_char(V[t2].value)?"true":"false";break;
                            case 38: V[t3].value=Tra.str_char(V[t3].value)!=Tra.str_char(V[t2].value)?"true":"false";break;
                            case 39: V[t3].value=Tra.str_char(V[t3].value)<=Tra.str_char(V[t2].value)?"true":"false";break;
                            case 40: V[t3].value=Tra.str_char(V[t3].value)>Tra.str_char(V[t2].value)?"true":"false";break;
                            case 41: V[t3].value=Tra.str_char(V[t3].value)<=Tra.str_char(V[t2].value)?"true":"false";break;
                            case 42: V[t3].value=Tra.str_char(V[t3].value)==Tra.str_char(V[t2].value)?"true":"false";break;
                        }
                        V[t3].type = 7;
                        break;
                    }
                }
                return t3;
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                cout << "�﷨���� δ�ҵ�Follow��" << endl;
                exit(0);
            }
            else
                return t1;
        }
        else
        {
            cout << "�﷨���� δ�ҵ�<��������>" << endl;
            exit(0);
        }
    }

    int K() // -> <�������ʽ>
    {
        int t1 = T(); 
        int t = t1; // ����һ���м����,�����������
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
            int t2 = T(); // �ڶ���������
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t].type;
            V[j].value = V[t].value;
            t = j--; // �����м����
            if(V[t].type != V[t2].type) // �жϲ�������ĺ����ɵ���ֵ�Ƿ�Ϊͬһ����
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
            if(V[t].type == 4) // int
            {
                switch(op)
                {
                    case 31: V[t].value=Tra.num_str(Tra.str_int(V[t].value)+Tra.str_int(V[t2].value));break;
                    case 32: V[t].value=Tra.num_str(Tra.str_int(V[t].value)-Tra.str_int(V[t2].value));break;
                }
            }
            else if(V[t].type == 5) // double
            {
                switch(op)
                {
                    case 31: V[t].value=Tra.num_str(Tra.str_double(V[t].value)+Tra.str_double(V[t2].value));break;
                    case 32: V[t].value=Tra.num_str(Tra.str_double(V[t].value)-Tra.str_double(V[t2].value));break;
                }
            }
            else
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
        }
        return t;
    }

    int T() // -> <��>
    {
        int t1 = U(); 
        int t = t1; // ����һ���м����,�����������
        while(sym==33 || sym==34 || sym==55)
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
                cout << "'%' OK " << endl;
                sym = Lex.getsym();
            }
            int t2 = U(); // �ڶ���������
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].type = V[t].type;
            V[j].value = V[t].value;
            t = j--; // �����м����
            if(V[t].type != V[t2].type) // �жϲ�������ĺ����ɵ���ֵ�Ƿ�Ϊͬһ����
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
            if(V[t].type==4) // int
            {
                switch(op)
                {
                    case 33: V[t].value=Tra.num_str(Tra.str_int(V[t].value)*Tra.str_int(V[t2].value));break;
                    case 34: V[t].value=Tra.num_str(Tra.str_int(V[t].value)/Tra.str_int(V[t2].value));break;
                    case 55: V[t].value=Tra.num_str(Tra.str_int(V[t].value)%Tra.str_int(V[t2].value));break;
                }
            }
            else if(V[t].type==5) // double
            {
                switch(op)
                {
                    case 33: V[t].value=Tra.num_str(Tra.str_double(V[t].value)*Tra.str_double(V[t2].value));break;
                    case 34: V[t].value=Tra.num_str(Tra.str_double(V[t].value)/Tra.str_double(V[t2].value));break;
                    
                }
            }
            else
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
        }
        return t;
    }

    int U() // -> <����>
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
                cout << "�﷨���� δ�ҵ�')'" << endl;
        }
        else if(sym>=21 && sym<=23)
            t = P();
        else
            cout << "�﷨���� δ�ҵ�<����>" << endl;
        return t;
    }

    int P() // -> <ID|NUM> ->  ID | NUM | true | false
    {
        int num;
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK " << endl;
            if(sym == 21) // ����ı�����
                num = Lex.get_num(); // �õ���������������
            else // ���͡������� ����
            {
                V[j].name = "tmp" + Tra.num_str(1000-j);
                V[j].value = code_str[x-1];
                V[j].type = sym - 18; // 22-18=4 -> int  23-18=5 -> double
                num = j--;
            }
            sym = Lex.getsym();
            return num;
        }
        else if(sym==14 || sym==15) // true or false
        {
            cout << "'true' or 'false' OK " << endl;
            V[j].name = "tmp" + Tra.num_str(1000-j);
            V[j].value = code_str[x-1];
            V[j].type = 7; // bool����
            num = j--;
            sym = Lex.getsym();
            return num;
        } 
        else
        {
            cout << "�﷨���� δ�ҵ�<ID|NUM>" << endl;
            return -1;
        }
    }

    void S1() // <��������>
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
            default: cout << "�﷨���� δ�ҵ�<type>" << endl;
                    break;
        }
    }

    void B1() // <����>
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
                cout << "�﷨���� δ�ҵ�'}'" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'{'" << endl;
    }

    void F1() // <��䴮>
    {
        G1();
        while(sym==21||(sym>=3&&sym<=7)||sym==8||sym==10||sym==11||sym==2)
            G1();
    }

    void G1() // <���>
    {
        if(sym>=3 && sym<=7) // �������
            O1();
        else if(sym == 21) // ��ֵ���
            H1();
        else if(sym == 8) // �������
            I1();
        else if(sym==10 || sym==11) // ѭ�����
            J1();
        else if(sym == 2) // �������
            Q1();
        else
            cout << "�﷨���� δ�ҵ�<���>" << endl;
    }

    void O1() // -> <�������>
    {
        if(sym == 7) // bool������
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<token>' OK " << endl;
                if(Lex.get_num() != -1) // �Զ�����������Ѿ����ڸñ���
                {
                    cout << "������� �����ظ�����" << endl;
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
                        cout << "�﷨���� δ�ҵ�';'" << endl;
                }       
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }   
                else
                    cout << "�﷨���� δ�ҵ�'='��';'" << endl;
            }
            else
            {
                cout << "�﷨���� δ�ҵ�<������>" << endl; 
                exit(0);
            }
        }
        else // �������Ͷ���
        {
            S1();
            if(sym == 21)
            {
                cout << "<������> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "������� �����ظ�����" << endl;
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
                        cout << "�﷨���� δ�ҵ�';'" << endl;
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�'='��';'" << endl;
            }
            else
            {
                cout << "�﷨���� δ�ҵ�<������>" << endl; 
                exit(0);
            }
        }
    }

    void P1()// <ID|NUM>
    {
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK" << endl;
            if(sym == 21)
                int num=Lex.get_num();//��ñ����ĺ�,û�ҵ�����-1
            sym=Lex.getsym();
        }
        else if(sym==14 || sym==15)
        {
            cout << "true or false OK" << endl;
            sym=Lex.getsym();
        }
        else
            cout << "�﷨���� δ�ҵ�<ID|NUM>" << endl;
    }

    void Q1() // <�������>
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
                cout << "�﷨���� δ�ҵ�';'" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'return'" << endl;
    }

    void R1() // -> <��ֵ���ʽ>
    {
        if(sym == 21)
        {
            cout << "<������> OK " << endl;
            int num = Lex.get_num(); // ���ض���ı����������д洢���±�
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                if(V[num].type == 7) // bool
                    L1();
                else    
                    K1();
            }
            else
                cout << "�﷨���� δ�ҵ�'='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }

    void H1() // -> <��ֵ���>
    {
        if(sym == 21)
        {
            cout << "<token> OK " << endl;
            int num = Lex.get_num(); // ���ض���ı����������д洢���±�
            sym = Lex.getsym();
            if(sym == 36)
            {
                cout << "'=' OK " << endl;
                sym = Lex.getsym();
                if(V[num].type == 7) // bool
                    L1();
                else    
                    K1();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
            }
            else if(sym==58)
            {
            	cout << "'+=' OK " << endl;
                sym = Lex.getsym();
                if(V[num].type == 7) // bool
                    L1();
                else    
                    K1();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
			}
			else if(sym==60)
			{
				cout << "'-=' OK " << endl;
                sym = Lex.getsym();
                if(V[num].type == 7) // bool
                    L1();
                else    
                    K1();
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
			}
            else
                cout << "�﷨���� δ�ҵ�'=''+=''-='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }

    void I1() // -> <�������>
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' succed " << endl;
                sym = Lex.getsym();
                L1(); // �������Ľ������
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�')'" << endl;
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                    G1();
                else if(sym == 46)
                    B1();
                if(sym == 9) // else
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                        G1();
                    else if(sym == 46)
                        B1();
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                    cout << "�﷨���� δ�ҵ�Follow��" << endl;
            }
            else    
                cout << "�﷨���� δ�ҵ�'('" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'if'" << endl; 
    }

    void J1() // -> <ѭ�����>
    {
        if(sym == 10) // while
        {
            cout << "'while' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�'('" << endl;
            L1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
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
                cout << "�﷨���� δ�ҵ�'('" << endl;
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
                cout << "�﷨���� δ�ҵ�';'" << endl;
            R1();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
            B1();
        }
        else
            cout << "�﷨���� δ�ҵ�'for'" << endl;
    }

    void L1() // <�������ʽ> 
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
                cout << "�﷨���� δ�ҵ�Follow��" << endl;
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
                cout << "�﷨���� δ�ҵ�')'" << endl;
            L1_();
        }
        else
        {
            cout << "�﷨���� δ�ҵ�<�������ʽ>" << endl;
            exit(0);
        }
    }

    void L1_()
    {
        if(sym==56 || sym==57)
        {
            sym == Lex.getsym();
            L1();
            L1_();
        }
        else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
        {
            cout << "�﷨���� δ�ҵ�Follow��" << endl;
            exit(0);
        }
    }

    void K1() // <�������ʽ>
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
                cout << "�﷨���� δ�ҵ�')'" << endl;
        }
        else if(sym>=21 && sym<=23)
            P1();
        else 
            cout << "�﷨���� δ�ҵ�<�������ʽ>" << endl;
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
            cout << "�﷨���� δ�ҵ�Follow��" << endl;
            exit(0);
        }
    }
};
int interpreter::i = 0;   // ֮��洢�����ı���
int interpreter::j = 999; // ֮ǰ�洢�м����

int main()
{
    transform TRA; // ����ת����
    lexical LEX; // �ʷ���
    interpreter INT; // ���ͳ�����
    output OUT; // ��������
    
    FILE* fp;
    if((fp=fopen(file_in, "r")) == NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    LEX.save(fp);  
    fclose(fp);

    INT.sym = LEX.getsym(); // ��ȡһ�����ʣ��õ����ֱ���
    cout << "�﷨������" << endl;
    INT.A();

    fp = fopen(file_out, "w");
    OUT.define(fp); // ����������
    OUT.middle(fp); // ����м����
    OUT.answer(fp); // ������н��
    fclose(fp);

    return 0;
}
