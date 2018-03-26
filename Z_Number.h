// Иванов, Ковалева

#ifndef Z_NUMBER_H_INCLUDED
#define Z_NUMBER_H_INCLUDED
#include "N_Number.h"

using namespace std;

const unsigned int SIZE = 100;

class Z_Number
{
public:
	int sign; //знак числа (1 — минус, 0 — плюс)
	int number[SIZE]; // массив цифр
	int last_position; //номер старшей позиции

	N_Number ABS_Z_N() // Абсолютная величина числа, результат - натуральное
	{		
		Z_Number temp;
		temp.sign = 0;
		temp.number = number;
		temp.last_position = last_position;
		N_Number result = temp.TRANS_Z_N();
		return result;
	}

	int POZ_Z_D() // Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
	{
		int result;
		if(sign == 1){
			result = 1;
		} else
		{
			if(number[last_position] == 0)
			{
				result = 0;
			} else
			{
				result = 2;
			}
		}
		return result;
	}

	Z_Number MUL_ZM_Z() // Умножение целого на (-1)
	{
		Z_Number result;
		result.last_position = last_position;
		for(int i = 0; i < last_position; i++)
		{
			result.number[i]=number[i];
		}
			
		if(sign == 1)
		{
			result.sign = 0;	
		} else
		{
			result.sign = 1;
		}
		return result;
	}

	Z_Number TRANS_N_Z(N_Number n1) // Преобразование натурального в целое
	{
		Z_Number result;
		result.last_position = last_position;
		result.sign = 0;
		for(int i = 0; i < last_position; i++)
		{
			result.number[i]=number[i];
		}
		return result;
	}

	N_Number TRANS_Z_N() // Преобразование целого неотрицательного в натуральное
	{
		N_Number result;
		result.last_position = last_position;
		if (POZ_Z_D() == 2) {
			//тут мы пишем юзверю, что он не прав и число у него отрицательное
		} else
		{
			for(int i = 0; i < last_position; i++)
			{
				result.number[i]=number[i];
			}
		}
		return result;
	}

	Z_Number ADD_ZZ_Z(Z_Number z2) // Сложение целых чисел
	{
		Z_Number result;
		N_Number abs1 = ABS_Z_N();
		N_Number abs2 = z2.ABS_Z_N();
		if ((sign == 0) && (z2.sign == 0))
		{
			result.number = TRANS_N_Z(abs1.ADD_NN_N(abs2));
			result.sign = 0;
		} else
		{
			if ((sign == 1) && (z2.sign == 1))
			{
				result = TRANS_N_Z(abs1.ADD_NN_N(abs2));
				result.sign = 1;
			} else
			{
				int comp = abs1.COM_NN_D(abs2);
				if(comp == 1)
				{
					result = TRANS_N_Z(abs2.SUB_NN_N(abs1));
					result.sign = z2.sign;
				} else
				{
					result = TRANS_N_Z(abs1.SUB_NN_N(abs2));
					result.sign = sign;
				}
				}
			}	
		return result;
	} 

	Z_Number SUB_ZZ_Z(Z_Number z2) // Вычитание целых чисел
	{
		Z_Number result;
		Z_Number temp = z2.MUL_ZM_Z();
		
		N_Number abs1 = ABS_Z_N();
		N_Number absTemp = temp.ABS_Z_N();
		result = TRANS_N_Z(abs1.ADD_NN_N(absTemp));
		return result;
	}

	Z_Number MUL_ZZ_Z(Z_Number z2) // Умножение целых чисел
	{
		Z_Number result;
		N_Number abs1 = ABS_Z_N();
		N_Number abs2 = z2.ABS_Z_N();
		if (sign == z2.sign)
		{
			result = TRANS_N_Z(abs1.MUL_NN_N(abs2));
			result.sign = 0;
		} else {
			result = TRANS_N_Z(abs1.MUL_NN_N(abs2));
			result.sign = 1;
		}
		return result;
	}

	Z_Number DIV_ZZ_Z(Z_Number z2) // Частное от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)
	{
		Z_Number result;
		N_Number abs1 = ABS_Z_N();
		N_Number abs2 = z2.ABS_Z_N();
		if (sign == z2.sign)
		{
			result = TRANS_N_Z(abs1.DIV_NN_N(abs2));
			result.sign = 0;
		} else {
			result = TRANS_N_Z(abs1.DIV_NN_N(abs2));
			result.sign = 1;
		}
		return result;
	}

	Z_Number MOD_ZZ_Z(Z_Number z2) // Остаток от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)
	{
		Z_Number result;
		N_Number abs1 = ABS_Z_N();
		N_Number abs2 = z2.ABS_Z_N();
		if (sign == 0)
		{
			result = TRANS_N_Z(abs1.MOD_NN_N(abs2));
		} else
		{
			result = TRANS_N_Z( abs2.SUB_NN_N(abs1.MOD_NN_N(abs2)) );
		}
		return result;
	}

};

#endif
