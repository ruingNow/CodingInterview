package nwpu.edu.cn428;
//description:从1到n和为m的组合
//@author :wisdom
//data:2017/6/21

import java.util.Scanner;
public class SearchSomeSureValue {
	static int  length;
	static void findCombination(int n,int m,int flag[]){
		if(n<1||m<1){
			return ;
		}
		if(n>m){
			n = m;
		}
		if(n==m){
			flag[n-1] = 1;
			for(int i=0;i<length;i++){
				if(flag[i]==1){
					System.out.println(i+1+" ");
				}
			}
			System.out.println();       
			flag[n-1] = 0;
		}
		flag[n-1] = 1;                     
		findCombination(n-1,m-n,flag);
		
		flag[n-1] = 0;                  
		findCombination(n-1,m,flag);
	}
	public static void main(String args[]){
		int n,m;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		length = n;
		int [] flag = new int[n];        
		findCombination(n,m,flag);       
	}
}
