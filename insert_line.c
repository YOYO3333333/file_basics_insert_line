include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    FILE *fp1 = fopen(file_in, "r");
    FILE *fp2 = fopen(file_out, "w");
    if ((fp1 == NULL) && (fp2 == NULL))
        return -1;
    if (fp1 == NULL)
    {
        fclose(fp2);
        return -1;
    }
    if (fp2 == NULL)
    {
        fclose(fp1);
        return -1;
    }
    char *line = NULL
    size_t len = 0;
    ssize_t read;
    size_t cmpt = 0;
    while ((read = getline(&line, &len, fp1)) != -1)
    {
        if (cmpt == n)
            fputs(content, fp2);
        fputs(line, fp2);
        cmpt++;
    }
    if (line)
        free(line);
    while (cmpt < n)
    {
        fputs("\n", fp2);
        cmpt++;
    }
    if (cmpt == n)
    {
        fputs(content, fp2);
        cmpt++;
    }
    fclose(fp1);
    fclose(fp2);
    int temp = 0;
    FILE *fp3 = fopen(file_out, "r");
    char *line1 = NULL;
    size_t len1 = 0;
    ssize_t read1;
    while ((read1 = getline(&line1, &len1, fp3)) != -1)
        temp++;
    if (line1)
        free(line1);
    fclose(fp3);
    return temp;
}

struct global global_init(void)
{
    struct global *global =calloc(3,sizeof(struct global));
    if (!global)
        return NULL;
    return global;
}

struct vhosts vhosts_init(void)
{
    struct vhosts *vhosts  =calloc(3,sizeof(struct vhosts));
    if (!vhosts)
        return NULL;
    return vhosts;
}
