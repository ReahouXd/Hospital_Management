#include<iostream>
#include<conio.h>
#include "Headers\\design.h"
#include "Headers\\staff.h"
#include "Headers\\patient.h"
#include "Headers\\Surgical.h"

using namespace std;

void Loading();
void Login();
void MainMenu();
void Staff();
void Patient(); 
void Patient0_17Y();
void Patient17_45Y();
void Patient45Y_UP(); 
void SURGICAL();
void IncomeAndExpense();
void Invoice();
void ABOUTYUS();

int main()
{
	mkdir("Files"); 
	setcursor(false, 1); 
//	Loading();
//	
	Login();
	MainMenu(); 
	getch();
	return 0;
}

void Loading()
{
	cover();
	welcomeFtLoading();
}

void Login()
{
    int attempts = 3;
    cls();
	while(1)
	{
		setcursor(true, 1);
		char username[25];
		char pwd[30];
		cover();
		loginAcc();
		
		DrawRectangle(40, 11, 90, 19, 6);
		DrawRectangle(62, 21, 44, 1, 2);	
		gotoxy(68,22); foreColor(4);
		cout<<"Username : "; 
		DrawRectangle(62, 25, 44, 1, 2);
		gotoxy(68,26); foreColor(4);
		cout<<"Password : ";
		gotoxy(79,22); foreColor(4);
		while(true)
		{
			inputLetter(username);
			if(!strcmp(username, "\0"))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		gotoxy(79,26); foreColor(4);
		while(true)
		{
			hidePassword(pwd);
			if(!strcmp(pwd, "\0"))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		setcursor(false, 1);
		Clearloading();
		if(!strcmp(username, "admin") && !strcmp(pwd, "Group2"))
		{
			gotoxy(75,29); foreColor(2);
			cout<<"[ LOGIN SUCCESS ]";
			delay(500);
			char a = 219;
			int i;
			gotoxy(68,34); foreColor(2);
			for(i=0; i<30; i++)
			{
				cout<<a;
				delay(100);
			}
			delay(500);
			system("cls");
			MainMenu();
		}
		else
		{
			attempts--;
            if(attempts > 0) 
			{
				gotoxy(57,29); foreColor(4);
                cout<<"Incorrect username or password. You have "<<attempts<<" time to login"<<endl;
                delay(1000);
                system("cls");
            } 
			else 
			{
				gotoxy(63,29); foreColor(4);
                cout<<"You have run out of attempts. Login failed."<<endl;
                delay(1000);
                cls();
                cover();
    			thank();
	            delay(700);
	            cls();
	            cover();
	            byebye();
	            delay(700);
                exit(0);
            }
		}
	}
}

void MainMenu()
{
	int x = 0;
	char option;
	cls();
	cover();
	foreColor(1);
	ANT();
	BoxMenu();
	do
	{
		setcursor(false, 1);
		foreColor(6);
		gotoxy(81, 12);
		cout<<"STAFF";
		gotoxy(80, 14);
	    cout<<"PATIENT";
	    gotoxy(75, 16);
	    cout<<"INCOME AND EXPENSES";
	    gotoxy(80, 18);
	    cout<<"INVOICE";
	    gotoxy(80, 20);
	    cout<<"ABOUT US";
	    gotoxy(77, 22);
	    cout<<"LOGOUT PROGRAM";
	    gotoxy(78, 24);
	    cout<<"EXIT PROGRAM";
	    foreColor(9);
	    gotoxy(68, 27);
	    cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
		if(x == 0)
		{
			foreColor(4);gotoxy(81, 12);cout<<"STAFF";
		}
		if(x == 1)
		{
			foreColor(4);gotoxy(80, 14); cout<<"PATIENT";
		}
		if(x == 2)
		{
			foreColor(4);gotoxy(75, 16); cout<<"INCOME AND EXPENSES";
		}
		if(x == 3)
		{
			foreColor(4);gotoxy(80, 18); cout<<"INVOICE";
		}
		if(x == 4)
		{
			foreColor(4);gotoxy(80, 20); cout<<"ABOUT US";
		}
		if(x == 5)
		{
			foreColor(4);gotoxy(77, 22); cout<<"LOGOUT PROGRAM";
		}
		if(x == 6)
		{
			foreColor(4);gotoxy(78, 24); cout<<"EXIT PROGRAM";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					x--; 
					if(x < 0)
					{
						x = 6;
					}
					break;
				}
			case 80:
				{
					x++; 
					if(x > 6)
					{
						x = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(x)
		{
			case 0:
				{
					cls();
					Staff();
				}
				break;
			case 1:
				{
					cls();
					Patient(); 
					
				}
				break;
			case 2:
				{
					cls(); 
					IncomeAndExpense();
				}
				break;
			case 3:
				{
					cls();
					Invoice(); 
				}
				break;
			case 4:
				{
					cls();
					ABOUTYUS();
				}
				break;
			case 5:
				{
					cls();
					Login();
				}
				break;
			case 6:
				{
					cls();
	    			cover();
	    			thank();
	    			cls();
	    			cover();
	    			byebye();
	    			delay(1500);
	    			exit(0);
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
}

void Staff()
{	
	int y = 0;
	char option;
	cls();
	cover();
	BoxStaff();
	foreColor(2);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<" INSERT STAFF";
		gotoxy(76, 16); cout<<" VIEW STAFF";
		gotoxy(76, 19); cout<<" SEARCH STAFF";
		gotoxy(76, 22); cout<<" UPDATE STAFF";
		gotoxy(76, 25); cout<<" DELETE STAFF";
		gotoxy(76, 28); cout<<" BACK TO MENU";
		foreColor(9); gotoxy(68, 32); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<" INSERT STAFF";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<" VIEW STAFF";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<" SEARCH STAFF";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<" UPDATE STAFF";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<" DELETE STAFF";
		}
		if(y == 5)
		{
			foreColor(4); gotoxy(76, 28); cout<<" BACK TO MENU";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 5;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 5)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					InsertStaff();
					cls();
					cover();
					chooseInsert();
				}while(getch() != 27);
				Staff(); 
				break;
			case 1:
				cls();
				cover();
				styleView();
				ShowStaff();
				foreColor(2);
				cout<<"\n\n\n\n\t\t\t\t\t\t\t       <<<< Press Any Key back to [MENU STAFF] >>>>"<<endl;
				getch(); 
				Staff(); 
				break;
			case 2:
				{
					do{
						cls();
						cover();
						ShowStaff();
						SearchStaff(); 
						cls(); 
						cover();
						chooseSearch(); 
					}while(getch() != 27); 
					Staff(); 
				}
				break;
			case 3:
				{
					do{
						cls();
						cover();
						ShowStaff();
						UpdateStaff(); 
						cls(); 
						cover();
						chooseUpdate(); 
					}while(getch() != 27); 
					Staff(); 
				}
				break;
			case 4:
				{
					do{
						cls();
						cover();
						ShowStaff();
						DeleteStaff(); 
						cls(); 
						cover();
						chooseDelete(); 
					}while(getch() != 27); 
					Staff(); 
				}
				break;
			case 5:
				{
					cls();
					MainMenu();
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
			
}

void Patient()
{	
	int y = 0;
	char option;
	cls();
	cover();
	BoxPatient();
	foreColor(3);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<"PATIENT (0Y - 17Y)";
		gotoxy(76, 16); cout<<"PATIENT (18Y - 45Y)";
		gotoxy(76, 19); cout<<"PATIENT (46Y UP)";
		gotoxy(76, 22); cout<<"SURGICAL PATIENT";
		gotoxy(76, 25); cout<<"BACK TO MENU";
		foreColor(9); gotoxy(68, 29); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<"PATIENT (0Y - 17Y)";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<"PATIENT (18Y - 45Y)";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<"PATIENT (46Y UP)";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<"SURGICAL PATIENT";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<"BACK TO MENU";
		}
		
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 4;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 4)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				cls();
				Patient0_17Y(); 
				break;
			case 1:
				Patient17_45Y();
				break;
			case 2:
				Patient45Y_UP(); 
				break;
			case 3:
				SURGICAL();
				break;
			case 4:
				MainMenu(); 
				break;
			default:
				cls();
				break;
		}

	}while(1);
			
}

void Patient0_17Y()
{	
	int y = 0;
	char option;
	cls();
	cover();
	BoxPatient1();
	foreColor(4);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<" INSERT PATIENT";
		gotoxy(76, 16); cout<<" VIEW PATIENT";
		gotoxy(76, 19); cout<<" SEARCH PATIENT";
		gotoxy(76, 22); cout<<" UPDATE PATIENT";
		gotoxy(76, 25); cout<<" DELETE PATIENT";
		gotoxy(76, 28); cout<<" RETURN";
		foreColor(9); gotoxy(68, 32); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<" INSERT PATIENT";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<" VIEW PATIENT";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<" SEARCH PATIENT";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<" UPDATE PATIENT";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<" DELETE PATIENT";
		}
		if(y == 5)
		{
			foreColor(4); gotoxy(76, 28); cout<<" RETURN";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 5;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 5)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					InsertPatient("Files\\Patient0_17Y.bin", 1999, 0, 17);
					cls();
					cover();
					chooseInsert();
				}while(getch() != 27);
				Patient0_17Y(); 
				break;
			case 1:
				cls();
				cover();
				styleViewPt();
				ShowPatient("Files\\Patient0_17Y.bin");
				foreColor(2);
				cout<<"\n\n\n\n\t\t\t\t\t\t\t      <<<< Press Any Key back to [MENU PATIENT] >>>>"<<endl;
				getch(); 
				Patient0_17Y();
				break;
			case 2:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient0_17Y.bin");
						SearchPatient("Files\\Patient0_17Y.bin"); 
						cls(); 
						cover();
						chooseSearch(); 
					}while(getch() != 27); 
					Patient0_17Y();
				}
				break;
			case 3:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient0_17Y.bin");
						UpdatePatient("Files\\Patient0_17Y.bin", 0, 17); 
						cls(); 
						cover();
						chooseUpdate(); 
					}while(getch() != 27); 
					Patient0_17Y(); 
				}
				break;
			case 4:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient0_17Y.bin");
						DeletePatient("Files\\Patient0_17Y.bin"); 
						cls(); 
						cover();
						chooseDelete(); 
					}while(getch() != 27); 
					Patient0_17Y(); 
				}
				break;
			case 5:
				{
					cls();
					Patient(); 
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
}

