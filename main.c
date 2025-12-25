#include <stdio.h>
#include "editor.h"
int main() {
    c_insert_char(0, 'W');
    printf("Moteur C pret: %s\n", c_get_content());
    return 0;
}
