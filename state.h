#pragma once
#include <stdbool.h>

#define MAX_STATE_NAME_LENGTH 255

typedef struct transition_table transition_table_t;
typedef struct transition_table_entry transition_table_entry_t;

typedef struct state {

    char state_name[MAX_STATE_NAME_LENGTH];
    transition_table_t * transition_table;
    bool is_final_state;

} state_t;

state_t * create_new_state(char * state_name, bool is_final_state);
void set_state_as_initial_state(fsm_t * fsm, state_t * state);




#define MAX_TRANSITION_INPUT 255
// #define MAX_TRANSITION_OUTPUT 255

struct transition_table_entry
{
    char state_transition_key[MAX_TRANSITION_INPUT];
    // char output[MAX_TRANSITION_OUTPUT];
    state_t * next_state;

};

bool is_transition_table_entry_empty(transition_table_entry_t * transition_table_entry);

transition_table_entry_t * create_and_insert_new_transition_table_entry(
    transition_table_t * tt,
    char * state_transition_key,
    state_t * next_state
);





#define MAX_NUMBER_OF_TRANSITION_ENTRIES 255

struct transition_table
{
   transition_table_entry_t * transition_entries[MAX_NUMBER_OF_TRANSITION_ENTRIES];
};