#include "ecsj.h"

#define __DEF_CALLOC 4
#define EXPAND(x) x+5

static unsigned long __last_id = 0;

ecsj_component __component(unsigned int type, void *data, unsigned long size) {
  ecsj_component _c = (ecsj_component) {
    type,
    NULL,
  };
  _c.content = malloc(size);
  memcpy(_c.content, data, size);
  return _c;
}

ecsj_entity __entity() {
  ecsj_entity e = {
    __last_id++,
  };
  e.components = malloc(sizeof(ecsj_component) * __DEF_CALLOC);
  e.__allocated = __DEF_CALLOC;
  e.len = 0;
  return e;
}

// private
void ecsj_entity_expand(ecsj_entity *e) {
  if (e->len == e->__allocated) {
    unsigned short new_alloc = EXPAND(e->__allocated);
    e->components = realloc(e->components, sizeof(ecsj_component)*new_alloc);
    e->__allocated = new_alloc;
  }
}

// public
void ecsj_entity_add_component(ecsj_entity *e, ecsj_component component) {
  e->components[e->len] = component;
  e->len++;
  ecsj_entity_expand(e);
}

void ecsj_entity_on_component_of_type(ecsj_entity *e, unsigned int type, void (*func)(ecsj_component* component)) {
  for (unsigned short i=0; i<e->len; i++) {
    if (e->components[i].type == type) {
      func(&e->components[i]);
    }
  }
}