void Patient17_45Y()
{	
	int y = 0;
	char option;
	cls();
	cover();
	BoxPatient1();
	foreColor(5);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<" INSERT PATIENT";
		gotoxy(76, 16); cout<<" VIEW PATIENT";
		gotoxy(76, 19); cout<<" SEARCH PATIENT";
		gotoxy(76, 22); cout<<" UPDATE PATIENT";
		gotoxy(76, 25); cout<<" DELETE PATIENT";
		gotoxy(76, 28); cout<<" RETURN";
		foreColor(9); gotoxy(68, 32); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<" INSERT PATIENT";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<" VIEW PATIENT";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<" SEARCH PATIENT";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<" UPDATE PATIENT";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<" DELETE PATIENT";
		}
		if(y == 5)
		{
			foreColor(4); gotoxy(76, 28); cout<<" RETURN";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 5;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 5)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					InsertPatient("Files\\Patient17_45Y.bin", 2999, 18, 45);
					cls();
					cover();
					chooseInsert();
				}while(getch() != 27);
				Patient17_45Y(); 
				break;
			case 1:
				cls();
				cover();
				styleViewPt();
				ShowPatient("Files\\Patient17_45Y.bin");
				foreColor(2);
				cout<<"\n\n\n\n\t\t\t\t\t\t\t      <<<< Press Any Key back to [MENU PATIENT] >>>>"<<endl;
				getch(); 
				Patient17_45Y(); 
				break;
			case 2:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient17_45Y.bin");
						SearchPatient("Files\\Patient17_45Y.bin"); 
						cls(); 
						cover();
						chooseSearch(); 
					}while(getch() != 27); 
					Patient17_45Y(); 
				}
				break;
			case 3:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient17_45Y.bin");
						UpdatePatient("Files\\Patient17_45Y.bin", 18, 45); 
						cls();
						cover();
						chooseUpdate(); 
					}while(getch() != 27); 
					Patient17_45Y(); 
				}
				break;
			case 4:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient17_45Y.bin");;
						DeletePatient("Files\\Patient17_45Y.bin"); 
						cls(); 
						cover();
						chooseDelete(); 
					}while(getch() != 27); 
					Patient17_45Y(); 
				}
				break;
			case 5:
				{
					cls();
					Patient(); 
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
}

