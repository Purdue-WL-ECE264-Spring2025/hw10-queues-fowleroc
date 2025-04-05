#include "queue.h"
#include "tile_game.h"
int generate_next_states(struct game_state current, struct game_state next_states[4]);
bool inqueue(struct queue *q, uint64_t key);

//helper functions for BFS
void enqueue(struct queue *q, struct game_state state) {
    uint64_t state_enc = serialize(state);
    insert_at_head(&(q->data), state_enc);
}

struct game_state dequeue(struct queue *q) { 
    uint64_t node_enc = remove_from_tail(&(q->data));
    return (deserialize(node_enc)); 
}

//check if a state already exists in the queue to prevent unnecessary operations
bool inqueue(struct queue *q, uint64_t key) {
    struct list_node *curr = q->data.head;
    while (curr != NULL) {
        if (curr->value == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
//put all possible next states into an array of struct game_states
int generate_next_states(struct game_state current, struct game_state next_states[4]) {
    int count = 0;
    if (current.empty_row < 3) {
        next_states[count] = current;
        move_up(&next_states[count]);
        count++;
    }
    if (current.empty_row > 0) {
        next_states[count] = current;
        move_down(&next_states[count]);
        count++;
    }
    if (current.empty_col < 3) {
        next_states[count] = current;
        move_left(&next_states[count]);
        count++;
    }
    if (current.empty_col > 0) {
        next_states[count] = current;
        move_right(&next_states[count]);
        count++;
    }
    return count;
}
//check if a state matches the target state
bool istarget(struct game_state state) {
    int val = 1;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (row == 3 && col == 3) {
                if (state.tiles[row][col] != 0)
                    return false;
            } else {
                if (state.tiles[row][col] != val++)
                    return false;
            }
        }
    }
    return true;
}

int number_of_moves(struct game_state start) { 
    struct queue q;
    enqueue(&q, start);

    uint64_t start_key = serialize(start);
    
    while (q.data.head != NULL) {
        struct game_state curr = dequeue(&q);
        if (is_goal(curr)) {
            return curr.num_steps;
        }

        struct game_state next[4];
        int count = generate_next_states(curr, next);

        for (int i = 0; i < count; i++) {
            uint64_t key = serialize(next[i]);
            if (!inqueue(&q, key)) {
                enqueue(&q, next[i]);
            }
        }
    }
    return -1;
}
