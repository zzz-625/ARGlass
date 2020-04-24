#line 1 "..\\Library\\fih\\src\\hid_transfer.c"
 







 

 
#line 1 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 13 "..\\Library\\fih\\src\\hid_transfer.c"
#line 1 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 14 "..\\Library\\fih\\src\\hid_transfer.c"
#line 1 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
 










 






































 















 

 
 
 



 



 
typedef enum IRQn
{
     

    NonMaskableInt_IRQn   = -14,     
    HardFault_IRQn        = -13,     
    SVCall_IRQn           = -5,      
    PendSV_IRQn           = -2,      
    SysTick_IRQn          = -1,      

     
    BOD_IRQn              = 0,       
    WDT_IRQn              = 1,       
    EINT0_IRQn            = 2,       
    EINT1_IRQn            = 3,       
    GPABC_IRQn            = 4,       
    GPDEF_IRQn            = 5,       
    PWM0_IRQn             = 6,       
    PWM1_IRQn             = 7,       
    TMR0_IRQn             = 8,       
    TMR1_IRQn             = 9,       
    TMR2_IRQn             = 10,      
    TMR3_IRQn             = 11,      
    UART0_IRQn            = 12,      
    UART1_IRQn            = 13,      
    SPI0_IRQn             = 14,      
    SPI1_IRQn             = 15,      
    SPI2_IRQn             = 16,      
    HIRC_IRQn             = 17,      
    I2C0_IRQn             = 18,      
    I2C1_IRQn             = 19,      
    SC2_IRQn              = 20,      
    SC0_IRQn              = 21,      
    SC1_IRQn              = 22,      
    USBD_IRQn             = 23,      
    LCD_IRQn              = 25,      
    PDMA_IRQn             = 26,      
    I2S_IRQn              = 27,      
    PDWU_IRQn             = 28,      
    ADC_IRQn              = 29,      
    DAC_IRQn              = 30,      
    RTC_IRQn              = 31       
} IRQn_Type;






 

 






   


#line 1 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"
 




 

























 











#line 1 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "d:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"

















 




 



 

 













#line 120 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"



 







#line 162 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"

#line 1 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 "..\\Library\\nuvoton\\CMSIS\\Include\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}


#line 263 "..\\Library\\nuvoton\\CMSIS\\Include\\cmsis_armcc.h"


#line 297 "..\\Library\\nuvoton\\CMSIS\\Include\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 



__attribute__((always_inline)) static __inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  int32_t s = 4   * 8 - 1;  

  result = value;                       
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                         
  return(result);
}








 



#line 649 "..\\Library\\nuvoton\\CMSIS\\Include\\cmsis_armcc.h"

   


 



 

#line 731 "..\\Library\\nuvoton\\CMSIS\\Include\\cmsis_armcc.h"
 


#line 54 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmInstr.h"

 
#line 84 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmInstr.h"

   

#line 164 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"
#line 1 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmFunc.h"

 
#line 84 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cmFunc.h"

 