void Patient45Y_UP()
{	
	int y = 0;
	char option;
	cls();
	cover();
	BoxPatient1();
	foreColor(6);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<" INSERT PATIENT";
		gotoxy(76, 16); cout<<" VIEW PATIENT";
		gotoxy(76, 19); cout<<" SEARCH PATIENT";
		gotoxy(76, 22); cout<<" UPDATE PATIENT";
		gotoxy(76, 25); cout<<" DELETE PATIENT";
		gotoxy(76, 28); cout<<" RETURN";
		foreColor(9); gotoxy(68, 32); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<" INSERT PATIENT";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<" VIEW PATIENT";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<" SEARCH PATIENT";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<" UPDATE PATIENT";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<" DELETE PATIENT";
		}
		if(y == 5)
		{
			foreColor(4); gotoxy(76, 28); cout<<" RETURN";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 5;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 5)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					InsertPatient("Files\\Patient45Y_UP.bin", 3999, 46);
					cls();
					cover();
					chooseInsert();
				}while(getch() != 27);
				Patient45Y_UP(); 
				break;
			case 1:
				cls();
				cover();
				styleViewPt();
				ShowPatient("Files\\Patient45Y_UP.bin");
				foreColor(2);
				cout<<"\n\n\n\n\t\t\t\t\t\t\t      <<<< Press Any Key back to [MENU PATIENT] >>>>"<<endl;
				getch(); 
				Patient45Y_UP(); 
				break;
			case 2:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient45Y_UP.bin");
						SearchPatient("Files\\Patient45Y_UP.bin"); 
						cls();
						cover();
						chooseSearch(); 
					}while(getch() != 27); 
					Patient45Y_UP(); 
				}
				break;
			case 3:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient45Y_UP.bin");
						UpdatePatient("Files\\Patient45Y_UP.bin", 46); 
						cls(); 
						cover();
						chooseUpdate(); 
					}while(getch() != 27); 
					Patient45Y_UP(); 
				}
				break;
			case 4:
				{
					do{
						cls();
						cover();
						ShowPatient("Files\\Patient45Y_UP.bin");
						DeletePatient("Files\\Patient45Y_UP.bin"); 
						cls(); 
						cover();
						chooseDelete(); 
					}while(getch() != 27); 
					Patient45Y_UP(); 
				}
				break;
			case 5:
				{
					cls();
					Patient(); 
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
}


