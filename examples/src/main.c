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
  ecsj_component pos = ECSJ_COMPONENT(position, POSITION_T, P(6, 4));
  ecsj_component body = ECSJ_COMPONENT(collider, COLLIDER_T, CIRC_COLLIDER(P(0, 0), 5));
  ecsj_component head = ECSJ_COMPONENT(collider, COLLIDER_T, RECT_COLLIDER(P(-2, 5), 4, 4));

  c_print(&pos);
  c_print(&body);
  c_print(&head);
  return 0;
}
