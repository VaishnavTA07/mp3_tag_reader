#include<stdio.h>
#include<string.h>
#include<unistd.h> 
#include "header.h"

void edit(FILE *fp,char *tag_edit,char *info_edit,char *file_name)
{
    fseek(fp,0,SEEK_SET);
    FILE *fp2;
    if((fp2=fopen("temp.mp3","wb"))==NULL)
    {
        fprintf(stderr,"File not created\n");
        return;
    }

    char buffer[10];
    unsigned int new_size=(strlen(info_edit)+1);         // New frame size (including encoding byte
    fread(buffer,1,10,fp);                                // Read ID3 header
    fwrite(buffer,1,10,fp2);
    while(1)
    {
        char  tag[5];
        unsigned char s[4],s_temp[4];
        int size;
        char flag[3];
        char info[100];

        fread(tag,1,4,fp);
        tag[4]='\0';

        fread(s,1,4,fp);

        // Convert big-endian size bytes to integer

        size = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
        
        fread(flag,1,3,fp);
        fread(info,1,size-1,fp);

        if(strcmp(tag,tag_edit)==0)
        {
            fwrite(tag,1,4,fp2);
            s_temp[0] = (new_size >> 24) & 0xFF;
            s_temp[1] = (new_size >> 16) & 0xFF;
            s_temp[2] = (new_size >> 8)  & 0xFF;
            s_temp[3] =  new_size        & 0xFF;
            fwrite(s_temp, 1, 4, fp2);
            fwrite(flag,1,3,fp2);
            fwrite(info_edit,1,new_size-1,fp2);
            break;
            
        }
        else
        {
            // Copy frame as it is if tag doesn't match
            fwrite(tag,1,4,fp2);
            fwrite(s,1,4,fp2);
            fwrite(flag,1,3,fp2);
            fwrite(info,1,size-1,fp2);
        
        }

    }

      // Copy remaining MP3 audio data
    char buff[1];
    while((fread(buff,1,1,fp))>0)
    {
        fwrite(buff,1,1,fp2);
    }

    // Delete original file
    remove(file_name);
    // Replace with edited file
    rename("temp.mp3",file_name);


}