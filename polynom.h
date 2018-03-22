#pragma once
// Коклина, Фомченкова, Латышева, Копылов
class polynom
{
public:
	int pow; // многочлен будет этой степени
	int coef[100][2]; // коэффициенты многочлена в виде дробей, храним задом наперед (a0,a1,a2...)

	polynom ADD_PP_P(polynom p1, polynom p2) //сложение многосленов
	{
		return;
	};

	polynom SUB_PP_P(polynom p1, polynom p2) //вычитание многосленов
	{
		return;
	};

	polynom MUL_PQ_P(polynom p1, int chisl, int znam) //умножение на рациональное число
	{
		return;
	};

	polynom MUL_Pxk_P(polynom p1, int k) //умножение на x^k
	{
		return;
	};

	int LED_P_Q(polynom p1) //старший коэффициент
	{
		return;
	};

	int DEG_P_N(polynom p1) //степень многочлена
	{
		return;
	};

	int FAC_P_Q(polynom p2) //вынесение НОК и НОД, надо возвращать два числа, придумай что-нибудь или разбей на две функции
	{
		return;
	};

	polynom MUL_PP_P(polynom p1, polynom p2) //умножение многосленов
	{
		return;
	};

	polynom DIV_PP_P(polynom p1, polynom p2) //частное от деления многочлена на многочлен
	{
		return;
	};

	polynom MOD_PP_P(polynom p1, polynom p2) //остаток от деления многочлена на многочлен
	{
		return;
	};

	polynom GCF_PP_P(polynom p1, polynom p2) //НОД многосленов
	{
		return;
	};

	polynom DER_P_P(polynom p1) //производная многочлена
	{
		return;	
	};

	polynom NMR_P_P(polynom p1) //преобразование корней
	{
		return;
	};
}