#include "ecs.h"
#include <stdlib.h>

void c_add(components *cs, component c) {
  if (cs->c == NULL) {
    cs->c = malloc(sizeof(component));
    *cs->c = c;
    return;
  }

  components *csi;
  for (csi=cs; csi->next != NULL; csi=csi->next);

  csi->next = malloc(sizeof(components));
  csi->next->c = malloc(sizeof(component));
  *csi->next->c = c;
  csi->next->next = NULL;
}

void c_delete(components *cs, component *c) {
  if (cs->c == c) {
    *cs->c = *cs->next->c;
    *cs->next = *cs->next->next;
    return;
  }

  for (components *csi=cs;; csi=csi->next) {
    if (csi->next->c == c) {
      components *actual_next = csi->next->next;
      free(csi->next->c);
      free(csi->next);
      csi->next = actual_next;
      return;
    }
  }
}

void c_iter(components *cs, void (*func)(component *c)) {
  for (components *csi=cs; csi->next != NULL; csi=csi->next)
    func(csi->c);
}
