#pragma once
#include <stdbool.h>
#include <string.h>

#define CS_INIT(cs)\
  components *cs;\
  cs = malloc(sizeof(components));\
  cs->c = (component) {nope_T, NULL};\
  cs->next = NULL;

#define COMPONENT(type, name, data)\
  component name = (component) {\
    type,\
    NULL,\
  };\
  name.content = malloc(sizeof(data));\
  memcpy(name.content, &data, sizeof(data));

#define P(x, y) (point) {x, y}

#define CIRC_COLLIDER(root, r) (collider) {root, {.radius=r}}

#define RECT_COLLIDER(root, width, height) (collider) {root, {.wh={width, height}}}

typedef enum {
  nope_T,
  POSITION_T,
  COLLIDER_T,
  HOMOSEXUALITY_T
} component_type;

typedef struct { double x, y; } point;

// Declare components
typedef point position;

typedef struct {
  position root;
  union {
    position wh;
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
  component c;
  struct components_node *next;
} components;

void cs_add(components *cs, component c);
void cs_iter(components *cs, void (*func)());