void SURGICAL()
{
	int y = 0;
	char option;
	cls();
	cover();
	BoxSurgical();
	foreColor(7);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<" INSERT SURGICAL";
		gotoxy(76, 16); cout<<" VIEW SURGICAL";
		gotoxy(76, 19); cout<<" SEARCH SURGICAL";
		gotoxy(76, 22); cout<<" UPDATE SURGICAL";
		gotoxy(76, 25); cout<<" DELETE SURGICAL";
		gotoxy(76, 28); cout<<" RETURN";
		foreColor(9); gotoxy(68, 32); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<" INSERT SURGICAL";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<" VIEW SURGICAL";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<" SEARCH SURGICAL";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<" UPDATE SURGICAL";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<" DELETE SURGICAL";
		}
		if(y == 5)
		{
			foreColor(4); gotoxy(76, 28); cout<<" RETURN";
		}
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 5;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 5)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					Insertsurgical();
					cls();
					cover();
					chooseInsert();
				}while(getch() != 27);
				SURGICAL(); 
				break;
			case 1:
				cls();
				cover();
				styleViewSp();
				Showsurgical();
				foreColor(2);
				cout<<"\n\n\n\n\t\t\t\t\t\t\t      <<<< Press Any Key back to [MENU SURGICAL] >>>>"<<endl;
				getch(); 
				SURGICAL(); 
				break;
			case 2:
				{
					do{
						cls();
						cover();
						Showsurgical();
						Searchsurgical(); 
						cls();
						cover();
						chooseSearch(); 
					}while(getch() != 27); 
					SURGICAL(); 
				}
				break;
			case 3:
				{
					do{
						cls();
						cover();
						Showsurgical();
						Updatesurgical(); 
						cls(); 
						cover();
						chooseUpdate(); 
					}while(getch() != 27); 
					SURGICAL(); 
				}
				break;
			case 4:
				{
					do{
						cls();
						cover();
						Showsurgical();
						Deletesurgical(); 
						cls(); 
						cover();
						chooseDelete(); 
					}while(getch() != 27); 
					SURGICAL(); 
				}
				break;
			case 5:
				{
					cls();
					Patient(); 
				}
				break;
			default:
				cls();
				break;
		}

	}while(1);
}

