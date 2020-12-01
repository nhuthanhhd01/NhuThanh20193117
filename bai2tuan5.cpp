#include<iostream>

using namespace std;

struct Node

{

float data;

Node* next;

};

// khai bao danh sach

struct List

{

Node* firstNode;

Node* finalNode;

};

// khoi tao danh sach

void List_Init(List* list)

{

list->firstNode = NULL;

list->finalNode = NULL;

}

//them phan tu vao dau danh sach

Node* List_Add(List* list, float data)

{

Node* newnode = new Node;

newnode->data = data;

newnode->next = list->firstNode;

list->firstNode = newnode;

return newnode;

}

int List_Length(List* list)

{

	Node* node = list->firstNode;

		int i = 0;

while (node != NULL) {

		i++;

		node = node->next;

}

return i;

}

//hien thi noi dung phan tu trong danh sach

void List_Display(List* list)

{

Node* node = list->firstNode;

	int i = List_Length(list);

	cout << "\nDo dai cua list:\t" << i;

if (list->firstNode == 0)

	cout << "\nList rong\r\n";

else

{

while (node != NULL)

{

cout << "\ndia chi cua node " << i << "\t" << &node->data;

cout << "\nnode->data:\t\t" << node->data;

cout << "\nnode->next:\t\t" << node->next << "\n";

node = node->next;

i--;

}

}

}

	Node* Themphantu(List* list, float data, int k)

{

	Node* p = List_Add(list, data);

	list->firstNode = p->next;

	Node* q = list->firstNode;

	Node* r = list->firstNode;

if (k == 1)

{

	Node* p = List_Add(list, data);

return p;

}

	int dem = 0;

while (r != NULL && dem != k - 1)

{

		dem++;

	if (dem < k - 1)

	q = q->next;

	r = r->next;

}

	p->next = r;

	q->next = p;

}

Node* XoaPhanTu(List* list, int k)

{

	Node* p = list->firstNode;

	Node* q = list->firstNode;

if (k == 1)

	list->firstNode = list->firstNode->next;

	int dem = 0;

	while (dem != k && q != NULL)

{

	dem++;

	if (dem < k - 1)

	p = p->next;

	if (dem <= k)

	q = q->next;

}

	p->next = q;

}

int main()

{

	List list1;

	List_Init(&list1);

	List_Display(&list1);

	List_Add(&list1, 1);//list: 1

	List_Add(&list1, 2);//list: 2 1

	cout << "Noi dung list sau hai lenh List_Add:";

	List_Display(&list1);

		cout << "Noi dung list sau khi them 2 lenh List_Add nua:";

	List_Add(&list1, 3);//list: 3 2 1

	List_Add(&list1, 4);//list 4 3 2 1

	List_Display(&list1);

		cout << "Day sau khi them phan tu la:\n";

	Themphantu(&list1, 8, 3);

	List_Display(&list1);

		cout << "Day sau khi xoa phan tu la:\n";

	XoaPhanTu(&list1, 2);

	List_Display(&list1);

		return 0;

}
