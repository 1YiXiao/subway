#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����վ����Ϣ�ͳ˳����ýṹ��
struct Station {
    char name[50];
    double fare;
};

// �������ڲ���������Ϣ
void textToSpeech(const char* text) {
    // ���� TTS ����������ı�ת��Ϊ��������
}

int main() {
    // ���ļ�����ȡվ����Ϣ�ͷ���
    FILE* stationFile = fopen("վ��.txt", "r");
    if (stationFile == NULL) {
        printf("�޷���վ����Ϣ�ļ���\n");
        return 1;
    }

    struct Station stations[3]; // ������3��վ��
    for (int i = 0; i < 3; i++) {
        fscanf(stationFile, "%s %lf", stations[i].name, &stations[i].fare);
    }
    fclose(stationFile);

    // ¼��˳�ͬѧ��Ϣ
    char studentInfo[100];
    printf("������༶��������ѧ�ţ�");
    fgets(studentInfo, sizeof(studentInfo), stdin);
    studentInfo[strcspn(studentInfo, "\n")] = '\0'; // ȥ�����з�

    // ������ӭ��Ϣ
    printf("��ӭ%sͬѧ����������\n", studentInfo);
    textToSpeech("��ӭ");
    textToSpeech(studentInfo);
    textToSpeech("ͬѧ����������");

    // ģ��˳�����
    printf("�˳����̿�ʼ��\n");
    for (int i = 0; i < 3; i++) {
        printf("����վ�㣺%s\n", stations[i].name);
        // ������������ʾ����վ��

        if (i < 2) {
            printf("����ǰ����һվ��\n");
            // ������������ʾ����ǰ����һվ
        }
    }

    // ���㲢����������Ϣ
    double totalFare = stations[2].fare; // ������ʼվ�����Ϊ��һ��վ��ķ���
    printf("%sͬѧ����������ϣ����ù�%.2lfԪ��\n", studentInfo, totalFare);
    textToSpeech(studentInfo);
    textToSpeech("ͬѧ����������ϣ����ù�");
    // ��������������������Ϣ

    return 0;
}