#line 165 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"
















 
#line 198 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"

 






 
#line 214 "..\\Library\\nuvoton\\CMSIS\\Include\\core_cm0.h"

 




 










 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:28;               
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:15;               
    uint32_t T:1;                         
    uint32_t _reserved1:3;                
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t _reserved0:1;                
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 



 







 



 
typedef struct
{
  volatile uint32_t ISER[1U];                
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER[1U];                
        uint32_t RSERVED1[31U];
  volatile uint32_t ISPR[1U];                
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR[1U];                
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];                  
}  NVIC_Type;

 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
        uint32_t RESERVED0;
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
        uint32_t RESERVED1;
  volatile uint32_t SHP[2U];                 
  volatile uint32_t SHCSR;                   
} SCB_Type;

 















 



























 















 









 






 



 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 








 
 







 






 







 


 







 

 










 









 


 



 





 

 
 









 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
  else
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FAUL << 16U) |
                 (1UL << 2U));
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  NVIC_SetPriority (SysTick_IRQn, (1UL << 2) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 










#line 142 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\system_Nano100Series.h"
 








 












 

#line 31 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\system_Nano100Series.h"


extern uint32_t SystemCoreClock;         
extern uint32_t CyclesPerUs;             









 

extern void SystemCoreClockUpdate (void);
extern uint32_t SysGet_PLLClockFreq(void);








 
#line 143 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 144 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

 
 
 



 


#pragma anon_unions




 



 

typedef struct
{


    












 
    volatile const  uint32_t RESULT[18];


    
















































































 
    volatile uint32_t CR;

    





























































 
    volatile uint32_t CHEN;

    



























 
    volatile uint32_t CMPR0;

    



























 
    volatile uint32_t CMPR1;

    







































 
    volatile uint32_t SR;
    uint32_t RESERVE0[1];


    









 
    volatile const  uint32_t PDMA;

    



















 
    volatile uint32_t PWRCTL;

    




















 
    volatile uint32_t CALCTL;

    










 
    volatile uint32_t CALWORD;

    

































 
    volatile uint32_t SMPLCNT0;

    
















 
    volatile uint32_t SMPLCNT1;

} ADC_T;




 






























































































































   
   


 



 

typedef struct
{


    





































































 
    volatile uint32_t PWRCTL;

    
























 
    volatile uint32_t AHBCLK;

    























































































 
    volatile uint32_t APBCLK;

    

























 
    volatile const  uint32_t CLKSTATUS;

    


















 
    volatile uint32_t CLKSEL0;

    













































 
    volatile uint32_t CLKSEL1;

    

























































 
    volatile uint32_t CLKSEL2;

    


















 
    volatile uint32_t CLKDIV0;

    










 
    volatile uint32_t CLKDIV1;

    




















 
    volatile uint32_t PLLCTL;

    













 
    volatile uint32_t FRQDIV;

    







































 
    volatile uint32_t MCLKO;

    










 
    volatile  uint32_t WK_INTSTS;

} CLK_T;




 
































































































































































































































































   
   


 



 

typedef struct
{


    

























 
    volatile uint32_t CTL0;

    







 
    volatile uint32_t DATA0;

    

















 
    volatile uint32_t STS0;
    uint32_t RESERVE0[1];


    

























 
    volatile uint32_t CTL1;

    







 
    volatile uint32_t DATA1;

    

















 
    volatile uint32_t STS1;
    uint32_t RESERVE1[1];


    

















 
    volatile uint32_t COMCTL;

} DAC_T;




 


































   
   


 



 

typedef struct
{


    


































 
    volatile uint32_t EBICON;

    





















 
    volatile uint32_t EXTIME;

} EBI_T;




 































   
   


 



 

typedef struct
{


    


































 
    volatile uint32_t ISPCON;

    









 
    volatile uint32_t ISPADR;

    









 
    volatile uint32_t ISPDAT;

    












 
    volatile uint32_t ISPCMD;

    










 
    volatile uint32_t ISPTRG;

    










 
    volatile const  uint32_t DFBADR;
    uint32_t RESERVE0[10];


    


















 
    volatile uint32_t ISPSTA;

} FMC_T;




 

















































   
   


 



 

typedef struct
{


    









 
    volatile const  uint32_t PDID;

    






























 
    volatile uint32_t RST_SRC;

    


































 
    volatile uint32_t IPRST_CTL1;

    








































































 
    volatile uint32_t IPRST_CTL2;
    uint32_t RESERVE0[4];


    









 
    volatile uint32_t TEMPCTL;
    uint32_t RESERVE1[3];


    






















































 
    volatile uint32_t PA_L_MFP;

    

























































 
    volatile uint32_t PA_H_MFP;

    




















































 
    volatile uint32_t PB_L_MFP;

    























































 
    volatile uint32_t PB_H_MFP;

    



















































 
    volatile uint32_t PC_L_MFP;

    















































 
    volatile uint32_t PC_H_MFP;

    

















































 
    volatile uint32_t PD_L_MFP;

    






























 
    volatile uint32_t PD_H_MFP;

    































 
    volatile uint32_t PE_L_MFP;

    






























 
    volatile uint32_t PE_H_MFP;

    



























 
    volatile uint32_t PF_L_MFP;
    uint32_t RESERVE2[1];


    










 
    volatile uint32_t PORCTL;

    






















































 
    volatile uint32_t BODCTL;

    




























 
    volatile  uint32_t BODSTS;

    




























 
    volatile uint32_t Int_VREFCTL;
    uint32_t RESERVE3[4];


    



































 
    volatile uint32_t IRCTRIMCTL;

    
















 
    volatile uint32_t IRCTRIMIEN;

    























 
    volatile uint32_t IRCTRIMINT;
    uint32_t RESERVE4[29];


    









 
    volatile uint32_t RegLockAddr;

} SYS_T;




 






































































































































































































































































































































































































































































   
   


 



 

typedef struct
{


    






















































































































 
    volatile uint32_t PMD;

    











 
    volatile uint32_t OFFD;

    











 
    volatile uint32_t DOUT;

    















 
    volatile uint32_t DMASK;

    









 
    volatile const  uint32_t PIN;

    















 
    volatile uint32_t DBEN;

    

















 
    volatile uint32_t IMD;

    






































































































































































































































































































 
    volatile uint32_t IER;

    














 
    volatile uint32_t ISRC;

    












 
    volatile uint32_t PUEN;

} GPIO_T;


typedef struct
{
    

































 
    volatile uint32_t DBNCECON;
} GP_DB_T;




 








































































































































































   




 










   
   


 



 

typedef struct
{


    

































 
    volatile uint32_t CON;

    












 
    volatile uint32_t INTSTS;

    


















 
    volatile const  uint32_t STATUS;

    









 
    volatile uint32_t DIV;

    















 
    volatile uint32_t TOUT;

    
















 
    volatile uint32_t DATA;

    

















 
    volatile uint32_t SADDR0;

    

















 
    volatile uint32_t SADDR1;
    uint32_t RESERVE0[2];


    












 
    volatile uint32_t SAMASK0;

    












 
    volatile uint32_t SAMASK1;
    uint32_t RESERVE1[4];


    









 
    volatile uint32_t WKUPCON;

    










 
    volatile  uint32_t WKUPSTS;

} I2C_T;




 
































































   
   


 



 

typedef struct
{


    
























































































 
    volatile uint32_t CTRL;

    















 
    volatile uint32_t CLKDIV;

    






































 
    volatile uint32_t INTEN;

    

































































































 
    volatile uint32_t STATUS;

    











 
    volatile  uint32_t TXFIFO;

    











 
    volatile const  uint32_t RXFIFO;

} I2S_T;




 




















































































































































   
   


 



 

typedef struct
{


    








 
    volatile const  uint32_t IRQSRC[32];


    








 
    volatile uint32_t NMI_SEL;

    















 
    volatile uint32_t MCU_IRQ;

} INTR_T;




 










   
   


 



 

typedef struct
{


    









































 
    volatile uint32_t CTL;

    








































 
    volatile uint32_t DISPCTL;

    














 
    volatile uint32_t MEM_0;

    














 
    volatile uint32_t MEM_1;

    














 
    volatile uint32_t MEM_2;

    














 
    volatile uint32_t MEM_3;

    














 
    volatile uint32_t MEM_4;

    














 
    volatile uint32_t MEM_5;

    














 
    volatile uint32_t MEM_6;

    














 
    volatile uint32_t MEM_7;

    














 
    volatile uint32_t MEM_8;

    














 
    volatile uint32_t MEM_9;

    



















 
    volatile uint32_t FCR;

    













 
    volatile uint32_t FCSTS;

} LCD_T;




 















































































































































































   
   


 



 


typedef struct
{


    



















































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t DMASAR;
    uint32_t RESERVE0[1];


    








 
    volatile uint32_t DMABCR;
    uint32_t RESERVE1[1];


    








 
    volatile const  uint32_t DMACSAR;
    uint32_t RESERVE2[1];


    









 
    volatile const  uint32_t DMACBCR;

    












 
    volatile uint32_t DMAIER;

    



















 
    volatile uint32_t DMAISR;
    uint32_t RESERVE3[22];


    











 
    volatile uint32_t WDATA;

    








 
    volatile uint32_t SEED;

    








 
    volatile const  uint32_t CHECKSUM;

} DMA_CRC_T;


typedef struct
{


    






























 
    volatile uint32_t GCRCSR;

    












































 
    volatile uint32_t DSSR0;

    





















 
    volatile uint32_t DSSR1;

    






























 
    volatile const  uint32_t GCRISR;

} DMA_GCR_T;


typedef struct
{
    


















































 
    volatile uint32_t CSR;

    









 
    volatile uint32_t SAR;

    









 
    volatile uint32_t DAR;

    









 
    volatile uint32_t BCR;
    uint32_t RESERVE0[1];


    








 
    volatile const  uint32_t CSAR;

    








 
    volatile const  uint32_t CDAR;

    









 
    volatile const  uint32_t CBCR;

    


















 
    volatile uint32_t IER;

    





























 
    volatile uint32_t ISR;

    











 
    volatile uint32_t TCR;

} PDMA_T;



typedef struct
{


    



























 
    volatile uint32_t CSR;

    








 
    volatile uint32_t SAR;

    








 
    volatile uint32_t DAR;

    









 
    volatile uint32_t BCR;
    uint32_t RESERVE0[1];


    








 
    volatile const  uint32_t CSAR;

    








 
    volatile const  uint32_t CDAR;

    








 
    volatile const  uint32_t CBCR;

    












 
    volatile uint32_t IER;

    


















 
    volatile uint32_t ISR;
    uint32_t RESERVE1[1];


    










 
    volatile uint32_t SASOCR;

    








 
    volatile uint32_t DASOCR;

} VDMA_T;





 





























































   





 



































































   





 






































































   





 























































   

   


 



 

typedef struct
{


    


















 
    volatile uint32_t PRES;

    






















 
    volatile uint32_t CLKSEL;

    






















































 
    volatile uint32_t CTL;

    


















 
    volatile uint32_t INTEN;

    


































 
    volatile uint32_t INTSTS;

    






















 
    volatile uint32_t OE;
    uint32_t RESERVE0[1];


    


























 
    volatile uint32_t DUTY0;

    















 
    volatile const  uint32_t DATA0;
    uint32_t RESERVE1[1];


    


























 
    volatile uint32_t DUTY1;

    















 
    volatile const  uint32_t DATA1;
    uint32_t RESERVE2[1];


    


























 
    volatile uint32_t DUTY2;

    















 
    volatile const  uint32_t DATA2;
    uint32_t RESERVE3[1];


    
























 
    volatile uint32_t DUTY3;

    















 
    volatile const  uint32_t DATA3;
    uint32_t RESERVE4[3];


    




































































































 
    volatile uint32_t CAPCTL;

    






































 
    volatile uint32_t CAPINTEN;

    


























































 
    volatile uint32_t CAPINTSTS;

    










 
    volatile const  uint32_t CRL0;

    










 
    volatile const  uint32_t CFL0;

    










 
    volatile const  uint32_t CRL1;

    










 
    volatile const  uint32_t CFL1;

    










 
    volatile const  uint32_t CRL2;

    










 
    volatile const  uint32_t CFL2;

    










 
    volatile const  uint32_t CRL3;

    










 
    volatile const  uint32_t CFL3;

    


















 
    volatile const  uint32_t PDMACH0;

    


















 
    volatile const  uint32_t PDMACH2;

} PWM_T;




 

























































































































































































































































































































































































































   
   


 



 

typedef struct
{


    














 
    volatile  uint32_t INIR;

    












 
    volatile  uint32_t AER;

    


























 
    volatile uint32_t FCR;

    












 
    volatile uint32_t TLR;

    












 
    volatile uint32_t CLR;

    










 
    volatile uint32_t TSSR;

    














 
    volatile uint32_t DWR;

    












 
    volatile uint32_t TAR;

    












 
    volatile uint32_t CAR;

    









 
    volatile const  uint32_t LIR;

    















 
    volatile uint32_t RIER;

    
























 
    volatile uint32_t RIIR;

    






















 
    volatile uint32_t TTR;
    uint32_t RESERVE0[2];


    























 
    volatile uint32_t SPRCTL;

    









 
    volatile uint32_t SPR[20];

} RTC_T;




 

































































































































































































   
   


 



 

typedef struct
{


    union
    {
        








 
        volatile const  uint32_t  RBR;
        








 
        volatile  uint32_t  THR;
    };

    



















































































 
    volatile uint32_t CTL;

    






















































































 
    volatile uint32_t ALTCTL;

    









 
    volatile uint32_t EGTR;

    











 
    volatile uint32_t RFTMR;

    
















 
    volatile uint32_t ETUCR;

    




















































 
    volatile uint32_t IER;

    
















































 
    volatile uint32_t ISR;

    







































































 
    volatile uint32_t TRSR;

    








































































 
    volatile uint32_t PINCSR;

    










 
    volatile uint32_t TMR0;

    










 
    volatile uint32_t TMR1;

    










 
    volatile uint32_t TMR2;

    


























 
    volatile uint32_t UACTL;

    








 
    volatile const  uint32_t TDRA;

    










 
    volatile const  uint32_t TDRB;

} SC_T;




 

































































































































































































































































































   
   


 



 

typedef struct
{


    































































































 
    volatile uint32_t CTL;

    



















































 
    volatile uint32_t STATUS;

    














 
    volatile uint32_t CLKDIV;

    

















































 
    volatile uint32_t SSR;

    










 
    volatile const  uint32_t RX0;

    










 
    volatile const  uint32_t RX1;
    uint32_t RESERVE0[2];


    












 
    volatile  uint32_t TX0;

    












 
    volatile  uint32_t TX1;
    uint32_t RESERVE1[3];


    











 
    volatile uint32_t VARCLK;

    


























 
    volatile uint32_t DMA;

    
































 
    volatile uint32_t FFCTL;
} SPI_T;




 






































































































































































   
   


 



 

typedef struct
{


    






































































































































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t PRECNT;

    













 
    volatile uint32_t CMPR;

    














 
    volatile uint32_t IER;

    



























 
    volatile uint32_t ISR;

    








 
    volatile const  uint32_t DR;

    









 
    volatile const  uint32_t TCAP;
} TIMER_T;





 
























































































   


   



 



 

typedef struct
{


    union
    {

        








 
        volatile const  uint32_t  RBR;


        








 
        volatile  uint32_t  THR;
    };

    






















































 
    volatile uint32_t CTL;

    










































 
    volatile uint32_t TLCTL;

    

































 
    volatile uint32_t IER;

    












































 
    volatile  uint32_t ISR;

    
















































 
    volatile  uint32_t TRSR;

    















































 
    volatile  uint32_t FSR;

    























 
    volatile uint32_t MCSR;

    



















 
    volatile uint32_t TMCTL;

    












 
    volatile uint32_t BAUD;
    uint32_t RESERVE0[2];


    
















 
    volatile uint32_t IRCR;

    

















































 
    volatile uint32_t ALT_CTL;

    











 
    volatile uint32_t FUN_SEL;

} UART_T;




 

















































































































































































































































   
   


 



 



 
typedef struct
{


    








 
    volatile uint32_t BUFSEG;

    
















 
    volatile uint32_t MXPLD;

    

































 
    volatile uint32_t CFG;
    uint32_t RESERVE;

} USBD_EP_T;

typedef struct
{


    





























 
    volatile uint32_t CTL;

    

















 
    volatile const  uint32_t BUSSTS;

    


















 
    volatile uint32_t INTEN;

    

















































 
    volatile uint32_t INTSTS;

    







 
    volatile uint32_t FADDR;

    

































 
    volatile const  uint32_t EPSTS;

    









 
    volatile uint32_t BUFSEG;

    












 
    volatile const  uint32_t EPSTS2;


    USBD_EP_T EP[8];

    uint32_t RESERVE0;

    





















 
    volatile uint32_t PDMA;

} USBD_T;




 
































































































































































   
   


 



 

typedef struct
{


    






































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t IER;

    



























 
    volatile uint32_t ISR;

} WDT_T;




 































   
   


 



 

typedef struct
{


    










 
    volatile  uint32_t RLD;

    




















 
    volatile uint32_t CR;

    










 
    volatile uint32_t IER;

    












 
    volatile uint32_t STS;

    








 
    volatile const  uint32_t VAL;

} WWDT_T;




 




























   
   





#pragma no_anon_unions





 
 






 

#line 11623 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11636 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11659 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

   





 
#line 11692 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11714 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

   

   




 

typedef volatile unsigned char  vu8;        
typedef volatile unsigned short vu16;       
typedef volatile unsigned long  vu32;       





 







 







 








 







 








 







 







 






 








 







 








 







 







 






 


   

 
 
 



 











 
#line 11902 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

 










   

   






 
 
 
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"
 








 










 



 



 

 
 
 
#line 58 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

 
 
 

 





 














 




 




 

#line 103 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 112 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 120 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 128 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"





















 
#line 157 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 164 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 171 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 178 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 186 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 194 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 201 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 208 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

 
#line 216 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 223 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 230 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 237 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 244 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 251 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"













 
#line 271 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 278 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"












#line 297 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 305 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 313 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 322 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

 
#line 330 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 337 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

































 
#line 377 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"







#line 390 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"




























 

















#line 442 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"

#line 449 "..\\Library\\nuvoton\\StdDriver\\inc\\sys.h"













 
























 

























 
























 





















   



 






 







 







 







 







 







 







 








 









 









 









 







 







 







 







 







 







 








 









 








 








 









 









 







 







 














 









 









 









 
static __inline void SYS_UnlockReg(void)
{
    while(((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr != (0x1ul << (0)))
    {
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x59;
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x16;
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x88;
    }
}







 
static __inline void SYS_LockReg(void)
{
    ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0;
}

void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
uint32_t  SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);
void SYS_EnableIRCTrim(uint32_t u32TrimSel,uint32_t u32TrimEnInt);
void SYS_DisableIRCTrim(void);
   

   

   







 


#line 11927 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"
 








 











 



 



 


#line 40 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

 
#line 52 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"


 
#line 61 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

 
#line 89 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

 
#line 97 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"


 






 


































 












































 
#line 193 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

 



 



 














#line 231 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

 


 


 
#line 266 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"


 
 
 
#line 281 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

#line 290 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"
 
 
 
#line 299 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"

#line 326 "..\\Library\\nuvoton\\StdDriver\\inc\\clk.h"
   




 
void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_GetPLLClockFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
void CLK_SysTickDelay(uint32_t us);
void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
void CLK_DisableSysTick(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);

   

   

   







 
#line 11928 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\adc.h"
 








 











 



 



 

#line 76 "..\\Library\\nuvoton\\StdDriver\\inc\\adc.h"

   




 







 











 











 











 










 










 







 







 




















 
#line 195 "..\\Library\\nuvoton\\StdDriver\\inc\\adc.h"






 
















 
#line 228 "..\\Library\\nuvoton\\StdDriver\\inc\\adc.h"






 








 







 







 










 












 











 









 









 







 







 


void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param);
void ADC_DisableHWTrigger(ADC_T *adc);
void ADC_EnableTimerTrigger(ADC_T *adc,
                            uint32_t u32Source,
                            uint32_t u32PDMACnt);
void ADC_DisableTimerTrigger(ADC_T *adc);
void ADC_SetExtraSampleTime(ADC_T *adc,
                            uint32_t u32ChNum,
                            uint32_t u32SampleTime);
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask);



   

   

   







 
#line 11929 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"
 








 











 



 




 
#line 38 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"





   





 








 
#line 66 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"







 







 











 











 








 
#line 121 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"











 








 
#line 148 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"







 
#line 162 "..\\Library\\nuvoton\\StdDriver\\inc\\dac.h"

