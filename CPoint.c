#include <stdio.h>
#include <stdlib.h>

// a point on the integer grid

struct Point
{
  /*
  // constructor
  Point()
  {
    x = y = 0;
  }

  // add point componentwise
  void add(const Point &p)
  {
    x += p.x;
    y += p.y;
  }

  // print to standard output
  void print() const
  {
    std::cout << "[" << x << "," << y << "]" << std::endl;
  }
  */
  // data
  int x, y;
};

// cannot have functions in C struct, therefore we create our own
// adds two values and then stores it in a struct
void add(struct Point *p, int x, int y) {
  p->x += x;
  p->y += y;
}

// prints out our x and y from our struct Point
void print(struct Point *p) {
  printf("[%d, %d]\n", p->x, p->y);
}


int main()
{
  /*
  const int N = 200;
  Point *A = new Point[N], sum;

  for (int i=0; i < N; ++i) {
    A[i].x = i; A[i].y = -i;
    sum.add(A[i]);
  }
  sum.print();
  delete [] A;
  */

  // variables
  const int N = 200;
  int i = 0;

  // allocate memory for the structs
  struct Point* A = malloc (N * sizeof(struct Point));
  struct Point* sum = malloc (sizeof(struct Point));

  // no constructor in structs for C so we initialize ourselves
  A[i].x = 0;
  A[i].y = 0;
  sum->x = 0;
  sum->y = 0;

  // our loop to fill our Point structs, A and sum
  for (i=0; i<N; ++i) {
    A[i].x = i; 
    A[i].y = -i;
    // add our A's and store it in sum
    add(sum, A[i].x, A[i].y);
  }

  // print out our sum
  print(sum);

  // free our memory that we malloc
  free (A);
  free (sum);

}