#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int N = 10000;
const int M = 5000;
typedef long ll;
ll orig[N][M];
ll img[N][M];


void init(ll img[][M]) {
	ll t = 12345678;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			img[i][j] = t++;
		}
}

void f0(ll img[][M]) {
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4 ;
			}
		}
}

void f1(ll img[][M]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4 ;
			}
		}
}

void f2(ll img[][M]) {
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) >> 2 ;
			}
		}
}

void f3(ll img[][M]) { //循环展开
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < M; i += 2) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4;
				img[i + 1][j] = (img[i][j] + img[i + 2][j] + img[i + 1][j - 1] + img[i + 1][j + 1]) / 4;
			}
		}
	}
}

void success(ll img[][M]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j += 2) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) >> 2;
				img[i][j] = (img[i - 1][j + 1] + img[i + 1][j + 1] + img[i][j] + img[i][j + 2]) >> 2;
			}
		}

}

void pc(ll img[][M]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j += 4) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				continue;
			} else {
				img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) >> 2;
				img[i][j] = (img[i - 1][j + 1] + img[i + 1][j + 1] + img[i][j] + img[i][j + 2]) >> 2;
				img[i][j] = (img[i - 1][j + 2] + img[i + 1][j + 2] + img[i][j + 1] + img[i][j + 3]) >> 2;
				img[i][j] = (img[i - 1][j + 3] + img[i + 1][j + 3] + img[i][j + 2] + img[i][j + 4]) >> 2;
			}
		}
}

int main() {
	clock_t t1, t2;
	init(orig);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	f0(img);
	t2 = clock();
	printf("初始程序：%ld\n", t2 - t1);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	f1(img);
	t2 = clock();
	printf("按行读取：%ld\n", t2 - t1);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	f2(img);
	t2 = clock();
	printf("除法改为位运算：%ld\n", t2 - t1);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	f3(img);
	t2 = clock();
	printf("循环展开：%ld\n", t2 - t1);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	success(img);
	t2 = clock();
	printf("最优：%ld\n", t2 - t1);

	memcpy(img, orig, sizeof(orig));
	t1 = clock();
	pc(img);
	t2 = clock();
	printf("个性化：%ld\n", t2 - t1);
	return 0;
}