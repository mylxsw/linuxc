#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"

int main(int argc, char *argv[]) 
{
    MYSQL *conn_ptr;
    int res;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;

    conn_ptr = mysql_init(NULL);
    if (!conn_ptr) {
        fprintf(stderr, "mysql_init failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(
                conn_ptr, 
                "127.0.0.1", 
                "root", 
                NULL, 
                "foo", 
                0,
                NULL,
                0)
    ) {
        printf("Connection success\n");
        
        res = mysql_query(conn_ptr, "INSERT INTO children(fname, age) VALUES('Tom', 3)");

        if (!res) {
            printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
        } else {
            fprintf(stderr, "Insert error %d: %s\n", mysql_errno(conn_ptr), mysql_error(conn_ptr));
        }

        res = mysql_query(conn_ptr, "SELECT LAST_INSERT_ID()");
        if (res) {
            printf("SELECT error: %s\n", mysql_error(conn_ptr)); 
        } else {
            res_ptr = mysql_use_result(conn_ptr);
            if (res_ptr) {
                while ((sqlrow = mysql_fetch_row(res_ptr))) {
                    printf("We inserted childno %s\n", sqlrow[0]);
                }
                mysql_free_result(res_ptr);
            }
        }

        res = mysql_query(conn_ptr, "SELECT childno, fname, age FROM children WHERE age > 5");
        if (res) {
            printf("SELECT error: %s\n", mysql_error(conn_ptr));
        } else { 
            res_ptr = mysql_store_result(conn_ptr);
            if (res_ptr) {
                printf("Retrived %lu rows\n", (unsigned long)mysql_num_rows(res_ptr));
                while ((sqlrow = mysql_fetch_row(res_ptr))) {
                    printf("Fetched data ...\n");
                }

                if (mysql_errno(conn_ptr)) {
                    fprintf(stderr, "Retrive error: %s\n", mysql_error(conn_ptr));
                }
                mysql_free_result(res_ptr);
            }
        }

        mysql_close(conn_ptr);
    } else {
        printf("Connection failed: %d - %s\n", mysql_errno(conn_ptr), mysql_error(conn_ptr));
    }

    return EXIT_SUCCESS;
}
