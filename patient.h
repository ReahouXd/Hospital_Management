#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <fstream>
#include "design.h"

using namespace std; 

fstream filePatient; 

int AutoID(); 
char* inputLetter(char*, int); 
char* inputNumber(char*, int); 
char* input4Tel(char*, int);

class Patient{
	private: 
		int id;
		int age;  
		char name[30], gender[10], phoneNumber[20], date[20], address[30], disease[30];
		double amount, service; 
		
	public: 
		void Input(int minAge = 0, int maxAge = 100)
		{
			BoxInputPatient();
			foreColor(6);;
			gotoxy(124,18); foreColor(3); cout << "DD-MM-YYYY";
			gotoxy(38,14); foreColor(2); cout<<"ID : ";
			gotoxy(96, 14); foreColor(2); cout<<"NAME : ";
			gotoxy(38,18); foreColor(2);cout<<"GENDER : ";
			gotoxy(96,18); foreColor(2);cout<<"DATE OF BIRTH : ";
			gotoxy(38,22); foreColor(2);cout<<"AGE : ";
			gotoxy(96,22); foreColor(2);cout<<"PHONE NUMBER : ";
			gotoxy(38,26); foreColor(2);cout<<"ADDRESS : ";
			gotoxy(96,26); foreColor(2);cout<<"DISEASE : ";
			gotoxy(38,30); foreColor(2);cout<<"AMOUNT ($) : ";
			gotoxy(96,30); foreColor(2);cout<<"SERVICE ($) : ";
			
			gotoxy(43, 14); cout<<id<<endl; fflush(stdin); cin.clear();
			fflush(stdin); cin.clear();
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
			gotoxy(47, 18); 
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

			foreColor(2); 
			fflush(stdin); cin.clear();

			while(true)
	        {
		        foreColor(2); 
		        
		        gotoxy(112, 18); cout<<"            "; 
		        gotoxy(112, 18); inputNumber(date, 10);
				
				if(!strcmp(date, "\0"))
				{
					continue;
				}
				
				if(strlen(date)==10)
				{
					string day = string(1, date[0]) + string(1, date[1]); 
			        string month = string(1, date[3]) + string(1, date[4]); 
			        string year = string(1, date[6]) + string(1, date[7]) + string(1, date[8]) + string(1, date[9]); 
			        
			        if((stoi(day) >= 1 && stoi(day) <= 31) && (stoi(month) >= 1 && stoi(month) <= 12) && (stoi(year) >= 1900 && stoi(year) <= 2024) && (date[2] == '-' && date[5] == '-')) 
					{
						//
						SYSTEMTIME currentTime;
    					GetLocalTime(&currentTime);
    					
    					age = currentTime.wYear - stoi(year); 
						if(stoi(month) > currentTime.wMonth) age--; 
						
						if(age >= minAge && age <= maxAge) break; 
						else{
							gotoxy(108, 20); foreColor(4); cout<<"Age must be between "<<minAge<<" - "<<maxAge;
							continue; 
						}
					}
				}	
				gotoxy(107, 20); cout<<"                             "; 
		        gotoxy(108, 20); foreColor(4); cout<<"Wrong Format";
	        }
	        
  			gotoxy(107, 20); cout<<"                             ";
	        gotoxy(44, 22); cout<<age;
			fflush(stdin); cin.clear();
			gotoxy(111, 22);
			
			foreColor(2);
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
			gotoxy(48, 26); 
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
			gotoxy(106, 26); 
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
			gotoxy(51, 30); amount = inputFloat(); 
			fflush(stdin); cin.clear();
			gotoxy(110, 30); service = inputFloat(); 
		}
		
		void Display(int y)
		{	 
			drawBoxSingleLine(13, y, 145, 1, 5); 
			foreColor(6); gotoxy(16, y + 1); cout<<left<<setw(10)<<id<<setw(20)<<name<<setw(10)<<gender<<setw(8)<<age<<setw(15)<<date<<setw(18)<<disease<<setw(14)<<amount<<setw(14)<<service<<setw(15)<<phoneNumber<<setw(15)<<address;
		}
		
		void Header(int y)
		{
			DrawRectangle(13, y - 1 , 145, 1, 2); 
			foreColor(4);
			gotoxy(16, y); cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Gender"<<setw(8)<<"Age"<<setw(15)<<"Date of Birth"<<setw(18)<<"Disease"<<setw(14)<<"Amount($)"<<setw(14)<<"Service($)"<<setw(15)<<"Phone Number"<<setw(15)<<"Address";
		}
		
		int getID()
		{
			return id; 
		}
		
		int getAge()
		{
			return age; 
		}
		
		double getAmount()
		{
			return amount; 
		}
		
		double getService()
		{
			return service; 
		}
		
		char* getName(){
			return name; 
		}
		
		char* getAdd(){
			return address; 
		}
		
		char* getDate(){
			return date; 
		}
		
		char* getDisease(){
			return disease; 
		}
		
