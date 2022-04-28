#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

/*输入输出文件*/
char file_in[] = "./eryuanzu.txt";
char file_out[] = "./siyuanshi.txt";
/*存储种别码及其相应单词*/
int code_num[1000] = {0};
string code_str[1000]; // 存储种别码对应的字符串
int x = 0; // x是单词数组中的计数器
string Quadruples[500][4]; // 存储四元式

/*数值类型转换函数*/
string num_str(int num) // 整型 -> 字符串
{
    stringstream ss;
    ss << num;
    return ss.str();
}

/*----文法函数声明----*/   
void A(); // <主函数> -> int main() <语句块> 
void C(); // <函数> -> <所有类型> <函数名>() <语句块>  
void D(); // <所有类型> -> void|int|double|char|bool
void S(); // <其他类型> -> void|int|double|char
void E(); // <函数名> -> ID
void B(); // <语句块> -> {(<语句块>|<语句串>)*}
void F(); // <语句串> -> <语句>(<语句>)*
void G(); // <语句> -> <声明语句>|<赋值语句>|<条件语句>|<循环语句>|<返回语句>
void O(); // <声明语句> -> (<其它类型> ID ((=<算术表达式>;)|;))
          //             | (<Bool> ID ((=<布尔表达式>;)|;))
void R(); // <赋值表达式> -> ID = (<算术表达式>|<布尔表达式>) 
void H(); // <赋值语句> -> <赋值表达式>; 
void I(); // <条件语句> -> if(<布尔表达式>) (<语句块>|<语句>) (else(<语句块>|<语句>) | 空)
void J(); // <循环语句> -> while(布尔表达式) <语句块>
          //             | for((<赋值语句>|<声明语句>) <布尔表达式>; <赋值表达式>) <语句块>
void Q(); // <返回语句> -> return (<算术表达式>|<布尔表达式>);
int  L(); // <布尔表达式> -> <布尔项>(||<布尔项>)*
int  W(); // <布尔项> -> <布尔因子>(&&<布尔因子>)*
int  X(); // <布尔因子> -> (<布尔表达式>)
          //             | <算术表达式> relop <算术表达式>
          //             | <ID|NUM>
int  K(); // <算术表达式> -> <项>(+<项>)* | <项>(-<项>)*
int  T(); // <项> -> <因子>(*<因子>)* | <因子>(/<因子>)*| <因子>(%<因子>)*
int  U(); // <因子> -> (<算术表达式>) | <ID|NUM> 
int  P(); // <ID|NUM> -> ID|NUM|true|false

struct val  // 变量结构体   符号表结构
{
    string name; // 变量名
    int type;  // 值类型的种别码 
    string value; // code_str数组中存储的字符串(来自词法分析)
} V[1500];

class quaternary // 四元式类
{
    static int row; // 四元式的行数
public:
    void emit(string s1, string s2, string s3, string s4) // 四元式生成函数
    {
        Quadruples[row][0] = s1;
        Quadruples[row][1] = s2;
        Quadruples[row][2] = s3; 
        Quadruples[row][3] = s4;
        row++;
    }
    void disp(FILE *fp) // 输出最终四元式
    {
        for(int i=0; i<row; i++)
        {
            fprintf(fp,"(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
            printf("(%s,%s,%s,%s)\n",Quadruples[i][0].c_str(),Quadruples[i][1].c_str(),Quadruples[i][2].c_str(),Quadruples[i][3].c_str());
        }
    }
};
int quaternary::row = 0;

class lexical // 词法类
{
    int n; // 文件中读取到的种别码
    char str[100]; // 文件中读取到的单词
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
            fscanf(fp, "%d %s", &n, str); //读取二元式
            code_num[k] = n; //存储种别码
            code_str[k] = str; //存储单词
            k++;
        }
    }
    int getsym()
    {
        return code_num[x++]; //读取下一个单词
    }
    int get_num() // 查表，与表中已有字符串匹配，若存在返回变量的序号，不存在返回-1,并将新标识符插入表中
    {
        for(int i=0; (V[i].name).size(); i++) // 声明变量单词表非空时，循环
            if(V[i].name == code_str[x-1])
                return i;
        return -1;
    }
};

