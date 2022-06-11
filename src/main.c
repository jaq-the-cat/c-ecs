#include <stdio.h>
#include <stdlib.h>
#include "ecs.h"

void c_print(component *c){
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
    case nope_T:
      {
        printf("nope_T{}\n");
      }
    default:
      break;
  }
}

void iter(component *c) {
  c_print(c);
}

int main(int argc, char* argv[]) {
  CS_INIT(cs);
  COMPONENT(POSITION_T, pos, P(6, 4));
  COMPONENT(COLLIDER_T, circ_col, CIRC_COLLIDER(P(0, 0), 5));
  COMPONENT(COLLIDER_T, rect_col, RECT_COLLIDER(P(-2, 5), 4, 4));
  cs_add(cs, pos);
  cs_add(cs, circ_col);
  cs_add(cs, rect_col);
  cs_iter(cs, iter);
  return 0;
}
