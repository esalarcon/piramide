#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MOD_RESTA(X,Y) ((X)>(Y))?((X)-(Y)):((Y)-(X))

double get_process_time(void);
void imprimir_piramide(char d[]); 
void base_piramide(char d[]);
void resolver_piramide(char d[]);
int piramide_OK(char d[]);

int main(void)
{
   char piramide[16];
   double start_t, end_t;
   long intentos = 15L*15L*15L*15L*15L;
   long i; 
   long oks = 0L;

   start_t = get_process_time();
   for(i=0;i<intentos;i++)
   {
         memset(piramide,0,sizeof(piramide));
         base_piramide(piramide);
         resolver_piramide(piramide); 
         if(piramide_OK(piramide))
         {
            imprimir_piramide(piramide);
            oks++;
         }
   }
   end_t = get_process_time();
   printf("\n%ld resueltos de %ld (%0.03f s)\n",oks,i,end_t-start_t);
   return EXIT_SUCCESS;
}

double get_process_time(void) 
{
	clock_t uptime = clock() / (CLOCKS_PER_SEC / 1000);
   return ((double)uptime)/1000.0;
}

void imprimir_piramide(char d[])
{
   printf("\n");
   printf("        %02d\n",d[14]);
   printf("      %02d  %02d\n",d[12],d[13]);   
   printf("    %02d  %02d  %02d\n",d[9],d[10],d[11]);
   printf("  %02d  %02d  %02d  %02d\n",d[5],d[6],d[7],d[8]);   
   printf("%02d  %02d  %02d  %02d  %02d\n",d[0],d[1],d[2],d[3],d[4]);
} 

void resolver_piramide(char d[])
{
   d[5]  = MOD_RESTA(d[0],d[1]);
   d[6]  = MOD_RESTA(d[1],d[2]);
   d[7]  = MOD_RESTA(d[2],d[3]);  
   d[8]  = MOD_RESTA(d[3],d[4]);  
   d[9]  = MOD_RESTA(d[5],d[6]);  
   d[10] = MOD_RESTA(d[6],d[7]); 
   d[11] = MOD_RESTA(d[7],d[8]); 
   d[12] = MOD_RESTA(d[9],d[10]); 
   d[13] = MOD_RESTA(d[10],d[11]); 
   d[14] = MOD_RESTA(d[12],d[13]);
}

void base_piramide(char d[])
{
   static char i=1, j=1, k=1, l=1, m=1;
   d[0]=i;
   d[1]=j;
   d[2]=k;
   d[3]=l;
   d[4]=m;
   if(++m>15)
   {
      m=1;
      if(++l>15)
      {
         l=1;
         if(++k>15)
         {
            k=1;
            if(++j>15)
            {
               j=1;
               if(++i>15)
               {
                  i=1;
               }
            }
         }
      }
   }
}

int piramide_OK(char d[])
{
   char v[16];
   int ret=0;
   int i=0;
   memset(v,0,sizeof(v));
   for(i=0;i<16;i++)
      if(!(v[d[i]&0x0F])) 
         v[d[i]&0x0F]++;
   for(i=0;i<16;i++) ret+=v[i];
   return (ret==16)?1:0;
}

