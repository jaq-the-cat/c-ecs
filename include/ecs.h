#pragma once
#include <stdbool.h>

typedef enum {
  POSITION,
  COLLIDER,
  HOMOSEXUALITY
} component_type;

// Declare components
typedef struct {
  double x, y;
} position;

typedef struct {
  double x, y;
  union {
    double h, w;
    double radius;
  } size; 
} collider;

typedef struct {
  double level;
  double breastsize;
  bool femboy;
  bool dragqueen;
  bool haspussy;
} homosexuality;

typedef struct {
  component_type type;
  void *content;
} component;

typedef struct components_node {
  component *c;
  struct components_node *next;
} components;

#define C_INIT(cs)\
  cs = malloc(sizeof(components));\
  cs->c = NULL;\
  cs->next = NULL;

void c_add(components *cs, component c);
void c_delete(components *cs, component *c);
void c_iter(components *cs, void (*func)());
