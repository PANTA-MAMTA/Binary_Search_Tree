#include<stdio.h>
#include<malloc.h>

struct node
{
       int data;
       struct node* left;
       struct node* right;
};

struct node* createNode(int data)
{
       struct node *n;
       n=(struct node *)malloc(sizeof(struct node));
       n->data=data;
       n->left=NULL;
       n->right=NULL;
       return n;
}

void inOrder(struct node* root)
{
       if(root!=NULL)
       {
              inOrder(root->left);
              printf("%d  ",root->data);
              inOrder(root->right);
              

       }
}

int isBST(struct node* root)
{
       static struct node *prev=NULL;
       if(root!=NULL)
       {
              if(!isBST(root->left))
              {
                     return 0;
              }
              if(prev!=NULL && root->data>=prev->data)
              { 
                     return 0;
              }
              prev=root;
              return isBST(root->right);

       }
       else
       {
              return 1;
       }
}

struct node* search(struct node* root, int key)
{
       if(root==NULL)
       {
              return NULL;
       }

       if(key==root->data)
       {
              return root;
       }
       else if(key<root->data)
       {
              return search(root->left, key);
       }
       else{
              return search(root->right, key);
       }
}

int main()
{

       struct node *p=createNode(9);
       struct node *p1=createNode(6);
       struct node *p2=createNode(10);
       struct node *p3=createNode(2);
       struct node *p4=createNode(7);
       struct node *p5=createNode(8);

       /*
       tree looks like this:
              9
             /  \   
             6   10
            /  \   /
           2    7  8
       */

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    
  struct node* n= search(p, 7);
  if(n!=NULL){
  printf("found:%d",n->data);
  }
  else
  {
  printf("element not found");
  }
    return 0;   
}