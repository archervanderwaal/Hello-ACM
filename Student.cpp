# include <stdio.h>
# define NULL 0
# include <malloc.h>
# define LEN sizeof (struct student)
# include <stdlib.h>
# include <conio.h>
# include <unistd.h>
# include <windows.h> 

int n = 0;//全局变量
/*
**结构体
*/
struct student 
{
    long int number;
    char name [20];
    char sex[20];
    int chinese ;
    int math;
    int english;
    float aver;
    struct student * next;
};

/*
**主菜单函数
*/
void menu ()
{
    printf ("\n\n\n\n\n");
    printf ("\t\t*****学生成绩管理系统*****\n"); 
    printf ("\t\t         1、输入学生信息               \n");
    printf ("\t\t         2、输出学生信息              \n");
    printf ("\t\t         3、删除学生信息              \n");
    printf ("\t\t         4、查找学生信息              \n");
    printf ("\t\t         5、按平均分排序               \n");
    printf ("\t\t         6、插入学生信息           \n");
    printf ("\t\t         0、退出菜单               \n ");  
       printf ("\t\t***************************\n");
       printf ("请输入您要进行的操作编号:\n");
}

/*
**创建链表（添加学生信息）
*/
struct student * creat_list ()
{
    struct student * head, * p1, * p2;
    head = NULL;
    p1 = (struct student *) malloc (LEN);
    if (p1 == NULL)
    {
        printf ("内存分配失败！\n");
        exit (0);
    }
    printf ("请按111111 xxx 男/女 80 80 80的形式录入信息（如果要终止输入,请将学号输为0）:\n");
    printf ("学号     姓名   性别   语文   数学   英语\n");
    scanf ("%ld",&p1->number);
    scanf ("%s",p1->name);
    scanf ("%s",&p1->sex);
    scanf ("%d%d%d",&p1->chinese,&p1->math,&p1->english);
    p1->aver =( p1->chinese + p1->math + p1->english)/3;
    while (p1->number>0)
    {
        n++;
        if (n == 1)
        head = p1;
        else 
        p2->next = p1;
        p2 = p1;
        p1 = (struct student * )malloc (LEN);
        while (p1 == NULL)
        {
            printf ("内存分配失败！\n");
            exit (0);
        }
        scanf ("%ld",&p1->number);
       scanf ("%s",p1->name);
      scanf ("%s",&p1->sex);
      scanf   ("%d%d%d",&p1->chinese,&p1->math,&p1->english); 
      p1->aver =( p1->chinese + p1->math + p1->english)/3;
    }
    //printf ("录入学生信息完毕，请继续选择:\n");
    free (p1);
    p1=NULL;
    return (head);
}


/*
**输出（学生）信息函数
*/
void print_list (struct student * head)
{
    printf (" 学号    姓名   性别    语文   数学   英语        平均分\n");
    struct student * p;
    p = head;
    while (p!=NULL)
    {
        printf("%ld   ",p->number);
        printf ("%5s%5s   %5d   %5d   %5d       %5f ",p->name,p->sex,p->chinese,p->math,p->english,p->aver);
        printf ("\n");
        p = p->next;
    }
}



/*
**删除函数
*/
struct student *delete_list (struct student *head)
{
    struct student * p1;
    struct student * p2;
    long int de_num;
    printf ("请输入您要删除学生的学号:\n");
    scanf ("%ld",&de_num);
    if (head == NULL)
    {
        printf ("非法的链表！");
        return head;
    }
    p1 = head;
    while (p1->number != de_num&&p1->next !=NULL)
     {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->number == de_num)
    {
        if (p1 == head)
        {
            head = p1->next;
        }
        else 
        {
            p2->next = p1->next;
        }
        free (p1);
        p1 = NULL;
        n = n-1;
    }
   else 
   {
      printf ("没有找到您要删除的学号!\n");
   }
    return head;
}


/*
**清除缓存区以及清屏
*/
void clear_s ()
{
            __fpurge (stdin);
            getchar ();
            system ("clear");
            menu();
}


/*
**查找函数
*/

struct student * find_stu (struct student * head )
{
    long int num;
    printf ("请输入你要查找的学号:\n");
    scanf ("%ld",&num);
    struct student * p1;
    p1 = head;
    for (;;)
    {
        if (p1->number == num)
        {
        return p1;
        break;
        }
        else
        p1=p1->next;
      }
}


/*
**输出查找信息
*/
void print_find (struct student * p1)
{
    printf ("您要查找的是:\n");
    printf ("学号     姓名   性别   语文   数学   英语\n");
     printf("%ld   ",p1->number);
        printf ("%5s%5s   %5d   %5d   %5d",p1->name,p1->sex,p1->chinese,p1->math,p1->english);
        printf ("\n");
}

/*
**功能5:按平均分排序
*/

