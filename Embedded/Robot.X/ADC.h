void ADC1StartConversionSequence();
void InitADC1();
void ADCClearConversionFinishedFlag();
extern unsigned char ADCConversionFinishedFlag;
unsigned char ADCIsConversionFinished(void);
unsigned int * ADCGetResult(void);