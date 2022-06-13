#pragma once
#include <string.h>
#include <stdlib.h>

typedef struct {
  unsigned int type;
  void *content;
} ecsj_component;

typedef struct {
  unsigned long id;
  ecsj_component* components;
  unsigned short len;
  unsigned short __allocated;
} ecsj_entity;

ecsj_component __component(unsigned int type, void *data, unsigned long size);
ecsj_entity __entity();

#define ECSJ_ENTITY() __entity()
#define ECSJ_COMPONENT(datatype, type, data) _component(type, &data, sizeof(datatype))
