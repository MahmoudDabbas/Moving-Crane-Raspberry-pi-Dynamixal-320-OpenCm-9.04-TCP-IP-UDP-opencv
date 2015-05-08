#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM_1 1
#define ID_NUM_2 2
#define ID_NUM_3 3
/* Control table defines */
#define GOAL_SPEED 32

#define CCW_Angle_Limit 8
#define CONTROL_MODE 11

Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup() {
  // Dynamixel 2.0 Protocol -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  
    Dxl.wheelMode(ID_NUM_1); //wheelMode() is to use wheel mode
    Dxl.wheelMode(ID_NUM_2); //wheelMode() is to use wheel mode
    pinMode(BOARD_LED_PIN, OUTPUT);
    pinMode(D10, INPUT_PULLDOWN);
    pinMode(D11, INPUT_PULLDOWN);
    pinMode(D12, INPUT_PULLDOWN);

 }
int speed = 500ww;

void loop() 
{
   int input2 = digitalRead(D10);
   int input3 = digitalRead(D12);
   int input4 = digitalRead(D11);

  if(input2==LOW&&input3==LOW&&input4==LOW)
  {  forward();
  delay(100);
  }

  if(input2==LOW&&input3==HIGH&&input4==LOW)
  {  backward();
  delay(100);
  }
  if(input2==HIGH&&input3==LOW&&input4==LOW)
  {  right();
  delay(100);
  }
  if(input2==HIGH&&input3==HIGH&&input4==LOW)
  {  left();
  delay(100);
  }
  if(input4==HIGH)
  {  stop();
  delay(100);
  }



}


void slow()
{
speed = 200;
}

void forward()
{
  //forward
  Dxl.goalSpeed(ID_NUM_2, speed| 0x400); 
  Dxl.goalSpeed(ID_NUM_1, speed); 
  digitalWrite(BOARD_LED_PIN, LOW); // set to as HIGH LED is turn-off  
}

void backward()
{
  //forward
  Dxl.goalSpeed(ID_NUM_2,speed); 
  Dxl.goalSpeed(ID_NUM_1,speed| 0x400); 
  digitalWrite(BOARD_LED_PIN, HIGH); // set to as HIGH LED is turn-off  
}

void right()
{
  //forward
  Dxl.goalSpeed(ID_NUM_2,speed| 0x400); 
  Dxl.goalSpeed(ID_NUM_1,speed| 0x400); 
  digitalWrite(BOARD_LED_PIN, HIGH); // set to as HIGH LED is turn-off  
}


void left()
{
  //forward
  Dxl.goalSpeed(ID_NUM_2,speed); 
  Dxl.goalSpeed(ID_NUM_1,speed); 
  digitalWrite(BOARD_LED_PIN, HIGH); // set to as HIGH LED is turn-off  
}

void stop()
{
  //forward
  Dxl.goalSpeed(ID_NUM_2,0); 
  Dxl.goalSpeed(ID_NUM_1,0); 
  digitalWrite(BOARD_LED_PIN, LOW); // set to as HIGH LED is turn-off  
}

