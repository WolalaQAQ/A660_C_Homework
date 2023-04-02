//
// Created by wolala on 23-4-2.
//
#include "vector.h"

typedef struct {
  void* data;
  size_t size;
  size_t capacity;
  size_t element_size;
} Vector;

Vector* vector_create(size_t initial_capacity, size_t element_size) {
  Vector* vec = (Vector*)malloc(sizeof(Vector));
  vec->data = malloc(initial_capacity * element_size);
  vec->size = 0;
  vec->capacity = initial_capacity;
  vec->element_size = element_size;
  return vec;
}

void vector_destroy(Vector* vec) {
  free(vec->data);
  free(vec);
}

void vector_resize(Vector* vec, size_t new_capacity) {
  void* new_data = realloc(vec->data, new_capacity * vec->element_size);
  if (new_data) {
    vec->data = new_data;
    vec->capacity = new_capacity;
  } else {
    printf("Error: Memory allocation failed.\n");
    exit(1);
  }
}

void vector_push_back(Vector* vec, const void* value) {
  if (vec->size == vec->capacity) {
    vector_resize(vec, vec->capacity * 2);
  }
  memcpy((char*)vec->data + vec->size * vec->element_size, value, vec->element_size);
  vec->size++;
}

void vector_pop_back(Vector* vec, void* out_value) {
  if (vec->size == 0) {
    printf("Error: Attempting to pop from an empty vector.\n");
    exit(1);
  }
  vec->size--;
  if (out_value) {
    memcpy(out_value, (char*)vec->data + vec->size * vec->element_size, vec->element_size);
  }
}