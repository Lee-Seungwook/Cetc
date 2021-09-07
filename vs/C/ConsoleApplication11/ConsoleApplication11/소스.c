#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct phone {
	char name[30];
	char year[5];
	char number[15];
};
void print_menu();
void view_phone();
void add_phone();
void delete_phone();
char *fname = "c:\\hkd\\phone.txt";;
int main() {
	char select = 0;
	puts("Phone Book Manager\n");
	while (select != 4) {
		print_menu();
		select = getche();
		switch (select) {
		case '1': view_phone(); break;
		case '2': add_phone(); break;
		case '3': delete_phone(); break;
		case '4': return 0; break;
		dafault: printf("\n Invalid option\n");
		}
	}
	system("pause");
	return 0;
}
void print_menu() {
	printf("\n");
	printf("1. View phone book \n");
	printf("2. Add phone number \n");
	printf("3. Delete phone number \n");
	printf("4. Quit \n");
}

void view_phone() {
	char line[80] = "";
	FILE *fp1, *fp2;
	int i;

	fp1 = fopen(fname, "r");

	if (fp1 == NULL) {
		fp2 = fopen(fname, "w");
		fclose(fp2);
		fp1 = fopen(fname, "r");
	}

	for (i = 1; ; i++) {
		fgets(line, 80, fp1);
		if (feof(fp1)) break;
		printf("\n%2d: %s", i, line);
	}

	if (i == 1) puts("\n Empty phone book\n");
	fclose(fp1);
}

void add_phone() {
	struct phone pn = { "", "", "" };
	char line[80] = "";
	FILE *fp;

	fp = fopen(fname, "a");
	printf("\nEnter name: ");
	scanf("%s", &pn.name);
	printf("\nEnter School year: ");
	scanf("%s", &pn.year);
	printf("\nEnter phone number: ");
	scanf("%s", &pn.number);
	printf("\n");

	strcat(line, pn.name);
	strcat(line, "\t");
	strcat(line, pn.year);
	strcat(line, "\t");
	strcat(line, pn.number);
	strcat(line, "\n");

	fputs(line, fp);
	fclose(fp);
}
void delete_phone() {
	char tempBuffer[30][80] = { "", };
	char line[80] = "";
	FILE *fp1, *fp2;
	int del_line, i, count = 0;
	fp1 = fopen(fname, "r");
	if (fp1 == NULL) {
		puts("\n No phone book file\n");
		exit(0);
	}
	printf("\nEnter number to delete: ");
	scanf("%d", &del_line);
	printf("\n");
	for (i = 0; i < 30; i++) {
		strcpy(line, "");
		fgets(line, 80, fp1);
		if (i + 1 != del_line) {
			strcpy(tempBuffer[i], line);
			count++;
		}
		else
			printf("Entry number %d is deleted \n", del_line);
		if (feof(fp1)) break;
	}
	fclose(fp1);
	fp2 = fopen(fname, "w");
	for (i = 0; i < count; i++)
		fputs(tempBuffer[i], fp2);
	fclose(fp2);
}
void search_name() {
	char line[80] = "";
	char name[30];
	FILE *fp1, *fp2;
	int i;

	printf("\Enter name to search : ");
	scanf("%s", name);

	fp1 = fopen(fname, "r");

	if (fp1 == NULL) {
		fp2 - fopen(fname, "w");
		fclose(fp2);
		fp1 = fopen(fname, "r");
	}

	printf("Search Name and phone Number\n");
	for (i = 1; ; i++) {
		fgets(line, 80, fp1);
		if (feof(fp1)) break;
		if (strstr(line, name)) printf("\n%2d : %s", i, line);
	}
	if (i == 1) puts("\n No matching name in phone book\n");
	fclose(fp1);
}