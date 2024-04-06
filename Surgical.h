#ifndef SURGICAL_PATIENT_H
#define SURGICAL_PATIENT_H

#include <iostream>
#include <fstream>
#include "design.h"
#include "patient.h"

class Surgical{
	private: 
		int id = 4999, day;
		double priceRoom = 150;
		int age;  
		char name[30], gender[10], phoneNumber[20], dob[20], address[30], disease[30], surgeryDay[15];
		double amount, service; 
	public: 
		void Input()
		{
			BoxInputSurgical();
			foreColor(6);
			gotoxy(124,17); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(124,29); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(38,13); foreColor(2); cout<<"ID : ";
			gotoxy(96, 13); foreColor(2); cout<<"NAME : ";
			gotoxy(38,17); foreColor(2);cout<<"GENDER : ";
			gotoxy(96,17); foreColor(2);cout<<"DATE OF BIRTH : ";
			gotoxy(38,21); foreColor(2);cout<<"AGE : ";
			gotoxy(96,21); foreColor(2);cout<<"PHONE NUMBER : ";
			gotoxy(38,25); foreColor(2);cout<<"ADDRESS : ";
			gotoxy(96,25); foreColor(2);cout<<"DISEASE : ";
			gotoxy(38,29); foreColor(2);cout<<"DAY OF STAY : ";
			gotoxy(96,29); foreColor(2);cout<<"SURGERY DATE : ";
			gotoxy(38,33); foreColor(2);cout<<"AMOUNT ($) : ";
			gotoxy(96,33); foreColor(2);cout<<"SERVICE ($) : ";
			
			gotoxy(43, 13); cout<<id<<endl; fflush(stdin); cin.clear();
			fflush(stdin); cin.clear();
			gotoxy(103, 13);
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
			gotoxy(47, 17); 
			while(true)
			{
				inputLetter(gender, 6);
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

			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(112, 17); cout<<"            "; 
		        gotoxy(112, 17); inputNumber(dob, 10);
				
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
				gotoxy(109, 19); cout<<"                           "; 
		        gotoxy(109, 19); foreColor(4); cout<<"Wrong Format";
	        }
	        
  			gotoxy(109, 19); cout<<"                           "; 
	        gotoxy(44, 21); cout<<age;
	        
			fflush(stdin); cin.clear();
			gotoxy(111, 21); 
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
			gotoxy(48, 25); 
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
			gotoxy(106, 25); 
			while(true)
			{
				inputLetter(disease, 26);
				if(!strcmp(disease, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(52, 29); day = inputFloat();
			fflush(stdin); cin.clear();

			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(111, 29); cout<<"            "; 
		        gotoxy(111, 29); inputNumber(surgeryDay, 10);
				
				if(!strcmp(surgeryDay, "\0"))
				{
					continue;
				}
				
				if(strlen(surgeryDay)==10)
				{
					string day = string(1, surgeryDay[0]) + string(1, surgeryDay[1]); 
			        string month = string(1, surgeryDay[3]) + string(1, surgeryDay[4]); 
			        string year = string(1, surgeryDay[6]) + string(1, surgeryDay[7]) + string(1, surgeryDay[8]) + string(1, surgeryDay[9]); 
			        
			        if((stoi(day) >= 1 && stoi(day) <= 31) && (stoi(month) >= 1 && stoi(month) <= 12) && (stoi(year) >= 1900 && stoi(year) <= 2024) && (surgeryDay[2] == '-' && surgeryDay[5] == '-')) 
					{
						break; 
					}
				}	
		        gotoxy(107, 31); foreColor(4); cout<<"Wrong Format";
	        }
	        
  			gotoxy(107, 31); cout<<"                           "; 
	        
			fflush(stdin); cin.clear();
			gotoxy(51, 33); amount = inputFloat(); 
			fflush(stdin); cin.clear();
			gotoxy(110, 33); service = inputFloat(); 
			
		}
		
		void Display(int y)
		{	 
			drawBoxSingleLine(7, y, 156, 1, 5); 
			foreColor(6); gotoxy(9, y + 1); cout<<left<<setw(7)<<id<<setw(15)<<name<<setw(10)<<gender<<setw(7)<<age<<setw(15)<<dob<<setw(15)<<phoneNumber<<setw(18)<<address<<setw(15)<<disease<<setw(15)<<day<<setw(15)<<surgeryDay<<setw(11)<<amount<<setw(8)<<service;
		}
		
		void Header(int y)
		{
			DrawRectangle(7, y - 1 , 156, 1, 2); 
			foreColor(4);
			gotoxy(9, y); cout<<left<<setw(7)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Gender"<<setw(7)<<"Age"<<setw(15)<<"Date Of Birth" << setw(15) << "Phone Number" << setw(18) << "Address" << setw(15) << "Disease"<<setw(15)<<"Day Of stay"<<setw(15)<<"Surgery Day"<<setw(11)<<"Amount($)"<<setw(8)<<"Service($)";
		}
		
		void edit()
		{
			BoxInputSurgical();
			foreColor(6);
			gotoxy(124,17); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(124,29); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(38,13); foreColor(2); cout<<"ID : ";
			gotoxy(96, 13); foreColor(2); cout<<"NAME : ";
			gotoxy(38,17); foreColor(2);cout<<"GENDER : ";
			gotoxy(96,17); foreColor(2);cout<<"DATE OF BIRTH : ";
			gotoxy(38,21); foreColor(2);cout<<"AGE : ";
			gotoxy(96,21); foreColor(2);cout<<"PHONE NUMBER : ";
			gotoxy(38,25); foreColor(2);cout<<"ADDRESS : ";
			gotoxy(96,25); foreColor(2);cout<<"DISEASE : ";
			gotoxy(38,29); foreColor(2);cout<<"DAY OF STAY : ";
			gotoxy(96,29); foreColor(2);cout<<"SURGERY DATE : ";
			gotoxy(38,33); foreColor(2);cout<<"AMOUNT ($) : ";
			gotoxy(96,33); foreColor(2);cout<<"SERVICE ($) : ";
			
			gotoxy(43, 13); cout<<id<<endl; fflush(stdin); cin.clear();
			fflush(stdin); cin.clear();
			gotoxy(103, 13);
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
			gotoxy(47, 17); 
			while(true)
			{
				inputLetter(gender, 6);
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

			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(112, 17); cout<<"            "; 
		        gotoxy(112, 17); inputNumber(dob, 10);
				
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
				gotoxy(109, 19); cout<<"                           "; 
		        gotoxy(109, 19); foreColor(4); cout<<"Wrong Format";
	        }
	        
  			gotoxy(109, 19); cout<<"                           "; 
	        gotoxy(44, 21); cout<<age;
	        
			fflush(stdin); cin.clear();
			gotoxy(111, 21); 
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
			gotoxy(48, 25); 
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
			gotoxy(106, 25); 
			while(true)
			{
				inputLetter(disease, 26);
				if(!strcmp(disease, "\0"))
				{
					continue;
				}
				else
				{
					break;
				}
			}
			fflush(stdin); cin.clear();
			gotoxy(52, 29); day = inputFloat();
			fflush(stdin); cin.clear();

			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(111, 29); cout<<"            "; 
		        gotoxy(111, 29); inputNumber(surgeryDay, 10);
				
				if(!strcmp(surgeryDay, "\0"))
				{
					continue;
				}
				
				if(strlen(surgeryDay)==10)
				{
					string day = string(1, surgeryDay[0]) + string(1, surgeryDay[1]); 
			        string month = string(1, surgeryDay[3]) + string(1, surgeryDay[4]); 
			        string year = string(1, surgeryDay[6]) + string(1, surgeryDay[7]) + string(1, surgeryDay[8]) + string(1, surgeryDay[9]); 
			        
			        if((stoi(day) >= 1 && stoi(day) <= 31) && (stoi(month) >= 1 && stoi(month) <= 12) && (stoi(year) >= 1900 && stoi(year) <= 2024) && (surgeryDay[2] == '-' && surgeryDay[5] == '-')) 
					{
						break; 
					}
				}	
		        gotoxy(107, 31); foreColor(4); cout<<"Wrong Format";
	        }
	        
  			gotoxy(107, 31); cout<<"                           "; 
	        
			fflush(stdin); cin.clear();
			gotoxy(51, 33); amount = inputFloat(); 
			fflush(stdin); cin.clear();
			gotoxy(110, 33); service = inputFloat();
			 
		}
			
		
		
		int getID()
		{
			return id; 
		}
		
		void setID(int id)
		{
			this -> id = id; 
		}
		char* getName()
		{
			return name;
		}
		char* getAdd()
		{
			return address;
		}
		float getAge()
		{
			return age;
		}
		char* getdate()
		{
			return dob;
		}
		char* getDisease()
		{
			return disease;
		}
		double getService()
		{
			return service;
		}
		double getAmount()
		{
			return amount;
		}
		int getDay()
		{
			return day;
		}
		double getpriceRoom()
		{
			return priceRoom;
		}
		
}; 

