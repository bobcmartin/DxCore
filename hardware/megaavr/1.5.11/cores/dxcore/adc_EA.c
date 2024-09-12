
#include "wiring_private.h"
#include "util/delay.h"


 #if defined ((__AVR_DU__) || (__AVR_EA__))
  void __attribute__((weak)) init_ADC0() 
  {
    ADC_t* pADC;
    _fastPtr_d(pADC, &ADC0);    
      #if F_CPU     > 32000000            // 36 MHz /14 = 2.57 MHz
        pADC->CTRLB  = ADC_PRESC_DIV10_gc; // 33 MHz /14 = 2.35 MHz
      #elif F_CPU  >= 30000000            // 32 MHz /12 = 2.67 MHz
        pADC->CTRLB  = ADC_PRESC_DIV12_gc; // 30 MHz /12 = 2.50 MHz
      #elif F_CPU  >= 24000000            // 25 MHz /10 = 2.50 MHz
        pADC->CTRLB  = ADC_PRESC_DIV10_gc; // 24 MHz /10 = 2.40 MHz
      #elif F_CPU  >= 20000000
        pADC->CTRLB  = ADC_PRESC_DIV8_gc;  // 20 MHz / 8 = 2.50 MHz
      #elif F_CPU  >= 16000000
        pADC->CTRLB  = ADC_PRESC_DIV6_gc;  // 16 MHz / 6 = 2.67 MHz
      #elif F_CPU  >= 12000000
        pADC->CTRLB  = ADC_PRESC_DIV4_gc;  // 12 MHz / 4 = 3.00 MHz
      #elif F_CPU  >=  6000000            // 10 MHz / 4 = 2.50 MHz
        pADC->CTRLB  = ADC_PRESC_DIV4_gc;  //  8 MHz / 4 = 2.00 MHz
      #else                               //  5 MHz / 2 = 2.50 MHz
        pADC->CTRLB  = ADC_PRESC_DIV2_gc;  //  4 MHz / 2 = 2.00 MHz
      #endif                              //  1 MHz / 2 =  500 kHz
      pADC->CTRLE = 15; // 15.5 without PGA, 16 with PGA, corresponding to 7.75 or 8 us.
      
      pADC->CTRLA = ADC_ENABLE_bm | ADC_LOWLAT_bm;
      pADC->PGACTRL = ADC_PGABIASSEL_75PCT_gc;
  }
#endif
      
