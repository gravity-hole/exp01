#include<iostream>
using namespace std;
struct student {
	int num;
	student* next;
};
int search(student* first, int num)							//在链表中搜索第i个结点的值
{
	student* node = first;
	for (int i = 0; i < num - 1; i++) {
		node = node->next;
	}
	return node->num;
}
student* buildchain() {								//建立链表函数
	student* first = new student;
	first->num = 2;
	first->next = NULL;
	student* tail = first;
	for (int i = 3; i < 100000; i++) {						//首先设置规模为十万的连续自然数的链表
		student* node = new student;
		node->num = i;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	student* spc = new student;								//补充一个空的头节点，方便之后操作
	spc->next = first;
	first = spc;
	student* location = first->next;						//设置现在指向的学生位置（现在为2号），即现在的mod
	for (int i = 3; i < 100000; i++) {
		if (!location)										//考虑location是否有意义
			break;	
		student* q = location;								//设p，q为相邻节点，方便删除操作									
		student* p = location->next;						
		int j = 3;
		int num = 1;
		int mod = location->num;							//当前数到哪儿
		while (j < 100000&&p!=NULL&&q!=NULL) {
			if (!num) {										//如果数到mod，就删除当前节点p
				q->next = p->next;			
				p = q->next;								//并更新p，q不必更新
			}
			else {											//如果没数到，就同时更新p，q
				q = q->next;
				p = p->next;
			}
			j++;											//j是遍历的数据规模
			num = (num + 1) % mod;							//表示数至mod的这个过程
		}
		location = location->next;							//更换mod
	}
	return first;
}
void generate()
{
	int num[10000];
	int i = 0;
	while (cin >> num[i] && (num[i] != 0))
		i++;
	student* first = buildchain();
	for (int j = 0; j < i; j++)
		cout << search(first, num[j] + 1) << '\n';
}
int main()
{
	generate();
	return 0;
}