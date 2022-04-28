#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;  

/*输入输出文件*/
char file_in[] = "./text.txt"; 
char file_out[] = "./eryuanzu.txt";
/*读取字符、种别码、字符串存储数组*/
char ch; 
char token[10]; 
int syn = 52; 
/*全局变量*/
int n = 0;
int m = 0;
int sum_int = 0;
float sum_float = 0.0;
int row = 1; //文件第几行
/*保留字*/
const int reserve_num = 17; //保留字个数
char reserve[reserve_num][10] = 
{
    "main", "return",
    "void", "int", "double", "char", "bool",
    "if", "else", "while", "for", "break", "continue",
    "true", "false",
    "read", "write"
};

void scan(FILE *fp)
{
    /*1.标识符 or 保留字 2.数字 3.负数 4.符号*/
    for(n=0; n<10; n++)
        token[n] = '\0'; //每次读取字符前清空数组
    ch = fgetc(fp); //从文件中读取字符
    while(ch==' '||ch=='\t')
        ch = fgetc(fp); //跳过空白字符
 
    /*1.标识符 or 保留字*/
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        m = 0;
        do
        {
            token[m++] = ch;
            ch = fgetc(fp);
        }while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||(ch=='_'));
        fseek(fp, -1, SEEK_CUR); //单词读取结束，退回到最后读取到的字符前位置
        token[m] = '\0'; //单词读取结束
        syn = 21; //标识符 种别码
        for(n=0; n<reserve_num; n++)
            if(strcmp(token, reserve[n])==0) //判断是否为保留字
            {
                syn = n+1; //保留字 种别码
                break;
            }
    }
    /*2.数字*/
    else if(ch>='0' && ch<='9')
    {
        sum_int = 0;
        sum_float = 0.0;
        while(ch>='0' && ch<='9')
        {
            sum_int = sum_int * 10 + ch - '0';
            ch = fgetc(fp);
        }
        if(sum_int > 2147483647) //超过整形数最大表示范围
            syn = -1; //出错
        else 
        {
            if(ch == '.') //识别到小数点
            {
                int cnt = 0; //小数点位数计数
                sum_float = float(sum_int);
                ch = fgetc(fp);
                while(ch>='0' && ch<='9')
                {
                    sum_float += (ch-'0') / pow(10, ++cnt);
                    ch = fgetc(fp);
                }
                syn = 23; //浮点型常数
            }
            else
                syn = 22; //整型常数   
        }
        fseek(fp, -1, SEEK_CUR);
    }
    /*3.负数*/
    else if(ch == '-')
    {
        fseek(fp, -2, SEEK_CUR); 
        ch = fgetc(fp); //检查'-'前字符
        if((ch>='0' && ch<='9')||(ch>='A' && ch<='z')) //'-'前有数字，表示减号，是符号类型
        { 
            ch = fgetc(fp);
            token[0] = ch;//将'-'存入数组中  
            ch = fgetc(fp);
            if(ch=='=')
            {
                token[1]=ch;
                syn=60;  //-=的种别码 
			}
			else if(ch=='-')
		    {
				token[1]=ch;
				syn=61;  //--的种别码 
			}
			else
			{
				syn=32;//'-'的种别码
				fseek(fp, -1, SEEK_CUR);
			}	
        }
        else
        {
            fseek(fp, 1, SEEK_CUR); //跳过'-'字符
            ch = fgetc(fp); //'-'后字符
            if(ch>='0' && ch<='9')
            {
                sum_int = 0;
                sum_float = 0.0;
                while(ch>='0' && ch<='9')
                {
                    sum_int = sum_int * 10 + ch - '0';
                    ch = fgetc(fp);
                }
                if(sum_int > 2147483647) //超过整形数最大表示范围
                    syn = -1; //出错
                else 
                {
                    if(ch == '.') //识别到小数点
                    {
                        int cnt = 0; //小数点位数计数
                        sum_float = float(sum_int);
                        ch = fgetc(fp);
                        while(ch>='0' && ch<='9')
                        {
                            sum_float += (ch-'0') / pow(10, ++cnt);
                            ch = fgetc(fp);
                        }
                        sum_float = -sum_float; //负数去反
                        syn = 23; //浮点型常数
                    }
                    else
                    {
                        sum_int = -sum_int; //负数去反
                        syn = 22; //整型常数
                    }  
                }
                fseek(fp, -1, SEEK_CUR);
            }
        }
    }
    /*4.符号*/
    else switch(ch)
    {
        case'/': token[0] = ch;
                 ch = fgetc(fp);
                 if(ch == '/') //"//"注释符
                 {
                     while(fgetc(fp) != '\n');
                     syn = -3; // 注释 的种别码
                 }
                 else if(ch == '*') // "/**/"注释符
                 {
                     while(1)
                     {
                         while(fgetc(fp) != '*');
                         if(fgetc(fp) == '/')
                            break;
                     }   
                     syn = -3; // 注释 的种别码               
                 }
                 else
                 {
                     syn = 34; // '/' 的种别码
                     fseek(fp, -1, SEEK_CUR);
                 }
                 break;
        case'<': token[0] = ch;
                 ch = fgetc(fp);
                 if(ch == '=')
                 {
                     token[1] = ch;
                     syn = 39; // <= 的种别码
                 }
                 else
                 {
                     syn = 37; // < 的种别码
                     fseek(fp, -1, SEEK_CUR);
                 }
                 break;
        case'>': token[0] = ch;
                 ch = fgetc(fp);
                 if(ch == '=')
                 {
                     token[1] = ch;
                     syn = 41; // >= 的种别码
                 }
                 else
                 {
                     syn = 40; // > 的种别码
                     fseek(fp, -1, SEEK_CUR);
                 }
                 break;
        case'=': token[0] = ch;
                 ch = fgetc(fp);
                 if(ch == '=')
                 {
                     token[1] = ch;
                     syn = 42; // == 的种别码
                 }
                 else
                 {
                     syn = 36; // = 的种别码
                     fseek(fp, -1, SEEK_CUR);
                 }
                 break;
        case'!': token[0] = ch;
                 ch = fgetc(fp);
                 if(ch == '=')
                 {
                     token[1] = ch;
                     syn = 38; // != 的种别码
                 }
                 else
                 {
                     syn = 43; // ! 的种别码
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
                 	syn=58;  //+=的种别码 
				 }
				 else if(ch=='+')
				 {
				 	token[1]=ch;
				 	syn=59;  //++的种别码 
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
        case'\n': syn=-2; //文件读取到换行符
                  break;
        case EOF: syn=0; //文件读取结束
                  break; 
        default:  syn=-1; //异常字符
                  break; 
    }
}

