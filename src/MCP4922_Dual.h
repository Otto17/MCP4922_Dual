/*
	Библиотека для удобного управления 2-х канальным ЦАП "MCP4922".
	
	Управление производится каждым каналом по отдельности.
	Изменение значений на одном канале, не влияют на выход второго канала.
	
	Дата создания: 15.01.2024г.
	Версия: 1.0
	Автор: Otto.

*/



#ifndef MCP4922_Dual_h
#define MCP4922_Dual_h

#include "Arduino.h"
#include <SPI.h>		// Подключаем библиотеку для работы с SPI


class MCP4922_Dual {
  public:
    MCP4922_Dual(byte SDI, byte SCK,byte CS);		// Выводы: SDI(MOSI), SCK, CS
    void SetA(int A);		// Функция установки значения для первого (A) канала
	void SetB(int B);		// Функция установки значения для второго (B) канала

  private:
    byte _SDI;
    byte _SCK;
    byte _CS;


//Функции для отправки данных по SPI на каналы A и B
    void sendValSPI_A(int A);
	void sendValSPI_B(int B);
};

#endif
