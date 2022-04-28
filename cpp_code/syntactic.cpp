#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

/*��������ļ�*/
char file_in[] = "./eryuanzu.txt";
char file_out[] = "./siyuanshi.txt";
/*�洢�ֱ��뼰����Ӧ����*/
int code_num[1000] = {0};
string code_str[1000]; // �洢�ֱ����Ӧ���ַ���
int x = 0; // x�ǵ��������еļ�����
string Quadruples[500][4]; // �洢��Ԫʽ

/*��ֵ����ת������*/
string num_str(int num) // ���� -> �ַ���
{
    stringstream ss;
    ss << num;
    return ss.str();
}

/*----�ķ���������----*/   
void A(); // <������> -> int main() <����> 
void C(); // <����> -> <��������> <������>() <����>  
void D(); // <��������> -> void|int|double|char|bool
void S(); // <��������> -> void|int|double|char
void E(); // <������> -> ID
void B(); // <����> -> {(<����>|<��䴮>)*}
void F(); // <��䴮> -> <���>(<���>)*
void G(); // <���> -> <�������>|<��ֵ���>|<�������>|<ѭ�����>|<�������>
void O(); // <�������> -> (<��������> ID ((=<�������ʽ>;)|;))
          //             | (<Bool> ID ((=<�������ʽ>;)|;))
void R(); // <��ֵ���ʽ> -> ID = (<�������ʽ>|<�������ʽ>) 
void H(); // <��ֵ���> -> <��ֵ���ʽ>; 
void I(); // <�������> -> if(<�������ʽ>) (<����>|<���>) (else(<����>|<���>) | ��)
void J(); // <ѭ�����> -> while(�������ʽ) <����>
          //             | for((<��ֵ���>|<�������>) <�������ʽ>; <��ֵ���ʽ>) <����>
void Q(); // <�������> -> return (<�������ʽ>|<�������ʽ>);
int  L(); // <�������ʽ> -> <������>(||<������>)*
int  W(); // <������> -> <��������>(&&<��������>)*
int  X(); // <��������> -> (<�������ʽ>)
          //             | <�������ʽ> relop <�������ʽ>
          //             | <ID|NUM>
int  K(); // <�������ʽ> -> <��>(+<��>)* | <��>(-<��>)*
int  T(); // <��> -> <����>(*<����>)* | <����>(/<����>)*| <����>(%<����>)*
int  U(); // <����> -> (<�������ʽ>) | <ID|NUM> 
int  P(); // <ID|NUM> -> ID|NUM|true|false

struct val  // �����ṹ��   ���ű�ṹ
{
    string name; // ������
    int type;  // ֵ���͵��ֱ��� 
    string value; // code_str�����д洢���ַ���(���Դʷ�����)
} V[1500];

