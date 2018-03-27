#pragma once
// Ęîâŕëĺâŕ, Čâŕíîâ
class celoe
{
public:
	bool Is_Posotive;
	int len;
	int bdy[100];
	
	celoe (string str){

		int i=0, start=0;
			if (str[0]=='-') start++;

		while(str[i] != '/0') i++; // Scan number

		for(int j = i-1, z = 0; j >= start; z++, j--) number[z]=str[j]; // Push number

		if (str[0]=='-') Is_Posotive = false;

	}

	
	// OR: natural chislo; лучше вот так, наверное. не очень эффективно, но похуй
	//     bool Is_Posotive; 

	celoe ABS_Z_N() // ěîäóëü
	{
		return;
	}

	int POZ_Z_D() // îďđĺäĺëĺíčĺ çíŕęŕ
	{
		return;
	}

	celoe MUL_ZM_Z() //óěíîćĺíčĺ íŕ -1
	{
		return;
	}

	self? TRANS_N_Z(natural n1) //ďĺđĺâîä â öĺëîĺ čç íŕňóđŕëüíîăî
	{
		return;
	}

	natural TRANS_Z_N() // ďĺđĺâîä â íŕňóđŕëüíîĺ
	{
		return;
	}

	celoe ADD_ZZ_Z(celoe c1) // ńëîćĺíčĺ
	{
		return;
	} 

	celoe SUB_ZZ_Z(celoe c1)// âű÷čňŕíčĺ
	{
		return;
	}

	celoe MUL_ZZ_Z(celoe c1)// óěíîćĺíčĺ
	{
		return;
	}

	celoe DIV_ZZ_Z(natural n1)//÷ŕńňíîĺ îň äĺëĺíčĺ
	{
		return;
	}

	celoe MOD_ZZ_Z(celoe c1)// îńňŕňîę îň äĺëĺíč˙
	{
		return;
	}


};
