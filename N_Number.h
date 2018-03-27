#ifndef N_NUMBER_H_INCLUDED
#define N_NUMBER_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

const unsigned int Size=100;

class N_Number
{
public:
    int number[Size],last_position;
    
		N_Number (string str){
			int i=0;

			while(str[i] != '/0') i++; // Scan number

			last_position = i-1;

			for(int j = i-1, z = 0; j >= 0; z++, j--) number[z]=str[j]; // Push number

		}
    
    int COM_NN_D(N_Number number_2)
    {
        if(last_position>number_2.last_position) return 2;
        if(last_position<number_2.last_position) return 1;
        if(last_position==number_2.last_position)
        {
            for(int i=last_position-1;i>=0;i--)
            {
                if(number[i]>number_2.number[i]) return 2;
                if(number[i]<number_2.number[i]) return 1;
            }
            return 0;
        }
        return 0;
    }
    string NZER_N_B()
    {
        if((last_position==1) && (number[0]==0)) return "íåò";
        else return "äà";
    }
    N_Number ADD_1N_N()
    {
        last_position++;
        number[last_position-1]=0;
        for(int i=0;i<last_position;i++)
        {
            if(number[i]==9) number[i]=0;
            else
            {
                number[i]++;
                break;
            }
        }
        if(number[last_position-1]==0) last_position--;
        N_Number number_1;
        number_1.last_position=last_position;
        for(int i=0;i<number_1.last_position;i++)
            number_1.number[i]=number[i];
        return number_1;
    }
    N_Number ADD_NN_N(N_Number number_2)
    {
        int remainder=0;
        if(number_2.last_position<last_position)
        {
            for(int i=number_2.last_position;i<last_position;i++)
                number_2.number[i]=0;
            number_2.last_position=last_position;
        }
        for(int i=0;i<last_position;i++)
        {
            number_2.number[i]=number_2.number[i]+number[i]+remainder;
            remainder=0;
            if(number_2.number[i]>=10)
            {
                remainder=1;
                number_2.number[i]=number_2.number[i]-10;
            }
        }
        if(remainder==1)
        {
            number_2.last_position++;
            number_2.number[number_2.last_position-1]=0;
            for(int i=last_position;i<number_2.last_position;i++)
            {
                if(number_2.number[i]==9) number_2.number[i]=0;
                else
                {
                    number_2.number[i]++;
                    break;
                }
            }
            if(number_2.number[number_2.last_position-1]==0) number_2.last_position--;
        }
        return number_2;
    }
    N_Number SUB_NN_N(N_Number number_2)
    {
        if((COM_NN_D(number_2)==2) || (COM_NN_D(number_2)==0))
        {
            for(int i=0;i<number_2.last_position;i++)
            {
                if(number[i]>=number_2.number[i]) number[i]=number[i]-number_2.number[i];
                else
                {
                    for(int j=i+1;j<last_position;j++)
                    {
                        if(number[j]==0) number[j]=9;
                        else
                        {
                            number[j]--;
                            break;
                        }
                    }
                    number[i]=number[i]+10-number_2.number[i];
                }
            }
            if(number[last_position-1]==0) last_position--;
        }
        number_2.last_position=last_position;
        for(int i=0;i<number_2.last_position;i++)
            number_2.number[i]=number[i];
        return number_2;
    }
};

#endif // N_NUMBER_H_INCLUDED
