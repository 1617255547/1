#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<conio.h>

// ���嵥����ڵ���������,�����������Ϳ�����������
typedef int Element;//��ǰΪint
typedef struct node {
    Element el;          // �洢�ڵ�ɸ�����
    struct node* next;  // �洢��һ�ڵ��ַ
}Node;

// ���嵥��������
typedef struct LinkedList {
    Node* head;      // �洢����ͷ�ڵ�
    Node* tail;      // �洢����β�ڵ�
    int size;        // �洢����ڵ���
}LinkedList;

// ��ʼ������
void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// ������β����ӽڵ������
void add(LinkedList* list, Element el) {//����ͷָ�����Ҫ��ӵ�����
    // �����½ڵ�
    Node* node = (Node*)malloc(sizeof(Node));
    node->el = el;
    node->next = NULL;//���½�ָ����ֵNULL

    if (list->head == NULL) {   // ����Ϊ�գ��½ڵ���ͷ�ڵ㣬���Դ�Ϊ�½��ڵ�
        list->head = node;
    }
    else {                    // ����Ϊ�գ����½ڵ���ӵ�β��
        list->tail->next = node;
    }

    list->tail = node;//���¼���������ָ�븳ֵ��¼
    list->size++;//�ڵ�����1
}

// ��������ָ��λ�ò���ڵ�
void insert(LinkedList* list, int index, Element el) {
    if (index >= list->size) {  // indexԽ�磬ֱ����ӵ�β��
        add(list, el);
    }
    else {
        // �����½ڵ�
        Node* node = (Node*)malloc(sizeof(Node));
        node->el = el;
        node->next = NULL;

        Node* p = list->head;    // ָ��ͷ�ڵ�
        Node* q = NULL;         // ָ��ptrǰһ���ڵ�

        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }

        if (q == NULL) {         // ����λ��Ϊͷ�ڵ�
            node->next = p;
            list->head = node;
        }
        else {
            q->next = node;
            node->next = p;
        }

        list->size++;
    }
}

// ɾ��������ָ��λ�ýڵ㲢���ظýڵ�����
int removeNode(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {   // indexԽ��
        printf("ɾ��ʧ�ܣ��ڵ���Խ��");//��֪������ɾ�����
        return -1;  // ����-1��ʾɾ��ʧ��
    }
    else {
        Node* p = list->head;    // ָ��ͷ�ڵ�
        Node* q = NULL;         // ָ��ptrǰһ���ڵ�

        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }

        if (q == NULL) {         // ɾ��ͷ�ڵ�
            list->head = p->next;
        }
        else {
            q->next = p->next;
        }

        if (p == list->tail) {    // ɾ��β�ڵ�
            list->tail = q;
        }

        int data = p->el;       // ��ȡ��ɾ���ڵ�����
        free(p);                  // �ͷŴ�ɾ���ڵ�
        list->size--;

        return data;    // ���ش�ɾ���ڵ�����
    }
}

// ��ȡ����ָ��λ�ýڵ�����
int get(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {   // indexԽ�磬������沢����-1
        printf("�ڵ���Խ�磬��������ȷ�Ľڵ���");
        return -1;
    }
    else {
        Node* p = list->head;    // ָ��ͷ�ڵ�

        for (int i = 0; i < index-1; i++) {
            p = p->next;
        }

        return p->el;   // ����ָ��λ�ýڵ�����
    }
}
//�޸Ľڵ�����
void Modify(LinkedList* list, int index, Element el)
{
    if (index < 0 || index >= list->size) {          // indexԽ�磬������沢����
        printf("�ڵ���Խ�磬��������ȷ�Ľڵ���");
        return;
    }
    else {
        Node* p = list->head;                       // ָ��ͷ�ڵ�
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->el = el;
        printf("\n���޸����\n");
        return;                            
    }
}
// ��ӡ�������ȫ������
void printList(LinkedList* list) {
    Node* p = list->head;

    printf("\nList: ");
    while (p != NULL) {
        printf("%d ", p->el);//������������޸ģ����Լ����壬�˴�Ϊint
        p = p->next;
    }
    printf("\n��ǰ�ڵ���Ϊ��\n%d\n",list->size);
}
//�����˵�
void Menu()
{
    printf("\n=========[����������˵�]============\n");
    printf("[A/a]-��ӡ����\n");
    printf("[B/b]��β����ӽڵ�\n");
    printf("[C/c]���м����ڵ�\n");
    printf("[D/d]ɾ���ڵ�\n");
    printf("[E/e]��ȡ�����ڵ�����\n");
    printf("[F/f]�޸Ľڵ�����\n");
    printf("[�ո�]-�˳�\n");
    printf("=================================\n");
}
// ������
int main() {
    LinkedList list;

    initList(&list);        // ��ʼ������

    add(&list, 1);          // ��ӽڵ�
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);

    printList(&list);       // ��ӡ��ʼ����

    printf("\n�������Ѿ��������ݣ�������ʾ���������һ������\n");
    int i;
    Element el;            //�洢����ڵ��������ݣ�����������
    char c = '0';
    do
    {
        printf("\n�����Ҫ������������,ɾ��������������\n�ڵ���+�ո�+���������+�س�\n������ʹ�õ�������������0\n");
        scanf_s("%d %d", &i, &el);                 //�������������ͷ����仯ʱ���˴����޸���������
        Menu();
        printf("\n��ѡ������Ҫ�Ĳ���\n");
        switch (c = _getch())
        {
        case 'A':
        case 'a':printList(&list);            //�������
            break;
        case 'B':
        case 'b':add(&list, el);               //��ӽڵ�
            break;
        case 'C':
        case 'c':insert(&list, i, el);         //����ڵ�
            break;
        case 'D':
        case 'd':removeNode(&list, i);       // ɾ���ڵ�
            break;
        case 'E':
        case 'e':printf("The %drd element is: %d\n\n", i, get(&list, 2));    // ��ȡ�ڵ�����
            break;
        case 'F':
        case 'f':Modify(&list, i, el);
            break;
        }
    } while (c != ' ');

        return 0;
    }