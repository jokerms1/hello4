#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
void window4()
{
    printf("*   *   *   *   *   *   *   *   *  *  *  *  *\n");
    printf("\t    1:修  改   课   程   号                 \n");
    printf("\t    2:修  改   课   程   名   称            \n");
    printf("\t    3:修  改   课   程   性   质            \n");
    printf("\t    4:修  改   课   程   学   时            \n");
    printf("\t    5:修  改   课   程   学   分 \n");
    printf("\t    6:修  改   课   程   人   数   上   限   \n");
    printf("\t    7:退  出   当   前   界   面\n");
    printf("*   *   *   *   *   *   *   *    *   *   *  *\n");
}
void window2()
{
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *  *  *  *  *");
    printf("\n\n\t课    程    管   理   信   息   系  统\n");
    printf("\t    1:新  增   课   程   信   息   系  统\n");
    printf("\t    2:修  改   课   程   信   息\n");
    printf("\t    3:删  除   课   程   信   息\n");
    printf("\t    4:查  看   课   程   信   息\n");
    printf("\t    5:查  看   某   个   课   程   的  详  细   信   息\n");
    printf("\t    6:初  始   化   课   程   信   息\n\n");
    printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *  *  *  *  *\n");
}
void addClass()
{
    FILE *fp;
    char p;
    fp=fopen("./ModuleB/class.txt","a+");
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程人数上线\n");
    printf("是否要添加一个课程信息(Y/N):");
    scanf("%c",&p);
    getchar();
    while(p!='N')
    {
        Class *cla;
        cla=(Class *)malloc(sizeof(Class));
        printf("课程编号:");
        scanf("%d",&cla->ClassNum);
        getchar();
        printf("课程名称:");
        scanf("%s",cla->ClassName);
        getchar();
        printf("课程性质:");
        scanf("%s",cla->ClassQuality);
        getchar();
        printf("授课学时:");
        scanf("%d",&cla->ClassTime);
        getchar();
        printf("学分:");
        scanf("%d",&cla->ClassScore);
        getchar();
        cla->StuNum=0;
        Student *stu;
        stu=(Student *)malloc(sizeof(Student));
        stu=read(stu);
        stu=stu->next;
        while(stu)
        {
            
             for(int i=0;i<5;i++)
               if(strcmp(stu->c[i].ClassName,cla->ClassName)==0)
                 {
                        cla->StuNum++;
                 }
             stu=stu->next;
        }
        printf("课程人数上线:");
        scanf("%d",&cla->StuLimit);
        getchar();
        fwrite(cla,sizeof(Class),1,fp);
        printf("是否要继续添加一个课程信息(Y/N):");
        scanf("%c",&p);
    }
    fclose(fp); 
}
void inputClass()
{
    FILE *fp;
    char p;
    fp=fopen("./ModuleB/class.txt","w");
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程人数上线\n");
    printf("是否要添加一个课程信息(Y/N):");
    scanf("%c",&p);
    getchar();
    while(p!='N')
    {
        Class *cla;
        cla=(Class *)malloc(sizeof(Class));
        printf("课程编号:");
        scanf("%d",&cla->ClassNum);
        getchar();
        printf("课程名称:");
        scanf("%s",cla->ClassName);
        getchar();
        printf("课程性质:");
        scanf("%s",cla->ClassQuality);
        getchar();
        printf("授课学时:");
        scanf("%d",&cla->ClassTime);
        getchar();
        printf("学分:");
        scanf("%d",&cla->ClassScore);
        getchar();
        cla->StuNum=0;
        Student *stu;
        stu=(Student *)malloc(sizeof(Student));
        stu=read(stu);
        stu=stu->next;
        while(stu)
        {
            
             for(int i=0;i<5;i++)
               if(strcmp(stu->c[i].ClassName,cla->ClassName)==0)
                 {
                        cla->StuNum++;
                 }
             stu=stu->next;
        }
        printf("课程人数上线:");
        scanf("%d",&cla->StuLimit);
        getchar();
        fwrite(cla,sizeof(Class),1,fp);
        printf("是否要继续添加一个课程信息(Y/N):");
        scanf("%c",&p);
    }
    fclose(fp); 
}
Class *readClass(Class *head)
{
        int i,n;
        Class *s,*q;
        FILE *fp;
        fp=fopen("./ModuleB/class.txt","r");
        s=head;
        fseek(fp,0,SEEK_END);
        n=ftell(fp)/sizeof(Class);
        rewind(fp);
        for(i=0;i<n;i++)
        {
              Class *r;
              r=(Class *)malloc(sizeof(Class));
              fread(r,sizeof(Class),1,fp);
              r->next=NULL;
              s->next=r;
              s=s->next;
        }
      fclose(fp);
      return head;    
}
void catClass(Class *head)
{
         Class *s,*p;
         s=head->next;
         printf("课程编号 课程名称 课程性质    授课学时 学分 课程已选人数 课程人数上线\n");
         while(s)
         {
             printf("%d\t %s\t  %s\t%d\t %d\t  %d\t    %d\n",s->ClassNum,s->ClassName,s->ClassQuality,s->ClassTime,s->ClassScore,s->StuNum,s->StuLimit);
             s=s->next;
         }
}
void catCla1(Class *head)
{
         Class *s,*p;
         
         int i=0,j=0;
         char c[30];
         printf("请输入你要搜索的课程名或者课程号:");
         scanf("%s",c);
         s=head->next;
         getchar();
         while(s)
         {
              if((strcmp(s->ClassName,c)==0)||(s->ClassNum==atoi(c)))
              {
                    printf("课程编号 课程名称 课程性质    授课学时 学分 课程已选人数 课程人数上线\n");
                    printf("%d\t %s\t  %s\t%d\t %d\t  %d\t    %d\n",s->ClassNum,s->ClassName,s->ClassQuality,s->ClassTime,s->ClassScore,s->StuNum,s->StuLimit);
                    printf("\n\n");
                    Student *stu;
                    stu=(Student *)malloc(sizeof(Student));
                    stu=read(stu);
                    stu=stu->next;
                    printf("\n已选的课程的学生信息:\n");
                    while(stu)
                    {
                          for(i=0;i<5;i++)
                          {
                               if(strcmp(stu->c[i].ClassName,s->ClassName)==0)
                                {
                                    
                                     j=0;
                                     printf("%d\t\t%s\t\t",stu->StudentNum,stu->StudentName);
                                      for(j=0;j<5;j++)
                                     {
                                         if(strcmp(stu->c[j].ClassName,"0")!=0)
                                         {
                                           printf("%s\t",stu->c[j].ClassName);
                                         }
                                         else
                                         {
                                           printf("\t");
                                         }
                                    }
                                    printf("%d\n",stu->sum);
                                    break; 
                                }
                          }
                          stu=stu->next;
                    }
                    break;
              }
              s=s->next;
         }
}
void updateClass1(Class *head)
{
       Class *s;
       FILE *fp;
       fp=fopen("./ModuleB/class.txt","w");
       s=head->next;
       while(s)
       {
              fwrite(s,sizeof(Class),1,fp);
              s=s->next;
       }
       fclose(fp);
}
void deleteClass(Class *head)
{
       Class *cla,*r;
       int number;
       char c[30];
       char p,q;
       cla=head->next;
       r=head;
       printf("是否要删除一个课程的完整信息(Y/N):");
       scanf("%c",&p);
       getchar();
       if(p=='Y')
       {
            printf("请输入一个要删除的课程的课程号或者名称:");
            scanf("%s",c);
            getchar();
            while(cla)
            {
                  
                     if((strcmp(cla->ClassName,c)==0)||(cla->ClassNum==atoi(c)))
                      {
                              r->next=cla->next;
                              free(cla);
                              break;
                      }
                     r=cla;
                     cla=cla->next;
            }
       }
       updateClass1(head);
       updateStu();
}
void alterClass(Class *head)
{
     Class *s;
     int n;
     char c[30];
     s=head->next;
      printf("请输入要修改的课程号或者课程信息:");
     system("clear");
     window4();
     scanf("%s",c);
     getchar();
     while(s)
     {
             if((strcmp(s->ClassName,c)==0)||(s->ClassNum==atoi(c)))
             {
                  
                  
                  l:printf("请输入你的选择:");
                  scanf("%d",&n);
                  getchar();
                  switch(n)
                  {  
                        case  1:
                        { 
                             printf("请输入修改后的课程编号:");
                             scanf("%d",&s->ClassNum);
                             getchar();
                             break;
                        }
                        case  2:
                        { 
                            printf("请输入修改后的课程名称:");
                            scanf("%s",s->ClassName);
                            getchar();
                             system("clear");
                             window2();
                            break;
                        }
                        case  3:
                        {
                             printf("请输入修改后的课程性质:");
                             scanf("%s",s->ClassQuality);
                             getchar(); system("clear");
                             window2();break;
                        }
                        case  4:
                        {
                             printf("请输入修改后的授课学时:");
                             scanf("%d",&s->ClassTime);
                             getchar(); system("clear");
                             window2();break;
                        }
                        case  5:
                        {
                             printf("请输入修改后的课程学分:");
                             scanf("%d",&s->ClassScore);
                             getchar(); system("clear");
                             window2();break;
                        }  
                        case  6:
                        {
                             printf("请输入修改后的课程人数上限:");
                             scanf("%d",&s->StuLimit);
                             getchar(); system("clear");
                             window2();break;
                        }
                        case  7:
                        {  
                             system("clear");
                             window2();
                             break;
                        }
                        default:
                         {
                              printf("输出有误,请重新输入:");
                              goto  l;
                         } 
                  }  
             }
             s=s->next;
     }
     updateClass1(head);
     updateStu();
}
void updateClass()
{
      int i;
      FILE *fp;
      Class *cla,*head;
      Student *stu,*s;
      cla=(Class *)malloc(sizeof(Class));
      cla=readClass(cla);
      head=cla;
      fp=fopen("./MoudleB/class.txt","w");
      cla=cla->next;
      s=(Student *)malloc(sizeof(Student));
      s=read(s);
      stu=s->next;
      while(cla)
      {
    
           cla->StuNum=0; 
           while(stu)
           {
            
             for(i=0;i<5;i++)
               if(strcmp(stu->c[i].ClassName,cla->ClassName)==0)
                 {
                        cla->StuNum++;
                        break;
                 }
              stu=stu->next;
            }
           stu=s->next;
           cla=cla->next;
      }
      head=head->next;
      while(head)
      {
            fwrite(head,sizeof(Class),1,fp);
            head=head->next;
      }
      fclose(fp);
}
void initClass()
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
                    inputClass();
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
      window2();
}
int class()
{
    int i;
    int j;
    int n;
    int p=0;
    window2();
    while(1)
    {
	printf("请输入你的选择(按7退出):");
        scanf("%d",&n);
        getchar();
        switch(n)
       {
            case 1:addClass();continue;
            case 2:
           {
            Class *cla;
            cla=(Class *)malloc(sizeof(Class));
            cla=readClass(cla);
            alterClass(cla);
             continue;
            }
           case 3:
            {
             Class  *cla;
             cla=(Class *)malloc(sizeof(Class));
             cla=readClass(cla);
             deleteClass(cla);
             continue;
            }
           case 4:{
             Class  *cla;
             cla=(Class *)malloc(sizeof(Class));
             cla=readClass(cla);
             catClass(cla);continue;
           }
           case 5:{
             Class *cla;
             cla=(Class *)malloc(sizeof(Class));
             cla=readClass(cla);
             catCla1(cla);
             continue;
           }
           case 6:{
               initClass();
               continue;
           }
           case 7:{p=1;system("clear");break;}
           default:printf("你输入有误，请重输");continue;
        }
        if(p)break;
     }
     
}

