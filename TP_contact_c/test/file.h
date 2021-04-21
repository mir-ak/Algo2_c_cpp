#include "list.h"


#ifndef _FILE_H_
#define _FILE_H_

/**
 *
 */
typedef list file;

/**
 *
 */
file* file_create_file();


/**
 *
 */
contact* file_create_node(int id, char* name, char *phone_number);

/**
 *
 */
void file_put (file* stk, contact* pnew);

/**
 *
 */
contact* file_get(file* stk);

/**
 *
 */
void file_display_contact(contact* ptr);

#endif
