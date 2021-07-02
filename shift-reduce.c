#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z = 0, i = 0, j = 0, c = 0,st=0;

char a[16], ac[20], stk[15], act[10],temp[3],st1[15]; 
 
void check()
{
    while(1)
    {

          if(stk[st] == 'S'&& a[j+1]!='\0' && stk[st-1]!=',') 

          {

                  printf("\t   REDUCE TO L->S");

                  stk[st] = 'L';

                  stk[st+1] = '\0';

                  printf("\n$%s\t%s$\t", stk, a); 

          }

          else if(stk[st-2] == 'L' && stk[st-1] == ',' && stk[st] == 'S')
          {

                  printf("\t   REDUCEL->L,S");

                  stk[st-2]='L';

                  stk[st-1]='\0';

                  st=st-2;

                  printf("\n$%s\t%s$\t", stk, a);

          }    

          else if(stk[st] == 'a') 

          {

                    printf("\t   REDUCE TO S->a");

                    stk[st] = 'S';

                    stk[st + 1] = '\0';


                    printf("\n$%s\t%s$\t", stk, a); 

          }
          else if(stk[st-2] == '(' && stk[st-1] == 'L' && stk[st] == ')')
          {
                    printf("\t   REDUCE TO S->(L)");

                    stk[st-2] = 'S';

                    stk[st-1] = '\0';

                    st=st-2;

                    printf("\n$%s\t%s$\t", stk, a);
          }
          if(stk[0] == 'S' && stk[1] == '\0' && j==c)
          {

                  printf("\t   Accept\n");
                  exit(0);
          }
          if(!strcmp(st1,stk))
                  return;
          strcpy(st1,stk);

    }
}

int main()
{

    printf("GRAMMAR is -\nS->(L) | a \nL->L,S | S \n"); 
  
    printf("Enter a string:");
    
    gets(a);

    c=strlen(a); 

    strcpy(act,"SHIFT "); 

     
    printf("\nstack \t input \t\t    action\n------------------------------------------------"); 


    printf("\n$\t%s$\t", a); 


    for(j = 0; j < c; j++) 

    {

          temp[0] = a[j];     

          temp[1] = '\0';
      
          strcat(act,temp);
      
          printf("\t   %s", act);

          stk[st] = a[j];     

          stk[st+1] = '\0';

          a[j]=' ';

          printf("\n$%s\t%s$\t", stk, a); 

          check(); 
      
          st++;
      
          strcpy(act,"SHIFT ");
      
          strcpy(st1,stk);

    }
 
    st++;
  
    check(); 

    printf("\t   Reject\n");
}
