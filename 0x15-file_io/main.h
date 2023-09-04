#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void check_arguments(int argc, char *argv[]);
void open_source_file(const char *filename, mode_t permissions, int *source_fd);
void open_dest_file(const char *filename, mode_t permissions, int *dest_fd);
void copy_file_content(int source_fd, int dest_fd);
void close_files(int source_fd, int dest_fd);

#define BUFSIZE 1024

#endif
