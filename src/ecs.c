#include "ecs.h"

component_t _component(unsigned int type, void *data, unsigned long size) {
  component_t _c = (component_t) {
    type,
    NULL,
  };
  _c.content = malloc(size);
  memcpy(_c.content, data, size);
  return _c;
}
