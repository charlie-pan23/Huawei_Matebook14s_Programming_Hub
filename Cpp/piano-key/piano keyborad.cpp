#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#define M1 Beep(523,200);
#define M2 Beep(587,200);
#define M3 Beep(659,200);
#define M4 Beep(698,200);
#define M5 Beep(784,200);
#define M6 Beep(880,200);
#define M7 Beep(980,200);
//����
#define L1 Beep(262,200);
#define L2 Beep(294,200);
#define L3 Beep(330,200);
#define L4 Beep(349,200);
#define L5 Beep(392,200);
#define L6 Beep(440,200);
#define L7 Beep(493,200);
//����
#define N1 Beep(532,200);
#define N2 Beep(588,200);
#define N3 Beep(660,200);
#define N4 Beep(698,200);
#define N5 Beep(784,200);
#define N6 Beep(880,200);
#define N7 Beep(988,200);
//������
#define H1 Beep(1046,200);
#define H2 Beep(1175,200);
#define H3 Beep(1319,200);
#define H4 Beep(1397,200);
#define H5 Beep(1568,200);
#define H6 Beep(1760,200);
#define H7 Beep(1976,200);
#define N 1000      //���׵�����
 
using namespace std;
 
int music[N];
int mcount = 0;
 
void play();        //����
void readMusic();   //��ȡ����
void playMusic();   //��������
void menu();        //�˵�
 
//�˵�
void menu(){
int choice;
    do
    {
        cout<<"------------------------------"<<endl;
        cout<<"0���˳�"<<endl;
        cout<<"1������(1-7)"<<endl;
        cout<<"2����������"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"������ѡ��:"<<endl;
        scanf("%d",&choice);        //����choice��ֵѡȡ����
        switch(choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            system("cls");
            cout<<"��ESC������һ��"<<endl;
            play();
            break;
        case 2:
            system("cls");
            playMusic();
            break;
        default:
            cout<<"�������!"<<endl;
        }
        system("pause");
        system("cls");
    }
    while(choice != 0);
}
 
//��ȡ����
void readMusic(){
    int i=0;
    FILE * fp;
    fp=fopen("music.txt","a+");      //��ֻ����ʽ���ļ���
    if(fp==NULL){
        cout<<"�ļ���ʧ��!"<<endl;
        exit(0);
    }
    //��ȡ���ṹ������
    while(!feof(fp)){
        fscanf(fp,"%d",&music[i]);
        i++;
    }
    mcount = i;     //��ȡ���ŵ���������
    fclose(fp);
}
 
//��������
void playMusic(){
    int i;
    for(i = 0;i < mcount;i++){
        Sleep(100);
        printf("%d ",music[i]);
        switch(music[i])
        { 
            case 1:H1;break;
            case 2:H2;break;
            case 3:H3;break;
            case 4:H4;break;
            case 5:H5;break;
            case 6:H6;break;
            case 7:H7;break;
        }
        Sleep(100);
	}
}
 
 
//����
void play(){
    char ch;
	while(1)
	{
		if(kbhit())
		{
 
			ch = getch();
			switch(ch)
			{
				case '1':H1;break;
				case '2':H2;break;
				case '3':H3;break;
				case '4':H4;break;
				case '5':H5;break;
				case '6':H6;break;
				case '7':H7;break;
				case '\033':return;
			}
		}
	}
}
 
int main()
{
    readMusic();
    menu();
}
 

