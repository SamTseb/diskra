#pragma once
// Коклина, Фомченкова, Латышева, Мосокина
class polynom
{
public:
	int pow; // многочлен будет этой степени
	Drob body[100]; // коэффициенты многочлена в виде дробей, храним задом наперед (a0,a1,a2...)

	polynom ADD_PP_P(polynom p1) //сложение многосленов
	{
		polynom copy, new_polynom; 
		int k = 0, i; 

		copy.pow = pow; 

		for (i = 0; i < copy.pow; i++) 
		copy.body[i] = body[i]; 


		for (i = 0; i < copy.pow && i < p1.pow; i++) // сложение коэффициентов при переменных с одинаковой степенью 
		{ 
			new_polynom.body[i] = ADD_QQ_Q(p1); 
			k++; 
		} 

		for (i = k; i < copy.pow || i < p1.pow; i++) // копирование коэффициентов при переменных "без пары" в новый полином 
		{ 
			new_polynom.body[i] = (copy.pow > p1.pow) ? copy.body[i] : p1.body[i]; 
		} 
		
		new_polynom.pow = (copy.pow > p1.pow) ? copy.pow : p1.pow; 

		return new_polynom; 
	};

	polynom SUB_PP_P(polynom p1) //вычитание многосленов
	{
		return;
	};

	polynom MUL_PQ_P(int chisl, int znam) //умножение на рациональное число
	{
		return;
	};

	polynom MUL_Pxk_P(int k) //умножение на x^k
	{
		return;
	};

	fraction LED_P_Q() //старший коэффициент
	{
		return;
	};

	int DEG_P_N() //степень многочлена
	{
		return;
	};

	fraction FAC_P_Q() //вынесение НОК и НОД, надо возвращать два числа, придумай что-нибудь или разбей на две функции
	{
		return;
	};

	polynom MUL_PP_P(polynom p1) //умножение многосленов
	{
		return;
	};

	polynom DIV_PP_P(polynom p1) //частное от деления многочлена на многочлен
	{
		polynom copy, new_polynom; 
		int k = 0, i;
		
		copy.pow = pow;
		for (i = 0; i < copy.pow; i++)
			copy.body[i] = body[i];

		while (p1.pow <= copy.pow) {
			for (i = p1.pow - 1; i != pow - 1; i++)
				p1.body[i] = 0;

			for (i = 0; i < copy.pow; i++)
				p1.body[i] *= copy.body[copy.pow - 1];

			for (i = 0; i < pow; i++)
				body[i] -= copy.body[i];

			new_polynom.body[k++] = copy.body[i];  // коэфициенты записаны в прямом порядке (an...a1,a0)
			copy.pow--;
		}
		
		new_polynom.pow = k;
		
		return new_polynom;
	};

	polynom MOD_PP_P(polynom p1) //остаток от деления многочлена на многочлен
	{
		polynom quotient = DIV_PP_P(p1);  // частное
		polynom copy, result;
		
		copy.pow = pow;
		for (int i = 0; i < pow; i++)
			copy.body[i] = body[i];

		for (int i = 0; i < quotient.pow; i++)
			body[i] = quotient.body[i];
		pow = quotient.pow;

		polynom QP = MUL_PP_P(p1);  

		for (int i = 0; i < copy.pow; i++)
			body[i] = copy.body[i];
		pow = copy.pow;

		return result = SUB_PP_P(QP);
	};

	polynom GCF_PP_P(polynom p1) //НОД многосленов
	{
		return;
	};

	polynom DER_P_P(polynom p1) //производная многочлена
	{
		return;	
	};

	polynom NMR_P_P() //преобразование корней
	{
		return;
	};
}
