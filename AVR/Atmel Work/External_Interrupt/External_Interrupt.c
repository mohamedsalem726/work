/*
 * External_Interrupt.c
 *
 * Created: 10/15/2020 4:38:57 PM
 *  Author: Mohamed Salem
 */ 



#include "External_Interrupt.h"




void SET_GlobalInterrupts(void)
{
	
	#if      GLOBAL_INTERRUPT_STATUS  ==  GLOBAL_INT_ENABLE
	
	SET_BIT(SREG,7);
	
	#elif    GLOBAL_INTERRUPT_STATUS  ==  GLOBAL_INT_DISABLE
	
	CLR_BIT(SREG,7);
	
	#endif
}

void ExternalINT0_Init(void)
{
	SET_GlobalInterrupts();
	
	SET_BIT(GICR , 6);
	
	#if    EXTERNAL_INT0_TRIGER == TNT_LOW_LEVEL_TRIGER
	
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#elif  EXTERNAL_INT0_TRIGER == TNT_RISING_EDGE_TRIGER
	
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	#elif  EXTERNAL_INT0_TRIGER == TNT_FALLING_EDGE_TRIGER
	
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	#elif  EXTERNAL_INT0_TRIGER == TNT_ANY_LOGICAL_CHANGE_TRIGER
	
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#endif
	
}

void ExternalINT1_Init(void)
{
	SET_GlobalInterrupts();
	
	SET_BIT(GICR , 7);
	
	#if   EXTERNAL_INT1_TRIGER  == TNT_LOW_LEVEL_TRIGER
	
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	
	#elif  EXTERNAL_INT1_TRIGER == TNT_RISING_EDGE_TRIGER
	
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	#elif  EXTERNAL_INT1_TRIGER == TNT_FALLING_EDGE_TRIGER
	
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	#elif  EXTERNAL_INT1_TRIGER == TNT_ANY_LOGICAL_CHANGE_TRIGER
	
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	
	#endif 
}

void ExternalINT2_Init(void)
{
	SET_GlobalInterrupts();

	SET_BIT(GICR , 5);
		
    #if  EXTERNAL_INT2_TRIGER == TNT_RISING_EDGE_TRIGER
		
    SET_BIT(MCUCSR,6);
		
    #elif  EXTERNAL_INT2_TRIGER == TNT_FALLING_EDGE_TRIGER
		
	CLR_BIT(MCUCSR,6);
		
	#endif
}