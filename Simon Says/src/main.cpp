#include <Arduino.h>
#include <ezButton.h>

const int redLedPin = 2;
const int yellowLedPin = 3;
const int greenLedPin = 4;


int whichLightComputer = 0; // een int die opslaat welk lampje de computer kiest en in de array opslaat
                            // rood = 1, geel = 2, groen = 3
int whichLightPlayer = 0;

int computerSequenceEasy[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int playerSequenceEasy[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int computerSequenceMedium[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int playerSequenceMedium[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int computerSequenceHard[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int playerSequenceHard[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


int gameDifficulty;
int turnIndicator = 1;
bool playerHasLost = false;


int redLedState = LOW;
int yellowLedState = LOW;
int greenLedState = LOW;

ezButton leftButton(7);
ezButton middleButton(8);
ezButton rightButton(12);


void turnOnRed()
{
  digitalWrite(redLedPin, HIGH);
  redLedState = HIGH;
  delay(500);
  digitalWrite(redLedPin, LOW);
  redLedState = LOW;
  delay(500);
}
void turnOnYellow()
{
  digitalWrite(yellowLedPin, HIGH);
  yellowLedState = HIGH;
  delay(500);
  digitalWrite(yellowLedPin, LOW);
  yellowLedState = LOW;
  delay(500);
}
void turnOnGreen()
{
  digitalWrite(greenLedPin,HIGH);
  greenLedState = HIGH;
  delay(500);
  digitalWrite(greenLedPin, LOW);
  greenLedState = LOW;
  delay(500);
}


void changeRedLight()
{
  if (redLedState == LOW)
  {
    if (leftButton.isPressed())
    {
      digitalWrite(redLedPin, HIGH);
      redLedState = HIGH;
      whichLightPlayer = 1;

    }
  }
  else if (redLedState == HIGH)
  {
    if (leftButton.isPressed())
    {
      digitalWrite(redLedPin, LOW);
      redLedState = LOW;
    }
  }

}
void changeYellowLight()
{
  if (yellowLedState == LOW)
  {
    if (middleButton.isPressed())
    {
      digitalWrite(yellowLedPin, HIGH);
      yellowLedState = HIGH;
      whichLightPlayer = 2;
    }
  }
  else if (yellowLedState == HIGH)
  {
    if (middleButton.isPressed())
    {
      digitalWrite(yellowLedPin, LOW);
      yellowLedState = LOW;
    }
  }
}
void changeGreenlight()
{
  if (greenLedState == LOW)
  {
    if (rightButton.isPressed())
    {
      digitalWrite(greenLedPin, HIGH);
      greenLedState = HIGH;
      whichLightPlayer = 3;
    }
  }
  else if (greenLedState == HIGH)
  {
    if (rightButton.isPressed())
    {
      digitalWrite(greenLedPin, LOW);
      greenLedState = LOW;
    }
  }

}
void chooseRandomLight()
{
  int randomNumber = random(1, 4);

  switch(randomNumber)
  {
    case 1:
     whichLightComputer = 1;
     digitalWrite(redLedPin, HIGH);
     redLedState = HIGH;
     delay(1000);
     digitalWrite(redLedPin, LOW);
     redLedState = LOW;
     delay(200);
     break;
    case 2:
     whichLightComputer = 2;
     digitalWrite(yellowLedPin, HIGH);
     yellowLedState = HIGH;
     delay(1000);
     digitalWrite(yellowLedPin, LOW);
     yellowLedState = LOW;
     delay(200);
     break;
    case 3:
     whichLightComputer = 3;
     digitalWrite(greenLedPin, HIGH);
     greenLedState = HIGH;
     delay(1000);
     digitalWrite(greenLedPin, LOW);
     greenLedState = LOW;
     delay(200);
     break;
  }
}

void turnOffLeds()
{
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  redLedState = LOW;
  yellowLedState = LOW;
  greenLedState = LOW;
}


void gameStart()
{
  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  redLedState = HIGH;
  yellowLedState = HIGH;
  greenLedState = HIGH;
  delay(750);

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  redLedState = LOW;
  yellowLedState = LOW;
  greenLedState = LOW;
  delay(750);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  redLedState = HIGH;
  yellowLedState = HIGH;
  greenLedState = HIGH;
  delay(750);

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  redLedState = LOW;
  yellowLedState = LOW;
  greenLedState = LOW;
  delay(750);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  redLedState = HIGH;
  yellowLedState = HIGH;
  greenLedState = HIGH;
  delay(750);

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  redLedState = LOW;
  yellowLedState = LOW;
  greenLedState = LOW;
  delay(750);  

  Serial.println("Welcome to the game of Simon Says!");
  Serial.println("Please choose your difficulty:");
  Serial.println("1: Kids Corner.");
  Serial.println("2: Slightly Painful");
  Serial.println("3: Lol, you a pro or what?");
  Serial.println("Please input 1, 2 or 3:");
  
  while(Serial.available() == 0)
  {
  
  }
    gameDifficulty = Serial.read() - 48;

    Serial.println("Wow ok....");
    delay(750);
    Serial.println("Good luck!");



    delay(1500);

   

  
}


void computerTurnEasy()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {

    if (computerSequenceEasy[i] > 0)
    {
      if (computerSequenceEasy[i] == 1)
      {
        turnOnRed();
      }
      else if (computerSequenceEasy[i] == 2)
      {
        turnOnYellow();
      }
      else if (computerSequenceEasy[i] == 3)
      {
        turnOnGreen();
      }    
    }
    else if (computerSequenceEasy[i] == 0)
    {
      chooseRandomLight();
      computerSequenceEasy[i] = whichLightComputer;
      whichLightComputer = 0;
    }
  }

    

  }
}
void playerTurnEasy()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {
    while (whichLightPlayer == 0)
    {
      leftButton.loop();
      middleButton.loop();
      rightButton.loop();
      

      changeRedLight();
      changeYellowLight();
      changeGreenlight();
    }
    playerSequenceEasy[i] = whichLightPlayer;

    if (playerSequenceEasy[i] != computerSequenceEasy[i])
    {
      Serial.println("Sorry, wrong answer!");
      Serial.println("You Lose!");
      playerHasLost = true;
      delay(500);
      turnOffLeds();
      break;
    }
    else if (playerSequenceEasy[i] == computerSequenceEasy[i])
    {
      whichLightPlayer = 0;
      delay(500);
      turnOffLeds();
     
    }
  }
delay(1000);
 }
}

void computerTurnMedium()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {

    if (computerSequenceMedium[i] > 0)
    {
      if (computerSequenceMedium[i] == 1)
      {
        turnOnRed();
      }
      else if (computerSequenceMedium[i] == 2)
      {
        turnOnYellow();
      }
      else if (computerSequenceMedium[i] == 3)
      {
        turnOnGreen();
      }    
    }
    else if (computerSequenceMedium[i] == 0)
    {
      chooseRandomLight();
      computerSequenceMedium[i] = whichLightComputer;
      whichLightComputer = 0;
    }
    
  }  
 }
}
void playerTurnMedium()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {
    while (whichLightPlayer == 0)
    {
      leftButton.loop();
      middleButton.loop();
      rightButton.loop();
      

      changeRedLight();
      changeYellowLight();
      changeGreenlight();
    }
    playerSequenceMedium[i] = whichLightPlayer;

    if (playerSequenceMedium[i] != computerSequenceMedium[i])
    {
      Serial.println("Sorry, wrong answer!");
      Serial.println("You Lose!");
      playerHasLost = true;
      delay(500);
      turnOffLeds();
      break;
    }
    else if (playerSequenceMedium[i] == computerSequenceMedium[i])
    {
      whichLightPlayer = 0;
      delay(500);
      turnOffLeds();
     
    }
  }