void DAC_Open(DAC_T *dac, uint32_t u32Ch, uint32_t u32TrgSrc);
void DAC_Close(DAC_T *dac, uint32_t u32Ch);
int DAC_SetDelayTime(DAC_T *dac, uint32_t u32Delay);

   

   

   







 
#line 11930 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\fmc.h"
 









 










 



 




 


 
 
 









 
 
 
#line 56 "..\\Library\\nuvoton\\StdDriver\\inc\\fmc.h"





   




 

 
 
 






 







 







 







 







 







 







 







 







 







 







 







 


 
 
 

extern void FMC_Close(void);
extern int32_t FMC_Erase(uint32_t u32PageAddr);
extern int32_t FMC_GetBootSource(void);
extern void FMC_Open(void);
extern uint32_t FMC_Read(uint32_t u32Addr);
extern uint32_t FMC_ReadCID(void);
extern uint32_t FMC_ReadPID(void);
extern uint32_t FMC_ReadUCID(uint32_t u32Index);
extern uint32_t FMC_ReadUID(uint32_t u32Index);
extern uint32_t FMC_ReadDataFlashBaseAddr(void);
extern void FMC_SetVectorPageAddr(uint32_t u32PageAddr);
extern uint32_t FMC_GetVectorPageAddr(void);
extern void FMC_Write(uint32_t u32Addr, uint32_t u32Data);
extern int32_t FMC_ReadConfig(uint32_t *u32Config, uint32_t u32Count);
extern int32_t FMC_WriteConfig(uint32_t *u32Config, uint32_t u32Count);


   

   

   







 
#line 11931 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\ebi.h"
 









 










 



 




 


 
 
 




 



 
 
 
#line 54 "..\\Library\\nuvoton\\StdDriver\\inc\\ebi.h"

 
 
 
#line 65 "..\\Library\\nuvoton\\StdDriver\\inc\\ebi.h"


   




 

 
 
 






 








 







 








 







 








 


 
 
 

void EBI_Open(uint32_t u32Bank, uint32_t u32DataWidth, uint32_t u32TimingClass, uint32_t u32BusMode, uint32_t u32CSActiveLevel);
void EBI_Close(uint8_t u32Bank);
void EBI_SetBusTiming(uint32_t u32Bank, uint32_t u32TimingConfig, uint32_t u32MclkDiv);


   

   

   







 
#line 11932 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"
 








 











 



 



 


 
 
 




 
 
 






 
 
 



 
 
 






#line 80 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"














 
#line 112 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

#line 129 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

#line 146 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

#line 163 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

#line 180 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

#line 187 "..\\Library\\nuvoton\\StdDriver\\inc\\gpio.h"

   



 










 











 











 











 











 











 











 












 



















 










 











 











 











 










 













 












 














 












 



void GPIO_SetMode(GPIO_T *gpio, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *gpio, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *gpio, uint32_t u32Pin);



   

   

   







 
#line 11933 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\i2c.h"
 








 











 



 



 









   




 







 







 







 
static __inline void I2C_STOP(I2C_T *i2c)
{
    i2c->CON |= ((0x1ul << (4)) | (0x1ul << (2)));
    while(i2c->CON & (0x1ul << (2)));
}






 
static __inline void I2C_WAIT_READY(I2C_T *i2c)
{
    while(!(i2c->INTSTS & (0x1ul << (0))));
    i2c->INTSTS |= (0x1ul << (0));
}






 








 







 









 







 









 







 


