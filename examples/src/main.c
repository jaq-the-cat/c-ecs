#include <stdio.h>
#include <stdlib.h>
#include "ecsj.h"
#include "components.h"

void c_print(ecsj_component *c){
  switch (c->type) {
    case POSITION_T:
      {
        position *pos = (position*) c->content;
        printf("POSITION{%lf, %lf}\n", pos->x, pos->y);
        break;
      }
    case COLLIDER_T:
      {
        collider *col = (collider*) c->content;
        printf("COLLIDER{%lf, %lf}\n", col->root.x, col->root.y);
        break;
      }
    case HOMOSEXUALITY_T:
      {
        homosexuality *homo = (homosexuality*) c->content;
        printf("HOMOSEXUALITY{%lf}\n", homo->level);
        break;
      }
    default:
      break;
  }
}

void iter(ecsj_component *c) {
  c_print(c);
}

int main(int argc, char* argv[]) {
  ecsj_entity e = ECSJ_ENTITY();
  // position
  ecsj_entity_add_component(&e, ECSJ_COMPONENT(position, POSITION_T, P(6, 4)));
  // body collider
  ecsj_entity_add_component(&e, ECSJ_COMPONENT(collider, COLLIDER_T, CIRC_COLLIDER(P(0, 0), 5)));
  // head collider
  ecsj_entity_add_component(&e, ECSJ_COMPONENT(collider, COLLIDER_T, RECT_COLLIDER(P(-2, 5), 4, 4)));

  c_print(&e.components[0]);
  c_print(&e.components[1]);
  c_print(&e.components[2]);

  return 0;
}
