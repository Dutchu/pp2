#ifndef STRUCTS_LIB_LIBRARY_H
#define STRUCTS_LIB_LIBRARY_H

/* -- STRUCTS -- */
//ZAD 10
struct array_t {
    int size;
    int array[100];
};
//ZAD 01
struct point_t {
    int x;
    int y;
};

/* -- ZAD 01 -- */
void show(const struct point_t* p);
struct point_t* set(struct point_t* p, int x, int y);
int save_point_b(const char *filename, const struct point_t* p);
int load_point_b(const char *filename, struct point_t* p);
int save_point_t(const char *filename, const struct point_t* p);
int load_point_t(const char *filename, struct point_t* p);
int serialize_point(struct point_t *p, char *string);
/* -- ZAD 10 -- */
int read_std_input(char *path);
void clean_std_input(void);
int compare(const void *a, const void *b);
int sort(struct array_t *arr);

#endif //STRUCTS_LIB_LIBRARY_H
