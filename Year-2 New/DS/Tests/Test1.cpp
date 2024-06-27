#include<iostream>
#include<string.h>
using namespace std;


typedef struct s1
{
	string data;
	struct s2
	{
		int tagdown, tagside;
		union u
		{
			s1 *up;
			s2 *next;
		} point1, point2;
	} *down;
	s1 *next;
} *s1ptr;

typedef struct s2
{
	int tagdown, tagside;		//0 = point to link ; 1 = point to subject
	union u
	{
		s1ptr up;
		s2 *next;
	} point1, point2;			// point1 for student ; point2 for course
} *s2ptr;


void add(s1ptr student, s1ptr course, s2ptr link, string st, string cr, int horizontal, int vertical)
{
	if(student != NULL && course!= NULL)
	{
		if(student->data != st) add(student->next, course, link, st, cr, ++horizontal, vertical);
		
		else
		{
			if(course->data != cr) add(student, course->next, link, st, cr, horizontal, ++vertical);
			else
			{
				if(student->down == NULL)
				{
					link == new s2;
					link->tagdown = 1
					link->point1.up = student;
					student->down = link;
				}
				else
				{
					while(student->down->point1.next->tagdown != 1)
					{
						student->down->point1 = student->down->point1.next;
					}
				}
				
				if(course->down == NULL)
				{
				}
			}
		}
	}
}


int main()
{
	s1ptr student = NULL, course = NULL;
	s2ptr link = NULL;
	
	
	return 0;
}
