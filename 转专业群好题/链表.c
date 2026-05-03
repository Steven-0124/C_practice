#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node* next;
}Node;

Node* createList();//创建链表
void freeList(Node* head);//释放链表
void printList(Node* head);//打印链表
int match(Node* start, char* pattern);//匹配，看是否一样
void opt1 (Node* head, char* s1);
void opt2 (Node* head, char* s1);
void opt3 (Node* head, char* s1, char* s2);

int main (void)
{
    int t = 0;
    char s1[51] = {0};
    char s2[51] = {0};

    Node* head = createList();
    
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        int a = 0;
        scanf("%d", &a);
        if(a == 1) 
        {
            scanf("%s", s1);
            opt1(head, s1);
        }
        else if(a == 2) 
        {
            scanf("%s", s1);
            opt2(head, s1);
        }
        else if(a == 3) 
        {
            scanf("%s %s", s1, s2);
            opt3(head, s1, s2);
        }
    }

    printList(head);
    freeList(head);
    return 0;
}

Node* createList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;
    Node* tail = head;

    int ch = 0;//注意是int,getchar()的返回值也是int
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node -> c = (char)ch;
        new_node -> next = NULL;
        tail -> next = new_node;
        tail = new_node;
    }
    return head;
}

void freeList(Node* head)
{
    Node* p = head;
    while(p)//直到空，malloc是逐个开的，所以要逐个释放避免内存泄漏
    {
        Node* tmp = p;
        p = p -> next;
        free(tmp);
    }
}

void printList(Node* head)
{
    Node* p = head -> next;
    while(p)
    {
        printf("%c", p -> c);
        p = p -> next;
    }
    printf("\n");
}

int match(Node* start, char* pattern)
{
    Node* p = start;
    for(int i = 0; pattern[i]; i++)//直到pattern[i]为\0
    {
        if(!p || p->c != pattern[i]) return 0;//一但触发两个条件的其中一个就匹配失败，返回0
        //条件1：p长度不够，当p为NULL时，!p为1
        //条件2：有不相等的字符，第二个表达式返回1
        p = p -> next;
    }
    return 1;
}


void opt1 (Node* head, char* s1)//删除
{
    int len = strlen(s1);
    Node *pre = head;
    Node *cur = head -> next;

    while(cur)//直到cur指到空指针为止
    {
        if(match(cur, s1))
        {
            for(int i = 0; i < len; i++)
            {
                Node* tmp = cur;
                cur = cur -> next;
                free(tmp);//释放掉这一小段
            }
            pre->next = cur;
        }
        else
        {
            pre = cur;//往后移一格
            cur = cur -> next;
        }
    }
}

void opt2 (Node* head, char* s1)//插入
{
    int len = strlen(s1);
    Node* pre = head;
    Node* cur = head -> next;

    while(cur)
    {
        if(match(cur, s1))
        {
            Node* insert_pos = cur;//插入位置
            for(int i = 0; i < len; i++)//移动s1长度，准备在s1后面插入s1
            {
                insert_pos = insert_pos->next;//指下一个节点  
            }

            Node* new_head = NULL;
            Node* new_tail = NULL;
            for(int i = 0; i < len; i++)//建立存s1的链表
            {
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->c = s1[i];
                new_node->next = NULL;
                if(!new_head)//第一个节点
                {
                    new_head = new_node;
                    new_tail = new_node;
                }
                else
                {
                    new_tail->next = new_node;//连接到尾部
                    new_tail = new_node;//更新尾指针
                }
            }
            //插入
            if(insert_pos)//s1后还有节点
            {
                new_tail->next = insert_pos;
            }
            else//s1后已在链表最后
            {
                new_tail->next = NULL;
            }

            Node* s1_end = cur;
            for(int i = 0; i < len-1; i++)
            {
                s1_end = s1_end->next;//挪位置，找s1最后一个节点
            }
            s1_end->next = new_head;//指向新链表头

            pre = new_tail;//pre指向尾部的位置
            cur = new_tail ? new_tail->next : NULL;
        }
        
        else//不匹配，向后移动
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

void opt3 (Node* head, char* s1, char* s2)//替换
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    Node* pre = head;
    Node* cur = head->next;

    while(cur)
    {
        if(match(cur, s1))//匹配
        {
            //1.删s1
            for(int i = 0; i < len1; i++)
            {
                Node* tmp = cur;
                cur = cur->next;
                free(tmp);
            }
            pre->next = cur;

            //2.插入s2
            Node* new_head = NULL;
            Node* new_tail = NULL;
            for(int i = 0; i < len2; i++)
            {
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->c = s2[i];
                new_node->next = NULL;
                if(!new_head)
                {
                    new_head = new_node;
                    new_tail = new_node;
                }
                else
                {
                    new_tail->next = new_node;
                    new_tail = new_node;
                }
            }

            //插入到原s1位置
            new_tail->next = cur;
            pre->next = new_head;
            pre = new_tail;//pre指向插入s2链表的尾部，继续遍历
        }

        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

/*
题目描述
给定一个初始字符串 ，以及  组操作。
每组操作包含一个操作类型  和一个字符串 。具体操作如下：
? ?
：在  中找到所有出现的 ，并将其删除。
? ?
：在  中找到所有出现的 ，并在每个  后面再插入一个 （相当于复制一遍）。
? ?
：再读入一个字符串 ，在  中将所有出现的 替换为 。
注：若=ababa，输入1 aba后正确的输出是ba，也即重叠出现时只删除第一次出现的。
 组操作全部完成后，输出最终的字符串。
注意：每次操作都是从左到右依次处理所有匹配项，处理完当前操作后再进行下一个操作。
输入格式
第一行包含一个字符串 ，表示初始长串。
第二行包含一个整数 ，表示操作组数。
接下来  行，每行描述一组操作：
? 首先包含一个整数  和一个字符串 。
? 如果 ，则在  后面还有一个字符串 。
输出格式
输出一行，表示  组操作完成后的最终字符串。
输入输出样例
输入 #1
复制
helloworld
3
1 lo
2 o
3 woorld earth
输出 #1
复制
helearth
输入 #2
复制
abcabc
2
1 abc
1 abc
输出 #2
复制
输入 #3
复制
banana
3
3 a o
2 n
1 o
输出 #3
复制
bnnnn
说明/提示
样例解释
样例 #1 解释：
? 初始：helloworld
? 操作 1（删除 lo）：hel + world → hel world
? 操作 2（复制 o）：hel + w + oo + rld → hel woorld
? 操作 3（woorld 替换为 earth）：hel + earth → hel earth
注意：样例输出有空格，请仔细对照。
样例 #2 解释：
? 初始：abcabc
? 操作 1（删除 abc）：所有 abc 被删除 → 空串
? 操作 2（复制 abc）：空串中无 abc，不变
? 最终为空，输出空字符串
数据范围与约定
? 对于  的数据，保证初始字符串  长度 。
? 。
?  长度 ，且不为空串。
? 所有字符串仅包含小写字母。
? 保证操作过程中字符串长度不会超过 。
? 时间限制：
? 内存限制：
注意事项
1. 字符串匹配是区分大小写的（本题全为小写）。
2. 每次操作需要处理所有匹配项，不是只处理第一个。
3. 操作是依次执行的，后一个操作基于前一个操作的结果。
*/