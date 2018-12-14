
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int y = 0, ml = 0, wl, i, counter, z, N;
	char c;
	char oa[100], word[50];
	FILE *f;
	printf("\n give the file's name: ");
	gets(oa);
	f = fopen(oa, "r");
	while (!feof(f)) {
		c = fgetc(f);
		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'z'))
			if (ml == 0) {
				y++;
				ml = 1;//ml=1 -> in word .ml=0 -> out word
			}
			else {
				ml = 1;
			}
		else
			ml = 0;
	}
	fclose(f);
	printf("\nhow much words you wanna search: ");
	scanf("%d", &N);
	for (z = 0; z < N; z++) {
		f = fopen(oa, "r");
		printf("\n give the word you want to search: ");
		scanf("%s", word);
		counter = 0;
		wl = strlen(word); //wl=="word length
		while (!feof(f)) {
			c = fgetc(f);
			if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'z'))
				if (ml == 0 && word[0] == c) {
					ml = 1;
					i = 1;
					while (word[i] == (c = fgetc(f)) && i < wl) {
						i++;
						if (i == wl - 1) {
							counter++;
						}
					}
				}
				else {
					ml = 0;
				}
		}
		printf("\nh this file have %d words  ", y);
		printf("\nthe word '%s' is mentioned in the text %d times\n", word,counter);
	}
	fclose(f);
	return 0;
}