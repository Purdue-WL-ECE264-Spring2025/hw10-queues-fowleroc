#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
    uint64_t state_enc = serialize(state);
    insert_at_head(&(q->data), state_enc);
}

struct game_state dequeue(struct queue *q) { 
    uint64_t node_enc = remove_from_tail(&(q->data));
    return (deserialize(node_enc)); 
}

int number_of_moves(struct game_state start) { return 0; }
