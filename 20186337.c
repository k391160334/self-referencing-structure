#include <stdio.h>
#include <stdlib.h>
struct node {
	int value;
	struct node *next;
};
struct node *getValue();
int printlist(struct node*Head);
void printHalf(struct node*head, int count);
void printReverse(struct node*head, int count);
void printRemoveOdd(struct node*head, int count);

int main() {

	struct node*head = NULL;
	head = getValue(head);
	int count = printlist(head);           //입력자료를 입력 순으로 출력
	printf("\n");
	printf("%d", count);                   //입력된 자료의 개수를 출력
	printf("\n");
	printHalf(head, count);                //중간의 값 출력
	printf("\n");
	printReverse(head, count);             //거꾸로 출력
	printf("\n");
	printRemoveOdd(head, count);           //홀수 삭제 출력
	printf("\n");
}
struct node *getValue() {
	struct node *p = (struct node*)malloc(sizeof(struct node));
	struct node *prevP;
	struct node *head = p;
	prevP = head;
	int tempValue;
	while(1) {
		scanf("%d", &tempValue);
		if (tempValue == EOF) {
			prevP->next = NULL;
			free(p);
			break;
		}
		else {
			p->value = tempValue;
			p->next = (struct node*)malloc(sizeof(struct node));
			prevP = p;
			p = p->next;
		}
	}
	return head;
}

int printlist(struct node*Head) {
	struct node*p=Head;
	int count = 0;
	while(1) {
		printf("%d", p->value);
		count++;
		p = p->next;
		if (p == NULL) break;
		else printf(" ");
	}
	return count;
}
void printHalf(struct node*head,int count) {
	struct node*p = head;
	for (int i = 0; i < count / 2; i++) {
		p = p->next;
	}
	printf("%d", p->value);
}
void printReverse(struct node*head, int count) {
	struct node*p = head;
	int* valueRev = (int *)malloc(sizeof(int)*count);
	for (int i = count - 1; i >= 0; i--) {
		valueRev[i] = p->value;
		if(i>0) p = p->next;
	}
	for (int i = 0; i < count; i++) {
		printf("%d", valueRev[i]);
		printf(" ");
	}
}
void printRemoveOdd(struct node*head, int count) {
	head = head->next;
	struct node*p = head;
	for (int i = 0; i < ((int)count / 2) - 1; i++) {
		p->next = p->next->next;
		p = p->next;
	}
	if(count/2) p->next = NULL;
	
	p = head;
	while (1) {
		printf("%d", p->value);
		printf(" ");
		if (p->next != NULL) p = p->next;
		else break;
	}
}