	Surgical surgical;
	fstream  filesurgical;

void Insertsurgical()
{
	setcursor(true, 1);
	filesurgical.open("Files\\surgical.bin", ios::in | ios::binary);
	
	int lastId = 4999;
	
	while(filesurgical.read((char*)&surgical,sizeof(surgical)))
	{
		lastId = surgical.getID();
	}
	surgical.setID(lastId + 1);
	filesurgical.close();
	
	filesurgical.open("Files\\surgical.bin", ios::out | ios::app | ios::binary);
	surgical.Input();
	foreColor(2);
	setcursor(false, 1);
//	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    <<< Successfull >>>";
//	delay(1000);
//	cls();
	ClearBG();
	filesurgical.write((char*)&surgical,sizeof(surgical));
	filesurgical.close();
}
void Showsurgical()
{
	setcursor(false, 1);
	int y = 12;
	filesurgical.open("Files\\surgical.bin", ios::in | ios::binary);
	if(filesurgical.fail()) 
	{
		gotoxy(73, 15);
		cout<<"<<< file not found >>>"<<endl;
	}
	else
	{
		cout<<endl<<endl;
		gotoxy(0,9);
		surgical.Header(y-2);
		filesurgical.read((char*)&surgical,sizeof(surgical));
		while(filesurgical.eof()!= true)
		{
			surgical.Display(y);
			y += 3; 
			filesurgical.read((char*)&surgical,sizeof(surgical));
		}
	}
	filesurgical.close();
}
void Searchsurgical()
{
	setcursor(true, 1);
	int y = 17; 
	filesurgical.open("Files\\surgical.bin", ios::in | ios::binary);
	bool found = false;
	if(filesurgical.fail())
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
		filesurgical.read((char*)&surgical,sizeof(surgical));
		while(!filesurgical.eof())
		{
			if(tempId == surgical.getID())
			{
//				cls();
				cover();
				ClearBG();
				gotoxy(77,5);
				foreColor(3);
				styleSearchPt();
//				cout<<"... surgical Data ...\n\n\n\n\n\n\n\n\n";
//				gotoxy(0, 17);
				surgical.Header(y);
				surgical.Display(y + 2);
				foreColor(3);
				y += 3; 
				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t <<< Press to Continue >>>";
				getch();
				found = true;
			}
			filesurgical.read((char*)&surgical,sizeof(surgical));
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
	filesurgical.close();
}

void Updatesurgical()
{
	setcursor(true, 1);
	filesurgical.open("Files\\surgical.bin", ios::out | ios::in | ios::binary);
	bool found = false;
	if(filesurgical.fail())
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
		filesurgical.read((char*)&surgical,sizeof(surgical));
		while(!filesurgical.eof())
		{
			if(updateid == surgical.getID())
			{
//				cls();
				cover();
				ClearBG();
//				gotoxy(72, 5);
//				foreColor(3);
//				cout<<"---- Enter surgical Data ----";
				surgical.edit();
				int lastread = filesurgical.tellg(); 
				filesurgical.seekp(lastread - sizeof(surgical));
				filesurgical.write((char*)&surgical,sizeof(surgical));
				found = true;
			}
			filesurgical.read((char*)&surgical, sizeof(surgical));
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
	filesurgical.close();
}

void Deletesurgical()
{
	setcursor(true, 1);
	filesurgical.open("Files\\surgical.bin", ios::in | ios::binary);
	fstream backup;

	backup.open("Files\\Temp.bin", ios::out | ios::binary);
	
	bool found = false;
	if(filesurgical.fail())
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
		filesurgical.read((char*)&surgical,sizeof(surgical));
		while(!filesurgical.eof())
		{
			if(deleteid == surgical.getID())
			{
				found = true;
			}
			if(deleteid != surgical.getID())
			{
				backup.write((char*)&surgical, sizeof(surgical));
			}
			filesurgical.read((char*)&surgical,sizeof(surgical));
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
	filesurgical.close();
	backup.close();
	remove("Files\\surgical.bin");
	rename("Files\\Temp.bin", "Files\\surgical.bin");
}

//////////////////////////////////////////

int countPatient0_17Y(); 
int countPatient17Y_45Y(); 
int countPatient45Y_UP();

void invoiceTemplate(){
	setcursor(true, 1);
	int y = 17; 
	int count = countPatient0_17Y() + countPatient17Y_45Y() + countPatient45Y_UP(); 
	SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);

	filesurgical.open("Files\\surgical.bin", ios::in | ios::binary);
	bool found = false;
	if(filesurgical.fail())
	{
		setcursor(false, 1);
		gotoxy(75, 15);
		cout<<"<<< File Not Found >>>";
		delay(1500);
	}
	else
	{
		int tempId;
		drawBoxSingleLine(60, 4, 46, 1, 3);
		gotoxy(61, 5); foreColor(14);
		cout<<"Enter ID you want to view Invoice : "; 
		gotoxy(97, 5); tempId = inputNumber();
		setcursor(false, 1);
		filesurgical.read((char*)&surgical,sizeof(surgical));
		while(!filesurgical.eof())
		{
			count++; 
			if(tempId == surgical.getID())
			{
				ClearBG();
				cover(); 
				BoxInvoiceSurgical();
				
				foreColor(2);
				gotoxy(28, 11); cout<<"Patient ID  "; gotoxy(50, 11); cout<<surgical.getID(); 
				gotoxy(105, 11); cout<<"Invoice ID "; gotoxy(125, 11); cout<<"YTT-123-00"<<count++; 
				gotoxy(28, 13); cout<<"Patient Name "; gotoxy(50, 13); cout<<surgical.getName(); 
				gotoxy(105, 13); cout<<"Address "; gotoxy(125, 13); cout<<surgical.getAdd(); 
				gotoxy(28, 15); cout<<"Age "; gotoxy(50, 15); cout<<surgical.getAge()<<" year"; 
				gotoxy(105, 15); cout<<"Date "; gotoxy(125, 15); cout<<surgical.getdate();
			
				foreColor(2); gotoxy(29, 19); cout<<"NO"; gotoxy(38, 19); cout<<"Description"; gotoxy(131, 19); cout<<"Price"; 
				foreColor(2); gotoxy(29, 21); cout<<"1"; gotoxy(38, 21); cout<<surgical.getDisease(); gotoxy(131, 21); cout<<"$"<<surgical.getAmount(); 
				foreColor(2); gotoxy(29, 23); cout<<"2"; gotoxy(38, 23); cout<<"Service"; gotoxy(131, 23); cout<<"$"<<surgical.getService();
				foreColor(2); gotoxy(29, 25); cout<<"3"; gotoxy(38, 25); cout<<"Room"; gotoxy(131, 25); cout<<"$"<<surgical.getpriceRoom(); 
				foreColor(2); gotoxy(29, 27); cout<<"4"; gotoxy(38, 27); cout<<"Day Of Stay"; gotoxy(131, 27); cout<<surgical.getDay()<<" Day";
				gotoxy(124, 29); cout<<"Total : $"<<surgical.getDay() * (surgical.getAmount() + surgical.getService() + surgical.getpriceRoom()); 
				gotoxy(0, 30); cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t <<< Press to Continue >>>";
				getch();
				found = true;
				break; 
			}
			filesurgical.read((char*)&surgical,sizeof(surgical));
		}
		if(found == false)
		{
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
	}
	filesurgical.close();
}

double GetTotal(string path)
{
	filesurgical.open(path, ios::in | ios::binary); 
	double total = 0.00; 
	filesurgical.read((char*)&surgical,sizeof(surgical));
	while(!filesurgical.eof()){
		total += (surgical.getDay() * (surgical.getAmount() + surgical.getService() + surgical.getpriceRoom())); 
		filesurgical.read((char*)&surgical,sizeof(surgical));
	}
	filesurgical.close(); 
	return total; 
}


#endif