//
// Created by Adminstrator on 2023/3/21.
//

#include "movie.h"

void generateKey(struct Ticket* ticket) {
  int i;
  for (i = 0; i < 10; i++) {
    ticket->key[i] = rand() % 10;
  }
}
