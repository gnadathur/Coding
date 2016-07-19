//
//  memcpy.cpp
//  xcode
//
//  Created by Gokul Nadathur on 7/18/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <cstdint>
#include <cstring>
#include <iostream>

using namespace std;

//void aligned_memcpy_sse2(void* dest, const void* src, const unsigned long size)
//{
//    
//    asm
//    {
//        mov esi, src;    //src pointer
//        mov edi, dest;   //dest pointer
//        
//        mov ebx, size;   //ebx is our counter
//        shr ebx, 7;      //divide by 128 (8 * 128bit registers)
//    loop_copy:
//        prefetchnta 128[ESI]; //SSE2 prefetch
//        prefetchnta 160[ESI];
//        prefetchnta 192[ESI];
//        prefetchnta 224[ESI];
//        
//        movdqa xmm0, 0[ESI]; //move data from src to registers
//        movdqa xmm1, 16[ESI];
//        movdqa xmm2, 32[ESI];
//        movdqa xmm3, 48[ESI];
//        movdqa xmm4, 64[ESI];
//        movdqa xmm5, 80[ESI];
//        movdqa xmm6, 96[ESI];
//        movdqa xmm7, 112[ESI];
//        
//        movntdq 0[EDI], xmm0; //move data from registers to dest
//        movntdq 16[EDI], xmm1;
//        movntdq 32[EDI], xmm2;
//        movntdq 48[EDI], xmm3;
//        movntdq 64[EDI], xmm4;
//        movntdq 80[EDI], xmm5;
//        movntdq 96[EDI], xmm6;
//        movntdq 112[EDI], xmm7;
//        
//        add esi, 128;
//        add edi, 128;
//        dec ebx;
//        
//        jnz loop_copy; //loop please
//    loop_copy_end:
//    }
//}

void memcpyPrivate(char* src, char* dest, int nBytes)
{
    auto count = (nBytes >> 3);
    auto rem = nBytes - (count << 3);
    uint64_t *isrc = (uint64_t*)src, *idest = (uint64_t*)dest;
    for ( ; count > 0; ++isrc, ++idest, --count) {
        *idest = *isrc;
    }
    src = (char*)isrc;
    dest = (char*)idest;
    if (rem >= 4) {
        *(uint32_t*)dest = *(uint32_t*)src++;
        rem -= 4;
        dest += 4;
        src += 4;
    }
    if (rem) {
        for (;rem > 0; --rem) {
            *dest++ = *src++;
        }
    }
}

int main(int argc, char** argv)
{
    char* src = (char*)"01234567890123";
    char dest[14];
    memset(dest,0,14);
    memcpyPrivate(src,dest,13);
    cout << dest;
    return 0;
}