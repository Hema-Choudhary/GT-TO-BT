#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include"gt_s.c"
#include"bt_s.c"
#include"gt_h.c"
#define ERROR fprintf(stdout,"\nERROR IN THE PATH!");
#define D_ERROR fprintf(stdout,"\n ELEMENT DOES NOT EXIST");
#include"gt_f.c"

int main(void)
{
 int val,op,*path,plen,*bfs,i,cnt=0;
 char  buff[100],*tk;
 gt *(*childs);
 do
 {
 fprintf(stdout,"\n\n1)INSERT\n2)DELETE ALL\n3)DELETE\n4)BFS\n5)GT to BT\nEnter option: ");
 fscanf(stdin,"%d",&op);
 switch(op)
 {
 
 case 1: 
         create();
         if(root!=NULL)
          {
          fprintf(stdout,"\nELEMENTS :");
          display(root);
          }
          break;
case 2:  
         if(root!=NULL)
          {
          printf("\nDEL VAL");
          scanf("%d",&val);
          if(val==root->e)
           root=NULL;
          else
           del(root,val);
          }
         else
          fprintf(stdout,"\nNo element to Delete");
         if(root!=NULL)
         {
          fprintf(stdout,"\nELEMENTS :");
          display(root);
         }
         break;
case 3:   
         if(root!=NULL)
         {
         plen=0;
         path=(int*)malloc((unsigned int)sizeof(int)*(unsigned int)1);
         fprintf(stdout,"\nEnter the DEL VAL:");
         fscanf(stdin,"%d",&val);
         if(root->cnt==0)
          path[0]=-1;
         else
         {
           fprintf(stdout,"\nEnter path: ");
           fscanf(stdin,"%s",buff);
           tk=strtok(buff,"/");
 
           while(tk)
           {
             path=(int *)realloc(path,(unsigned int)sizeof(int)*(unsigned int)(plen+1));
             path[plen++]=atoi(tk);
             tk=strtok(NULL,"/");
           }
          path[plen]=-1;
          }
          delete(root,val,path,1); 
          path=(int *)realloc(path,(unsigned int)sizeof(int)*(unsigned int)0);
          }
          else
           fprintf(stdout,"\nCannot Delete");   
          if(root!=NULL)
           display(root);
          
           break;      
case 4: 
        if(root!=NULL)
         {
         cnt=0;
         childs=malloc((unsigned int)sizeof(gt *)*(unsigned int)0);
         bfs=(int *)malloc((unsigned int)sizeof(int)*(unsigned int)0);   
         bfs_t(root,childs,&bfs,0,&cnt,0);
         fprintf(stdout,"\n");
         for(i=0;i<cnt;i++)
         {
          fprintf(stdout,"\t %d",bfs[i]);
         }       
         }break;  
         
case 5:
       if(root!=NULL)
       {
        make_BT(root,broot);
        fprintf(stdout,"\nBT :");
        BT_disp(broot);       
       }
       else
       fprintf(stdout,"\n GT DOES NOT EXIST!");         
  }
 }while(op<=5);
return 0;
}
