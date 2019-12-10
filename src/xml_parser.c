/* Simple XML Parser  
 * 
 *              Author : Viki (a) Vignesh Natarajan
 *              Firma  : vikilabs.org
 */
#include "xml_parser.h"

char *get_xml_tag_value(const char *xml_file, char *xml_tag)
{
    FILE *fp;
    char *line_buffer = NULL;
    size_t	line_buffer_len = 0;
    ssize_t n_char_read = 0;
    int i, match = 0, j, start_index, end_index;
    int tag_len = 0;
    char *value = NULL;

    if(!xml_tag){
        printf("[ error ] xml_tag is null\n");
        goto safe_return;
    }

    fp = fopen(xml_file, "r");

    if(!fp){
        printf("[ error ] unable to open file - %s\n", xml_file);
        goto safe_return;
    }

    #ifdef XML_PARSER_DEBUG
    printf("\n[ debug ] Searching for xml_tag : %s\n", xml_tag);
    #endif

    while((n_char_read = getline(&line_buffer, &line_buffer_len, fp)) != -1 ){
        match = 0;        
        if(value){
            /* free previous allocation */
            free(value);
            value = NULL;
        }
       
        tag_len = strlen(xml_tag);

        if( line_buffer_len < ( 2 * tag_len ) ){
            /*content is empty | xml_tag will not match*/
            continue;          
        }

        #ifdef XML_PARSER_DEBUG
        printf("[ debug ] checking opening xml tag : ");
        #endif
        for(i=0; i < strlen(xml_tag); i++) {
            match = 1;
            if(xml_tag[i] != line_buffer[i]){ 
                #ifdef XML_PARSER_DEBUG
                printf(" : no match");
                #endif
                match = 0;
                break;
            }else{
                #ifdef XML_PARSER_DEBUG
                printf("%c", line_buffer[i]);
                #endif
                /*match*/
                start_index = i + 1;
            }
        }

        #ifdef XML_PARSER_DEBUG
        printf("\n");
        #endif 

        if(match){
            match = 0;
            
            #ifdef XML_PARSER_DEBUG
            printf("[ debug ] checking closing xml tag : ");
            #endif 
            
            for( i = ( n_char_read - 1 ); i >= start_index; i-- ){
                /*Not validating the closing xml_tag, just searching for the symbol*/
                if(line_buffer[i] == '<'){
                    end_index = i - 1;
                    match = 1;
                    break;
                }
            }

            if(!match){
                printf("[ error ] no closing xml tag found, file is corrupt\n");
                goto safe_return;
            }
            
            #ifdef XML_PARSER_DEBUG
            for(i = end_index + 1; i < line_buffer_len; i++){
                printf("%c", line_buffer[i]);
            }
            printf("\n");
            #endif        

            if(end_index < start_index){
                #ifdef XML_PARSER_DEBUG
                printf("[ debug ] found xml tag with empty content\n");
                #endif
                value = (char *) calloc((3), sizeof(char));
                value[0]='"';
                value[1]='"';
                value[2]='\0';
                goto safe_return;
            }

            value = (char *) calloc((end_index - start_index + 2), sizeof(char));
            
            if(!value){
                printf("[ error ] out of memory\n");
                goto safe_return;
            }
        
            j = 0;
            for(i = start_index; i <= end_index; i++){

                value[j] = line_buffer[i];
                value[j+1] = '\0';
                j += 1;
            }

            goto safe_return;
        }

        memset(line_buffer, 0x00, line_buffer_len);
    }

safe_return:
    
    if(line_buffer){
        free(line_buffer);
    }

    if(fp){
        fclose(fp);
    }

    #ifdef XML_PARSER_INFO
    if(value){
        printf("[ status ] ------- [ xml_tag : %s ] [ value = %s]\n", xml_tag, value);
    }
    #endif

    return value;  /*caller should free the value*/
}


