/* Ty Massaquoi
    Lab 4
    February 9, 2024

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int size=0;

	while(head!=NULL){
		size++;
		head=head->next;
	}
	return size;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function il return "abc"
char* toCString(node* head)
{
	int temp=length(head);
	char*ptr=malloc((temp+1)*sizeof(char));
	 int i=0;

	 while (head!=NULL){
		ptr[i]=head->letter;
		head=head->next;
		i++;
	 }
	 ptr[temp]='\0';
	 return ptr;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
node*newNode=(node*)malloc(sizeof(node));
newNode->letter=c;
newNode->next=NULL;

if(*pHead==NULL){
	*pHead=newNode;
}else{
	node*temp= *pHead;

	while(temp->next !=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
}

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node*ptr= *pHead;
	while(ptr!=NULL){
		node*temp=ptr;
		ptr=ptr->next;
	}
	*pHead=NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