void Invoice()
{
	int y = 0;
	char option;
	cls();
	cover();
	BoxInvoice();
	foreColor(8);
	ANT();
	do
	{
		setcursor(false, 1);
		foreColor(2);
		foreColor(6);gotoxy(76, 13); cout<<"PATIENT (0Y - 17Y)";
		gotoxy(76, 16); cout<<"PATIENT (18Y - 45Y)";
		gotoxy(76, 19); cout<<"PATIENT (46Y UP)";
		gotoxy(76, 22); cout<<"SURGICAL PATIENT";
		gotoxy(76, 25); cout<<"BACK TO MENU";
		foreColor(9); gotoxy(68, 29); cout<<"<<< USE UP AND DOWN ARROW KEY >>>"; 
	    
	    if(y == 0)
		{
			foreColor(4); gotoxy(76, 13); cout<<"PATIENT (0Y - 17Y)";
		}
		if(y == 1)
		{
			foreColor(4); gotoxy(76, 16); cout<<"PATIENT (18Y - 45Y)";
		}
		if(y == 2)
		{
			foreColor(4); gotoxy(76, 19); cout<<"PATIENT (46Y UP)";
		}
		if(y == 3)
		{
			foreColor(4); gotoxy(76, 22); cout<<"SURGICAL PATIENT";
		}
		if(y == 4)
		{
			foreColor(4); gotoxy(76, 25); cout<<"BACK TO MENU";
		}
		
		option = getch();
		switch(option)
		{
			case 72:
				{
					y--; 
					if(y < 0)
					{
						y = 4;
					}
					break;
				}
			case 80:
				{
					y++; 
					if(y > 4)
					{
						y = 0;
					}
					break;
				}
		}
	}while(option != 13); 
	
	do
	{	
		switch(y)
		{
			case 0:
				do
				{
					cls();
					cover();
					ShowPatient("Files\\Patient0_17Y.bin");
					invoiceTemplate("Files\\Patient0_17Y.bin"); 
					cls();
					cover();
					chooseSearch(); 
				}while(getch() != 27);	
				Invoice();
				break;
			case 1:
				do
				{
					cls(); 
					cover();
					ShowPatient("Files\\Patient17_45Y.bin");
					invoiceTemplate("Files\\Patient17_45Y.bin");
					cls();
					cover();
					chooseSearch(); 
				}while(getch() != 27);
				Invoice();
				break;
			case 2:
				do
				{
					cls();
					cover();
					ShowPatient("Files\\Patient45Y_UP.bin");
					invoiceTemplate("Files\\Patient45Y_UP.bin");
					cls();
					cover();
					chooseSearch(); 
				}while(getch() != 27);
				Invoice();
				break;
			case 3:
				do
				{
					cls();
					cover();
					Showsurgical();
					invoiceTemplate();
					cls();
					cover();
					chooseSearch(); 
				}while(getch() != 27);
				Invoice();
				break;
			case 4:
				MainMenu();
				break;
			default:
				cls();
				break;
		}

	}while(1);
}

