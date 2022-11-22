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

void insert(struct node*root,int key)
{
       struct node *prev=NULL;
       while(root!=NULL)
       {
              prev=root;
              if(key==root->data)
              {
                printf("cannotinset%d,alreadyinBST",key);
                  return;   
              }
              else if(key<root->data)
              {
                     root=root->left;
              }

              else
              {
                     root=root->right;
              }
       }

       struct node* new=createNode(key);
       if(key<prev->data)
       {
              prev->left=new;
       }
       else
       {
              prev->right=new;
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


struct node* inOrderPredecessor(struct node* root)
{
       root=root->left;
       while(root->right!=NULL)
       {
              root=root->right;
       }
       return root;
}
struct node *deleteNode(struct node *root,int value)
{
     struct node* iPre;
      if(root==NULL)
      {
       return NULL;
      }
      if(root->left==NULL && root->right==NULL)
      {
       free(root);
       return NULL;
      }
       //search for the nodeto be deleted
       if(value<root->data)
       {
              root->left=deleteNode(root->left,value);
       }
       else if(value>root->data)
       {
              root->right=deleteNode(root->right,value);
       }
       //deletion strategy when the node is found
       else
       {
              iPre=inOrderPredecessor(root);
              root->data=iPre->data;
             root->left= deleteNode(root->left,iPre->data);
       }
       return root;
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
            /  \  /
            2   7 8
       */

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    
    inOrder(p);
    deleteNode(p,1);
    printf("\n");
    
    inOrder(p);
    return 0;   
}