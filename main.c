#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

int list[MAX],n,cdr;

void display()
{
	int i;
	printf("\n====================================\nProcesses -->");
	for(i=1;i<=n;i++)
		printf("\t %d",i);
	printf("\nAlive     -->");
	for(i=1;i<=n;i++)
		printf("\t %d",list[i]);
	printf("\n====================================");
	printf("\nThe leader is :%d\n====================================",cdr);
}

void ring()
{
	int msg[20],ring_n,k,i;
	int ch,crash,activate,gid,flag,subcdr;
	do
	{
			printf("\n====================================\n1.Crash\n2.Activate\n3.Display\n4.Exit\nEnter :");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\n====================================\nEnter process no. to crash :");
					scanf("%d",&crash);
					if(list[crash])
						list[crash]=0;
					else
					{
						printf("\nProcess is alreaady dead!!");
						break;
					}
					do
					{
						printf("\nEnter election generator id :");
						scanf("%d",&gid);
						if(gid==cdr)
						{
							printf("\nEnter a valid generator id :");
						}
					} while(gid==crash);
					flag=0;
					k=1;
					if(crash==cdr)
					{
						msg[k++]=gid;
						printf("====================================");
						for(i=(gid+1)%n;i!=gid;i=(i+1)%n)
						{
							if(list[i])
							{
								printf("\nmessage is sent to %d k =%d",i,k);
								msg[k++]=i;
							}
						}
						subcdr=0;
						printf("\n====================================");
						for(i=1;i<k;i++)
						{
							printf("\nmsg::%d",msg[i]);
							if(subcdr<msg[i])
							{
								subcdr=msg[i];
							}
						}
						cdr=subcdr;
					}
					display();
					break;
				case 2:
					//activate
					printf("\n====================================\nEnter process no. to activated :");
					scanf("%d",&activate);
					if(!list[activate])
						list[activate]=1;
						else
					{
						printf("\nProcess is already active!!");
						break;
					}				
					//
					if(activate==n)
					{
						cdr=n;
						break;
					}
					printf("====================================");
					for(i=activate+1;i<=n;i++)
					{
						printf("\nMessage is sent from %d to %d",activate,i);
						if(list[i])
						{
							subcdr=i;
							printf("\nResponse is sent from %d to %d",i,activate);
							flag=1;
						}
					}
					if(flag==1)
					{
						cdr=subcdr;
					}
					else
					{
						cdr=activate;
					}

				display();
					//
				break;
			case 3:
				display();
			break;
			case 4:
				break;
			}
	} while(ch!=4);
}

int main()
{
	int i,j;
	printf("\nEnter no. of process :");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nIs Process %d active or not (0/1) :",i);
		scanf("%d",&list[i]);
		if(list[i])
			cdr=i;
	}
	display();
	do
	{
		printf("\n1.Ring algorithm\n2.Display\n3.Exit\nEnter :");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				ring();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(1);
		}
	} while(j!=3);
	return 0;
}