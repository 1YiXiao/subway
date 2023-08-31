#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showStyle() {
	system("color f3");
	system("title ģ�����");
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
	FILE* stationFile = fopen("C:\\Users\\��\\Desktop\\station.txt", "r");
	if (stationFile == NULL) {
		printf("�޷���վ����Ϣ�ļ���\n");
		return 1;
	}

	for (int i = 0; i < 5; ++i) {
		if (fscanf(stationFile, "%s", stations[i].name) != 1) {
			printf("�޷���ȡվ����Ϣ��\n");
			fclose(stationFile);
			return 1;
		}
	}
	fclose(stationFile);

	char className[50];
	char studentName[50];
	int studentID;
	printf("������༶��");
	scanf("%s", className);
	printf("������������");
	scanf("%s", studentName);
	printf("������ѧ�ţ�");
	scanf("%d", &studentID);

	char welcomeText[100];
	sprintf(welcomeText, "��ӭ%sͬѧ����������", studentName);
	textToSpeech(welcomeText);
	printf("%s\n", welcomeText);

	printf("վ����Ϣ��\n");
	for (int i = 0; i < 5; ++i) {
		printf("��%dվ��%s\n", i + 1, stations[i].name);
	}

	char startStationName[50], endStationName[50];
	int startStation = -1, endStation = -1;

	printf("��������ʼվ�����ƣ�");
	scanf("%s", startStationName);
	for (int i = 0; i < 5; ++i) {
		if (strcmp(startStationName, stations[i].name) == 0) {
			startStation = i;
			break;
		}
	}

	printf("���������վ�����ƣ�");
	scanf("%s", endStationName);
	for (int i = 0; i < 5; ++i) {
		if (strcmp(endStationName, stations[i].name) == 0) {
			endStation = i;
			break;
		}
	}

	if (startStation == -1 || endStation == -1) {
		printf("��Ч��վ�����ơ�\n");
		return 1;
	}

	// Play announcement for each station
	for (int i = startStation; i <= endStation; ++i) {
		char announcement[100];
		sprintf(announcement, "��%dվΪ%s��", i + 1, stations[i].name);
		textToSpeech(announcement);
		printf("%s\n", announcement);

		// Wait for user to press Enter
		printf("���س���������һվ...");
		getchar();  // Consume the newline character
		getchar();  // Wait for Enter key press
	}

	float totalFare = (endStation - startStation) * 1.0;
	char fareAnnouncement[100];
	sprintf(fareAnnouncement, "%sͬѧ����������ϣ����ù�%.2fԪ��", studentName, totalFare);
	textToSpeech(fareAnnouncement);
	printf("%s\n", fareAnnouncement);

	// Export student information
	char exportPath[100];
	sprintf(exportPath, "C:\\Users\\��\\Desktop\\ͬѧ��Ϣ\\%s.txt", studentName);
	FILE* exportFile = fopen(exportPath, "w");
	if (exportFile != NULL) {
		fprintf(exportFile, "�༶��%s\n������%s\nѧ�ţ�%d\n", className, studentName, studentID);
		fclose(exportFile);
		printf("ͬѧ��Ϣ�ѵ�������%s\n", exportPath);
	}
	else {
		printf("�޷�����ͬѧ��Ϣ��\n");
	}


	return 0;
}
