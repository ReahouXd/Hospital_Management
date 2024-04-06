#ifndef _FILESTAFF_H
#define _FILESTAFF_H

#include<iostream>
#include<conio.h>
#include<fstream>
#include"antheaderInput.h"
#include"design.h"
#include"antheaderPlusPlus.h"
#include "patient.h"
using namespace std;

class Staff
{
	private:
		int id = 999, age;
		char name[30], gender[10], phoneNumber[15], dob[15], address[30], position[20];
		float salary;
	public:
		void setID(int id)
		{
			this -> id = id;
		}
		int getID()
		{
			return id;
		}
		void Input()
		{
			BoxInputStaff();
			foreColor(6);;
			gotoxy(65,22); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(38,14); foreColor(2); cout<<"ID : ";
			gotoxy(96, 14); foreColor(2); cout<<"NAME : ";
			gotoxy(38,18); foreColor(2);cout<<"GENDER : ";
			gotoxy(96,18); foreColor(2);cout<<"POSITION : ";
			gotoxy(38,22); foreColor(2);cout<<"DATE OF BIRTH : ";
			gotoxy(96,22); foreColor(2);cout<<"SALARY : ";
			gotoxy(38,26); foreColor(2);cout<<"PHONE NUMBER : ";
			gotoxy(96,26); foreColor(2);cout<<"ADDRESS : ";
			
			gotoxy(43, 14); cout<<id<<endl; fflush(stdin); cin.clear();
			gotoxy(103, 14);
			while(true)
			{
			inputLetter(name, 29);
			if(!strcmp(name, "\0"))
			{
				continue;
			}
			else
			{
				break;
			}
			}
			fflush(stdin); cin.clear();
			gotoxy(47, 18); 
			while(true)
			{
				inputLetter(gender,6);
				if(!strcmp(gender, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(107, 18); 
			while(true)
			{
				inputLetter(position, 25);
				if(!strcmp(position, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(54, 22); cout<<"           "; 
		        gotoxy(54, 22); inputNumber(dob, 10);
				
				if(!strcmp(dob, "\0"))
				{
					continue;
				}
				
				if(strlen(dob)==10)
				{
					string day = string(1, dob[0]) + string(1, dob[1]); 
			        string month = string(1, dob[3]) + string(1, dob[4]); 
			        string year = string(1, dob[6]) + string(1, dob[7]) + string(1, dob[8]) + string(1, dob[9]); 
			        
			        if((stoi(day) >= 1 && stoi(day) <= 31) && (stoi(month) >= 1 && stoi(month) <= 12) && (stoi(year) >= 1900 && stoi(year) <= 2024) && (dob[2] == '-' && dob[5] == '-')) 
					{
						SYSTEMTIME currentTime;
    					GetLocalTime(&currentTime);
    					
    					age = currentTime.wYear - stoi(year); 
						if(stoi(month) > currentTime.wMonth) age--; 
						
						break; 
					}
				}	
				gotoxy(54, 24); cout<<"                           "; 
		        gotoxy(54, 24); foreColor(4); cout<<"Wrong Format";
	        }
	        gotoxy(54, 24); cout<<"                           ";
			fflush(stdin); cin.clear();
			
			gotoxy(105, 22);  
			salary = inputFloat();
			fflush(stdin); cin.clear();
			gotoxy(53, 26); 
			while(true)
			{
				input4Tel(phoneNumber, 14);
				if(!strcmp(phoneNumber, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(106, 26); 
			while(true)
			{
				inputLetter(address, 26);
				if(!strcmp(address, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
		}
		
		void Display(int y)
		{	 
			drawBoxSingleLine(15, y, 138, 1, 5); 
			foreColor(6); gotoxy(19, y + 1); cout<<left<<setw(10)<<id<<setw(20)<<name<<setw(10)<<gender<<setw(10)<<age<<setw(15)<<position<<setw(20)<<dob<<setw(13)<<salary<<setw(20)<<phoneNumber<<setw(15)<<address;
		}
		
		void Header(int y)
		{
			DrawRectangle(15, y - 1, 138, 1, 2); 
			foreColor(4);
			gotoxy(19, y); cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Gender"<<setw(10)<<"Age"<<setw(15)<<"Position"<<setw(20)<<"Date of Birth"<<setw(13)<<"Salary($)"<<setw(20)<<"Phone Number"<<setw(15)<<"Address";
		}
		
		void edit()
		{
			BoxInputStaff();
			foreColor(6);;
			gotoxy(65,22); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(38,14); foreColor(2); cout<<"ID : ";
			gotoxy(96, 14); foreColor(2); cout<<"NAME : ";
			gotoxy(38,18); foreColor(2);cout<<"GENDER : ";
			gotoxy(96,18); foreColor(2);cout<<"POSITION : ";
			gotoxy(38,22); foreColor(2);cout<<"DATE OF BIRTH : ";
			gotoxy(96,22); foreColor(2);cout<<"SALARY : ";
			gotoxy(38,26); foreColor(2);cout<<"PHONE NUMBER : ";
			gotoxy(96,26); foreColor(2);cout<<"ADDRESS : ";
			
			gotoxy(43, 14); cout<<id<<endl; fflush(stdin); cin.clear();
			gotoxy(103, 14);
			while(true)
			{
			inputLetter(name, 29);
			if(!strcmp(name, "\0"))
			{
				continue;
			}
			else
			{
				break;
			}
			}
			fflush(stdin); cin.clear();
			gotoxy(47, 18); 
			while(true)
			{
				inputLetter(gender,6);
				if(!strcmp(gender, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(107, 18); 
			while(true)
			{
				inputLetter(position, 25);
				if(!strcmp(position, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(54, 22); cout<<"           "; 
		        gotoxy(54, 22); inputNumber(dob, 10);
				
				if(!strcmp(dob, "\0"))
				{
					continue;
				}
				
				if(strlen(dob)==10)
				{
					string day = string(1, dob[0]) + string(1, dob[1]); 
			        string month = string(1, dob[3]) + string(1, dob[4]); 
			        string year = string(1, dob[6]) + string(1, dob[7]) + string(1, dob[8]) + string(1, dob[9]); 
			        
			        if((stoi(day) >= 1 && stoi(day) <= 31) && (stoi(month) >= 1 && stoi(month) <= 12) && (stoi(year) >= 1900 && stoi(year) <= 2024) && (dob[2] == '-' && dob[5] == '-')) 
					{
						SYSTEMTIME currentTime;
    					GetLocalTime(&currentTime);
    					
    					age = currentTime.wYear - stoi(year); 
						if(stoi(month) > currentTime.wMonth) age--; 
						
						break; 
					}
				}	
				gotoxy(54, 24); cout<<"                           "; 
		        gotoxy(54, 24); foreColor(4); cout<<"Wrong Format";
	        }
	        gotoxy(54, 24); cout<<"                           ";
			fflush(stdin); cin.clear();
			
			gotoxy(105, 22);  
			salary = inputFloat();
			fflush(stdin); cin.clear();
			gotoxy(53, 26); 
			while(true)
			{
				input4Tel(phoneNumber, 14);
				if(!strcmp(phoneNumber, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(106, 26); 
			while(true)
			{
				inputLetter(address, 26);
				if(!strcmp(address, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
		}
		
		double getSalary(){
			return salary; 
		}
		
};

	Staff staff;
	fstream fileStaff;

void InsertStaff()
{
	setcursor(true, 1);
	fileStaff.open("Files\\Staff.bin", ios::in | ios::binary);
	
	int lastId = 999;
	
	while(fileStaff.read((char*)&staff,sizeof(staff)))
	{
		lastId = staff.getID();
	}
	staff.setID(lastId + 1);
	fileStaff.close();
	
	fileStaff.open("Files\\Staff.bin", ios::out | ios::app | ios::binary);
	staff.Input();
	foreColor(2);
	setcursor(false, 1);
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    <<< Successfull >>>";
	delay(1000);
//	cls();
	ClearBG();
	fileStaff.write((char*)&staff,sizeof(staff));
	fileStaff.close();
}
void ShowStaff()
{
	setcursor(false, 1);
	int y = 12;
	fileStaff.open("Files\\Staff.bin", ios::in | ios::binary);
	if(fileStaff.fail()) 
	{
		gotoxy(73, 15);
		cout<<"<<< file not found >>>"<<endl;
	}
	else
	{
		cout<<endl<<endl;
		gotoxy(0,9);
		staff.Header(y - 2);
		fileStaff.read((char*)&staff,sizeof(staff));
		while(fileStaff.eof()!= true)
		{
			staff.Display(y);
			y += 3; 
			fileStaff.read((char*)&staff,sizeof(staff));
		}
	}
	fileStaff.close();
}
void SearchStaff()
{
	setcursor(true, 1);
	int y = 17; 
	fileStaff.open("Files\\Staff.bin", ios::in | ios::binary);
	bool found = false;
	if(fileStaff.fail())
	{
		setcursor(false, 1);
		gotoxy(75, 15);
		cout<<"<<< File Not Found >>>";
		delay(1500);
	}
	else
	{
		int tempId;
		drawBoxSingleLine(64, 4, 38, 1, 3);
		gotoxy(65, 5); foreColor(14);
		cout<<"Enter ID you want to search : "; 
		gotoxy(95, 5); tempId = inputNumber();
		setcursor(false, 1);
		fileStaff.read((char*)&staff,sizeof(staff));
		while(!fileStaff.eof())
		{
			if(tempId == staff.getID())
			{
//				cls();
				cover();
				ClearBG();
				gotoxy(77,5);
				foreColor(3);
				styleSearch();
//				cout<<"... Staff Data ...\n\n\n\n\n\n\n\n\n";
//				gotoxy(0, 17);
				staff.Header(y);
				staff.Display(y + 2);
				foreColor(3);
				y += 3; 
				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t <<< Press to Continue >>>";
				getch();
				found = true;
			}
			fileStaff.read((char*)&staff,sizeof(staff));
		}
		if(found == false)
		{
//			cls();
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
	}
	fileStaff.close();
}

void UpdateStaff()
{
	setcursor(true, 1);
	fileStaff.open("Files\\Staff.bin", ios::out | ios::in | ios::binary);
	bool found = false;
	if(fileStaff.fail())
	{
		setcursor(false, 1);
		gotoxy(75, 15);
		cout<<"<<< File Not Found >>>"<<endl;
		delay(1500);
	}
	else
	{
		int updateid;
		
		drawBoxSingleLine(64, 4, 38, 1, 3);
		gotoxy(65, 5); foreColor(14);
		cout<<"Enter ID You want to Update : "; 
		gotoxy(95, 5); updateid = inputNumber();
		fileStaff.read((char*)&staff,sizeof(staff));
		while(!fileStaff.eof())
		{
			if(updateid == staff.getID())
			{
//				cls();
				cover();
				ClearBG();
				staff.edit();
				int lastread = fileStaff.tellg(); 
				fileStaff.seekp(lastread - sizeof(staff));
				fileStaff.write((char*)&staff,sizeof(staff));
				found = true;
			}
			fileStaff.read((char*)&staff, sizeof(staff));
		}
		if(found == false)
		{
			setcursor(false, 1);
//			cls();
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
		if(found == true)
		{
			setcursor(false, 1);
//			cls();
			cover();
			ClearBG();
			UpDateSuccess();
			delay(1500);
		}
	}
	fileStaff.close();
}

void DeleteStaff()
{
	setcursor(true, 1);
	fileStaff.open("Files\\Staff.bin", ios::in | ios::binary);
	fstream backup;

	backup.open("Files\\Temp.bin", ios::out | ios::binary);
	
	bool found = false;
	if(fileStaff.fail())
	{
		setcursor(false, 1);
		gotoxy(75, 15);
		cout<<"<<< File Not Found >>>";
		delay(1500);
	}
	else
	{
		int deleteid;
		drawBoxSingleLine(64, 4, 38, 1, 3);
		gotoxy(65, 5); foreColor(14);
		cout<<"Enter ID You want to Delete : "; 
		gotoxy(95, 5); deleteid = inputNumber();
		fileStaff.read((char*)&staff,sizeof(staff));
		while(!fileStaff.eof())
		{
			if(deleteid == staff.getID())
			{
				found = true;
			}
			if(deleteid != staff.getID())
			{
				backup.write((char*)&staff, sizeof(staff));
			}
			fileStaff.read((char*)&staff,sizeof(staff));
		}
		setcursor(false, 1);
		if(found == false)
		{
//			cls();
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
		if(found == true)
		{
//			cls();
			cover();
			ClearBG();
			DeleteSuccess();
			delay(1500);
		}
	}
	fileStaff.close();
	backup.close();
	remove("Files\\Staff.bin");
	rename("Files\\Temp.bin", "Files\\Staff.bin");
} 

double getTotalSalary(string path)
{
	fileStaff.open(path, ios::in | ios::binary); 
	double total = 0; 
	fileStaff.read((char*)&staff, sizeof(staff)); 
	while(!fileStaff.eof())
	{
		total += staff.getSalary(); 
		fileStaff.read((char*)&staff, sizeof(staff)); 
	}
	fileStaff.close(); 
	return total; 
}

int countTotalStaff(const string& filePath) 
{
    int totalCount = 0;
    ifstream file(filePath, ios::binary);
    
    if(!file.is_open()) 
	{
        cerr<<"Error opening file: "<<filePath;
        return -1;
    }

    while(file.read((char*)&staff, sizeof(staff))) 
	{
        totalCount++;
    }

    file.close();
    
    return totalCount;
}

#endif