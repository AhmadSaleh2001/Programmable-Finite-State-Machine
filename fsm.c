#include <stdlib.h>
#include <string.h>
#include "fsm.h"

fsm_t * create_new_fsm(char * fsm_name) {
    fsm_t * fsm = malloc(sizeof(fsm_t));
    memcpy(fsm->fsm_name, fsm_name, MAX_FSM_NAME_LENGTH - 1);
    fsm->fsm_name[MAX_FSM_NAME_LENGTH - 1] = '\0';

    return fsm;
}