		void setID(int id)
		{
			this -> id = id; 
		}
}; 

Patient pt; 

void InsertPatient(string fileName_Path, int no, int minAge, int maxAge = 100)
{
	setcursor(true, 1);
	int lastId = no;
	filePatient.open(fileName_Path, ios::in | ios::binary); 
	
	while(filePatient.read((char*)&pt,sizeof(pt)))
	{
		lastId = pt.getID();
	}
	filePatient.close(); 
	
	filePatient.open(fileName_Path, ios::out | ios::app | ios::binary);
	pt.setID(lastId + 1); 
	pt.Input(minAge, maxAge);
	foreColor(2);
	setcursor(false, 1);
	cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t    <<< Successfull >>>";
	delay(1000);
	ClearBG();
	filePatient.write((char*)&pt,sizeof(pt));
	filePatient.close();
}
void ShowPatient(string fileName_Path)
{
	setcursor(false, 1);
	int y = 12;
	filePatient.open(fileName_Path, ios::in | ios::binary);
	if(filePatient.fail()) 
	{
		gotoxy(73, 15);
		cout<<"<<< file not found >>>"<<endl;
	}
	else
	{
		cout<<endl<<endl;
		gotoxy(0,9);
		pt.Header(y - 2);
		filePatient.read((char*)&pt,sizeof(pt));
		while(filePatient.eof()!= true)
		{
			pt.Display(y);
			y += 3; 
			filePatient.read((char*)&pt,sizeof(pt));
		}
	}
	filePatient.close();
}
void SearchPatient(string fileName_Path)
{
	setcursor(true, 1);
	int y = 17; 
	filePatient.open(fileName_Path, ios::in | ios::binary);
	bool found = false;
	if(filePatient.fail())
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
		filePatient.read((char*)&pt,sizeof(pt));
		while(!filePatient.eof())
		{
			if(tempId == pt.getID())
			{
				cover();
				ClearBG();
				gotoxy(77,5);
				foreColor(3);
				styleSearchPt();
				pt.Header(y);
				pt.Display(y + 2);
				foreColor(3);
				y += 3; 
				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t <<< Press to Continue >>>";
				getch();
				found = true;
			}
			filePatient.read((char*)&pt,sizeof(pt));
		}
		if(found == false)
		{
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
	}
	filePatient.close();
}

void UpdatePatient(string fileName_Path, int minAge, int maxAge = 100)
{
	setcursor(true, 1);
	filePatient.open(fileName_Path, ios::out | ios::in | ios::binary);
	bool found = false;
	if(filePatient.fail())
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
		filePatient.read((char*)&pt,sizeof(pt));
		while(!filePatient.eof())
		{
			if(updateid == pt.getID())
			{
				cover();
				ClearBG();
				pt.Input(minAge, maxAge);
				int lastread = filePatient.tellg(); 
				filePatient.seekp(lastread - sizeof(pt));
				filePatient.write((char*)&pt,sizeof(pt));
				found = true;
			}
			filePatient.read((char*)&pt, sizeof(pt));
		}
		setcursor(false, 1);
		if(found == false)
		{
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
		if(found == true)
		{
			cover();
			ClearBG();
			UpDateSuccess();
			delay(1500);
		}
	}
	filePatient.close();
}

void DeletePatient(string fileName_Path)
{
	setcursor(true, 1);
	filePatient.open(fileName_Path, ios::in | ios::binary);
	fstream backup;

	backup.open("Files\\Temp.bin", ios::out | ios::binary);
	
	bool found = false;
	if(filePatient.fail())
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
		setcursor(false, 1);
		filePatient.read((char*)&pt,sizeof(pt));
		while(!filePatient.eof())
		{
			if(deleteid == pt.getID())
			{
				found = true;
			}
			if(deleteid != pt.getID())
			{
				backup.write((char*)&pt, sizeof(pt));
			}
			filePatient.read((char*)&pt,sizeof(pt));
		}
		if(found == false)
		{
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
		if(found == true)
		{
			cover();
			ClearBG();
			DeleteSuccess();
			delay(1500);
		}
	}
	filePatient.close();
	backup.close();
	remove(fileName_Path.c_str());
	rename("Files\\Temp.bin", fileName_Path.c_str());
} 

//void invoiceTemplate(string); 

int countPatient0_17Y(); 
int countPatient17Y_45Y(); 
int countPatient45Y_UP(); 
int countSurgical();

void invoiceTemplate(string path){
	setcursor(true, 1);
	int y = 17; 
	int count = 0; 
	SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);

