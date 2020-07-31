#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num;
    char singer[20];
    char album[20];
    char name[20];
}MUSIC;

struct node
{
     int num;
    char singer[20];
    char album[20];
    char name[20];
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("insufficient memory\n");
        exit(0);
    }
    return x;
}



NODE insert_rear(MUSIC item,NODE first)
{
    NODE temp,cur;
    int c=0;
    temp=getnode();
    temp->num=item.num;
    strcpy(temp->singer,item.singer);
    strcpy(temp->name,item.name);
    strcpy(temp->album,item.album);
    if(first==NULL)
    {
      return temp;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    c=c+1;
    return first;
}

NODE delete_info(NODE first,int key)
{
    NODE cur,prev;
    int c=0;
    if(first==NULL)
    {
        printf("list is empty\n");
        return first;
    }
    if(key==first->num)
    {
      cur=first;
      first=first->link;
      printf("item deleted is %d\n",cur->num);
      free(cur);
      c=c-1;
      return first;
    }
    prev=NULL;
    cur=first;
    while(cur!=NULL)
    {
        if(key==cur->num)
           break;
        prev=cur;
        cur=cur->link;
    }
    if(cur==NULL)
    {
        printf("unsuccessful search");
        return first;
    }
    prev->link=cur->link;
    free(cur);
    c=c-1;
    return first;
}

void search(int key,NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }
    cur=first;
    while(cur!=NULL)
    {
        if(key==cur->num)
          break;
        cur=cur->link;
    }
    if(cur==NULL)
    {
        printf("search is unsuccessful");
        return;
    }
    printf("search is successful");
}

NODE insert_info(MUSIC item,NODE first,int key)
{
    NODE temp,prev,cur;
    int i;
    temp=getnode();
    temp->num=item.num;
    strcpy(temp->singer,item.singer);
    strcpy(temp->name,item.name);
    strcpy(temp->album,item.album);
    temp->link=NULL;
    if(first==NULL)
        return temp;
    prev=NULL;
    cur=first;
    for(i=0;i<key;i++)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    temp->link=cur;
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }
    printf("contents of Music player are\n");
    cur=first;
    while(cur!=NULL)
    {
        printf("\n SONG NUM:%d\n SINGER:%s\n NAME=%s\n ALBUM:%s\n",cur->num,cur->singer,cur->name,cur->album);
        cur=cur->link;
    }
    printf("\n");
}

int main()
{
    NODE first;
    int ch,key;
    first=NULL;
    MUSIC item;
    while(1)
    {
        printf("\nMusic player menu\n 1.insert to Queue\n 2.delete info\n 3.search\n 4.display\n 5.insert info\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {


            case 1:
            printf("enter the Music num:\n");
            scanf("%d",&item.num);
            printf("enter the Singer:\n");
            scanf("%s",item.singer);
            printf("enter the Name of song:\n");
            scanf("%s",item.name);
            printf("Enter the Album:\n");
            scanf("%s",&item.album);
            first=insert_rear(item,first);
            break;

            case 2:
            printf("enter the id ");
            scanf("%d",&key);
            first=delete_info(first,key);
            break;

            case 3:
            printf("enter the id\n");
            scanf("%d",&key);
            search(key,first);
            break;

            case 4:
            display(first);
            break;

            case 5:
            printf("enter the location");
            scanf("%d",&key);
             printf("enter the Music num:\n");
            scanf("%d",&item.num);
            printf("enter the Singer:\n");
            scanf("%s",item.singer);
            printf("enter the Name of song:\n");
            scanf("%s",item.name);
            printf("Enter the Album:\n");
            scanf("%s",item.album);

            first=insert_info(item,first,key);
            break;

            default:
            printf("invalid choice\n");
            exit(0);
        }
    }
    return 0;
}

