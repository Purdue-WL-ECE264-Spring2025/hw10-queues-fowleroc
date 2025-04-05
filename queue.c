#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
    insert_at_head(q, &state);
}

struct game_state dequeue(struct queue *q) { 
    remove_from_tail(q);
    return (struct game_state){0}; 
}

int number_of_moves(struct game_state start) { return 0; }
