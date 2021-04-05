#include "AES.h"


int main(int argc, char *argv[]) {
	uint8_t *word;
	char *orig, *encry, c; 
	uint8_t i, x, j, flag = 1, n;
	FILE *fp1, *fp2;

	if((argc != 4) || (argc == 2 && !strcmp(argv[1], "-h"))) {
		printf("for help:\n  ./project -h\n");
		printf("for encryption:\n  Usage: ./project -e <filename1> <filename2>\n");
		printf("    filename1: file to be encrypted\n    filename2: encrypted file\n");
		printf("for decryption:\n  Usage: ./project -d <filename1> <filename2>\n");
		printf("    filename1: file to be decrypted\n    filename2: decrypted file\n");
		return 0;
	}

	/*
	 *128 bit key used for encryption and decryption
	 */
	uint8_t key[16] = {
		0x00, 0x01, 0x02, 0x03,
		0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b,
		0x0c, 0x0d, 0x0e, 0x0f};
	
	/*
	 *w is array of words
	 *each word consist of 4 Bytes
	 *total words = (10 + 1) * 4
	 */
	word = malloc(4 * (Nr + 1) * sizeof(int) * 4);
	orig = (char*)malloc(sizeof(char) * 16);
	encry = (char*)malloc(sizeof(char) * 16);

	/*
	 *Generation of round keys
	 */
	RoundKey(key, word);
	
	if(!strcmp(argv[1], "-e")) {
		fp1 = fopen(argv[2], "r");
		fp2 = fopen(argv[3], "w");
		if(!fp1) {
			printf("Open Failed\n");
			return 0;
		}
		do {
			for(i = 0; i < 16; i++) {
				if((x = fscanf(fp1, "%c", &c) != EOF)) {
					orig[i] = c;
				}
				else {
					c = (16 - i) + '0';
					for(j = i; j < 16; j++) {
						orig[j] = c;
					}
					flag = 0;
					break;
				}
			}
			Cipher(orig, encry, word);
			for(i = 0; i < 16; i++) {
				fprintf(fp2, "%c", encry[i]);
			}
		} while(x);
		if(flag) {
			for(i = 0; i < 16; i++)
				orig[i] = '0';
			Cipher(orig, encry, word);
			for(i = 0; i < 16; i++) {
				fprintf(fp2, "%c", encry[i]);
			}
		}
		free(word);
		free(orig);
		free(encry);
		fclose(fp1);
		fclose(fp2);
		return 0;

	}

	else if(!strcmp(argv[1], "-d")) {
		fp1 = fopen(argv[2], "r");
		fp2 = fopen(argv[3], "w");

		if(!fp1) {
			printf("Open Failed\n");
			return 0;
		}

		while(1) {
			for(i = 0; i < 16; i++) {
				if((x = fscanf(fp1, "%c", &c) != EOF)) {
					encry[i] = c;
				}
			}
			if((x = fscanf(fp1, "%c", &c) == EOF)) {
				AntiCipher(encry, orig, word);				
				n = orig[15] - '0';
				
				for(i = 0; i < (16 - n); i++) {
					fprintf(fp2, "%c", orig[i]);
				}
				break;
			}
			else {
				fseek(fp1, -1, SEEK_CUR);
				AntiCipher(encry, orig, word);
				for(i = 0; i < 16; i++) {
					fprintf(fp2, "%c", orig[i]);
				}
			}
		}
		
		free(word);
		free(orig);
		free(encry);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	else {
		printf("for help:\n  ./project -h\n");
		printf("for encryption:\n  Usage: ./project -e <filename1> <filename2>\n");
		printf("    filename1: file to be encrypted\n    filename2: encrypted file\n");
		printf("for decryption:\n  Usage: ./project -d <filename1> <filename2>\n");
		printf("    filename1: file to be decrypted\n    filename2: decrypted file\n");
		return 0;

	}
}