#include <stdio.h>
#include <stdlib.h>
#include "ecs.h"
#include "components.h"

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
  cs_add(cs, c_create(
        POSITION_T, &P(6, 4), sizeof(position)));
  cs_add(cs, c_create(
        COLLIDER_T, &CIRC_COLLIDER(P(0, 0), 5), sizeof(collider)));
  cs_add(cs, c_create(
        COLLIDER_T, &RECT_COLLIDER(P(-2, 5), 4, 4), sizeof(collider)));

  cs_iter(cs, iter);
  return 0;
}
