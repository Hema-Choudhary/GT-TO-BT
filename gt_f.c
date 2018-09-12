
void del(gt *r,int val)
{
 int i,j;
 for(i=0;i<r->cnt;i++)
  {
   if(r->ch[i]->e==val)
   {
    for(j=i;j<r->cnt;j++)
     {
      r->ch[j]=r->ch[j+1];
     }
     r->cnt--;
     r->ch=realloc(r->ch,(unsigned int)sizeof(gt *)*(unsigned int)r->cnt);
     i--;
   }
   else
   del(r->ch[i],val);
  }
}

void display(gt *r)
{
 int i;
 fprintf(stdout,"%d",r->e);
 for(i=0;i<r->cnt;i++)
  {
  fprintf(stdout," \t*"); 
  display(r->ch[i]);
  fprintf(stdout,"/");
  }
}

void create(void)
{
 int *path,plen=0;
 char *tk,buff[100];
 gt * new;
 path=(int *)malloc(sizeof(int)*0);
 new=(gt*)malloc(sizeof(gt));
 new->cnt=0;
 new->ch=malloc((unsigned int)sizeof(gt *)*(unsigned int)0);
 fprintf(stdout,"\nEnter the elment:");
 fscanf(stdin,"%d",&new->e);
 if(root!=NULL)
 {
  fprintf(stdout,"\nEnter the path:");
  fscanf(stdin,"%s",buff);
  tk=strtok(buff,"/");
 
  while(tk)
  {
   path=(int *)realloc(path,(unsigned int)sizeof(int)*(unsigned int)(plen+1));
   path[plen++]=atoi(tk);
   tk=strtok(NULL,"/");
  }
 }
 path[plen]=-1;
 insert(root,new,path,1);
 path=(int*)realloc(path,sizeof(int)*0);
}

void insert(gt *r,gt *new,int *path,int i)
{
 
 int j;
 if(i==1)
 {
  if(r==NULL)
  {
   if(path[0]==-1)
   {
    root=new;
    return;
   }
   else
   {
     ERROR;
     return;
   }
  }
  else
  {
   if(path[0]==-1)
   {
    ERROR;
    return;
   }
   else if(path[0]!=r->e)
   {
    ERROR;
    return;
   }
  }  
 }

  if(path[i]==-1)
  {
    for(j=0;j<r->cnt;j++)
    {
     if(r->ch[j]->e==new->e)
      break;
    }
    
    if(j==r->cnt)
    {
     r->cnt++;
     r->ch=realloc(r->ch,(unsigned int)sizeof(gt *)*(unsigned int)r->cnt);
     r->ch[r->cnt-1]=new;
    }
    else
     fprintf(stdout,"\nThe element already exists");
  }
  else
  {
    for(j=0;j<r->cnt;j++)
    {
     if(r->ch[j]->e==path[i])
     {
      i++;
      insert(r->ch[j],new,path,i);
      break;
     }
    }
    if(j==r->cnt)
    { 
     ERROR;
     return;  
    }
  }
}


void delete(gt *r,int val,int *path,int i)
{
 
 int k,j;
 if(i==1)
 {
  if(path[0]==-1)
  {
   if(root->e==val)
    {
    root=NULL;
    return;
    }
   else
    {
     ERROR;
     return;
    } 
  }
  else
  {
   if(root->e!=path[0])
   {
    ERROR;
    return;
   }
  }
 }
  for(j=0;j<r->cnt;j++)
  { 
   if(path[i]==-1)
   { 
    if(r->ch[j]->e==val)
    { 
     for(k=j;k<r->cnt-1;k++)
       {r->ch[k]=r->ch[k+1];}
     r->cnt--;
     r->ch=realloc(r->ch,(unsigned int)sizeof(gt *)*(unsigned int)r->cnt);
     return; 
    }
   }
   else
   {
    if(r->ch[j]->e==path[i])
     {
     i++;
     delete(r->ch[j],val,path,i);
     break;
     }
   }
  }
  if(r->cnt==j)
  {
   ERROR;
   return;
  }
}



void bfs_t(gt *r,gt *(*childs),int **bfs,int cnt1,int *cnt2,int k)
{
 int i;
 if(r==stop)
 {
  return;
 }
 if(r==root)
 {
  (*cnt2)++;
  *bfs=realloc(*bfs,(unsigned int)sizeof(int)*(unsigned int)(*cnt2));
  *bfs[(*cnt2)-1]=r->e;
  }
  for(i=0;i<r->cnt;i++)
  {
  cnt1++; (*cnt2)++;
  childs=realloc(childs,(unsigned int)sizeof(gt *)*(unsigned int)cnt1);
  *bfs=realloc(*bfs,(unsigned int)sizeof(int)*(unsigned int)(*cnt2));
  childs[cnt1-1]=r->ch[i];
  (*bfs)[(*cnt2)-1]=r->ch[i]->e;
  }
  childs=realloc(childs,(unsigned int)sizeof(gt *)*(unsigned int)cnt1+1);
  childs[cnt1]=stop;
 
 if(r!=root) 
   k++;
 bfs_t(childs[k],childs,bfs,cnt1,cnt2,k);
}


void make_BT(gt *g_root,bt *b_root)
{
 int i;
 bt *new,*temp,*new2;
 if(g_root==root)
 {
  b_root=(bt*)malloc(sizeof(bt));
  b_root->e=g_root->e;
  b_root->r=b_root->l=NULL;
  broot=b_root;
 }
 if(g_root->cnt!=0)
 {
  new=(bt*)malloc(sizeof(bt));
  new->e=g_root->ch[0]->e;
  new->r=new->l=NULL;
  b_root->l=new;
  
  temp=new;
  for(i=1;i<g_root->cnt;i++)
  {
   new2=(bt*)malloc(sizeof(bt));
   new2->e=g_root->ch[i]->e;
   new2->r=new2->l=NULL;
   temp->r=new2;
   temp=new2;
  }
  
  for(i=0,temp=new;i<g_root->cnt;i++,temp=temp->r)
  {
   make_BT(g_root->ch[i],temp);
  }
 }
}

void BT_disp(bt *r)
{
 if(r!=NULL)
 {
  fprintf(stdout,"\t%d",r->e);
  BT_disp(r->l);
  BT_disp(r->r); 
 }
}

