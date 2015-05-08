#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define ID_NUM 1

Dynamixel Dxl(DXL_BUS_SERIAL1);

void close(){
  Dxl.goalPosition(5, 450);
  delay(1000);
}

void Pos1(){
 Dxl.goalPosition(1, 200);
  Dxl.goalPosition(2, 500);
  Dxl.goalPosition(3, 500);
  Dxl.goalPosition(4, 500);
  Dxl.goalPosition(5, 200);
  delay(3000);
}

void Pos2(){
  Dxl.goalPosition(1, 200);
  Dxl.goalPosition(2, 310);
  Dxl.goalPosition(3, 310);
  Dxl.goalPosition(4, 310);
  Dxl.goalPosition(5, 200);
  delay(3000);
}

void Pos3(){
  Dxl.goalPosition(1, 750);
  Dxl.goalPosition(2, 413);
  Dxl.goalPosition(3, 50);
  Dxl.goalPosition(4, 413);
  Dxl.goalPosition(5, 600);
  delay(3000); 
  }
  
void Pos4(){
  Dxl.goalPosition(1, 612);
  Dxl.goalPosition(2, 250);
  Dxl.goalPosition(3, 250);
  Dxl.goalPosition(4, 800);
  Dxl.goalPosition(5, 600);
  delay(3000); 
  }


void open(){
  Dxl.goalPosition(5, 200);
  delay(1000);
}  
int angle=20;
int pos1=200,pos2=ceil(angle*3.44)+207,pos3=517-2*ceil(angle*3.44),pos4=672,pos5=400;
void setup() {
  // Initialize the dynamixel bus:
  
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps  
  Dxl.begin(3);  
  SerialUSB.attachInterrupt(usbInterrupt);
  Serial2.begin(57600);
  Serial2.attachInterrupt(serialInterrupt);
  pinMode(BOARD_LED_PIN, OUTPUT);  //toggleLED_Pin_Out

  
  Dxl.maxTorque(1,600); 
  Dxl.maxTorque(2,1024); 
  Dxl.maxTorque(3,1024); 
  Dxl.maxTorque(4,1024); 
  Dxl.maxTorque(5,500); 
          
  Dxl.jointMode(1); //jointMode() is to use position mode
  Dxl.jointMode(2);
  Dxl.jointMode(3);
  Dxl.jointMode(4);
  Dxl.jointMode(5);

  Dxl.goalSpeed(1, 30);
  Dxl.goalSpeed(2, 50);
  Dxl.goalSpeed(3, 50);
  Dxl.goalSpeed(4, 50);
  Dxl.goalSpeed(5, 500);


  Dxl.goalPosition(1, pos1);
  Dxl.goalPosition(2, pos2);
  Dxl.goalPosition(3, pos3);
  Dxl.goalPosition(4, pos4);
  Dxl.goalPosition(5, pos5);
  delay(3000);

}

void serialInterrupt(byte buffer){
    if((buffer-48)==1)
    {pos1=pos1+15;  Dxl.goalPosition(1, pos1);SerialUSB.println("I received 1.");SerialUSB.println(pos1);}
    if((buffer-48)==2)
    {pos1=pos1-15;  Dxl.goalPosition(1, pos1);SerialUSB.println("I received 2.");}
    if((buffer-48)==3)
    {pos2=pos2+15;pos3=pos3-30;pos4=pos4+15;  Dxl.goalPosition(2, pos2); 
    Dxl.goalPosition(3, pos3); Dxl.goalPosition(4, pos4);SerialUSB.println("I received 3.");}
    if((buffer-48)==4)
    {pos2=pos2-15;pos3=pos3+30;pos4=pos4-15;  Dxl.goalPosition(2, pos2); 
    Dxl.goalPosition(3, pos3); Dxl.goalPosition(4, pos4);SerialUSB.println("I received 4.");}
    if((buffer-48)==5)
    {pos5=pos5-50;  Dxl.goalPosition(5, pos5);SerialUSB.println("I received 5.");}
    if((buffer-48)==6)
    {pos5=pos5+50;  Dxl.goalPosition(5, pos5);SerialUSB.println("I received 6.");}
    if((buffer-48)==7)
    {pos4=pos4+50;  Dxl.goalPosition(4, pos4);SerialUSB.println("I received 7.");}
    if((buffer-48)==8)
    {pos4=pos4-50;  Dxl.goalPosition(4, pos4);SerialUSB.println("I received 8.");}
    if((buffer-48)==9)
    {pos3=pos3-50;  Dxl.goalPosition(3, pos3);SerialUSB.println("I received 9.");}
    if((buffer-48)==0)
    {pos3=pos3+50;  Dxl.goalPosition(3, pos3);SerialUSB.println("I received 0.");}

}

void usbInterrupt(byte* buffer, byte nCount){
//  SerialUSB.print("nCount =");
    SerialUSB.println(nCount);    
    for(unsigned int i=0; i < nCount;i++)  //printf_SerialUSB_Buffer[N]_receive_Data
    SerialUSB.println((char)buffer[i]);
    SerialUSB.println((char)buffer[0]);
    if((char)buffer[0]=='1')
    {pos1=pos1+15;  Dxl.goalPosition(1, pos1);SerialUSB.println("I received 1.");SerialUSB.println((char)buffer[0]);}
    if((char)buffer[0]=='2')
    {pos1=pos1-15;  Dxl.goalPosition(1, pos1);SerialUSB.println("I received 2.");}
    if((char)buffer[0]=='3')
    {pos2=pos2+15;pos3=pos3-30;pos4=pos4+15;  Dxl.goalPosition(2, pos2); 
    Dxl.goalPosition(3, pos3); Dxl.goalPosition(4, pos4);SerialUSB.println("I received 3.");}
    if((char)buffer[0]=='4')
    {pos2=pos2-15;pos3=pos3+30;pos4=pos4-15;  Dxl.goalPosition(2, pos2); 
    Dxl.goalPosition(3, pos3); Dxl.goalPosition(4, pos4);SerialUSB.println("I received 4.");}
    if((char)buffer[0]=='5')
    {pos5=pos5-15;  Dxl.goalPosition(5, pos5);SerialUSB.println("I received 5.");}
    if((char)buffer[0]=='6')
    {pos5=pos5+15;  Dxl.goalPosition(5, pos5);SerialUSB.println("I received 6.");
    SerialUSB.print("pos5 is:");SerialUSB.print(pos5);}
    if((char)buffer[0]=='7')
    {pos4=pos4+15;  Dxl.goalPosition(4, pos4);SerialUSB.println("I received 7.");
    SerialUSB.print("pos4 is:");SerialUSB.print(pos4);}

}


void loop() {
  toggleLED();
  delay(100);
  //open();
  //delay(1000);
  //close();
  //Pos1();
  //delay(1000);



}
