#ifndef EDITOR_H
#define EDITOR_H

#define MAX_DOC_SIZE 100000
#define MAX_IMAGE_PATH 256
#define MAX_IMAGES 10

typedef struct {
    char path[MAX_IMAGE_PATH];
    int pos;
    int w, h;
} DocumentImage;

typedef struct {
    int start;
    int end;
} Range;

// Fonctions Texte
void c_insert_char(int pos, char val);
void c_delete_char(int pos);
const char* c_get_content();

// Fonctions Images
void c_add_image(const char *path, int pos);
void c_resize_image(int index, int new_w, int new_h);
int c_get_image_count();
DocumentImage c_get_image_info(int index);

// Fonctions Analyse
int c_find_pattern(const char *pattern, Range *results);
int c_get_spell_errors(Range *errors);
void c_save_as_word(const char *filename);

#endif