uint32_t I2C_Open(I2C_T *i2c, uint32_t u32BusClock);
void I2C_Close(I2C_T *i2c);
void I2C_ClearTimeoutFlag(I2C_T *i2c);
void I2C_Trigger(I2C_T *i2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Si, uint8_t u8Ack);
void I2C_DisableInt(I2C_T *i2c);
void I2C_EnableInt(I2C_T *i2c);
uint32_t I2C_GetBusClockFreq(I2C_T *i2c);
uint32_t I2C_SetBusClockFreq(I2C_T *i2c, uint32_t u32BusClock);
uint32_t I2C_GetIntFlag(I2C_T *i2c);
void I2C_ClearIntFlag(I2C_T *i2c);
uint32_t I2C_GetStatus(I2C_T *i2c);
uint32_t I2C_GetData(I2C_T *i2c);
void I2C_SetData(I2C_T *i2c, uint8_t u8Data);
void I2C_SetSlaveAddr(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddr, uint8_t u8GCMode);
void I2C_SetSlaveAddrMask(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddrMask);
void I2C_EnableTimeout(I2C_T *i2c, uint8_t u8LongTimeout);
void I2C_DisableTimeout(I2C_T *i2c);
void I2C_EnableWakeup(I2C_T *i2c);
void I2C_DisableWakeup(I2C_T *i2c);

   

   

   







 
#line 11934 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\crc.h"
 








 











 



 



 

 
 
 





 
 
 





 
 
 





   



 









 










 










 










 










 










 










 



 
void CRC_Open(uint32_t u32Mode, uint32_t u32Attribute, uint32_t u32Seed, uint32_t u32DataLen);
void CRC_StartDMATransfer(uint32_t u32SrcAddr, uint32_t u32ByteCount);
uint32_t CRC_GetChecksum(void);


   

   

   







 
#line 11935 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\pdma.h"
 








 











 



 



 

 
 
 




 
 
 
#line 48 "..\\Library\\nuvoton\\StdDriver\\inc\\pdma.h"

 
 
 
#line 65 "..\\Library\\nuvoton\\StdDriver\\inc\\pdma.h"

#line 79 "..\\Library\\nuvoton\\StdDriver\\inc\\pdma.h"



   



 










 











 












 












 












 












 












 
#line 184 "..\\Library\\nuvoton\\StdDriver\\inc\\pdma.h"










 


void PDMA_Open(uint32_t u32Mask);
void PDMA_Close(void);
void PDMA_SetTransferCnt(uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(uint32_t u32Ch, uint32_t u32Periphral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_SetTimeOut(uint32_t u32Ch, uint32_t u32OnOff, uint32_t u32TimeOutCnt);
void PDMA_Trigger(uint32_t u32Ch);
void PDMA_EnableInt(uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(uint32_t u32Ch, uint32_t u32Mask);

   

   

   







 
#line 11936 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\pwm.h"
 








 











 



 



 
#line 58 "..\\Library\\nuvoton\\StdDriver\\inc\\pwm.h"

   




 








 
#line 84 "..\\Library\\nuvoton\\StdDriver\\inc\\pwm.h"








 








 











 















 











 















 






uint32_t PWM_ConfigOutputChannel(PWM_T *pwm,
                                 uint32_t u32ChannelNum,
                                 uint32_t u32Frequency,
                                 uint32_t u32DutyCycle);
uint32_t PWM_ConfigCaptureChannel (PWM_T *pwm,
                                   uint32_t u32ChannelNum,
                                   uint32_t u32UnitTimeNsec,
                                   uint32_t u32CaptureEdge);
void PWM_Start(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_Stop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_ForceStop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Duration);
void PWM_DisableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_DisableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_ClearCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t PWM_GetCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void PWM_DisablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnablePDMA(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32RisingFirst, uint32_t u32Mode);
void PWM_DisablePDMA(PWM_T *pwm, uint32_t u32ChannelNum);

   

   

   







 
#line 11937 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\rtc.h"
 








 











 



 




 
















#line 56 "..\\Library\\nuvoton\\StdDriver\\inc\\rtc.h"

#line 64 "..\\Library\\nuvoton\\StdDriver\\inc\\rtc.h"






   




 



 
typedef struct
{
    uint32_t u32Year;           
    uint32_t u32Month;          
    uint32_t u32Day;            
    uint32_t u32DayOfWeek;      
    uint32_t u32Hour;           
    uint32_t u32Minute;         
    uint32_t u32Second;         
    uint32_t u32TimeScale;      
    uint32_t u32AmPm;           
} S_RTC_TIME_DATA_T;

   




 









 










 










 









 









 









 









 









 










 









 









 



void RTC_Open(S_RTC_TIME_DATA_T *sPt);
void RTC_Close(void);
void RTC_32KCalibration(int32_t i32FrequencyX100);
void RTC_SetTickPeriod(uint32_t u32TickSelection);
void RTC_EnableInt(uint32_t u32IntFlagMask);
void RTC_DisableInt(uint32_t u32IntFlagMask);
uint32_t RTC_GetDayOfWeek(void);
void RTC_DisableTamperDetection(void);
void RTC_EnableTamperDetection(uint32_t u32PinCondition);
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day);
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek);
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetDateAndTime(S_RTC_TIME_DATA_T *sPt);



   


   

   









 



#line 11938 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"
 








 











 



 



 
#line 37 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"

#line 48 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"


   




 


















 



















 








 
#line 117 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"








 
#line 139 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"







 
#line 160 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"







 
#line 181 "..\\Library\\nuvoton\\StdDriver\\inc\\sc.h"






 








 









 







 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    
    sc->CTL &= ~((0x7ul << (20)) | (0x1ul << (23)));

    if(u32Count != 0)
    {
        sc->CTL |= ((u32Count - 1) << (20)) | (0x1ul << (23));
    }
}






 
static __inline void  SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    
    sc->CTL &= ~((0x7ul << (16)) | (0x1ul << (19)));

    if(u32Count != 0)
    {
        sc->CTL |= ((u32Count - 1) << (16)) | (0x1ul << (19));
    }
}


uint32_t SC_IsCardInserted(SC_T *sc);
void SC_ClearFIFO(SC_T *sc);
void SC_Close(SC_T *sc);
void SC_Open(SC_T *sc, uint32_t u32CardDet, uint32_t u32PWR);
void SC_ResetReader(SC_T *sc);
void SC_SetBlockGuardTime(SC_T *sc, uint32_t u32BGT);
void SC_SetCharGuardTime(SC_T *sc, uint32_t u32CGT);
void SC_StopAllTimer(SC_T *sc);
void SC_StartTimer(SC_T *sc, uint32_t u32TimerNum, uint32_t u32Mode, uint32_t u32ETUCount);
void SC_StopTimer(SC_T *sc, uint32_t u32TimerNum);


   

   

   







 
#line 11939 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\scuart.h"
 








 











 



 



 













   




 

 






 









 









 








 









 









 



 






 









 










 










 









 


 











 












 














 











 










 











 


void SCUART_Close(SC_T* sc);
uint32_t SCUART_Open(SC_T* sc, uint32_t u32baudrate);
uint32_t SCUART_Read(SC_T* sc, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t SCUART_SetLineConfig(SC_T* sc, uint32_t u32Baudrate, uint32_t u32DataWidth, uint32_t u32Parity, uint32_t  u32StopBits);
void SCUART_SetTimeoutCnt(SC_T* sc, uint32_t u32TOC);
void SCUART_Write(SC_T* sc,uint8_t *pu8TxBuf, uint32_t u32WriteBytes);

   

   

   







 
#line 11940 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\spi.h"
 








 











 



 




 

















#line 55 "..\\Library\\nuvoton\\StdDriver\\inc\\spi.h"


   




 






 







 







 







 







 







 









 









 









 







 






 








 








 








 








 








 








 










 







 







 








 







 







 








 
static __inline void SPI_SET_DATA_WIDTH(SPI_T *spi, uint32_t u32Width)
{
    if(u32Width == 32)
        u32Width = 0;

    spi->CTL = (spi->CTL & ~(0x1ful << (3))) | (u32Width << (3));
}








 







 







 







 







 







 







 







 







 







 


uint32_t SPI_Open(SPI_T *spi, uint32_t u32MasterSlave, uint32_t u32SPIMode, uint32_t u32DataWidth, uint32_t u32BusClock);
void SPI_Close(SPI_T *spi);
void SPI_ClearRxFIFO(SPI_T *spi);
void SPI_ClearTxFIFO(SPI_T *spi);
void SPI_DisableAutoSS(SPI_T *spi);
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock);
void SPI_EnableFIFO(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
void SPI_DisableFIFO(SPI_T *spi);
uint32_t SPI_GetBusClock(SPI_T *spi);
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_EnableWakeup(SPI_T *spi);
void SPI_DisableWakeup(SPI_T *spi);
   

   

   







 
#line 11941 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\timer.h"
 








 











 



 



 





















   




 







 









 








 







 
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (0));
}





 
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (0));
}






 
static __inline void TIMER_EnableWakeup(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (2));
}





 
static __inline void TIMER_DisableWakeup(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (2));
}






 
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (22));
}





 
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (22));
}






 
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (14));
}





 
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (14));
}





 
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->IER |= (0x1ul << (0));
}





 
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->IER &= ~(0x1ul << (0));
}





 
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->IER |= (0x1ul << (1));
}





 
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->IER &= ~(0x1ul << (1));
}







 
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return(timer->ISR & (0x1ul << (0)) ? 1 : 0);
}





 
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (0));
}







 
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return(timer->ISR & (0x1ul << (1)) ? 1 : 0);
}





 
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (1));
}







 
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer)
{
    return (timer->ISR & (0x1ul << (4)) ? 1 : 0);
}





 
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (4));
}





 
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->TCAP;
}





 
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->DR;
}

uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);
void TIMER_EnableFreqCounter(TIMER_T *timer,
                             uint32_t u32DropCount,
                             uint32_t u32Timeout,
                             uint32_t u32EnableInt);
void TIMER_DisableFreqCounter(TIMER_T *timer);
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src);
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask);

   

   

   







 
#line 11942 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\uart.h"
 








 












 



 



 


 
 
 


























 
 
 



 
 
 






   




 








 









 











 









 










 








 









 









 








 









 










 











 











 









 









 



















 


















 





















 








 
__inline void UART_CLEAR_RTS(UART_T* uart)
{
    uart->MCSR |= (0x1ul << (0));
}






 
__inline void UART_SET_RTS(UART_T* uart)
{
    uart->MCSR &= ~(0x1ul << (0));
}






 








 



void UART_ClearIntFlag(UART_T* uart, uint32_t u32InterruptFlag);
void UART_Close(UART_T* uart );
void UART_DisableFlowCtrl(UART_T* uart );
void UART_DisableInt(UART_T*  uart, uint32_t u32InterruptFlag );
void UART_EnableFlowCtrl(UART_T* uart );
void UART_EnableInt(UART_T*  uart, uint32_t u32InterruptFlag );
void UART_Open(UART_T* uart, uint32_t u32baudrate);
uint32_t UART_Read(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
void UART_SetLine_Config(UART_T* uart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t  u32stop_bits);
void UART_SetTimeoutCnt(UART_T* uart, uint32_t u32TOC);
void UART_SelectIrDAMode(UART_T* uart, uint32_t u32Buadrate, uint32_t u32Direction);
void UART_SelectRS485Mode(UART_T* uart, uint32_t u32Mode, uint32_t u32Addr);
void UART_SelectLINMode(UART_T* uart, uint32_t u32Mode, uint32_t u32BreakLength);
uint32_t UART_Write(UART_T* uart,uint8_t *pu8TxBuf, uint32_t u32WriteBytes);


   

   

   







 








#line 11943 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"
 







 






 



 



 
typedef struct s_usbd_info
{
    uint8_t *gu8DevDesc;                 
    uint8_t *gu8ConfigDesc;              
    uint8_t **gu8StringDesc;             
    uint8_t **gu8HidReportDesc;          
    uint32_t *gu32HidReportSize;         
    uint32_t *gu32ConfigHidDescIdx;      
} S_USBD_INFO_T;


extern S_USBD_INFO_T gsInfo;


   



 




#line 56 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"


extern volatile uint32_t g_usbd_UsbConfig;

 




 
#line 77 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"

 
#line 86 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"

 



 
#line 98 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"

 







 


















#line 139 "..\\Library\\nuvoton\\StdDriver\\inc\\usbd.h"















   




 










 












 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 







 







 






 











 










 












 















 
static __inline void USBD_MemCopy(uint8_t *dest, uint8_t *src, int32_t size)
{
    while (size--) *dest++ = *src++;
}









 
static __inline void USBD_SetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            *((volatile uint32_t *) (u32CfgAddr)) = (u32Cfg | (0x1ul << (9)));
            break;
        }
    }
}








 
static __inline void USBD_ClearStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            *((volatile uint32_t *) (u32CfgAddr)) = (u32Cfg & ~(0x1ul << (9)));
            break;
        }
    }
}









 
static __inline uint32_t USBD_GetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
            break;
    }
    return (u32Cfg & (0x1ul << (9)));
}


 
extern volatile uint8_t g_usbd_RemoteWakeupEn;

typedef void (*VENDOR_REQ)(void);  

typedef void (*CLASS_REQ)(void);  

typedef void (*SET_INTERFACE_REQ)(uint32_t u32AltInterface);  

 
void USBD_Open(S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
void USBD_Start(void);
void USBD_GetSetupPacket(uint8_t *buf);
void USBD_ProcessSetupPacket(void);
void USBD_StandardRequest(void);
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlIn(void);
void USBD_PrepareCtrlOut(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlOut(void);
void USBD_SwReset(void);
void USBD_SetVendorRequest(VENDOR_REQ pfnVendorReq);
void USBD_LockEpStall(uint32_t u32EpBitmap);


   

   

   




 
#line 11944 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\wdt.h"
 








 











 



 



 
#line 39 "..\\Library\\nuvoton\\StdDriver\\inc\\wdt.h"






   




 






 







 







 








 








 








 







 






 
static __inline void WDT_Close(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->CTL = 0;
    return;
}





 
static __inline void WDT_EnableInt(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->IER = (0x1ul << (0));
    return;
}





 
static __inline void WDT_DisableInt(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->IER = 0;
    return;
}

void  WDT_Open(uint32_t u32TimeoutInterval,
               uint32_t u32ResetDelay,
               uint32_t u32EnableReset,
               uint32_t u32EnableWakeup);

   

   

   







 
#line 11945 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\wwdt.h"
 








 











 



 



 
#line 47 "..\\Library\\nuvoton\\StdDriver\\inc\\wwdt.h"


   




 






 







 








 








 







 










 



void WWDT_Open(uint32_t u32PreScale, uint32_t u32CmpValue, uint32_t u32EnableInt);


   

   

   







 
#line 11946 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\i2s.h"
 








 










 



 



 





 



 



 


 



 
#line 59 "..\\Library\\nuvoton\\StdDriver\\inc\\i2s.h"

#line 68 "..\\Library\\nuvoton\\StdDriver\\inc\\i2s.h"

 



 



   



 








 
static __inline void I2S_ENABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CTRL |= (0x1ul << (16));
    else
        i2s->CTRL |= (0x1ul << (17));
}









 
static __inline void I2S_DISABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CTRL &= ~(0x1ul << (16));
    else
        i2s->CTRL &= ~(0x1ul << (17));
}






 







 







 







 







 







 







 







 







 







 







 







 










 








 







 








 








 







 







 


uint32_t I2S_Open(I2S_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat, uint32_t u32AudioInterface);
void I2S_Close(I2S_T *i2s);
void I2S_EnableInt(I2S_T *i2s, uint32_t u32Mask);
void I2S_DisableInt(I2S_T *i2s, uint32_t u32Mask);
uint32_t I2S_EnableMCLK(I2S_T *i2s, uint32_t u32BusClock);
void I2S_DisableMCLK(I2S_T *i2s);
void I2S_SetFIFO(I2S_T *i2s, uint32_t u32TxThreshold, uint32_t u32RxThreshold);

   


   

   







 

#line 11947 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"
 








 








#line 20 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"





 



 




 


 
 
 



#line 51 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"

#line 58 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"





#line 71 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"

#line 80 "..\\Library\\nuvoton\\StdDriver\\inc\\lcd.h"












   




 
typedef enum
{
    LCD_C_TYPE = 0,           
    LCD_EXTERNAL_R_TYPE = 1,  
    LCD_INTERNAL_R_TYPE = 2,  
    LCD_EXTERNAL_C_TYPE = 3   
} LCD_PanelType;

   




 







 








 








 








 








 








 


uint32_t LCD_EnableFrameCounter(uint32_t u32Count);
void LCD_DisableFrameCounter(void);
uint32_t LCD_EnableBlink(uint32_t u32ms);
void LCD_DisableBlink(void);
void LCD_EnableInt(uint32_t IntSrc);
void LCD_DisableInt(uint32_t IntSrc);
uint32_t LCD_Open(uint32_t u32DrivingType, uint32_t u32ComNum, uint32_t u32BiasLevel, uint32_t u32FramerateDiv, uint32_t u32DrivingVol);
void LCD_SetPixel(uint32_t u32Com, uint32_t u32Seg, uint32_t u32OnFlag);
void LCD_SetAllPixels(uint32_t u32OnOff);
void LCD_Close(void);








 
static __inline void LCD_EnableDisplay(void)
{
     
    ((LCD_T *) (((uint32_t)0x40000000) + 0xB0000))->CTL |= (0x1ul << (0));
}








 
static __inline void LCD_DisableDisplay(void)
{
     
    ((LCD_T *) (((uint32_t)0x40000000) + 0xB0000))->CTL &= ~(0x1ul << (0));
}



   


   

   










 


#line 11948 "..\\Library\\nuvoton\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"



 

#line 15 "..\\Library\\fih\\src\\hid_transfer.c"

#line 1 "..\\Library\\fih\\inc\\fih_arg.h"



#line 5 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\lt_i2c.h"



