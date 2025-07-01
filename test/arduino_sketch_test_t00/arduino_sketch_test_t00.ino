#define U8_C_PREPROC_MCRO_CONST_EX01 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX02 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX03 ((uint8_t) 0U)

#define U8_C_PREPROC_MCRO_CONST_EX10 ((uint8_t) 0U)

//	Todo: finalise pin
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01 = 9;

void setup() {
  //	Open serial port and set a baud rate (data rate) to allow for text based output to a connected computer
	Serial.begin(9600);
	//	Wait for up to ~1000 milliseconds for Serial to connect
	int setup_serial_cnt = 1000;     // 
	while (!Serial && setup_serial_cnt > 0)
	{
		delay(1);
		setup_serial_cnt--;
	}

  // put your setup code here, to run once:

	pinMode(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, OUTPUT);
	digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, true);

	pinMode(LED_BUILTIN, OUTPUT);

	digitalWrite(LED_BUILTIN, false);
	if(Serial)
	{
		delay(1000);
		Serial.println("Program set-up complete");
		delay(1000);
	}

}

void loop() {
  // put your main code here, to run repeatedly:

		analogWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, (0U));

        Serial.println("");

        delay(U8_C_PREPROC_MCRO_CONST_EX10);

		digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, true);

        Serial.println("");

        delay(U8_C_PREPROC_MCRO_CONST_EX10);

		analogWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, (0U));

        Serial.println("");

        delay(U8_C_PREPROC_MCRO_CONST_EX10);

		digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, true);

        Serial.println("");

        delay(U8_C_PREPROC_MCRO_CONST_EX10);
}