class quaternary // ��Ԫʽ��
{
    static int row; // ��Ԫʽ������
public:
    void emit(string s1, string s2, string s3, string s4) // ��Ԫʽ���ɺ���
    {
        Quadruples[row][0] = s1;
        Quadruples[row][1] = s2;
        Quadruples[row][2] = s3; 
        Quadruples[row][3] = s4;
        row++;
    }
    void disp(FILE *fp) // ���������Ԫʽ
    {
        for(int i=0; i<row; i++)
        {
            fprintf(fp,"(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
            printf("(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
        }
    }
};
int quaternary::row = 0;

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

class syntactic // �﷨��
{
    static int i, j, reg;
    static int count_label; // ������䡢ѭ����� 
    lexical Lex;
    quaternary Qua;
public:
    int sym; // sym�Ǹõ��ʵ��ֱ��� 
    syntactic()
    {
        sym = 52;
    }
    void A() // -> 4 1 48 49 B
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
    void C() // -> D E 48 49 B
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
    void D() // -> 3|4|5|6|7
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
    void S() // -> 3|4|5|6
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
    void E() // -> 21    
    {
        if(sym == 21) 
        {
            cout << "<������> OK " << endl;
            sym = Lex.getsym();
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }
    void B() // -> 46 (B|F)* 47
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
    void F() // -> G G*
    {
        G();
        while((sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11)||sym==2)
            G();
    }    
    void G() // -> O|H|I|J|Q
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
    void O() // -> (S 21 ((36 K 44) | 44)) | (7 21 ((36 L 44) | 44))
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
                    if(V[i].type != V[t].type)
                    {
                        cout << "������� �������Ͳ�ƥ��" << endl;
                        exit(0);
                    }
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
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
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
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
    void R() // -> 21 36 (K|L)
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
                Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
            }
            else
                cout << "�﷨���� δ�ҵ�'='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }
    void H() // -> R 44
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
                if(sym==59)
                {
                	cout<<"'++' OK"<<endl;
                	sym=Lex.getsym();
                	if(sym == 44)
                	{
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                	}
					Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);   
					Qua.emit("++","_","_",V[num].name);            	                	
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
					Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);   
					Qua.emit("--","_","_",V[num].name);            	                	
				}               
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);   
                }
                else
                {
				 	cout << "�﷨���� δ�ҵ�';'" << endl;
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);   
				}   
                
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
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
                Qua.emit("+=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
			 } 
			 else if(sym ==60)
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
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "�﷨���� δ�ҵ�';'" << endl;
                Qua.emit("-=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
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
                Qua.emit("++","_","_",V[num].name);
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
                Qua.emit("--","_","_",V[num].name);
			 }
             else
			    cout << "�﷨���� δ�ҵ�'=''+=''-='" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�<������>" << endl;
    }
    void I() // -> 8 48 L 49 (G|B) (( 9 (G|B) ) | �� )
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
                string label1 = "label" + num_str(count_label++);
                string label2 = "label" + num_str(count_label++);
                Qua.emit("JZ",(V[t1].value.size())?V[t1].value:V[t1].name,"_",label1);
                if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                {
                    G();
                    Qua.emit("JP","_","_",label2);
                }
                else if(sym == 46)
                {
                    B();
                    Qua.emit("JP","_","_",label2);
                }
                Qua.emit(label1,"_","_","_");
                if(sym == 9) // else
                {
                    cout << "'else' OK " << endl;
                    sym = Lex.getsym();
                    if(sym==21||(sym>=3&&sym<=6)||sym==8||(sym==10||sym==11)||sym==2)
                        G();
                    else if(sym == 46)
                        B();
                    Qua.emit(label2,"_","_","_");
                }
                else if(sym==1||sym==22||sym==23||(sym>=31&&sym<=45)||(sym>=50&&sym<=57))
                {
                    printf("�﷨���� δ�ҵ�Follow��\n");
                }
            }
            else    
                cout << "�﷨���� δ�ҵ�'('" << endl;
        }
        else
            cout << "�﷨���� δ�ҵ�'if'" << endl; 
    }
    void J() // -> (10 48 L 49 B) | (11 48 (H|O) L 44 R 49 B)
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
            string label1 = "label" + num_str(count_label++); 
            string label2 = "label" + num_str(count_label++);   
            Qua.emit(label1,"_","_","_");
            int t = L();
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
            Qua.emit("JZ",(V[t].value.size())?V[t].value:V[t].name,"_",label2);
            B();
            Qua.emit("JP","_","_",label1);
            Qua.emit(label2,"_","_","_");
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
            string label1 = "label" + num_str(count_label++); 
            string label2 = "label" + num_str(count_label++); 
            string label3 = "label" + num_str(count_label++); 
            string label4 = "label" + num_str(count_label++); 
            Qua.emit(label1,"_","_","_");
            int t = L();
            if(sym == 44)
            {
                cout << "';' OK " << endl;
                sym = Lex.getsym();
            }
            else    
                cout << "�﷨���� δ�ҵ�';'" << endl;
            Qua.emit("JZ",(V[t].value.size())?V[t].value:V[t].name,"_",label4);
            Qua.emit("JP","_","_",label2);
            Qua.emit(label3,"_","_","_");
            R();
            Qua.emit("JP","_","_",label1);
            if(sym == 49)
            {
                cout << "')' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "�﷨���� δ�ҵ�')'" << endl;
            Qua.emit(label2,"_","_","_");
            B();
            Qua.emit("JP","_","_",label3);
            Qua.emit(label4,"_","_","_");
        }
        else
            cout << "'while' or 'for' fail" << endl;
    }
    void Q() // -> 2 (L|K) 44
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
            Qua.emit("return",(V[t].value.size())?V[t].value:V[t].name,"_","_");
        }
        else
            cout << "ERROR!  'return' missing" << endl;
    }
    int L() // -> W (57 W)*
    {
        int t1 = W();
        int t = t1; // ����һ���м����
        while(sym == 57)
        {
            cout << "'|' OK " << endl;
            sym = Lex.getsym();
            int t2 = W();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            Qua.emit("|",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);
        }
        return t;
    }
    int W() // -> X (56 X)*
    {
        int t1 = X();
        int t = t1; // ����һ���м����
        while(sym == 56)
        {
            cout << "'&' OK " << endl;
            sym = Lex.getsym();
            int t2 = X();
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t;
            t = j--;
            Qua.emit("&",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);
        }
        return t;
    }
    int X() // -> (48 L 49) | (K relop K) | K
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
                    t2 = P(); // !!!!??
                else
                    t2 = K();
                V[j].name = "tmp" + num_str(1000-j);
                V[j].type = V[t1].type;
                int t3 = j--; // �м����
                switch(V[t2].type)
                {
                    case 3:
                    {
                        cout << "������� �������Ͳ�ƥ��" << endl;
                        exit(0);
                    }
                    case 4:
                    case 5:
                    case 6:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "������� �������Ͳ�ƥ��" << endl;
                            exit(0);
                        }
                        switch(op)
                        {
                            case 37: Qua.emit("<",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 38: Qua.emit("!=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 39: Qua.emit("<=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 40: Qua.emit(">",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 41: Qua.emit(">=",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                            case 42: Qua.emit("==",(V[t1].value.size())?V[t1].value:V[t1].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t3].name);break;
                        }
                        V[t3].type = 7; // bool��
                        break;
                    }
                }
                return t3;
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                printf("�﷨���� δ�ҵ�Follow��\n");
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
    int K() // -> T ((32|32) T)*
    {
        int t1 = T(); 
        int t = t1; // ����һ���м����,�����������
        while(sym==31 || sym==32 )
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
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t; // ��һ��������
            t = j--; // �����м����
            if(V[t].type != V[t2].type) // �жϲ�������ĺ����ɵ���ֵ�Ƿ�Ϊͬһ����
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
            switch(op)
            {    
                case 31:Qua.emit("+",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 32:Qua.emit("-",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
            }
        }
        
        return t;
    }
    int T() // -> U ((33|34) U)*
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
            else if(sym==55)
            {
                cout << "'%' OK " << endl;
                sym = Lex.getsym();
            }
            int t2 = U(); // �ڶ���������
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t; // ��һ��������
            t = j--; // �����м����
            if(V[t].type != V[t2].type) // �жϲ�������ĺ����ɵ���ֵ�Ƿ�Ϊͬһ����
            {
                cout << "������� �������Ͳ�ƥ��" << endl;
                exit(0);
            }
            switch(op)
            {
                case 33:Qua.emit("*",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 34:Qua.emit("/",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
                case 55:Qua.emit("%",(V[t3].value.size())?V[t3].value:V[t3].name,(V[t2].value.size())?V[t2].value:V[t2].name,V[t].name);break;
            }
        }
        return t;
    }
    int U() // -> (48 K 49) | (21|22|23) 
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
        else if(sym>=21 || sym<=23)
            t = P();
        else
            cout << "�﷨���� δ�ҵ�<����>" << endl;
        return t;
    }
    int P() // -> 21|22|23|14|15
    {
        int num;
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK " << endl;
            if(sym == 21) // ����ı�����
                num = Lex.get_num(); // �õ���������������
            else // ���͡������� ����
            {
                V[1000+reg].value = code_str[x-1];
                V[1000+reg].type = sym - 18; // 22-18=4 -> int  23-18=5 -> double
                num = 1000 + reg++; // ���ص��Ǵ洢�������Ԫ�ص��±�
            }
            sym = Lex.getsym();
            return num;
        }
        else if(sym==14 || sym==15) // true or false
        {
            cout << "'true' or 'false' OK " << endl;
            V[1000+reg].value = code_str[x-1];
            V[1000+reg].type = 7; // bool����
            num = 1000 + reg++;
            sym = Lex.getsym();
            return num;
        } 
        else
        {
            cout << "�﷨���� δ�ҵ�<ID|NUM>" << endl;
            return -1;
        }
    }
};
int syntactic::count_label = 1;
int syntactic::i = 0;
int syntactic::j = 999;
int syntactic::reg = 0;

int main()
{
    lexical LEX; // �ʷ���
    syntactic SYN; // �﷨��
    quaternary QUA; // ��Ԫʽ��
    FILE* fp;
    if((fp=fopen(file_in, "r")) == NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    LEX.save(fp);  
    fclose(fp);

    SYN.sym = LEX.getsym(); //��ȡһ�����ʣ��õ����ֱ���
    cout << "�﷨������" << endl;
    SYN.A();

    fp = fopen(file_out, "w");
    cout << endl << "�����Ԫʽ��" << endl;
    QUA.disp(fp);
    fclose(fp);

    return 0;
}
