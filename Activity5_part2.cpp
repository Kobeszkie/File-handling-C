#include<toolbox.h>

//FUNCTION DECLARATION
void menu_option();
void new_file();
void add_record();
void display_option();
void exit_option();

//FILE DECLARATION
FILE *fptr;

char stud_no[20], ln[20], ln1[20], fn[20], mi[10], prog_code=' ';
int x, y, item_no, page_no, acct, comp, business, others, total;


void home_option(){
	
	printxy(6,2,"Main Screen");//letter
	line2(15,5,100,26); //Outer_Box
	
	line1(20,6,95,10);//taskbar
	printxy(40,7,"Polythecnic University of the Phils.");//name_taskbar
	printxy(49,8,"San Juan Campus");//name_taskbar
	printxy(50,9,"San Juan City");//name_taskbar
	
	line1(20,11,55,25);//leftbox
	line1(60,11,95,25);//rightbox
	
	line1(25,12,50,14);//inside_leftbox
	printxy(34,13,"Main Menu");//inside_leftbox_letter
	
	printxy(25,16,"A]Create a new file");//choice_A
	printxy(25,18,"B]Add a record");//choice_B
	printxy(25,20,"C]Browse");//choice_C
	printxy(25,22,"D]Close");//choice_D
	printxy(30,24,"Select an option:");//choice_D
	
	line1(15,27,100,29);//second_outer_box
	
	menu_option();
}

void menu_option(){
	
	//TYPING OPTIONS
	gotoxy(48,24);
	char option;
	switch(option=tolower(getche()))
	{
		case 'a':
			clearportion(16,28,99,28);
			printxy(50,28,"Creating New File");Sleep(500);
			clearportion(16,28,99,28);
			new_file();
			break;
		case 'b':
			clearportion(16,28,99,28);
			printxy(47,28,"Adding a new record");Sleep(500);
			clearportion(16,28,99,28);
			add_record();
			break;
		case 'c':
			clearportion(16,28,99,28);
			printxy(50,28,"Displaying Data");Sleep(700);
			clearportion(16,28,99,28);
			display_option();
			break;
		case 'd':
			clearportion(16,28,99,28);
			printxy(45,28,"Exiting the Program");Sleep(500);
			break;
		default:
			clearportion(16,28,99,28);
			printxy(45,28,"Invalid Input");Sleep(500);
			clearportion(16,28,99,28);
			menu_option();
			break;
	}
}

void new_file()
{
	printxy(24,28,"!!!WARNING!!! This will erase the contents of the file. Proceed?[Y/N]");
	gotoxy(94,28);
	char option;
	switch(option=tolower(getche()))
	{
		case 'y':
			clearportion(16,28,99,28);
			gotoxy(41,28);printxy(40,28,"A new file has been created, press any key");
			fptr=fopen("Text.txt", "w");
			fclose(fptr);
			getch();
			clearportion(16,28,99,28);
			menu_option();
			break;
		case 'n':
			clearportion(16,28,99,28);
			menu_option();
			break;
		default:
			clearportion(16,28,99,28);
			center(32,"Invalid Input");Sleep(500);
			break;
	}	
}


void add_record()
{
	//RIGHT BOX
	fptr=fopen("Text.txt", "a");

	clearportion(61,12,94,24);
	printxy(63,14,"Student number:");//inside_rightbox_options
	printxy(63,16,"last name:");//inside_rightbox_options
	printxy(63,18,"First Name:");//inside_rightbox_options
	printxy(63,20,"M.I:");//inside_rightbox_options
	printxy(63,22,"Program Code:");//inside_rightbox_options
	clearportion(80,14,94,22);
	//INPUTING DATA
	gotoxy(80,14);
	scanf("\n");gets(stud_no);
	gotoxy(80,16);gets(ln);
	gotoxy(80,18);gets(fn);
	gotoxy(80,20);gets(mi);
	gotoxy(80,22);scanf("%c", &prog_code);
	prog_code=tolower(prog_code);
	fprintf(fptr,"%s %s, %s %s. %c\n", stud_no, ln, fn, mi, prog_code);
	fclose(fptr);
	clearportion(16,28,99,28);
	home_option();
}

void display_option()
{	
	int x, y=0, item_no=0, page_no=1, acct=0, comp=0, business=0, others=0, total=0, value=3;
	system("cls");
	printxy(35,1,"Polythecnic University of the Phils.");//name_taskbar
	printxy(44,2,"San Juan Campus");//name_taskbar
	printxy(45,3,"San Juan City");//name_taskbar	
	printxy(2,5,"Page:");//letter	
	printxy(15,7,"#\tStudent\t\t#\tStudent name\t\t#\tProgram");//letter
	printxy(10,8,"===================================================================================");	
	fptr=fopen("Text.txt", "r");
	while(fscanf(fptr,"%s %s %s %s %c", stud_no, ln, fn, mi, &prog_code)!=EOF)
	{
		if(y >= value)
		{	
			getche();
			y=0;
			page_no++;
			clearportion(15,9,106,12);
		}
		gotoxy(7,5);printf("%d", page_no);
		item_no++;
		y++;
		gotoxy(15,9+y);printf("%d",item_no);
		gotoxy(26,9+y);printf("%s",stud_no);
		gotoxy(47,9+y);printf("%s %s %s",fn,mi,ln);
		
		switch(prog_code)
		{
			case 'a':	
				gotoxy(78,9+y);printf("Accounting");
				acct++;
				break;
			case 'b':
				gotoxy(78,9+y);printf("Business");
				business++;
				break;
			case 'c':
				gotoxy(78,9+y);printf("Computer");
				comp++;
				break;
			default:
				gotoxy(78,9+y);printf("Other Courses");
				others++;
				break;
		}
	}	
	total = acct + comp + business + others;
	gotoxy(2,15);printf("Total number of students: %d", total);
	gotoxy(7,16);printf("Accounting Students: %d", acct);
	gotoxy(9,17);printf("Business Students: %d", business);
	gotoxy(9,18);printf("Computer Students: %d", comp);
	gotoxy(4,19);printf("Other Courses Students: %d", others);
	gotoxy(4,22);printf("press any key...........");
	
	getche();
	system("cls");
	printxy(73,16,"Programmed");//inside_rightbox_letter
	printxy(77,18,"By:");//inside_rightbox_letter
	printxy(71,20,"KOBE E. FAJARDO");//inside_rightbox_letter
	home_option();
}

void exit_option(){
	
	clearportion(61,12,94,24);
	printxy(74,16,"THANKYOU");//inside_rightbox_letter
	printxy(77,18,"FOR");//inside_rightbox_letter
	printxy(71,20,"USING THIS CODE");//inside_rightbox_letter
}

main(){
	
	printxy(73,16,"Programmed");//inside_rightbox_letter
	printxy(77,18,"By:");//inside_rightbox_letter
	printxy(71,20,"KOBE E. FAJARDO");//inside_rightbox_letter
	home_option();
}