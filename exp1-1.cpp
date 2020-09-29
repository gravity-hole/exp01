#include<iostream>
using namespace std;
int line[100000];
int main()                                      //运用静态链表
{
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){                 
        int a , b;
        cin >> a;
        cin >> b;
        line[b] = a;                            //该行表示b的前驱为a
    }
    int location = 0;
    for(int i = 0; i < n; i++){
        cout << line[location] <<' ';
        location = line[location];
    }
    return 0;
}