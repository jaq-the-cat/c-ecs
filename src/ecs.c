#include "ecs.h"
#include <stdlib.h>
#include <stdio.h>

void cs_add(components *cs, component c) {
  if (cs->c.type == 0) {
    cs->c = c;
    return;
  }

  components *csi;
  for (csi=cs; csi->next != NULL; csi=csi->next);

  csi->next = malloc(sizeof(components));
  csi->next->c = c;
  csi->next->next = NULL;
}

void cs_iter(components *cs, void (*func)(component *c)) {
  for (components *csi=cs; csi != NULL; csi=csi->next)
    func(&csi->c);
}

component c_create(uint16_t type, void *data, unsigned long size) {
  printf("data: %p\n", data);
  component _c = (component) {
    type,
    NULL,
  };
  _c.content = malloc(sizeof(data));\
  memcpy(_c.content, data, size);
  return _c;
}
