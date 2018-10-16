#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
void window5()
{
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");
    printf("\t   1:键盘录入\n");
    printf("\t   2:文件录入\n");
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");
}
void window3()
{
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");
    printf("\t    1:修  改   学   生   姓   名\n");
    printf("\t    2:修  改   学   生   学   号\n");
    printf("\t    3:修  改   学   生   已   选   课   程\n");
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");
}
void window1()
{
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *");
    printf("\n\n\t学   生   管   理   信   息   系  统\n");
    printf("\t    1:新  增   学   生   信   息\n");
    printf("\t    2:修  改   学   生   信   息\n");
    printf("\t    3:删  除   学   生   信   息\n");
    printf("\t    4:查  看   所   有   学   生   信   息\n");
    printf("\t    5:查  看   某   个   学   生   信   息\n");
    printf("\t    6:初  始   化   学   生   信   息\n\n");
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");
}
void  updateStu()
{
       FILE *fp;
       int i;
       Student *stu,*r;
       Class *cla,*s;
       cla=(Class *)malloc(sizeof(Class));
       stu=(Student *)malloc(sizeof(Student));
       r=(Student *)malloc(sizeof(Student));
       cla=readClass(cla);
       stu=read(stu);
       r=stu;
       fp=fopen("./ModuleA/student.txt","w");
       while(r)
       {
            s=cla->next;
            r->sum=0;
            for(i=0;i<5;i++)
            {
                 while(s&&(strcmp(r->c[i].ClassName,"0")!=0))
                 {
                      if(strcmp(r->c[i].ClassName,s->ClassName)==0)
                       {
                             r->sum+=s->ClassScore;
                             break;
                       }
                       s=s->next;
                 }
                 if(s==NULL)
                 {
                        strcpy(r->c[i].ClassName,"0");
                 }
            }
            r=r->next;
       }
       stu=stu->next;
       while(stu)
       {
           fwrite(stu,sizeof(Student),1,fp);
           stu=stu->next;
       }
       fclose(fp);
}
Student *read(Student *head)
{
        int i=0;
        int n=0;
        Student *s,*q,*r;
        FILE *fp;
        fp=fopen("./ModuleA/student.txt","r");
        s=head;
        fseek(fp,0,SEEK_END);
        n=ftell(fp)/sizeof(Student);
        rewind(fp);
        for(i=0;i<n;i++)
        {
              Student *r;
              r=(Student *)malloc(sizeof(Student));
              fread(r,sizeof(Student),1,fp);
              r->next=NULL;
              s->next=r;
              s=s->next;
        }
      fclose(fp);
      return head;
}
void update(Student *head)
{
       FILE *fp;
       fp=fopen("./ModuleA/student.txt","w");
       Student *s;
       s=head->next;
       while(s)
       { 
            
                fwrite(s,sizeof(Student),1,fp);
                s=s->next;
       }
       fclose(fp);
}
void delete(Student *head)
{
       Student *s,*r;
       FILE *fp;
       int number;
       char c[30];
       char p,q;
       s=head->next;
       r=head;
       printf("是否要删除一个学生的完整信息(Y/N):");
       scanf("%c",&p);
       getchar();
       if(p=='Y')
       {
            printf("请输入一个要删除的学生的学号或者姓名:");
            scanf("%s",c);
            getchar();
            while(s)
            {
                  
                     if((strcmp(s->StudentName,c)==0)||(s->StudentNum==atoi(c)))
                      {
                              r->next=s->next;
                              free(s);
                              break;
                      }
                     r=s;
                     s=s->next;
            }
       }
       update(head);
       updateClass();
       
}
void alter(Student *head)
{
       Student *s;
       int i=0;
       int n;
       char p,q,ch;
       char c[30];
       s=head->next;
       printf("是否要修该一个学生信息(Y/N)");
       scanf("%c",&p);
       getchar();
       while(p!='N')
       {
            printf("请输入你要修改的一个学生的学号或者姓名:");
            scanf("%s",c);
            getchar();
             while(s)
            {
                  
                     if((strcmp(s->StudentName,c)==0)||(s->StudentNum==atoi(c)))
                      {
                            system("clear");
                            window3();
                            printf("请输入你的选择:");
                            scanf("%d",&n);
                            getchar();
                            switch(n)
                            { 
                                  case 1:
                                  {
                                       printf("请输入你要修改的姓名:");
                                       scanf("%s",s->StudentName);
                                       getchar();
                                       break;
                                  }
                                  case 2:
                                  {
                                       printf("请输入你要修改的学号:");
                                       scanf("%d",&s->StudentNum);
                                       getchar();
                                       break;
                                  }
                                  case 3:
                                  {
                                       s->sum=0;
                                       printf("请输入你要修改的课程:");
                                       do
                                       {
                                            scanf("%s",s->c[i].ClassName);
                                            Class *cla;
                                            cla=(Class *)malloc(sizeof(Class));
                                            cla=readClass(cla);
                                            cla=cla->next;
                                            while(cla)
                                            {
                                             if(strcmp(cla->ClassName,s->c[i].ClassName)==0)
                                             {
                                                s->sum+=cla->ClassScore;
                                             }
                                            cla=cla->next;
                                            }
                                            i++;
                                            ch=getchar();
                                       }while(ch!='\n');
                                       for(;i<5;i++)
                                       {
                                               strcpy(s->c[i].ClassName,"0");
                                       }
                                  }
                            } 
                            break;
                      }
                     s=s->next;
            }
            printf("是否要继续修该一个学生信息(Y/N):");
            scanf("%c",&p);
            getchar();
       }
       system("clear");
       window1();
       update(head);
       updateClass();
}
void cat(Student *head)
{    
       int i;
       Student *q,*p,*s;
       s=head->next;
       printf("学生学号\t学生姓名\t学生已选课程\t\t\t\t学分总和\n");
       while(s)
       {
          i=0;
          printf("%d\t\t%s\t\t",s->StudentNum,s->StudentName);
          for(i=0;i<5;i++)
          {
               if(strcmp(s->c[i].ClassName,"0")!=0)
                {
                  printf("%s\t",s->c[i].ClassName);
                }
               else
                {
                   printf("\t");
                }
               
          }
          printf("%d\n",s->sum);
          s=s->next;
       }
}
void catStu(Student *head)
{    
       int i;
       Student *q,*p,*s;
       char c[30];
       s=head->next;
       printf("请输入你要查看的学生的学号或者姓名:");
       scanf("%s",c);
       getchar();
       
       while(s)
       {
          if((strcmp(s->StudentName,c)==0)||(s->StudentNum==atoi(c)))
          {
          i=0;
          printf("学生学号\t学生姓名\t学生已选课程\t\t\t\t学分总和\n");
          printf("%d\t\t%s\t\t",s->StudentNum,s->StudentName);
          for(i=0;i<5;i++)
          {
               if(strcmp(s->c[i].ClassName,"0")!=0)
                {
                  printf("%s\t",s->c[i].ClassName);
                }
               else
                 
                {
                   printf("\t");
                }
               
          }
          printf("%d\n",s->sum);
          break;
          }
          s=s->next;
       }
}
void add()
{
      FILE *fp;
      char p,q;
      int i=0;
      int number;
      fp=fopen("./ModuleA/student.txt","a+");
      printf("是否要添加一个学生信息(Y/N):");
      scanf("%c",&p);
      getchar();
      while(p!='N')
      {
           i=0;
           Student *s;
           s=(Student *)malloc(sizeof(Student));
           s->sum=0;
           printf("请输入一个学生的学号和姓名:");
           scanf("%d%s",&s->StudentNum,s->StudentName);
           getchar();
           do
           {
                
                 printf("请输入一个课程名称:");
                 scanf("%s",s->c[i].ClassName);
                 getchar();
                
                 Class *cla;
                 cla=(Class *)malloc(sizeof(Class));
                 cla=readClass(cla);
                 cla=cla->next;
                 while(cla)
                 {
                         if(strcmp(cla->ClassName,s->c[i].ClassName)==0)
                            {
                                      s->sum+=cla->ClassScore;
                            }
                            cla=cla->next;
                 }
                 i++;
                 printf("是否继续添加一个课程的名称和学分:(Y/N):");
                 scanf("%c",&q);
                 getchar();
           }while(q!='N');
           for(;i<5;i++)
           {
                strcpy(s->c[i].ClassName,"0");
           }
           fwrite(s,sizeof(Student),1,fp);
           printf("是否要继续添加一个学生信息(Y/N):");
           scanf("%c",&p);
           getchar();
      }
      fclose(fp);
      updateClass();
}
void input()
{
      FILE *fp;
      char p,q;
      int i=0;
      int number;
      fp=fopen("student.txt","w");
      printf("是否要添加一个学生信息(Y/N):");
      scanf("%c",&p);
      getchar();
      while(p!='N')
      {
           i=0;
           Student *s;
           s=(Student *)malloc(sizeof(Student));
           s->sum=0;
           printf("请输入一个学生的学号和姓名:");
           scanf("%d%s",&s->StudentNum,s->StudentName);
           getchar();
           do
           {
                
                 printf("请输入一个课程名称:");
                 scanf("%s",s->c[i].ClassName);
                 getchar();
                
                 Class *cla;
                 cla=(Class *)malloc(sizeof(Class));
                 cla=readClass(cla);
                 cla=cla->next;
                 while(cla)
                 {
                         if(strcmp(cla->ClassName,s->c[i].ClassName)==0)
                            {
                                      s->sum+=cla->ClassScore;
                            }
                            cla=cla->next;
                 }
                 i++;
                 printf("是否继续添加一个课程的名称和学分:(Y/N):");
                 scanf("%c",&q);
                 getchar();
           }while(q!='N');
           for(;i<5;i++)
           {
                strcpy(s->c[i].ClassName,"0");
           }
           fwrite(s,sizeof(Student),1,fp);
           printf("是否要继续添加一个学生信息(Y/N):");
           scanf("%c",&p);
           getchar();
      }
      fclose(fp);
      updateClass();
}
void initStu()
{
      
       int n;
       system("clear");
       window5();
       l:printf("请输入你的选择(1-2)(按3结束):");
       scanf("%d",&n);
       getchar();
       switch(n)
       {
             case 1:
             {
                    input();
                    break;
             }
             case 2:
             {
                   
                   break;
             }
             case 3:
             {
                   
                   break;
             }
             default:
             {
                    printf("你输入的有误,请重新输入\n");
                    goto l;   
             }
       }
      system("clear");
      window1();
}
int student()
{
    int i;
    int j;
    int n;
    int p=0;
    window1();
    while(1)
    {
	printf("请输入你的选择(按7退出):");
        scanf("%d",&n);
        getchar();
        switch(n)
       {
            case 1:add();continue;
            case 2:
           {
            Student *stu;
            stu=(Student *)malloc(sizeof(Student));
            stu=read(stu);
            alter(stu);continue;
            }
            case 3:
            {
             Student *stu;
             stu=(Student *)malloc(sizeof(Student));
             stu=read(stu);
             delete(stu);continue;
            }
           case 4:{
            Student *stu;
            stu=(Student *)malloc(sizeof(Student));
            stu=read(stu);
            cat(stu);
            continue;
           }
           case 5:{
           Student *stu;
           stu=(Student *)malloc(sizeof(Student));
           stu=read(stu);
           catStu(stu);
           continue;
           }
           case 6:{
                 initStu();
                 break;
           }
           case 7:{p=1;system("clear");break;}
           default:printf("你输入有误，请重输");continue;
        }
        if(p)break;
     }
     
}


