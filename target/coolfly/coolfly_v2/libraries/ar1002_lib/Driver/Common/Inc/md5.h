#ifndef MD5_H  
#define MD5_H  
#include "stdint.h" 

#define MD5_SIZE        (16)

typedef struct  
{  
    uint32_t count[2];  
    uint32_t state[4];  
    uint8_t buffer[64];     
}MD5_CTX;  
   
                           
#define F(x,y,z) ((x & y) | (~x & z))  
#define G(x,y,z) ((x & z) | (y & ~z))  
#define H(x,y,z) (x^y^z)  
#define I(x,y,z) (y ^ (x | ~z))  
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))  
#define FF(a,b,c,d,x,s,ac) \
          { \
          a += F(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }  
#define GG(a,b,c,d,x,s,ac) \
          { \
          a += G(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }  
#define HH(a,b,c,d,x,s,ac) \
          { \
          a += H(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }  
#define II(a,b,c,d,x,s,ac) \
          { \
          a += I(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }                                              
void MD5Init(MD5_CTX *context);  
void MD5Update(MD5_CTX *context,uint8_t *input,uint32_t inputlen);  
void MD5Final(MD5_CTX *context,uint8_t digest[16]);  
void MD5Transform(uint32_t state[4],uint8_t block[64]);  
void MD5Encode(uint8_t *output,uint32_t *input,uint32_t len);  
void MD5Decode(uint32_t *output,uint8_t *input,uint32_t len);  
uint8_t MD5Check(uint8_t *data,
                 uint32_t dataLength,
                 uint8_t *u8_md5sum);
#endif  
