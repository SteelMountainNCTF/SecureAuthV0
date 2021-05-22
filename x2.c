#include <stdio.h>
#include <unistd.h>
#include <string.h>

const char *s2   = "4jNm.7jCV\"q'I|pFJz^DT|n-c";
const char *flgt = "NORZH{                  }";

const char offs[4] = { 69, 19, 91, 27 };
const int offs2[4] = { 26, 68, 4, 76 };

int main() {
  const int slen = strlen(s2);
  for(int j = 0; j < slen; ++j) {
    char tmp = ((s2[j] - 33) + offs2[j % 4]) % 95 + 33;
    //fprintf(stderr, "%d: '%c' vs '%c' vs '%c'\n", j, s2[j], flgt[j], tmp);
    write(1, &tmp, 1);
  }
  write(1, "\n", 1);
  //for(int j = 0; j < slen; ++j) {
    //fprintf(stderr, "%d: '%c' vs. '%c' = (%c-%c) %d vs. %d\n", j, s2[j], flgt[j], flgt[j], s2[j], (flgt[j] - s2[j] + 95) % 95, offs2[j%4]);
  //}
  return 0;
}