#line 5 "..\\Library\\fih\\inc\\lt_i2c.h"
#line 6 "..\\Library\\fih\\inc\\lt_i2c.h"
#line 1 "..\\Library\\fih\\inc\\fih_arg.h"
#line 7 "..\\Library\\fih\\inc\\lt_i2c.h"

 













typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus;

extern int LT_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data);
extern int LT_WriteI2C_ByteN(uint8_t RegAddr, uint8_t *P_Data, uint16_t N);
extern uint8_t LT_ReadI2C_Byte(uint8_t RegAddr);
extern int LT_ReadI2C_ByteN(uint8_t RegAddr, uint8_t *p_data, uint16_t N);
extern void LtChipID(void);
extern void LT_Read_Mode(void);

#line 6 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\imu_spi.h"








#line 10 "..\\Library\\fih\\inc\\imu_spi.h"
#line 11 "..\\Library\\fih\\inc\\imu_spi.h"





#line 22 "..\\Library\\fih\\inc\\imu_spi.h"

#line 39 "..\\Library\\fih\\inc\\imu_spi.h"

#line 67 "..\\Library\\fih\\inc\\imu_spi.h"

#line 76 "..\\Library\\fih\\inc\\imu_spi.h"


























#line 116 "..\\Library\\fih\\inc\\imu_spi.h"

#line 130 "..\\Library\\fih\\inc\\imu_spi.h"

 
#line 140 "..\\Library\\fih\\inc\\imu_spi.h"

 





 





 





 














 



typedef struct bma2x2_accel_data {
				uint16_t acc_x, acc_y, acc_z;
} bma2x2_acc_data;

typedef struct bmg160_data_t {
				uint16_t gyro_x, gyro_y, gyro_z;
}bmg160_gyro_data;


typedef struct bmm050_data_t {
	int8_t dig_x1,dig_y1,dig_x2,dig_y2;

	uint16_t dig_z1; 
	int16_t dig_z2,dig_z3,dig_z4; 

	uint8_t dig_xy1,dig_xy2; 

	uint16_t dig_xyz1; 
}bmm050_t;

typedef struct bmm050_mag_data_float_t {
				float mag_x, mag_y, mag_z;
}bmm050_mag_data;

extern void Spi_WriteReg_Gyro(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_Acc(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_Mag(uint8_t reg, uint8_t u8Value);
extern uint8_t Spi_ReadReg_Gyro(uint8_t reg);

extern int8_t Spi_ReadReg_Mag(uint8_t reg);
extern uint8_t Spi_ReadReg_Acc(uint8_t reg);
extern void Imu_Spi1_Init(void);
extern void read_imu_chip_id(void);

extern void init_imu_chip(bmm050_t *bmm050);
extern void Imu_Read_Data(void);

extern void Imu_Acc_Raw(bma2x2_acc_data *accel);
extern void Imu_Gyro_Raw(bmg160_gyro_data *gyro);
extern void Imu_Mag_Raw(bmm050_mag_data *mag);






#line 7 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\hid_transfer.h"
 







 



 



 
#line 24 "..\\Library\\fih\\inc\\hid_transfer.h"

 




 




 
 





#line 52 "..\\Library\\fih\\inc\\hid_transfer.h"

 



 








 

 
void HID_Init(void);
void HID_ClassRequest(void);

void EP2_Handler(void);
void EP3_Handler(void);
void HID_SetInReport(void);
void HID_GetOutReport(uint8_t *pu8EpBuf, uint32_t u32Size);

void Hid_Transfer_Data(void);


 
#line 8 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\Ecx335af.h"
#line 4 "..\\Library\\fih\\inc\\Ecx335af.h"
#line 5 "..\\Library\\fih\\inc\\Ecx335af.h"

#line 13 "..\\Library\\fih\\inc\\Ecx335af.h"

extern void Spi_WriteReg_1(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_2(uint8_t reg, uint8_t u8Value);
extern uint8_t Spi_ReadReg_1(uint8_t reg);
extern uint8_t Spi_ReadReg_2(uint8_t reg);
extern void step_1(void);
extern void step_2(void);
extern void step_3(void);
extern void step_4(void);
extern void step_5(void);
extern void step_6(void);
extern void step_6_1(void);
extern void ECX_PwrSv_1(void);
extern void ECX_PwrSv_2(void);
extern void Ecx335af_Init(void);
extern void Ecx335af_Power_On(void);
extern void Ecx335af_Power_Off(void);
extern void Ecx335af_Power_Saving(void);
extern void Ecx335af_Exit_Power_Saving(void);
extern void Ecx335af_spi2_init(void);
extern void Read_Ecx335af_reg(void);
extern void Change_Mode(void);

extern void delay_ms(int ms);


#line 9 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\backlight.h"
#line 4 "..\\Library\\fih\\inc\\backlight.h"
#line 5 "..\\Library\\fih\\inc\\backlight.h"
#line 6 "..\\Library\\fih\\inc\\backlight.h"

#line 14 "..\\Library\\fih\\inc\\backlight.h"

extern uint8_t g_CalDac_Reg;

typedef struct {
	uint8_t reg_05;
	uint8_t reg_08;
	uint8_t reg_1D;
	uint8_t reg_18;
	uint8_t reg_19;
	uint8_t reg_1A;
	uint8_t reg_1B;	
} fih_lcd;

extern void BrightHandler(void);
extern void Bright_Strong(void);
extern void Bright_Weak(void);

#line 10 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\key.h"



#line 5 "..\\Library\\fih\\inc\\key.h"
#line 6 "..\\Library\\fih\\inc\\key.h"

extern void Mode_Change_Interrupt_Init(void);
extern void GPDEF_IRQHandler(void);
extern void Backlight_Interrupt_Init(void);
extern void GPABC_IRQHandler(void);

#line 11 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\LT7211_upgrade.h"



#line 5 "..\\Library\\fih\\inc\\LT7211_upgrade.h"



extern int CheckChipId(void);
extern void Config(void);
extern void ReadKey(void);
extern void BlockErase(void);
extern void Write_Frimware(void);
extern int Verify_Firmware(void);
extern void Write_Key(void);
extern void LT7211_Firmware_Upgrade(void);


#line 12 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\Ecx335af_calibration.h"



#line 5 "..\\Library\\fih\\inc\\Ecx335af_calibration.h"
#line 6 "..\\Library\\fih\\inc\\Ecx335af_calibration.h"
#line 7 "..\\Library\\fih\\inc\\Ecx335af_calibration.h"




extern void Set_Vcali_To_Data_Flash(void);

extern void Get_Vcali_From_Data_Flash(void);

extern void Horizontal_orbit_adjustment(int8_t h1, int8_t h2);
extern void Vertical_orbit_adjustment(int8_t v1, int8_t v2);
extern void Set_Value_To_Ecx335af(void);
extern void Ecx335af_Calibration(void);

extern void Ecx335af_Calibration_test(void);


#line 13 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\debug.h"





#line 22 "..\\Library\\fih\\inc\\debug.h"

#line 14 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\lp_i2c.h"



#line 5 "..\\Library\\fih\\inc\\lp_i2c.h"
#line 6 "..\\Library\\fih\\inc\\lp_i2c.h"
#line 7 "..\\Library\\fih\\inc\\lp_i2c.h"

 













extern int LP_WriteI2C_Byte(uint8_t SlaAddr, uint8_t RegAddr, uint8_t Data);
extern int LP_WriteI2C_ByteN(uint8_t SlaAddr, uint8_t RegAddr, uint8_t *P_Data, uint16_t N);
extern uint8_t LP_ReadI2C_Byte(uint8_t SlaAddr, uint8_t RegAddr);
extern int LP_ReadI2C_ByteN(uint8_t SlaAddr, uint8_t RegAddr, uint8_t *p_data, uint16_t N);


#line 15 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\mcu_version.h"









typedef struct
{
	uint8_t cali_flag;				
	int8_t h1;						
	int8_t v1;						
	int8_t h2;						
	int8_t v2;						
	
	uint8_t mcu_version_flag;		
	uint8_t *mcu_version;			
	uint8_t *lt7211b_fwversion;		
	
	int8_t dl_flags;				
}Data_Flash_T;

extern Data_Flash_T data_flash;
extern int8_t dl_flag;

extern void Data_Flash_Value_Init(void);
extern void Fmc_Test(void);
extern void MCU_FMC_Init(void);
extern void Set_Mcu_Version(void);
extern void Get_Mcu_Version(void);
extern void mcu_version_init(void);

#line 16 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\i2c_alsps.h"



#line 5 "..\\Library\\fih\\inc\\i2c_alsps.h"
#line 6 "..\\Library\\fih\\inc\\i2c_alsps.h"
#line 7 "..\\Library\\fih\\inc\\i2c_alsps.h"









 
#line 25 "..\\Library\\fih\\inc\\i2c_alsps.h"
 


 
 



 





 



 







 
#line 60 "..\\Library\\fih\\inc\\i2c_alsps.h"

 



 
#line 72 "..\\Library\\fih\\inc\\i2c_alsps.h"


extern uint8_t ALP_ReadI2C_Byte(uint8_t RegAddr);
extern int ALP_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data);
extern void i2c_alsps_init();
extern void sy3096ps_enable(int enable);
extern uint8_t sy3096ps_read_ps(void);
extern void sy3096ps_clear_interrupt(void);
extern void AlspsPro(void);
extern void PS_Interrupt_Init(void);

#line 17 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\als.h"



#line 5 "..\\Library\\fih\\inc\\als.h"
#line 6 "..\\Library\\fih\\inc\\als.h"
#line 7 "..\\Library\\fih\\inc\\als.h"



 
#line 21 "..\\Library\\fih\\inc\\als.h"

 







 
#line 37 "..\\Library\\fih\\inc\\als.h"




 






 

static uint32_t cali_adc = 815;

extern void ALs_Pro(void);
extern void sy3079as_enable(int enable);
extern int Check_ALS_ID(void);
extern uint16_t sy3096ps_read_als(void);
extern uint32_t sy3079as_process_data(void);
extern void sy3079as_clear_interrupt(void);
extern void sy3079_u32_swap(uint32_t *x, uint32_t *y);
extern void sy3079_bubble_sort_u32(uint32_t* array, int arysize);
extern uint32_t sy3079as_als_calibration(void);


#line 18 "..\\Library\\fih\\inc\\fih_arg.h"
#line 1 "..\\Library\\fih\\inc\\download_flag.h"
#line 19 "..\\Library\\fih\\inc\\fih_arg.h"


#line 17 "..\\Library\\fih\\src\\hid_transfer.c"

uint8_t volatile g_u8EP2Ready = 0;

void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS));
    uint32_t u32State = ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->BUSSTS & 0xf));


    if (u32IntSts & (0x1ul << (2)))
    {
        
        (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (2)));

        if (((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->BUSSTS & (0x1ul << (4)))))
        {
             
            ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->CTL |= 0xF));
        }
        else
        {
             
            ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->CTL &= ~(0x1ul << (0))));
        }
    }


    if (u32IntSts & (0x1ul << (0)))
    {
         
        (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (0)));

        if (u32State & (0x1ul << (0)))
        {
             
            ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->CTL |= 0xF));
            USBD_SwReset();
        }
        if (u32State & (0x1ul << (1)))
        {
             
            ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->CTL &= ~(0x1ul << (1))));
        }
        if (u32State & (0x1ul << (2)))
        {
             
            ((uint32_t)(((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->CTL |= 0xF));
        }
    }


    if(u32IntSts & (0x1ul << (3)))
    {
         
        (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (3)));
    }

    if (u32IntSts & (0x1ul << (1)))
    {
        
        if (u32IntSts & (0x1ul << (31)))
        {
            
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (31)));

             
            (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((0) << 4))) |= (0x1ul << (15)));
            (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((1) << 4))) |= (0x1ul << (15)));

            USBD_ProcessSetupPacket();
        }

        
        if (u32IntSts & (0x1ul << (16)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (16)));
            
            USBD_CtrlIn();
        }

        if (u32IntSts & (0x1ul << (17)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (17)));

            
            USBD_CtrlOut();
        }

        if (u32IntSts & (0x1ul << (18)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (18)));
            
            EP2_Handler();
        }

        if (u32IntSts & (0x1ul << (19)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (19)));
            
            EP3_Handler();
        }

        if (u32IntSts & (0x1ul << (20)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (20)));
        }

        if (u32IntSts & (0x1ul << (21)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (21)));
        }

        if (u32IntSts & (0x1ul << (22)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (22)));
        }

        if (u32IntSts & (0x1ul << (23)))
        {
             
            (((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->INTSTS = (0x1ul << (23)));
        }
    }
}

