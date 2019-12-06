/* Simple XML Parser  
 * 
 *              Author : Viki (a) Vignesh Natarajan
 *              Firma  : vikilabs.org
 */

#ifndef XML_PARSER_H
#define XML_PARSER_H
#define XML_PARSER_INFO
//#define XML_PARSER_DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Return the string inside the xml tag. 
 * 
 * CAUTION: It is responsibility of the caller to free() the return value
 * 
 */
extern char *get_xml_tag_value(const char *xml_file, char *xml_tag);

#endif
