#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  uint64_t *heap = new uint64_t;
  uint64_t stackvar;

  uint64_t diff = &stackvar - heap;
  float distance = diff / (1024 * 1024 * 1024);
  printf("distance = %.2f GB\n", distance);
  free(heap);

  return 0;
}