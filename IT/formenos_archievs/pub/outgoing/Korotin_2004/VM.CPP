#include <iostream.h>
#include <stdlib.h>

inline void ERR(char* s,int i) { cerr << s << " " << i << "\n"; exit(1); }
inline void ERR(char* s) { cerr << s << " " << "\n"; exit(1); }

class matrix;
class vect {
	float* p;
	int size;
public:
	vect ( int );
	vect( vect& );
	float& operator [] ( int );
	~vect();
	friend ostream& operator << ( ostream&, vect& );
	friend vect operator* ( matrix& m, vect& v );
	friend vect operator* ( vect& v, matrix& m );
};
vect :: vect( int n )
{
	if ( n < 0 ) ERR("Error vector size ",n);
	p = new float [ size = n ];
}
vect :: vect( vect& v )
{
	p = new float [ size = v.size ];
	for( int i=0; i<v.size; i++) p[i] = v.p[i];
}
float& vect :: operator [] ( int n )
{
	if ( n < 1 || n > size ) ERR("Error vector element size ",n);
	return p[n-1];
}
vect :: ~vect()
{
	delete p;
}
ostream& operator << ( ostream& s, vect& v )
{
	s << "\t";
	for ( int i=0; i<v.size; i++ ) s << v.p[i] << " ";
	return s << "\n";
}
class matrix {
	vect** p;
	int size1, size2;
public:
	matrix( int, int );
	vect& operator [] ( int );
	~matrix();
	friend ostream& operator << ( ostream&, matrix& );
	friend vect operator * ( matrix& m, vect& v );
	friend vect operator * ( vect& v, matrix& m );
};
matrix :: matrix( int n1, int n2 )
{
	if ( n1 < 0 ) ERR("Error matrix 1 dimension ",n1);
	if ( n2 < 0 ) ERR("Error matrix 2 dimension ",n2);
	p = new vect* [ size1 = n1 ];
	for ( int i=0; i<n1; i++ ) p[i] = new vect(n2);
	size2 = n2;
}
vect& matrix :: operator [] ( int n1 )
{
	if ( n1 < 1 || n1 > size1 ) ERR("Error matrix first index",n1);
	return ( *p[n1-1] );
}
matrix :: ~matrix()
{
	for( int i=0; i<size1; i++) delete p[i];
	delete p;
}
ostream& operator << (ostream& s, matrix& m)
{
	int i,j;
	for( i=0; i<m.size1; i++ ) s << *m.p[i];
	return s;
}
vect operator * ( matrix& m, vect& v )
{
	if( m.size2 != v.size )
	   ERR("Error: different vector and matrix dimensions");
	vect r(m.size1);
	for( int i=0; i<m.size1; i++ ) {
		r.p[i]=0.;
		for ( int j=0; j<v.size; j++ )
		r.p[i]+=m.p[i]->p[j]*v.p[j]; }
	return r;
}
vect operator * ( vect& v, matrix& m )
{
	if( m.size1 != v.size )
	   ERR("Error: different matrix and vector dimensions");
	vect r(m.size2);
	for( int i=0; i<m.size2; i++ ) {
		r.p[i] = 0.;
		for ( int j=0; j<v.size; j++ ) r.p[i]+=m.p[j]->p[i]*v.p[j];}
	return r;
}
void main( void )
{
	vect a(3);
	matrix b(3,3);

	a[1]=1.; a[2]=2.; a[3]=3.;
	b[1][1]=1.; b[1][2]=2.; b[1][3]=3.;
	b[2][1]=4.; b[2][2]=5.; b[2][3]=6.;
	b[3][1]=7.; b[3][2]=8.; b[3][3]=9.;
	cout << "Matrix:\n" << b;
	cout << "Vector:\n" << a;
	cout << "Matrix-vector multiplication result:\n" << b * a;
	cout << "Vector-matrix multiplication result:\n" << a * b;
}
