#pragma once
#include <string.h>
#include <stdlib.h>

typedef struct {
  unsigned int type;
  void *content;
} component_t;

component_t _component(unsigned int type, void *data, unsigned long size);
#define COMPONENT(datatype, type, data) _component(type, &data, sizeof(datatype))
