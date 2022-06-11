#include <stdio.h>
#include <stdlib.h>
#include "ecs.h"

void iter(component *c) {
}

int main(int argc, char* argv[]) {
  CS_INIT(cs);
  COMPONENT(POSITION_T, pos, POSITION(6, 9));
  cs_add(cs, pos);
  cs_iter(cs, iter);
  return 0;
}
