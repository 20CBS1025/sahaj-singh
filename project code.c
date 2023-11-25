#include <stdio.h>
#include <string.h>

#define KEY "my_secret_key" // Replace with a strong, secure key
#define CIPHER_TEXT_SIZE 1024

void encrypt(char *plaintext, char *ciphertext) {
  int i, keyLength = strlen(KEY);

  for (i = 0; plaintext[i] != '\0'; i++) {
    ciphertext[i] = plaintext[i] ^ KEY[(i % keyLength)];
  }
  ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
  int i, keyLength = strlen(KEY);

  for (i = 0; ciphertext[i] != '\0'; i++) {
    plaintext[i] = ciphertext[i] ^ KEY[(i % keyLength)];
  }
  plaintext[i] = '\0';
}

int main() {
  char message[] = "This is a confidential message";
  char encryptedMessage[CIPHER_TEXT_SIZE];
  char decryptedMessage[CIPHER_TEXT_SIZE];

  // Encrypt the message
  encrypt(message, encryptedMessage);
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the message
  decrypt(encryptedMessage, decryptedMessage);
  printf("Decrypted message: %s\n", decryptedMessage);

  return 0;
}