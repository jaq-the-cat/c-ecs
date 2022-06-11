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

void cs_delete(components *cs, component *c) {
  if (cs->c.type == nope_T) {
    cs->c = cs->next->c;
    components *new_next = cs->next->next;
    free(cs->next);
    cs->next = new_next;
    return;
  }

  for (components *csi=cs;; csi=csi->next) {
    if (&csi->next->c == c) {
      components *new_next = csi->next->next;
      free(csi->next);
      csi->next = new_next;
      return;
    }
  }
}

void cs_iter(components *cs, void (*func)(component *c)) {
  for (components *csi=cs; csi != NULL; csi=csi->next)
    func(&csi->c);
}
