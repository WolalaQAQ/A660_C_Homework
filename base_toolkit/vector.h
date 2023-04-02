//
// Created by wolala on 23-4-2.
//

#ifndef A660_C_HOMEWORK_VECTOR_H
#define A660_C_HOMEWORK_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void* data;
  size_t size;
  size_t capacity;
  size_t element_size;
} Vector;

Vector* vector_create(size_t initial_capacity, size_t element_size);
void vector_destroy(Vector* vec);
void vector_resize(Vector* vec, size_t new_capacity);
void vector_push_back(Vector* vec, const void* value);
void vector_pop_back(Vector* vec, void* out_value);


#endif  // A660_C_HOMEWORK_VECTOR_H
