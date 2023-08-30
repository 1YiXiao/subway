#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void showStyle()
{

	system("color f3");
	system("title 发音小程序");
}
char userData[10000] = "";
void inputUserData()
{
	memset(userData, 0, 10000);//初始化userdata，将0复制给前10000个字符; 
	printf("请输入学生信息：");
	gets_s(userData);
	//gets_s(userData); 
}

int main() {//收费按照站台数目计算; 

	showStyle();
	//输入文本
	inputUserData();
	//生产vbs文件
	FILE* fp = fopen("voice.vbs", "w");
	//写入CreteObject("SAPI.SpVoice"),Speak("用户输入的内容")；
	fprintf(fp, "CreateObject(\"SAPI.SpVoice\").Speak(\"欢迎%s同学乘坐地铁\")", userData);
	FILE* f = fopen("D:\\0.txt", "w+");
	fprintf(f, userData);//把userdata放到f里 











	fclose(f);
	fclose(fp);//关闭文件;
	system("voice.vbs"); //语音读取vbs文件
	return 0;
}
