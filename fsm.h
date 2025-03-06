#pragma once
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define MAX_STATE_NAME_LENGTH 255

typedef struct fsm fsm_t;
typedef struct state state_t;
typedef struct transition_table transition_table_t;
typedef struct transition_table_entry transition_table_entry_t;

#define MAX_FSM_NAME_LENGTH 255
#define MAX_INPUT_FROM_USER 127

typedef enum {
    FSM_NO_ERROR,
    FSM_NO_TRANSITION
} fsm_error_t;

typedef struct fsm
{
    char fsm_name[MAX_FSM_NAME_LENGTH];

    char input_buffer[MAX_INPUT_FROM_USER]; // Input provided to FSM
    u_int8_t input_buffer_size; // Size of input provided to FSM
    u_int8_t input_buffer_cursor; // Index for processed input

    state_t * initial_state;

};


fsm_t * create_new_fsm(char * fsm_name);

fsm_error_t execute(fsm_t * fsm, char * buffer_input, uint8_t size, bool * fsm_result, char * fsm_output);


typedef struct state {

    char state_name[MAX_STATE_NAME_LENGTH];
    transition_table_t * transition_table;
    bool is_final_state;

};

state_t * create_new_state(char * state_name, bool is_final_state);
void set_state_as_initial_state(fsm_t * fsm, state_t * state);
void insert_new_transition_table_entry(
    state_t * state,
    char * state_transition_key,
    char * state_transition_output,
    state_t * next_state
);



#define MAX_TRANSITION_INPUT 255
#define MAX_TRANSITION_OUTPUT 255

struct transition_table_entry
{
    char state_transition_key[MAX_TRANSITION_INPUT];
    uint8_t state_transition_key_size;

    char transition_output[MAX_TRANSITION_OUTPUT];
    uint8_t state_transition_output_size;

    state_t * next_state;

};

bool is_transition_table_entry_empty(transition_table_entry_t transition_table_entry);

transition_table_entry_t * create_and_insert_new_transition_table_entry(
    transition_table_t * tt,
    char * state_transition_key,
    char * state_transition_output,
    state_t * next_state
);




#define MAX_NUMBER_OF_TRANSITION_ENTRIES 255

struct transition_table
{
   transition_table_entry_t transition_entries[MAX_NUMBER_OF_TRANSITION_ENTRIES];
};