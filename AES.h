#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define Nr 10



uint8_t gmul(uint8_t a, uint8_t b);
void ShiftLeft(uint8_t *str, uint8_t base);
void ShiftRight(uint8_t *str, uint8_t base);
void RoundKey(uint8_t *key, uint8_t *word);
void AddRoundKey(uint8_t *state, uint8_t *word, uint8_t r);
void SubByte(uint8_t *state);
void RowShift(uint8_t *state);
void MixColumn(uint8_t *state);
void Cipher(char *orig, char *encry, uint8_t *word);
void InvSubByte(uint8_t *state);
void InvRowShift(uint8_t *state);
void InvMixColumn(uint8_t *state);
void AntiCipher(char *encry, char *orig, uint8_t *word);
