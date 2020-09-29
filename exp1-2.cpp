#include<iostream>
#include<string>
using namespace std;
int judgegl(string a, string b)                                     //判断两字符串代表的数的大小
{
    if(a.length() != b.length())
        return (a.length() > b.length());                           //优先比较两字符串长度
    else{
        for(int i = 0; i < a.length(); i++)
            if(a[i] != b[i])
                return (a[i] > b[i]);                               //大于返回1，小于返回0，等于返回-1
        return -1;
    }
}
string calculate(string src,string dest)
{   
    string srcs = dest;                                             //将src（较小的数）扩充为srcs，与dest（较大的数）有相同的长度，即位数
    string result = dest;
    string cin(result.length(),'0');                                //设置借位字符串，表示每一位的借位
    int bias = dest.length() - src.length();                        
    for(int i = 0; i < bias; i++)                                   //将src赋给srcs，高位补0
        srcs[i] = '0';
    for(int i = bias; i < srcs.length(); i++)
        srcs[i] = src[i - bias];
    for(int i = srcs.length() - 1; i >= 0; i--){
        if (dest[i] >= srcs[i]&&!((dest[i] == srcs[i])&&(cin[i] == '1')))               //对每一位进行比较，考虑是否借位，是则加十，并将高一位的cin置为1
            result[i] = dest[i] - srcs[i] + 48 - (cin[i] - 48);
        else{
            result[i] = dest[i] + 10 - srcs[i] + 48 - (cin[i] - 48);
            cin[i - 1] = '1';
        }
    }
    return result;
}
void display(string result)                                         //显示函数
{
    if(result.length() > 1){                                        //分长度为1和大于1的情况
    int i = 0;  
        for( i = 0; i < result.length() ; i++){                     //开头没有0
            if (result[0]!= '0') {
			i = -1;
			break;
		}
            if(result[i] == '0'&& result[i + 1] != '0')             //开头有0，则找出连续的最后一个0，返回位置
                break;
        }
        for( int j = i + 1;j < result.length(); j++){
            cout << result[j];
        }
    }
    else
        cout << result[0];
    return;
}
void sub(string src, string dest)                                     //调用以上函数
{
    string result;
    if(judgegl(dest, src) == -1)
        cout << 0;
    else if(judgegl(dest, src) == 1){                                 //dest比src大
        result = calculate(src, dest);
        display(result);
    }
    else{                                                             //dest比src小
        result = calculate(dest, src);
        cout << '-';
        display(result);
    }
    return;
}
int main()
{
    string src,dest;
    cin >> dest;
    cin >> src;
    sub(src, dest);
    return 0;
}