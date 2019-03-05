#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
string Data_ram[35],Data_video[35],Filename,tmp;
int Data_Length,mod;

void data_right();
void data_print();
int main(){
	
	system("title \"C++滚屏 by Blocks233 QQ 3131421042\"");
	printf("待显示文件高度为32\n请前往http://www.orz6.com/lattice.aspx进行转换\n请输入文件名：(示例文件 data.txt)\n");
	scanf("%s",Filename.c_str());
	
	printf("请输入偏移量\n英文字符为1的倍数，中文字符为2的倍数\n偏移量越大速度越快\n");
	scanf("%d",&mod);
	
	ifstream Input;
	Input.open(Filename.c_str());
	for(int i=0;i<32;i++) {
		Data_ram[i]+="                                                 ";
		getline(Input,tmp);
		Data_ram[i]+=tmp;
	}
	Input.close();
	
	Data_Length=Data_ram[0].length();
	
	HWND hwnd=GetForegroundWindow();
	ShowWindow(hwnd,SW_MAXIMIZE);
	
	printf("按任意键开始滚屏\n");
	system("pause > nul");
	system("cls");
	system("color 4");
	
	while(1){
		
		for(int i=0;i<32;i++) Data_video[i]=Data_ram[i].data();
		for(int i=0;i<Data_Length/mod;i++){
			data_right();
			data_print();
			Sleep(50);
			system("cls");
		}
		
		for(int i=0;i<32;i++) Data_video[i]="\0";
		for(int i=0;i<32;i++){
			Data_video[i]=Data_ram[i].data();
			data_print();
			Sleep(200);
			system("cls");
		}
		
		
		for(int i=0;i<32;i++) Data_video[i]="\0";
		for(int i=0;i<32;i++){
			for(int j=31;j>0;j--) Data_video[j]=Data_video[j-1].data();
			Data_video[0]=Data_ram[32-1-i].data();
			data_print();
			Sleep(200);
			system("cls");
		}
		
	}
} 


void data_right(){
	for(int i=0;i<32;i++) Data_video[i][Data_Length]=' ';
	for(int k=0;k<mod;k++){
		for(int i=0;i<32;i++)
			for(int j=0;j<Data_Length;j++){
				Data_video[i][j]=Data_video[i][j+1];
			}
	}
}


void data_print(){
	for(int i=0;i<32;i++)	printf("%s\n",Data_video[i].data());
}
