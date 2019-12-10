#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "xml_parser.h"

#define XML_FILE "./config.xml"
//#define XML_FILE "./corrupt_config.xml"

int main()
{
    char *value = NULL;
    int ret;
    value =  get_xml_tag_value(XML_FILE,  "<sim_pin_code>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<sim_me_code>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<inet_apn>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<inet_username>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<inet_password>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<inet_dns1>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<inet_dns2>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<aws_url>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<aws_api_header>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<single>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<two>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<three>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<hundred>"); free(value);
    value =  get_xml_tag_value(XML_FILE,  "<special_characters>"); free(value);
     
    return 0;
}
