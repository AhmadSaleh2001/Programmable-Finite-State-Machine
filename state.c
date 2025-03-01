#include <stdlib.h>
#include <string.h>
#include "fsm.h"
#include "state.h"


// States

state_t * create_new_state(char * state_name, bool is_final_state) {
    state_t * state = malloc(sizeof(state));
    memcpy(state->state_name, state_name, MAX_STATE_NAME_LENGTH - 1);   
    state->state_name[MAX_STATE_NAME_LENGTH - 1] = '\0';
    state->is_final_state = is_final_state;

    return state;
}

void set_state_as_initial_state(fsm_t * fsm, state_t * state) {
    fsm->initial_state = state;
}




// Transition table entries

bool is_transition_table_entry_empty(transition_table_entry_t * transition_table_entry) {
    return transition_table_entry == NULL || transition_table_entry->next_state == NULL;
}

transition_table_entry_t * create_and_insert_new_transition_table_entry(
    transition_table_t * tt,
    char * state_transition_key,
    state_t * next_state
) {
    transition_table_entry_t * new_transition_table_entry = malloc(sizeof(transition_table_entry_t));
    memcpy(new_transition_table_entry->state_transition_key, state_transition_key, MAX_TRANSITION_INPUT - 1);
    new_transition_table_entry->state_transition_key[MAX_TRANSITION_INPUT - 1] = '\0';    
    new_transition_table_entry->next_state = next_state;

    for(int i=0;i<MAX_NUMBER_OF_TRANSITION_ENTRIES;i++) {
        if(is_transition_table_entry_empty(tt->transition_entries[i])) {
            tt->transition_entries[i] = new_transition_table_entry;
            break;
        }
    }

    return new_transition_table_entry;
}