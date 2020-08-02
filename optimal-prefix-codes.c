#include<stdio.h>
#include<string.h>
#define MAX 100
int size=0;
struct node
{
    char c;
    int f;
    struct node *l,*r,*next;
};
struct node* createnode(char c)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->c=c;
    new_node->f=1;
    new_node->l=new_node->r=NULL;
    new_node->next=NULL;
    return new_node;
};
void main()
{
    char str[100];
    printf("enter the statement:");
    gets(str);
    struct node* root;
    root=createnode(str[0]);
    size++;
    for(int i=1;i<strlen(str);i++)
    {
        int k=0,j=1;
        struct node* temp=root;
        while(j<=i)
        {
            if(temp==NULL)
                break;
            else if(str[i]==temp->c)
              {
                (temp->f)++;
                k=1;
                break;
              }

              else
              {
                temp=temp->next;
                j++;
              }
        }
        if(k!=1)
        {
            size++;
            struct node* t=createnode(str[i]);
            t->next=root;
            root=t;
        }
    }
    bubblesort(root);
    create_prefix_code(root);
}
struct node* createnode1(int d)
{
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        new_node->f=d;
        new_node->l=new_node->r=NULL;
        return new_node;
}
void create_prefix_code(struct node* root)
{
    int sum,j=1;
    while(j<size)
    {
        sum=root->f +root->next->f;
        struct node *temp=createnode1(sum);
        temp->next=root->next->next;
        temp->l=root;
        temp->r=root->next;
        root=temp;
        if(j!=size-1)
        {
            struct node* t=root->next;
            struct node* t1=root;
            if(temp->f <= t->f)
            {
                j++;
            }
            else
            {
                int k;
                for(k=j+1;k<=size;k++)
                {
                    if(k==size)
                    {
                        struct node* t2=root->next;
                        t1->next=temp;
                        root=t2;
                        break;
                    }
                    else if(temp->f<=t->f)
                    {
                    struct node* t2=root->next;
                    t1->next=root;
                    temp->next=t;
                    root=t2;
                    break;
                    }
                    else
                    {
                    t1=t1->next;
                    t=t->next;
                    }
                }
                j++;
            }
        }
        else
            {
               j++;
            }
    }
    int arr[100],t=0;
    printf("prefix code for each character in statement : \n");
    printcode(root,arr,t);
}
void bubblesort(struct node *root)
{
    int s;
    struct node *p;
    struct node *lp=NULL;
    if (root==NULL)
        return;
    do
    {
        s=0;
        p=root;
        while (p->next!=lp)
        {
            if (p->f>p->next->f)
            {
                swap(p,p->next);
                s=1;
            }
            p=p->next;
        }
        lp=p;
    }
    while(s);
}
void swap(struct node *a,struct node *b)
{
    int temp=a->f;
    a->f=b->f;
    b->f=temp;
    char c=a->c;
    a->c=b->c;
    b->c=c;
}
void printcode(struct node* root,int arr[],int top)
{
    if(root->l)
    {
        arr[top] = 0;
        printcode(root->l,arr,top+1);
    }
    if(root->r)
    {
        arr[top] = 1;
        printcode(root->r,arr,top+1);
    }
    if(Leafnode(root))
    {
        printf("%c-%d: ",root->c, root->f);
        printbits(arr,top);
    }
}
int Leafnode(struct node* root)
{
    return !(root->l)&&!(root->r);
}
void printbits(int arr[],int n)
{
    int i;
    for (i=0;i<n;++i)
        printf("%d", arr[i]);
    printf("\n");
}

