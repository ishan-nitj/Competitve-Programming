//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000001
#define M 1000000007
#define MAX 100001


double x1,x2,y_1,y2,x3,y3,x4,y4;

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int init(){
	cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	double m1 = (y2-y_1)/(x2-x1);
	double m2 = (y4-y3)/(x4-x3);
	double c1 = y_1-m1*x1;
	double c2 = y3-m2*x3;
	/*
	 * if the slopes are same the line segments will intersect if some portion
	 * overlaps over another.this can be verified by checking the distances.
	 */
	if (m1==m2){
		if (dist(x1,y_1,x3,y3)+dist(x1,y_1,x4,y4)==dist(x3,y3,x4,y4)) cout << "Yes";
		else if (dist(x2,y2,x3,y3)+dist(x2,y2,x4,y4)==dist(x3,y3,x4,y4)) cout << "Yes";
		else if (dist(x3,y3,x1,y_1)+dist(x3,y3,x2,y2)==dist(x1,y_1,x2,y2)) cout << "Yes";
		else if (dist(x4,y4,x1,y_1)+dist(x4,y4,x2,y2)==dist(x1,y_1,x2,y2)) cout << "Yes";
		else cout << "No";
	}
	else{
		/*
		 * assume that the segments intersects.Calculate their point of intersection.
		 * verify it lies on both the lines or not by calculating the distances.
		 */
		double x,y;
		x = (c2-c1)/(m1-m2);
		y = m2*x+c2;
		if (dist(x1,y_1,x,y)+dist(x2,y2,x,y)==dist(x1,y_1,x2,y2) && dist(x3,y3,x,y)+dist(x4,y4,x,y)==dist(x3,y3,x4,y4))
			cout << "Yes";
		else cout << "No";
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
