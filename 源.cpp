#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void showStyle()
{

	system("color f3");
	system("title ����С����");
}
char userData[10000] = "";
void inputUserData()
{
	memset(userData, 0, 10000);//��ʼ��userdata����0���Ƹ�ǰ10000���ַ�; 
	printf("������ѧ����Ϣ��");
	gets_s(userData);
	//gets_s(userData); 
}

int main() {//�շѰ���վ̨��Ŀ����; 

	showStyle();
	//�����ı�
	inputUserData();
	//����vbs�ļ�
	FILE* fp = fopen("voice.vbs", "w");
	//д��CreteObject("SAPI.SpVoice"),Speak("�û����������")��
	fprintf(fp, "CreateObject(\"SAPI.SpVoice\").Speak(\"��ӭ%sͬѧ��������\")", userData);
	FILE* f = fopen("D:\\0.txt", "w+");
	fprintf(f, userData);//��userdata�ŵ�f�� 











	fclose(f);
	fclose(fp);//�ر��ļ�;
	system("voice.vbs"); //������ȡvbs�ļ�
	return 0;
}
