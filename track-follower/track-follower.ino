//m1
int enA=10;
int in1=9;
int in2=8;
//m2
int enB=5;
int in3=7;
int in4=6;
//ir sensor
int leftIR=A0;
int rightIR=A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(leftIR,INPUT);
  pinMode(rightIR,INPUT);
  Serial.begin(9600);
}

void motorAction(int motorNum, int orientation, int spd){
  int pwm;
  int p1;
  int p2; 
  if (motorNum ==1){
    pwm=enA;
    p1=in1;
    p2=in2;
  }else if (motorNum ==2){
    pwm=enB;
    p1=in3;
    p2=in4;
  }else{
    return;
  }

  if (orientation == 0){
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
  } else if (orientation == 1){
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
  } else if (orientation == -1){
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
  }
  analogWrite(pwm,spd);
}


void loop() {
  int leftIRValue=analogRead(leftIR);
  int rightIRValue=analogRead(rightIR);
  Serial.print(leftIRValue);
  Serial.print("__");
  Serial.println(rightIRValue);
  
  if (leftIRValue>500 && rightIRValue>500){
    motorAction(1,1,70);
    motorAction(2,1,70);
  } else if (leftIRValue<500 && rightIRValue>500) {
    // go left
    motorAction(1,1,70);
    motorAction(2,-1,70);
   
  } else if (leftIRValue>500 && rightIRValue<500) {
    // go right
    motorAction(1,-1,70);
    motorAction(2,1,70);
  } else if (leftIRValue<500 && rightIRValue<500) {
    // stop
    motorAction(1,0,0);
    motorAction(2,0,0);
  }
}
