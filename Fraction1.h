#pragma once
#include "celoe.h"
#include "N_Number.h"


class fraction
{
public:
	celoe chislitel;	 // celoe 
	N_Number znamenatel; // natural

	fraction RED_Q_Q() // reduction of fractions
	{
		N_Number NOD,
			bufferForChisl;						// for the NOD
		fraction* buffer;
		buffer = (fraction*)malloc(sizeof(fraction));   // copy of object
		buffer = this;

		bufferForChisl = chislitel.ABS_Z_N();			// numerator to natural for find the NOD
		NOD = bufferForChisl.GCF_NN_N(znamenatel);
		buffer->chislitel = buffer->chislitel.DIV_ZZ_Z(NOD);	// reduction
		buffer->znamenatel = NOD.DIV_NN_N(buffer->znamenatel);
		return *buffer;
	};

	bool INT_Q_B() // if rational - 1, else - 0
	{
		fraction* buffer;
		buffer = (fraction*)malloc(sizeof(fraction)); // copy of object
		*buffer = this->RED_Q_Q(); // reduce the fraction

		if ((buffer->znamenatel.number[0] == 1) && (buffer->znamenatel.last_position == 1)) {
			free(buffer);
			return 1; // not rational
		}
		else {
			free(buffer);
			return 0; // fraction
		}
	};

	fraction TRANS_Z_Q(celoe c1) // integer to fraction
	{
		fraction* buffer;  
		buffer = (fraction*)malloc(sizeof(fraction));

		N_Number a;
		a.number[1] = { 1 };
		a.last_position = 1;

		buffer->chislitel = c1;
		buffer->znamenatel = a;

		return *buffer;
	};

	celoe TRANS_Q_Z() // fraction to integer
	{
		fraction* buffer;
		buffer = (fraction*)malloc(sizeof(fraction));
		buffer = this;

		celoe chisl;
		chisl = buffer->chislitel;

		return chisl;
	};

	fraction ADD_QQ_Q(fraction f1) // fraction + fraction
	{
		return;
	};

	fraction SUB_QQ_Q(fraction f1) // fraction - fraction
	{
		return;
	};

	fraction MUL_QQ_Q(fraction f1) // fraction * fraction
	{
		fraction* buffer;
		buffer = (fraction*)malloc(sizeof(fraction));
		buffer = this;

		buffer->chislitel = buffer->chislitel.MUL_ZZ_Z(f1.chislitel); 
		buffer->znamenatel = buffer->znamenatel.MUL_NN_N(f1.znamenatel);
		return *buffer;
	};

	fraction DIV_QQ_Q(fraction f1) // fraction / fraction
	{
		fraction* buffer;
		N_Number znamF1;
		celoe chislF1;
		buffer = (fraction*)malloc(sizeof(fraction));
		buffer = this;
		// flip the fraction
		chislF1 = chislF1.TRANS_N_Z(f1.znamenatel);  // znamenatel -> 4islitel (mne ne nravitsya kak vizivaetsya metod)
		chislF1.Is_Posotive = f1.chislitel.Is_Posotive; // sign of numerator
		buffer->chislitel = buffer->chislitel.MUL_ZZ_Z(chislF1);

		znamF1 = f1.chislitel.TRANS_Z_N(); 
		buffer->znamenatel = buffer->znamenatel.MUL_NN_N(znamF1); 
		return *buffer;
	};
};
// my englesh is very well