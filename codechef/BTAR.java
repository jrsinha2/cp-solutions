import java.util.*;
import java.io.*;
import java.math.*;
class main
{	public static void main(String [] args)
	{	int t;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t>0)
		{	t--;
			long a1=0,a2=0,a3=0,value,n,sum=0,c=0;
			int i;
			n=sc.nextInt();
			for(i=0;i<n;i++)
			{	value=sc.nextInt();
				if(value%4==1)
					a1++;
				if(value%4==2)
					a2++;
				if(value%4==3)
					a3++;
				sum+=value;
			}
			if(sum%4==0)
			{	c= Math.min(a1,a3);
				a1-=c;
				a3-=c;
				c+=a2/2;
				a2%=2;
				if(a2>0)
				{	if(a1>0)
					{	c+=2;
						a2=0;
						a1-=2;
					}
					if(a3>0)
					{	c+=2;
						a2=0;
						a3-=2;
					}
				}
				if(a1>0)
				{	c+=((a1/4)*3);
				}	
				if(a3>0)
				{	c+=((a3/4)*3);
				}
				System.out.println(c);
			}
			else
				System.out.println("-1");
		}
	}
}	