delay(1000);  
 }
}

void computerTurnHard()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {

    if (computerSequenceHard[i] > 0)
    {
      if (computerSequenceHard[i] == 1)
      {
        turnOnRed();
      }
      else if (computerSequenceHard[i] == 2)
      {
        turnOnYellow();
      }
      else if (computerSequenceHard[i] == 3)
      {
        turnOnGreen();
      }    
    }
    else if (computerSequenceHard[i] == 0)
    {
      chooseRandomLight();
      computerSequenceHard[i] = whichLightComputer;
      whichLightComputer = 0;
    }
    
  }
 }    
}
void playerTurnHard()
{
 if (playerHasLost == false)
 {
  for (int i = 0; i < turnIndicator; i++)
  {
    while (whichLightPlayer == 0)
    {
      leftButton.loop();
      middleButton.loop();
      rightButton.loop();
      

      changeRedLight();
      changeYellowLight();
      changeGreenlight();
    }
    playerSequenceHard[i] = whichLightPlayer;

    if (playerSequenceHard[i] != computerSequenceHard[i])
    {
      Serial.println("Sorry, wrong answer!");
      Serial.println("You Lose!");
      playerHasLost = true;
      delay(500);
      turnOffLeds();
      break;
    }
    else if (playerSequenceHard[i] == computerSequenceHard[i])
    {
      whichLightPlayer = 0;
      delay(500);
      turnOffLeds();
     
    }
  }
delay(1000);  
 } 
}

void gameSkeleton()
{
  int gameTurns;

  if (gameDifficulty == 1)
  {
    gameTurns = 8;
  }
  else if (gameDifficulty == 2)
  {
    gameTurns = 12;
  }
  else if (gameDifficulty == 3)
  {
    gameTurns = 16;
  }

  for (int i = 0; i < gameTurns; i++)
  {
    switch (gameDifficulty)
    {
      case 1:
       computerTurnEasy();
       playerTurnEasy();
       turnIndicator++;
       break;
      case 2:
       computerTurnMedium();
       playerTurnMedium();
       turnIndicator++;
       break;
      case 3: 
       computerTurnHard();
       playerTurnHard();
       turnIndicator++;
       break;
    }


  }


}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A0));


  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);


  leftButton.setDebounceTime(25);
  middleButton.setDebounceTime(25);
  rightButton.setDebounceTime(25);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (playerHasLost == true)
 {
    Serial.println("Please reset the Arduino to play again.");
    delay(5000);
 }

 if (playerHasLost == false)
 {

  gameStart();


  if (gameDifficulty == 1)
  {
    while (playerHasLost == false)
    {
    gameSkeleton();
    
    }
  }

  else if (gameDifficulty == 2)
  {
    while (playerHasLost == false)
    {
    gameSkeleton();
    }
  }

  else if (gameDifficulty == 3)
  {
    while (playerHasLost == false)
    {
    gameSkeleton();
    }
  }

  else {
    Serial.println("Please enter a valid number!");
  }
 }



}