int main()
{
    FILE *fp1 = fopen(file_in, "r");  //打开源代码文件
    FILE *fp2 = fopen(file_out, "w"); //词法分析器输出文件
    if(fp1 == NULL)
    {
        cout << "open the file_in failed!" << endl;
        exit(0);
    }
    if(fp2 == NULL)
    {
        cout << "open the file_out failed!" << endl;
        exit(0);
    }

    cout << "source program" << endl;
    while((ch = fgetc(fp1)) != EOF) //显示源程序内容
        cout << ch;

    cout << endl << endl;
    cout << "词法分析器输出" << endl;
    fseek(fp1, 0L, SEEK_SET); //光标移至源代码文件开头
    
    scan(fp1);
    while(syn != 0)
    {
        switch(syn)
        {
            case 22: cout << syn << " " << sum_int <<endl; //整型
                     fprintf(fp2, "%d %d\n", syn, sum_int);
                     break;
            case 23: cout <<syn << " " << sum_float <<endl; //浮点型
                     fprintf(fp2, "%d %f\n", syn, sum_float);
                     break;
            case -1: cout << "Error in row " << row << "!" << endl; //报错
                     fprintf(fp2, "Error in row %d!\n", row);
                     break;
            case -2: row++; //增加行数
                     break;
            case -3: break; //注释部分
            case 0:  break; //文件读取结束
            default: cout << syn << " " << token << endl; //标识符 or 保留字
                     fprintf(fp2, "%d %s\n", syn, token);
                     break;
        }
        scan(fp1);
    }
   
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