class syntactic // 语法类
{
    static int i, j, reg;
    static int count_label; // 条件语句、循环语句 
    lexical Lex;
    quaternary Qua;
public:
    int sym; // sym是该单词的种别码 
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
                        cout << "语法错误 未找到')'" << endl;
                }
                else
                    cout << "语法错误 未找到'('" << endl;
            }
            else
                cout << "语法错误 未找到'main'" << endl;
        }
        else
            cout << "语法错误 未找到'int'" << endl;
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
                cout << "语法错误 未找到')'" << endl;
        }
        else
            cout << "语法错误 未找到'('" << endl;
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
            default: cout << "语法错误 未找到<type>" << endl;
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
            default: cout << "语法错误 未找到<type>" << endl;
                    break;
        }
    }
    void E() // -> 21    
    {
        if(sym == 21) 
        {
            cout << "<变量名> OK " << endl;
            sym = Lex.getsym();
        }
        else
            cout << "语法错误 未找到<变量名>" << endl;
    }
    void B() // -> 46 (B|F)* 47
    {
        if(sym == 46)
        {
            cout << "'{' OK " << endl;
            sym = Lex.getsym();
            while(sym==46||(sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11))
            {
                if(sym == 46) // 语句块
                    B();
                else
                    F(); // 语句串
            }
            if(sym == 47)
            {
                cout << "'}' OK " << endl;
                sym = Lex.getsym();
            }
            else
                cout << "语法错误 未找到'}'" << endl;
        }
        else
            cout << "语法错误 未找到'{'" << endl;
    }
    void F() // -> G G*
    {
        G();
        while((sym>=3&&sym<=7)||sym==21||sym==8||(sym==10||sym==11)||sym==2)
            G();
    }    
    void G() // -> O|H|I|J|Q
    {
        if(sym>=3 && sym<=7) // 声明语句
            O();
        else if(sym == 21) // 赋值语句
            H();
        else if(sym == 8) // 条件语句
            I();
        else if(sym==10 || sym==11) // 循环语句
            J();
        else if(sym == 2) // 返回语句
            Q();
        else
            cout << "语法错误 未找到<语句>" << endl;
    }
    void O() // -> (S 21 ((36 K 44) | 44)) | (7 21 ((36 L 44) | 44))
    {
        V[i].type = sym;
        if(sym == 7) // bool型声明
        {
            cout << "'bool' OK " << endl;
            sym = Lex.getsym();
            if(sym == 21)
            {
                cout << "'<变量名>' OK " << endl;
                if(Lex.get_num() != -1) // 自定义变量表中已经存在该变量
                {
                    cout << "语义错误 变量重复定义" << endl;
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
                        cout << "语义错误 变量类型不匹配" << endl;
                        exit(0);
                    }
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else    
                        cout << "语法错误 未找到';'" << endl;
                }       
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }   
                else
                    cout << "语法错误 未找到'='或';'" << endl;
            }
            else
            {
                cout << "语法错误 未找到<变量名>" << endl; 
                exit(0);
            }
        }
        else // 其它类型定义
        {
            S();
            if(sym == 21)
            {
                cout << "<变量名> OK " << endl;
                if(Lex.get_num() != -1)
                {
                    cout << "语义错误 变量重复定义" << endl;
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
                        cout << "语义错误 变量类型不匹配" << endl;
                        exit(0);
                    }
                    Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[i++].name);
                    if(sym == 44)
                    {
                        cout << "';' OK " << endl;
                        sym = Lex.getsym();
                    }
                    else    
                        cout << "语法错误 未找到';'" << endl;
                }
                else if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    i++;
                    sym = Lex.getsym();
                }
                else
                    cout << "语法错误 未找到'='或';'" << endl;
            }
            else
            {
                cout << "语法错误 未找到<变量名>" << endl; 
                exit(0);
            }
        }
    }
    void R() // -> 21 36 (K|L)
    {
        if(sym == 21)
        {
            cout << "<变量名> OK " << endl;
            int num = Lex.get_num(); // 返回定义的变量在数组中存储的下标
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
                    cout << "语义错误 变量类型不匹配" << endl;
                    exit(0);
                }
                Qua.emit("=","_",(V[t].value.size())?V[t].value:V[t].name,V[num].name);
            }
            else
                cout << "语法错误 未找到'='" << endl;
        }
        else
            cout << "语法错误 未找到<变量名>" << endl;
    }
    void H() // -> R 44
    {
        if(sym == 21)
        {
            cout << "<token> OK " << endl;
            int num = Lex.get_num(); // 返回定义的变量在数组中存储的下标
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
                    cout << "语义错误 变量类型不匹配" << endl;
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
				 	cout << "语法错误 未找到';'" << endl;
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
                    cout << "语义错误 变量类型不匹配" << endl;
                    exit(0);
                }
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "语法错误 未找到';'" << endl;
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
                    cout << "语义错误 变量类型不匹配" << endl;
                    exit(0);
                }
                if(sym == 44)
                {
                    cout << "';' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "语法错误 未找到';'" << endl;
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
                    cout << "语法错误 未找到';'" << endl;
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
                    cout << "语法错误 未找到';'" << endl;
                Qua.emit("--","_","_",V[num].name);
			 }
             else
			    cout << "语法错误 未找到'=''+=''-='" << endl;
        }
        else
            cout << "语法错误 未找到<变量名>" << endl;
    }
    void I() // -> 8 48 L 49 (G|B) (( 9 (G|B) ) | 空 )
    {
        if(sym == 8)
        {
            cout << "'if' OK " << endl;
            sym = Lex.getsym();
            if(sym == 48)
            {
                cout << "'(' succed " << endl;
                sym = Lex.getsym();
                int t1 = L(); // 条件语句的结果变量
                if(sym == 49)
                {
                    cout << "')' OK " << endl;
                    sym = Lex.getsym();
                }
                else
                    cout << "语法错误 未找到')'" << endl;
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
                    printf("语法错误 未找到Follow集\n");
                }
            }
            else    
                cout << "语法错误 未找到'('" << endl;
        }
        else
            cout << "语法错误 未找到'if'" << endl; 
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
                cout << "语法错误 未找到'('" << endl;
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
                cout << "语法错误 未找到')'" << endl;
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
                cout << "语法错误 未找到'('" << endl;
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
                cout << "语法错误 未找到';'" << endl;
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
                cout << "语法错误 未找到')'" << endl;
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
                cout << "语法错误 未找到';'" << endl;
            Qua.emit("return",(V[t].value.size())?V[t].value:V[t].name,"_","_");
        }
        else
            cout << "ERROR!  'return' missing" << endl;
    }
    int L() // -> W (57 W)*
    {
        int t1 = W();
        int t = t1; // 生成一个中间变量
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
        int t = t1; // 生成一个中间变量
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
                int t3 = j--; // 中间变量
                switch(V[t2].type)
                {
                    case 3:
                    {
                        cout << "语义错误 变量类型不匹配" << endl;
                        exit(0);
                    }
                    case 4:
                    case 5:
                    case 6:
                    {
                        if(V[t3].type != V[t2].type)
                        {
                            cout << "语义错误 变量类型不匹配" << endl;
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
                        V[t3].type = 7; // bool型
                        break;
                    }
                }
                return t3;
            }
            else if(sym!=38&&sym!=42&&sym!=44&&sym!=49&&sym!=56&&sym!=57)
            {
                printf("语法错误 未找到Follow集\n");
                exit(0);
            }
            else
                return t1;
        }
        else
        {
            cout << "语法错误 未找到<布尔因子>" << endl;
            exit(0);
        }
    }
    int K() // -> T ((32|32) T)*
    {
        int t1 = T(); 
        int t = t1; // 生成一个中间变量,在数组中序号
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
            int t2 = T(); // 第二个运算数
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t; // 第一个运算数
            t = j--; // 更新中间变量
            if(V[t].type != V[t2].type) // 判断参与运算的和生成的数值是否为同一类型
            {
                cout << "语义错误 变量类型不匹配" << endl;
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
        int t = t1; // 生成一个中间变量,在数组中序号
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
            int t2 = U(); // 第二个运算数
            V[j].name = "tmp" + num_str(1000-j);
            V[j].type = V[t].type;
            int t3 = t; // 第一个运算数
            t = j--; // 更新中间变量
            if(V[t].type != V[t2].type) // 判断参与运算的和生成的数值是否为同一类型
            {
                cout << "语义错误 变量类型不匹配" << endl;
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
                cout << "语法错误 未找到')'" << endl;
        }
        else if(sym>=21 || sym<=23)
            t = P();
        else
            cout << "语法错误 未找到<因子>" << endl;
        return t;
    }
    int P() // -> 21|22|23|14|15
    {
        int num;
        if(sym>=21 && sym<=23)
        {
            cout << "<ID or NUM> OK " << endl;
            if(sym == 21) // 定义的变量名
                num = Lex.get_num(); // 得到所定义变量的序号
            else // 整型、浮点型 常数
            {
                V[1000+reg].value = code_str[x-1];
                V[1000+reg].type = sym - 18; // 22-18=4 -> int  23-18=5 -> double
                num = 1000 + reg++; // 返回的是存储大数组该元素的下标
            }
            sym = Lex.getsym();
            return num;
        }
        else if(sym==14 || sym==15) // true or false
        {
            cout << "'true' or 'false' OK " << endl;
            V[1000+reg].value = code_str[x-1];
            V[1000+reg].type = 7; // bool类型
            num = 1000 + reg++;
            sym = Lex.getsym();
            return num;
        } 
        else
        {
            cout << "语法错误 未找到<ID|NUM>" << endl;
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
    lexical LEX; // 词法类
    syntactic SYN; // 语法类
    quaternary QUA; // 四元式类
    FILE* fp;
    if((fp=fopen(file_in, "r")) == NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    LEX.save(fp);  
    fclose(fp);

    SYN.sym = LEX.getsym(); //读取一个单词，得到其种别码
    cout << "语法分析：" << endl;
    SYN.A();

    fp = fopen(file_out, "w");
    cout << endl << "输出四元式：" << endl;
    QUA.disp(fp);
    fclose(fp);

    return 0;
}
