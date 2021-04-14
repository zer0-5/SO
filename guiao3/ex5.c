#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  for(int i = 1; i < argc; ++i) {
    if(!fork())
      execlp(argv[i], argv[i], NULL);
  }

  for(int i = 1; i < argc; ++i)
    wait(NULL);

  return 0;
}
