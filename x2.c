#include <stdio.h>
#include <unistd.h>
#include <string.h>

const char *s2   = "4jNm.7jCV\"q'I|pFJz^DT|n-c";
const char *flgt = "NORZH{                   }";

const char offs[4] = { 69, 19, 91, 27 };

int main() {
  const int slen = strlen(s2);
  for(int i = 0; i < 95; ++i) {
    fprintf(stderr, "%d:\n", i);
    for(int j = 0; j < slen; ++j) {
      char tmp = (i + (s2[j] - 33) - 0* offs[j % 4]) % 95 + 33;
      write(1, &tmp, 1);
    }
    write(1, "\n", 1);
  }
  for(int j = 0; j < slen; ++j) {
    fprintf(stderr, "%d: '%c' vs. '%c' = (%c-%c) %d\n", j, s2[j], flgt[j], flgt[j], s2[j], flgt[j] - s2[j]);
  }
  return 0;
}
