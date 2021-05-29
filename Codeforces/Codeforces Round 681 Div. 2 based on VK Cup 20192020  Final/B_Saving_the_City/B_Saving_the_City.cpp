import java.io.*;
import java.io.IOException;
import java.math.BigInteger;
import java.util.*;








	//import javafx.util.Pair; 
	//import java.util.concurrent.LinkedBlockingDeque;







		
	public  class Codeforces {
		
			
			public static long mod = 1000000007 ;
			public static double epsilon=0.00000000008854;//value of epsilon
			public static InputReader sc = new InputReader(System.in);
			public static PrintWriter pw = new PrintWriter(System.out);
			public static Random rn=new Random();
			public static  Deque<pfactor> primeFactor(long n){//Return prime factors of a number
				/*class pfactor{
					long p=0,c=0;//p is prime number & c is its count
					pfactor(long p1,long c1){
						p=p1;
						c=c1;
					}
				} */
					Deque<pfactor> q=new LinkedList<>();
					//ArrayList<pfactor> a=new ArrayList<>();
					for(int i=2;i<=Math.sqrt(n);i++){
						if(n%i==0){
							int c=0;
							while(n%i==0){
								n/=i;
								c++;
							}
							q.add(new pfactor(i,c));
						}
					}
					if(n>1){
						q.add(new pfactor(n,1));
					}
					return q;
				}
			
			
			public static void solve(){
				int a=sc.nextInt();
				int b=sc.nextInt();
				String s=sc.nextLine();
				int f=0,zero=0;
				int ans=0;
				for(int i=0;i<s.length();i++){
					if(s.charAt(i)=='0')
					zero++;
					if(s.charAt(i)=='1'){
						if(f==0){ans+=a;
							zero=0;
							f=1;
						}
						if(zero==0)continue;
						ans+=Math.min(zero*b, a);
						zero=0;
						
					}
				}
				pw.println(ans);

			}
			
			
			
			
			public static void main(String[] args) throws Exception {
				// code starts.

				int q=sc.nextInt();
				while(q-->0){
					solve();
				}
				// Code ends...
				pw.flush();
				pw.close();
			}
			public static Comparator<Integer[]> MOquery(int block){
				return
				new Comparator<Integer[]>(){
					@Override
					public int compare(Integer a[],Integer b[]){
						int a1=a[0]/block;
						int b1=b[0]/block;
						if(a1==b1){
							if((a1&1)==1)
							return a[1].compareTo(b[1]);
							else{
								return b[1].compareTo(a[1]);
							}
						}
						return a1-b1;
					}
				};
			}
		
			public static Comparator<Long[]> column(int i){
				return 
				new Comparator<Long[]>() {
					@Override
					public int compare(Long[] o1, Long[] o2) {
						return o1[i].compareTo(o2[i]);//for ascending
						//return o2[i].compareTo(o1[i]);//for descending
					}
				};
			}
			public static Comparator<Integer[]> column(){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						//return o1[i].compareTo(o2[i]);//for ascending
						//return o2[i].compareTo(o1[i]);//for descending
						
						for(int i=0;i<o1.length;i++){
							if(o1[i].compareTo(o2[i])!=0)
							return o1[i].compareTo(o2[i]);
						}
						return 0;
					}
				};
			}
			public static Comparator<Integer[]> column2(){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						//return o1[i].compareTo(o2[i]);//for ascending
						//return o2[i].compareTo(o1[i]);//for descending
						int l1=0,l2=0;
						for(int i=0;i<o1.length-1;i++){
							l1+=o1[i];
							l2+=o2[i];
						}
						return l2-l1;
					}
				};
			}
			public static Comparator<Integer[]> dis(int k,Integer a[][]){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						//return o1[i].compareTo(o2[i]);//for ascending
						//return o2[i].compareTo(o1[i]);//for descending
						int l1=0,l2=0;
						for(int i=0;i<o1.length-1;i++){
							l1+=Math.abs(a[k][i]-o1[i]);
							l2+=Math.abs(a[k][i]-o2[i]);
						}
						return l2-l1;
					}
				};
			}
			public static Comparator<Integer[]> col(int i){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						//if(o1[i]-o2[i]!=0)
						return o1[i].compareTo(o2[i]);//for ascending
						//return o1[i+1].compareTo(o2[i+1]);
						//return o2[i].compareTo(o1[i]);//for descending
					}
				};
			}
			public static Comparator<Integer> des(){
				return 
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						//return o1[i].compareTo(o2[i]);//for ascending
						return o2.compareTo(o1);//for descending
					}
				};
			}
			public static Comparator<Integer> des(int dp[]){
				return 
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						//return o1[i].compareTo(o2[i]);//for ascending
						return dp[o2]-dp[o1];//for descending
					}
				};
			}
			
			
			
			
			public static String reverseString(String s){
				StringBuilder input1 = new StringBuilder(); 
				input1.append(s);  
				input1 = input1.reverse();
				return input1.toString();
			}
			public static int[] scanArray(int n){
				int a[]=new int [n];
				//Random x=new Random();
				for(int i=0;i<n;i++){
					a[i]=sc.nextInt();
				}
				
		
				return a;
			}
			public static long[] scanLongArray(int n){
				long a[]=new long [n];
				for(int i=0;i<n;i++)
				a[i]=sc.nextLong();
		
				return a;
			}
			public static String [] scanStrings(int n){
				String a[]=new String [n];
				for(int i=0;i<n;i++)
				a[i]=sc.nextLine();
		
				return a;
			}
			public static class InputReader {
		
				private final InputStream stream;
				private final byte[] buf = new byte[8192];
				private int curChar, snumChars;
				private SpaceCharFilter filter;
		
				public InputReader(InputStream stream) {
					this.stream = stream;
				}
		
				public int snext() {
					if (snumChars == -1)
						throw new InputMismatchException();
					if (curChar >= snumChars) {
						curChar = 0;
						try {
							snumChars = stream.read(buf);
						} catch (IOException e) {
							throw new InputMismatchException();
						}
						if (snumChars <= 0)
							return -1;
					}
					return buf[curChar++];
				}
		
				public int nextInt() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					int sgn = 1;
					if (c == '-') {
						sgn = -1;
						c = snext();
					}
					int res = 0;
					do {
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						res *= 10;
						res += c - '0';
						c = snext();
					} while (!isSpaceChar(c));
					return res * sgn;
				}
		
				public long nextLong() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					int sgn = 1;
					if (c == '-') {
						sgn = -1;
						c = snext();
					}
					long res = 0;
					do {
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						res *= 10;
						res += c - '0';
						c = snext();
					} while (!isSpaceChar(c));
					return res * sgn;
				}
		
				public int[] nextIntArray(int n) {
					int a[] = new int[n];
					for (int i = 0; i < n; i++) {
						a[i] = nextInt();
					}
					return a;
				}
		
				public String readString() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!isSpaceChar(c));
					return res.toString();
				}
		
				public String nextLine() {
					int c = snext();
					while (isSpaceChar(c))
						c = snext();
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!isEndOfLine(c));
					return res.toString();
				}
		
				public boolean isSpaceChar(int c) {
					if (filter != null)
						return filter.isSpaceChar(c);
					return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
				}
		
				private boolean isEndOfLine(int c) {
					return c == '\n' || c == '\r' || c == -1;
				}
		
				public interface SpaceCharFilter {
					public boolean isSpaceChar(int ch);
				}
			}
			
		}
		class SegmentTree{//l&R inclusive
			int s[],n;
			SegmentTree(int a[]){
				n=a.length;
				int l=(int)Math.ceil(Math.log(n)/Math.log(2));
				l=2*(int)Math.pow(2,l)-1;
				s=new int[l];
				//createSegmentTreeUtil(a, 0, 0, a.length-1);
			}
			
			int createSegmentTreeUtil(int a[],int root,int l,int r){
				if(l==r)
				s[root]=a[l];
				else
				s[root]= Compare(createSegmentTreeUtil(a, 2*root+1, l, (l+r)/2), createSegmentTreeUtil(a,2*root+2, (l+r)/2+1,r));
				return s[root];
			}
			int getValue(int gl,int gr){
				return getValueUtil(0, 0, n-1, gl, gr);
			}
			int getValueUtil(int root,int l,int r,int gl,int gr){
				if(l>=gl&&r<=gr){
					return s[root];
				}
				if(l>gr||r<gl){
					return 0;
				}
				return Compare(getValueUtil(2*root+1, l, (l+r)/2, gl, gr), getValueUtil(2*root+2, (l+r)/2+1, r, gl, gr));
			}
			void update(int in,int val){
				updateUtil(val, in,0,0,n-1);
			}
			int updateUtil(int p,int k,int root,int l,int r){
				if(l==r&&l==k){
					return s[root]=p;
				}
				else if(l>k||r<k)
				return s[root];
				else{
					return s[root]=Compare(updateUtil(p, k, 2*root+1, l, (l+r)/2), updateUtil(p, k, 2*root+2,(l+r)/2+1,r ));
				}
			}
			int Compare(int a,int b){
				return Math.max(a, b);
			}
		}
		class Pair{
			int r;int w;
			Pair(int node,int weight){
				r=node;w=weight;
			}
		}
		class pfactor{
			long p=0,c=0;//p is prime number & c is its count
			pfactor(long p1,long c1){
				p=p1;
				c=c1;
			}
		}