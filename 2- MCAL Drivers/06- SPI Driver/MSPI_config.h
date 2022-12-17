#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/*Data Order
 * 1- FirstLSB
 * 2- FirstMSB
 * */
#define DataOrder      FirstLSB

/*Clock Polarity
 * 1- LeadingEdgeIsRisingEdge
 * 2- LeadingEdgeIsFallingEdge
 * */
#define ClockPolarity   LeadingEdgeIsFallingEdge

/*Clock Phase
 * 1- LeadingEdgeIsSample
 * 2- LeadingEdgeIsSetup
 * */
#define ClockPhase    LeadingEdgeIsSetup

/*Speed Mode
 * 1- NormalSpeed
 * 2- DoubleSpeed*/
#define SpeedMode            NormalSpeed

/*Normal Clock Mode
 * 1-NormalFoscDevidedBy4
 * 2-NormalFoscDevidedBy16
 * 3-NormalFoscDevidedBy64
 * 4-NormalFoscDevidedBy128
 * */
#define NormalClockRate      NormalFoscDevidedBy128

/*Double Clock Mode
 * 1-DoubleFoscDevidedBy2
 * 2-DoubleFoscDevidedBy8
 * 3-DoubleFoscDevidedBy32
 * 4-DoubleFoscDevidedBy64
 * */
#define DoubleClockRate      DoubleFoscDevidedBy64

#endif /* MSPI_CONFIG_H_ */
