/*
DASHBOARD by Andrés Saumell Caminos

Programa inicial "main".
Utiliza la base Free RTOS que incluye ESP32 en el Arduino IDE.
Las tareas están organizadas de tal manera que las que cambian las variables importantes, las ejecute el Core 0.
Las tareas que dibujan la pantalla y solo visualizan las variables, están en el Core 1.
*/

#include "uss.h"
#include "IMU9.h"

TaskHandle_t HandleIMU;
TaskHandle_t HandleUSS;
TaskHandle_t HandleCanBus;
TaskHandle_t HandleScreen;

void TaskIMU(void * parameter)
{
	//long timer;	//Variable para controlar el tiempo que se tarda en hacer la tarea
	while(1)	//Bucle infinito para que la tarea se ejecute siempre.
	{
    long timer = millis();
		Serial.println("Task IMU is running");

    //CODE
    float t1 = testLoad();
    delay(5);
		Serial.print("RESULTADO: ");
    Serial.println(t1);

		Serial.print("Task IMU finished in ");
		Serial.println(millis() - timer);

    delay(1000);
	}
}

void TaskUSS(void * parameter)
{
	//long timer;	//Variable para controlar el tiempo que se tarda en hacer la tarea
	while(1)	//Bucle infinito para que la tarea se ejecute siempre.
	{
		long timer = millis();
		Serial.println("Task USS is running");

		//CODE
    //testLoad();
    delay(5000);
		
		Serial.print("Task USS finished in ");
		Serial.println(millis() - timer);

    delay(1000);
	}
}

void TaskCanBus(void * parameter)
{
	//long timer;	//Variable para controlar el tiempo que se tarda en hacer la tarea
	while(1)	//Bucle infinito para que la tarea se ejecute siempre.
	{
		long timer = millis();
		Serial.println("Task CanBus is running");

		//CODE
		//testLoad();
    delay(10000);

		Serial.print("Task CanBus finished in ");
		Serial.println(millis() - timer);

    delay(1000);
	}
}

void TaskScreen(void * parameter)
{
	//long timer;	//Variable para controlar el tiempo que se tarda en hacer la tarea
	while(1)	//Bucle infinito para que la tarea se ejecute siempre.
	{
		long timer = millis();
		Serial.println("Task Screen is running");
    
		//CODE
    //testLoad();
		
		Serial.print("Task Screen finished in ");
		Serial.println(millis() - timer);

    delay(1000);
	}
}

void ISR_test()
{
  Serial.print("Interrupcion - TIEMPO: ");
  Serial.println(millis());
}


////////////////////////////////////////////////////////


void setup() {
	Serial.begin(115200);
  delay(1000);

  touchAttachInterrupt(T3, ISR_test, 40);
	
	xTaskCreatePinnedToCore(TaskIMU, "Task IMU", 10000, NULL, 1, &HandleIMU, 0);
  xTaskCreatePinnedToCore(TaskUSS, "Task USS", 10000, NULL, 1, &HandleUSS, 0);  
  xTaskCreatePinnedToCore(TaskCanBus, "Task Can Bus", 10000, NULL, 1, &HandleCanBus, 0);
  xTaskCreatePinnedToCore(TaskScreen, "Task Screen", 10000, NULL, 1, &HandleScreen, 1);
  }

void loop() {
	//Elimina la funcion "loop" del planificador de RTOS para no perder tiempo.
	vTaskDelete(NULL);

}