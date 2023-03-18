#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;


NODE insert(int,NODE);
void traverse(NODE);
void search(NODE);
NODE getnode();
void in(NODE);
void pre(NODE);
void post(NODE);

void main(){
    NODE root=NULL;
    int ch,n,item;
    while(1){
        printf("\n------------------MENU----------------\n");
        printf("1.create tree\n");
        printf("2.traverse\n");
        printf("3.search\n");
        printf("4.exit\n");
        printf("------------------------------------------\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{printf("enter the number of elemnts\n");
            scanf("%d",&n);
            while(n>0){
                printf("enter the element : ");
                scanf("%d",&item);
                root=insert(item , root);
                n--;
            }
            }
            break;
            case 2:traverse(root);break;
            case 3:search(root);break;
            case 4:return;
            default:printf("invalid choice");
        }
    }
}

NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE insert(int item,NODE root){
    NODE cur,prev,temp;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(root==NULL){
        root=temp;
        return root;
    }
    else{
        prev=NULL;
        cur=root;
        while(cur!=NULL){
            prev=cur;
            cur=(temp->info>cur->info)?cur->rlink:cur->llink;
        }
        if(temp->info<prev->info)
            prev->llink=temp;
        else
            prev->rlink=temp;
    }
    return root;

}
void in(NODE IN){
    if(IN!=NULL){
        in(IN->llink);
        printf("%d\t",IN->info);
        in(IN->rlink);
    }

}

void pre(NODE PRE){
    if(PRE!=NULL){
        
        printf("%d\t",PRE->info);
        pre(PRE->llink);
        pre(PRE->rlink);
    }

}


void post(NODE POST){
    if(POST!=NULL){
        post(POST->llink);
        post(POST->rlink);
        printf("%d\t",POST->info);
        
    }

}
void traverse(NODE root){
    NODE IN,POST,PRE;
    IN=root;
    POST=root;
    PRE=root;
    printf("\ntraversing the tree.....\n");
    printf("\ninorder : \t");
    in(IN);
    printf("\npreorder : \t");
    pre(PRE);
    printf("\npostorder : \t");
    post(POST);

}



void search(NODE root){
    int flag,key;
    printf("enter the element to be searched\n");
    scanf("%d",&key);
    NODE cur=root;
    while(cur!=NULL){
        if(cur->info==key){
            flag=1;
            printf("key element found ....!!!");   
            break; 
        }
        else{
            if(key<cur->info){
                cur=cur->llink;
            }
            else{
                cur=cur->rlink;
            }
        }
    }
    if(flag==0){
        printf("key element is not found..!!!\n search the element which is in tree...!!!");
    }
}