//    cout << currentTime.wYear << "-" << currentTime.wMonth << "-" << currentTime.wDay;
	
	if(path == "Files\\Patient17_45Y.bin"){
		count += countPatient0_17Y(); 
	}
	
	else if(path == "Files\\Patient45Y_UP.bin"){
		count = countPatient0_17Y() + countPatient17Y_45Y(); 
	}
	
	filePatient.open(path, ios::in | ios::binary);
	bool found = false;
	if(filePatient.fail())
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
		filePatient.read((char*)&pt,sizeof(pt));
		while(!filePatient.eof())
		{
			count++; 
			if(tempId == pt.getID())
			{
				ClearBG();
				cover(); 
				BoxDisplayInvoice();
				
				foreColor(2);
				gotoxy(28, 13); cout<<"Patient ID  "; gotoxy(50, 13); cout<<pt.getID(); 
				gotoxy(105, 13); cout<<"Invoice ID "; gotoxy(125, 13); cout<<"YTT-123-00"<<count++; 
				gotoxy(28, 15); cout<<"Patient Name "; gotoxy(50, 15); cout<<pt.getName(); 
				gotoxy(105, 15); cout<<"Address "; gotoxy(125, 15); cout<<pt.getAdd(); 
				gotoxy(28, 17); cout<<"Age "; gotoxy(50, 17); cout<<pt.getAge()<<" year"; 
				gotoxy(105, 17); cout<<"Date "; gotoxy(125, 17); cout<<pt.getDate();
			
				foreColor(2); gotoxy(29, 21); cout<<"NO"; gotoxy(38, 21); cout<<"Description"; gotoxy(131, 21); cout<<"Price"; 
				foreColor(2); gotoxy(29, 24); cout<<"1"; gotoxy(38, 24); cout<<pt.getDisease(); gotoxy(131, 24); cout<<"$"<<pt.getAmount(); 
				foreColor(2); gotoxy(29, 28); cout<<"2"; gotoxy(38, 28); cout<<"Service"; gotoxy(131, 28); cout<<"$"<<pt.getService(); 
				gotoxy(124, 31); cout<<"Total : $"<<pt.getAmount() + pt.getService(); 
				gotoxy(0, 32); cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t <<< Press to Continue >>>";
				getch();
				found = true;
				break; 
			}
			filePatient.read((char*)&pt,sizeof(pt));
		}
		if(found == false)
		{
			cover();
			ClearBG();
			NotFind();
			delay(1000);
		}
	}
	filePatient.close();
}

int countPatient0_17Y(){
	int count = 0; 
	filePatient.open("Files\\Patient0_17Y.bin", ios::in | ios::binary); 
	filePatient.read((char*)&pt, sizeof(pt)); 
	while(filePatient.eof() != true){
		count++; 
		filePatient.read((char*)&pt, sizeof(pt)); 
	}
	filePatient.close(); 
	return count; 
}

int countPatient17Y_45Y(){
	filePatient.open("Files\\Patient17_45Y.bin", ios::in | ios::binary); 
	int count = 0; 
	filePatient.read((char*)&pt, sizeof(pt)); 
	while(!filePatient.eof()){
		count++; 
		filePatient.read((char*)&pt, sizeof(pt)); 
	}
	filePatient.close(); 
	return count; 
}

int countPatient45Y_UP(){
	filePatient.open("Files\\Patient45Y_UP.bin", ios::in | ios::binary); 
	int count = 0; 
	filePatient.read((char*)&pt, sizeof(pt)); 
	while(!filePatient.eof()){
		count++; 
		filePatient.read((char*)&pt, sizeof(pt)); 
	}
	filePatient.close(); 
	return count; 
}

int AutoID(string fileName_Path, int no){
	fstream file; 
	int count = no; 
	file.open(fileName_Path, ios::in | ios::binary); 
	
	if(file.is_open()){
		file.read((char*)&pt, sizeof(pt)); 
		while(!file.eof()){
			count++; 
			file.read((char*)&pt, sizeof(pt)); 
		}
	}
	file.close(); 
	
	return count;
}

double getTotal(string path){
	filePatient.open(path, ios::in | ios::binary); 
	double total = 0; 
	filePatient.read((char*)&pt, sizeof(pt)); 
	while(!filePatient.eof()){
		total += (pt.getAmount() + pt.getService()); 
		filePatient.read((char*)&pt, sizeof(pt)); 
	}
	filePatient.close(); 
	return total; 
}


int countTotalPatients(string fileName_Path) 
{
    int totalCount = 0;
    filePatient.open(fileName_Path, ios::in | ios::binary);
    filePatient.seekg(0, ios::end);
    int fileSize = filePatient.tellg(); 
    int recordSize = sizeof(Patient);

    if(fileSize > 0) 
	{
        totalCount = fileSize / recordSize;
    }

    filePatient.close();
    return totalCount;
}

char* inputLetter(char* charArray, int n)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(index == n) continue; 
		else if(!(input>='a' && input<='z' || input>='A' && input<='Z' || input == 32 ))
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}

char* inputNumber(char* charArray, int n)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(index == n) continue; 
		else if(!(input>='0' && input<='9' || input == '.' || input == '-')  )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}

char* input4Tel(char* charArray, int n)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(index == n) continue; 
		else if(!(input>='0' && input<='9' || input == 32 || input == '+') )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}
#endif