#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"
void window()
{
	printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *");
	printf("\n\n\t1:学   生   管   理   信   息   系   统\n");
	printf("\n\t2:课   程    管   理   信   息   系   统\n");
	printf("*   *   *   *   *   *   *   *    *   *   *   *   *   *   *\n");

}



int main()
{
        
	int n;
        system("clear");
        window();
	printf("请输入你的选择(1-2)(按3结束):");
	scanf("%d",&n);
	getchar();
	while(1)
	{
		switch(n)
		{
			case 1:{
                                       system("clear");
				       student();
                                       window();
				       printf("请重新输入你的选择(1-2)(按3结束):");
                                       scanf("%d",&n);
	                               getchar();
                                       break;
			        }
			case 2:{
                                       system("clear");
				       class();
                                       window();
				       printf("请重新输入你的选择(1-2)(按3结束):");
                                       scanf("%d",&n);
	                               getchar();
                                       break;
			       }
			case 3:{system("clear");exit(1);}
			default:{
                                printf("选择有误,请重新输入:");
                                scanf("%d",&n);
                                getchar();
                                }
		}
                  
	}
}