unsigned int EP3_READY;
void EP2_Handler(void)   
{
		
    
}

void EP3_Handler(void)   
{
    
	
		
		EP3_READY = 1;
		Hid_Transfer_Data();
     
    
    
    
}


 




 
void HID_Init(void)
{
     
     
    ((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->BUFSEG = 0;

     
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((0) << 4))) = ((0x1ul << (8)) | (2ul << (5)) | 0));
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((0) << 4))) = ((0 + 8)));

     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((1) << 4))) = ((0x1ul << (8)) | (1ul << (5)) | 0));
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((1) << 4))) = ((0 + 8)));

     
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((2) << 4))) = ((2ul << (5)) | 0x01));
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((2) << 4))) = (((0 + 8) + 64)));

     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((3) << 4))) = ((1ul << (5)) | 0x02));
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((3) << 4))) = ((((0 + 8) + 64) + 64)));
     
    (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((3) << 4))) = (64));

}

void HID_ClassRequest(void)
{
    uint8_t buf[8];
		int i = 0;

    USBD_GetSetupPacket(buf);

	for(i=0; i<8; i++)
	{



    }



		
	if (buf[0] & 0x80)    
    {



        
        switch (buf[1])
        {
        case 0x01:



        case 0x02:



        case 0x03:



        default:
        {
             
            USBD_SetStall(0);
            break;
        }
        }
    }
    else
    {



        
        switch (buf[1])
        {
        case 0x09:
        {
            if (buf[3] == 3)
            {
                 
                (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((1) << 4))) |= (0x1ul << (7)));
                (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((1) << 4))) = (0));
            }
            break;
        }
        case 0x0A:
        {
             
            (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. CFG + (uint32_t)((0) << 4))) |= (0x1ul << (7)));
            (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((0) << 4))) = (0));
            break;
        }
        case 0x0B:



        default:
        {
            
             
            USBD_SetStall(0);
            break;
        }
        }
    }
}

 


 











typedef __packed struct
{
    uint8_t u8Cmd;
    uint8_t u8Size;
    uint32_t u32Arg1;
    uint32_t u32Arg2;
    uint32_t u32Signature;
    uint32_t u32Checksum;
} CMD_T;

CMD_T gCmd;

static uint8_t  g_u8PageBuff[2048] = {0};     
static uint32_t g_u32BytesInPageBuf = 0;           
static uint8_t  g_u8TestPages[4 * 2048] = {0};     

int32_t HID_CmdEraseSectors(CMD_T *pCmd)
{
    uint32_t u32StartSector;
    uint32_t u32Sectors;

    u32StartSector = pCmd->u32Arg1 - 0x10;
    u32Sectors = pCmd->u32Arg2;

    printf("Erase command - Sector: %d   Sector Cnt: %d\n", u32StartSector, u32Sectors);

     
    memset(g_u8TestPages + u32StartSector * 4096, 0xFF, sizeof(uint8_t) * u32Sectors * 4096);

     
    pCmd->u8Cmd = 0x00;

    return 0;
}


int32_t HID_CmdReadPages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;
	uint32_t u32Pages_T;

    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

	u32Pages_T   = u32Pages - 2;

	printf("Read command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages_T);

	if(u32Pages_T)
    {
         
         
        memcpy(g_u8PageBuff, g_u8TestPages, sizeof(g_u8PageBuff));
        g_u32BytesInPageBuf = 2048;

         
        pCmd->u32Signature = 1;

         
        USBD_MemCopy((uint8_t *)(((((uint32_t)0x40000000) + 0x60000)+0x100) + ((uint32_t)*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((2) << 4))))), (void *)g_u8PageBuff, 64);
        (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((2) << 4))) = (64));
        g_u32BytesInPageBuf -= 64;
    }

    return 0;
}


int32_t HID_CmdWritePages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;

    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

    printf("Write command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages);
    g_u32BytesInPageBuf = 0;

     
    pCmd->u32Signature = 0;

    return 0;
}


int32_t gi32CmdTestCnt = 0;
int32_t HID_CmdTest(CMD_T *pCmd)
{
    int32_t i;
    uint8_t *pu8;

    pu8 = (uint8_t *)pCmd;
    printf("Get test command #%d (%d bytes)\n", gi32CmdTestCnt++, pCmd->u8Size);
    for(i=0; i<pCmd->u8Size; i++)
    {
        if((i&0xF) == 0)
        {
            printf("\n");
        }
        printf(" %02x", pu8[i]);
    }

    printf("\n");


     
    pCmd->u8Cmd = 0x00;

    return 0;
}


uint32_t CalCheckSum(uint8_t *buf, uint32_t size)
{
    uint32_t sum;
    int32_t i;

    i = 0;
    sum = 0;
    while(size--)
    {
        sum+=buf[i++];
    }

    return sum;

}


int32_t ProcessCommand(uint8_t *pu8Buffer, uint32_t u32BufferLen)
{
    uint32_t u32sum;

    USBD_MemCopy((uint8_t *)&gCmd, pu8Buffer, u32BufferLen);
		printf("ProcessCommand --- gCmd.u8Cmd = %x !\n",gCmd.u8Cmd);

     
    if((gCmd.u8Size > sizeof(gCmd)) || (gCmd.u8Size > u32BufferLen))
        return -1;

     
    if(gCmd.u32Signature != 0x43444948)
        return -1;

     
    u32sum = CalCheckSum((uint8_t *)&gCmd, gCmd.u8Size);
    if(u32sum != gCmd.u32Checksum)
        return -1;

    switch(gCmd.u8Cmd)
    {
		case 0x71:
    {
        HID_CmdEraseSectors(&gCmd);
        break;
    }
    case 0xD2:
    {
        HID_CmdReadPages(&gCmd);
        break;
    }
    case 0xC3:
    {
        HID_CmdWritePages(&gCmd);
        break;
    }
    case 0xB4:
    {
        HID_CmdTest(&gCmd);
        break;
    }
    default:
		{
				printf("default!\n");
        return -1;
		}
    }
	
    return 0;
}


