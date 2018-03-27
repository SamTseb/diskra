#ifndef N_NUMBER_H_INCLUDED
#define N_NUMBER_H_INCLUDED
#include <iostream>

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

			for(int j = i-1, z = 0; j >= 0; z++, j--) number[z]=static_cast<int>(str[j]); // Push number

		}


    N_Number Return_Number()
    {
        N_Number number_0;
        number_0.last_position=last_position;
        for(int i=0;i<number_0.last_position;i++)
            number_0.number[i]=number[i];
        return number_0;
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
    int NZER_N_B()
    {
        if((last_position==1) && (number[0]==0)) return 0; //0 - âûâîäèì "íåò", 1 - âûâîäèì "äà".
        else return 1;
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
        N_Number number_1=Return_Number();
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
        if(COM_NN_D(number_2)==2)
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
            while(number[last_position-1]==0)
                last_position--;
        }
        else
            if(COM_NN_D(number_2)==0)
            {
                last_position=1;
                number[0]=0;
            }
            else
            {
                last_position=1;
                number[0]=-1;
            }
        number_2=Return_Number();
        return number_2; //Âîçâðàùàåò -1, åñëè ïåðâîå ÷èñëî ìåíüøå âòîðîãî.
    }
    N_Number MUL_ND_N(int numeral)
    {
        if(numeral==0)
        {
            number[0]=0;
            last_position=1;
        }
        else
        {
            last_position++;
            number[last_position-1]=0;
            int borrow=0;
            for(int i=0;i<last_position;i++)
            {
                number[i]=number[i]*numeral+borrow;
                borrow=0;
                if(number[i]>=10)
                {
                    borrow=int(number[i]/10);
                    number[i]=number[i]%10;
                }
            }
            if(number[last_position-1]==0) last_position--;
        }
        N_Number number_0;
        number_0.last_position=last_position;
        for(int i=0;i<number_0.last_position;i++)
            number_0.number[i]=number[i];
        return number_0;
    }
    N_Number MUL_Nk_N(int numeral)
    {
        if(((number[0]!=0) || (last_position!=1)) && (numeral!=0))
        {
            for(int i=0;i<last_position;i++)
                number[last_position+numeral-1-i]=number[last_position-1-i];
            last_position=last_position+numeral;
            for(int i=0;i<numeral;i++)
                number[i]=0;
        }
        N_Number number_0;
        number_0.last_position=last_position;
        for(int i=0;i<number_0.last_position;i++)
            number_0.number[i]=number[i];
        return number_0;
    }
    N_Number MUL_NN_N(N_Number number_2)
    {
        N_Number sum,number_3;
        sum.last_position=1;
        sum.number[0]=0;
        for(int i=0;i<number_2.last_position;i++)
        {
            number_3=Return_Number();
            number_3=number_3.MUL_ND_N(number_2.number[i]);
            number_3=number_3.MUL_Nk_N(i);
            sum=sum.ADD_NN_N(number_3);
        }
        return sum;
    }
    N_Number SUB_NDN_N(N_Number number_2,int numeral)
    {
        number_2=number_2.MUL_ND_N(numeral);
        number_2=SUB_NN_N(number_2);
        return number_2;
    }
    N_Number DIV_NN_Dk(N_Number number_2)
    {
        N_Number answer;
        if((NZER_N_B()==0) || (number_2.NZER_N_B()==0))
        {
            answer.last_position=1;
            answer.number[0]=-2;
        }
        else
        {
            if(COM_NN_D(number_2)==1)
            {
                answer=Return_Number();
                last_position=number_2.last_position;
                for(int i=0;i<last_position;i++)
                    number[i]=number_2.number[i];
                number_2=answer;
            }
            int j=last_position-1;
            answer.last_position=number_2.last_position;
            for(int i=answer.last_position-1;i>=0;i--)
            {
                answer.number[i]=number[j];
                j--;
            }
            int position=j+1;
            if(answer.COM_NN_D(number_2)==1)
            {
                answer.last_position++;
                for(int i=answer.last_position-1;i>0;i--)
                    answer.number[i]=answer.number[i-1];
                answer.number[0]=number[j];
                position--;
            }
            int numeral=0;
            while((answer.COM_NN_D(number_2)==2) || (answer.COM_NN_D(number_2)==0))
            {
                answer.SUB_NN_N(number_2);
                numeral++;
            }
            answer.last_position=1;
            answer.number[0]=numeral;
            answer.MUL_Nk_N(position);
        }
        return answer; //Âîçâðàùàåò -2, åñëè ïûòàåìñÿ äåëèòü íà 0.
    }
    N_Number DIV_NN_N(N_Number number_2)
    {
        N_Number answer;
        answer.last_position=1;
        if((NZER_N_B()==0) || (number_2.NZER_N_B()==0))
            answer.number[0]=-2;
        else
        {
            answer.number[0]=0;
            N_Number number_0;
            if(COM_NN_D(number_2)==1)
            {
                number_0=Return_Number();
                last_position=number_2.last_position;
                for(int i=0;i<last_position;i++)
                    number[i]=number_2.number[i];
                number_2=number_0;
            }
            number_0=Return_Number();
            while(number_0.COM_NN_D(number_2)!=1)
            {
                answer=answer.ADD_NN_N(number_0.DIV_NN_Dk(number_2));
                number_0=number_0.SUB_NN_N(number_2.MUL_NN_N(number_0.DIV_NN_Dk(number_2)));
            }
        }
        return answer; //Âîçâðàùàåò -2, åñëè ïûòàåìñÿ äåëèòü íà 0.
    }
    N_Number MOD_NN_N(N_Number number_2)
    {
        N_Number answer;
        answer.last_position=1;
        if((NZER_N_B()==0) || (number_2.NZER_N_B()==0))
            answer.number[0]=-2;
        else
        {
            answer.number[0]=0;
            if(COM_NN_D(number_2)==1)
            {
                answer=Return_Number();
                last_position=number_2.last_position;
                for(int i=0;i<last_position;i++)
                    number[i]=number_2.number[i];
                number_2=answer;
            }
            answer=SUB_NN_N(DIV_NN_N(number_2).MUL_NN_N(number_2));
        }
        return answer; //Âîçâðàùàåò -2, åñëè ïûòàåìñÿ äåëèòü íà 0.
    }
    N_Number GCF_NN_N(N_Number number_2)
    {
        N_Number number_1=Return_Number();
        while((number_1.NZER_N_B()!=0) && (number_2.NZER_N_B()!=0))
        {
            if(number_1.COM_NN_D(number_2)==2)
                number_1=number_1.MOD_NN_N(number_2);
            else
                number_2=number_2.MOD_NN_N(number_1);
        }
        return number_1.ADD_NN_N(number_2);
    }
    N_Number LCM_NN_N(N_Number number_2)
    {
        if((MUL_NN_N(number_2).NZER_N_B()==0) && (ADD_NN_N(number_2).NZER_N_B()!=0)) return MUL_NN_N(number_2);
        if((NZER_N_B()==0) && (number_2.NZER_N_B()==0))
        {
            number_2.number[0]=-3;
            return number_2; //Âîçâðàùàåò -3, åñëè îáà ÷èñëà ðàâíû 0.
        }
        return MUL_NN_N(number_2).DIV_NN_N(GCF_NN_N(number_2));
    }
};

#endif // N_NUMBER_H_INCLUDED
