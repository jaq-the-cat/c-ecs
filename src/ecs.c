#include "ecs.h"
#include <stdlib.h>
#include <stdio.h>

component_t component(uint16_t type, void *data, unsigned long size) {
  printf("data: %p\n", data);
  component_t _c = (component_t) {
    type,
    NULL,
  };
  _c.content = malloc(sizeof(data));\
  memcpy(_c.content, data, size);
  return _c;
}