void HID_GetOutReport(uint8_t *pu8EpBuf, uint32_t u32Size)
{
    uint8_t  u8Cmd;
    uint32_t u32StartPage;
    uint32_t u32Pages;
    uint32_t u32PageCnt;

     
    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32Pages     = gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature;  


     
    if((u8Cmd == 0xC3) &&  (u32PageCnt < u32Pages))
    {
         

         
        USBD_MemCopy(&g_u8PageBuff[g_u32BytesInPageBuf], pu8EpBuf, 64);
        g_u32BytesInPageBuf += 64;

         
        if(g_u32BytesInPageBuf >= 2048)
        {
            printf("Writing page %d\n", u32StartPage + u32PageCnt);
             
            memcpy(g_u8TestPages + u32PageCnt * 2048, g_u8PageBuff, sizeof(g_u8PageBuff));
            u32PageCnt++;

             
            if(u32PageCnt >= u32Pages)
            {
                u8Cmd = 0x00;

                printf("Write command complete.\n");
            }

            g_u32BytesInPageBuf = 0;

        }

         
        gCmd.u8Cmd        = u8Cmd;
        gCmd.u32Signature = u32PageCnt;
    }
    else
    {
         
        if(ProcessCommand(pu8EpBuf, u32Size))
        {
            printf("Unknown HID command!\n");
        }
    }
}

void HID_SetInReport(void)
{
    uint32_t u32StartPage;
    uint32_t u32TotalPages;
    uint32_t u32PageCnt;
    uint8_t *ptr;
    uint8_t u8Cmd;

    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32TotalPages= gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature;

     
    if(u8Cmd == 0xD2)
    {
         
        if((u32PageCnt >= u32TotalPages) && (g_u32BytesInPageBuf == 0))
        {
             
            u8Cmd = 0x00;
            printf("Read command complete!\n");
        }
        else
        {
            if(g_u32BytesInPageBuf == 0)
            {
                 
                 
                printf("Reading page %d\n", u32StartPage + u32PageCnt);
                memcpy(g_u8PageBuff, g_u8TestPages + u32PageCnt * 2048, sizeof(g_u8PageBuff));

                g_u32BytesInPageBuf = 2048;

                 
                u32PageCnt++;
            }

             
            ptr = (uint8_t *)(((((uint32_t)0x40000000) + 0x60000)+0x100) + ((uint32_t)*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((2) << 4)))));
            USBD_MemCopy(ptr, (void *)&g_u8PageBuff[2048 - g_u32BytesInPageBuf], 64);
            (*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((2) << 4))) = (64));
            g_u32BytesInPageBuf -= 64;
        }
    }

    gCmd.u8Cmd        = u8Cmd;
    gCmd.u32Signature = u32PageCnt;

}

 





typedef __packed struct {
	uint8_t u8Command;
	uint8_t cmd_status;

	uint16_t u16Buffer_Gy_X;
	uint16_t u16Buffer_Gy_Y;
	uint16_t u16Buffer_Gy_Z;
	uint16_t u16Buffer_Ac_X;
	uint16_t u16Buffer_Ac_Y;
	uint16_t u16Buffer_Ac_Z;
	float s16Buffer_Ma_X;
	float s16Buffer_Ma_Y;
	float s16Buffer_Ma_Z;

	uint8_t Key_status;

	uint8_t u8BL;

	int8_t i8Cal_h1;
	int8_t i8Cal_v1;
	int8_t i8Cal_h2;
	int8_t i8Cal_v2;
	
	
} HID_T;

HID_T hCmd;

typedef __packed struct {
	uint8_t u8Command_r;
	uint8_t cmd_status_r;
	uint8_t u8Buffer_r[62];
} HID_T_R;

HID_T_R hCmdR;


int32_t HID_CmdImuData(HID_T_R *pCmd_r,HID_T *pCmd)
{
	uint8_t i = 0;

	bmg160_gyro_data gy_xyz;	
	bma2x2_acc_data acc_xyz;
	bmm050_mag_data mag_xyz;

	Imu_Gyro_Raw(&gy_xyz);
	Imu_Acc_Raw(&acc_xyz);
	Imu_Mag_Raw(&mag_xyz);

	

	pCmd->u16Buffer_Gy_X=gy_xyz.gyro_x;
	pCmd->u16Buffer_Gy_Y=gy_xyz.gyro_y;
	pCmd->u16Buffer_Gy_Z=gy_xyz.gyro_z;

	pCmd->u16Buffer_Ac_X=acc_xyz.acc_x;
	pCmd->u16Buffer_Ac_Y=acc_xyz.acc_y;
	pCmd->u16Buffer_Ac_Z=acc_xyz.acc_z;

	pCmd->s16Buffer_Ma_X=mag_xyz.mag_x;
	pCmd->s16Buffer_Ma_Y=mag_xyz.mag_y;
	pCmd->s16Buffer_Ma_Z=mag_xyz.mag_z;
	
				
	pCmd->u8Command = pCmd_r->u8Command_r;
	
	if (pCmd_r->cmd_status_r == 0x0)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		pCmd->Key_status=(*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((6)<<2))));
		pCmd->u8BL = g_CalDac_Reg;
					
		Get_Vcali_From_Data_Flash();
		pCmd->i8Cal_h1 = data_flash.h1;
		pCmd->i8Cal_v1 = data_flash.v1;
		pCmd->i8Cal_h2 = data_flash.h2;
		pCmd->i8Cal_v2 = data_flash.v2;
	}
	else if(pCmd_r->cmd_status_r == 0x1)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		
		if((*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((6)<<2)))) != pCmd_r->u8Buffer_r[0])
		{
			Change_Mode();
		}		
			
		
		pCmd->Key_status=(*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((6)<<2))));
		
	}
	else if(pCmd_r->cmd_status_r == 0x2)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		
		g_CalDac_Reg =  pCmd_r->u8Buffer_r[0];
		BrightHandler();
	}
	else if(pCmd_r->cmd_status_r == 0x3)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		data_flash.h1 = pCmd_r->u8Buffer_r[0];
		data_flash.v1 = pCmd_r->u8Buffer_r[1];
		data_flash.h2 = pCmd_r->u8Buffer_r[2];
		data_flash.v2 = pCmd_r->u8Buffer_r[3];
		
		Ecx335af_Calibration();
	}

	
	
	
	return 0;
}

void Hid_Transfer_Data(void)
{
	uint8_t *ptrOut, *ptrIn;
	char s1[50],s2[20];
	uint8_t i=0,j=0;
	int8_t flag = 0;

	if(EP3_READY==1)
	{
		EP3_READY=0;
                            
		 
		ptrOut = (uint8_t *)(((((uint32_t)0x40000000) + 0x60000)+0x100) + ((uint32_t)*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((3) << 4)))));
    		ptrIn = (uint8_t *)(((((uint32_t)0x40000000) + 0x60000)+0x100) + ((uint32_t)*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. BUFSEG + (uint32_t)((2) << 4)))));
     
		USBD_MemCopy((uint8_t *)&hCmdR, ptrOut, 64);
			
		if(hCmdR.u8Command_r == 0x01)
		{
			HID_CmdImuData(&hCmdR,&hCmd);
			USBD_MemCopy(ptrIn, (void *)&hCmd, 64);
    			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((3) << 4))) = (64));                        
			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((2) << 4))) = (64));
			hCmd.u8Command = 0x00;
    		}

		if(hCmdR.u8Command_r == 0x02)
		{
			memcpy(s1,data_flash.mcu_version,sizeof(char)*10);
			memcpy(s2,data_flash.lt7211b_fwversion,sizeof(char)*10);

			while(s1[i]!='\0')
			{
				i++;
			}

			while(s2[j]!='\0')
			{
				s1[i]=s2[j];
				i++;
				j++;
			}
			s1[i]='\0';
			
			
			USBD_MemCopy(ptrIn, (void *)&s1, 64);
			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((3) << 4))) = (64));                        
			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((2) << 4))) = (64));
			hCmd.u8Command = 0x00;
		}
		
		else if(hCmdR.u8Command_r == 0x04)
		{
			data_flash.dl_flags = hCmdR.cmd_status_r;
			
			printf("hCmdR.cmd_status_r = %d \n",hCmdR.cmd_status_r);
			printf("data_flash.dl_flags = %d\n",data_flash.dl_flags);
			
			Set_Mcu_Version();
			
			delay_ms(800);
			
			Get_Mcu_Version();
			
			if (1 == dl_flag)
			{
				set_boot_flags();	
			}
			
			
			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((3) << 4))) = (64));                        
			(*((volatile uint32_t *) ((uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0]. MXPLD + (uint32_t)((2) << 4))) = (64));
			hCmd.u8Command = 0x00;			
	
		}

   	}
}