struct student *ave_list(struct student *head)
{
 struct student *first;   //为原链表剩下用于直接插入排序的节点头指针
 struct student *t;    //临时指针变量：插入节点
 struct student *p,*q;     //临时指针变量
 first = head->next;  //原链表剩下用于直接插入排序的节点链表：可根据图12来理解
 head->next = NULL;  //只含有一个节点的链表的有序链表：可根据图11来理解
 while(first != NULL)  //遍历剩下无序的链表
 {
  //注意：这里for语句就是体现直接插入排序思想的地方
  for (t = first, q = head; ((q != NULL) && (q->aver < t->aver)); p = q, q = q->next); //无序节点在有序链表中找插入的位置
  //退出for循环，就是找到了插入的位置，应该将t节点插入到p节点之后，q节点之前
  //注意：按道理来说，这句话可以放到下面注释了的那个位置也应该对的，但是就是不能。原因：你若理解了上面的第3条，就知道了
  //下面的插入就是将t节点即是first节点插入到p节点之后，已经改变了first节点，所以first节点应该在被修改之前往后移动，不能放到下面注释的位置上去
  first = first->next; //无序链表中的节点离开，以便它插入到有序链表中
  if (q == head)  //插在第一个节点之前
  {
   head = t;
  }
  else   //p是q的前驱
  {
   p->next = t;
  }
  t->next = q;  //完成插入动作
  //first = first->next; 
 }
 return head;
}




/*
**功能6：插入学生信息
*/
struct student * insert (struct student * head)
{
    long int num;
    struct student * p, * p1, * p2;
  printf ("请输入您要插入学生的学号:\n");
   scanf ("%ld",&num);
   p = head;
   if (head == NULL)
   {
       p2 = (struct student *)malloc (LEN);
       if(p2 == NULL)
       {
           printf ("开辟节点失败");
           return NULL;
       }
       head = p2;
       p2->number = num;
       printf ("请输入您要插入的学生的姓名性别语文数学英语成绩\n");
        scanf ("%s",p2->name);
        scanf ("%s",&p2->sex);
        scanf ("%d%d%d",&p2->chinese,&p2->math,&p2->english);
        p2->aver =( p2->chinese + p2->math + p2->english)/3;
        n=n+1;
        return head;
     }
     else
     {
         p = head;
         while (p->number <num&&p->next!=NULL)
         {
             p1 = p;
             p = p->next;
         }
       if (p1->next == NULL)
        {
            p2=(struct student *)malloc(LEN);
            if (p2 == NULL)
            {
                printf ("开辟节点失败\n");
                return NULL;
            }
            p->next = p2;
            p2->next = NULL;
            p2->number = num;
            printf ("请输入您要插入的学生的姓名性别语文数学英语成绩\n");
        scanf ("%s",p2->name);
        scanf ("%s",&p2->sex);
        scanf ("%d%d%d",&p2->chinese,&p2->math,&p2->english);
        p2->aver =( p2->chinese + p2->math + p2->english)/3;
        n = n + 1;
            return head;
         }
         else
         {
         p2=(struct student *)malloc (LEN);
             if(p2 == NULL)
            {
                 printf ("开辟节点失败");
                 return NULL;
           }
         p1->next = p2;
         p2->next = p;
         p2->number = num;
                printf ("请输入您要插入的学生的姓名性别语文数学英语成绩\n");
        scanf ("%s",p2->name);
        scanf ("%s",&p2->sex);
        scanf ("%d%d%d",&p2->chinese,&p2->math,&p2->english);
        p2->aver =( p2->chinese + p2->math + p2->english)/3;
        n = n+1;
        return head;
        }
     }
}


/*
**主函数
*/
int main (void)
{
    int choice;
    struct student * head, * phead;
    struct student * p1;
    printf("\033[36;m");
    menu();
    scanf ("%d",&choice);
    while (choice != 0)
    {
        switch (choice )
        {
            case 1:
                head = creat_list ();
              printf("录入完毕,任意键返回\n");
                clear_s();
            break;
            case 2:
                 print_list (head);
              printf ("输出完毕,任意键返回\n");
                clear_s();
            break;
            case 3:
                delete_list(head);
                if (head == NULL)
                {
                 printf ("删除不成功,请选择:\n");
                    scanf ("%d",&choice);
                    break;
                }
              printf ("删除完毕,任意键返回\n");
                clear_s();
                break;
            case 4:
                 p1 = find_stu(head);
                 print_find(p1);
              printf ("查找完毕,任意键返回\n");
                   clear_s();
                  break;
           case 5:
                 phead = ave_list (head);
                 print_list(phead);
              printf ("排序完毕,任意键返回\n");
                 clear_s();
                 break;
           case 6:
                 head = insert (head);
                 print_list(head);
              printf ("插入完毕,任意键返回\n");
                 clear_s();
                 break;
           case 0:
                 exit (0);
                     break;
          }
        scanf ("%d",&choice);
    }
}
