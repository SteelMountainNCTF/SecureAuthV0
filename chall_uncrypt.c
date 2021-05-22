#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *s2 = "c-n|TD^zJFp|I'q\"VCj7.mNj4"; // idb
char *off_49CA050 = "f4|<eN3w$"; // weak

static int64_t reverse(char * xs, int xlen) {
  int64_t v3x3, v3x4, v3x5, v3x6;
  for ( v3x6 = 0; v3x6 < (xlen / 2); ++v3x6 ) {
    // swaps xs[v3x6] and xs[xlen - 1 - v3x6]
    char v3x13 = xs[v3x6];
    xs[v3x6] = xs[xlen - 1 - v3x6];
    xs[xlen - 1 - v3x6] = v3x13;
  }
  return xlen / 2;
}

static void chall_transform(char * xs, int xlen, char (*trf)(int, char)) {
  for (int i = 0; i < xlen; ++i )
    xs[i] = trf(i, xs[i] - 33) % 95 + 33;
}

static char chall_key2elem(int i) {
  return off_49CA050[i % 4] - 33;
}

static char chall_crypt_trf(int i, char x) {
  return x + chall_key2elem(i);
}

static char chall_uncrypt_trf(int i, char y) {
  return y - chall_key2elem(i);
}

int main(int argc, char **argv, char **env) {
  char v4[65] = {0};
  strncpy(v4, s2, 64);
  const int xlen = strlen(v4);
  reverse(v4, xlen);
  write(1, v4, xlen);
  write(1, "\n", 1);
  chall_transform(v4, xlen, chall_uncrypt_trf);
  write(1, v4, xlen);
  write(1, "\n", 1);
  chall_transform(v4, xlen, chall_crypt_trf);
  write(1, v4, xlen);
  write(1, "\n", 1);

  return 0;
}
