#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define CS_INIT(cs)\
  components *cs;\
  cs = malloc(sizeof(components));\
  cs->c = (component) {nope_T, NULL};\
  cs->next = NULL;

typedef struct { double x, y; } point;

typedef struct {
  uint16_t type;
  void *content;
} component;

typedef struct components_node {
  component c;
  struct components_node *next;
} components;

void cs_add(components *cs, component c);
void cs_iter(components *cs, void (*func)());
component c_create(uint16_t type, void *data, unsigned long size);
