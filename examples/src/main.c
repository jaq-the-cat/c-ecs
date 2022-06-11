#include <stdio.h>
#include <stdlib.h>
#include "ecsj.h"
#include "components.h"

void c_print(component_t *c){
  switch (c->type) {
    case POSITION_T:
      {
        position *_pos = (position*) c->content;
        printf("POSITION{%lf, %lf}\n", _pos->x, _pos->y);
        break;
      }
    case COLLIDER_T:
      {
        collider *_col = (collider*) c->content;
        printf("COLLIDER{%lf, %lf}\n", _col->root.x, _col->root.y);
        break;
      }
    case HOMOSEXUALITY_T:
      {
        homosexuality *_homo = (homosexuality*) c->content;
        printf("HOMOSEXUALITY{%lf}\n", _homo->level);
        break;
      }
    default:
      break;
  }
}

void iter(component_t *c) {
  c_print(c);
}

int main(int argc, char* argv[]) {
  component_t pos = COMPONENT(position, POSITION_T, P(6, 4));
  component_t body = COMPONENT(collider, COLLIDER_T, CIRC_COLLIDER(P(0, 0), 5));
  component_t head = COMPONENT(collider, COLLIDER_T, RECT_COLLIDER(P(-2, 5), 4, 4));

  c_print(&pos);
  c_print(&body);
  c_print(&head);
  return 0;
}
