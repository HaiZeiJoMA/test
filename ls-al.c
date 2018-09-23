/*************************************************************************
	> File Name: ls-al.c
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 日  9/23 09:09:56 2018
 ************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

int file_mode(struct stat *buf) {
    int mode = 0;
    int i;
    char buff[10] = {"----------"};
    switch (buf -> st_mode & S_IFMT) {
        case S_IFIFO: buff[0] = 'f';
            break;
        case S_IFDIR: 
            buff[0] = 'd';
            mode = 1;
            break;
        case S_IFSOCK: buff[0] = 's';
            break;
        case S_IFBLK: buff[0] = 'b';
            break;
        case S_IFLNK: buff[0] = 'l';
            break;
    }

    if (buf -> st_mode & S_IRUSR) buff[1] = 'r';
    if (buf -> st_mode & S_IWUSR) buff[2] = 'w';
    if (buf -> st_mode & S_IXUSR) {
        if (mode == 0)
        mode = 3;
        buff[3] = 'x';
    }
    if (buf -> st_mode & S_IRGRP) buff[4] = 'r';
    if (buf -> st_mode & S_IWGRP) buff[5] = 'w';
    if (buf -> st_mode & S_IXGRP) {
        if (mode == 0)
        mode = 3;
        buff[6] = 'x';
    }
    if (buf -> st_mode & S_IROTH) buff[7] = 'r';
    if (buf -> st_mode & S_IWOTH) buff[8] = 'w';
    if (buf -> st_mode & S_IXOTH) {
        if (mode == 0)
        mode = 3;
        buff[9] = 'x';
    }

    for (i = 0; i < 10; ++i) {
        printf("%c", buff[i]);
    }
    return mode;
}

void file_gid_uid(int uid, int gid) {
    struct passwd *ptr;
    struct group *str;
    ptr = getpwuid(uid);
    str = getgrgid(gid);
    printf("%8s%8s", ptr -> pw_name, str -> gr_name);
}

int is_real(struct dirent *p) {
    return strncmp(".", p -> d_name, 1);
}

void get_dir_info(char **argv) {
    DIR* dir;
    struct dirent *p;
    struct stat buf;
    int ret;
    char temp[100]; 
    if ((dir = opendir(argv[1])) == NULL) {
        printf("open error!\n");
        exit(0);
    }
    while ((p = readdir(dir)) != NULL) {
        if (is_real(p)) {
        strcpy(temp, argv[1]);
        strcat(temp, p -> d_name);
        if ((ret = stat(temp, &buf)) == -1) {   
            printf("stat error!\n");
            exit(0);
        }

        int mode;
        mode = file_mode(&buf); 
        printf(" %3d ", buf.st_nlink);  
        file_gid_uid(buf.st_uid, buf.st_gid);   
        printf("\t%lld", buf.st_size);          
        printf("\t%.12s ", 4 + ctime(&buf.st_mtime));
                if (mode == 1) {
            printf("\033[34m\t%s\n\033[0m", p -> d_name);
        } else if (mode == 3){
            printf("\033[32m\t%s\n\033[0m", p -> d_name);
        } else {
            printf("\t%s\n", p -> d_name);
        }
    }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc == 1) argv[1] = "./";
    get_dir_info(argv);
    return 0;
}
