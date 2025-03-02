#include <stdio.h>
#include <stdbool.h>
#include "fsm.h"

int main() {

    fsm_t * fsm = create_new_fsm("strict alternating binary number");
    printf("fsm name: %s\n", fsm->fsm_name);

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
    fsm_error_t error = execute(fsm, "1011101010", 10, &result);

    printf("result: %d\n", result);
    printf("error: %d\n", error);

    return 0;
}