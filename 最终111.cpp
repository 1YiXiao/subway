#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showStyle() {
	system("color f3");
	system("title 模拟地铁");
}

void textToSpeech(const char* text) {
	char command[500];
	sprintf(command, "CreateObject(\"SAPI.SpVoice\").Speak(\"%s\")", text);
	FILE* fp = fopen("voice.vbs", "w");
	if (fp != NULL) {
		fprintf(fp, "%s", command);
		fclose(fp);
	}
	system("voice.vbs");
}

int main() 
{
	showStyle();
	struct Station {
		char name[50];
	};

	struct Station stations[5];
	FILE* stationFile = fopen("C:\\Users\\闫\\Desktop\\station.txt", "r");
	if (stationFile == NULL) {
		printf("无法打开站点信息文件。\n");
		return 1;
	}

	for (int i = 0; i < 5; ++i) {
		if (fscanf(stationFile, "%s", stations[i].name) != 1) {
			printf("无法读取站点信息。\n");
			fclose(stationFile);
			return 1;
		}
	}
	fclose(stationFile);

	char className[50];
	char studentName[50];
	int studentID;
	printf("请输入班级：");
	scanf("%s", className);
	printf("请输入姓名：");
	scanf("%s", studentName);
	printf("请输入学号：");
	scanf("%d", &studentID);

	char welcomeText[100];
	sprintf(welcomeText, "欢迎%s同学乘坐地铁。", studentName);
	textToSpeech(welcomeText);
	printf("%s\n", welcomeText);

	printf("站点信息：\n");
	for (int i = 0; i < 5; ++i) {
		printf("第%d站：%s\n", i + 1, stations[i].name);
	}

	char startStationName[50], endStationName[50];
	int startStation = -1, endStation = -1;

	printf("请输入起始站点名称：");
	scanf("%s", startStationName);
	for (int i = 0; i < 5; ++i) {
		if (strcmp(startStationName, stations[i].name) == 0) {
			startStation = i;
			break;
		}
	}

	printf("请输入结束站点名称：");
	scanf("%s", endStationName);
	for (int i = 0; i < 5; ++i) {
		if (strcmp(endStationName, stations[i].name) == 0) {
			endStation = i;
			break;
		}
	}

	if (startStation == -1 || endStation == -1) {
		printf("无效的站点名称。\n");
		return 1;
	}

	// Play announcement for each station
	for (int i = startStation; i <= endStation; ++i) {
		char announcement[100];
		sprintf(announcement, "第%d站为%s。", i + 1, stations[i].name);
		textToSpeech(announcement);
		printf("%s\n", announcement);

		// Wait for user to press Enter
		printf("按回车键继续下一站...");
		getchar();  // Consume the newline character
		getchar();  // Wait for Enter key press
	}

	float totalFare = (endStation - startStation) * 1.0;
	char fareAnnouncement[100];
	sprintf(fareAnnouncement, "%s同学地铁乘坐完毕，费用共%.2f元。", studentName, totalFare);
	textToSpeech(fareAnnouncement);
	printf("%s\n", fareAnnouncement);

	// Export student information
	char exportPath[100];
	sprintf(exportPath, "C:\\Users\\闫\\Desktop\\同学信息\\%s.txt", studentName);
	FILE* exportFile = fopen(exportPath, "w");
	if (exportFile != NULL) {
		fprintf(exportFile, "班级：%s\n姓名：%s\n学号：%d\n", className, studentName, studentID);
		fclose(exportFile);
		printf("同学信息已导出至：%s\n", exportPath);
	}
	else {
		printf("无法导出同学信息。\n");
	}


	return 0;
}
