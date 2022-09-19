#ifndef DUCK_H
#define DUCK_H

#include <stddef.h>
#include <stdint.h>

struct duck;
extern const size_t sizeof_duck;
typedef struct duck *duck_t;

#define duck_define(NAME)                 \
    uint8_t NAME##_as_bytes[sizeof_duck]; \
    duck_t NAME = (duck_t)NAME##_as_bytes

void duck_initialize(duck_t);

void duck_set_data(duck_t, void *);

typedef void (*duck_tell_fn_t)(void *, void *);
typedef void *(*duck_ask_fn_t)(void *, void *);

void duck_set_tell_fn(duck_t, duck_tell_fn_t);
void duck_tell(duck_t, void *);

void duck_set_ask_fn(duck_t, duck_ask_fn_t);
void *duck_ask(duck_t, void *);     

#endif