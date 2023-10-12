// PB4 at port 12, PB5 at port 13
void setup() {
  asm("sbi 0x4, 5"); // DDRB, PB5
  asm("cbi 0x4, 4"); // DDRB, PB4
}

void loop() {
  volatile int status;
  asm volatile (
    "ldi %0, 1 \n" //high 
    "sbis %1, %2 \n" //skip next if pin high
    "clr %0 \n" //low
    : "=r" (status) : "I" (0x3), "I" (4) // 출력, PINB, PB4
  );

  if (status == 1)
    asm("sbi 0x5, 5"); //PORTB
  else
    asm("cbi 0x5, 5");  //PORTB 
  delay(1000);

}
