/**
1. 사용 부품                         수량
  ㄱ. 아두이노 나노                   x1
  ㄴ. 아두이노 나노 CNC Shield V4     x1
  ㄷ. NEMA17 17HS4023 스텝모터        x1
  ㄹ. A4988 스텝모터 드라이버         x1

2. CNC Shield 결선
  ㄱ. X
    EN    - D8(공통)
    DIR   - D2
    STEP  - D5

  ㄴ. Y
    EN    - D8(공통)
    DIR   - D3
    STEP  - D6

  ㄷ. Z
    EN    - D8(공통)
    DIR   - D4
    STEP  - D7
*/


#define DIR   2 
#define STEP  5
#define EN    8

#define SW1   12

#define TRUE  1 
#define FALSE 0

#define STEP1 200
void step(boolean dir, int steps, unsigned int time);

void setup() {
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
}



void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(SW1) == LOW){
    digitalWrite(EN,LOW);
    do{
      step(TRUE, STEP1, 800);
    }while(digitalRead(SW1) == LOW);
  }
  
  else if(digitalRead(SW1) == HIGH) {
    digitalWrite(EN, HIGH);
  }
}

void step(boolean dir, int steps, unsigned int time){
  digitalWrite(DIR, dir);
  for(int i = 0; i < steps; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(time);
    digitalWrite(STEP, LOW);
    delayMicroseconds(time);
  }
}
