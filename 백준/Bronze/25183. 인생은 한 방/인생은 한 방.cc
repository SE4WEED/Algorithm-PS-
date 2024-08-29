#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[100010];
int main() {
	int t;
	scanf("%d", &t);
	scanf("%s", str);
	int max = 1;
	int cont = 1;
	for (int i = 1; i < t; i++) {
		if (str[i - 1] - str[i] == 1 || str[i - 1] - str[i] == -1) {
			cont++;
			if (max < cont)max = cont;
		}
		else {
			cont = 1;
		}
	}
	if (max >= 5){
		printf("YES\n");
	}else {
		printf("NO\n");
	}
	return 0;
}