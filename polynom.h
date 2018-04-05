#pragma once
// Коклина, Фомченкова, Латышева, Мосокина
class polynom
{
public:
	int pow; // многочлен будет этой степени
	Drob body[100]; // коэффициенты многочлена в виде дробей, храним задом наперед (a0,a1,a2...)

	polynom ADD_PP_P(polynom p1) //сложение многочленов
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
			new_polynom.body[i] = (copy.pow > p1.pow) ? copy.body[i] : p1.body[i]; 
		
		new_polynom.pow = (copy.pow > p1.pow) ? copy.pow : p1.pow; 

		return new_polynom; 
	};

	polynom SUB_PP_P(polynom p1) //вычитание многочленов
	{
		polynom copy, new_polynom; 
		int k = 0, i; 

		copy.pow = pow; 

		for (i = 0; i < copy.pow; i++) 
			copy.body[i] = body[i]; 


		for (i = 0; i < copy.pow && i < p1.pow; i++) // вычитание коэффициентов при переменных с одинаковой степенью 
		{ 
			new_polynom.body[i] = SUB_QQ_Q(p1); 
			k++; 
		} 

		for (i = k; i < copy.pow || i < p1.pow; i++) // копирование коэффициентов при переменных "без пары" в новый полином 
			new_polynom.body[i] = (copy.pow > p1.pow) ? copy.body[i] : p1.body[i];  
		
		new_polynom.pow = (copy.pow > p1.pow) ? copy.pow : p1.pow; 

		return new_polynom; 
	};

	polynom MUL_PQ_P(int chisl, int znam) //умножение на рациональное число
	{
		// тут под вопросом
		polynom new_polynom;  
		int i; 

		new_polynom.pow = pow; 

		for (i = 0; i < new_polynom.pow; i++) // вычитание коэффициентов при переменных с одинаковой степенью 
		{ 
			new_polynom.body[i] = body[i]; 
			new_polynom.body[i] = MUL_QQ_Q(new_polynom); // вот этот момент! 
		} 

		return new_polynom; 
	};

	polynom MUL_Pxk_P(int k) //умножение на x^k
	{
		polynom copy, new_polynom; 
		int k, i; 

		copy.pow = pow; 

		for (i = 0; i < copy.pow; i++) 
			copy.body[i] = body[i]; 

		if (k > 0) 
		{ 
			for (i = 0; i < copy.pow; i++) 
 				new_polynom.body[i + k] = copy.body[i]; 
		} 
		else 
		{ 
			if(copy.pow-i+k>0) 
				new_polynom.body[i] = copy.body[i-k]; 
		} 

		return new_polynom; 
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

	polynom MUL_PP_P(polynom p1) //умножение многочленов
	{
		return;
	};

	polynom DIV_PP_P(polynom p1) //частное от деления многочлена на многочлен
	{
		polynom copy, new_polynom, temporary, quotient; 
		int k = 0, i;
		fraction led1, led2;
		
		copy.pow = pow;
		quotient.pow = pow;
		for (i = 0; i < copy.pow; i++) {
			copy.body[i] = body[i];
			quotient.body[i] = body[i];
		}
		
		new_polynom. pow = copy.pow - p1.pow;
		
		while (p1.pow <= quotient.pow) {
			led1 = LED_P_Q(quotient);
			led2 = LED_P_Q(p1);
			
			temporary.pow = quotient.pow - p1.pow;
			temporary.body[temporary.pow] = led1/led2;
			for (i = 0; i < temporary.pow - 1; i++)
				temporary.body[i] = 0;
			
			new_polynom = ADD_PP_P(temporary);
			quotient = SUB_PP_P(MUL_PP_P(p1, temporary));
		}
		
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

	polynom GCF_PP_P(polynom p1) //НОД многочленов
	{
		polynom copy, remainder; 
		int i;
		copy.pow = pow; 

		for (i = 0; i < pow; i++) 
			copy.body[i] = body[i];
		
		bool flag = true;
		while (flag == true){
			remainder = MOD_PP_P(p1); //находим остаток от деления многочленов
			remainder.pow = DEG_P_N(remainder); //если степень нулевая, НОД найден
			if (remainder.pow == 0) 
				flag = false;
			else {
				p1.pow = DEG_P_N(p1);
				for (i = 0; i < pow; i++) 
					body[i] = p1.body[i];
				for (i = 0; i < p1.pow; i++) 
					p1.body[i] = remainder.body[i];
			}
		}
		
		for (i = 0; i < copy.pow; i++) 
			body[i] = copy.body[i];
		pow = copy.pow;
		
		return p1;
	};

	polynom DER_P_P() //производная многочлена
	{
		polynom copy, new_polynom; 
		int i;
		
		for (i = 0; i < pow - 1; i++) 
			new_polynom.body[i] = (i+1)*body[i+1];
		new_polynom.body[pow] = 0;
		
		return new_polynom;	
	};

	polynom NMR_P_P() //преобразование корней
	{
		return;
	};
}
