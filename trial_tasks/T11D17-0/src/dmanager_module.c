#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"
#include "dmanager_module.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000


int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    set_doors_closed(doors);
    sort_doors(doors);
    output_doors(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door *doors) {
    struct door door_tmp;

    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = i + 1; j < DOORS_COUNT; j++) {
            if (doors[i].id > doors[j].id) {
                door_tmp = doors[i];
                doors[i] = doors[j];
                doors[j] = door_tmp;
            }
        }
    }
}

void set_doors_closed(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void output_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d %d\n", doors[i].id, doors[i].status);
    }
}