void IncomeAndExpense()
{
		cls();
		cover();
		dataincomeandExpense();
		styelIncomeAndExpense();
		double p1 = getTotal("Files\\Patient0_17Y.bin"); 
		double p2 = getTotal("Files\\Patient17_45Y.bin"); 
		double p3 = getTotal("Files\\Patient45Y_UP.bin"); 
		double p4 = GetTotal("Files\\surgical.bin");
		double staffSalary = getTotalSalary("Files\\staff.bin");
		double NetIncome;
		double totalIncome;
		
		totalIncome = p1 + p2 + p3 + p4;
		
		gotoxy(96, 14); cout<<"$"<<p1 ; 
		gotoxy(96, 16); cout<<"$"<<p2 ;
		gotoxy(96, 18); cout<<"$"<<p3 ;

		gotoxy(96, 20); cout<<"$"<<p4 ; 
		gotoxy(103, 22); cout<<totalIncome ;
		gotoxy(96, 28); cout<<"$"<<staffSalary;
		NetIncome = totalIncome - staffSalary;
		foreColor(2);
		gotoxy(86, 32); cout<<"$"<<NetIncome ;
		
		int totalPatients = countTotalPatients("Files\\Patient0_17Y.bin") + countTotalPatients("Files\\Patient17_45Y.bin") + countTotalPatients("Files\\Patient45Y_UP.bin") + countTotalPatients("Files\\surgical.bin");
		int pt1 = countTotalPatients("Files\\Patient0_17Y.bin");
		int pt2 = countTotalPatients("Files\\Patient17_45Y.bin");
		int pt3 = countTotalPatients("Files\\Patient45Y_UP.bin");
		int pt4 = countTotalPatients("Files\\surgical.bin");
		
		gotoxy(68, 14); cout<<pt1;
		gotoxy(68, 16); cout<<pt2;
		gotoxy(68, 18); cout<<pt3;
		gotoxy(68, 20); cout<<pt4;
	    				
	    string filePath = "Files\\Staff.bin";
		int totalStaff = countTotalStaff(filePath);
		gotoxy(47, 28); cout<<"Staff";		
		if(totalStaff != -1) 
		{
			gotoxy(68, 28); cout<<totalStaff;
		}
		foreColor(2);
		foreColor(7); cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t<<<< Press Any Key back to [MENU] >>>>"<<endl;
		getch();
		MainMenu();
}

void ABOUTYUS()
{
	cls();
	cover();
	foreColor(6); 
	styleAboutMe();
	foreColor(5);
	gotoxy(44,12); cout<<"-    Topic : Hospital Management System.";
	gotoxy(44,14); cout<<"-    Member : Taing ChingSong, Rithy PremPrey, Roeun Chanthou.";
	gotoxy(44,20); cout<<"-    We have completed Scholarship course C/C++ at ANT Technology Training Center.";
	gotoxy(44,16); cout<<"-    Teacher : Mr. Mean Pheakdey, Mentor 1 : Miss Vuth Reachana, ";
	gotoxy(44,18); cout<<"     Mentor 2 : Mr. San Moniakkhara.";
	gotoxy(44,26); cout<<"-    Our Email : roeunchanthou03@gmail.com, chingsong57@gmail.com, rahengzii@gmail.com";
	gotoxy(44,22); cout<<"-    In the end let's say thank you to all of teachers at ANT Training";
	gotoxy(44,24); cout<<"     that give me lots of knowledge.";
	gotoxy(44,28); cout<<"-     Thank You \3\3.";
	foreColor(7); cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t<<<< Press Any Key back to [MENU] >>>>"<<endl;
	getch();
	MainMenu();
}