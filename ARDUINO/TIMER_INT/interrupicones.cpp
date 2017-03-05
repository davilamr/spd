#include "interrupciones.h"   
void timerInt1(void)
 /*
  * rutina de atención de la interrupción del timer. 
  * Cambia el estado del LED y prende un flag para atender en Loop
  */
   {   
 
    ledState = !ledState ;
    f_timerInterrupt1 = 1;
 
   }

   void timerInt3(void)
 /*
  * rutina de atención de la interrupción del timer. 
  * Cambia el estado del LED y prende un flag para atender en Loop
  */
   {   
 
    ledState3 = !ledState3 ;
    f_timerInterrupt3 = 1;
 
   }

// Private functions
static volatile int xtalCounter;
static volatile unsigned int errorCounter;
static volatile unsigned int decimalTick;
static volatile unsigned int flagDecimalTick;
static volatile unsigned int flagPauseDecimalTick;
static volatile unsigned int flagAscDesc;

static void (*sysDecimalTickHook)(unsigned int t);
static void (*sysTickHook)(void);

void syst_init(unsigned int flagAscDescVal,unsigned int decimalTickStart)
{
    /*xtalCounter=0;
    errorCounter=0;
    decimalTick=decimalTickStart;
    flagPauseDecimalTick=0;
    flagAscDesc = flagAscDescVal;
    sysDecimalTickHook = 0;
    sysTickHook=0;
    
    T3CONbits.TON=1;*/
}

unsigned long syst_getDecimalTick(void)
{
    return decimalTick;
}

unsigned int syst_isDecimalTick(void)
{
    return flagDecimalTick;
}

void syst_resetDecimalTickFlag(void)
{
    flagDecimalTick=0;
}

void syst_setDecimalTickState(unsigned int state)
{
    flagPauseDecimalTick=state;
}

void syst_setDecimalTickHook(void (*fn)(unsigned int t))
{
    sysDecimalTickHook = fn;
}
void syst_setTickHook(void (*fn)(void))
{
    sysTickHook = fn;
}
