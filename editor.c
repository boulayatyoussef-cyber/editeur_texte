#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "editor.h"

char doc_buffer[MAX_DOC_SIZE] = "";
DocumentImage images[MAX_IMAGES];
int image_count = 0;
const char *dict[] = {"bonjour", "monde", "word", "code", "texte", "ubuntu"};
int dict_size = 6;

void c_insert_char(int pos, char val) {
    int len = strlen(doc_buffer);
    if (pos < 0 || pos > len) pos = len;
    memmove(doc_buffer + pos + 1, doc_buffer + pos, len - pos + 1);
    doc_buffer[pos] = val;
}

void c_delete_char(int pos) {
    int len = strlen(doc_buffer);
    if (pos <= 0 || pos > len) return;
    memmove(doc_buffer + pos - 1, doc_buffer + pos, len - pos + 1);
}

const char* c_get_content() { return doc_buffer; }

void c_add_image(const char *path, int pos) {
    if (image_count < MAX_IMAGES) {
        strncpy(images[image_count].path, path, MAX_IMAGE_PATH-1);
        images[image_count].pos = pos;
        images[image_count].w = 200; images[image_count].h = 150;
        image_count++;
    }
}

void c_resize_image(int index, int new_w, int new_h) {
    if (index >= 0 && index < image_count) {
        images[index].w = new_w; images[index].h = new_h;
    }
}

int c_get_image_count() { return image_count; }
DocumentImage c_get_image_info(int index) { return images[index]; }

int c_find_pattern(const char *pattern, Range *results) {
    if (!pattern || strlen(pattern) == 0) return 0;
    int count = 0; char *ptr = doc_buffer;
    while ((ptr = strstr(ptr, pattern)) != NULL && count < 50) {
        results[count].start = (int)(ptr - doc_buffer);
        results[count].end = results[count].start + strlen(pattern);
        ptr += strlen(pattern); count++;
    }
    return count;
}

int c_get_spell_errors(Range *errors) {
    int count = 0; char temp[MAX_DOC_SIZE]; strcpy(temp, doc_buffer);
    char *token = strtok(temp, " \n\t.,;!");
    while (token && count < 50) {
        int found = 0;
        for (int i = 0; i < dict_size; i++) if (strcasecmp(token, dict[i]) == 0) { found = 1; break; }
        if (!found) {
            char *ptr = strstr(doc_buffer, token);
            if(ptr) { 
                errors[count].start = (int)(ptr - doc_buffer);
                errors[count].end = errors[count].start + strlen(token); count++; 
            }
        }
        token = strtok(NULL, " \n\t.,;!");
    }
    return count;
}

void c_save_as_word(const char *filename) {
    FILE *f = fopen(filename, "w");
    if(f) {
        fprintf(f, "{\\rtf1\\ansi\\deff0 {\\fonttbl {\\f0 Calibri;}}\\f0\\fs24 %s}", doc_buffer);
        fclose(f);
    }
}
