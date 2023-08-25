#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义站点信息和乘车费用结构体
struct Station {
    char name[50];
    double fare;
};

// 函数用于播报语音信息
void textToSpeech(const char* text) {
    // 调用 TTS ，将传入的文本转换为语音播放
}

int main() {
    // 打开文件并读取站点信息和费用
    FILE* stationFile = fopen("站点.txt", "r");
    if (stationFile == NULL) {
        printf("无法打开站点信息文件。\n");
        return 1;
    }

    struct Station stations[3]; // 假设有3个站点
    for (int i = 0; i < 3; i++) {
        fscanf(stationFile, "%s %lf", stations[i].name, &stations[i].fare);
    }
    fclose(stationFile);

    // 录入乘车同学信息
    char studentInfo[100];
    printf("请输入班级、姓名和学号：");
    fgets(studentInfo, sizeof(studentInfo), stdin);
    studentInfo[strcspn(studentInfo, "\n")] = '\0'; // 去除换行符

    // 播报欢迎信息
    printf("欢迎%s同学乘坐地铁。\n", studentInfo);
    textToSpeech("欢迎");
    textToSpeech(studentInfo);
    textToSpeech("同学乘坐地铁。");

    // 模拟乘车过程
    printf("乘车过程开始：\n");
    for (int i = 0; i < 3; i++) {
        printf("到达站点：%s\n", stations[i].name);
        // 播放语音，提示到达站点

        if (i < 2) {
            printf("继续前往下一站。\n");
            // 播放语音，提示继续前往下一站
        }
    }

    // 计算并播报费用信息
    double totalFare = stations[2].fare; // 假设起始站点费用为第一个站点的费用
    printf("%s同学地铁乘坐完毕，费用共%.2lf元。\n", studentInfo, totalFare);
    textToSpeech(studentInfo);
    textToSpeech("同学地铁乘坐完毕，费用共");
    // 播放语音，播报费用信息

    return 0;
}
