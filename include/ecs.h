#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef struct {
  uint16_t type;
  void *content;
} component_t;

component_t _component(uint16_t type, void *data, unsigned long size);
#define COMPONENT(datatype, type, data) _component(type, &data, sizeof(datatype))
