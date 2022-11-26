#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

uint32_t s_u32_key[2] = {0x12345678,0x12345678};

void UPGRADE_Encrypt(uint8_t *pu8_inBuff, uint32_t u32_dataLen, uint8_t *pu8_outBuff, uint8_t u8_flag)
{

    unsigned int k0 = s_u32_key[0];
    unsigned int k1 = s_u32_key[1];
    unsigned int  index ;
    unsigned int i ;

    unsigned char c ;
    unsigned char ori ;
    unsigned char index_0 ;

    unsigned char key00 = 0xff& k0;
    unsigned char key01 = 0xff&(k0>>8);
    unsigned char key02 = 0xff&(k0>>16);
    unsigned char key03 = 0xff&(k0>>24);


    unsigned char key10 = 0xff& k1;
    unsigned char key11 = 0xff&(k1>>8);
    unsigned char key12 = 0xff&(k1>>16);
    unsigned char key13 = 0xff&(k1>>24);


    unsigned char key0 ;
    unsigned char key1 ;
    unsigned char enc_byte ;
    unsigned char dec_byte ;
    unsigned char offset;

    unsigned char shift ;
    unsigned char mm,nn,kk;
    
	index = 0 ;
    uint32_t j = 0;
    
    for (j = 0; j < u32_dataLen; j++)
    {
    	

    	offset = index%4;	

    	mm = index&0xff ;
    	nn = (index>>8)&0xff ;
    	kk = (index>>16)&0xff ;
    	i = mm + nn + kk ;
    	index_0 = i%256; 

    	if ( index <= 3 )
        {
    		if ( 	offset == 0 )
            {
        		key0 =  index_0 ;
        		key1 =  index_0 ;
    		}
    		else if ( offset == 1 ) 
            {
        		key0 =  index_0 ;
        		key1 =  index_0 ;
    		}
    		else if ( offset == 2 ) 
            {
        		key0 =  index_0 ;
        		key1 =  index_0 ;
    		}
    		else if ( offset == 3 ) 
            {
        		key0 =  index_0 ;
        		key1 =  index_0 ;
    		}
    	}
    	else 
        {	
    			if ( 	offset == 0 ){
    			key0 = key00 + index_0 ;
    			key1 = key10 + index_0 ;
    			}
    			else if ( offset == 1 ) {
    			key0 = key01 + index_0 ;
    			key1 = key11 + index_0 ;
    			}
    			else if ( offset == 2 ) {
    			key0 = key02 + index_0 ;
    			key1 = key12 + index_0 ;
    			}
    			else if ( offset == 3 ) {
    			key0 = key03 + index_0 ;
    			key1 = key13 + index_0 ;
    			}
    	}


    	shift =  (	(key1   )&0x01 )+ 
    			 (	(key1>>1)&0x01 )+ 
    			 (	(key1>>2)&0x01 )+ 
    			 (	(key1>>3)&0x01 )+ 
    			 (	(key1>>4)&0x01 )+ 
    			 (	(key1>>5)&0x01 )+ 
    			 (	(key1>>6)&0x01 )+ 
    			 (	(key1>>7)&0x01 );

        
        c = pu8_inBuff[j];

        if (0 == u8_flag)
        {
        	switch ( shift ) 
            {
        		case 0 :
        			ori = c ;	
        		break;

        		case 1 :
        			ori = (( c<<1 )&0xff) |  ( (c>>7)&0xff) ;
        		break;

        		
        		case 2 :
        			ori = (( c<<2 )&0xff) |  ( (c>>6)&0xff) ;
        		break;

        		case 3 :
        			ori = (( c<<3 )&0xff) |  ( (c>>5)&0xff) ;
        		break;

        		case 4 :
        			ori = (( c<<4 )&0xff) |  ( (c>>4)&0xff) ;
        		break;

        		case 5 :
        			ori = (( c<<5 )&0xff) |  ( (c>>3)&0xff) ;
        		break;

        		case 6 :
        			ori = (( c<<6 )&0xff) |  ( (c>>2)&0xff) ;
        		break;

        		case 7 :
        			ori = (( c<<7 )&0xff) |  ( (c>>1)&0xff) ;
        		break;
        		default :
        			ori = c ;	
        		break ;
        	
        	}

        	enc_byte = ori^key0;
            pu8_outBuff[j] = enc_byte;
        }
        else
        {
        	dec_byte = key0^c;

        	switch ( shift )
            {
        	case 0 : 
        		dec_byte = dec_byte	;
        	break	;

        	case 1 :
        		dec_byte = ( (dec_byte >>1)&0xff ) | ((dec_byte<<7)&0xff )	;
        	break	;

        	case 2 :
        		dec_byte = ( (dec_byte >>2)&0xff ) | ((dec_byte<<6)&0xff )	;
        	break	;

        	case 3 :
        		dec_byte = ( (dec_byte >>3)&0xff ) | ((dec_byte<<5)&0xff )	;
        	break	;

        	case 4 :
        		dec_byte = ( (dec_byte >>4)&0xff ) | ((dec_byte<<4)&0xff )	;
        	break	;

        	case 5 :
        		dec_byte = ( (dec_byte >>5)&0xff ) | ((dec_byte<<3)&0xff )	;
        	break	;

        	case 6 :
        		dec_byte = ( (dec_byte >>6)&0xff ) | ((dec_byte<<2)&0xff )	;
        	break	;

        	case 7 :
        		dec_byte = ( (dec_byte >>7)&0xff ) | ((dec_byte<<1)&0xff )	;
        	break	;
            }
            pu8_outBuff[j] = dec_byte;            
        }
    
    index++;
    }
}


int main_upgrade_encrypt( int argc, const char * argv [] )
{
    FILE* in;
    FILE* outencrypt;
    // FILE* outdecoder;

    in = fopen(argv[1], "rb");
    s_u32_key[0] = strtoul(argv[2], NULL, 0);
    s_u32_key[1] = strtoul(argv[3], NULL, 0);
    
    char outFileName[64] = "encrypt_";
    
    strcat(outFileName, argv[4]);

    printf("encrypt key1=%08lx key2=%08lx\n", s_u32_key[0], s_u32_key[1]);
    printf("output encrypt file name %s\n", outFileName);
    fseek(in, 0, SEEK_END);
    uint32_t len = ftell(in);
    fseek(in, 0, SEEK_SET);
    uint8_t *inbuff = malloc_safe(len);
    uint8_t *outbuff = malloc_safe(len);
    memset(inbuff, 0, len);
    memset(outbuff, 0, len);
    
    outencrypt = fopen(outFileName, "wb");
    fread(inbuff, 1, len, in);
    UPGRADE_Encrypt(inbuff, len, outbuff, 0);
    fwrite(outbuff, 1, len, outencrypt);
    fclose(outencrypt);
    fclose(in);


	return 0;
    
}
