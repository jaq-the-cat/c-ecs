#include "ecs.h"
#include <stdlib.h>

void cs_add(components *cs, component c) {
  if (cs->c.type == nope_T) {
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
