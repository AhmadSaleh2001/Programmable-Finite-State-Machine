#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fsm.h"

void alternate_binary_fsm(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("strict alternating binary number");

    state_t * s1 = create_new_state("state 1", 0); // inital state
    state_t * s2 = create_new_state("state 2", 1); // when we have zero
    state_t * s3 = create_new_state("state 3", 1); // when we have one
    state_t * s4 = create_new_state("state 4", 0); // invalid state

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", 1, s2);
    insert_new_transition_table_entry(s1, "1", 1, s3);

    insert_new_transition_table_entry(s2, "0", 1, s4);
    insert_new_transition_table_entry(s2, "1", 1, s3);

    insert_new_transition_table_entry(s3, "0", 1, s2);
    insert_new_transition_table_entry(s3, "1", 1, s4);

    insert_new_transition_table_entry(s4, "0", 1, s4);
    insert_new_transition_table_entry(s4, "1", 1, s4);

    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
}

void fsm_accept_at_the_end_00_or_11(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("strict alternating binary number");

    state_t * s1 = create_new_state("state 1", 0); // inital state
    state_t * s2 = create_new_state("state 2", 0); // when we have one zero
    state_t * s3 = create_new_state("state 3", 1); // when we have two zeros
    state_t * s4 = create_new_state("state 4", 0); // when we have one one
    state_t * s5 = create_new_state("state 5", 1); // when we have two ones

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", 1, s2);
    insert_new_transition_table_entry(s1, "1", 1, s4);

    insert_new_transition_table_entry(s2, "0", 1, s3);
    insert_new_transition_table_entry(s2, "1", 1, s4);

    insert_new_transition_table_entry(s3, "0", 1, s3);
    insert_new_transition_table_entry(s3, "1", 1, s4);

    insert_new_transition_table_entry(s4, "0", 1, s2);
    insert_new_transition_table_entry(s4, "1", 1, s5);

    insert_new_transition_table_entry(s5, "0", 1, s2);
    insert_new_transition_table_entry(s5, "1", 1, s5);

    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

int main() {

    // alternate_binary_fsm("0101011\0");
    fsm_accept_at_the_end_00_or_11("01010100\0");
    fsm_accept_at_the_end_00_or_11("000111010\0");
    fsm_accept_at_the_end_00_or_11("00ahmad0111010\0"); // invalid case

    return 0;
}